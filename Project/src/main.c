#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/util.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>

#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>

#include "print_led.h"


#include <zephyr/drivers/kscan.h>
#include <zephyr/drivers/led.h>

#include "batterydisplay.h"
#include "value.h"

#if !DT_NODE_EXISTS(DT_ALIAS(qdec0))
#error "Unsupported board: qdec0 devicetree alias is not defined"
#endif

#define SW_NODE DT_NODELABEL(gpiosw)
#if !DT_NODE_HAS_STATUS(SW_NODE, okay)
#error "Unsupported board: gpiosw devicetree alias is not defined or enabled"
#endif
static const struct gpio_dt_spec sw = GPIO_DT_SPEC_GET(SW_NODE, gpios);

static bool sw_led_flag = false;
static int rotary_idx = 0;

static struct gpio_callback sw_cb_data;
static int seconds = 80;
static int beat_count = 0;

void sw_callback(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	printk("SW pressed\n");
	sw_led_flag = !sw_led_flag;
}


// #include "led.h"
#if !DT_NODE_EXISTS(DT_PATH(zephyr_user)) || \
	!DT_NODE_HAS_PROP(DT_PATH(zephyr_user), io_channels)
#error "No suitable devicetree overlay specified"
#endif

#define DT_SPEC_AND_COMMA(node_id, prop, idx) \
	ADC_DT_SPEC_GET_BY_IDX(node_id, idx),

/* Data of ADC io-channels specified in devicetree. */
static const struct adc_dt_spec adc_channels[] = {
	DT_FOREACH_PROP_ELEM(DT_PATH(zephyr_user), io_channels,
			     DT_SPEC_AND_COMMA)
};

#define MAX_SENSORVALUE 1000
#define MIN_SENSORVALUE 500
#define SENSOR_INVALID_VALUE 65500

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


struct k_timer my_timer;
struct k_work my_work;

static int level = 4;
static int status = 0;

#define ADC_NODE DT_PATH(zephyr_user)
#if !DT_NODE_EXISTS(ADC_NODE) || !DT_NODE_HAS_PROP(ADC_NODE, io_channels)
#error "No suitable devicetree overlay specified"
#endif

#define ADC_SPEC_AND_COMMA(node_id, prop, idx) \
    ADC_DT_SPEC_GET_BY_IDX(node_id, idx),


// add for joystick
struct k_timer my_timer1;
struct k_work my_work1;

int32_t preX = 0;
int32_t preY = 0;
static const int ADC_MAX = 1023;
static const int AXIS_DEVIATION = ADC_MAX / 2;
int32_t nowX = 0;
int32_t nowY = 0;
int err;
uint16_t buf;
struct adc_sequence sequence = {
    .buffer = &buf,
    /* buffer size in bytes, not number of samples */
    .buffer_size = sizeof(buf),
    .resolution = 10, // Ensure the resolution is set correctly
};

bool isChange(void)
{
    if ((nowX < (preX - 50)) || nowX > (preX + 50)) {
        preX = nowX;
        return true;
    }

    if ((nowY < (preY - 50)) || nowY > (preY + 50)) {
        preY = nowY;
        return true;
    }
    return false;
}

