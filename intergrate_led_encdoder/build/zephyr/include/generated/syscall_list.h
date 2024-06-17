/* auto-generated by gen_syscalls.py, don't edit */

#ifndef ZEPHYR_SYSCALL_LIST_H
#define ZEPHYR_SYSCALL_LIST_H

#define K_SYSCALL_CLOCK_GETTIME 0
#define K_SYSCALL_DEVICE_GET_BINDING 1
#define K_SYSCALL_DEVICE_IS_READY 2
#define K_SYSCALL_GPIO_GET_PENDING_INT 3
#define K_SYSCALL_GPIO_PIN_CONFIGURE 4
#define K_SYSCALL_GPIO_PIN_GET_CONFIG 5
#define K_SYSCALL_GPIO_PIN_INTERRUPT_CONFIGURE 6
#define K_SYSCALL_GPIO_PORT_CLEAR_BITS_RAW 7
#define K_SYSCALL_GPIO_PORT_GET_DIRECTION 8
#define K_SYSCALL_GPIO_PORT_GET_RAW 9
#define K_SYSCALL_GPIO_PORT_SET_BITS_RAW 10
#define K_SYSCALL_GPIO_PORT_SET_MASKED_RAW 11
#define K_SYSCALL_GPIO_PORT_TOGGLE_BITS 12
#define K_SYSCALL_I2C_CONFIGURE 13
#define K_SYSCALL_I2C_GET_CONFIG 14
#define K_SYSCALL_I2C_RECOVER_BUS 15
#define K_SYSCALL_I2C_TARGET_DRIVER_REGISTER 16
#define K_SYSCALL_I2C_TARGET_DRIVER_UNREGISTER 17
#define K_SYSCALL_I2C_TRANSFER 18
#define K_SYSCALL_KSCAN_CONFIG 19
#define K_SYSCALL_KSCAN_DISABLE_CALLBACK 20
#define K_SYSCALL_KSCAN_ENABLE_CALLBACK 21
#define K_SYSCALL_K_BUSY_WAIT 22
#define K_SYSCALL_K_CONDVAR_BROADCAST 23
#define K_SYSCALL_K_CONDVAR_INIT 24
#define K_SYSCALL_K_CONDVAR_SIGNAL 25
#define K_SYSCALL_K_CONDVAR_WAIT 26
#define K_SYSCALL_K_EVENT_CLEAR 27
#define K_SYSCALL_K_EVENT_INIT 28
#define K_SYSCALL_K_EVENT_POST 29
#define K_SYSCALL_K_EVENT_SET 30
#define K_SYSCALL_K_EVENT_SET_MASKED 31
#define K_SYSCALL_K_EVENT_WAIT 32
#define K_SYSCALL_K_EVENT_WAIT_ALL 33
#define K_SYSCALL_K_FLOAT_DISABLE 34
#define K_SYSCALL_K_FLOAT_ENABLE 35
#define K_SYSCALL_K_FUTEX_WAIT 36
#define K_SYSCALL_K_FUTEX_WAKE 37
#define K_SYSCALL_K_IS_PREEMPT_THREAD 38
#define K_SYSCALL_K_MSGQ_ALLOC_INIT 39
#define K_SYSCALL_K_MSGQ_GET 40
#define K_SYSCALL_K_MSGQ_GET_ATTRS 41
#define K_SYSCALL_K_MSGQ_NUM_FREE_GET 42
#define K_SYSCALL_K_MSGQ_NUM_USED_GET 43
#define K_SYSCALL_K_MSGQ_PEEK 44
#define K_SYSCALL_K_MSGQ_PEEK_AT 45
#define K_SYSCALL_K_MSGQ_PURGE 46
#define K_SYSCALL_K_MSGQ_PUT 47
#define K_SYSCALL_K_MUTEX_INIT 48
#define K_SYSCALL_K_MUTEX_LOCK 49
#define K_SYSCALL_K_MUTEX_UNLOCK 50
#define K_SYSCALL_K_OBJECT_ACCESS_GRANT 51
#define K_SYSCALL_K_OBJECT_ALLOC 52
#define K_SYSCALL_K_OBJECT_ALLOC_SIZE 53
#define K_SYSCALL_K_OBJECT_RELEASE 54
#define K_SYSCALL_K_PIPE_ALLOC_INIT 55
#define K_SYSCALL_K_PIPE_BUFFER_FLUSH 56
#define K_SYSCALL_K_PIPE_FLUSH 57
#define K_SYSCALL_K_PIPE_GET 58
#define K_SYSCALL_K_PIPE_PUT 59
#define K_SYSCALL_K_PIPE_READ_AVAIL 60
#define K_SYSCALL_K_PIPE_WRITE_AVAIL 61
#define K_SYSCALL_K_POLL 62
#define K_SYSCALL_K_POLL_SIGNAL_CHECK 63
#define K_SYSCALL_K_POLL_SIGNAL_INIT 64
#define K_SYSCALL_K_POLL_SIGNAL_RAISE 65
#define K_SYSCALL_K_POLL_SIGNAL_RESET 66
#define K_SYSCALL_K_QUEUE_ALLOC_APPEND 67
#define K_SYSCALL_K_QUEUE_ALLOC_PREPEND 68
#define K_SYSCALL_K_QUEUE_CANCEL_WAIT 69
#define K_SYSCALL_K_QUEUE_GET 70
#define K_SYSCALL_K_QUEUE_INIT 71
#define K_SYSCALL_K_QUEUE_IS_EMPTY 72
#define K_SYSCALL_K_QUEUE_PEEK_HEAD 73
#define K_SYSCALL_K_QUEUE_PEEK_TAIL 74
#define K_SYSCALL_K_SEM_COUNT_GET 75
#define K_SYSCALL_K_SEM_GIVE 76
#define K_SYSCALL_K_SEM_INIT 77
#define K_SYSCALL_K_SEM_RESET 78
#define K_SYSCALL_K_SEM_TAKE 79
#define K_SYSCALL_K_SLEEP 80
#define K_SYSCALL_K_STACK_ALLOC_INIT 81
#define K_SYSCALL_K_STACK_POP 82
#define K_SYSCALL_K_STACK_PUSH 83
#define K_SYSCALL_K_STR_OUT 84
#define K_SYSCALL_K_THREAD_ABORT 85
#define K_SYSCALL_K_THREAD_CREATE 86
#define K_SYSCALL_K_THREAD_CUSTOM_DATA_GET 87
#define K_SYSCALL_K_THREAD_CUSTOM_DATA_SET 88
#define K_SYSCALL_K_THREAD_DEADLINE_SET 89
#define K_SYSCALL_K_THREAD_JOIN 90
#define K_SYSCALL_K_THREAD_NAME_COPY 91
#define K_SYSCALL_K_THREAD_NAME_SET 92
#define K_SYSCALL_K_THREAD_PRIORITY_GET 93
#define K_SYSCALL_K_THREAD_PRIORITY_SET 94
#define K_SYSCALL_K_THREAD_RESUME 95
#define K_SYSCALL_K_THREAD_STACK_ALLOC 96
#define K_SYSCALL_K_THREAD_STACK_FREE 97
#define K_SYSCALL_K_THREAD_STACK_SPACE_GET 98
#define K_SYSCALL_K_THREAD_START 99
#define K_SYSCALL_K_THREAD_SUSPEND 100
#define K_SYSCALL_K_THREAD_TIMEOUT_EXPIRES_TICKS 101
#define K_SYSCALL_K_THREAD_TIMEOUT_REMAINING_TICKS 102
#define K_SYSCALL_K_TIMER_EXPIRES_TICKS 103
#define K_SYSCALL_K_TIMER_REMAINING_TICKS 104
#define K_SYSCALL_K_TIMER_START 105
#define K_SYSCALL_K_TIMER_STATUS_GET 106
#define K_SYSCALL_K_TIMER_STATUS_SYNC 107
#define K_SYSCALL_K_TIMER_STOP 108
#define K_SYSCALL_K_TIMER_USER_DATA_GET 109
#define K_SYSCALL_K_TIMER_USER_DATA_SET 110
#define K_SYSCALL_K_UPTIME_TICKS 111
#define K_SYSCALL_K_USLEEP 112
#define K_SYSCALL_K_WAKEUP 113
#define K_SYSCALL_K_YIELD 114
#define K_SYSCALL_LED_BLINK 115
#define K_SYSCALL_LED_GET_INFO 116
#define K_SYSCALL_LED_OFF 117
#define K_SYSCALL_LED_ON 118
#define K_SYSCALL_LED_SET_BRIGHTNESS 119
#define K_SYSCALL_LED_SET_CHANNEL 120
#define K_SYSCALL_LED_SET_COLOR 121
#define K_SYSCALL_LED_WRITE_CHANNELS 122
#define K_SYSCALL_LOG_BUFFERED_CNT 123
#define K_SYSCALL_LOG_FILTER_SET 124
#define K_SYSCALL_LOG_PANIC 125
#define K_SYSCALL_LOG_PROCESS 126
#define K_SYSCALL_SENSOR_ATTR_GET 127
#define K_SYSCALL_SENSOR_ATTR_SET 128
#define K_SYSCALL_SENSOR_CHANNEL_GET 129
#define K_SYSCALL_SENSOR_GET_DECODER 130
#define K_SYSCALL_SENSOR_RECONFIGURE_READ_IODEV 131
#define K_SYSCALL_SENSOR_SAMPLE_FETCH 132
#define K_SYSCALL_SENSOR_SAMPLE_FETCH_CHAN 133
#define K_SYSCALL_SPI_RELEASE 134
#define K_SYSCALL_SPI_TRANSCEIVE 135
#define K_SYSCALL_SYS_CLOCK_HW_CYCLES_PER_SEC_RUNTIME_GET 136
#define K_SYSCALL_UART_CONFIGURE 137
#define K_SYSCALL_UART_CONFIG_GET 138
#define K_SYSCALL_UART_DRV_CMD 139
#define K_SYSCALL_UART_ERR_CHECK 140
#define K_SYSCALL_UART_IRQ_ERR_DISABLE 141
#define K_SYSCALL_UART_IRQ_ERR_ENABLE 142
#define K_SYSCALL_UART_IRQ_IS_PENDING 143
#define K_SYSCALL_UART_IRQ_RX_DISABLE 144
#define K_SYSCALL_UART_IRQ_RX_ENABLE 145
#define K_SYSCALL_UART_IRQ_TX_DISABLE 146
#define K_SYSCALL_UART_IRQ_TX_ENABLE 147
#define K_SYSCALL_UART_IRQ_UPDATE 148
#define K_SYSCALL_UART_LINE_CTRL_GET 149
#define K_SYSCALL_UART_LINE_CTRL_SET 150
#define K_SYSCALL_UART_POLL_IN 151
#define K_SYSCALL_UART_POLL_IN_U16 152
#define K_SYSCALL_UART_POLL_OUT 153
#define K_SYSCALL_UART_POLL_OUT_U16 154
#define K_SYSCALL_UART_RX_DISABLE 155
#define K_SYSCALL_UART_RX_ENABLE 156
#define K_SYSCALL_UART_RX_ENABLE_U16 157
#define K_SYSCALL_UART_TX 158
#define K_SYSCALL_UART_TX_ABORT 159
#define K_SYSCALL_UART_TX_U16 160
#define K_SYSCALL_ZEPHYR_FPUTC 161
#define K_SYSCALL_ZEPHYR_FWRITE 162
#define K_SYSCALL_ZEPHYR_READ_STDIN 163
#define K_SYSCALL_ZEPHYR_WRITE_STDOUT 164
#define K_SYSCALL_Z_CURRENT_GET 165
#define K_SYSCALL_Z_LOG_MSG_RUNTIME_VCREATE 166
#define K_SYSCALL_Z_LOG_MSG_STATIC_CREATE 167
#define K_SYSCALL_Z_SYS_MUTEX_KERNEL_LOCK 168
#define K_SYSCALL_Z_SYS_MUTEX_KERNEL_UNLOCK 169
#define K_SYSCALL_BAD 170
#define K_SYSCALL_LIMIT 171


