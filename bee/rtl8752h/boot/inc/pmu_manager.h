/**
*********************************************************************************************************
*               Copyright(c) 2020, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file         pmu_manager.h
* @brief        PMU Manager implementation head file.
* @details
* @author       George Chang
* @date         2023-01-10
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
#include "rtl876x_aon_reg.h"
#include "power_manager_unit_platform.h"
#include "clock_manager_power_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                              Types
 *============================================================================*/
/** @defgroup PMU_Manager_Exported_Types PMU Manager Exported Types
  * @{
  */

/* ===================== AON State Machine Section ======================*/
#define WAIT_AON_STATE_MACHINE_BACK_TO_ACTIVE() \
    do {\
        platform_delay_us(100);\
        while ((HAL_READ32(SYSTEM_REG_BASE, AON_REG_AON_RG5X) & 0x3) != 0);\
    } while (0)

typedef enum
{
    LDO_VDDCORE_TUNE_MIN              = 0,
    LDO_VDDCORE_TUNE_0V90             = 1,
    LDO_VDDCORE_TUNE_1V00             = 2,
    LDO_VDDCORE_TUNE_TYPE_MAX         = 3,
} LDO_VDDCORE_TUNE_TYPE;

typedef enum
{
    LDO_RET_TUNE_0V68                 = 0,
    LDO_RET_TUNE_TYPE_MAX             = 1,
} LDO_RET_TUNE_TYPE;

typedef enum
{
    LDO_VDDANA_TUNE_MIN               = 0,
    LDO_VDDANA_TUNE_1V15              = 1,
    LDO_VDDANA_TUNE_1V20              = 2,
    LDO_VDDANA_TUNE_TYPE_MAX          = 3,
} LDO_VDDANA_TUNE_TYPE;

typedef enum
{
    LDO_ANA_TUNE_1V15                 = 0,
    LDO_ANA_TUNE_1V20                 = 1,
    LDO_ANA_TUNE_TYPE_MAX             = 2,
} LDO_ANA_TUNE_TYPE;

typedef enum
{
    SWR_VDDCORE_TUNE_0V67             = 0,
    SWR_VDDCORE_TUNE_0V90             = 1,
    SWR_VDDCORE_TUNE_1V02             = 2,
    SWR_VDDCORE_TUNE_TYPE_MAX         = 3,
} SWR_VDDCORE_TUNE_TYPE;

typedef enum
{
    SWR_VDDCORE_LQ_TUNE_0V67          = 0,
    SWR_VDDCORE_LQ_TUNE_0V90          = 1,
    SWR_VDDCORE_LQ_TUNE_1V02          = 2,
    SWR_VDDCORE_LQ_TUNE_TYPE_MAX      = 3,
} SWR_VDDCORE_LQ_TUNE_TYPE;

typedef enum
{
    SWR_VDDANA_TUNE_0V90              = 0,
    SWR_VDDANA_TUNE_1V00              = 1,
    SWR_VDDANA_TUNE_1V15              = 2,
    SWR_VDDANA_TUNE_1V20              = 3,
    SWR_VDDANA_TUNE_TYPE_MAX          = 4,
} SWR_VDDANA_TUNE_TYPE;

typedef enum
{
    SWR_VDDANA_LQ_TUNE_0V90           = 0,
    SWR_VDDANA_LQ_TUNE_1V00           = 1,
    SWR_VDDANA_LQ_TUNE_1V15           = 2,
    SWR_VDDANA_LQ_TUNE_1V20           = 3,
    SWR_VDDANA_LQ_TUNE_TYPE_MAX       = 4,
} SWR_VDDANA_LQ_TUNE_TYPE;

typedef enum
{
    LDO_311_TUNE_0V90                 = 0,
    LDO_311_TUNE_1V10                 = 1,
    LDO_311_TUNE_TYPE_MAX             = 2,
} LDO_311_TUNE_TYPE;

typedef enum
{
    LDO_OSC_LV_TUNE_0V90              = 0,
    LDO_OSC_LV_TUNE_1V10              = 1,
    LDO_OSC_LV_TUNE_TYPE_MAX          = 2,
} LDO_OSC_LV_TUNE_TYPE;

typedef enum
{
    LDO_318_RF_TUNE_1V8               = 0,
    LDO_318_RF_TUNE_TYPE_MAX          = 1,
} LDO_318_RF_TUNE_TYPE;

typedef enum
{
    LDO_MICBIAS_TUNE_1V8              = 0,
    LDO_MICBIAS_TUNE_TYPE_MAX         = 1,
} LDO_MICBIAS_TUNE_TYPE;

typedef enum
{
    PFM_CCOT_TUNE_TYPE_0              = 0,
    PFM_CCOT_TUNE_TYPE_1              = 1,
    PFM_CCOT_TUNE_TYPE_MAX            = 2,
} PFM_CCOT_TUNE_TYPE;

typedef enum
{
    SWR_VDDCORE                       = 0,
    SWR_VDDANA                        = 1,
    SWR_TYPE_MAX                      = 2,
} SWR_TYPE;

