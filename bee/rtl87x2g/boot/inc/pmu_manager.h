/**
*********************************************************************************************************
*               Copyright(c) 2020, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file         pmu_manager.h
* @brief        PMU Manager implementation head file.
* @details
* @author       js.lin
* @date         2022-09-22
* @version      v0.1
*********************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __PMU_MANAGER_H
#define __PMU_MANAGER_H

/*============================================================================*
 *                               Header Files
 *============================================================================*/
#include "aon_reg.h"
#include "power_manager_unit_platform.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AUTO_TABLE_MAP_OFFSET       0xB00
#define CORE_SWITCH_BUCK_OFFSET     0xB04
#define CORE_SWITCH_XTAL_OFFSET     0xB18

#ifndef MAX
#define MAX(a,b)            (((a) > (b)) ? (a) : (b))
#endif

/*============================================================================*
 *                              Types
 *============================================================================*/
/** @defgroup PMU_Manager_Exported_Types PMU Manager Exported Types
  * @{
  */

#define WAIT_AON_STATE_MACHINE_BACK_TO_ACTIVE()                         \
    do {                                                                \
        platform_delay_us(100);                                         \
        while ((AON_REG_READ(AON_REG2X_SYS) & 0x3) != 0);               \
    } while (0)

typedef enum _POWER_DOMAIN_TYPE
{
    ALWAYS_ACTIVE                       = 0,
    AON_DOMAIN                          = 1,
    PON_DOMAIN                          = 2,
    CORE_DOMAIN                         = 4,
    ALWAYS_INACTIVE                     = 6,
} POWER_DOMAIN_TYPE;

typedef enum _SWR_CORE_TYPE
{
    LDO_MODE        = 0,
    SWR_PWM_MODE    = 1,
    SWR_PFM_MODE    = 2,
} SWR_CORE_TYPE;

typedef enum
{
    SWR_CORE_LDO_TUNE_1V10              = 0,
    SWR_CORE_LDO_TUNE_1V20              = 1,
    SWR_CORE_LDO_TUNE_1V30              = 2,
    SWR_CORE_LDO_TUNE_TYPE_MAX          = 3,
} SWR_CORE_LDO_TUNE_TYPE;

typedef enum
{
    SWR_CORE_PWM_TUNE_1V00              = 0,
    SWR_CORE_PWM_TUNE_1V10              = 1,
    SWR_CORE_PWM_TUNE_1V20              = 2,
    SWR_CORE_PWM_TUNE_1V30              = 3,
    SWR_CORE_PWM_TUNE_TYPE_MAX          = 4,
} SWR_CORE_PWM_TUNE_TYPE;

typedef enum
{
    SWR_CORE_PFM_TUNE_OFF               = 0,
    SWR_CORE_PFM_TUNE_0V70              = 1,
    SWR_CORE_PFM_TUNE_0V90              = 2,
    SWR_CORE_PFM_TUNE_1V10              = 3,
    SWR_CORE_PFM_TUNE_TYPE_MAX          = 4,
} SWR_CORE_PFM_TUNE_TYPE;

typedef enum
{
    LDO_RET_TUNE_0V70                   = 0,
    LDO_RET_TUNE_0V90                   = 1,
    LDO_RET_TUNE_1V10                   = 2,
    LDO_RET_TUNE_TYPE_MAX               = 3,
} LDO_RET_TUNE_TYPE;

typedef enum
{
    LDO_DIGI_TUNE_0V85                  = 0,
    LDO_DIGI_TUNE_0V95                  = 1,
    LDO_DIGI_TUNE_1V00                  = 2,
    LDO_DIGI_TUNE_1V10                  = 3,
    LDO_DIGI_TUNE_TYPE_MAX              = 4,
} LDO_DIGI_TUNE_TYPE;

typedef enum
{
    LDO_318_TUNE_1V8                    = 0,
    LDO_318_TUNE_TYPE_MAX               = 1,
} LDO_318_TUNE_TYPE;

typedef enum
{
    SDADC_TUNE_2V8                      = 0,
    SDADC_TUNE_1V8                      = 1,
    SDADC_TUNE_TYPE_MAX                 = 2,
} SDADC_TUNE_TYPE;