/* Following syscalls are not used in image */
#define K_SYSCALL_ADC_CHANNEL_SETUP 172
#define K_SYSCALL_ADC_READ 173
#define K_SYSCALL_ADC_READ_ASYNC 174
#define K_SYSCALL_ATOMIC_ADD 175
#define K_SYSCALL_ATOMIC_AND 176
#define K_SYSCALL_ATOMIC_CAS 177
#define K_SYSCALL_ATOMIC_NAND 178
#define K_SYSCALL_ATOMIC_OR 179
#define K_SYSCALL_ATOMIC_PTR_CAS 180
#define K_SYSCALL_ATOMIC_PTR_SET 181
#define K_SYSCALL_ATOMIC_SET 182
#define K_SYSCALL_ATOMIC_SUB 183
#define K_SYSCALL_ATOMIC_XOR 184
#define K_SYSCALL_AUXDISPLAY_BACKLIGHT_GET 185
#define K_SYSCALL_AUXDISPLAY_BACKLIGHT_SET 186
#define K_SYSCALL_AUXDISPLAY_BRIGHTNESS_GET 187
#define K_SYSCALL_AUXDISPLAY_BRIGHTNESS_SET 188
#define K_SYSCALL_AUXDISPLAY_CAPABILITIES_GET 189
#define K_SYSCALL_AUXDISPLAY_CLEAR 190
#define K_SYSCALL_AUXDISPLAY_CURSOR_POSITION_GET 191
#define K_SYSCALL_AUXDISPLAY_CURSOR_POSITION_SET 192
#define K_SYSCALL_AUXDISPLAY_CURSOR_SET_ENABLED 193
#define K_SYSCALL_AUXDISPLAY_CURSOR_SHIFT_SET 194
#define K_SYSCALL_AUXDISPLAY_CUSTOM_CHARACTER_SET 195
#define K_SYSCALL_AUXDISPLAY_CUSTOM_COMMAND 196
#define K_SYSCALL_AUXDISPLAY_DISPLAY_OFF 197
#define K_SYSCALL_AUXDISPLAY_DISPLAY_ON 198
#define K_SYSCALL_AUXDISPLAY_DISPLAY_POSITION_GET 199
#define K_SYSCALL_AUXDISPLAY_DISPLAY_POSITION_SET 200
#define K_SYSCALL_AUXDISPLAY_IS_BUSY 201
#define K_SYSCALL_AUXDISPLAY_POSITION_BLINKING_SET_ENABLED 202
#define K_SYSCALL_AUXDISPLAY_WRITE 203
#define K_SYSCALL_BBRAM_CHECK_INVALID 204
#define K_SYSCALL_BBRAM_CHECK_POWER 205
#define K_SYSCALL_BBRAM_CHECK_STANDBY_POWER 206
#define K_SYSCALL_BBRAM_GET_SIZE 207
#define K_SYSCALL_BBRAM_READ 208
#define K_SYSCALL_BBRAM_WRITE 209
#define K_SYSCALL_BC12_SET_RESULT_CB 210
#define K_SYSCALL_BC12_SET_ROLE 211
#define K_SYSCALL_CAN_ADD_RX_FILTER_MSGQ 212
#define K_SYSCALL_CAN_CALC_TIMING 213
#define K_SYSCALL_CAN_CALC_TIMING_DATA 214
#define K_SYSCALL_CAN_GET_CAPABILITIES 215
#define K_SYSCALL_CAN_GET_CORE_CLOCK 216
#define K_SYSCALL_CAN_GET_MAX_BITRATE 217
#define K_SYSCALL_CAN_GET_MAX_FILTERS 218
#define K_SYSCALL_CAN_GET_STATE 219
#define K_SYSCALL_CAN_GET_TIMING_DATA_MAX 220
#define K_SYSCALL_CAN_GET_TIMING_DATA_MIN 221
#define K_SYSCALL_CAN_GET_TIMING_MAX 222
#define K_SYSCALL_CAN_GET_TIMING_MIN 223
#define K_SYSCALL_CAN_RECOVER 224
#define K_SYSCALL_CAN_REMOVE_RX_FILTER 225
#define K_SYSCALL_CAN_SEND 226
#define K_SYSCALL_CAN_SET_BITRATE 227
#define K_SYSCALL_CAN_SET_BITRATE_DATA 228
#define K_SYSCALL_CAN_SET_MODE 229
#define K_SYSCALL_CAN_SET_TIMING 230
#define K_SYSCALL_CAN_SET_TIMING_DATA 231
#define K_SYSCALL_CAN_START 232
#define K_SYSCALL_CAN_STOP 233
#define K_SYSCALL_COUNTER_CANCEL_CHANNEL_ALARM 234
#define K_SYSCALL_COUNTER_GET_FREQUENCY 235
#define K_SYSCALL_COUNTER_GET_GUARD_PERIOD 236
#define K_SYSCALL_COUNTER_GET_MAX_TOP_VALUE 237
#define K_SYSCALL_COUNTER_GET_NUM_OF_CHANNELS 238
#define K_SYSCALL_COUNTER_GET_PENDING_INT 239
#define K_SYSCALL_COUNTER_GET_TOP_VALUE 240
#define K_SYSCALL_COUNTER_GET_VALUE 241
#define K_SYSCALL_COUNTER_GET_VALUE_64 242
#define K_SYSCALL_COUNTER_IS_COUNTING_UP 243
#define K_SYSCALL_COUNTER_SET_CHANNEL_ALARM 244
#define K_SYSCALL_COUNTER_SET_GUARD_PERIOD 245
#define K_SYSCALL_COUNTER_SET_TOP_VALUE 246
#define K_SYSCALL_COUNTER_START 247
#define K_SYSCALL_COUNTER_STOP 248
#define K_SYSCALL_COUNTER_TICKS_TO_US 249
#define K_SYSCALL_COUNTER_US_TO_TICKS 250
#define K_SYSCALL_DAC_CHANNEL_SETUP 251
#define K_SYSCALL_DAC_WRITE_VALUE 252
#define K_SYSCALL_DMA_CHAN_FILTER 253
#define K_SYSCALL_DMA_RELEASE_CHANNEL 254
#define K_SYSCALL_DMA_REQUEST_CHANNEL 255
#define K_SYSCALL_DMA_RESUME 256
#define K_SYSCALL_DMA_START 257
#define K_SYSCALL_DMA_STOP 258
#define K_SYSCALL_DMA_SUSPEND 259
#define K_SYSCALL_EEPROM_GET_SIZE 260
#define K_SYSCALL_EEPROM_READ 261
#define K_SYSCALL_EEPROM_WRITE 262
#define K_SYSCALL_ENTROPY_GET_ENTROPY 263
#define K_SYSCALL_ESPI_CONFIG 264
#define K_SYSCALL_ESPI_FLASH_ERASE 265
#define K_SYSCALL_ESPI_GET_CHANNEL_STATUS 266
#define K_SYSCALL_ESPI_READ_FLASH 267
#define K_SYSCALL_ESPI_READ_LPC_REQUEST 268
#define K_SYSCALL_ESPI_READ_REQUEST 269
#define K_SYSCALL_ESPI_RECEIVE_OOB 270
#define K_SYSCALL_ESPI_RECEIVE_VWIRE 271
#define K_SYSCALL_ESPI_SAF_ACTIVATE 272
#define K_SYSCALL_ESPI_SAF_CONFIG 273
#define K_SYSCALL_ESPI_SAF_FLASH_ERASE 274
#define K_SYSCALL_ESPI_SAF_FLASH_READ 275
#define K_SYSCALL_ESPI_SAF_FLASH_WRITE 276
#define K_SYSCALL_ESPI_SAF_GET_CHANNEL_STATUS 277
#define K_SYSCALL_ESPI_SAF_SET_PROTECTION_REGIONS 278
#define K_SYSCALL_ESPI_SEND_OOB 279
#define K_SYSCALL_ESPI_SEND_VWIRE 280
#define K_SYSCALL_ESPI_WRITE_FLASH 281
#define K_SYSCALL_ESPI_WRITE_LPC_REQUEST 282
#define K_SYSCALL_ESPI_WRITE_REQUEST 283
#define K_SYSCALL_FLASH_ERASE 284
#define K_SYSCALL_FLASH_EX_OP 285
#define K_SYSCALL_FLASH_GET_PAGE_COUNT 286
#define K_SYSCALL_FLASH_GET_PAGE_INFO_BY_IDX 287
#define K_SYSCALL_FLASH_GET_PAGE_INFO_BY_OFFS 288
#define K_SYSCALL_FLASH_GET_PARAMETERS 289
#define K_SYSCALL_FLASH_GET_WRITE_BLOCK_SIZE 290
#define K_SYSCALL_FLASH_READ 291
#define K_SYSCALL_FLASH_READ_JEDEC_ID 292
#define K_SYSCALL_FLASH_SFDP_READ 293
#define K_SYSCALL_FLASH_SIMULATOR_GET_MEMORY 294
#define K_SYSCALL_FLASH_WRITE 295
#define K_SYSCALL_FUEL_GAUGE_BATTERY_CUTOFF 296
#define K_SYSCALL_FUEL_GAUGE_GET_BUFFER_PROP 297
#define K_SYSCALL_FUEL_GAUGE_GET_PROP 298
#define K_SYSCALL_FUEL_GAUGE_SET_PROP 299
#define K_SYSCALL_HWINFO_CLEAR_RESET_CAUSE 300
#define K_SYSCALL_HWINFO_GET_DEVICE_ID 301
#define K_SYSCALL_HWINFO_GET_RESET_CAUSE 302
#define K_SYSCALL_HWINFO_GET_SUPPORTED_RESET_CAUSE 303
#define K_SYSCALL_HWSPINLOCK_GET_MAX_ID 304
#define K_SYSCALL_HWSPINLOCK_LOCK 305
#define K_SYSCALL_HWSPINLOCK_TRYLOCK 306
#define K_SYSCALL_HWSPINLOCK_UNLOCK 307
#define K_SYSCALL_I2S_BUF_READ 308
#define K_SYSCALL_I2S_BUF_WRITE 309
#define K_SYSCALL_I2S_CONFIGURE 310
#define K_SYSCALL_I2S_TRIGGER 311
#define K_SYSCALL_I3C_DO_CCC 312
#define K_SYSCALL_I3C_TRANSFER 313
#define K_SYSCALL_IPM_COMPLETE 314
#define K_SYSCALL_IPM_MAX_DATA_SIZE_GET 315
#define K_SYSCALL_IPM_MAX_ID_VAL_GET 316
#define K_SYSCALL_IPM_SEND 317
#define K_SYSCALL_IPM_SET_ENABLED 318
#define K_SYSCALL_IVSHMEM_ENABLE_INTERRUPTS 319
#define K_SYSCALL_IVSHMEM_GET_ID 320
#define K_SYSCALL_IVSHMEM_GET_MAX_PEERS 321
#define K_SYSCALL_IVSHMEM_GET_MEM 322
#define K_SYSCALL_IVSHMEM_GET_OUTPUT_MEM_SECTION 323
#define K_SYSCALL_IVSHMEM_GET_PROTOCOL 324
#define K_SYSCALL_IVSHMEM_GET_RW_MEM_SECTION 325
#define K_SYSCALL_IVSHMEM_GET_STATE 326
#define K_SYSCALL_IVSHMEM_GET_VECTORS 327
#define K_SYSCALL_IVSHMEM_INT_PEER 328
#define K_SYSCALL_IVSHMEM_REGISTER_HANDLER 329
#define K_SYSCALL_IVSHMEM_SET_STATE 330
#define K_SYSCALL_K_MEM_PAGING_HISTOGRAM_BACKING_STORE_PAGE_IN_GET 331
#define K_SYSCALL_K_MEM_PAGING_HISTOGRAM_BACKING_STORE_PAGE_OUT_GET 332
#define K_SYSCALL_K_MEM_PAGING_HISTOGRAM_EVICTION_GET 333
#define K_SYSCALL_K_MEM_PAGING_STATS_GET 334
#define K_SYSCALL_K_MEM_PAGING_THREAD_STATS_GET 335
#define K_SYSCALL_MAXIM_DS3231_GET_SYNCPOINT 336
#define K_SYSCALL_MAXIM_DS3231_REQ_SYNCPOINT 337
#define K_SYSCALL_MBOX_MAX_CHANNELS_GET 338
#define K_SYSCALL_MBOX_MTU_GET 339
#define K_SYSCALL_MBOX_SEND 340
#define K_SYSCALL_MBOX_SET_ENABLED 341
#define K_SYSCALL_MDIO_BUS_DISABLE 342
#define K_SYSCALL_MDIO_BUS_ENABLE 343
#define K_SYSCALL_MDIO_READ 344
#define K_SYSCALL_MDIO_WRITE 345
#define K_SYSCALL_NET_ADDR_NTOP 346
#define K_SYSCALL_NET_ADDR_PTON 347
#define K_SYSCALL_NET_ETH_GET_PTP_CLOCK_BY_INDEX 348
#define K_SYSCALL_NET_IF_GET_BY_INDEX 349
#define K_SYSCALL_NET_IF_IPV4_ADDR_ADD_BY_INDEX 350
#define K_SYSCALL_NET_IF_IPV4_ADDR_LOOKUP_BY_INDEX 351
#define K_SYSCALL_NET_IF_IPV4_ADDR_RM_BY_INDEX 352
#define K_SYSCALL_NET_IF_IPV4_SET_GW_BY_INDEX 353
#define K_SYSCALL_NET_IF_IPV4_SET_NETMASK_BY_INDEX 354
#define K_SYSCALL_NET_IF_IPV6_ADDR_ADD_BY_INDEX 355
#define K_SYSCALL_NET_IF_IPV6_ADDR_LOOKUP_BY_INDEX 356
#define K_SYSCALL_NET_IF_IPV6_ADDR_RM_BY_INDEX 357
#define K_SYSCALL_NRF_QSPI_NOR_XIP_ENABLE 358
#define K_SYSCALL_PECI_CONFIG 359
#define K_SYSCALL_PECI_DISABLE 360
#define K_SYSCALL_PECI_ENABLE 361
#define K_SYSCALL_PECI_TRANSFER 362
#define K_SYSCALL_PHY_CONFIGURE_LINK 363
#define K_SYSCALL_PHY_GET_LINK_STATE 364
#define K_SYSCALL_PHY_LINK_CALLBACK_SET 365
#define K_SYSCALL_PHY_READ 366
#define K_SYSCALL_PHY_WRITE 367
#define K_SYSCALL_PS2_CONFIG 368
#define K_SYSCALL_PS2_DISABLE_CALLBACK 369
#define K_SYSCALL_PS2_ENABLE_CALLBACK 370
#define K_SYSCALL_PS2_READ 371
#define K_SYSCALL_PS2_WRITE 372
#define K_SYSCALL_PTP_CLOCK_GET 373
#define K_SYSCALL_PWM_CAPTURE_CYCLES 374
#define K_SYSCALL_PWM_DISABLE_CAPTURE 375
#define K_SYSCALL_PWM_ENABLE_CAPTURE 376
#define K_SYSCALL_PWM_GET_CYCLES_PER_SEC 377
#define K_SYSCALL_PWM_SET_CYCLES 378
#define K_SYSCALL_RESET_LINE_ASSERT 379
#define K_SYSCALL_RESET_LINE_DEASSERT 380
#define K_SYSCALL_RESET_LINE_TOGGLE 381
#define K_SYSCALL_RESET_STATUS 382
#define K_SYSCALL_RETAINED_MEM_CLEAR 383
#define K_SYSCALL_RETAINED_MEM_READ 384
#define K_SYSCALL_RETAINED_MEM_SIZE 385
#define K_SYSCALL_RETAINED_MEM_WRITE 386
#define K_SYSCALL_RTC_ALARM_GET_SUPPORTED_FIELDS 387
#define K_SYSCALL_RTC_ALARM_GET_TIME 388
#define K_SYSCALL_RTC_ALARM_IS_PENDING 389
#define K_SYSCALL_RTC_ALARM_SET_CALLBACK 390
#define K_SYSCALL_RTC_ALARM_SET_TIME 391
#define K_SYSCALL_RTC_GET_CALIBRATION 392
#define K_SYSCALL_RTC_GET_TIME 393
#define K_SYSCALL_RTC_SET_CALIBRATION 394
#define K_SYSCALL_RTC_SET_TIME 395
#define K_SYSCALL_RTC_UPDATE_SET_CALLBACK 396
#define K_SYSCALL_RTIO_CQE_COPY_OUT 397
#define K_SYSCALL_RTIO_CQE_GET_MEMPOOL_BUFFER 398
#define K_SYSCALL_RTIO_RELEASE_BUFFER 399
#define K_SYSCALL_RTIO_SQE_CANCEL 400
#define K_SYSCALL_RTIO_SQE_COPY_IN_GET_HANDLES 401
#define K_SYSCALL_RTIO_SUBMIT 402
#define K_SYSCALL_SDHC_CARD_BUSY 403
#define K_SYSCALL_SDHC_CARD_PRESENT 404
#define K_SYSCALL_SDHC_EXECUTE_TUNING 405
#define K_SYSCALL_SDHC_GET_HOST_PROPS 406
#define K_SYSCALL_SDHC_HW_RESET 407
#define K_SYSCALL_SDHC_REQUEST 408
#define K_SYSCALL_SDHC_SET_IO 409
#define K_SYSCALL_SIP_SUPERVISORY_CALL 410
#define K_SYSCALL_SIP_SVC_PLAT_ASYNC_RES_REQ 411
#define K_SYSCALL_SIP_SVC_PLAT_ASYNC_RES_RES 412
#define K_SYSCALL_SIP_SVC_PLAT_FORMAT_TRANS_ID 413
#define K_SYSCALL_SIP_SVC_PLAT_FREE_ASYNC_MEMORY 414
#define K_SYSCALL_SIP_SVC_PLAT_FUNC_ID_VALID 415
#define K_SYSCALL_SIP_SVC_PLAT_GET_ERROR_CODE 416
#define K_SYSCALL_SIP_SVC_PLAT_GET_TRANS_IDX 417
#define K_SYSCALL_SIP_SVC_PLAT_UPDATE_TRANS_ID 418
#define K_SYSCALL_SMBUS_BLOCK_PCALL 419
#define K_SYSCALL_SMBUS_BLOCK_READ 420
#define K_SYSCALL_SMBUS_BLOCK_WRITE 421
#define K_SYSCALL_SMBUS_BYTE_DATA_READ 422
#define K_SYSCALL_SMBUS_BYTE_DATA_WRITE 423
#define K_SYSCALL_SMBUS_BYTE_READ 424
#define K_SYSCALL_SMBUS_BYTE_WRITE 425
#define K_SYSCALL_SMBUS_CONFIGURE 426
#define K_SYSCALL_SMBUS_GET_CONFIG 427
#define K_SYSCALL_SMBUS_HOST_NOTIFY_REMOVE_CB 428
#define K_SYSCALL_SMBUS_HOST_NOTIFY_SET_CB 429
#define K_SYSCALL_SMBUS_PCALL 430
#define K_SYSCALL_SMBUS_QUICK 431
#define K_SYSCALL_SMBUS_SMBALERT_REMOVE_CB 432
#define K_SYSCALL_SMBUS_SMBALERT_SET_CB 433
#define K_SYSCALL_SMBUS_WORD_DATA_READ 434
#define K_SYSCALL_SMBUS_WORD_DATA_WRITE 435
#define K_SYSCALL_SYSCON_GET_BASE 436
#define K_SYSCALL_SYSCON_GET_SIZE 437
#define K_SYSCALL_SYSCON_READ_REG 438
#define K_SYSCALL_SYSCON_WRITE_REG 439
#define K_SYSCALL_SYS_CACHE_DATA_FLUSH_AND_INVD_RANGE 440
#define K_SYSCALL_SYS_CACHE_DATA_FLUSH_RANGE 441
#define K_SYSCALL_SYS_CACHE_DATA_INVD_RANGE 442
#define K_SYSCALL_SYS_CSRAND_GET 443
#define K_SYSCALL_SYS_RAND32_GET 444
#define K_SYSCALL_SYS_RAND_GET 445
#define K_SYSCALL_UART_MUX_FIND 446
#define K_SYSCALL_UPDATEHUB_AUTOHANDLER 447
#define K_SYSCALL_UPDATEHUB_CONFIRM 448
#define K_SYSCALL_UPDATEHUB_PROBE 449
#define K_SYSCALL_UPDATEHUB_REBOOT 450
#define K_SYSCALL_UPDATEHUB_UPDATE 451
#define K_SYSCALL_USER_FAULT 452
#define K_SYSCALL_W1_CHANGE_BUS_LOCK 453
#define K_SYSCALL_W1_CONFIGURE 454
#define K_SYSCALL_W1_GET_SLAVE_COUNT 455
#define K_SYSCALL_W1_READ_BIT 456
#define K_SYSCALL_W1_READ_BLOCK 457
#define K_SYSCALL_W1_READ_BYTE 458
#define K_SYSCALL_W1_RESET_BUS 459
#define K_SYSCALL_W1_SEARCH_BUS 460
#define K_SYSCALL_W1_WRITE_BIT 461
#define K_SYSCALL_W1_WRITE_BLOCK 462
#define K_SYSCALL_W1_WRITE_BYTE 463
#define K_SYSCALL_WDT_DISABLE 464
#define K_SYSCALL_WDT_FEED 465
#define K_SYSCALL_WDT_SETUP 466
#define K_SYSCALL_ZSOCK_ACCEPT 467
#define K_SYSCALL_ZSOCK_BIND 468
#define K_SYSCALL_ZSOCK_CLOSE 469
#define K_SYSCALL_ZSOCK_CONNECT 470
#define K_SYSCALL_ZSOCK_FCNTL 471
#define K_SYSCALL_ZSOCK_GETHOSTNAME 472
#define K_SYSCALL_ZSOCK_GETPEERNAME 473
#define K_SYSCALL_ZSOCK_GETSOCKNAME 474
#define K_SYSCALL_ZSOCK_GETSOCKOPT 475
#define K_SYSCALL_ZSOCK_GET_CONTEXT_OBJECT 476
#define K_SYSCALL_ZSOCK_INET_PTON 477
#define K_SYSCALL_ZSOCK_IOCTL 478
#define K_SYSCALL_ZSOCK_LISTEN 479
#define K_SYSCALL_ZSOCK_POLL 480
#define K_SYSCALL_ZSOCK_RECVFROM 481
#define K_SYSCALL_ZSOCK_SELECT 482
#define K_SYSCALL_ZSOCK_SENDMSG 483
#define K_SYSCALL_ZSOCK_SENDTO 484
#define K_SYSCALL_ZSOCK_SETSOCKOPT 485
#define K_SYSCALL_ZSOCK_SHUTDOWN 486
#define K_SYSCALL_ZSOCK_SOCKET 487
#define K_SYSCALL_ZSOCK_SOCKETPAIR 488
#define K_SYSCALL_Z_ERRNO 489
#define K_SYSCALL_Z_ZSOCK_GETADDRINFO_INTERNAL 490


#ifndef _ASMLANGUAGE

#include <stdarg.h>
#include <stdint.h>

#endif /* _ASMLANGUAGE */

#endif /* ZEPHYR_SYSCALL_LIST_H */
