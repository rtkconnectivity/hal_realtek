/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_rcc.h"
#include "rtl_tim.h"

/*============================================================================*
 *                          Private Functions
 *============================================================================*/
extern uint32_t TIM_GetTimerID(TIM_TypeDef *TIMx);

#if TIM_SUPPORT_CLOCK_DEPEND
extern void TIM_ConfigClkDepend(TIM_TypeDef *TIMx, uint8_t ClockDepend);
#endif

extern void TIM_SetHighLoadCount(TIM_TypeDef *TIMx, uint32_t TIM_PWM_High_Count);

extern void TIM_PWMDeadzoneConfig(TIM_TypeDef *TIMx,
                                  uint8_t PWM_Deazone_ClockSrc, uint8_t PWM_Deadzone_DIV,
                                  uint8_t PWMDeadZone_En, uint32_t PWM_Deazone_Size,
                                  uint8_t PWM_Stop_State_P, uint8_t PWM_Stop_State_N);

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Deinitializes the TIMx peripheral registers to their default reset values.
  * \param  TIMx: Select the TIM peripheral. \ref TIMER_Declaration
  * \return None
  */
void TIM_DeInit(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    /*enable timer IP clock and function */
#if (CHIP_TIM_NUM <= 8)
    RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, DISABLE);
#else
    else if ((TIMx == TIMB_0) || (TIMx == TIMB_1) || (TIMx == TIMB_2) || (TIMx == TIMB_3))
    {
        RCC_PeriphClockCmd(APBPeriph_TIMERB, APBPeriph_TIMERB_CLOCK, DISABLE);
    }
    else if ((TIMx == TIMC_0) || (TIMx == TIMC_1) || (TIMx == TIMC_2) || (TIMx == TIMC_3) ||
             (TIMx == TIMC_4) || (TIMx == TIMC_5))
    {
        RCC_PeriphClockCmd(APBPeriph_TIMERC, APBPeriph_TIMERC_CLOCK, DISABLE);
    }
#endif
}

/**
  * \brief  Initializes the TIMx Time Base Unit peripheral according to
  *         the specified parameters in the TIM_TimeBaseInitStruct.
  * \param  TIMx: Select the TIM peripheral. \ref TIMER_Declaration
  * \param  TIM_TimeBaseInitStruct: pointer to a TIM_TimeBaseInitTypeDef
  *         structure that contains the configuration information for the
  *         specified TIM peripheral.
  * \return None
  */
void TIM_TimeBaseInit(TIM_TypeDef *TIMx, TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_TIM_MODE(TIM_TimeBaseInitStruct->TIM_Mode));
    assert_param(IS_TIM_PWM_DeadZone_En(TIM_TimeBaseInitStruct->PWMDeadZone_En));

    RCC_TIMClkConfig(TIMx,
                     TIM_TimeBaseInitStruct->TIM_ClockSrc,
                     TIM_TimeBaseInitStruct->TIM_SOURCE_DIV);

#if TIM_SUPPORT_CLOCK_DEPEND
    TIM_ConfigClkDepend(TIMx, TIM_TimeBaseInitStruct->ClockDepend);
#endif

    /* set timer mode and mask interrupt */
    TIMER_CONTROLREG_TypeDef timer_0x08 = {.d32 = TIMx->TIMER_CONTROLREG};
    if (TIM_TimeBaseInitStruct->TIM_PWM_En == DISABLE)
    {
        timer_0x08.b.TimerMode = TIM_TimeBaseInitStruct->TIM_Mode;
        timer_0x08.b.TimerInterruptMask = 0x1;
        TIMx->TIMER_CONTROLREG = timer_0x08.d32;
        /* set timer period */
        TIMx->TIMER_LOADCOUNT = TIM_TimeBaseInitStruct->TIM_Period;
    }
    else
    {
        timer_0x08.b.TimerMode = TIM_TimeBaseInitStruct->TIM_Mode;
        timer_0x08.b.TimerInterruptMask = 0x1;
        timer_0x08.b.TIMER_PWM = 0x1;
        TIMx->TIMER_CONTROLREG = timer_0x08.d32;

        /* set pwm high count */
        TIM_SetHighLoadCount(TIMx, TIM_TimeBaseInitStruct->TIM_PWM_High_Count);
        /* set pwm low count */
        TIMx->TIMER_LOADCOUNT = TIM_TimeBaseInitStruct->TIM_PWM_Low_Count;
    }

    /* Config PWM Deadzone */
    TIM_PWMDeadzoneConfig(TIMx,
                          TIM_TimeBaseInitStruct->PWM_Deazone_ClockSrc,
                          TIM_TimeBaseInitStruct->PWM_Deadzone_DIV,
                          TIM_TimeBaseInitStruct->PWMDeadZone_En,
                          TIM_TimeBaseInitStruct->PWM_Deazone_Size,
                          TIM_TimeBaseInitStruct->PWM_Stop_State_P,
                          TIM_TimeBaseInitStruct->PWM_Stop_State_N);

    /* Clear the IT status */
    (void)TIMx->TIMER_EOI;
}

/**
  * \brief  Fills each TIM_InitStruct member with its default value.
  * \param  TIM_InitStruct : pointer to a TIM_InitTypeDef structure which will be initialized.
  * \return None
  */
