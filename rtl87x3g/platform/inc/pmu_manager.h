/**
  *****************************************************************************************
  *     Copyright(c) 2020, Realtek Semiconductor Corporation. All rights reserved.
  *****************************************************************************************
  * @file    pmu_manager.h
  * @brief   PMU implementation head file.
  * @author  Po Yu Chen
  * @date    2020-09-01
  * @version v0.1
  * *************************************************************************************
  */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __PMU_MANAGER_H
#define __PMU_MANAGER_H

/*============================================================================*
 *                               Header Files
 *============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "power_manager_unit_platform.h"
#include "rtl876x_aon_reg.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                              Definitions
 *============================================================================*/
#define WAIT_AON_STATE_MACHINE_BACK_TO_ACTIVE()                         \
    do {                                                                \
        platform_delay_us(100);                                         \
        while ((HAL_READ32(SYSON_BASE, AON_RG4X) & 0x3) != 0);     \
    } while (0)

#define LDO_AUX_HQ_TUNE_BOUND_FOR_RESISTANCE    0x1E    // 2.465V
#define LDO_AUX_LQ_TUNE_BOUND_FOR_RESISTANCE    0x1F    // 2.465V

/*============================================================================*
 *                              Types
 *============================================================================*/
/** @defgroup PMU_MANAGER_Exported_Types PMU Manager Exported Types
  * @{
  */
typedef enum _SWR_CORE_AUDIO_TYPE
{
    LDO_MODE        = 0,
    SWR_MODE        = 1,
} SWR_CORE_AUDIO_TYPE;

typedef enum
{
    PFM_CCM_MODE    = 0,
    PFM_DCM_MODE    = 1,

    PWM_MODE        = 3,
} SWR_MODE_TYPE;

typedef enum _LDO_POWER_DOMAIN_TYPE
{
    ALWAYS_ACTIVE   = 0,
    AON_DOMAIN      = 1,
    PON_DOMAIN      = 2,
    CORE_DOMAIN     = 4,
    ALWAYS_INACTIVE = 6,
} LDO_POWER_DOMAIN_TYPE;

typedef enum
{
    SWR_CORE_TUNE_0V67              = 0,
    SWR_CORE_TUNE_1V00              = 1,
    SWR_CORE_TUNE_1V10              = 2,
    SWR_CORE_TUNE_1V21              = 3,
    SWR_CORE_TUNE_TYPE_MAX          = 4,
} SWR_CORE_TUNE_TYPE;

typedef enum
{
    LDO_RET_TUNE_0V67               = 0,
    LDO_RET_TUNE_1V00               = 1,
    LDO_RET_TUNE_1V10               = 2,
    LDO_RET_TUNE_TYPE_MAX           = 3,
} LDO_RET_TUNE_TYPE;

typedef enum
{
    LDO_DIG_TUNE_1V00               = 0,
    LDO_DIG_TUNE_1V10               = 1,
    LDO_DIG_TUNE_TYPE_MAX           = 2,
} LDO_DIG_TUNE_TYPE;

typedef enum
{
    VDDIO_0                         = 0,
    VDDIO_1                         = 1,
    VDDIO_2                         = 2,
    VDDIO_TYPE_MAX                  = 3,
} VDDIO_TYPE;

typedef enum
{
    VCORE_1                         = 0,
    VCORE_2                         = 1,
    VCORE_TYPE_MAX                  = 2,
} VCORE_TYPE;

typedef union
{
    uint8_t d8;
    struct
    {
        uint8_t vcore1: 3;
        uint8_t vcore2: 3;
        uint8_t rsvd: 2;
    };
} VCORE_POWER_DOMAIN;

typedef enum
{
    AVCC_DRV_POWER_OFF      = 0x0,
    AVCC_DRV_POWER_BY_LQ    = 0x1,
    AVCC_DRV_POWER_BY_HQ    = 0x2,
    AVCC_DRV_POWER_BY_BOTH  = 0x3,
} AVCC_DRV_POWER_TYPE;

