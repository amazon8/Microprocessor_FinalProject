#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/util.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>

#include "print_led.h"

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

void sw_callback(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
	printk("SW pressed\n");
	sw_led_flag = !sw_led_flag;
}

void display_rotary_led(int32_t rotary_val)
{
	if(rotary_val > 0){
		seconds++;
		printk("encdoer up\n");
		led_on_seconds(seconds);
	} else if(rotary_val < 0){
		seconds--;
		printk("encdoer down\n");
		led_on_seconds(seconds);
	}
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

int main(void)
{
	int err;
	bool isClear = true;
	uint32_t count = 0;
	uint16_t buf;
    uint32_t sound_value = 0;
	int sound_level = 0;
	uint32_t prev_timestamp =0;
	uint32_t curr_timestamp =0;
	uint32_t intervals[3] = {0, 0, 0};
	int bpm = 0;

	struct adc_sequence sequence = {
		.buffer = &buf,
		/* buffer size in bytes, not number of samples */
		.buffer_size = sizeof(buf),
                // .oversampling = 0,
                // .calibrate = 0,
	};

        // printk("Sound Sensor : array_size [%d]\n", ARRAY_SIZE(adc_channels));
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

			
			if(sound_level > 400 && isClear == true){
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
				}
				prev_timestamp = curr_timestamp;
				printk("Count : %u \n", count++);
				printk("sound_value: %" PRIu32 " sound_level : %d\n", sound_value, sound_level);
			}
			else if (sound_level < 30){
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