typedef enum
{
    AUTO_SWITCH_TABLE0_IDLE_MODE            = 0,
    AUTO_SWITCH_TABLE1_XTAL_MODE_TRANSITION = 1,
    AUTO_SWITCH_TABLE2_TXAFE1_TRX_MODE      = 2,
    AUTO_SWITCH_TABLE3_TXAFE2_TRX_MODE      = 3,
    AUTO_SWITCH_TABLE4_TXAFE1_TX_4DBM_MODE  = 4,

    AUTO_SWITCH_TABLE_MAX                   = 5,
}
AUTO_SWITCH_TABLE_TYPE;

typedef enum
{
    AUTO_SWITCH_RF_0_SHUTDOWN             = 0,
    AUTO_SWITCH_RF_4_TRANSITION           = 1,
    AUTO_SWITCH_RF_5_NO_USED              = 2,
    AUTO_SWITCH_RF_6_RX                   = 3,
    AUTO_SWITCH_RF_7_TX                   = 4,

    AUTO_SWITCH_RF_MODE_MAX               = 5,
} AUTO_SWITCH_RF_MODE_TYPE;

typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t rf_0_remap_table: 3;
        uint32_t RESERVED_4: 1;
        uint32_t rf_4_remap_table: 3;
        uint32_t RESERVED_3: 1;
        uint32_t rf_5_remap_table: 3;
        uint32_t RESERVED_2: 1;
        uint32_t rf_6_remap_table: 3;
        uint32_t RESERVED_1: 1;
        uint32_t rf_7_remap_table: 3;
        uint32_t RESERVED_0: 12;
        uint32_t auto_switch_update: 1;
    };
} REG_AUTO_TABLE_MAP_TYPE;

typedef union
{
    uint32_t value[14];
    struct
    {
        uint32_t core_mode: 2;
        uint32_t sdadc_mode: 1;
        uint32_t power_on_sequence_restart_en: 1;
        uint32_t adaptive_xtal_delay_en: 1;
        uint32_t auto_switch_en: 1;
        uint32_t buck_add_saw_current: 1;
        uint32_t rsvd0: 25;

        uint32_t clk_32k_power_domain: 3;
        uint32_t ldo_318_rf_power_domain: 3;
        uint32_t usb_power_domain: 3;
        uint32_t rsvd1: 23;

        REG_AUTO_TABLE_MAP_TYPE auto_switch_mapping_table;

        uint8_t swr_core_ldo_tune[SWR_CORE_LDO_TUNE_TYPE_MAX];
        uint8_t swr_core_pwm_tune[SWR_CORE_PWM_TUNE_TYPE_MAX];
        uint8_t swr_core_pfm_tune[SWR_CORE_PFM_TUNE_TYPE_MAX];
        uint8_t ldo_ret_tune[LDO_RET_TUNE_TYPE_MAX];
        uint8_t ldo_digi_tune[LDO_DIGI_TUNE_TYPE_MAX];
        uint8_t ldo_318_tune[LDO_318_TUNE_TYPE_MAX];
        uint8_t sdadc_tune[SDADC_TUNE_TYPE_MAX];
        uint8_t swr_saw_freq_tune;

        uint8_t lop_xtal_delay;

        uint8_t rsvd[21];
    };
} PMU_CFG;

#define LOP_PON_TABLE_REGISTER_NUM    6

