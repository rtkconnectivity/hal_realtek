/**
 * Copyright (c) 2015, Realsil Semiconductor Corporation. All rights reserved.
 */

#ifndef _PATCH_PLATFORM_H_
#define _PATCH_PLATFORM_H_

#include <stdarg.h>
#include <patch.h>
#include "clock_manager.h"
#include "pmu_manager.h"
#include "adapter.h"
#include "charger.h"
#include "power_manager.h"
#include "power_manager_unit_platform.h"
#include "portable.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "os_mem.h"
#include "os_queue.h"
#include "os_sched.h"
#include "os_sync.h"
#include "os_msg.h"
#include "os_task.h"
#include "os_timer.h"
#include "os_trace.h"
#include "ftl_api.h"
#include "utils.h"
#include "flash_nor_device.h"
#include "hw_aes_int.h"
#include "pingpong_buffer.h"
#include "adc_manager.h"
#include "log_uart_dma.h"
#include "ram_ctrl.h"
#include "debug_port.h"
#include "aon_wdg.h"
#include "phy_common_int.h"
#include "rfc_int.h"
#include "modem_int.h"
#include "phy_int.h"
#include "thermal.h"
#include "clock_manager_power_interface.h"
#include "platform_rtc.h"
#include "patch_header_check.h"
#include "occd_parser.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Patch of Efuse Driver */
bool efuse_one_byte_read_rom(uint16_t addr, uint8_t *data);
bool efuse_one_byte_write_rom(uint16_t addr, uint8_t data);

/* ============================ Patch of Secure Boot ============================ */
void boot_failed_rom(void);
bool efuse_header_size_verification_rom(void);
bool efuse_legality_rom(void);
void efuse_set_read_protect_rom(void);
void efuse_set_write_protect_rom(void);
void efuse_swd_control_rom(bool before_secure_boot);
void efuse_system_general_control_rom(void);
void efuse_update_parameter_rom(void);
bool image_authentication_rom(uint32_t img_addr, IMG_ID img_id);
bool image_decryption_rom(T_IMG_HEADER_FORMAT *header, uint32_t enc_len);
bool is_secure_boot_rom(void);
bool ram_image_authentication_rom(uint32_t addr, uint32_t size, IMG_ID img_id);
void efuse_set_write_protect_range_rom(bool enable, bool lock, uint16_t begin, uint16_t end);
void efuse_set_read_protect_range_rom(bool enable, bool lock, uint16_t begin, uint16_t end);

/* ============================ Patch of System Init ============================ */
void hal_setup_hardware_rom(void);
void hal_setup_cpu_rom(void);
bool mpu_setup_rom(void);
uint32_t read_cpu_counter_rom(void);
RTLNUM_Type get_soc_rtl_num_rom(void);
uint32_t get_occd_addr_rom(void);
uint32_t get_occd_size_rom(void);
uint32_t get_extra_occd_addr_rom(void);
uint32_t get_extra_occd_size_rom(void);

/* ============================================================================== */

/* ============================ Patch of log trace ============================== */
void timestamp_enter_dlps_cb_rom(void);
void timestamp_exit_dlps_cb_rom(void);
void log_direct_rom(const char *fmt, va_list  arg);
void log_snoop_rom(T_LOG_SUBTYPE subtype, uint16_t length, uint8_t *p_snoop);
extern bool (*patch_log_lowerstack)(uint8_t *l_msg);
extern bool (*patch_trace_assist)(T_LOG_SUBTYPE subtype, uint16_t length,
                                  char *p_data, uint8_t *l_msg, uint32_t *p_ret);
extern bool (*patch_log_stream)(T_LOG_SUBTYPE subtype, uint8_t module,
                                uint16_t length, uint8_t *p_data, uint8_t *l_msg);
/* ============================================================================== */

/* ============================ Patch of log buffer ============================= */
void log_uart_dma_init_rom(void);
void dsp_log_output_rom(void);
bool dsp_log_transport_rom(LogDMA_SM *me);
void log_dma_idle(LogDMA_SM *me, LogDMA_Signal signal);
void log_dma_process_mcu(LogDMA_SM *me, LogDMA_Signal signal);
void log_dma_process_dsp(LogDMA_SM *me, LogDMA_Signal signal);
void log_dma_pending_mcu(LogDMA_SM *me, LogDMA_Signal signal);
void log_dma_pending_dsp(LogDMA_SM *me, LogDMA_Signal signal);
void log_uart_dma_idle_hook_rom(void);
bool log_pm_check_rom(void);
void log_uart_dma_start_rom(uint8_t *p_buf, uint16_t size);
void sys_timestamp_init_rom(void);
void log_pm_exit_rom(void);
void log_pm_enter_rom(void);
/* ============================================================================== */

/* Used for clock manager  */
/*-------- Active clock gen ----------*/
void deinit_clock_core_domain_module_rom(void);
void clock_set_unit_cfg_rate_rom(ACTIVE_CLK_TYPE module, CLK_FREQ_TYPE clk_rate,
                                 CLK_FREQ_TYPE clk_rate_slow);
void clock_get_unit_cfg_rate_rom(ACTIVE_CLK_TYPE module, CLK_FREQ_TYPE *clk_rate,
                                 CLK_FREQ_TYPE *clk_rate_slow);
