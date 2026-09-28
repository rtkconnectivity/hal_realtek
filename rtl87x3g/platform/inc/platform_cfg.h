#ifndef PLATFORM_CFG_H
#define PLATFORM_CFG_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    TIMESTAMP_HW_TIMER1_CH0 = 1,
    TIMESTAMP_RSVD = 2,
    TIMESTAMP_MAX = 3
} T_TIMESTAMP_TYPE;

/**
 * @struct EFUSE_RAM_CONFIG
 * @brief RAM EFuse settings.
 *
 * Refer to EFUSE[0x].
 */
typedef struct
{
    uint32_t RBAR;
    uint32_t RLAR;
    uint8_t Attr;
} __attribute__((packed)) MPU_ATTRIBUTE_CONFIG;

/**
 * @struct SYS_INIT_CONFIG
 * @brief Platform EFuse settings.
 *
 * Refer to EFUSE[0x].
 */
typedef struct EFUSE_PLATFORM_CONFIG_
{
    uint32_t log_encode : 3;    /* 0: raw (default), 1: base64, 2~7: RSVD */
    uint32_t timestamp_src : 2; /* 0: Use OS Tick, not sync, 1: Use HW Timer 7, 2: RSVD */
    uint32_t log_ram_size : 3;  /* actual size = 256 * (1 + log_ram_size) */
    uint32_t log_ram_type : 3;
    uint32_t log_output_if : 3;      /* 0: uart (default), 1: flash, 2: usb, 3~7: RSVD */
    uint32_t auth_checksum_size : 8; /* in 16 bytes */
    uint32_t log_ram_num : 3;
    uint32_t timestamp_div : 3;   /* HW Timer 7 divider when it is used as log timestamp */
    uint32_t systick_clk_src : 1; /* SYSTICK_EXTERNAL_CLOCK, SYSTICK_PROCESSOR_CLOCK */
    uint32_t low_power_mode_enable_interrupt_early : 1;
    uint32_t wdgIP : 1;         /* default = 0 */
    uint32_t lowerstack_en : 1;

    uint32_t reboot_record_address; /* start address of reboot record */

    uint32_t aes_iv[4];
    uint32_t aes_key[8];

    uint32_t adp_det_timeout : 8; /* ADP Det software debouncing timeout, 10ms per bit */
    uint32_t adc_mgr_queue : 4;
    uint32_t adc_channel : 10;    /* internal channel and differential channel. */
    uint32_t adc_ext_channel : 8; /* adc external channel load calibration data config */
    uint32_t reserved0 : 1;
    uint32_t stack_en : 1;

    uint32_t systick_ext_clk_freq; /* External systick timer clock frequency */
    uint32_t share_dsp_ram_reg;    /* Hashed value to be written to secure resister */
    uint32_t config_file_key[4];   /* key from config file */

    uint64_t trace_mask[4];

    MPU_ATTRIBUTE_CONFIG mpu_region[12];

    uint64_t sys_init_param[16]; //EFUSE[150~1CF]
} __attribute__((packed)) SYS_INIT_CONFIG;

typedef enum
{
    EXTERNAL_CLOCK = 0,
    CORE_CLOCK = 1
} SYSTICK_CLK_SRC_TYPE;

typedef enum
{
    SYSTICK_EXT_32K = 32000,
    SYSTICK_EXT_32K768 = 32768,
    SYSTICK_EXT_1M = 1000000,
} SYSTICK_EXT_CLK_FREQ_TYPE;

extern SYS_INIT_CONFIG sys_init_cfg;

#define IS_USE_VHCI (sys_init_cfg.stack_en)

#endif