typedef union _AON_LOP_PON
{
    uint32_t d32[LOP_PON_TABLE_REGISTER_NUM];
    struct
    {
        AON_LOP_RG0X_TYPE lop_rg0x;
        AON_LOP_RG1X_TYPE lop_rg1x;
        AON_LOP_RG2X_TYPE lop_rg2x;
        AON_LOP_RG7X_TYPE lop_rg7x;
        AON_LOP_RG8X_TYPE lop_rg8x;
        AON_LOP_RG9X_TYPE lop_rg9x;
    };
    struct
    {
        // 0xAB0    0x4000_0ab0
        uint32_t LOP_PON_ENPC_DIGI: 1;
        uint32_t LOP_PON_PFM: 1;
        uint32_t LOP_PON_SWR: 1;
        uint32_t LOP_PON_POW_32KOSC: 1;
        uint32_t LOP_PON_ACTIVE_CLK_SEL: 1;
        uint32_t LOP_PON_XTAL: 1;
        uint32_t LOP_PON_POW_32KXTAL: 1;
        uint32_t LOP_PON_VDDIO_PSRAM_PC_EN: 1;
        uint32_t LOP_PON_VDDIO_FLASH_PC_EN: 1;
        uint32_t LOP_PON_ENPC_AON: 1;
        uint32_t LOP_PON_VDDIO_PC_CTRL: 1;
        uint32_t LOP_PON_PLL1: 1;
        uint32_t LOP_PON_PLL2: 1;
        uint32_t LOP_RG0_dummy1: 6;
        uint32_t LOP_PON_XTAL_MODE: 3;
        uint32_t LOP_PON_PWM_EN_POS: 1;
        uint32_t LOP_PON_PFM_EN_POS: 1;
        uint32_t LOP_PON_OSC: 1;
        uint32_t LOP_PON_0xAB0_RESERVED_0: 7;

        // 0xAB4    0x4000_0ab4
        uint32_t LOP_PON_BUCK_PFM_IHALF: 1;
        uint32_t LOP_PON_BUCK_EN_OCP_IBON: 1;
        uint32_t LOP_PON_BUCK_PFM_ICOMP: 4;
        uint32_t LOP_PON_BUCK_PFM_ISCH: 4;
        uint32_t LOP_PON_BUCK_ENOCPPS_H: 1;
        uint32_t LOP_PON_LDO_ENLDO311_IB20nA: 1;
        uint32_t LOP_PON_MBIAS_VR_SEL_LDO311: 3;
        uint32_t LOP_PON_BUCK_ENOCPPFM_H: 1;
        uint32_t LOP_PON_LDO_EN_DL_LDO311: 3;
        uint32_t LOP_PON_BUCK_OCPRES_H: 2;
        uint32_t LOP_PON_BUCK_OCPSEL_H: 1;
        uint32_t LOP_PON_BUCK_VREFOCP_H: 3;
        uint32_t LOP_PON_BUCK_ENOFFSAWPFM_H: 1;
        uint32_t LOP_PON_BUCK_PFM_COT_EN: 1;
        uint32_t LOP_PON_BUCK_PFM_AOT_EN: 1;
        uint32_t LOP_PON_IBSEL_TONCOMP: 2;
        uint32_t LOP_PON_LDO_POW_LDODIGI: 1;
        uint32_t LOP_PON_AON_BUCK_LOW_IQ_ZCD_32K_CLK_EN: 1;

        // 0xAB8    0x4000_0ab8
        uint32_t LOP_PON_BUCK_ENOCPS: 1;
        uint32_t LOP_PON_BUCK_POW_ZCD: 1;
        uint32_t LOP_PON_LDO_EN_DMYL_50U_LDODIGI: 1;
        uint32_t LOP_PON_LDO_EN_DMYL_200U_LDODIGI: 1;
        uint32_t LOP_PON_IB_500N_TONCOMP_EN: 1;
        uint32_t LOP_PON_IB_500N_COTCOMP_EN: 1;
        uint32_t LOP_PON_BUCK_ZCDOFFSET: 7;
        uint32_t LOP_PON_BUCK_POW_LowIq_ZCD: 1;
        uint32_t LOP_PON_BUCK_STICKY_CODE_STATE1: 1;
        uint32_t LOP_PON_BUCK_FORCE_CODE_STATE1: 1;
        uint32_t LOP_PON_0xAB8_RESERVED_1: 7;
        uint32_t LOP_PON_0xAB8_RESERVED_0: 1;
        uint32_t LOP_PON_BUCK_STICKY_CODE_STATE2: 1;
        uint32_t LOP_PON_BUCK_FORCE_CODE_STATE2: 1;
        uint32_t LOP_PON_D300k_REG_MANU_CCOT: 6;

        // 0xACC    0x4000_0acc
        uint32_t LOP_BIAS_delay: 6;
        uint32_t LOP_LDO_delay: 6;
        uint32_t LOP_PLL_delay: 4;
        uint32_t LOP_SWR_delay: 8;
        uint32_t LOP_XTAL_delay: 8;

        // 0xAD0    0x4000_0ad0
        uint32_t LOP_ENPC_CORE_BIG_delay: 6;
        uint32_t LOP_ENPC_CORE_SMALL_delay: 6;
        uint32_t LOP_RG8X_Dummy_0: 4;
        uint32_t LOP_VDDIO_PC_VG2_delay: 8;
        uint32_t LOP_VDDIO_PC_VG1_delay: 8;

        // 0xAD4    0x4000_0ad4
        uint32_t LOP_PON_VDIGI_TUNE_STATE1: 5;
        uint32_t LOP_PON_VDIGI_TUNE_STATE2: 5;
        uint32_t LOP_PON_VDIGI_TUNE_STATE3: 5;
        uint32_t LOP_PON_0xAD4_RESERVED_1: 1;
        uint32_t LOP_PON_0xAD4_RESERVED_0: 16;
    };
} AON_LOP_PON;

