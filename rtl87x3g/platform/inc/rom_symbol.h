#include <stdint.h>
extern void (*platform_pm_init)(void);
extern void init_osc_sdm_timer(void);
extern void (*phy_hw_control_init)(bool);
extern void (*thermal_tracking_timer_init)(void);
extern void (*phy_init)(uint8_t);
extern void test_ahb_wait_cnt_config(void);
extern bool (*patch_RamVectorTableUpdate)(uint32_t v_num, IRQ_Fun isr_handler, bool *ret);
extern uint32_t flash_nor_get_exist(uint32_t idx);
extern void flash_nor_dump_main_info(void);
extern bool (*flash_nor_cmd_list_init)(void);
extern uint32_t (*flash_nor_malloc_for_query_info)(uint32_t idx);
extern void (*flash_nor_init_bp_lv)(void);
extern void (*flash_task_init)(void);
extern uint32_t (*platform_rtc_get_counter)(void);
/* idle hook */
extern void (*platform_rtc_aon_init)(void);
extern void (*power_manager_master_init)(void);
extern void (*power_manager_slave_init)(void);
extern void (*dvfs_init)(void);
extern void (*adapter_init)(void);
extern bool (*adc_mgr_init)(uint8_t req_num);
extern void (*charger_system_init)(void);
extern void (*patch_fw_sim)(void);
extern void memory_watch_enable(void);
extern void (*set_active_mode_clk_src)(void);
extern void set_up_32k_clk_src(void);
extern void (*system_interrupt_init)(void);
extern void (*pmu_apply_voltage_tune)(void);
extern void (*pmu_power_on_sequence_restart)(void);
extern void set_reg_by_otp(uint8_t timing_mask);
extern void (*si_flow_after_exit_low_power_mode)(void);
extern void (*pmu_active_ctrl)(void);
extern void (*disable_unused_clock)(void);
extern void (*ram_ctrl_power_set)(void);
extern void (*hal_setup_hardware)(void);
extern void (*hal_setup_cpu)(void);
extern void (*hw_aes_mutex_init)(void);
#define T_POWER_ON_SEQ 0x00000002
#define VERSION_GCID 0xdcb278c6
void dvfs_register_check_func(void *);
extern bool (*check_pke_ram_idle)(void);
extern void HardFault_Handler(void);

extern void (*ft_paras_apply)(void);
extern void (*si_flow_data_init)(void);
extern void enable_rxi300_interrupt(void);
extern void (*set_up_wdt)(void);
extern void (*main_patch)(void);