typedef enum
{
    SWR_SIDO_NORMAL                   = 0,
    SWR_SIDO_BURST                    = 1,
    SWR_OFF                           = 2,
    SWR_MODE_MAX                      = 3,
    SWR_UNDEF                         = 4,
} SWR_MODE_TYPE;

typedef enum
{
    LDO_VDDCORE                       = 0,
    LDO_RET                           = 1,
    LDO_VDDANA                        = 2,
    LDO_ANA                           = 3,
    LDO_311                           = 4,
    LDO_318_RF                        = 5,
    LDO_TYPE_MAX                      = 6,
} LDO_TYPE;

typedef enum
{
    LDO_ON                            = 0,
    LDO_OFF                           = 1,
    LDO_UNDEF                         = 2,
} LDO_MODE_TYPE;

typedef enum
{
    POS_LDO_VDDANA                    = 0,
    POS_LDO_VDDCORE                   = 1,
    POS_LDO_ANA                       = 2,
    POS_SWR_VDDANA_VREF               = 3,
    POS_SWR_VDDCORE_VREF              = 4,
    POS_SWR_VDDANA_VDIV               = 5,
    POS_SWR_VDDCORE_VDIV              = 6,
    POS_TYPE_MAX                      = 7,
} POS_TYPE;

typedef enum PMUFlowType
{
    PMU_FLOW_POWER_ON                 = 0,
    PMU_FLOW_POWER_OFF                = 1,
    PMU_FLOW_DEF_MAX,
} PMUFlowType;

typedef enum _SWR_CORE_TYPE
{
    LDO_MODE                          = 0,
    SWR_PFM_MODE                      = 1,
} SWR_CORE_TYPE;

typedef enum _PMUPowerDomain
{
    ALWAYS_ACTIVE                     = 0,
    AON_DOMAIN                        = 1,
    PON_DOMAIN                        = 2,
    CORE_DOMAIN                       = 4,
    ALWAYS_INACTIVE                   = 6,
} PMUPowerDomain;

typedef union
{
    uint32_t value[12];
    struct
    {
        uint32_t core_mode: 1;
        uint32_t power_on_sequence_restart_en: 1;
        uint32_t clk_32k_power_domain: 3;
        uint32_t ldo_318_rf_power_domain: 3;
        uint32_t lop_xtal_delay: 8;
        uint32_t auto_switch_en: 1;
        uint32_t rsvd0: 15;

        SWR_MODE_TYPE swr_vddcore_mode_pof_dlps;
        SWR_MODE_TYPE swr_vddana_mode_pof_dlps;

        uint8_t swr_vddana_tune[SWR_VDDANA_TUNE_TYPE_MAX];
        uint8_t swr_vddana_lq_tune[SWR_VDDANA_LQ_TUNE_TYPE_MAX];

        uint8_t swr_vddcore_tune[SWR_VDDCORE_TUNE_TYPE_MAX];
        uint8_t ldo_ret_tune[LDO_RET_TUNE_TYPE_MAX];
        uint8_t swr_vddcore_lq_tune[SWR_VDDCORE_LQ_TUNE_TYPE_MAX];
        uint8_t ldo_318_rf_tune[LDO_318_RF_TUNE_TYPE_MAX];

        uint8_t ldo_vddcore_tune[LDO_VDDCORE_TUNE_TYPE_MAX];
        uint8_t ldo_vddana_tune[LDO_VDDANA_TUNE_TYPE_MAX];
        uint8_t ldo_ana_tune[LDO_ANA_TUNE_TYPE_MAX];

        uint8_t ldo_osc_lv_tune[LDO_OSC_LV_TUNE_TYPE_MAX];
        uint8_t ldo_311_tune[LDO_311_TUNE_TYPE_MAX];

        uint8_t buck_tune_pfm_ccot1[PFM_CCOT_TUNE_TYPE_MAX];
        uint8_t buck_tune_pfm_ccot2[PFM_CCOT_TUNE_TYPE_MAX];

        uint8_t ldo_micbias_tune[LDO_MICBIAS_TUNE_TYPE_MAX];
        uint8_t swr_vddcore_tune_1v275;
        uint8_t ldo_vddcore_tune_1v275;
        uint32_t rsvd1: 8;
    };
} PMU_CFG;

#define LOP_PON_TABLE_REGISTER_NUM      9
#define LOP_POF_TABLE_REGISTER_NUM      7