typedef union
{
    uint32_t value[12];
    struct
    {
        uint8_t swr_core_ldo[SWR_CORE_TUNE_TYPE_MAX];
        uint8_t swr_core_pwm[SWR_CORE_TUNE_TYPE_MAX];
        uint8_t swr_core_pfm[SWR_CORE_TUNE_TYPE_MAX];
        uint8_t swr_core_lppfm;

        uint8_t swr_audio_ldo;
        uint8_t swr_audio_pfm;

        uint8_t ldo_ret_tune[LDO_RET_TUNE_TYPE_MAX];
        uint8_t ldo_dig_tune[LDO_DIG_TUNE_TYPE_MAX];

        uint32_t core_mode: 1;
        uint32_t audio_mode: 1;
        uint32_t power_on_sequence_restart: 1;
        uint32_t auto_switch_enable: 1;
        uint32_t clk_32k_power_domain: 3;
        uint32_t ldo_311_aon_tune_normal: 5;
        uint32_t ldo_311_aux_lq_tune_normal: 5;
        uint32_t ldo_311_aux_lq_tune_guard: 5;
        uint32_t ldo_311_aux_lq_power_domain: 3;
        uint32_t ldo_311_aon_tune_guard: 5;
        uint32_t rsvd1: 2;

        uint32_t ldo_318_tune: 4;
        uint32_t ldo_pa_tune: 8;
        uint32_t ldo_318_power_domain: 3;
        uint32_t ldo_pa_power_domain: 3;
        uint32_t ldo_sys_vcore_lq_tune_guard: 6;
        uint32_t saw_freq_tune: 6;
        uint32_t rsvd2: 2;

        uint32_t ldo_sys_hq_tune: 6;
        uint32_t ldo_sys_lq_tune_normal: 6;
        uint32_t ldo_sys_lq_tune_guard: 6;
        uint32_t ldo_sys_vcore_lq_tune_normal: 6;
        uint32_t ldo_sys_hq_power_domain: 3;
        uint32_t ldo_sys_vcore_lq_power_domain: 3;
        uint32_t rsvd3: 2;

        uint32_t ldo_aux1_hq_tune: 6;
        uint32_t ldo_aux1_lq_tune_normal: 6;
        uint32_t ldo_aux1_lq_tune_guard: 6;
        uint32_t ldo_aux1_hq_power_domain: 3;
        uint32_t ldo_aux1_lq_power_domain: 3;
        uint32_t ldo_aux1_lq_add_bias_power_domain: 3;
        uint32_t rsvd4: 5;

        uint32_t ldo_aux2_hq_tune: 6;
        uint32_t ldo_aux2_lq_tune_normal: 6;
        uint32_t ldo_aux2_lq_tune_guard: 6;
        uint32_t ldo_aux2_hq_power_domain: 3;
        uint32_t ldo_aux2_lq_power_domain: 3;
        uint32_t ldo_aux2_lq_add_bias_power_domain: 3;
        uint32_t rsvd5: 5;

        uint32_t ldo_audio_lq_tune_normal: 5;
        uint32_t ldo_audio_lq_tune_guard: 5;
        uint32_t ldo_avcc_tune: 4;
        uint32_t avcc_drv_hq_power_domain: 3;
        uint32_t avcc_drv_lq_power_domain: 3;
        uint32_t ldo_avcc_hq_power_domain: 3;
        uint32_t ldo_733_dpd_tune: 3;
        uint32_t rsvd6: 6;

        VCORE_POWER_DOMAIN vcore_power_domain;

        uint8_t rsvd7[3];
    };
} PMU_CFG;