void adc_read_work_handler(struct k_work *work)
{
    err = adc_channel_setup(adc_channels[0].dev, &adc_channels[0].channel_cfg);
    if (err < 0) {
        printk("Could not setup channel 0 (%d)\n", err);
        return;
    }

    (void)adc_sequence_init_dt(&adc_channels[0], &sequence);
    err = adc_read(adc_channels[0].dev, &sequence);
    if (err < 0) {
        printk("Could not read channel 0 (%d)\n", err);
        return;
    }

    nowX = (int32_t)buf;

    err = adc_channel_setup(adc_channels[1].dev, &adc_channels[1].channel_cfg);
    if (err < 0) {
        printk("Could not setup channel 1 (%d)\n", err);
        return;
    }

    (void)adc_sequence_init_dt(&adc_channels[1], &sequence);
    err = adc_read(adc_channels[1].dev, &sequence);
    if (err < 0) {
        printk("Could not read channel 1 (%d)\n", err);
        return;
    }

    nowY = (int32_t)buf;

    printk("Joy X: %" PRIu32 ", ", nowX);
    printk("Joy Y: %" PRIu32 ", ", nowY);

    if (nowX >= 65500 || nowY >= 65500) {
        return;
    }


    if (nowX == ADC_MAX && nowY == ADC_MAX) {
        status = 0;
    } else if (nowX < AXIS_DEVIATION && nowY == ADC_MAX) {
        status = 3;
    } else if (nowX > AXIS_DEVIATION && nowY == ADC_MAX) {
        status = 1;
    } else if (nowY > AXIS_DEVIATION && nowX == ADC_MAX) {
        status = 4;
    } else if (nowY < AXIS_DEVIATION && nowX == ADC_MAX) {
        status = 2;
    }
    printk("\n");

    if (status == 1) {
        if (level < 4) level++;
    }
    else if (status == 2) {
        if (level > 2) level--;
    }
    else if (status == 3) {
        if (level > 2) level--;
    }
    else if (status == 4) {
        if (level < 4) level++;
    }

    printk("status : %d, level : %d\n", status, level);
}

void my_timer1_handler(struct k_timer *dummy)
{
    k_work_submit(&my_work1);
}

void my_work_handler(struct k_work *work)
{


	if (level == 4) {
      if (beat_count == 0) {
         display_level(1);
      } else if (beat_count == 1) {
         display_level(4);
      } else if (beat_count == 2) {
         display_level(6);
      } else if (beat_count == 3) {
         display_level(7);
      }

      beat_count = beat_count +1;
      if (beat_count >= 3) {
         beat_count = 0;
      }
   }
   else if(level == 3) {
      if (beat_count == 0) {
         display_level(2);
      } else if (beat_count == 1) {
         display_level(5);
      } else if (beat_count == 2) {
         display_level(7);
      }

      beat_count = beat_count +1;
      if (beat_count >= 2) {
         beat_count = 0;
      }
   }
   else if(level == 2) {
      if (beat_count == 0) {
         display_level(4);
      } else if (beat_count == 1) {
         display_level(7);
      }

      beat_count = beat_count +1;
      if (beat_count >= 1) {
         beat_count = 0;
      }
   }
}

void display_rotary_led(int32_t rotary_val)
{
	if(rotary_val > 0){
		seconds++;
		printk("encdoer up\n");
		led_on_seconds(seconds);
		int bpm_interval = (int)(60000.0 / seconds);
		k_timer_start(&my_timer, K_MSEC(bpm_interval), K_MSEC(bpm_interval));
	} else if(rotary_val < 0){
		seconds--;
		printk("encdoer down\n");
		led_on_seconds(seconds);
		int bpm_interval = (int)(60000.0 / seconds);
		k_timer_start(&my_timer, K_MSEC(bpm_interval), K_MSEC(bpm_interval));
	}
}

K_WORK_DEFINE(my_work, my_work_handler);

void my_timer_handler(struct k_timer *dummy)
{
    k_work_submit(&my_work);
}

K_TIMER_DEFINE(my_timer, my_timer_handler, NULL);