typedef union _AON_LOP_PON
{
    uint16_t d16[LOP_PON_TABLE_REGISTER_NUM];
    struct
    {
        AON_FAST_REG_AON_REG_LOP_PON_RG0X_TYPE aon_reg_lop_pon_rg0x; //0x180
        AON_FAST_REG_AON_REG_LOP_PON_RG1X_TYPE aon_reg_lop_pon_rg1x; //0x182
        AON_FAST_REG_AON_REG_LOP_PON_RG2X_TYPE aon_reg_lop_pon_rg2x; //0x184
        AON_FAST_REG_AON_REG_LOP_PON_RG3X_TYPE aon_reg_lop_pon_rg3x; //0x186
        AON_FAST_REG_AON_REG_LOP_PON_RG4X_TYPE aon_reg_lop_pon_rg4x; //0x188
        AON_FAST_REG_AON_REG_LOP_PON_RG5X_TYPE aon_reg_lop_pon_rg5x; //0x18a
        AON_FAST_REG_AON_REG_LOP_RG0X_TYPE aon_reg_lop_rg0x;         //0x1a0
        AON_FAST_REG_AON_REG_LOP_RG1X_TYPE aon_reg_lop_rg1x;         //0x1a2
        AON_FAST_REG_AON_REG_LOP_RG3X_TYPE aon_reg_lop_rg3x;         //0x1a6
    };
    struct
    {
        // AON_REG_LOP_PON_RG0X
        uint16_t LOP_PON_LDO_POW_LDORET:                1; // 0
        uint16_t LOP_PON_LDO_POW_BIAS_LDOANA:           1; // 1
        uint16_t LOP_PON_LDO_ENPC_LDOANA:               1; // 2
        uint16_t LOP_PON_LDO_POW_LDOANA:                1; // 3
        uint16_t LOP_PON_LDO_POW_VDDANA:                1; // 4
        uint16_t LOP_PON_LDO_POW_VDDCORE:               1; // 5
        uint16_t LOP_PON_FLASH_PC_VG2:                  1; // 6
        uint16_t LOP_PON_FLASH_PC_VG1:                  1; // 7
        uint16_t LOP_PON_LDO_EN_VAON_VANA_PC:           1; // 8
        uint16_t LOP_PON_LDO_EN_LDO311_DMY_LITE:        1; // 9
        uint16_t LOP_PON_LDO_POW_LDO311:                1; // 10
        uint16_t LOP_PON_LDO_EN_LDO311_VDIV:            1; // 11
        uint16_t LOP_PON_MBIAS_POR_VIO_EN:              1; // 12
        uint16_t LOP_PON_MBIAS_POR_DVDDCORE_EN:         1; // 13
        uint16_t LOP_PON_MBIAS_POW_BG_EBIAS_AUXADC:     1; // 14
        uint16_t LOP_PON_MBIAS_BIAS50NA_EN:             1; // 15

        // AON_REG_LOP_PON_RG1X
        uint16_t LOP_PON_PMU_ST_PON_RET_DMY:            1; // 0
        uint16_t LOP_PON_PMU_ST_PON_RST_DMY_1_0:        2; // 2:1
        uint16_t LOP_PON_PMU_ST_PON_CORE_DMY_1_0:       2; // 4:3
        uint16_t LOP_PON_PMU_ST_PON_POS_DMY_1_0:        2; // 6:5
        uint16_t LOP_PON_PMU_ST_PON_SWR_DMY_2_0:        3; // 9:7
        uint16_t LOP_PON_PMU_ST_PON_SWR_BIAS_DMY_2_0:   3; // 12:10
        uint16_t LOP_PON_PMU_ST_PON_BIAS_DMY_1_0:       2; // 14:13
        uint16_t LOP_PON_BUCK_EN_FLASH_PD_DISCHG:       1; // 15

        // AON_REG_LOP_PON_RG2X
        uint16_t LOP_PON_ISO_DIG_40M:                   1; // 0
        uint16_t LOP_PON_REG1X_BUCK_DUMMY_3_0:          4; // 4:1
        uint16_t LOP_PON_BUCK_SEL_LPPFM2:               1; // 5
        uint16_t LOP_PON_BUCK_SEL_LPPFM1:               1; // 6
        uint16_t LOP_PON_BUCK_POW_SWR:                  1; // 7
        uint16_t LOP_PON_BUCK_POW_PFM2_LQ:              1; // 8
        uint16_t LOP_PON_BUCK_POW_PFM1_LQ:              1; // 9
        uint16_t LOP_PON_BUCK_POW_PFM2_HQ:              1; // 10
        uint16_t LOP_PON_BUCK_POW_PFM1_HQ:              1; // 11
        uint16_t LOP_PON_BUCK_POW_VDIV2_LQ:             1; // 12
        uint16_t LOP_PON_BUCK_POW_VDIV1_LQ:             1; // 13
        uint16_t LOP_PON_BUCK_POW_VDIV2:                1; // 14
        uint16_t LOP_PON_BUCK_POW_VDIV1:                1; // 15

        // AON_REG_LOP_PON_RG3X
        uint16_t LOP_PON_LDO_VDDANA_TUNE_VDIV:          5; // 4:0
        uint16_t AON_REG_LOP_PON_RG3X_DUMMY_5:          1; // 5
        uint16_t LOP_PON_LDO_POW_BIAS_VDDANA:           1; // 6
        uint16_t LOP_PON_LDO_POW_BIAS_VDDCORE:          1; // 7
        uint16_t LOP_PON_LDO_VDDCORE_TUNE_VDIV:         5; // 12:8
        uint16_t AON_REG_LOP_PON_RG3X_DUMMY_15_13:      3; // 15:13

        // AON_REG_LOP_PON_RG4X
        uint16_t LOP_PON_BT_ANAPAR_POW_XTAL:            1; // 0
        uint16_t LOP_PON_XTAL_MODE:                     3; // 3:1
        uint16_t LOP_PON_POW_32KOSC:                    1; // 4
        uint16_t LOP_PON_POW_OSC40:                     1; // 5
        uint16_t AON_REG_LOP_PON_RG4X_DUMMY_6:          1; // 6
        uint16_t LOP_PON_LDO_ENB_DMYL_200U_LDOANA:      1; // 7
        uint16_t LOP_PON_LDO_TUNE_LDOANA:               5; // 12:8
        uint16_t LOP_PON_MBIAS_POR_VIO_SIG_SEL:         1; // 13
        uint16_t AON_REG_LOP_PON_RG4X_DUMMY_15_14:      2; // 15:14

        // AON_REG_LOP_PON_RG5X
        uint16_t AON_REG_LOP_PON_RG5X_DUMMY_0:          1; // 0
        uint16_t LOP_PON_SWR_VDDCORE_VDIV_POS_EXT_RST_B: 1; // 1
        uint16_t LOP_PON_SWR_VDDANA_VDIV_POS_EXT_RST_B: 1; // 2
        uint16_t LOP_PON_SWR_VDDCORE_VREF_POS_EXT_RST_B: 1; // 3
        uint16_t LOP_PON_SWR_VDDANA_VREF_POS_EXT_RST_B: 1; // 4
        uint16_t LOP_PON_LDO_ANA_POS_EXT_RST_B:         1; // 5
        uint16_t LOP_PON_LDO_VDDCORE_POS_EXT_RST_B:     1; // 6
        uint16_t LOP_PON_LDO_VDDANA_POS_EXT_RST_B:      1; // 7
        uint16_t AON_REG_LOP_PON_RG5X_DUMMY_8:          1; // 8
        uint16_t LOP_PON_SWR_VDDCORE_VDIV_POS_EN_POS:   1; // 9
        uint16_t LOP_PON_SWR_VDDANA_VDIV_POS_EN_POS:    1; // 10
        uint16_t LOP_PON_SWR_VDDCORE_VREF_POS_EN_POS:   1; // 11
        uint16_t LOP_PON_SWR_VDDANA_VREF_POS_EN_POS:    1; // 12
        uint16_t LOP_PON_LDO_ANA_POS_EN_POS:            1; // 13
        uint16_t LOP_PON_LDO_VDDCORE_POS_EN_POS:        1; // 14
        uint16_t LOP_PON_LDO_VDDANA_POS_EN_POS:         1; // 15

        // AON_REG_LOP_RG0X
        uint16_t LOP_SWR_BIAS_DELAY:                    8; // 7:0
        uint16_t LOP_BIAS_DELAY:                        8; // 15:8

        // AON_REG_LOP_RG1X
        uint16_t LOP_POS_DELAY:                         8; // 7:0
        uint16_t LOP_SWR_DELAY:                         8; // 15:8

        // AON_REG_LOP_RG3X
        uint16_t LOP_CORE_DELAY:                        8; // 7:0
        uint16_t LOP_XTAL_DELAY:                        8; // 15:8
    };
} AON_LOP_PON;

