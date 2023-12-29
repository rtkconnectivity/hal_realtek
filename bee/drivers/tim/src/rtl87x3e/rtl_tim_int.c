/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     rtl_tim_int.c
* @brief    This file provides all the TIMER firmware internal functions.
* @details
* @author
* @date     2023-07-05
* @version  v1.0
*********************************************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "rtl_tim.h"
#include "rtl_rcc.h"

uint32_t TIM_GetTimerID(TIM_TypeDef *TIMx)
{
    uint32_t timerid = 0;
    uint32_t tempreg = (uint32_t)TIMx;

    /* Select clock source which can be system clock or 40 MHz  or pll*/
    if (tempreg <= TIM7_REG_BASE)
    {
        timerid = (tempreg - TIM0_REG_BASE) / 20;
    }
    else
    {
        timerid = 8 + (tempreg - TIM8_REG_BASE) / 20;
    }

    return timerid;
}

void TIM_ConfigClkDepend(TIM_TypeDef *TIMx, uint8_t ClockDepend)
{
    uint32_t timerid = TIM_GetTimerID(TIMx);

    if (timerid == 3 || timerid == 5 || timerid == 7 || \
        timerid == 9 || timerid == 11)//depend todo 9 11
    {
        if (ClockDepend == true)
        {
            SYSBLKCTRL->u_360.REG_PERION_REG_PERI_GTIMER_CLK_SRC0 |= BIT(((timerid - 1) >> 1) - 1);
        }
        else
        {
            SYSBLKCTRL->u_360.REG_PERION_REG_PERI_GTIMER_CLK_SRC0 &= ~BIT(((timerid - 1) >> 1) - 1);
        }
    }
}

void TIM_SetHighLoadCount(TIM_TypeDef *TIMx, uint32_t TIM_PWM_High_Count)
{
    uint32_t count2_address = 0;
    uint32_t timerid = TIM_GetTimerID(TIMx);

    if (timerid < 8)
    {
        count2_address = &TIMER0_LOAD_COUNT2;
        count2_address = count2_address + timerid;
    }
    else
    {
        count2_address = &TIMER8_LOAD_COUNT2;
        count2_address = count2_address + timerid - 8;
    }
    *count2_address = TIM_PWM_High_Count;
}

void TIM_PWMDeadzoneConfig(TIM_TypeDef *TIMx,
                           uint8_t PWM_Deazone_ClockSrc, uint8_t PWM_Deadzone_DIV,
                           uint8_t PWMDeadZone_En, uint32_t PWM_Deazone_Size,
                           uint8_t PWM_Stop_State_P, uint8_t PWM_Stop_State_N)
{
    uint32_t timerid = TIM_GetTimerID(TIMx);

    /* set pwm deadzone mode, pwm0_pn based on timer2, and pwm1_pn based on timer3 */
    if (PWMDeadZone_En == ENABLE)
    {
        if (timerid  == 2)
        {
            /* set pwm deadzone time */
            TIMER_PWM2_CR = ((PWM_Deazone_Size) \
                             | (PWM_Stop_State_N << 9) \
                             | (PWM_Stop_State_P << 10) \
                             | BIT12 \
                             | ((PWM_Deazone_Size == 0) ? BIT13 : 0));
        }
        else if (timerid == 3)
        {
            /* set pwm deadzone time */
            TIMER_PWM3_CR = ((PWM_Deazone_Size) \
                             | (PWM_Stop_State_N << 9) \
                             | (PWM_Stop_State_P << 10) \
                             | BIT12 \
                             | ((PWM_Deazone_Size == 0) ? BIT13 : 0));
        }
    }
    else
    {
        if (timerid == 2)
        {
            /*disable pwm0 deadzone mode*/
            TIMER_PWM2_CR &= ~BIT(12);
        }
        else if (timerid == 3)
        {
            /*disable pwm1 deadzone mode*/
            TIMER_PWM3_CR &= ~BIT(12);
        }
    }
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