typedef union
{
    struct
    {
        AON_FAST_AON_REG_LOP_PON_RG0X_TYPE lop_pon_rg0x;
        AON_FAST_AON_REG_LOP_PON_RG1X_TYPE lop_pon_rg1x;
        AON_FAST_AON_REG_LOP_PON_RG2X_TYPE lop_pon_rg2x;
        AON_FAST_AON_REG_LOP_PON_RG3X_TYPE lop_pon_rg3x;
        AON_FAST_AON_REG_LOP_PON_RG4X_TYPE lop_pon_rg4x;
        AON_FAST_AON_REG_LOP_PON_RG5X_TYPE lop_pon_rg5x;
        AON_FAST_AON_REG_LOP_PON_RG6X_TYPE lop_pon_rg6x;
        AON_FAST_AON_REG_LOP_PON_RG7X_TYPE lop_pon_rg7x;
        AON_FAST_AON_REG_LOP_PON_RG8X_TYPE lop_pon_rg8x;
        AON_FAST_AON_REG_LOP_PON_RG9X_TYPE lop_pon_rg9x;

        AON_FAST_AON_REG_LOP_PON_DELAY_RG0X_TYPE lop_pon_delay_rg0x;
        AON_FAST_AON_REG_LOP_PON_DELAY_RG1X_TYPE lop_pon_delay_rg1x;
        AON_FAST_AON_REG_LOP_PON_DELAY_RG2X_TYPE lop_pon_delay_rg2x;
        AON_FAST_AON_REG_LOP_PON_DELAY_RG3X_TYPE lop_pon_delay_rg3x;
        AON_FAST_AON_REG_LOP_PON_DELAY_RG4X_TYPE lop_pon_delay_rg4x;
        AON_FAST_AON_REG_LOP_PON_DELAY_RG5X_TYPE lop_pon_delay_rg5x;
        AON_FAST_AON_REG_LOP_PON_DELAY_RG6X_TYPE lop_pon_delay_rg6x;
    };

    struct
    {
        /* lop_pon_rg0x */
        uint16_t AON_REG_LOP_PON_CHG_POW_M1: 1;
        uint16_t AON_REG_LOP_PON_CHG_POW_M2_DVDET: 1;
        uint16_t AON_REG_LOP_PON_CHG_POW_M1_DVDET: 1;
        uint16_t AON_REG_LOP_PON_CHG_EN_M1FON_LDO733: 1;
        uint16_t AON_REG_LOP_PON_CHG_EN_M2FONBUF: 1;
        uint16_t AON_REG_LOP_PON_CHG_EN_M2FON1K: 1;
        uint16_t AON_REG_LOP_PON_POW32K_32KXTAL: 1;
        uint16_t AON_REG_LOP_PON_POW32K_32KOSC: 1;
        uint16_t AON_REG_LOP_PON_MBIAS_POW_VAUDIO_DET: 1;
        uint16_t AON_REG_LOP_PON_MBIAS_POW_VDDCORE_DET: 1;
        uint16_t AON_REG_LOP_PON_MBIAS_POW_VAUX_DET: 1;
        uint16_t AON_REG_LOP_PON_MBIAS_POW_HV_DET: 1;
        uint16_t AON_REG_LOP_PON_MBIAS_POW_VBAT_DET: 1;
        uint16_t AON_REG_LOP_PON_MBIAS_POW_ADP_DET: 1;
        uint16_t AON_REG_LOP_PON_MBIAS_POW_BIAS_500nA: 1;
        uint16_t AON_REG_LOP_PON_MBIAS_POW_BIAS: 1;

        /* lop_pon_rg1x */
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_SAW_IB: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_IMIR: 1;
        uint16_t AON_REG_LOP_PON_LDOAUX1_POW_LDO533HQ: 1;
        uint16_t AON_REG_LOP_PON_LDOAUX1_EN_POS: 1;
        uint16_t AON_REG_LOP_PON_LDOSYS_POW_HQLQ533_PC: 1;
        uint16_t AON_REG_LOP_PON_LDOSYS_POW_HQLQVCORE533_PC: 1;
        uint16_t AON_REG_LOP_PON_LDOAUX1_POS_RST_B: 1;
        uint16_t AON_REG_LOP_PON_LDOAUX1_POW_VREF: 1;
        uint16_t AON_REG_LOP_PON_LDOSYS_POW_LDO533HQ: 1;
        uint16_t AON_REG_LOP_PON_LDOSYS_EN_POS: 1;
        uint16_t AON_REG_LOP_PON_LDOSYS_POW_LDO733LQ_VCORE: 1;
        uint16_t AON_REG_LOP_PON_CHG_SEL_M2CCDFB: 2;
        uint16_t AON_REG_LOP_PON_LDOSYS_POS_RST_B: 1;
        uint16_t AON_REG_LOP_PON_LDOSYS_POW_LDOVREF: 1;
        uint16_t AON_REG_LOP_PON_CHG_POW_M2: 1;

        /* lop_pon_rg2x */
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_ZCD_COMP_LOWIQ: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_TUNE_BNYCNT_INI: 6;
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_BNYCNT_1: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_FPWM_1: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_OCP: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_ZCD: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_PFM: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_PWM: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_VDIV: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_REF: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_SAW: 1;

        /* lop_pon_rg3x */
        uint16_t AON_REG_LOP_PON_RG3X_DUMMY1: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_BNYCNT_2: 1;
        uint16_t AON_REG_LOP_PON_LDO_DIG_POW_LDODIG: 1;
        uint16_t AON_REG_LOP_PON_LDO_DIG_EN_POS: 1;
        uint16_t AON_REG_LOP_PON_LDO_DIG_EN_LDODIG_PC: 1;
        uint16_t AON_REG_LOP_PON_XTAL_LPS_CAP_STEP: 2;
        uint16_t AON_REG_LOP_PON_XTAL_LPS_CAP_CYC: 2;
        uint16_t AON_REG_LOP_PON_LDO_DIG_POS_RST_B: 1;
        uint16_t AON_REG_LOP_PON_LDO_DIG_TUNE_LDODIG_VOUT: 5;
        uint16_t AON_REG_LOP_PON_LDO_DIG_POW_LDODIG_VREF: 1;

        /* lop_pon_rg4x */
        uint16_t AON_REG_LOP_PON_RG4X_DUMMY1: 4;
        uint16_t AON_REG_LOP_PON_SWR_CORE_TUNE_POS_VREFPFM: 8;
        uint16_t AON_REG_LOP_PON_SWR_CORE_TUNE_REF_VREFLPPFM: 4;

        /* lop_pon_rg5x */
        uint16_t AON_REG_LOP_PON_BLE_RESTORE: 1;
        uint16_t AON_REG_LOP_PON_VCORE_PC_POW_VCORE_PC_VG2: 1;
        uint16_t AON_REG_LOP_PON_VCORE_PC_POW_VCORE_PC_VG1: 1;
        uint16_t AON_REG_LOP_PON_LDO_DIG_POW_LDORET: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_SWR: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_POW_LDO: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_SEL_POS_VREFLPPFM: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_FPWM_2: 1;
        uint16_t AON_REG_LOP_PON_SWR_CORE_TUNE_VDIV: 8;

        /* lop_pon_rg6x */
        uint16_t AON_REG_LOP_PON_BT_PLL1_pow_pll: 1;
        uint16_t AON_REG_LOP_PON_BT_PLL_LDO_pow_LDO: 1;
        uint16_t AON_REG_LOP_PON_BT_PLL_LDO_ERC_V12A_BTPLL: 1;
        uint16_t AON_REG_LOP_PON_BT_PLL_LDO_SW_LDO2PORCUT: 1;
        uint16_t AON_REG_LOP_PON_ISO_XTAL: 1;
        uint16_t AON_REG_LOP_PON_OSC40M_POW_OSC: 1;
        uint16_t AON_REG_LOP_PON_XTAL_MODE: 3;
        uint16_t AON_REG_LOP_PON_XTAL_POW_XTAL: 1;
        uint16_t AON_REG_LOP_PON_BT_RET_RSTB: 1;
        uint16_t AON_REG_LOP_PON_RFC_RESTORE: 1;
        uint16_t AON_REG_LOP_PON_PF_RESTORE: 1;
        uint16_t AON_REG_LOP_PON_MODEM_RESTORE: 1;
        uint16_t AON_REG_LOP_PON_DP_MODEM_RESTORE: 1;
        uint16_t AON_REG_LOP_PON_BZ_RESTORE: 1;

        /* lop_pon_rg7x */
        uint16_t AON_REG_LOP_PON_RG7X_DUMMY1: 8;
        uint16_t AON_REG_LOP_PON_BT_CORE_RSTB: 1;
        uint16_t AON_REG_LOP_PON_BT_PON_RSTB: 1;
        uint16_t AON_REG_LOP_PON_ISO_BT_PON: 1;
        uint16_t AON_REG_LOP_PON_ISO_BT_CORE: 1;
        uint16_t AON_REG_LOP_PON_ISO_PLL2: 1;
        uint16_t AON_REG_LOP_PON_ISO_PLL: 1;
        uint16_t AON_REG_LOP_PON_BT_PLL3_pow_pll: 1;
        uint16_t AON_REG_LOP_PON_BT_PLL2_pow_pll: 1;

        /* lop_pon_rg8x */
        uint16_t AON_REG_LOP_PON_ISO_BT_CORE2: 1;
        uint16_t AON_REG_LOP_PON_VCORE_PC_POW_VCORE2_PC_VG2: 1;
        uint16_t AON_REG_LOP_PON_VCORE_PC_POW_VCORE2_PC_VG1: 1;
        uint16_t AON_REG_LOP_PON_BT_PLL3_CKO3_en: 1;
        uint16_t AON_REG_LOP_PON_BT_PLL2_CKO2_en: 1;
        uint16_t AON_REG_LOP_PON_BT_PLL1_CK_BTADC_en: 1;
        uint16_t AON_REG_LOP_PON_BT_PLL1_CK_BTDAC_en: 1;
        uint16_t AON_REG_LOP_PON_BT_PLL1_CK_BTADC_APR_en: 1;
        uint16_t AON_REG_LOP_PON_BT_PLL1_CK_BTDAC_APR_en: 1;
        uint16_t AON_REG_LOP_PON_BT_PLL1_CKO1_en: 1;
        uint16_t AON_REG_LOP_PON_ZB_RESTORE: 1;
        uint16_t AON_REG_LOP_PON_LDOSYS_ENB_DL_VCORELDOLQ: 1;
        uint16_t AON_REG_LOP_PON_LDOAUX2_533HQ_EN_VOUT_DISCHG: 1;
        uint16_t AON_REG_LOP_PON_VDDIO_FLASH_EN_VOUT_DISCHG: 1;
        uint16_t AON_REG_LOP_PON_LDOAUX1_533HQ_EN_VOUT_DISCHG: 1;
        uint16_t AON_REG_LOP_PON_LDOSYS_533HQ_EN_VOUT_DISCHG: 1;

        /* lop_pon_rg9x */
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY0: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY1: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY2: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY3: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY4: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY5: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY6: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY7: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY8: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY9: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY10: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY11: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY12: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY13: 1;
        uint16_t AON_REG_LOP_PON_RG9X_DUMMY14: 1;
        uint16_t AON_REG_LOP_PON_BT_CORE2_RSTB: 1;

        /* lop_pon_delay_rg0x */
        uint16_t LOP_PON_M1M2_DELAY: 8;
        uint16_t LOP_PON_BIAS_DELAY: 8;

        /* lop_pon_delay_rg1x */
        uint16_t LOP_PON_LDOHQ_DELAY: 8;
        uint16_t LOP_PON_SYS_DELAY: 8;

        /* lop_pon_delay_rg2x */
        uint16_t LOP_PON_SWR_DELAY: 8;
        uint16_t LOP_PON_SWR_BIAS_DELAY: 8;

        /* lop_pon_delay_rg3x */
        uint16_t LOP_PON_VCORE2_DELAY: 8;
        uint16_t LOP_PON_VCORE1_DELAY: 8;

        /* lop_pon_delay_rg4x */
        uint16_t LOP_PON_RST_DELAY: 8;
        uint16_t LOP_PON_RESTORE_DELAY: 8;

        /* lop_pon_delay_rg5x */
        uint16_t LOP_PON_PLL_DELAY: 8;
        uint16_t LOP_PON_XTAL_DELAY: 8;

        /* lop_pon_delay_rg6x */
        uint16_t AON_REG_LOP_PON_DELAY_RG4X_DUMMY0: 8;
        uint16_t LOP_PON_ISO_DELAY: 8;
    };
} AON_LOP_PON;

