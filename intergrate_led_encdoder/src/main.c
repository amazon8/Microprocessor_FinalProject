/*
 * Copyright (c) 2022 Valerio Setti <valerio.setti@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/gpio.h>

#if !DT_NODE_EXISTS(DT_ALIAS(qdec0))
#error "Unsupported board: qdec0 devicetree alias is not defined"
#endif

#define SW_NODE DT_NODELABEL(gpiosw)
#if !DT_NODE_HAS_STATUS(SW_NODE, okay)
#error "Unsupported board: gpiosw devicetree alias is not defined or enabled"
#endif


static const struct gpio_dt_spec sw = GPIO_DT_SPEC_GET(SW_NODE, gpios);

static bool sw_led_flag = false;


static struct gpio_callback sw_cb_data;
static int seconds = 80;

const struct device *dev;

// 타이머 핸들러 함수
void timer_handler2(struct k_timer *dummy)
{
    struct sensor_value val;
    int rc;

    rc = sensor_sample_fetch(dev);
    if (rc != 0) {
        printk("Failed to fetch sample (%d)\n", rc);
        return;
    }

    rc = sensor_channel_get(dev, SENSOR_CHAN_ROTATION, &val);
    if (rc != 0) {
        printk("Failed to get data (%d)\n", rc);
        return;
    }

    printk("Position = %d degrees \n", val.val1);
}

K_TIMER_DEFINE(my_timer2, timer_handler2, NULL);

void sw_callback(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
    printk("SW pressed\n");
    sw_led_flag = !sw_led_flag;
}

int main(void)
{
    gpio_init_callback(&sw_cb_data, sw_callback, BIT(sw.pin));
    gpio_add_callback(sw.port, &sw_cb_data);

    printk("Quadrature decoder sensor test\n");

    // 타이머 시작 (100ms 주기)
    k_timer_start(&my_timer2, K_MSEC(100), K_MSEC(100));


    return 0;
}