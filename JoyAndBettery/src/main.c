#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/util.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/kscan.h>
#include <zephyr/drivers/led.h>

#include "led.h"
#include "batterydisplay.h"
#include "value.h"

struct k_timer my_timer;
struct k_work my_work;

static int seconds = 0;
static int level = 4;
static int status = 0;

#define ADC_NODE DT_PATH(zephyr_user)
#if !DT_NODE_EXISTS(ADC_NODE) || !DT_NODE_HAS_PROP(ADC_NODE, io_channels)
#error "No suitable devicetree overlay specified"
#endif

#define ADC_SPEC_AND_COMMA(node_id, prop, idx) \
    ADC_DT_SPEC_GET_BY_IDX(node_id, idx),

static const struct adc_dt_spec adc_channels[] = {
    DT_FOREACH_PROP_ELEM(ADC_NODE, io_channels, ADC_SPEC_AND_COMMA)
};

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

    bool checkFlag = isChange();

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
        if (level == 3) level++;
    }
    else if (status == 2) {
        if (level == 4) level--;
    }
    else if (status == 3) {
        if (level == 4) level--;
    }
    else if (status == 4) {
        if (level == 3) level++;
    }

    printk("status : %d, level : %d\n", status, level);
}

void my_timer1_handler(struct k_timer *dummy)
{
    k_work_submit(&my_work1);
}

void my_work_handler(struct k_work *work)
{
    printk("Time: %d\n", seconds);

    // Display the time on the LED matrix
    led_on_seconds(seconds);

    // Display the time on the battery display
    if (seconds == 0) {
        display_level(0);
    } else if (seconds > 0 && seconds <= 15) {
        display_level(1); // 빨간
    } else if (seconds > 15 && seconds <= 30) {
        display_level(3); // 주황
    } else if (seconds > 30 && seconds <= 45) {
        display_level(5); // 초록
    } else {
        display_level(7); // 파랑
    }

    // Increment the seconds
    seconds = seconds + 15;
    if (seconds > 60) {
        seconds = 0;
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

    // Start the timer
    k_timer_start(&my_timer, K_SECONDS(1), K_SECONDS(1));

    k_work_init(&my_work1, adc_read_work_handler);
    k_timer_init(&my_timer1, my_timer1_handler, NULL);
    k_timer_start(&my_timer1, K_MSEC(200), K_MSEC(200));
    return DK_OK;
}