#define LOP_POF_TABLE_REGISTER_NUM    5

typedef union _AON_LOP_POF
{
    uint32_t d32[LOP_POF_TABLE_REGISTER_NUM];
    struct
    {
        AON_LOP_RG3X_TYPE lop_rg3x;
        AON_LOP_RG4X_TYPE lop_rg4x;
        AON_LOP_RG5X_TYPE lop_rg5x;
        AON_LOP_RG6X_TYPE lop_rg6x;
        AON_LOP_RG10X_TYPE lop_rg10x;
    };
    struct
    {
        // 0xABC    0x4000_0abc
        uint32_t LOP_POF_0xABC_RESERVED_3: 1;
        uint32_t LOP_POF_ENPC_DIGI: 1;
        uint32_t LOP_POF_POWLDO_DIGI: 1;
        uint32_t LOP_POF_ENPC_CORE: 1;
        uint32_t LOP_POF_POW_BIAS: 1;
        uint32_t LOP_POF_POW_32KOSC: 1;
        uint32_t LOP_POF_POW_32KXTAL: 1;
        uint32_t LOP_POF_SWR_CFG: 2;
        uint32_t LOP_POF_ENPC_AON: 1;
        uint32_t LOP_POF_0xABC_RESERVED_2: 6;
        uint32_t LOP_POF_VDDIO_PSRAM_PC_EN: 1;
        uint32_t LOP_POF_VDDIO_FLASH_PC_EN: 1;
        uint32_t LOP_POF_XTAL: 1;
        uint32_t LOP_POF_AON_GATED_EN: 1;
        uint32_t LOP_POF_CAL: 1;
        uint32_t LOP_POF_0xABC_RESERVED_1: 3;
        uint32_t LOP_POF_XTAL_MODE: 3;
        uint32_t LOP_POF_0xABC_RESERVED_0: 5;

        // 0xAC0    0x4000_0ac0
        uint32_t LOP_POF_BUCK_PFM_IHALF: 1;
        uint32_t LOP_POF_BUCK_EN_OCP_IBON: 1;
        uint32_t LOP_POF_BUCK_PFM_ICOMP: 4;
        uint32_t LOP_POF_BUCK_PFM_ISCH: 4;
        uint32_t LOP_POF_BUCK_ENOCPPS_H: 1;
        uint32_t LOP_POF_LDO_ENLDO311_IB20nA: 1;
        uint32_t LOP_POF_0xAC0_RESERVED_0: 3;
        uint32_t LOP_POF_BUCK_ENOCPPFM_H: 1;
        uint32_t LOP_POF_LDO_EN_DL_LDO311: 3;
        uint32_t LOP_POF_BUCK_OCPRES_H: 2;
        uint32_t LOP_POF_BUCK_OCPSEL_H: 1;
        uint32_t LOP_POF_BUCK_VREFOCP_H: 3;
        uint32_t LOP_POF_BUCK_ENOFFSAWPFM_H: 1;
        uint32_t LOP_POF_BUCK_PFM_COT_EN: 1;
        uint32_t LOP_POF_BUCK_PFM_AOT_EN: 1;
        uint32_t LOP_POF_IBSEL_TONCOMP: 2;
        uint32_t LOP_POF_MBIAS_POW_EBIAS_AUXADC: 1;
        uint32_t LOP_POF_AON_BUCK_LOW_IQ_ZCD_32K_CLK_EN: 1;

        // 0xAC4    0x4000_0ac4
        uint32_t LOP_POF_BUCK_ENOCPS: 1;
        uint32_t LOP_POF_BUCK_POW_ZCD: 1;
        uint32_t LOP_POF_LDO_EN_DMYL_50U_LDODIGI: 1;
        uint32_t LOP_POF_LDO_EN_DMYL_200U_LDODIGI: 1;
        uint32_t LOP_POF_IB_500N_TONCOMP_EN: 1;
        uint32_t LOP_POF_IB_500N_COTCOMP_EN: 1;
        uint32_t LOP_POF_BUCK_ZCDOFFSET: 7;
        uint32_t LOP_POF_BUCK_POW_LowIq_ZCD: 1;
        uint32_t LOP_POF_BUCK_STICKY_CODE_STATE1: 1;
        uint32_t LOP_POF_BUCK_FORCE_CODE_STATE1: 1;
        uint32_t LOP_POF_0xAC4_RESERVED_1: 7;
        uint32_t LOP_POF_0xAC4_RESERVED_0: 1;
        uint32_t LOP_POF_BUCK_STICKY_CODE_STATE2: 1;
        uint32_t LOP_POF_BUCK_FORCE_CODE_STATE2: 1;
        uint32_t LOP_POF_D300k_REG_MANU_CCOT: 6;

        // 0xAC8    0x4000_0ac8
        uint32_t LOP_LPS_TIMER_WAKEUP: 1;
        uint32_t LOP_RFC_RET: 1;
        uint32_t LOP_MODEM_RET: 1;
        uint32_t LOP_BZ_RET: 1;
        uint32_t LOP_BLE_RET: 1;
        uint32_t LOP_PF_RET: 1;
        uint32_t LOP_DP_MODEM_RET: 1;
        uint32_t LOP_ZB_RET: 1;
        uint32_t LOP_POF_0xAC8_RESERVED_0: 24;

        // 0xAD8    0x4000_0ad8
        uint32_t LOP_POF_VDIGI_TUNE_STATE1: 5;
        uint32_t LOP_POF_VDIGI_TUNE_STATE2: 5;
        uint32_t LOP_POF_MBIAS_VR_SEL_LDO311_STATE1: 3;
        uint32_t LOP_POF_MBIAS_VR_SEL_LDO311_STATE2: 3;
        uint32_t LOP_VAON2VPON_PC_OFF_delay: 5;
        uint32_t LOP_POF_0xAD8_RESERVED_0: 11;
    };
} AON_LOP_POF;