int main(void)
{
	bool isClear = true;
	uint32_t count = 0;
    uint32_t sound_value = 0;
	int sound_level = 0;
	uint32_t prev_timestamp =0;
	uint32_t curr_timestamp =0;
	uint32_t intervals[3] = {0, 0, 0};
	int bpm = 0;


	/* Configure channels individually prior to sampling. */
	for (size_t i = 0U; i < ARRAY_SIZE(adc_channels); i++) {
		if (!adc_is_ready_dt(&adc_channels[i])) {
			printk("ADC controller device %s not ready\n", adc_channels[i].dev->name);
			return 0;
		}

		err = adc_channel_setup_dt(&adc_channels[i]);
		if (err < 0) {
			printk("Could not setup channel #%d (%d)\n", i, err);
			return 0;
		}
	}

	

	struct sensor_value val;
	int rc;
	const struct device *const dev = DEVICE_DT_GET(DT_ALIAS(qdec0));

	if (!device_is_ready(dev)) {
		printk("Qdec device is not ready\n");
		return 0;
	}

	if(!gpio_is_ready_dt(&sw)) {
		printk("SW GPIO is not ready\n");
		return 0;
	}

	err = gpio_pin_configure_dt(&sw, GPIO_INPUT);
	if(err < 0){
		printk("Error configuring SW GPIO pin %d\n", err);
		return 0;
	}

	err = gpio_pin_interrupt_configure_dt(&sw, GPIO_INT_EDGE_RISING);
	if(err != 0){
		printk("Error configuring SW GPIO interrupt %d\n", err);
		return 0;
	}

	gpio_init_callback(&sw_cb_data, sw_callback, BIT(sw.pin));
	gpio_add_callback(sw.port, &sw_cb_data);

	printk("Quadrature decoder sensor test\n");

	led_on_idx(rotary_idx);

	//joystick
	printk("Seconds counter example 2\n");
    int ret = DK_OK;

    ret = batterydisplay_intit();
    if (ret != DK_OK) {
        printk("Error initializing battery display\n");
        return DK_ERR;
    }

    ret = led_init();
    if (ret != DK_OK) {
        printk("Error initializing LED\n");
        return DK_ERR;
    }

	// k_work_init(&my_work1, adc_read_work_handler);
    // k_timer_init(&my_timer1, my_timer1_handler, NULL);
    // k_timer_start(&my_timer1, K_MSEC(200), K_MSEC(200));

	while (1) {

		if(sw_led_flag){
			(void)adc_sequence_init_dt(&adc_channels[0], &sequence);
			err = adc_read(adc_channels[0].dev, &sequence);
			if (err < 0) {
				printk("Could not read (%d)\n", err);
				k_sleep(K_MSEC(100));
				continue;
			}

			sound_value = (int32_t)buf;
			if(sound_value >= SENSOR_INVALID_VALUE){
				// printk("sound_value: invalid data %" PRIu32 "\n", sound_value);
				// k_sleep(K_MSEC(1));
				continue;
			}
			sound_level = map(sound_value, 0, MAX_SENSORVALUE, 0, MIN_SENSORVALUE);

			
			if(sound_level > 500 && isClear == true){
				isClear = false;

				curr_timestamp = k_uptime_get_32();

				uint32_t sum_of_Intervals = 0;
				intervals[count % 3] = curr_timestamp - prev_timestamp ; // Record the current time
				if(count>2){
					for(int i=0;i<3;i++){
						sum_of_Intervals += intervals[i];
					} 
					bpm = (int)(60000 / (sum_of_Intervals / 3)); // Calculate BPM (3 intervals between 4 beats)
					printk("BPM : %d\n", bpm);
					seconds = bpm;
					led_on_seconds(seconds);
					int bpm_interval = (int)(60000.0 / bpm);
					k_timer_start(&my_timer, K_MSEC(bpm_interval), K_MSEC(bpm_interval));
				}
				prev_timestamp = curr_timestamp;
				printk("Count : %u \n", count++);
				printk("sound_value: %" PRIu32 " sound_level : %d\n", sound_value, sound_level);
			}
			else if (sound_level < 100){
				isClear = true;
			}
		}
		else{
			rc = sensor_sample_fetch(dev);
			if (rc != 0) {
				printk("Failed to fetch sample (%d)\n", rc);
				return 0;
			}

			rc = sensor_channel_get(dev, SENSOR_CHAN_ROTATION, &val);
			if (rc != 0) {
				printk("Failed to get data (%d)\n", rc);
				return 0;
			}

			// int sw_val = gpio_pin_get_dt(&sw);

			if(!sw_led_flag){
				display_rotary_led(val.val1);
			} else{
				led_off_all();
			}

			printk("Position = %d degrees \n", val.val1);

			k_msleep(100);
		}
		
		k_sleep(K_MSEC(1));
	}
	return 0;
}