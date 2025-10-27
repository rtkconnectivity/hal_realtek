#ifndef _PLATFORM_CFG_H
#define _PLATFORM_CFG_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "flash_nor_basic.h"

/*============================================================================*
*                              Part1: Boot Config
*============================================================================*/

typedef struct _FLASH_NOR_SETTINGS_CFG
{
    uint32_t flash_cmd_list_len : 2;
    uint32_t flash_busy_wait_tick : 6;
    uint32_t hpm_en : 1;
    uint32_t is_4_byte_address_mode : 1;
    uint32_t init_cmd_from_cfg : 1;
    uint32_t init_query_from_cfg : 1;
    uint32_t flash_dma_ch : 4;
    uint32_t flash_dma_ch_priority : 8;
    uint32_t flash_dma_irq_priority : 8;

    uint32_t wait_max_retry : 27;
    uint32_t erase_max_retry : 4;
    uint32_t reg_wren_type : 1;

    uint32_t turn_on_off_rf: 1;   // 0, no turn on/off rf; 1, turn on/off rf
    uint32_t spic_baud : 12;
    uint32_t dp_release_cyc_len : 3;
    uint32_t dp_release_delay_us : 8;
    uint32_t sw_reset_delay_us : 8;


    uint32_t bp_enable : 1;
    uint32_t bp_tb : 1;
    uint32_t bp_lv : 8;
    uint32_t bp_ignore : 1;
    uint32_t cache_enable : 1; //enable cache or not
    // 2'b00 for non-MCM flash, use VDDC power cut;
    // 2'b01 for 1.8V MCM flash;
    // 2'b10 for wide range MCM flash;
    // 2'b11 for non-MCM flash, do not need VDDC power cut (default);
    uint32_t disable_irq_lv: 3;
    uint32_t read_turn_on_off_rf: 1;
    uint32_t active_power: 2;
    uint32_t init_cmd_rdid : 8;
    uint32_t dp_enter_delay_us: 6;

    uint32_t init_cmd_rd_data : 8;
    uint32_t init_cmd_dp_release : 8;
    uint32_t init_cmd_en_reset : 8;
    uint32_t init_cmd_reset : 8;

    uint32_t flash_power_on_delay_100us_cnt: 8;
    uint32_t flash_init_delay_1ms_cnt: 8;
    uint32_t flash_init_whether_check_wip: 1;
    uint32_t flash_check_wip_delay_1ms_cnt: 15;

    T_FLASH_INFO_TBL flash_info_tbl;     /* store Flash related information */ //18 bytes
    FLASH_NOR_QUERY_INFO_TABLE_STRUCT query_info;


} __attribute__((packed)) FLASH_NOR_SETTINGS_CFG;


typedef struct _BT_EFUSE_BOOT_CFG
{
    uint32_t SWD_ENABLE: 1;
    uint32_t aon_reg_parsing_tag: 8;
    uint32_t is_bypass_flash: 1;
    uint32_t is_do_lop_pon_setting: 1;
    uint32_t is_hw_auto_pwm_pfm: 1;
    uint32_t ota_copy_image_before_secure_boot: 1;
    uint32_t rsvd: 19;

    uint32_t is_need_delay_for_32k_deglitch: 1;
    uint32_t deglitch_sync_begin_cnt: 26;
    uint32_t rsvd1: 5;

    FLASH_NOR_SETTINGS_CFG flash_setting;

} __attribute__((packed)) BT_EFUSE_BOOT_CFG;

extern BT_EFUSE_BOOT_CFG boot_cfg;

/*============================================================================*
 *                              Part2: Platform Config
*============================================================================*/
/**
 * @struct EFUSE_RAM_CONFIG
 * @brief RAM EFuse settings.
 *
 * Refer to EFUSE[0x].
 */
typedef struct RAM_CONFIG_
{
    uint16_t DS_cache_8_0: 9;
    uint16_t DS_lepa: 1;
    uint16_t SD_lepa: 1;
    uint16_t DS_lemst: 1;
    uint16_t SD_lemst: 1;
    uint16_t LS_snps_1_0: 2;
    uint16_t RSVD0: 1;

    uint16_t SD_cache_8_0: 9;
    uint16_t RSVD1: 7;

    uint16_t LS_retsram_4_0: 5;  // bit0-4: 32k + 32k + 32k + 4k +4k
    uint16_t DS_retsram_4_0: 5;
    uint16_t SD_retsram_4_0: 5;
    uint16_t RSVD2: 1;

    uint16_t LS_buffer: 1;
    uint16_t DS_buffer: 1;
    uint16_t SD_buffer: 1;
    uint16_t LS_audio: 1;
    uint16_t DS_audio: 1;
    uint16_t SD_audio: 1;
    uint16_t LS_rom: 1;
    uint16_t RSVD4: 1;
    uint16_t LS_zigbee_32x32_3_0: 4;
    uint16_t DS_zigbee_32x32_3_0: 4;

} __attribute__((packed)) RAM_CONFIG;

enum
{
    MEMCFG_ACTIVE,   // rtl8752h iso0 not control data ram, buffer ram and cache ram
    MEMCFG_LOWPOWER,
    MEMCFG_MAX
};