typedef union
{
    struct
    {
        AON_FAST_AON_REG_LOP_POF_RG0X_TYPE lop_pof_rg0x;
        AON_FAST_AON_REG_LOP_POF_RG1X_TYPE lop_pof_rg1x;
        AON_FAST_AON_REG_LOP_POF_RG2X_TYPE lop_pof_rg2x;
        AON_FAST_AON_REG_LOP_POF_RG3X_TYPE lop_pof_rg3x;
        AON_FAST_AON_REG_LOP_POF_RG4X_TYPE lop_pof_rg4x;
        AON_FAST_AON_REG_LOP_POF_RG5X_TYPE lop_pof_rg5x;
        AON_FAST_AON_REG_LOP_POF_RG6X_TYPE lop_pof_rg6x;
        AON_FAST_AON_REG_LOP_POF_RG7X_TYPE lop_pof_rg7x;
        AON_FAST_AON_REG_LOP_POF_RG8X_TYPE lop_pof_rg8x;
        AON_FAST_AON_REG_LOP_POF_RG9X_TYPE lop_pof_rg9x;

        AON_FAST_AON_REG_LOP_POF_DELAY_RG0X_TYPE lop_pof_delay_rg0x;
        AON_FAST_AON_REG_LOP_POF_DELAY_RG1X_TYPE lop_pof_delay_rg1x;
        AON_FAST_AON_REG_LOP_POF_DELAY_RG2X_TYPE lop_pof_delay_rg2x;
        AON_FAST_AON_REG_LOP_POF_DELAY_RG3X_TYPE lop_pof_delay_rg3x;
        AON_FAST_AON_REG_LOP_POF_DELAY_RG4X_TYPE lop_pof_delay_rg4x;
        AON_FAST_AON_REG_LOP_POF_DELAY_RG5X_TYPE lop_pof_delay_rg5x;

        AON_FAST_AON_REG_LOP_POF_MISC_TYPE lop_pof_misc;
    };

    struct
    {
        /* lop_pof_rg0x */
        uint16_t AON_REG_LOP_POF_CHG_POW_M1: 1;
        uint16_t AON_REG_LOP_POF_CHG_POW_M2_DVDET: 1;
        uint16_t AON_REG_LOP_POF_CHG_POW_M1_DVDET: 1;
        uint16_t AON_REG_LOP_POF_CHG_EN_M1FON_LDO733: 1;
        uint16_t AON_REG_LOP_POF_CHG_EN_M2FONBUF: 1;
        uint16_t AON_REG_LOP_POF_CHG_EN_M2FON1K: 1;
        uint16_t AON_REG_LOP_POF_POW32K_32KXTAL: 1;
        uint16_t AON_REG_LOP_POF_POW32K_32KOSC: 1;
        uint16_t AON_REG_LOP_POF_MBIAS_POW_VAUDIO_DET: 1;
        uint16_t AON_REG_LOP_POF_MBIAS_POW_VDDCORE_DET: 1;
        uint16_t AON_REG_LOP_POF_MBIAS_POW_VAUX_DET: 1;
        uint16_t AON_REG_LOP_POF_MBIAS_POW_HV_DET: 1;
        uint16_t AON_REG_LOP_POF_MBIAS_POW_VBAT_DET: 1;
        uint16_t AON_REG_LOP_POF_MBIAS_POW_ADP_DET: 1;
        uint16_t AON_REG_LOP_POF_MBIAS_POW_BIAS_500nA: 1;
        uint16_t AON_REG_LOP_POF_MBIAS_POW_BIAS: 1;

        /* lop_pof_rg1x */
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_SAW_IB: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_IMIR: 1;
        uint16_t AON_REG_LOP_POF_LDOAUX1_POW_LDO533HQ: 1;
        uint16_t AON_REG_LOP_POF_LDOAUX1_EN_POS: 1;
        uint16_t AON_REG_LOP_POF_LDOSYS_POW_HQLQ533_PC: 1;
        uint16_t AON_REG_LOP_POF_LDOSYS_POW_HQLQVCORE533_PC: 1;
        uint16_t AON_REG_LOP_POF_LDOAUX1_POS_RST_B: 1;
        uint16_t AON_REG_LOP_POF_LDOAUX1_POW_VREF: 1;
        uint16_t AON_REG_LOP_POF_LDOSYS_POW_LDO533HQ: 1;
        uint16_t AON_REG_LOP_POF_LDOSYS_EN_POS: 1;
        uint16_t AON_REG_LOP_POF_LDOSYS_POW_LDO733LQ_VCORE: 1;
        uint16_t AON_REG_LOP_POF_CHG_SEL_M2CCDFB: 2;
        uint16_t AON_REG_LOP_POF_LDOSYS_POS_RST_B: 1;
        uint16_t AON_REG_LOP_POF_LDOSYS_POW_LDOVREF: 1;
        uint16_t AON_REG_LOP_POF_CHG_POW_M2: 1;

        /* lop_pof_rg2x */
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_ZCD_COMP_LOWIQ: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_TUNE_BNYCNT_INI: 6;
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_BNYCNT_1: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_FPWM_1: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_OCP: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_ZCD: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_PFM: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_PWM: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_VDIV: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_REF: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_SAW: 1;

        /* lop_pof_rg3x */
        uint16_t AON_REG_LOP_POF_RG3X_DUMMY1: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_BNYCNT_2: 1;
        uint16_t AON_REG_LOP_POF_LDO_DIG_POW_LDODIG: 1;
        uint16_t AON_REG_LOP_POF_LDO_DIG_EN_POS: 1;
        uint16_t AON_REG_LOP_POF_LDO_DIG_EN_LDODIG_PC: 1;
        uint16_t AON_REG_LOP_POF_XTAL_LPS_CAP_STEP: 2;
        uint16_t AON_REG_LOP_POF_XTAL_LPS_CAP_CYC: 2;
        uint16_t AON_REG_LOP_POF_LDO_DIG_POS_RST_B: 1;
        uint16_t AON_REG_LOP_POF_LDO_DIG_TUNE_LDODIG_VOUT: 5;
        uint16_t AON_REG_LOP_POF_LDO_DIG_POW_LDODIG_VREF: 1;

        /* lop_pof_rg4x */
        uint16_t AON_REG_LOP_POF_RG4X_DUMMY1: 4;
        uint16_t AON_REG_LOP_POF_SWR_CORE_TUNE_POS_VREFPFM: 8;
        uint16_t AON_REG_LOP_POF_SWR_CORE_TUNE_REF_VREFLPPFM: 4;

        /* lop_pof_rg5x */
        uint16_t AON_REG_LOP_POF_BT_RET_RSTB: 1;
        uint16_t AON_REG_LOP_POF_VCORE_PC_POW_VCORE_PC_VG2: 1;
        uint16_t AON_REG_LOP_POF_VCORE_PC_POW_VCORE_PC_VG1: 1;
        uint16_t AON_REG_LOP_POF_LDO_DIG_POW_LDORET: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_SWR: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_POW_LDO: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_SEL_POS_VREFLPPFM: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_FPWM_2: 1;
        uint16_t AON_REG_LOP_POF_SWR_CORE_TUNE_VDIV: 8;

        /* lop_pof_rg6x */
        uint16_t AON_REG_LOP_POF_ISO_BT_PON: 1;
        uint16_t AON_REG_LOP_POF_ISO_BT_CORE: 1;
        uint16_t AON_REG_LOP_POF_ISO_PLL2: 1;
        uint16_t AON_REG_LOP_POF_ISO_PLL: 1;
        uint16_t AON_REG_LOP_POF_BT_PLL3_pow_pll: 1;
        uint16_t AON_REG_LOP_POF_BT_PLL2_pow_pll: 1;
        uint16_t AON_REG_LOP_POF_BT_PLL1_pow_pll: 1;
        uint16_t AON_REG_LOP_POF_BT_PLL_LDO_pow_LDO: 1;
        uint16_t AON_REG_LOP_POF_BT_PLL_LDO_ERC_V12A_BTPLL: 1;
        uint16_t AON_REG_LOP_POF_BT_PLL_LDO_SW_LDO2PORCUT: 1;
        uint16_t AON_REG_LOP_POF_ISO_XTAL: 1;
        uint16_t AON_REG_LOP_POF_OSC40M_POW_OSC: 1;
        uint16_t AON_REG_LOP_POF_XTAL_MODE: 3;
        uint16_t AON_REG_LOP_POF_XTAL_POW_XTAL: 1;

        /* lop_pof_rg7x */
        uint16_t AON_REG_LOP_POF_RG7X_DUMMY1: 8;
        uint16_t AON_REG_LOP_POF_RFC_STORE: 1;
        uint16_t AON_REG_LOP_POF_PF_STORE: 1;
        uint16_t AON_REG_LOP_POF_MODEM_STORE: 1;
        uint16_t AON_REG_LOP_POF_DP_MODEM_STORE: 1;
        uint16_t AON_REG_LOP_POF_BZ_STORE: 1;
        uint16_t AON_REG_LOP_POF_BLE_STORE: 1;
        uint16_t AON_REG_LOP_POF_BT_CORE_RSTB: 1;
        uint16_t AON_REG_LOP_POF_BT_PON_RSTB: 1;

        /* lop_pof_rg8x */
        uint16_t AON_REG_LOP_POF_ISO_BT_CORE2: 1;
        uint16_t AON_REG_LOP_POF_VCORE_PC_POW_VCORE2_PC_VG2: 1;
        uint16_t AON_REG_LOP_POF_VCORE_PC_POW_VCORE2_PC_VG1: 1;
        uint16_t AON_REG_LOP_POF_BT_PLL3_CKO3_en: 1;
        uint16_t AON_REG_LOP_POF_BT_PLL2_CKO2_en: 1;
        uint16_t AON_REG_LOP_POF_BT_PLL1_CK_BTADC_en: 1;
        uint16_t AON_REG_LOP_POF_BT_PLL1_CK_BTDAC_en: 1;
        uint16_t AON_REG_LOP_POF_BT_PLL1_CK_BTADC_APR_en: 1;
        uint16_t AON_REG_LOP_POF_BT_PLL1_CK_BTDAC_APR_en: 1;
        uint16_t AON_REG_LOP_POF_BT_PLL1_CKO1_en: 1;
        uint16_t AON_REG_LOP_POF_ZB_STORE: 1;
        uint16_t AON_REG_LOP_POF_LDOSYS_ENB_DL_VCORELDOLQ: 1;
        uint16_t AON_REG_LOP_POF_LDOAUX2_533HQ_EN_VOUT_DISCHG: 1;
        uint16_t AON_REG_LOP_POF_VDDIO_FLASH_EN_VOUT_DISCHG: 1;
        uint16_t AON_REG_LOP_POF_LDOAUX1_533HQ_EN_VOUT_DISCHG: 1;
        uint16_t AON_REG_LOP_POF_LDOSYS_533HQ_EN_VOUT_DISCHG: 1;

        /* lop_pof_rg9x */
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY0: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY1: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY2: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY3: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY4: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY5: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY6: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY7: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY8: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY9: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY10: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY11: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY12: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY13: 1;
        uint16_t AON_REG_LOP_POF_RG9X_DUMMY14: 1;
        uint16_t AON_REG_LOP_POF_BT_CORE2_RSTB: 1;

        /* lop_pof_delay_rg0x */
        uint16_t LOP_POF_M1M2_DELAY: 8;
        uint16_t LOP_POF_BIAS_DELAY: 8;

        /* lop_pof_delay_rg1x */
        uint16_t LOP_POF_SWR_BIAS_DELAY: 8;
        uint16_t LOP_POF_LDOHQ_DELAY: 8;

        /* lop_pof_delay_rg2x */
        uint16_t LOP_POF_VCORE_DELAY: 8;
        uint16_t LOP_POF_SWR_DELAY: 8;

        /* lop_pof_delay_rg3x */
        uint16_t LOP_POF_RST_DELAY: 8;
        uint16_t LOP_POF_STORE_DELAY: 8;

        /* lop_pof_delay_rg4x */
        uint16_t LOP_POF_PLL_DELAY: 8;
        uint16_t LOP_POF_XTAL_DELAY: 8;

        /* lop_pof_delay_rg5x */
        uint16_t AON_REG_LOP_POF_DELAY_RG5X_DUMMY0: 8;
        uint16_t LOP_POF_ISO_DELAY: 8;

        /* lop_pof_misc */
        uint16_t LOP_POF_MISC_DUMMY1: 15;
        uint16_t LOP_POF_AON_GATED_EN: 1;
    };
} AON_LOP_POF;