typedef union _AON_LOP_POF
{
    uint16_t d16[LOP_POF_TABLE_REGISTER_NUM];
    struct
    {
        AON_FAST_REG_AON_REG_LOP_POF_RG0X_TYPE aon_reg_lop_pof_rg0x; //0x190
        AON_FAST_REG_AON_REG_LOP_POF_RG1X_TYPE aon_reg_lop_pof_rg1x; //0x192
        AON_FAST_REG_AON_REG_LOP_POF_RG2X_TYPE aon_reg_lop_pof_rg2x; //0x194
        AON_FAST_REG_AON_REG_LOP_POF_RG3X_TYPE aon_reg_lop_pof_rg3x; //0x196
        AON_FAST_REG_AON_REG_LOP_POF_RG4X_TYPE aon_reg_lop_pof_rg4x; //0x198
        AON_FAST_REG_AON_REG_LOP_POF_RG5X_TYPE aon_reg_lop_pof_rg5x; //0x19a
        AON_FAST_REG_AON_REG_LOP_RG2X_TYPE aon_reg_lop_rg2x;         //0x1a4
    };
    struct
    {
        // AON_REG_LOP_POF_RG0X
        uint16_t LOP_POF_LDO_POW_LDORET:                1; // 0
        uint16_t LOP_POF_LDO_POW_BIAS_LDOANA:           1; // 1
        uint16_t LOP_POF_LDO_ENPC_LDOANA:               1; // 2
        uint16_t LOP_POF_LDO_POW_LDOANA:                1; // 3
        uint16_t LOP_POF_LDO_POW_VDDANA:                1; // 4
        uint16_t LOP_POF_LDO_POW_VDDCORE:               1; // 5
        uint16_t LOP_POF_FLASH_PC_VG2:                  1; // 6
        uint16_t LOP_POF_FLASH_PC_VG1:                  1; // 7
        uint16_t LOP_POF_LDO_EN_VAON_VANA_PC:           1; // 8
        uint16_t LOP_POF_LDO_EN_LDO311_DMY_LITE:        1; // 9
        uint16_t LOP_POF_LDO_POW_LDO311:                1; // 10
        uint16_t LOP_POF_LDO_EN_LDO311_VDIV:            1; // 11
        uint16_t LOP_POF_MBIAS_POR_VIO_EN:              1; // 12
        uint16_t LOP_POF_MBIAS_POR_DVDDCORE_EN:         1; // 13
        uint16_t LOP_POF_MBIAS_POW_BG_EBIAS_AUXADC:     1; // 14
        uint16_t LOP_POF_MBIAS_BIAS50NA_EN:             1; // 15

        // AON_REG_LOP_POF_RG1X
        uint16_t LOP_POF_PMU_ST_PON_RET_DMY:            1; // 0
        uint16_t LOP_POF_PMU_ST_PON_RST_DMY_1_0:        2; // 2:1
        uint16_t LOP_POF_PMU_ST_PON_CORE_DMY_1_0:       2; // 4:3
        uint16_t LOP_POF_PMU_ST_PON_POS_DMY_1_0:        2; // 6:5
        uint16_t LOP_POF_PMU_ST_PON_SWR_DMY_2_0:        3; // 9:7
        uint16_t LOP_POF_PMU_ST_PON_SWR_BIAS_DMY_2_0:   3; // 12:10
        uint16_t LOP_POF_PMU_ST_PON_BIAS_DMY_1_0:       2; // 14:13
        uint16_t LOP_POF_BUCK_EN_FLASH_PD_DISCHG:       1; // 15

        // AON_REG_LOP_POF_RG2X
        uint16_t LOP_POF_ISO_DIG_40M:                   1; // 0
        uint16_t LOP_POF_REG1X_BUCK_DUMMY_3_0:          4; // 4:1
        uint16_t LOP_POF_BUCK_SEL_LPPFM2:               1; // 5
        uint16_t LOP_POF_BUCK_SEL_LPPFM1:               1; // 6
        uint16_t LOP_POF_BUCK_POW_SWR:                  1; // 7
        uint16_t LOP_POF_BUCK_POW_PFM2_LQ:              1; // 8
        uint16_t LOP_POF_BUCK_POW_PFM1_LQ:              1; // 9
        uint16_t LOP_POF_BUCK_POW_PFM2_HQ:              1; // 10
        uint16_t LOP_POF_BUCK_POW_PFM1_HQ:              1; // 11
        uint16_t LOP_POF_BUCK_POW_VDIV2_LQ:             1; // 12
        uint16_t LOP_POF_BUCK_POW_VDIV1_LQ:             1; // 13
        uint16_t LOP_POF_BUCK_POW_VDIV2:                1; // 14
        uint16_t LOP_POF_BUCK_POW_VDIV1:                1; // 15

        // AON_REG_LOP_POF_RG3X
        uint16_t LOP_POF_LDO_VDDANA_TUNE_VDIV:          5; // 4:0
        uint16_t AON_REG_LOP_POF_RG3X_DUMMY_5:          1; // 5
        uint16_t LOP_POF_LDO_POW_BIAS_VDDANA:           1; // 6
        uint16_t LOP_POF_LDO_POW_BIAS_VDDCORE:          1; // 7
        uint16_t LOP_POF_LDO_VDDCORE_TUNE_VDIV:         5; // 12:8
        uint16_t AON_REG_LOP_POF_RG3X_DUMMY_13:         1; // 13
        uint16_t LOP_POF_SEL_IPTAT:                     1; // 14
        uint16_t LOP_POF_SEL_LV:                        1; // 15

        // AON_REG_LOP_POF_RG4X
        uint16_t LOP_POF_BT_ANAPAR_POW_XTAL:            1; // 0
        uint16_t LOP_POF_XTAL_MODE:                     3; // 3:1
        uint16_t LOP_POF_POW_32KOSC:                    1; // 4
        uint16_t LOP_POF_POW_OSC40:                     1; // 5
        uint16_t LOP_POF_AON_GATED_EN:                  1; // 6
        uint16_t LOP_POF_CAL:                           1; // 7
        uint16_t LOP_POF_LDO_TUNE_LDOANA:               5; // 12:8
        uint16_t LOP_POF_MBIAS_POR_VIO_SIG_SEL:         1; // 13
        uint16_t LOP_POF_VCORE_PC_VG2:                  1; // 14
        uint16_t LOP_POF_VCORE_PC_VG1:                  1; // 15

        // AON_REG_LOP_POF_RG5X
        uint16_t AON_REG_LOP_POF_RG5X_DUMMY_0:          1; // 0
        uint16_t LOP_POF_SWR_VDDCORE_VDIV_POS_EXT_RST_B: 1; // 1
        uint16_t LOP_POF_SWR_VDDANA_VDIV_POS_EXT_RST_B: 1; // 2
        uint16_t LOP_POF_SWR_VDDCORE_VREF_POS_EXT_RST_B: 1; // 3
        uint16_t LOP_POF_SWR_VDDANA_VREF_POS_EXT_RST_B: 1; // 4
        uint16_t LOP_POF_LDO_ANA_POS_EXT_RST_B:         1; // 5
        uint16_t LOP_POF_LDO_VDDCORE_POS_EXT_RST_B:     1; // 6
        uint16_t LOP_POF_LDO_VDDANA_POS_EXT_RST_B:      1; // 7
        uint16_t AON_REG_LOP_POF_RG5X_DUMMY_8:          1; // 8
        uint16_t LOP_POF_SWR_VDDCORE_VDIV_POS_EN_POS:   1; // 9
        uint16_t LOP_POF_SWR_VDDANA_VDIV_POS_EN_POS:    1; // 10
        uint16_t LOP_POF_SWR_VDDCORE_VREF_POS_EN_POS:   1; // 11
        uint16_t LOP_POF_SWR_VDDANA_VREF_POS_EN_POS:    1; // 12
        uint16_t LOP_POF_LDO_ANA_POS_EN_POS:            1; // 13
        uint16_t LOP_POF_LDO_VDDCORE_POS_EN_POS:        1; // 14
        uint16_t LOP_POF_LDO_VDDANA_POS_EN_POS:         1; // 15

        // AON_REG_LOP_RG2X
        uint16_t LOP_ZB_RET:                            1; // 0
        uint16_t LOP_RFC_RET:                           1; // 1
        uint16_t LOP_MODEM_RET:                         1; // 2
        uint16_t LOP_BZ_RET:                            1; // 3
        uint16_t LOP_BLE_RET:                           1; // 4
        uint16_t LOP_PF_RET:                            1; // 5
        uint16_t LOP_DP_MODEM_RET:                      1; // 6
        uint16_t AON_REG_LOP_RG2X_RESERVED_1:           1; // 7
        uint16_t LOP_POF_RET_DELAY:                     8; // 15:8
    };
} AON_LOP_POF;