typedef struct t_otp_ota
{
    uint32_t ota_use_randon_address: 1;
    uint32_t ota_adv_with_image_version: 1;
    uint32_t ota_with_encryption_data: 1;
    uint32_t ota_with_encryption_use_aes256: 1;
    uint32_t ota_with_encryption_aes_type: 2;
    uint32_t ota_resvd: 1;
    uint32_t ota_link_loss_reset: 1;
    uint32_t ota_use_buffer_check: 1;
    uint32_t ota_rsrvd: 23;

    uint8_t ota_rst_tgt_name[8];

    uint8_t ota_timeout_total;
    uint8_t ota_timeout_wait4_conn;
    uint8_t ota_timeout_wait4_image_transfer;
    uint8_t ota_timeout_ctittv;

    uint8_t ota_adv_random_address[6];
} __attribute__((packed)) T_OTP_OTA;

/**
 * @struct EFUSE_PLATFORM_CONFIG_
 * @brief Platform EFuse settings.
 *
 * Refer to EFUSE[0x].
 */
typedef struct EFUSE_PLATFORM_CONFIG_
{
    uint64_t trace_mask[4];              /* need to be put to first to avoid alignment access fault */

    uint16_t stack_en : 1;
    uint16_t cpu_sleep_en: 1;            /* default = 0 */
    uint16_t run_in_app : 1;             /* boot runs in app */
    uint16_t ftl_init_in_rom : 1;
    uint16_t rsvd0 : 12;

    uint32_t logPin : 6;                 /* default = P0_3 */
    uint32_t logChannel : 2;             /* LogChannel_TypeDef: default is LOG_CHANNEL_LOG1_UART */
    uint32_t logBaudRate : 5;            /* UartBaudRate_TypeDef: default is BAUD_RATE_2000000 */
    uint32_t enableROMMPU : 1;           /* protect rom as Read-only region, default = 1 */
    uint32_t logThreshold : 3;           /* Log threshold: default = 3 (256 = 1 << (5 + 3) */
    uint32_t logDisable : 1;             /* Disable all DBG_DIRECT and DBG_BUFFER log */
    uint32_t dump_info_before_reset : 1;
    uint32_t write_info_to_flash_before_reset : 1;
    uint32_t wait_log_transferred: 1;    /* Wait log transferred */
    uint32_t log_ram_type : 1;           /* config all ram always on */
    uint32_t ftl_mapping_table_ram_type : 1;
    uint32_t ftl_enable_write_skip : 1; /*if enable, if read value equal write value will skip*/
    uint32_t ftl_logic_addr_map_bit_num : 3; /*4bit by step, default value is 3 means 12bit*/
    uint32_t rsvd1 : 2;
    uint32_t damaged_img_id : 3;         /*single bank ota, 1-7 means App-AppData6 was damaged*/

    uint32_t aes_key[8];                 /* for OTA encryption */
    uint32_t reboot_record_address;      /* start address of reboot record */

    uint32_t reboot_record_item_limit_power_2 : 4;   /* max number of reboot record (2^n)*/
    uint32_t adp_det_timeout : 8;        /* ADP Det software debouncing timeout, 10ms per bit */
    uint32_t adc_mgr_queue : 4;
    uint32_t wdgIP   : 1;                /* default = 0 */
    uint32_t resetWhenHardFault : 1;     /* default = 0 */
    uint32_t log_ram_size : 3;           /* default = 2 (actual size = 256 * (1 + log_ram_size) */
    uint32_t hardfault_print_buf_log : 1;/* Print buffered log in hard fault handler */
    uint32_t adc_ext_channel : 8;        /* adc external channel load calibration data config */
    uint32_t log_timestamp_src : 2;      /* 0: Use OS Tick, not sync, 1: Use HW Timer 7, 2: RSVD */

    uint32_t adc_channel: 10;            /* internal channel and differential channel. */
    uint32_t tim5_divider : 3;           /* HW Timer 5 divider when it is used as log timestamp */
    uint32_t systick_clk_src: 1;         /* Select systick timer clock source */
    uint32_t enable_auto_clk_gating: 1;  /* Enable RXI300 Auto Clock Gating */
    uint32_t bz_sync_delay: 10;          /* default 200us */
    uint32_t low_power_mode_enable_interrupt_early: 1;
    uint32_t ftl_use_mapping_table: 1;
    uint32_t ftl_app_logical_addr_base: 3;
    uint32_t ftl_only_gc_in_idle: 1;
    uint32_t write_info_to_flash_when_hardfault: 1;

    uint32_t systick_ext_clk_freq;       /* External systick timer clock frequency */
    uint32_t share_cache_ram_reg;        /* Hashed value to be written to secure register */
    uint32_t ftl_real_logic_addr_size;   /* FTL real logic address size */

    uint32_t os_tick_rate_HZ;

    T_OTP_OTA ota __attribute__((aligned(4)));

    RAM_CONFIG ram_cfg[MEMCFG_MAX];

#ifdef _IS_ASIC_
    uint8_t sys_init_param[58];
#endif

} __attribute__((packed)) SYS_INIT_CONFIG;

typedef enum
{
    SYSTICK_EXT_32K = 32000,
    SYSTICK_EXT_32K768 = 32768,
    SYSTICK_EXT_1M = 1000000,
} SYSTICK_EXT_CLK_FREQ_TYPE;

extern SYS_INIT_CONFIG sys_init_cfg;

#endif