typedef struct
{
    AON_LOP_PON pon[PLATFORM_POWER_MODE_MAX];
    AON_LOP_POF pof[PLATFORM_POWER_MODE_MAX];
} AONLOPTable;

typedef enum PMUFlowType
{
    PMU_FLOW_POWER_ON                 = 0,
    PMU_FLOW_POWER_OFF                = 1,
    PMU_FLOW_DEF_MAX,
} PMUFlowType;

/** @} */ /* End of group PMU_MANAGER_Exported_Types */

/*============================================================================*
 *                              Variables
 *============================================================================*/
/** @defgroup PMU_MANAGER_Exported_Variables PMU Manager Exported Variables
  * @{
  */

extern PMU_CFG pmu_cfg;
extern AONLOPTable lop_table;

extern void (*ft_paras_apply)(void);

extern void (*auto_switch_table_init)(void);
extern void (*auto_switch_table_enable)(bool);
extern void (*force_auto_switch_table_tx_mode)(bool);

extern void (*si_flow_data_init)(void);
extern void (*si_flow_before_power_on_sequence_restart)(void);
extern void (*si_flow_after_power_on_sequence_restart)(void);
extern void (*si_flow_before_enter_low_power_mode)(void);
extern void (*si_flow_after_exit_low_power_mode)(void);