typedef struct
{
    AON_LOP_PON pon[PLATFORM_POWER_MODE_MAX];
    AON_LOP_POF pof[PLATFORM_POWER_MODE_MAX];
} AONLOPTable;

#define POS_TABLE_REGISTER_NUM  4

typedef union
{
    uint16_t d16[POS_TABLE_REGISTER_NUM];
    struct
    {
        /* pos_reg0x */
        uint16_t POS_INT_RST_B: 1;
        uint16_t RO_POS_EXT_RST_B: 1;
        uint16_t POS_SEL_EXT_RST_B: 1;
        uint16_t RO_POS_EN_POS: 1;
        uint16_t POS_DIV_CLK: 3;
        uint16_t POS_EN_DR_FIX: 1;
        uint16_t POS_REG0X_DUMMY8: 1;
        uint16_t POS_REG0X_DUMMY9: 1;
        uint16_t POS_REG0X_DUMMY10: 1;
        uint16_t POS_REG0X_DUMMY11: 1;
        uint16_t POS_REG0X_DUMMY12: 1;
        uint16_t POS_REG0X_DUMMY13: 1;
        uint16_t POS_REG0X_DUMMY14: 1;
        uint16_t POS_REG0X_DUMMY15: 1;

        /* pos_reg1x */
        uint16_t POS_POF_STEP: 3;
        uint16_t POS_REG1X_DUMMY3: 1;
        uint16_t POS_PON_STEP: 3;
        uint16_t POS_REG1X_DUMMY7: 1;
        uint16_t POS_POF_WAIT: 3;
        uint16_t POS_PON_WAIT: 3;
        uint16_t POS_REG1X_DUMMY14: 1;
        uint16_t POS_REG1X_DUMMY15: 1;

        /* pos_reg2x */
        uint16_t POS_PON_OVER: 3;
        uint16_t POS_REG2X_DUMMY7_3: 5;
        uint16_t POS_PON_START: 3;
        uint16_t POS_REG2X_DUMMY15_11: 5;

        /* pos_reg3x */
        uint16_t POS_POF_OVER: 3;
        uint16_t POS_REG3X_DUMMY7_3: 5;
        uint16_t POS_POF_START: 3;
        uint16_t POS_REG3X_DUMMY15_11: 5;
    };
} AON_FAST_POS_LDO;