uint32_t get_SystemCpuClock_rom(void);
uint8_t count_clk_40m_div_rom(uint8_t clk_src_40m);
uint8_t count_clk_src_div_rom(uint32_t clk_src_type, uint32_t clk_rate_wanted);
uint8_t get_cpu_clk_div_rom(CORE_MODE mode);
uint8_t get_dsp_clk_div_rom(CORE_MODE mode);
void set_cpu_clock_divider(uint8_t div, uint8_t div_slow, uint32_t src_clk_rate);
void set_dsp_clock_divider(uint8_t div, uint8_t div_slow, uint32_t src_clk_rate);
void set_spic0_clock_divider(uint8_t div, uint8_t div_slow, uint32_t src_clk_rate);
void set_spic1_clock_divider(uint8_t div, uint8_t div_slow, uint32_t src_clk_rate);
void set_spic2_clock_divider(uint8_t div, uint8_t div_slow, uint32_t src_clk_rate);
void set_psram_clock_divider(uint8_t div, uint8_t div_slow, uint32_t src_clk_rate);
void set_40m_clock_divider(uint8_t div, uint8_t div_slow, uint32_t src_clk_rate);
void set_cpu_clk_mux_and_div(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_dsp_clk_mux_and_div(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_spic0_clk_mux_and_div(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_spic1_clk_mux_and_div(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_spic2_clk_mux_and_div(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_psram_clk_mux_and_div(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_40m_clk_mux_and_div(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_cpu_clock_rom(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_dsp_clock_rom(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_spic0_clock_rom(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_spic1_clock_rom(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_spic2_clock_rom(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_psram_clock_rom(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_40m_clock_rom(uint8_t clk_src, uint8_t div, uint8_t div_slow);
void set_clock_gen_rom(ACTIVE_CLK_TYPE type, ACTIVE_CLK_SRC_TYPE clk_src);
void set_clock_gen_rate_rom(ACTIVE_CLK_TYPE clk_load, CLK_FREQ_TYPE clk_rate,
                            CLK_FREQ_TYPE clk_rate_slow);
void set_active_mode_clk_src_rom(void);
void set_pllx_rate_rom(ACTIVE_CLK_SRC_TYPE pll_src, CLK_FREQ_TYPE pll_rate);
void get_pllx_rate_rom(ACTIVE_CLK_SRC_TYPE pll_src, uint32_t *pll_rate);
void set_osc40_clk_src_rom(bool is_enable);
void set_adc_dac_clock_rom(bool is_enable);
void set_xtal40_oscillate_rom(bool is_enable);
void set_xtal40_capacity_rom(uint8_t xtal_sc_xi, uint8_t xtal_sc_xo);
void set_xtal40_low_power_pdck_rom(void);
void set_xtal40_aac_calibration_rom(void);
void set_pll_clk_src_rom(ACTIVE_CLK_SRC_TYPE src_type, bool is_enable);
void set_pll_ldo_rom(bool is_enable);
void set_pll1_cko1_div_rom(uint32_t pll1_freq_hz);
void set_pll2_cko2_div_rom(uint32_t pll2_freq_hz);
void set_pll3_cko3_div_rom(uint32_t pll3_freq_hz);
void set_clock_output_rom(ACTIVE_CLK_SRC_TYPE type, bool is_enable);
void settle_required_cko_rom(void);
bool clock_state_transition_rom(CLOCKState state);
CLOCKState get_base_clock_state_rom(PlatformPowerMode power_mode);
bool update_clock_state(CLOCKState base_clock_state);
bool set_base_clock_state_rom(void);
void clock_queue_in_request_rom(CLOCKRequest *p_request);
CLOCKRequestHandle clock_register_clock_request_rom(CLOCKState clock_state,
                                                    LDO_POWER_DOMAIN_TYPE power_domain);
void clock_request_init_rom(void);
void clock_check_request_handle_valid(CLOCKRequestHandle handle, uint32_t lr);
bool clock_set_request_power_domain_rom(CLOCKRequestHandle handle,
                                        LDO_POWER_DOMAIN_TYPE power_domain);
bool clock_set_request_clock_state_rom(CLOCKRequestHandle handle, CLOCKState clock_state);
CLOCKState clock_get_request_clock_state_rom(CLOCKRequestHandle handle);
LDO_POWER_DOMAIN_TYPE clock_get_request_power_domain_rom(CLOCKRequestHandle handle);
bool vad_mode_handle_clock_request_rom(bool is_enable);
CLOCK_40M_CONFIG_Type get_active_clock_pon_config_rom(PlatformPowerMode power_mode);
CLOCK_40M_CONFIG_Type get_active_clock_pof_config_rom(PlatformPowerMode power_mode);
CLOCK_32K_CONFIG_Type get_low_power_clock_pon_config_rom(PlatformPowerMode power_mode);
CLOCK_32K_CONFIG_Type get_low_power_clock_pof_config_rom(PlatformPowerMode power_mode);
void clock_update_active_lop_pof_table_rom(PlatformPowerMode power_mode);
void clock_update_active_lop_pon_table_rom(PlatformPowerMode power_mode);
void clock_update_active_lop_table_rom(PlatformPowerMode power_mode);
void clock_update_32k_lop_pof_table_rom(PlatformPowerMode power_mode);
void clock_update_32k_lop_pon_table_rom(PlatformPowerMode power_mode);
void clock_update_32k_lop_table_rom(PlatformPowerMode power_mode);
void clock_pm_enter_rom(PlatformPowerMode power_mode);
void clock_pm_exit_rom(void);
void set_xtal40_path_state_rom(bool is_enter_lpm);

/* 32k */
bool is_rtc_clk_32000Hz(void);
bool is_btmac_clk_32000Hz(void);
bool is_aon_clk_32000Hz(void);
void set_required_32k_rtc_in_rom(void);
void set_32k_clk_path_rom(void);
void set_32k_clock_setting_rom(void);
bool lpm_check_32k_clock_rom(void);
void internal_32k_cal_timer_cb_rom(void *p_handle);
void init_32k_clk_src_rom(void);
void bton_32k_set_alpha_tracker_rom(void);
void init_sdm_setting_rom(void);
void internal_32k_linear_cal_ini_rom(void);
void internal_32k_linear_cal_en_rom(void);
uint8_t internal_32k_linear_check_lock_rom(void);
void external_32k_cal_ini(void);
void lp_xtal_cal_ini(void);
void internal_32k_sdm_cal_ini(void);
void internal_32k_sdm_cal_en(void);
uint8_t external_32k_check_lock(void);
uint8_t internal_32k_sdm_check_lock(void);
void alpha_tracker_fb_alg_restart_rom(uint16_t countdown, bool with_init, uint32_t restart_reason);
void alpha_tracker_fb_alg_ini_rom(void);
bool is_alpha_tracker_fb_alg_restart_necessary_rom(void);
void handle_alpha_tracker_fb_alg_rom(void);
void update_alpha_tracker_fb_para_rom(void);
void prepare_next_internal_32k_alpha_tracker_sdm_k_rom(void);
void btmac_pm_restore_handle_internal_32k_clk_rom(void);
void platform_pm_restore_handle_32k_clk_rom(void);
void lpm_force_32k_to_osc32_rom(void);
void lpm_handle_32k_clk_src_rom(bool is_enter_lpm);
void lpm_handle_lp_xtal_rom(bool is_enter_lpm);
/* --------- End of 32k clock ----------*/
/* End of clock manager */



/* Used for nor flash driver */
/*-------- Flash nor device ----------*/
FLASH_NOR_RET_TYPE flash_nor_read_locked_rom(uint32_t addr, uint8_t *data, uint32_t len);
FLASH_NOR_RET_TYPE flash_nor_write_locked_slice_rom(uint32_t addr, uint8_t *data, uint32_t len,
                                                    uint32_t slice_len);
FLASH_NOR_RET_TYPE flash_nor_write_locked_rom(uint32_t addr, uint8_t *data, uint32_t len);
FLASH_NOR_RET_TYPE flash_nor_erase_locked_rom(uint32_t addr, FLASH_NOR_ERASE_MODE mode);
FLASH_NOR_RET_TYPE flash_nor_auto_dma_read_locked_rom(uint32_t src, uint32_t dst, uint32_t len,
                                                      FLASH_NOR_DMA_SETTING_FUNC dma_setting_func,
                                                      FLASH_NOR_ASYNC_CB cb);
FLASH_NOR_RET_TYPE flash_nor_find_cyc_cnt_rom(FLASH_NOR_IDX_TYPE idx, uint32_t cal_addr,
                                              bool is_cal_rd_dummy_len, uint32_t cfg_max);
FLASH_NOR_RET_TYPE flash_nor_cal_dly_cyc_rom(FLASH_NOR_IDX_TYPE idx, uint32_t cal_addr);
FLASH_NOR_RET_TYPE flash_nor_cal_dummy_cyc_rom(FLASH_NOR_IDX_TYPE idx, uint32_t cal_addr,
                                               FLASH_NOR_BIT_MODE mode);
FLASH_NOR_AVAILABLE_DELAY_SETTING *flash_nor_init_ram_for_cal_rom(void);
void flash_nor_deinit_ram_for_cal_rom(FLASH_NOR_AVAILABLE_DELAY_SETTING *avaliable_settings);
FLASH_NOR_RET_TYPE flash_nor_calibration_rom(FLASH_NOR_IDX_TYPE idx, FLASH_NOR_BIT_MODE mode);
FLASH_NOR_RET_TYPE flash_nor_try_high_speed_mode_rom(FLASH_NOR_IDX_TYPE idx,
                                                     FLASH_NOR_BIT_MODE bit_mode);
void flash_nor_finish_busy_and_suspended_operations_rom(void);
FLASH_NOR_RET_TYPE flash_nor_ioctl_rom(uint16_t cmd, uint16_t idx, uint32_t p1, uint32_t p2,
                                       uint32_t p3);
FLASH_NOR_RET_TYPE flash_nor_find_physical_cyc_phy_delay_chain_rom(FLASH_NOR_IDX_TYPE idx,
                                                                   uint32_t cal_addr, FLASH_NOR_AVAILABLE_DELAY_SETTING *available_setting);
FLASH_NOR_RET_TYPE flash_nor_malloc_for_query_info_rom(FLASH_NOR_IDX_TYPE idx);
FLASH_NOR_RET_TYPE flash_nor_get_bp_info_from_protected_range_rom(FLASH_NOR_IDX_TYPE idx,
                                                                  bool from_bottom, uint32_t num_bp_sector, FLASH_NOR_BP_INFO_STRUCT *bp_info);

/*-------- End of flash nor device --------*/

/*-------- Flash nor driver ----------*/
FLASH_NOR_RET_TYPE flash_nor_hook_func(void);
FLASH_NOR_RET_TYPE flash_nor_set_bp_lv_by_size_rom(FLASH_NOR_IDX_TYPE idx, bool from_bottom,
                                                   uint32_t num_bp_sector, FLASH_NOR_BP_INFO_STRUCT *bp_info);
FLASH_NOR_RET_TYPE flash_nor_suspend_erase_rom(FLASH_NOR_IDX_TYPE idx);
FLASH_NOR_RET_TYPE flash_nor_resume_erase_rom(FLASH_NOR_IDX_TYPE idx);
FLASH_NOR_RET_TYPE flash_nor_suspend_dma_rom(FLASH_NOR_IDX_TYPE idx, uint8_t dma_ch);
FLASH_NOR_RET_TYPE flash_nor_resume_dma_rom(FLASH_NOR_IDX_TYPE idx, uint8_t dma_ch);
FLASH_NOR_RET_TYPE flash_nor_enter_lpm_rom(FLASH_NOR_IDX_TYPE idx, bool backup_spic);
FLASH_NOR_RET_TYPE flash_nor_exit_lpm_rom(FLASH_NOR_IDX_TYPE idx, bool restore_spic);
FLASH_NOR_RET_TYPE flash_nor_auto_dma_memory_to_memory_transaction_rom(uint32_t src, uint32_t dst,
                                                                       uint32_t len,
                                                                       uint8_t dma_ch);
FLASH_NOR_CMD_NODE_TYPE *flash_nor_move_cmd_node_rom(FLASH_NOR_CMD_LIST_TYPE *src_list,
                                                     FLASH_NOR_CMD_LIST_TYPE *dst_list, FLASH_NOR_CMD_NODE_TYPE *cmd_node);
void flash_nor_cmd_node_assign_rom(void);
bool flash_nor_cmd_list_init_rom(void);
void flash_nor_context_switch_suspend_resume_check_rom(FLASH_NOR_IDX_TYPE idx);
void flash_nor_remaining_work_check_in_idle_rom(void);
FLASH_NOR_CMD_NODE_TYPE *flash_nor_get_blocking_cmd_node_rom(FLASH_NOR_REQ_TYPE req, uint32_t addr,
                                                             uint32_t len);
FLASH_NOR_RET_TYPE flash_nor_suspend_cmd_node_rom(FLASH_NOR_CMD_NODE_TYPE *cmd_node);
FLASH_NOR_RET_TYPE flash_nor_resume_cmd_node_rom(FLASH_NOR_CMD_NODE_TYPE *cmd_node);
FLASH_NOR_CMD_NODE_TYPE *flash_nor_resume_highest_priority_dma_rom(void);
void  flash_nor_wait_cmd_node_done_rom(FLASH_NOR_CMD_NODE_TYPE *cmd_node);
uint32_t  flash_nor_lock_rw_operation_rom(FLASH_NOR_REQ_TYPE req, uint32_t addr, uint32_t len);
uint32_t  flash_nor_lock_erase_operation_rom(FLASH_NOR_REQ_TYPE req, uint32_t addr,
                                             FLASH_NOR_CMD_NODE_TYPE **cmd_node);
uint32_t flash_nor_lock_dma_operation_rom(FLASH_NOR_REQ_TYPE req, uint32_t addr, uint32_t len,
                                          FLASH_NOR_CMD_NODE_TYPE **cmd_node);
uint32_t flash_nor_lock_rom(FLASH_NOR_REQ_TYPE req, uint32_t addr, uint32_t len,
                            FLASH_NOR_CMD_NODE_TYPE **req_cmd_node);
void flash_nor_unlock_rom(FLASH_NOR_REQ_TYPE req, uint32_t lock_flag);
void flash_nor_suspend_all_busy_nodes_rom(FLASH_NOR_IDX_TYPE req_idx);
bool flash_nor_check_is_erasing_rom(FLASH_NOR_IDX_TYPE idx, FLASH_NOR_CMD_NODE_TYPE **cmd_node);
bool flash_nor_erase_suspend_check_rom(uint8_t primask, FLASH_NOR_CMD_NODE_TYPE **node);
void flash_nor_erase_resume_check_rom(uint8_t primask, FLASH_NOR_CMD_NODE_TYPE *node, bool ret);

/*-------- End of flash nor driver --------*/
/* End of nor flash driver */

/* ============================ Patch of PMU Manager ============================ */
void si_flow_data_init_rom(void);

void lop_pof_setting_rom(PlatformPowerMode power_mode);
void lop_pon_setting_rom(PlatformPowerMode power_mode);
void lop_setting_rom(PlatformPowerMode power_mode);

void set_io_power_in_lps_mode_rom(bool on);
void set_clk_32k_power_in_powerdown_rom(bool on);

void pmu_handle_ldo_311_rom(bool use_normal_tune);
void pmu_handle_ldo_311_aux_lq_rom(bool en_vddcore, bool en_ldo_311_aux_lq);
void pmu_handle_ldo_318_rom(bool en_ldo_318);
void pmu_handle_ldo_pa_rom(bool en_ldo_pa);
void pmu_handle_ldo_sys_lq_rom(bool en_ldo_sys_hq, bool en_ldo_sys_vcore_lq);
void pmu_handle_ldo_aux1_lq_rom(bool en_ldo_aux1_hq, bool en_ldo_aux1_lq);
void pmu_handle_ldo_aux2_hq_rom(bool en_ldo_aux2_hq);
void pmu_handle_ldo_aux2_lq_rom(bool en_ldo_aux2_hq, bool en_ldo_aux2_lq);
void pmu_handle_ldo_audio_lq_rom(bool en_avcc_drv_hq, bool en_avcc_drv_lq);
void pmu_handle_vddcore_rom(bool is_need_core);
void pmu_handle_pof_swr_core_low_iq_pfm_rom(PlatformPowerMode power_mode);
void pmu_handle_dummy_load_rom(void);
void pmu_apply_voltage_tune_rom(void);

void pmu_active_ctrl_rom(void);
void pmu_lpm_ctrl_rom(PlatformPowerMode power_mode);
void pmu_power_on_sequence_restart_rom(void);
/* ============================================================================== */

/* ============================== Patch of Adapter ============================== */
void create_adp_det_debounce_timer_rom(void);
void adapter_init_rom(void);
/* ============================================================================== */

/* ============================== Patch of Charger ============================== */
void charger_system_init_rom(void);
bool charger_pm_check_rom(void);
void charger_pm_exit_rom(void);
/* ============================================================================== */

/* =========================== Patch of Power Manager =========================== */
void power_manager_check_rom(uint32_t pre_sys_lv_wakeup_time, PowerManagerUnit *p_cur_unit);
void power_manager_store_and_enter_rom(PMSystemLevel sys_lv, PowerManagerUnit *p_cur_unit);
void power_manager_exit_and_restore_rom(PowerManagerUnit *p_cur_unit);
void power_manager_cpu_sleep_rom(void);
void power_manager_handler_rom(void);
/* ============================================================================== */

/* ==================== Patch of Power Manager Unit Platform ==================== */
bool platform_pm_buffer_pre_allocate_rom(void);
void platform_pm_buffer_predict_time_rom(void);
void platform_pm_buffer_store_rollback_rom(void);
uint32_t platform_pm_find_minimum_xItemValue_rom(ListItem_t *list_item, UBaseType_t list_num,
                                                 PlatformExcludedHandleType type);
uint32_t platform_pm_find_nearest_timeout_tick_rom(void);
uint32_t platform_pm_cal_quotient_remainder_rom(const uint64_t divisor_upper,
                                                const uint64_t divisor_lower,
                                                const uint32_t dividend, uint32_t *remainder);
uint32_t platform_pm_estimate_pof_delay_rom(PlatformPowerMode power_mode);
uint32_t platform_pm_estimate_pon_delay_rom(PlatformPowerMode power_mode);
void platform_pm_buffer_store_rom(void);
void platform_pm_buffer_restore_rom(void);
void platform_pm_restore_os_tick_count_rom(void);
void platform_pm_hw_enter_flow_rom(void);
void platform_pm_hw_exit_flow_rom(void);
void platform_pm_cpu_enter_flow_rom(void);
void platform_pm_power_off_flow_rom(void);
void platform_pm_cpu_exit_flow_rom(void);

bool platform_pm_wakeup_time_rom(const uint32_t *cur_clk,
                                 const uint32_t *pre_sys_lv_wakeup_time_diff, uint32_t *unit_wakeup_time_diff);
bool platform_pm_check_rom(const uint32_t *cur_clk, const uint32_t *pre_sys_lv_wakeup_time_diff,
                           uint32_t *unit_wakeup_time_diff);
void platform_pm_store_rom(void);
void platform_pm_restore_rom(void);
void platform_pm_enter_rom(void);
void platform_pm_exit_rom(void);
void platform_pm_pend_rom(void);
bool platform_pm_wfi_check_rom(void);
/* ============================================================================== */

/* ============================== Patch of FreeRTOS ============================= */
void vTaskStartScheduler_rom(void) PRIVILEGED_FUNCTION;
void vApplicationStackOverflowHook_rom(TaskHandle_t xTask, char *pcTaskName);
portTASK_FUNCTION(prvIdleTask_rom, pvParameters);
void vDumpMemoryUsageTimeoutHandler_rom(xTimerHandle pxTimer);
void prvProcessExpiredTimer_rom(const TickType_t xNextExpireTime, const TickType_t xTimeNow);
void prvProcessTimerOrBlockTask_rom(const TickType_t xNextExpireTime, BaseType_t xListWasEmpty);
void prvSwitchTimerLists_rom(void);
void *pvPortMalloc_rom(RAM_TYPE ramType, size_t xSize) PRIVILEGED_FUNCTION;
void vPortFree_rom(void *pv) PRIVILEGED_FUNCTION;
void vApplicationIdleHook_rom(void);
void vApplicationMallocFailedHook_rom(RAM_TYPE ramType, size_t xWantedSize, size_t remainSize);
void prvHeapInit_rom(RAM_TYPE ramType);
void HeapSizeUpdate_rom(void);
void HeapConfigInit_Rom(void);
bool get_heap_info_rom(RAM_TYPE ramType, uint8_t *start_addr, size_t *size);
void ram_type_map_rom(RAM_TYPE *ramType);
void vMakeHeapContiguousy_Rom(void);
void systick_clk_src_setup_rom(void);
void switchContextSaveTaskInfo_Rom(void);
size_t xPortGetFreeHeapSizeRom(RAM_TYPE ramType);
QueueHandle_t xQueueGenericCreate_rom(const UBaseType_t uxQueueLength, const UBaseType_t uxItemSize,
                                      const uint8_t ucQueueType);
void vQueueDelete_rom(QueueHandle_t xQueue);
uint32_t get_malloc_lr_value_rom(void);
/* ============================================================================== */

/* ============================== Patch of os =================================== */
void os_queue_init_rom(T_OS_QUEUE *p_queue);
void os_queue_in_rom(T_OS_QUEUE *p_queue, void *p_elem);
void *os_queue_out_rom(T_OS_QUEUE *p_queue);
void *os_queue_peek_rom(T_OS_QUEUE *p_queue, int32_t index);
bool os_queue_search_rom(T_OS_QUEUE *p_queue, void *p_elem);
void os_queue_insert_rom(T_OS_QUEUE *p_queue, void *p_elem, void *p_new_elem);
bool os_queue_delete_rom(T_OS_QUEUE *p_queue, void *p_elem);
/* ============================================================================== */

/* ============================ Patch of hw aes ================================= */
extern void hw_aes_take_sem_rom(void);
extern void hw_aes_give_sem_rom(void);
extern void hw_aes_mutex_init_rom(void);
bool hw_aes_operate_rom(uint32_t *p_in, uint32_t *p_out, uint32_t word_len,
                        const uint32_t *p_aes_key,
                        uint32_t *p_iv, THw_AesConfig *aes_config);
bool hw_aes_decrypt_code_init_slim_rom(const uint32_t *aes_key, bool is_aes256);
bool hw_aes_decrypt_16byte_rom(uint8_t *input, uint8_t *output);
/* ============================================================================== */

/* ============================ Patch of PPB ==================================== */
bool PPB_Init_rom(PingpongBuffer *pPPB, WriteFullCB cb);
bool PPB_Write_rom(PingpongBuffer *pPPB, const uint8_t *source, uint16_t size);
/* ============================================================================== */

/* ============================== Patch of dma channel ================================== */
bool GDMA_channel_request_rom(uint8_t *ch, void *isr, bool is_hp_ch);
/* ============================================================================== */

/* ============================ Patch of adc manager ============================ */
bool adc_mgr_init_rom(uint8_t req_num);
bool adc_mgr_enable_req_rom(uint8_t index);
void adc_mgr_enable_rom(uint8_t index);
void adc_mgr_free_chann_rom(uint8_t index);
bool adc_mgr_register_req_rom(ADC_InitTypeDef *p_adc_init, adc_callback_function_t cb,
                              uint8_t *adc_mgr_index);
/* ============================================================================== */

/* ============================ Patch of main func ============================== */
int main_rom(void);
/* ============================================================================== */

/* ======================= Patch of RAM CTRL ==================================== */
void ram_ctrl_power_cfg_rom(void);
void ram_ctrl_power_set_rom(void);
void ram_ctrl_share_set_rom(uint8_t is_ram_in_mcu);
/* ============================================================================== */

/* ============================ Patch of debug port ============================= */
void debug_port_set_pin_bit_map_rom(T_PIN_GROUP pin_group, uint32_t dbg_bitmap);
void debug_port_open_rom(T_DEBUG_MODE debug_mode);
bool debug_port_check_hybrid_pad_rom(uint8_t pin_index, uint8_t dbg_port_index);
/* ============================================================================== */

/* ============================ Patch of PHY Common ==================================== */
void phy_init_script_execute_rom(const uint16_t *script_array, uint16_t length);
/* ============================================================================== */

/* ============================ Patch of RFC ==================================== */
uint16_t rfc_reg_read_rom(uint8_t addr);
void rfc_reg_write_rom(uint8_t addr, uint16_t wdata);
void rfc_reg_update_rom(uint8_t addr, uint16_t mask, uint16_t wdata);

void rfc_hw_control_init_rom(bool dlps_flow);

uint8_t rfc_get_rck_rom(void);
void rfc_set_rck_rom(uint8_t rck);
#if ((SUPPORT_POLAR_TX == 1) || (SUPPORT_IQM_MODE == 1))
void rfc_set_flatk_comp_rom(uint8_t *txgain_flatk_comp);
void rfc_set_flatk_rom(int8_t *txgain_flatk);
#endif

void rfc_set_tx_pfd_ldok_rom(uint8_t tx_pfd_ldok);
void rfc_set_tx_cp_ldok_rom(uint8_t tx_cp_ldok);
void rfc_set_tx_mmd_ldok_rom(uint8_t tx_mmd_ldok);
void rfc_set_rx_vco_ldok_rom(uint8_t rx_vco_ldok);
void rfc_set_tx_vco_ldok_rom(uint8_t tx_vco_ldok);
void rfc_set_tx_mxr_ldok_rom(uint8_t tx_mxr_ldok);

void rfc_set_vco_tx_currentk_rom(uint8_t vco_tx_currentk);
void rfc_set_vco_rx_currentk_rom(uint8_t vco_rx_currentk);
void rfc_set_pad_currentk_rom(uint8_t pad_currentk);
void rfc_set_pa_currentk_rom(uint8_t pa_currentk);
void rfc_set_lna_currentk_rom(uint8_t lna_currentk);
void rfc_set_tia_currentk_rom(uint8_t tia_currentk);
void rfc_set_iqgen_currentk_rom(uint8_t iqgen_currentk);

#if (SUPPORT_IQM_MODE == 1)
void rfc_get_lck_rom(uint8_t *lck);
void rfc_set_lck_rom(uint8_t *lck);
uint16_t rfc_get_lok_rom(void);
void rfc_set_lok_rom(uint16_t lok);
#endif

void rfc_init_rom(void);

void rfc_store_platform_rom(void);
void rfc_restore_platform_rom(void);
void rfc_restore_mac_rom(void);

void execute_post_processing_rom(uint8_t *txgain, TXGAIN_TYPE txgain_type, RF_MODE rf_mode,
                                 bool inverse);
#if (SUPPORT_POLAR_TX == 1)
int8_t txgain_to_power_conversion_polar_tx_rom(uint8_t txgain, TXGAIN_TYPE txgain_type);
uint8_t power_to_txgain_conversion_polar_tx_rom(int8_t txpower, TXGAIN_TYPE txgain_type);
#endif
#if (SUPPORT_IQM_MODE == 1)
int8_t txgain_to_power_conversion_iqm_mode_rom(uint8_t txgain, TXGAIN_TYPE txgain_type);
uint8_t power_to_txgain_conversion_iqm_mode_rom(int8_t txpower, TXGAIN_TYPE txgain_type);
#endif
#if (SUPPORT_TPM_MODE == 1)
int8_t txgain_to_power_conversion_tpm_mode_rom(uint8_t txgain, TXGAIN_TYPE txgain_type);
uint8_t power_to_txgain_conversion_tpm_mode_rom(int8_t txpower, TXGAIN_TYPE txgain_type);
#endif

int8_t get_config_max_tx_power_rom(TXGAIN_TYPE txgain_type, RF_MODE rf_mode);
int8_t get_tx_power_upperbound_rom(TXGAIN_TYPE txgain_type, RF_MODE rf_mode);
int8_t get_tx_power_lowerbound_rom(TXGAIN_TYPE txgain_type, RF_MODE rf_mode);
int8_t tx_power_fit_pmax_rom(int8_t tx_power, TXGAIN_TYPE txgain_type, RF_MODE rf_mode);

void rfc_set_lut_syn_if_table_rom(uint16_t index, uint32_t value);

void rfc_set_afc_option_rom(AFC_OPTION option, bool enable);
AFC_OPTION rfc_get_afc_option_rom(void);
/* ============================================================================== */

/* ============================ Patch of Modem ==================================== */
uint16_t modem_pi_read_rom(uint8_t modem_page, uint8_t addr);
void modem_pi_write_rom(uint8_t modem_page, uint8_t addr, uint16_t wdata);
void modem_pi_update_rom(uint8_t modem_page, uint8_t addr, uint16_t mask, uint16_t wdata);

void modem_hw_control_init_rom(bool dlps_flow);

void modem_auto_gated_rom(bool enable);

void modem_init_rom(void);

void modem_set_rxadck_rom(uint16_t rxadck);
#if ((SUPPORT_POLAR_TX == 1) || (SUPPORT_IQM_MODE == 1))
void modem_set_flatk_comp_rom(uint32_t txgain_flatk_comp);
void modem_set_flatk_rom(int8_t *txgain_flatk);
#endif
#if (SUPPORT_IQM_MODE == 1)
void modem_set_rxgaink_iqm_mode(uint32_t rxgaink);
#endif
#if (SUPPORT_TPM_MODE == 1)
void modem_set_rxgaink_tpm_mode(uint32_t rxgaink);
#endif
#if (SUPPORT_IQM_MODE == 1)
void modem_get_iqk_rom(uint16_t *iqk_x, uint16_t *iqk_y);
void modem_set_iqk_rom(uint16_t iqk_x, uint16_t iqk_y);
#endif
#if (SUPPORT_TPM_MODE == 1)
void modem_tpmk_bank_assign_rom(uint16_t *tpmk_bank);
#endif

void modem_store_platform_rom(void);
void modem_restore_platform_rom(void);
void modem_restore_mac_rom(void);

void modem_set_lbt_threshold_rom(void);
void modem_lbt_init_rom(void);
#if (SUPPORT_IQM_MODE == 1)
void modem_set_lbt_txg_max_th_val_iqm_mode(uint8_t lbt_txg_max_th_val);
#endif
#if (SUPPORT_TPM_MODE == 1)
void modem_set_lbt_txg_max_th_val_tpm_mode(uint8_t lbt_txg_max_th_val);
#endif

uint8_t modem_psd_get_entry_num_rom(void);
RF_MODE modem_psd_get_rf_mode_rom(void);
void modem_psd_init_rom(MODEM_PSD_SCAN_MODE mode);
void modem_psd_set_report_address_rom(uint32_t addr);

void modem_mse_init_rom(void);

bool lbt_check_rom(int8_t tx_power, TXGAIN_TYPE txgain_type, RF_MODE rf_mode);

uint8_t modem_get_rx_settling_time_rom(void);

#if (MODEM_SRAM_DEBUG == 1)
void btrf_modem_sram_debug_set_size_rom(uint8_t size);
void btrf_modem_sram_debug_set_en_rom(bool enable);
void btrf_modem_sram_debug_set_rst_rom(bool reset);
void btrf_modem_sram_debug_set_mode_rom(uint8_t mode);
void btrf_modem_sram_debug_init_rom(MODEM_SRAM_DEBUG_MANAGER *modem_sram_debug_manager);
#endif

#if (SUPPORT_ZIGBEE == 1)
void modem_set_zb_cca_sfd_detect_en_rom(bool enable);
void modem_set_zb_cca_combination_rom(ZB_CCA_COMB comb);
void modem_set_zb_cca_energy_detect_threshold_rom(uint8_t thres, ZB_CCA_ED_RES_TYPE res);
void modem_set_zb_cca_carrier_sense_threshold_rom(uint8_t thres, uint8_t times, uint8_t cont_times);
#endif

#if (SUPPORT_PROPRIETARY == 1)
void modem_set_proprietary_en_rom(bool enable);
void modem_set_proprietary_base_rom(uint8_t base_index, uint32_t base);
uint32_t modem_get_proprietary_base_rom(uint8_t base_index);
void modem_set_proprietary_2_rx_match_mode_en_rom(bool enable);
#endif

void modem_set_mod_index_rom(MOD_RATE_TYPE mod_rate, uint8_t mod_index);
uint8_t modem_get_mod_index_rom(MOD_RATE_TYPE mod_rate);
/* ============================================================================== */

/* ============================ Patch of PHY ==================================== */
void phy_hw_control_init_rom(bool dlps_flow);

void rck_init_rom(void);
void rxadck_rom(void);

#if ((SUPPORT_POLAR_TX == 1) || (SUPPORT_IQM_MODE == 1))
void get_valid_txgain_flatk_rom(int8_t *txgain_flatk);
void txgain_flatk_post_processing_rom(int8_t *txgain_flatk);
void txgain_flatk_rom(void);
#endif

uint32_t get_rxgaink_value_rom(uint8_t *rxgaink_result);
void rxgaink_rom(void);

void get_iqk_lok_rom(uint16_t *lok, uint16_t *iqk_x, uint16_t *iqk_y);
void set_iqk_lok_rom(uint16_t lok, uint16_t iqk_x, uint16_t iqk_y);
void iqk_lok_init_rom(void);

void phy_enable_expa_lna_setting_rom(void);

void phy_init_rom(uint8_t dlps_flow);

void phy_store_platform_rom(void);
void phy_restore_mac_rom(void);
void phy_restore_platform_rom(void);

int8_t get_txgaink_value_rom(RF_MODE rf_mode);

void tx_power_track_slope_update_rom(int16_t celsius);
void tx_power_track_offset_update_rom(void);
void tx_power_system_init_rom(void);

#if (SUPPORT_LEGACY == 1)
uint8_t legacy_get_max_tx_step_index_rom(RF_MODE rf_mode);
uint8_t legacy_get_min_tx_step_index_rom(RF_MODE rf_mode);
uint8_t legacy_get_default_tx_step_index_rom(TXGAIN_TYPE txgain_type, RF_MODE rf_mode);

int8_t legacy_get_tx_power_rom(uint8_t step_index, TXGAIN_TYPE txgain_type, RF_MODE rf_mode);
#endif
int8_t tx_power_apply_compensation_rom(int8_t tx_power, TXGAIN_TYPE txgain_type,
                                       RF_MODE rf_mode, bool inverse);
bool get_valid_txgain_index_from_tx_power_rom(int8_t tx_power_request, TXGAIN_TYPE txgain_type,
                                              RF_MODE rf_mode, bool dbm_resolution, uint8_t *actual_txgain_index, int8_t *actual_tx_power);
#if (SUPPORT_LEGACY == 1)
bool legacy_get_valid_tx_gain_from_step_index_rom(uint8_t step_index, TXGAIN_TYPE txgain_type,
                                                  RF_MODE rf_mode, uint8_t *actual_txgain_index, int8_t *actual_tx_power);
#endif

int8_t get_phy_rssi0_dbm_rom(RF_MODE rf_mode);
int8_t get_rssi_offset_rom(int8_t lna_idx, int8_t channel, RF_MODE rf_mode);
int8_t calculate_log_from_rssi_rom(uint16_t rssi_raw, uint8_t channel, RF_MODE rf_mode);

#if (SUPPORT_LEGACY == 1)
bool legacy_lbt_check_rom(uint8_t step_index, TXGAIN_TYPE txgain_type, RF_MODE rf_mode);
#endif
void set_lbt_threshold_with_compensation_rom(void);
/* ============================================================================== */

/* ======================== Patch of Thermal ==================================== */
int16_t thermal_meter_to_celsius_rom(uint8_t thermal_meter);
uint8_t celsius_to_thermal_meter_rom(int16_t celsius);
void thermal_meter_trigger_rom(void);
void thermal_meter_read_rom(void);
void thermal_meter_update_rom(void);
void force_thermal_meter_update_rom(void);
bool thermal_meter_check_rom(void);
void thermal_meter_init_rom(void);

bool thermal_tracking_register_callback_func_rom(void *);
void thermal_tracking_rom(void);
void thermal_tracking_timer_handler_rom(void *handle);
void thermal_tracking_timer_init_rom(void);
/* ============================================================================== */

///* ================================= Patch of platform RTC =========================================== */
void platform_rtc_aon_init_rom(void);
void platform_rtc_reset_rom(void);
void platform_rtc_run_cmd_rom(bool);
uint32_t platform_rtc_get_counter_rom(void);
void platform_rtc_set_comp_intr_config_rom(PFRTCComparator comp_bitmap, bool isr_type, bool enable);
void platform_rtc_set_comp_wk_config_rom(PFRTCComparator comp_bitmap, bool enable);
void platform_rtc_set_intr_group_config_rom(bool enable);
void platform_rtc_set_wk_group_config_rom(bool enable);
bool platform_rtc_get_intr_group_config_rom(void);
bool platform_rtc_get_wk_group_config_rom(void);
void platform_rtc_set_comp_rom(PFRTCComparator comp, uint32_t value);
uint32_t platform_rtc_get_comp_rom(PFRTCComparator comp);
PFRTCComparator platform_rtc_get_comp_intr_status_rom(void);
PFRTCComparator platform_rtc_get_comp_wk_status_rom(void);
void platform_rtc_set_comp_manual_intr_rom(PFRTCComparator comp_bitmap);
PFRTCComparator platform_rtc_get_comp_manual_intr_rom(void);
void platform_rtc_clear_comp_intr_status_rom(PFRTCComparator comp_bitmap);
void platform_rtc_clear_comp_wk_status_rom(PFRTCComparator comp_bitmap);
////* ===================================== End of platform RTC ======================================== */

#ifdef __cplusplus
}
#endif

#endif /* _PATCH_PLATFORM_H_ */