typedef struct
{
    AON_LOP_PON pon[PLATFORM_POWER_MODE_MAX];
    AON_LOP_POF pof[PLATFORM_POWER_MODE_MAX];
} AONLOPTable;

typedef struct
{
    uint8_t auto_switch_base_level[AUTO_SWITCH_TABLE_MAX];
    bool lop_table_valid;
    uint32_t lop_last_write_lr;
} PMU_MANAGER;

typedef union
{
    uint32_t u32;
    struct
    {
        uint32_t CORE_BUCK_FPWM_H:              1;
        uint32_t CORE_BUCK_PFM_AOT_EN:          1;
        uint32_t CORE_BUCK_PFM_COT_EN:          1;
        uint32_t CORE_BUCK_ENOFFSAWPFM_H:       1;
        uint32_t CORE_BUCK_OCPRES_H:            2;
        uint32_t CORE_BUCK_VREFOCP_H:           3;
        uint32_t CORE_BUCK_SWRTUNE_H:           6;
        uint32_t CORE_BUCK_VREFPFM_H:           4;
        uint32_t CORE_D300k_REG_MANU_CCOT:      6;
        uint32_t CORE_LDO_ENPC_LDODIGI:         1;
        uint32_t CORE_BUCK_LDOTUNE_H:           6;
    };
} CORE_SWITCH_BUCK;

typedef union
{
    uint32_t u32;
    struct
    {
        uint32_t CORE_XTAL_LPS_CAP_STEP:        2;
        uint32_t CORE_XTAL_LPS_CAP_CYC:         2;
        uint32_t CORE_XTAL_OV_UNIT:             3;
        uint32_t CORE_XTAL_OV_RATIO:            2;
        uint32_t CORE_XTAL_MODE:                3;
        uint32_t CORE_XTAL_MODE_DLY:            2;
        uint32_t CORE_XTAL_MODE_NMPC:           1;
        uint32_t XTAL_LDOPC_SEL:                1;
        uint32_t XTAL_GATED_RFP:                1;
        uint32_t XTAL_GATED_RFN:                1;
        uint32_t XTAL_GATED_AFEP:               1;
        uint32_t XTAL_GATED_AFEN:               1;
        uint32_t RSVD:                          12;
    };
} CORE_SWITCH_XTAL;