typedef union
{
    uint16_t d16[POS_TABLE_REGISTER_NUM];
    struct
    {
        /* pos_reg0x */
        uint16_t POS_INT_RST_B: 1;
        uint16_t RO_POS_EXT_RST_B: 1;
        uint16_t POS_SEL_EXT_RST_B: 1;
        uint16_t RO_POS_EN_POS: 1;
        uint16_t POS_DIV_CLK: 3;
        uint16_t POS_EN_DR_FIX: 1;
        uint16_t POS_REG0X_DUMMY8: 1;
        uint16_t POS_REG0X_DUMMY9: 1;
        uint16_t POS_REG0X_DUMMY10: 1;
        uint16_t POS_REG0X_DUMMY11: 1;
        uint16_t POS_REG0X_DUMMY12: 1;
        uint16_t POS_REG0X_DUMMY13: 1;
        uint16_t POS_REG0X_DUMMY14: 1;
        uint16_t POS_REG0X_DUMMY15: 1;

        /* pos_reg1x */
        uint16_t POS_POF_STEP: 4;
        uint16_t POS_PON_STEP: 4;
        uint16_t POS_POF_WAIT: 3;
        uint16_t POS_PON_WAIT: 3;
        uint16_t POS_REG1X_DUMMY14: 1;
        uint16_t POS_REG1X_DUMMY15: 1;

        /* pos_reg2x */
        uint16_t POS_PON_OVER: 5;
        uint16_t POS_REG2X_DUMMY7_3: 3;
        uint16_t POS_PON_START: 5;
        uint16_t POS_REG2X_DUMMY15_11: 3;

        /* pos_reg3x */
        uint16_t POS_POF_OVER: 5;
        uint16_t POS_REG3X_DUMMY7_3: 3;
        uint16_t POS_POF_START: 5;
        uint16_t POS_REG3X_DUMMY15_11: 3;
    };
} AON_FAST_POS_SWR_VREF;