extern void (*set_40m_clk_src_to_lop_table)(PlatformPowerMode);
extern void (*set_32k_clk_src_to_lop_table)(PlatformPowerMode);
extern void (*lop_pof_setting)(PlatformPowerMode);
extern void (*lop_pon_setting)(PlatformPowerMode);
extern void (*lop_setting)(PlatformPowerMode);

extern void (*set_io_power_in_lps_mode)(bool);
extern void (*set_clk_32k_power_in_powerdown)(bool);

extern void (*pmu_set_vddio_add_bias_power_domain)(VDDIO_TYPE, LDO_POWER_DOMAIN_TYPE);

extern void (*pmu_handle_m1_disbias)(bool);
extern void (*pmu_handle_adp_dummy_load)(bool);

extern void (*pmu_handle_ldo_311)(bool);
extern void (*pmu_handle_ldo_311_aux_lq)(bool, bool);
extern void (*pmu_handle_ldo_318)(bool);
extern void (*pmu_handle_ldo_pa)(bool);
extern void (*pmu_handle_ldo_sys_lq)(bool, bool);
extern void (*pmu_handle_ldo_aux1_lq_add_bias)(bool);
extern void (*pmu_handle_ldo_aux1_lq)(bool, bool, bool);
extern void (*pmu_handle_ldo_aux2_hq)(bool);
extern void (*pmu_handle_ldo_aux2_lq_add_bias)(bool);
extern void (*pmu_handle_ldo_aux2_lq)(bool, bool, bool);
extern void (*pmu_handle_ldo_audio_lq)(bool, bool);
extern void (*pmu_handle_vddcore)(bool, bool);
extern void (*pmu_handle_swr_core_pfm_pof)(PlatformPowerMode);
extern void (*pmu_handle_avcc_drv_change_mode)(SWR_CORE_AUDIO_TYPE);
extern void (*pmu_handle_avcc_drv_dummy_load_imp)(AVCC_DRV_POWER_TYPE, bool);
extern void (*pmu_handle_avcc_drv_imp)(bool);
extern void (*pmu_handle_ldo_avcc)(bool);
extern void (*pmu_handle_dummy_load)(void);
extern void (*pmu_apply_voltage_tune)(void);

