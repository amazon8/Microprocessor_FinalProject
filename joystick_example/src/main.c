#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/util.h>
#include <zephyr/drivers/kscan.h>
#include <zephyr/drivers/led.h>

#define LED_NODE DT_COMPAT_GET_ANY_STATUS_OKAY(holtek_ht16k33)
#define KEY_NODE DT_CHILD(LED_NODE, keyscan)

static const struct device *const led = DEVICE_DT_GET(LED_NODE);
struct k_timer my_timer;
struct k_work my_work;

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

// add for joystick
int32_t preX = 0;
int32_t preY = 0;
static const int ADC_MAX = 1023;
static const int AXIS_DEVIATION = ADC_MAX / 2;
int32_t nowX = 0;
int32_t nowY = 0;
int tempo = 480;
int level = 4;
int err;
uint16_t buf;
int status = 0;

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
    
    (void)adc_sequence_init_dt(&adc_channels[0], &sequence);
    err = adc_read(adc_channels[0].dev, &sequence);
    if (err < 0) {
        printk("Could not read channel 0 (%d)\n", err);
        return;
    }

    nowX = (int32_t)buf;

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
    bool checkFlag = isChange();

    if (nowX == ADC_MAX && nowY == ADC_MAX) {
		status = 0;
        printk("tempo : %d, level : %d", tempo, level);
    } else if (nowX < AXIS_DEVIATION && nowY == ADC_MAX) {
		status = 3;
        printk("tempo : %d, level : %d", tempo, level);
    } else if (nowX > AXIS_DEVIATION && nowY == ADC_MAX) {
		status = 1;
        printk("tempo : %d, level : %d", tempo, level);
    } else if (nowY > AXIS_DEVIATION && nowX == ADC_MAX) {
		status = 4;
        printk("tempo : %d, level : %d", tempo, level);
    } else if (nowY < AXIS_DEVIATION && nowX == ADC_MAX) {
		status = 2;
        printk("tempo : %d, level : %d", tempo, level);
    }
    printk("\n");

	if(status == 1) {
		if(level == 3) level++;
	}
	else if(status == 2) {
		if(tempo > 200) tempo -= 100;
	}
	else if(status == 3) {
		if(level == 4) level--;
	}
	else if(status == 4) {
		if(tempo < 1400) tempo += 100;
	}
}

void my_timer_handler(struct k_timer *dummy)
{
    k_work_submit(&my_work);
}

int main(void)
{
    printk("Starting joystick example\n");

    /* Configure channels individually prior to sampling. */
    for (size_t i = 0U; i < ARRAY_SIZE(adc_channels); i++) {
        printk("Setting up ADC channel %d\n", i);
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

    k_work_init(&my_work, adc_read_work_handler);

    k_timer_init(&my_timer, my_timer_handler, NULL);
    k_timer_start(&my_timer, K_MSEC(200), K_MSEC(200));

    while (1) {
        int i;
        int j;

        if (level == 4) {
            for (i = 33; i < 49; i = i + 4) {
                led_on(led, i);
                led_on(led, i + 1);
                led_on(led, i + 16);
                led_on(led, i + 17);
                led_on(led, i + 32);
                led_on(led, i + 33);
                led_on(led, i + 48);
                led_on(led, i + 49);
                k_sleep(K_MSEC(tempo));
                for (j = 0; j < 128; j++) {
                    led_off(led, j);
                }
            }
        }
        if (level == 3) {
            for (i = 33; i < 45; i = i + 4) {
                led_on(led, i);
                led_on(led, i + 1);
                led_on(led, i + 16);
                led_on(led, i + 17);
                led_on(led, i + 32);
                led_on(led, i + 33);
                led_on(led, i + 48);
                led_on(led, i + 49);
                k_sleep(K_MSEC(tempo));
                for (j = 0; j < 128; j++) {
                    led_off(led, j);
                }
            }
        }
    }
    return 0;
}