typedef union
{
    uint16_t d16[POS_TABLE_REGISTER_NUM];
    struct
    {
        /* pos_reg0x */
        uint16_t POS_INT_RST_B: 1;
        uint16_t RO_POS_EXT_RST_B: 1;
        uint16_t POS_SEL_EXT_RST_B: 1;
        uint16_t RO_POS_EN_POS: 1;
        uint16_t POS_DIV_CLK: 3;
        uint16_t POS_EN_DR_FIX: 1;
        uint16_t POS_REG0X_DUMMY8: 1;
        uint16_t POS_REG0X_DUMMY9: 1;
        uint16_t POS_REG0X_DUMMY10: 1;
        uint16_t POS_REG0X_DUMMY11: 1;
        uint16_t POS_REG0X_DUMMY12: 1;
        uint16_t POS_REG0X_DUMMY13: 1;
        uint16_t POS_REG0X_DUMMY14: 1;
        uint16_t POS_REG0X_DUMMY15: 1;

        /* pos_reg1x */
        uint16_t POS_POF_STEP: 4;
        uint16_t POS_PON_STEP: 4;
        uint16_t POS_POF_WAIT: 3;
        uint16_t POS_PON_WAIT: 3;
        uint16_t POS_REG1X_DUMMY14: 1;
        uint16_t POS_REG1X_DUMMY15: 1;

        /* pos_reg2x */
        uint16_t POS_PON_OVER: 8;
        uint16_t POS_PON_START: 8;

        /* pos_reg3x */
        uint16_t POS_POF_OVER: 8;
        uint16_t POS_POF_START: 8;
    };
} AON_FAST_POS_SWR_VDIV;

typedef union
{
    uint16_t d16[POS_TABLE_REGISTER_NUM];
    AON_FAST_POS_LDO pos_ldo_vddana;
    AON_FAST_POS_LDO pos_ldo_vddcore;
    AON_FAST_POS_LDO pos_ldo_ana;
    AON_FAST_POS_SWR_VREF pos_swr_vddana_vref;
    AON_FAST_POS_SWR_VDIV pos_swr_vddana_vdiv;
    AON_FAST_POS_SWR_VREF pos_swr_vddcore_vref;
    AON_FAST_POS_SWR_VDIV pos_swr_vddcore_vdiv;
} AON_FAST_POS;

typedef struct
{
    uint16_t addr[POS_TYPE_MAX];
    AON_FAST_POS reg[POS_TYPE_MAX];
} AON_FAST_POS_Table;

typedef struct
{
    SWR_MODE_TYPE swr_core_mode_pon[PLATFORM_POWER_MODE_MAX][SWR_TYPE_MAX];
    SWR_MODE_TYPE swr_core_mode_pof[PLATFORM_POWER_MODE_MAX][SWR_TYPE_MAX];

    LDO_MODE_TYPE ldo_mode_pon[PLATFORM_POWER_MODE_MAX][LDO_TYPE_MAX];
    LDO_MODE_TYPE ldo_mode_pof[PLATFORM_POWER_MODE_MAX][LDO_TYPE_MAX];

    bool lop_table_valid;
    bool pos_table_valid;
    uint32_t lop_last_write_lr;
    uint32_t pos_last_write_lr;
} PMU_MANAGER;

