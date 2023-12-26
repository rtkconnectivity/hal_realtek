/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     rtl_enh_tim_int.c
* @brief    This file provides all the ENHTIM firmware internal functions.
* @details
* @author   Bert
* @date     2023-07-05
* @version  v1.0
*********************************************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "rtl_enh_tim.h"
#include "rtl_rcc.h"

#define PWM_EMG_STOP        BIT8

uint32_t ENHTIM_GetTimerID(ENHTIM_TypeDef *ENHTIMx)
{
    uint32_t enhtim_id = ((uint32_t)ENHTIMx - (uint32_t)ENH_TIM0) / 0x24;

    return enhtim_id;
}

ENHPWM_TypeDef *ENHTIM_GetPwmID(uint32_t enhtim_id)
{
    switch (enhtim_id)
    {
    case 0:
        return ENH_TIM0_PWM;
    case 1:
        return ENH_TIM1_PWM;
    case 2:
        return ENH_TIM2_PWM;
    case 3:
        return ENH_TIM3_PWM;
    case 4:
        return ENH_TIM4_PWM;
    case 5:
        return ENH_TIM5_PWM;
    case 6:
        return ENH_TIM6_PWM;
    case 7:
        return ENH_TIM7_PWM;
    default:
        return 0;
    }
}

/**
 * @brief  ENHTIM PWM complementary output emergency stop.
 * @param  ENHTIMx: Where x can be 0 to 3 to select the ENHTIMx peripheral.
 * @return FIFO data length.
 */
void ENHTIM_PWMDeadZoneEMStop(ENHTIM_TypeDef *ENHTIMx)
{
    uint32_t enhtim_id = ENHTIM_GetTimerID(ENHTIMx);
    ENHPWM_TypeDef *ENH_TIMx_PWM = ENHTIM_GetPwmID(enhtim_id);

    ENH_TIMx_PWM->ENHTIMER_PWM_WRAP_CFG |= PWM_EMG_STOP;
}

void ENHTIM_ConfigLatchTrigger(uint32_t enhtim_id, const ENHTIM_InitTypeDef *ENHTIM_InitStruct)
{
    uint8_t ENHTIM_LatchTriggerPad =  ENHTIM_InitStruct->ENHTIM_LatchTriggerPad;
    uint32_t temp = 0xFF;
    /* Config Latch Count0 trigger GPIO pin. */

    if ((ENHTIM_LatchTriggerPad >= P0_0) && (ENHTIM_LatchTriggerPad <= P16_7))
    {
        temp = ENHTIM_LatchTriggerPad;
    }
    else if ((ENHTIM_LatchTriggerPad >= P17_0) && (ENHTIM_LatchTriggerPad <= P19_7))
    {
        temp = ENHTIM_LatchTriggerPad - 12;
    }

    *((uint32_t *)(&(KM4_SoC_VENDOR->u_400.REG_ENHTIMER_0_LATCH_TRIG_0_CFG)) + enhtim_id) |= temp;
}

void ENHTIM_PWMDeadzoneConfig(uint32_t enhtim_id, \
                              const ENHTIM_InitTypeDef *ENHTIM_InitStruct)
{
    ENHPWM_TypeDef *ENH_TIMx_PWM = ENHTIM_GetPwmID(enhtim_id);

    uint32_t enhtim_id_odd = enhtim_id % 2;
    uint32_t enhtim_id_temp = enhtim_id / 2;
    uint8_t ENHTIM_PWMDeadZoneClockSource = ENHTIM_InitStruct->ENHTIM_PWMDeadZoneClockSource;
    uint8_t  ENHTIM_PWMDeadZone_ClockDiv = ENHTIM_InitStruct->ENHTIM_PWMDeadZone_ClockDiv;
    uint8_t ENHTIM_PWMDeadZoneEn = ENHTIM_InitStruct->ENHTIM_PWMDeadZoneEn;
    uint32_t ENHTIM_DeadZoneSize = ENHTIM_InitStruct->ENHTIM_DeadZoneSize;
    uint8_t ENHTIM_PWMStopStateP = ENHTIM_InitStruct->ENHTIM_PWMStopStateP;
    uint8_t ENHTIM_PWMStopStateN = ENHTIM_InitStruct->ENHTIM_PWMStopStateN;
    uint8_t ENHTIM_PWMDeadZone_ClockDivEn = ENHTIM_PWMDeadZone_ClockDiv == 0 ? DISABLE : ENABLE;

    /* Set pwm1 deadzone mode, pwm1_pn based on enhance timer0 */

    ENHTIMER_PWM_WRAP_CFG_t enhpwm_cfg = {.d32 = ENH_TIMx_PWM->ENHTIMER_PWM_WRAP_CFG};
    if (ENHTIM_PWMDeadZoneEn == ENABLE)
    {
        *((uint32_t *)(&(ENHTIM_CLK_CTRL)) + enhtim_id_temp) |= BIT12 << 16 * enhtim_id_odd;
        *((uint32_t *)(&(ENHTIM_CLK_CTRL)) + enhtim_id_temp) |= BIT13 << 16 * enhtim_id_odd;
        *((uint32_t *)(&(ENHTIM_CLK_CTRL)) + enhtim_id_temp) |= ((ENHTIM_PWMDeadZoneClockSource) <<
                                                                 (11 + 16 * enhtim_id_odd));

        if ((ENHTIM_PWMDeadZone_ClockDivEn != DISABLE))
        {
            *((uint32_t *)(&(ENHTIM_CLK_CTRL)) + enhtim_id_temp) |= BIT10 << 16 * enhtim_id_odd;
            *((uint32_t *)(&(ENHTIM_CLK_CTRL)) + enhtim_id_temp) &= ~(0x7 << (7 + 16 * enhtim_id_odd));
            *((uint32_t *)(&(ENHTIM_CLK_CTRL)) + enhtim_id_temp) |= ((ENHTIM_PWMDeadZone_ClockDiv) <<
                                                                     (7 + 16 * enhtim_id_odd));
        }
        else
        {
            *((uint32_t *)(&(ENHTIM_CLK_CTRL)) + enhtim_id_temp) &= ~(BIT10 << 16 * enhtim_id_odd);
        }

        /* Enable pwm1 deadzone mode. */

        enhpwm_cfg.b.enhtimer_pwm_dead_zone_en = ENABLE;
        enhpwm_cfg.b.enhtimer_pwm_stop_state_1 = ENHTIM_PWMStopStateP;
        enhpwm_cfg.b.enhtimer_pwm_stop_state_0 = ENHTIM_PWMStopStateN;
        enhpwm_cfg.b.enhtimer_pwm_dead_zone_size = ENHTIM_DeadZoneSize;
        ENH_TIMx_PWM->ENHTIMER_PWM_WRAP_CFG = enhpwm_cfg.d32;
    }
    else
    {
        *((uint32_t *)(&(ENHTIM_CLK_CTRL)) + enhtim_id_temp) &= ~(BIT12 << 16 * enhtim_id_odd);
        *((uint32_t *)(&(ENHTIM_CLK_CTRL)) + enhtim_id_temp) &= ~(BIT13 << 16 * enhtim_id_odd);

        /* Disable pwm1 deadzone mode. */

        enhpwm_cfg.b.enhtimer_pwm_dead_zone_en = DISABLE;
        ENH_TIMx_PWM->ENHTIMER_PWM_WRAP_CFG = enhpwm_cfg.d32;
    }
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