typedef struct
{
    CORE_SWITCH_BUCK buck_table[AUTO_SWITCH_TABLE_MAX];
    CORE_SWITCH_XTAL xtal_table[AUTO_SWITCH_TABLE_MAX];
} AutoSwitchTable;

typedef enum PMUFlowType
{
    PMU_FLOW_POWER_ON                 = 0,
    PMU_FLOW_POWER_OFF                = 1,
    PMU_FLOW_DEF_MAX,
} PMUFlowType;

/** @} */ /* End of group PMU_Manager_Exported_Types */

/*============================================================================*
 *                              Variables
 *============================================================================*/
/** @defgroup PMU_Manager_Exported_Variables PMU Manager Exported Variables
  * @{
  */

extern PMU_CFG pmu_cfg;
extern PMU_MANAGER pmu_manager;
extern AutoSwitchTable auto_switch_table;

extern void (*pmu_auto_switch_map_apply)(void);
extern void (*pmu_auto_switch_map_config)(AUTO_SWITCH_RF_MODE_TYPE, AUTO_SWITCH_TABLE_TYPE);
extern void (*pmu_auto_switch_map_force_base_level)(AUTO_SWITCH_TABLE_TYPE, bool);

extern void (*ft_paras_apply)(void);

extern void (*si_flow_data_init)(void);
extern void (*si_flow_before_power_on_sequence_restart)(void);
extern void (*si_flow_after_power_on_sequence_restart)(void);
extern void (*si_flow_before_enter_low_power_mode)(void);
extern void (*si_flow_after_exit_low_power_mode)(void);

extern void (*lop_pof_setting)(PlatformPowerMode);
extern void (*lop_pon_setting)(PlatformPowerMode);
extern void (*lop_setting)(PlatformPowerMode);

extern void (*set_clk_32k_power_in_powerdown)(bool);
extern void (*pmu_set_usb_power_domain)(POWER_DOMAIN_TYPE);
extern void (*pmu_set_sdadc_mode)(SDADC_TUNE_TYPE);
extern void (*pmu_set_ldo_digi_tune_type)(LDO_DIGI_TUNE_TYPE);

extern void (*pmu_handle_vddcore)(PlatformPowerMode);
extern void (*pmu_handle_ldo_318)(bool);
extern void (*pmu_handle_ldo_318_rf)(bool);
extern void (*pmu_handle_ldo_ret)(bool);
extern void (*pmu_handle_tx_big_pout)(bool);

extern void (*pmu_sdadc_select)(SDADC_TUNE_TYPE type);

extern void (*pmu_trigger_saw_freq_update)(void);

extern void (*pmu_apply_voltage_tune)(void);

extern uint32_t (*pmu_estimate_delay)(PMUFlowType, PlatformPowerMode);
extern void (*pmu_pm_check)(PlatformPowerMode);
extern void (*pmu_pm_enter)(PlatformPowerMode);
extern void (*pmu_pm_exit)(void);

extern void (*pmu_power_on_sequence_restart)(void);

extern const AON_LOP_POF *pmu_get_lop_pof_table_for_read(PlatformPowerMode power_mode);
extern AON_LOP_POF *pmu_get_lop_pof_table_for_write(PlatformPowerMode power_mode);
extern const AON_LOP_PON *pmu_get_lop_pon_table_for_read(PlatformPowerMode power_mode);
extern AON_LOP_PON *pmu_get_lop_pon_table_for_write(PlatformPowerMode power_mode);

/** @} */ /* End of group PMU_Manager_Exported_Variables */

/*============================================================================*
 *                              Functions
 *============================================================================*/
/** @defgroup PMU_Manager_Exported_Functions PMU Manager Exported Functions
  * @{
  */

void auto_switch_table_init(void);
void auto_switch_table_enable(bool enable);

/** @} */ /* End of group PMU_Manager_Exported_Functions */

#ifdef __cplusplus
}
#endif

#endif /* __PMU_MANAGER_H */