/** @} */ /* End of group PMU_Manager_Exported_Types */

/*============================================================================*
 *                              Variables
 *============================================================================*/
/** @defgroup PMU_Manager_Exported_Variables PMU Manager Exported Variables
  * @{
  */

extern PMU_CFG pmu_cfg;
extern PMU_MANAGER pmu_manager;

extern void (*ft_paras_apply)(void);

extern void (*pmu_set_en_dr_fix)(bool);
extern void (*si_flow_data_init)(void);
extern void (*si_flow_before_power_on_sequence_restart)(void);
extern void (*si_flow_after_power_on_sequence_restart)(void);
extern void (*si_flow_before_enter_low_power_mode)(void);
extern void (*si_flow_after_exit_low_power_mode)(void);

extern void (*lop_pof_setting)(PlatformPowerMode);
extern void (*lop_pon_setting)(PlatformPowerMode);
extern void (*lop_setting)(PlatformPowerMode);
extern void (*pos_reg_setting)(POS_TYPE);
extern void (*pos_setting)(void);

extern uint8_t (*pmu_get_swr_vddcore_hq_tune)(PMUFlowType, PlatformPowerMode);
extern uint8_t (*pmu_get_swr_vddcore_lq_tune)(PMUFlowType, PlatformPowerMode);
extern uint8_t (*pmu_get_swr_vddana_hq_tune)(PMUFlowType, PlatformPowerMode);
extern uint8_t (*pmu_get_swr_vddana_lq_tune)(PMUFlowType, PlatformPowerMode);
extern uint8_t (*pmu_get_ldo_vddcore_tune)(PMUFlowType, PlatformPowerMode);
extern uint8_t (*pmu_get_ldo_vddana_tune)(PMUFlowType, PlatformPowerMode);

extern void (*pmu_set_pos_div_clk)(POS_TYPE, uint8_t);
extern void (*pmu_set_pos_pon_tune)(POS_TYPE, uint8_t);
extern void (*pmu_set_pos_pof_tune)(POS_TYPE, uint8_t);
extern uint8_t (*pmu_get_pos_pon_delay)(POS_TYPE);
extern uint8_t (*pmu_get_pos_pof_delay)(POS_TYPE);

extern void (*set_clk_32k_power_in_powerdown)(bool);
extern uint32_t (*pmu_estimate_delay)(PMUFlowType, PlatformPowerMode);
extern void (*pmu_check_ldo_vddcore)(PlatformPowerMode);
extern void (*pmu_check_ldo_ret)(PlatformPowerMode);
extern void (*pmu_check_ldo_vddana)(PlatformPowerMode);
extern void (*pmu_check_ldo_ana)(PlatformPowerMode);
extern void (*pmu_check_swr_vddcore)(PlatformPowerMode);
extern void (*pmu_check_swr_vddana)(PlatformPowerMode);
extern void (*pmu_check_swr_core)(PlatformPowerMode);
extern void (*pmu_check_vcore)(PlatformPowerMode);
extern void (*pmu_check_ldo_311)(PlatformPowerMode);
extern void (*pmu_check_mbias)(PlatformPowerMode);
extern void (*pmu_check_delay)(PlatformPowerMode);

extern void (*pmu_handle_swr_core_lq)(PMUFlowType, PlatformPowerMode);
extern void (*pmu_handle_ldo_318_rf)(PlatformPowerMode);

extern void (*pmu_apply_voltage_tune)(void);
extern void (*pmu_pm_check)(PlatformPowerMode);
extern void (*pmu_pm_enter)(PlatformPowerMode);
extern void (*pmu_pm_exit)(void);
extern void (*pmu_power_on_sequence_restart)(void);

extern CLOCK_40M_CONFIG_Type(*get_active_clock_pof_config)(PlatformPowerMode power_mode);
extern CLOCK_32K_CONFIG_Type(*get_low_power_clock_pof_config)(PlatformPowerMode power_mode);

/** @} */ /* End of group PMU_Manager_Exported_Variables */

/*============================================================================*
 *                              Functions
 *============================================================================*/
/** @defgroup PMU_Manager_Exported_Functions PMU Manager Exported Functions
  * @{
  */

const AON_LOP_POF *pmu_get_lop_pof_table_for_read(PlatformPowerMode power_mode);
AON_LOP_POF *pmu_get_lop_pof_table_for_write(PlatformPowerMode power_mode);
const AON_LOP_PON *pmu_get_lop_pon_table_for_read(PlatformPowerMode power_mode);
AON_LOP_PON *pmu_get_lop_pon_table_for_write(PlatformPowerMode power_mode);
const AON_FAST_POS *pmu_get_pos_table_for_read(POS_TYPE pos_type);
AON_FAST_POS *pmu_get_pos_table_for_write(POS_TYPE pos_type);

/** @} */ /* End of group PMU_Manager_Exported_Functions */

#ifdef __cplusplus
}
#endif

#endif /* __PMU_MANAGER_H */