extern uint32_t (*pmu_estimate_delay)(PMUFlowType, PlatformPowerMode);
extern void (*pmu_active_ctrl)(void);
extern void (*pmu_lpm_ctrl)(PlatformPowerMode);
extern void (*pmu_power_on_sequence)(void);
extern void (*pmu_power_off_sequence)(void);
extern void (*pmu_power_on_sequence_restart)(void);

/** @} */ /* End of group PMU_MANAGER_Exported_Variables */

/*============================================================================*
 *                              Functions
 *============================================================================*/
/** @defgroup PMU_MANAGER_Exported_Functions PMU Manager Exported Functions
  * @{
  */

LDO_POWER_DOMAIN_TYPE pmu_get_vcore_power_domain(VCORE_TYPE vcore_type);
void pmu_set_vcore_power_domain(VCORE_TYPE vcore_type, LDO_POWER_DOMAIN_TYPE power_domain);

void pmu_handle_swr_audio_short_protection(SWR_MODE_TYPE mode);
void pmu_handle_avcc_drv_dummy_load(AVCC_DRV_POWER_TYPE power_type, bool enable);
void pmu_handle_avcc_drv(bool en_avcc_drv);

/** @} */ /* End of group PMU_MANAGER_Exported_Functions */

#ifdef __cplusplus
}
#endif

#endif  /* __PMU_MANAGER_H */

