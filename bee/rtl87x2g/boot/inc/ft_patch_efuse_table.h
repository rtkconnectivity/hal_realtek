#ifndef _EFUSE_TABLE_H_
#define _EFUSE_TABLE_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define _PACKED_                __attribute__((packed))
#ifdef __cplusplus
extern "C" {
#endif
#ifndef   __STATIC_INLINE
#define __STATIC_INLINE         static inline
#endif

#define EFUSE_TOTAL_SIZE                              1024
#define EFUSE_AON_LOADER_SIZE                         200

#define EFUSE_FT_SYSTEM_SIZE                          3
#define EFUSE_ZIGBEE_SIZE                             36
#define EFUSE_FT_PMU_SIZE                             24
#define EFUSE_FT_PHY_SIZE                             179
#define EFUSE_FT_AUXADC_SIZE                          32
#define EFUSE_FT_XTAL_SIZE                            10
#define EFUSE_FT_SDADC_SIZE                           3
#define EFUSE_FT_MAC_SIZE                             1
#define EFUSE_FT_USB_SIZE                             8
#define EFUSE_FT_SIZE                                 (EFUSE_FT_SYSTEM_SIZE + EFUSE_ZIGBEE_SIZE + EFUSE_FT_PMU_SIZE + EFUSE_FT_PHY_SIZE + EFUSE_FT_AUXADC_SIZE + EFUSE_FT_XTAL_SIZE + EFUSE_FT_SDADC_SIZE + EFUSE_FT_MAC_SIZE + EFUSE_FT_USB_SIZE)  // 296 byte

#define EFUSE_FT_COMMON_SIZE                          1
#define EFUSE_SEC_PASSWD_RETRY_SIZE                   8
#define EFUSE_SEC_SECURE_BOOT_PROTECT                 3
#define EFUSE_SEC_PIN_WAKEUP_CTRL                     2
#define EFUSE_SEC_IMG_AUTH_CTRL                       6
#define EFUSE_SEC_IMG_KEY_SEL_CTRL                    11
#define EFUSE_SEC_SPECIFIC_HW_LOCK                    3
#define EFUSE_SEC_SPECIFIC_HW_CTRL                    9
#define EFUSE_SEC_DEBUG_INTERFACE_CTRL                2
#define EFUSE_SEC_SYSTEM_FUNC_CTRL                    4
#define EFUSE_SEC_GENERAL_FUNC_CTRL                   4
#define EFUSE_SEC_SLAVE_ACCESS_FILTER                 14
#define EFUSE_SEC_MASTER_SECURE_CTRL                  2
#define EFUSE_SEC_PASSWORD_FUNC_CTRL                  2
#define EFUSE_SEC_PRIVATE_FUNC_CTRL                   1
#define EFUSE_SEC_BOOTPATCH_VER_SIZE                  4
#define EFUSE_SEC_SECUREMCUAPP_VER_SIZE               4
#define EFUSE_SEC_MCUAPP_VER_SIZE                     8
#define EFUSE_SEC_MCUPATCH_VER_SIZE                   4
#define EFUSE_SEC_MERGED_OTAHEADER_VER_SIZE           (EFUSE_SEC_MCUAPP_VER_SIZE + EFUSE_SEC_MCUPATCH_VER_SIZE)
#define EFUSE_SEC_SHA256_BYTE_SIZE                    32
#define EFUSE_SEC_SYMMETRIC_KEY_SIZE                  16
#define EFUSE_SEC_BOOT_CFG_PARSING_ADDR_SIZE          2
#define EFUSE_SEC_DIRESCT_ACCESS_PARSING_ADDR_SIZE    2
#define EFUSE_MPL_SIZE                                4
#define EFUSE_FT_ID_PARA_SIZE                         26
#define EFUSE_FT_END_BYTE_SIZE                        2
#define EFUSE_RESERVED_SIZE                           (EFUSE_TOTAL_SIZE - EFUSE_AON_LOADER_SIZE - EFUSE_FT_COMMON_SIZE - EFUSE_FT_SIZE)

#define EFUSE_FT_PHY_ON_RAM_ADDR                      0x328400
#define EFUSE_FT_PMU_ON_RAM_ADDR                      0x203F30

/* security life cycle state */
typedef enum
{
    LCS_NON_SECURE_TEST      = 0xFF,
    LCS_SECURE_ENABLE        = 0xFC,
    LCS_DECOMMISSIONED        = 0x0
} LCS;

// #pragma diag_suppress 40 /* disable warning #40-D: expected an identifier)*/
typedef struct _PACKED_
{
    uint8_t end_byte[EFUSE_FT_END_BYTE_SIZE];
    uint8_t efuse_signature;
    uint8_t in_stock_number;
    uint8_t ft_version;
    uint8_t password_retry[EFUSE_SEC_PASSWD_RETRY_SIZE];
    uint8_t bp_ver_ref[EFUSE_SEC_BOOTPATCH_VER_SIZE];
    union
    {
        struct
        {
            uint8_t mcu_app_ver_ref[EFUSE_SEC_MCUAPP_VER_SIZE];
            uint8_t mcu_patch_ver_ref[EFUSE_SEC_MCUPATCH_VER_SIZE];
        };
        struct
        {
            uint8_t merged_ota_header_ver_ref[EFUSE_SEC_MERGED_OTAHEADER_VER_SIZE];
        };
    };
    uint8_t secure_mcu_app_ver_ref[EFUSE_SEC_SECUREMCUAPP_VER_SIZE];

    uint8_t header_size;
    uint8_t inv_header_size;
    uint8_t boot_cfg_parsing_addr[EFUSE_SEC_BOOT_CFG_PARSING_ADDR_SIZE];
    uint8_t direct_access_parsing_addr[EFUSE_SEC_DIRESCT_ACCESS_PARSING_ADDR_SIZE];
    union
    {
        uint8_t mp_loader_config[EFUSE_MPL_SIZE];
        struct _PACKED_
        {
            uint8_t mpl_try_cnt;
            uint8_t mpl_timeout;
            /* wire_mode:
                    2w: 3'b111,3'b101,3'b100,3'b001;
                    1w: 3'b011;
                    select by gpio: 3'b110,3'b010,3'b000
            */
            uint8_t mpl_wire_mode: 3;
            uint8_t mpl_pin_index: 3;
            uint8_t mpl_1w_hci: 2;
            /* single_wire_mode_sel:
                    sw: 3'b111,3'b001,3'b010,3'b100;
                    hw: 3'b011;3'b101, 3'b110, 3'b000
            */
            uint8_t mpl_single_wire_mode_sel: 3;
            uint8_t mpl_reserved: 5;
        };
    };
    union
    {
        uint8_t ft_id[EFUSE_FT_ID_PARA_SIZE];
        struct _PACKED_
        {
            uint8_t package_id;
            uint8_t package_id_inverse;
            uint8_t euid[14];
            uint8_t num_of_zeros_euid;
            uint8_t inv_num_of_zeros_euid;
            uint8_t app_euid[4];
            uint8_t num_of_zeros_app_euid;
            uint8_t inv_num_of_zeros_app_euid;
            uint8_t oem_id[2];
        };
    };
    union
    {
        uint8_t secure_boot_protect[EFUSE_SEC_SECURE_BOOT_PROTECT];
        struct _PACKED_
        {
            uint8_t secure_boot_more_if_check: 4;
            uint8_t secure_boot_counter_check: 4;
            uint8_t secure_boot_insert_random: 4;
            uint8_t secure_boot_ota_bank_check: 4;
            uint8_t secure_boot_swd_early_enable_check: 4;
            uint8_t secure_boot_protect_rsvd: 4;
        };
    };
    union
    {
        uint8_t pin_wakeup_ctrl[EFUSE_SEC_PIN_WAKEUP_CTRL];
        struct _PACKED_
        {
            uint8_t enable_p3_0_wakeup: 1;
            uint8_t enable_p3_1_wakeup: 1;
            uint8_t enable_p1_0_wakeup: 1;
            uint8_t enable_p1_1_wakeup: 1;
            uint8_t p3_0_wakeup_polarity: 1;
            uint8_t p3_1_wakeup_polarity: 1;
            uint8_t p1_0_wakeup_polarity: 1;
            uint8_t p1_1_wakeup_polarity: 1;
            uint8_t flash_power_source: 2;
            uint8_t hci_uart_pin_sel: 4;
            uint8_t lowerstack_disable: 1;
            uint8_t pin_wakeup_ctrl_rsvd: 1;
        };
    };
    union
    {
        uint8_t img_auth_ctrl[EFUSE_SEC_IMG_AUTH_CTRL];
        struct _PACKED_
        {
            uint8_t img_bootpatch_not_auth: 2;
            uint8_t img_ota_not_auth: 2;
            uint8_t img_securepatch_not_auth: 2;
            uint8_t img_securemcuapp_not_auth: 2;
            uint8_t img_securemcuappdata_not_auth: 2;
            uint8_t img_not_auth_rsvd0: 2;       //must rsvd for reserved image_id
            uint8_t img_not_auth_rsvd1: 2;       //must rsvd for reserved image_id
            uint8_t img_stackpatch_not_auth: 2;  //must rsvd for reserved image_id
            uint8_t img_mcupatch_not_auth: 2;
            uint8_t img_upperstack_not_auth: 2;
            uint8_t img_mcuapp_not_auth: 2;
            uint8_t img_mcucfgdata_not_auth: 2;
            uint8_t img_not_auth_rsvd2: 2;      //must rsvd for reserved image_id
            uint8_t img_not_auth_rsvd3: 2;      //must rsvd for reserved image_id
            uint8_t img_not_auth_rsvd4: 2;      //must rsvd for reserved image_id
            uint8_t img_mcudata1_not_auth: 2;
            uint8_t img_mcudata2_not_auth: 2;
            uint8_t img_mcudata3_not_auth: 2;
            uint8_t img_mcudata4_not_auth: 2;
            uint8_t img_mcudata5_not_auth: 2;
            uint8_t img_mcudata6_not_auth: 2;
            uint8_t auth_each_image_in_bank: 2;
            uint8_t img_auth_ctrl_rsvd: 4;
        };
    };
    union
    {
        uint8_t img_key_sel_ctrl[EFUSE_SEC_IMG_KEY_SEL_CTRL];
        struct _PACKED_
        {
            uint8_t img_bootpatch_auth_key: 4;
            uint8_t img_ota_auth_key: 4;
            uint8_t img_securepatch_auth_key: 4;
            uint8_t img_securemcuapp_auth_key: 4;
            uint8_t img_securemcuappdata_auth_key: 4;
            uint8_t img_auth_key_rsvd0: 4;      //must rsvd for reserved image_id
            uint8_t img_auth_key_rsvd1: 4;      //must rsvd for reserved image_id
            uint8_t img_stackpatch_auth_key: 4; //must rsvd for reserved image_id
            uint8_t img_mcupatch_auth_key: 4;
            uint8_t img_upperstack_auth_key: 4;
            uint8_t img_mcuapp_auth_key: 4;
            uint8_t img_mcucfgdata_auth_key: 4;
            uint8_t img_auth_key_rsvd2: 4;      //must rsvd for reserved image_id
            uint8_t img_auth_key_rsvd3: 4;      //must rsvd for reserved image_id
            uint8_t img_auth_key_rsvd4: 4;      //must rsvd for reserved image_id
            uint8_t img_mcudata1_auth_key: 4;
            uint8_t img_mcudata2_auth_key: 4;
            uint8_t img_mcudata3_auth_key: 4;
            uint8_t img_mcudata4_auth_key: 4;
            uint8_t img_mcudata5_auth_key: 4;
            uint8_t img_mcudata6_auth_key: 4;
            uint8_t rsvd : 4;
            uint8_t secure_lifecycle_state: 8;
        };
    };
    union
    {
        uint8_t specific_hw_lock[EFUSE_SEC_SPECIFIC_HW_LOCK];
        struct _PACKED_
        {
            uint8_t not_reg_w1o_aeskey2_lock: 2;
            uint8_t not_reg_w1o_aeskey3_lock: 2;
            uint8_t not_reg_w1o_aeskey4_lock: 2;
            uint8_t not_reg_w1o_scek_lock: 2;
            uint8_t not_reg_w1o_key_auto_load_lock: 2;
            uint8_t ignore_rot_validation: 2;
            uint8_t not_saf_lock: 2;
            uint8_t not_sc_lock: 2;
            uint8_t not_slv_acc_lock: 2;
            uint8_t not_xo_range_lock: 2;
            uint8_t specific_hw_lock_rsvd: 4;
        };
    };
    union
    {
        uint8_t specific_hw_ctrl[EFUSE_SEC_SPECIFIC_HW_CTRL];
        struct _PACKED_
        {
            uint8_t not_reg_aon_w1o_repaired_mode_lock: 2;
            uint8_t not_reg_aon_w1o_test_row_en_lock: 2;
            uint8_t not_reg_aon_w1o_test_mode_sel_lock: 2;
            uint8_t not_reg_key_auto_load_en: 2;
            uint8_t not_reg_aon_w1o_dsp1_dis: 2;
            uint8_t not_reg_aon_w1o_dsp1_jtag_dis: 2;
            uint8_t not_reg_aon_w1o_vad_dis: 2;
            uint8_t not_reg_aon_w1o_vadbuf_dis: 2;
            uint8_t not_reg_aon_w1o_spk1_dis: 2;
            uint8_t not_reg_aon_w1o_spk2_dis: 2;
            uint8_t not_reg_aon_w1o_mic1_dis: 2;
            uint8_t not_reg_aon_w1o_mic2_dis: 2;
            uint8_t not_reg_aon_w1o_mic3_dis: 2;
            uint8_t not_reg_aon_w1o_mic4_dis: 2;
            uint8_t not_reg_aon_w1o_mic5_dis: 2;
            uint8_t not_reg_aon_w1o_mic6_dis: 2;
            uint8_t not_reg_aon_w1o_spic1_dis: 2;
            uint8_t not_reg_aon_w1o_spic2_dis: 2;
            uint8_t not_reg_aon_w1o_spic3_dis: 2;
            uint8_t not_reg_aon_w1o_spic0_ft_dis: 2;
            uint8_t not_reg_aon_w1o_spic0_mp_dis: 2;
            uint8_t not_reg_aon_w1o_spic0_dbg_dis: 2;
            uint8_t not_reg_aon_w1o_guardtime_agc_dis: 2;
            uint8_t not_reg_aon_w1o_pn_cfo_comp_dis: 2;
            uint8_t not_reg_aon_w1o_detail_rxrpt_dis: 2;
            uint8_t not_reg_aon_w1o_detail_rxrpt_cfoe_dis: 2;
            uint8_t not_reg_aon_w1o_sniff_half_slot_dis: 2;
            uint8_t not_reg_aon_w1o_sniff1_func_dis: 2;
            uint8_t not_reg_aon_w1o_sniff2_func_dis: 2;
            uint8_t not_reg_aon_w1o_handover_func_dis: 2;
            uint8_t not_reg_aon_w1o_bt2_func_dis: 2;
            uint8_t not_reg_aon_w1o_bt4_func_dis: 2;
            uint8_t not_reg_aon_w1o_pa_func_dis: 2;
            uint8_t not_reg_aon_w1o_cis_func_dis: 2;
            uint8_t not_reg_aon_w1o_bis_func_dis: 2;
            uint8_t enable_cpu_snapshot_dump: 2;
        };
    };
    union
    {
        uint8_t debug_interface_ctrl[EFUSE_SEC_DEBUG_INTERFACE_CTRL];
        struct _PACKED_
        {
            uint8_t dbg_app: 4;                         /* control km4 secure debug enable when app */
            uint8_t dbg_boot: 2;                        /* control km4 secure debug enable when boot */
            uint8_t early_enable_swd: 2;                /* 00: do not enable km4 swd eariler */
            uint8_t dbg_ota_bank: 2;
            uint8_t dbg_boot_batch: 2;
            uint8_t dbg_secure_app: 2;
            uint8_t enable_swd_pad_config_in_rom: 2;    /* 11: config pinmux and pad in rom */
        };
    };
    union
    {
        uint8_t system_func_ctrl[EFUSE_SEC_SYSTEM_FUNC_CTRL];
        struct _PACKED_
        {
            uint8_t flash_disable_4byte_addr_mode: 2;
            uint8_t only_one_ota_bank: 2;
            uint8_t enable_dsp_function_spic_access: 2;
            uint8_t enable_aes_dma_mode: 2;
            uint8_t enable_dump_info_before_reset: 2;
            uint8_t set_active_clk_in_boot_loader: 2;
            uint8_t disable_pll_in_boot_loader: 2;
            uint8_t disable_efuse_bank0_read_protect: 2;
            uint8_t disable_efuse_bank0_write_protect: 2;
            uint8_t disable_efuse_bank1_read_protect: 2;
            uint8_t disable_efuse_bank1_write_protect: 2;
            uint8_t disable_image_auth_when_resume: 2;
            uint8_t disable_ram_patch_auth: 2;
            uint8_t enable_set_reg_by_otp: 2;
            uint8_t disable_limit_dbg_pw_retry_cnt: 2;
            uint8_t disable_slow_down_spic0_for_xtal_issue: 2;
        };
    };
    union
    {
        uint8_t general_func_ctrl[EFUSE_SEC_GENERAL_FUNC_CTRL];
        struct _PACKED_
        {
            uint8_t enable_mpl_ram_patch: 2;
            uint8_t enable_mpl_flash_access: 2;
            uint8_t enable_mpl_system_access: 2;
            uint8_t enable_mpl_otp_access: 2;
            uint8_t enable_hci_mac_rf_access: 2;
            uint8_t enable_hci_wifi_coexist_func: 2;
            uint8_t enable_hci_set_uart_baudrate: 2;
            uint8_t enable_hci_rf_dbg_func: 2;
            uint8_t enable_hci_read_chip_info: 2;
            uint8_t enable_hci_bt_extension: 2;
            uint8_t enable_hci_bt_dbg_func: 2;
            uint8_t enable_hci_bt_test: 2;
            uint8_t enable_hci_rf_test: 2;
            uint8_t disable_user_mode_app: 2;
            uint8_t general_func_ctrl_rsvd: 4;
        };
    };
    union
    {
        uint8_t slave_access_filter[EFUSE_SEC_SLAVE_ACCESS_FILTER];
        struct _PACKED_
        {
            // 00: secure, 11: non-secure
            uint8_t saf_aon_nonsec_slave: 2;
            uint8_t saf_peri_on_nonsec_slave: 2;
            uint8_t saf_soc_vendor_reg_nonsec_slave: 2;
            uint8_t saf_ir_rc_nonsec_slave: 2;
            uint8_t saf_qdec_nonsec_slave: 2;
            uint8_t saf_gmac_ctrl_nonsec_slave: 2;
            uint8_t saf_spic0_nonsec_slave: 2;
            uint8_t saf_spic1_nonsec_slave: 2;
            uint8_t saf_spic2_nonsec_slave: 2;
            uint8_t saf_spi0_nonsec_slave: 2;
            uint8_t saf_spi1_nonsec_slave: 2;
            uint8_t saf_spi_slave_nonsec_slave: 2;
            uint8_t saf_rtzip_nonsec_slave: 2;
            uint8_t saf_enhanced_timer_nonsec_slave: 2;
            uint8_t saf_modemrfcpi_nonsec_slave: 2;
            uint8_t saf_usb_otg_cfg_nonsec_slave: 2;
            uint8_t saf_i2s0_nonsec_slave: 2;
            uint8_t saf_i2s1_nonsec_slave: 2;
            uint8_t saf_spi_codec_nonsec_slave: 2;
            uint8_t saf_display_ctrl_nonsec_slave: 2;
            uint8_t saf_iso7816_nonsec_slave: 2;
            uint8_t saf_segcom_ctl_nonsec_slave: 2;
            uint8_t saf_bluewiz_nonsec_slave: 2;
            uint8_t saf_bt_vendor_reg_nonsec_slave: 2;
            uint8_t saf_zigbee_nonsec_slave: 2;
            uint8_t saf_sdio_host0_cfg_nonsec_slave: 2;
            uint8_t saf_gpioa_nonsec_slave: 2;
            uint8_t saf_gpiob_nonsec_slave: 2;
            uint8_t saf_timer_nonsec_slave: 2;
            uint8_t saf_sar_adc_nonsec_slave: 2;
            uint8_t saf_adc_24bit_nonsec_slave: 2;
            uint8_t saf_spi_3wire_nonsec_slave: 2;

            uint8_t saf_uart0_nonsec_slave: 2;
            uint8_t saf_uart1_nonsec_slave: 2;
            uint8_t saf_uart2_nonsec_slave: 2;
            uint8_t saf_uart3_nonsec_slave: 2;
            uint8_t saf_i2c0_nonsec_slave: 2;
            uint8_t saf_i2c1_nonsec_slave: 2;
            uint8_t saf_key_scan_nonsec_slave: 2;
//            uint8_t saf_public_key_engine_nonsec_slave: 2;
//            uint8_t saf_flash_sec_nonsec_slave: 2;
//            uint8_t saf_aes_nonsec_slave: 2;
//            uint8_t saf_sha256_nonsec_slave: 2;
//            uint8_t saf_trng_nonsec_slave: 2;
//            uint8_t saf_efuse_controller_nonsec_slave: 2;
            uint8_t saf_spi0_hs_nonsec_slave: 2;
            uint8_t saf_rxi350_dmac_cfg_nonsec_slave: 2;
            uint8_t saf_ppe_cfg_nonsec_slave: 2;
            uint8_t saf_can_nonsec_slave: 2;
            uint8_t saf_spic_phy_nonsec_slave: 2;
            uint8_t saf_i2c2_nonsec_slave: 2;
            uint8_t saf_i2c3_nonsec_slave: 2;
            uint8_t saf_uart4_nonsec_slave: 2;
            uint8_t saf_uart5_nonsec_slave: 2;
            uint8_t saf_dummy0_nonsec_slave: 2;
            uint8_t saf_dummy1_nonsec_slave: 2;
            uint8_t saf_dummy2_nonsec_slave: 2;
            uint8_t saf_dummy3_nonsec_slave: 2;
            uint8_t saf_nonsec_slave_lock: 2;

            uint8_t slave_access_filter_rsvd0: 6;
        };
    };
    union
    {
        uint8_t master_secure_control[EFUSE_SEC_MASTER_SECURE_CTRL];
        struct _PACKED_
        {
            // 00: non-secure, 11: secure
            uint8_t usbotg_hnonsec: 2;
            uint8_t sdio_host0_hnonsec: 2;
            uint8_t display_arprot_1: 2;
            uint8_t gmac_m_arprot_1: 2;
            uint8_t gmac_m_awprot_1: 2;
            uint8_t sc_hnonsec_lock: 2;
            uint8_t master_secure_control_rsvd0: 4;
        };
    };
    union
    {
        uint8_t password_func_ctrl[EFUSE_SEC_PASSWORD_FUNC_CTRL];
        struct _PACKED_
        {
            uint8_t pw_enable_mpl_ram_patch: 2;
            uint8_t pw_enable_mpl_flash_access: 2;
            uint8_t pw_enable_mpl_system_access: 2;
            uint8_t pw_enable_mpl_otp_access: 2;
            uint8_t pw_disable_efuse_bank0_read_protect: 2;
            uint8_t pw_disable_efuse_bank0_write_protect: 2;
            uint8_t pw_disable_efuse_bank1_read_protect: 2;
            uint8_t pw_disable_efuse_bank1_write_protect: 2;
        };
    };
    union
    {
        uint8_t private_func_ctrl[EFUSE_SEC_PRIVATE_FUNC_CTRL];
        struct _PACKED_
        {
            uint8_t image_auth_approach: 3;         // 3'b100: rsa, 3'b010: ed25519, 3'b001: ecdsa
            uint8_t disable_boot_patch: 2;
            uint8_t disable_boot_failed: 2;         // 00: boot failed even when normal boot
            uint8_t private_func_ctrl_rsvd: 1;
        };
    };
    uint32_t boot_patch_addr;
    uint32_t occd_base_addr;
    uint32_t ft_phy_on_ram_addr;
    uint32_t ft_pmu_on_ram_addr;
    uint8_t hci_rx_pin;
    uint8_t hci_tx_pin;
    uint8_t sha256_pub_auth_key3[EFUSE_SEC_SHA256_BYTE_SIZE];
    uint8_t num_of_zeros_sha256_3;
    uint8_t inv_num_of_zeros_sha256_3;
    uint8_t sha256_pub_auth_key2[EFUSE_SEC_SHA256_BYTE_SIZE];
    uint8_t num_of_zeros_sha256_2;
    uint8_t inv_num_of_zeros_sha256_2;
    uint8_t sha256_pub_auth_key[EFUSE_SEC_SHA256_BYTE_SIZE];
    uint8_t num_of_zeros_sha256;
    uint8_t inv_num_of_zeros_sha256;
    uint8_t debug_password_ref[EFUSE_SEC_SYMMETRIC_KEY_SIZE];
    uint8_t num_of_zeros_dpr;
    uint8_t inv_num_of_zeros_dpr;
    uint8_t scek[EFUSE_SEC_SYMMETRIC_KEY_SIZE];
    uint8_t num_of_zeros_scek;
    uint8_t inv_num_of_zeros_scek;
    uint8_t ocek[EFUSE_SEC_SYMMETRIC_KEY_SIZE];
    uint8_t num_of_zeros_ocek;
    uint8_t inv_num_of_zeros_ocek;
    uint8_t fpk[EFUSE_SEC_SYMMETRIC_KEY_SIZE];
    uint8_t num_of_zeros_fpk;
    uint8_t inv_num_of_zeros_fpk;
    uint8_t eek[EFUSE_SEC_SYMMETRIC_KEY_SIZE];
    uint8_t num_of_zeros_eek;
    uint8_t inv_num_of_zeros_eek;
    uint8_t aeskey2[EFUSE_SEC_SYMMETRIC_KEY_SIZE];
    uint8_t num_of_zeros_aeskey2;
    uint8_t inv_num_of_zeros_aeskey2;
} EFUSE_MAP;

/* ========= Definition of FT Fields ========= */
typedef union _EFUSE_CALIBRATION_INFO
{
    uint8_t d8;
    struct _PACKED_
    {
        uint8_t version: 7;
        uint8_t invalid: 1;
    };
} EFUSE_CALIBRATION_INFO;

/* ========= Definition of SYSTEM Fields ========= */
typedef union _FT_SYSTEM_TYPE
{
    uint8_t d8;
    struct _PACKED_
    {
        uint8_t flash_type : 1;  // 0: mcm flash; 1: others
        uint8_t psram_type : 1;  // 0: mcm psram; 1: others
        uint8_t reserved : 6;
    };
} FT_SYSTEM_TYPE;

typedef union _EFUSE_FT_SYSTEM
{
    uint8_t d8[EFUSE_FT_SYSTEM_SIZE];
    struct _PACKED_
    {
        uint8_t system_info;
        FT_SYSTEM_TYPE system_type;

        uint8_t rsvd;
    };
} EFUSE_FT_SYSTEM;

/* ========= Definition of PMU Fields ========= */
typedef union _EFUSE_PMU_INVALID
{
    uint16_t d16;
    struct _PACKED_
    {
        uint16_t vddcore_ldo: 1;
        uint16_t vddcore_pfm: 1;
        uint16_t vddcore_pwm: 1;
        uint16_t vret: 1;
        uint16_t vdigi: 1;
        uint16_t va18: 1;
        uint16_t micbias: 1;
        uint16_t saw_freq: 1;
        uint16_t rsvd: 8;
    };
} EFUSE_PMU_INVALID;

typedef union _EFUSE_PMU_SAW_FREQ
{
    uint8_t d8;
    struct _PACKED_
    {
        uint8_t tune: 4;
        uint8_t add_current: 1;
        uint8_t rsvd: 3;
    };
} EFUSE_PMU_SAW_FREQ;

typedef union _EFUSE_FT_PMU
{
    uint8_t d8[EFUSE_FT_PMU_SIZE];
    struct _PACKED_
    {
        uint8_t pmu_version;
        EFUSE_PMU_INVALID pmu_invalid;
        uint16_t vddcore_ldo_gain_err;
        uint16_t vddcore_pfm_gain_err;
        uint16_t vddcore_pwm_gain_err;
        uint16_t vret_gain_err;
        uint16_t vdigi_gain_err;
        uint16_t va18_gain_err;
        uint16_t micbias_gain_err;
        EFUSE_PMU_SAW_FREQ saw_freq;
        uint8_t rsvd[6];
    };
} EFUSE_FT_PMU;

/* ========== Definition of PHY Fields ========== */
typedef union _EFUSE_PHY_INVALID
{
    uint8_t d8[6];
    struct _PACKED_
    {
        uint32_t rxadck_invalid: 1;
        uint32_t rck_invalid: 1;
        uint32_t tmeter_invalid: 1;
        uint32_t tx_lck_invalid: 1;
        uint32_t rx_lck_invalid: 1;
        uint32_t kvco2k_invalid: 1;
        uint32_t tpmk_invalid: 1;
        uint32_t tpm_txgaink_invalid: 1;

        uint32_t tpm_rxgaink_invalid: 1;
        uint32_t pad_current_k_invalid: 1;
        uint32_t ibg50u_current_k_invalid: 1;
        uint32_t pa_current_k_invalid: 1;
        uint32_t vco_4g8_current_k_invalid: 1;
        uint32_t lna_current_k_invalid: 1;
        uint32_t vco_3g6_current_k_invalid: 1;
        uint32_t lna_ldo_invalid: 1;

        uint32_t rxiqg_ldo_invalid: 1;
        uint32_t rxbb_ldo_invalid: 1;
        uint32_t tx1_ldo_invalid: 1;
        uint32_t tx2_bias_ldo_invalid: 1;
        uint32_t tx2_buf_ldo_invalid: 1;
        uint32_t tx2_driver_ldo_invalid: 1;
        uint32_t vco_ldo_invalid: 1;
        uint32_t synd_ldo_invalid: 1;

        uint32_t syna_ldo_invalid: 1;
        uint32_t mxr_ldo_invalid: 1;
        uint32_t tpmk_adc_ldo_invalid: 1;
        uint32_t afe_ldo_invalid: 1;

        uint32_t rsvd: 20;
    };
} EFUSE_PHY_INVALID;

typedef union _EFUSE_FT_PHY
{
    uint8_t d8[EFUSE_FT_PHY_SIZE];
    struct _PACKED_
    {
        uint8_t phy_version;
        EFUSE_PHY_INVALID phy_invalid;
        uint8_t rxadck;
        uint8_t rck;
        uint8_t tmeter_val;
        uint8_t tmeter_ft_degree;
        uint8_t tx_lck[24];
        uint8_t rx_lck[24];
        uint8_t kvco2k[2];
        uint16_t tpmk[11];
        int8_t tpm_txgaink;
        uint8_t tpm_rxgaink[4];
        uint8_t pad_current_k;
        uint8_t ibg50u_current_k;
        uint8_t pa_current_k;
        uint8_t vco_4g8_current_k;
        uint8_t lna_current_k;
        uint8_t vco_3g6_current_k;
        uint8_t lna_ldo;
        uint8_t rxiqg_ldo;
        uint8_t rxbb_ldo;
        uint8_t tx1_ldo;
        uint8_t tx2_bias_ldo;
        uint8_t tx2_buf_ldo;
        uint8_t tx2_driver_ldo;
        uint8_t vco_ldo;
        uint8_t synd_ldo;
        uint8_t syna_ldo;
        uint8_t mxr_ldo;
        uint8_t tpmk_adc_ldo;
        uint8_t afe_ldo;
        uint8_t phy_rsvd[72];
    };
} EFUSE_FT_PHY;

/* ========== Definition of AUXADC Fields ========== */
typedef union _EFUSE_AUXADC_INVALID
{
    uint8_t d8[2];
    struct _PACKED_
    {
        uint8_t single_ended_divide: 1;
        uint8_t single_ended_bypass: 1;
        uint8_t differential_divide: 1;
        uint8_t differential_bypass: 1;
        uint16_t rsvd: 12;
    };
} EFUSE_AUXADC_INVALID;

typedef struct _PACKED_ _EFUSE_AUXADC_EXTERNAL_MODE
{
    int16_t divide_para_a;
    int16_t divide_para_b;
    int16_t divide_para_c;
    int16_t bypass_para_a;
    int16_t bypass_para_b;
    int16_t bypass_para_c;
} EFUSE_AUXADC_EXTERNAL_MODE;

typedef union _EFUSE_FT_AUXADC
{
    uint8_t d8[EFUSE_FT_AUXADC_SIZE];
    struct _PACKED_
    {
        uint8_t auxadc_version;
        EFUSE_AUXADC_INVALID auxadc_invalid;
        EFUSE_AUXADC_EXTERNAL_MODE se_mode;
        EFUSE_AUXADC_EXTERNAL_MODE df_mode;
        uint16_t divide_resistance_value;
        uint8_t auxadc_rsvd[3];
    };
} EFUSE_FT_AUXADC;

/* ========== Definition of XTAL Fields ========== */
typedef union _EFUSE_FT_XTAL
{
    uint8_t d8[EFUSE_FT_XTAL_SIZE];
    struct _PACKED_
    {
        uint8_t rsvd[10];
    };
} EFUSE_FT_XTAL;

/* ========== Definition of SDADC Fields ========== */
typedef union _EFUSE_FT_SDADC
{
    uint8_t d8[EFUSE_FT_SDADC_SIZE];
    struct _PACKED_
    {
        uint8_t rsvd[3];
    };
} EFUSE_FT_SDADC;

/* ========== Definition of MAC Fields ========== */
typedef union _EFUSE_FT_MAC
{
    uint8_t d8[EFUSE_FT_MAC_SIZE];
    struct _PACKED_
    {
        uint8_t rsvd[1];
    };
} EFUSE_FT_MAC;

/* ========== Definition of USB Fields ========== */

typedef union _EFUSE_USB_INVALID
{
    uint8_t d8;
    struct _PACKED_
    {
        uint8_t test_j_k_swing_invalid: 1;
        uint8_t squelch_level_invalid: 1;
        uint8_t rsvd: 6;
    };
} EFUSE_USB_INVALID;

typedef union _EFUSE_FT_USB
{
    uint8_t d8[EFUSE_FT_USB_SIZE];
    struct _PACKED_
    {
        uint8_t usb_version;
        EFUSE_USB_INVALID usb_invalid;
        uint8_t test_j_k_swing;
        uint8_t squelch_level;
        uint8_t rsvd[4];
    };
} EFUSE_FT_USB;

typedef union _EFUSE_FT_TABLE
{
    uint8_t d8[EFUSE_FT_SIZE];
    struct _PACKED_
    {
        EFUSE_FT_SYSTEM system;
        uint8_t zigbee[EFUSE_ZIGBEE_SIZE];
        EFUSE_FT_PMU pmu;
        EFUSE_FT_PHY phy;
        EFUSE_FT_AUXADC auxadc;
        EFUSE_FT_XTAL xtal;
        EFUSE_FT_SDADC sdadc;
        EFUSE_FT_MAC mac;
        EFUSE_FT_USB usb;
    };
} EFUSE_FT_TABLE;

typedef union
{
    uint8_t d8[EFUSE_FT_COMMON_SIZE];
    struct _PACKED_
    {
        uint8_t is_not_mcm : 1;
        uint8_t reserved : 7;
    };
} FT_COMMON_FORMAT;

typedef union
{
    uint8_t d8[EFUSE_TOTAL_SIZE];
    struct _PACKED_
    {
        uint8_t aon_loader[EFUSE_AON_LOADER_SIZE];    // 200 byte
        uint8_t reserved[EFUSE_RESERVED_SIZE - sizeof(EFUSE_MAP)];  //166 byte
        EFUSE_FT_TABLE ft_efuse_table;  // 296 byte
        FT_COMMON_FORMAT ft_common[EFUSE_FT_COMMON_SIZE];  // 1 byte
        EFUSE_MAP map;  // 361 byte
    };
} EFUSE_TABLE;

#define GET_EFUSE_ADDR(field) (offsetof(EFUSE_TABLE, map) + offsetof(EFUSE_MAP, field))
#define GET_EFUSE_FT_CAL_ADDR (offsetof(EFUSE_TABLE, ft_efuse_table))

#define EFUSE_DEFAULT_VALUE   0xFF

extern EFUSE_TABLE efuse_on_ram;

__STATIC_INLINE LCS get_security_lifecycle_state(void)
{
    return efuse_on_ram.map.secure_lifecycle_state;
}

#ifdef __cplusplus
}
#endif

#endif