void TIM_StructInit(TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct)
{
    TIM_TimeBaseInitStruct->TIM_ClockSrc = CK_40M_TIMER;
    TIM_TimeBaseInitStruct->TIM_Mode = TIM_Mode_UserDefine;
    TIM_TimeBaseInitStruct->TIM_Period = 0xfff;
#if TIM_SUPPORT_EVENT_DURATION
    TIM_TimeBaseInitStruct->TIM_EventMode = false;
    TIM_TimeBaseInitStruct->TIM_EventIndex = 1;
    TIM_TimeBaseInitStruct->TIM_EventDuration = TIM_EventDuration_64us;
#endif
    TIM_TimeBaseInitStruct->TIM_SOURCE_DIV = TIM_CLOCK_DIVIDER_1;
    TIM_TimeBaseInitStruct->TIM_SOURCE_DIV_En = DISABLE;
    TIM_TimeBaseInitStruct->TIM_PWM_En = DISABLE;
    TIM_TimeBaseInitStruct->PWM_Stop_State_P = PWM_STOP_AT_LOW;
    TIM_TimeBaseInitStruct->PWM_Stop_State_N = PWM_STOP_AT_HIGH;
    TIM_TimeBaseInitStruct->PWMDeadZone_En = DISABLE;
}

/**
  * \brief  Enables or disables the specified TIM peripheral.
  * \param  TIMx: Select the TIM peripheral. \ref TIMER_Declaration
  * \param  NewState: new state of the TIMx peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void TIM_Cmd(TIM_TypeDef *TIMx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    TIMER_CONTROLREG_TypeDef timer_0x08 = {.d32 = TIMx->TIMER_CONTROLREG};
    timer_0x08.b.TimerEnable = NewState;
    TIMx->TIMER_CONTROLREG = timer_0x08.d32;
}

/**
  * \brief  change TIM period value.
  * \param  TIMx: Select the TIM peripheral. \ref TIMER_Declaration
  * \return The new state of success or not  (SET or RESET).
  */
void TIM_ChangePeriod(TIM_TypeDef *TIMx, uint32_t period)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    TIMx->TIMER_LOADCOUNT = period;

    return;
}

/**
  * \brief  Enables or disables the specified TIMx interrupt.
  * \param  TIMx: Select the TIM peripheral. \ref TIMER_Declaration
  * \param  NewState: new state of the TIMx peripheral.
  *   This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void TIM_INTConfig(TIM_TypeDef *TIMx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    /* Enable the Interrupt sources */
    TIMER_CONTROLREG_TypeDef timer_0x08 = {.d32 = TIMx->TIMER_CONTROLREG};
    timer_0x08.b.TimerInterruptMask = !NewState;
    TIMx->TIMER_CONTROLREG = timer_0x08.d32;
}

/**
  * \brief  Change PWM freq and duty according high_cnt and low_cnt
  * \param  TIMx: Select the TIM peripheral. \ref TIMER_Declaration
  * \param  high_count: This parameter must range from 0x0000 to 0xFFFFFFFF
  * \param  low_count: This parameter must range from 0x0000 to 0xFFFFFFFF
  * \return None
  */
void TIM_PWMChangeFreqAndDuty(TIM_TypeDef *TIMx, uint32_t high_count, uint32_t low_count)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    /* Change PWM freq and duty */
    TIMx->TIMER_LOADCOUNT = low_count;
    TIM_SetHighLoadCount(TIMx, high_count);
}

/**
 * \brief   Get TIMx current value when timer is running.
 * \param   TIMx: Select the TIM peripheral. \ref TIMER_Declaration
 * \return  The counter value.
 */
uint32_t TIM_GetCurrentValue(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    return TIMx->TIMER_CURRENTVALUE;
}

/**
 * \brief   Check whether the TIM interrupt has occurred or not.
 * \param   TIMx: Select the TIM peripheral. \ref TIMER_Declaration
 * \return  The new state of the TIM_IT(SET or RESET).
 */
ITStatus TIM_GetINTStatus(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    ITStatus bitstatus = RESET;
    uint16_t itstatus = (uint16_t)TIMx->TIMER_INTSTATUS;
    if (itstatus != (uint16_t)RESET)
    {
        bitstatus = SET;
    }

    return bitstatus;
}

/**
 * \brief   Check whether the TIM is in operation or not.
 * \param   TIMx: Select the TIM peripheral. \ref TIMER_Declaration
 * \return  The new state of the timer operation status (SET or RESET).
 */
ITStatus TIM_GetOperationStatus(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    if (TIMx->TIMER_CONTROLREG & TIM_0X08_TIMERENABLE)
    {
        return SET;
    }
    else
    {
        return RESET;
    }
}

/**
 * \brief  Get TIMx elapsed value when timer is running.
 * \param  TIMx: Select the TIM peripheral. \ref TIMER_Declaration
 * \return The elapsed counter value.
 */
uint32_t TIM_GetElapsedValue(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    return (TIMx->TIMER_LOADCOUNT - TIMx->TIMER_CURRENTVALUE);
}

/**
 * \brief   Clear TIM interrupt.
 * \param   TIMx: Select the TIM peripheral. \ref TIMER_Declaration
 * \return  None.
 */
void TIM_ClearINT(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    /* Clear the IT */
    (void)TIMx->TIMER_EOI;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

