/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     rtl_tim_int.c
* @brief    This file provides all the TIMER firmware internal functions.
* @details
* @author   Bert
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

    if ((TIMx >= TIMB_0) && (TIMx <= TIMB_3))
    {
        timerid = ((tempreg - TIMER_B_REG_BASE) / 20);
    }
    else if ((TIMx >= TIMC_0) && (TIMx <= TIMC_5))
    {
        timerid = ((tempreg - TIMER_C_REG_BASE) / 20);
    }

    return timerid;
}

void TIM_SetHighLoadCount(TIM_TypeDef *TIMx, uint32_t TIM_PWM_High_Count)
{
    uint32_t timerid = TIM_GetTimerID(TIMx);

    *(&TIMERB_CH0_LOAD_COUNT2 + timerid) = TIM_TimeBaseInitStruct->TIM_PWM_High_Count;
}

void TIM_PWMDeadzoneConfig(TIM_TypeDef *TIMx,
                           uint8_t PWM_Deazone_ClockSrc, uint8_t PWM_Deadzone_DIV,
                           uint8_t PWMDeadZone_En, uint32_t PWM_Deazone_Size,
                           uint8_t PWM_Stop_State_P, uint8_t PWM_Stop_State_N)
{
    uint32_t timerid = TIM_GetTimerID(TIMx);

    /* Set Pwm Deadzone Mode */
    if (PWMDeadZone_En == ENABLE)
    {
        if (timerid  == 0)
        {
            /* Config Pwm Deadzone Clock */
            PERIBLKCTRL_PERI_CLK->u_160.BITS_160.r_timerb_pwm_wrap1_func_en = 0x1;
            PERIBLKCTRL_PERI_CLK->u_160.BITS_160.r_timerb_pwm_wrap1_ck_en = 0x1;
            PERIBLKCTRL_PERI_CLK->u_160.BITS_160.r_timerb_pwm_wrap1_clk_sel = PWM_Deazone_ClockSrc;
            if ((PWM_Deadzone_DIV != DISABLE))
            {
                PERIBLKCTRL_PERI_CLK->u_160.BITS_160.r_timerb_pwm_wrap1_div_en = 0x1;
                PERIBLKCTRL_PERI_CLK->u_160.BITS_160.r_timerb_pwm_wrap1_div_sel = PWM_Deadzone_DIV;
            }
            else
            {
                PERIBLKCTRL_PERI_CLK->u_160.BITS_160.r_timerb_pwm_wrap1_div_en = 0x0;
            }

            /* Set Pwm Deadzone Time */
            TIMER_B_PWM_WRAP_CFG_t tim_pwm_0x260 = {.d32 = PWMB_0->TIMER_B_PWM_WRAP_CFG};
            tim_pwm_0x260.b.timer_b_pwm_dead_zone_size = PWM_Deazone_Size;
            tim_pwm_0x260.b.timer_b_pwm_stop_state_0 = PWM_Stop_State_N;
            tim_pwm_0x260.b.timer_b_pwm_stop_state_1 = PWM_Stop_State_P;
            tim_pwm_0x260.b.timer_b_pwm_dead_zone_en = PWMDeadZone_En;
            PWMB_0->TIMER_B_PWM_WRAP_CFG = tim_pwm_0x260.d32;
        }
        else if (timerid == 1)
        {
            /* Config Pwm Deadzone Clock */
            PERIBLKCTRL_PERI_CLK->u_164.BITS_164.r_timerb_pwm_wrap2_func_en = 0x1;
            PERIBLKCTRL_PERI_CLK->u_164.BITS_164.r_timerb_pwm_wrap2_ck_en = 0x1;
            PERIBLKCTRL_PERI_CLK->u_164.BITS_164.r_timerb_pwm_wrap2_clk_sel = PWM_Deazone_ClockSrc;
            if ((PWM_Deadzone_DIV != DISABLE))
            {
                PERIBLKCTRL_PERI_CLK->u_164.BITS_164.r_timerb_pwm_wrap2_div_en = 0x1;
                PERIBLKCTRL_PERI_CLK->u_164.BITS_164.r_timerb_pwm_wrap2_div_sel = PWM_Deadzone_DIV;
            }
            else
            {
                PERIBLKCTRL_PERI_CLK->u_164.BITS_164.r_timerb_pwm_wrap2_div_en = 0x0;
            }

            /* Set Pwm Deadzone Time */
            TIMER_B_PWM_WRAP_CFG_t tim_pwm_0x264 = {.d32 = PWMB_1->TIMER_B_PWM_WRAP_CFG};
            tim_pwm_0x264.b.timer_b_pwm_dead_zone_size = PWM_Deazone_Size;
            tim_pwm_0x264.b.timer_b_pwm_stop_state_0 = PWM_Stop_State_N;
            tim_pwm_0x264.b.timer_b_pwm_stop_state_1 = PWM_Stop_State_P;
            tim_pwm_0x264.b.timer_b_pwm_dead_zone_en = PWMDeadZone_En;
            PWMB_1->TIMER_B_PWM_WRAP_CFG = tim_pwm_0x264.d32;
        }
        else if (timerid == 2)
        {
            /* Config Pwm Deadzone Clock */
            PERIBLKCTRL_PERI_CLK->u_168.BITS_168.r_timerb_pwm_wrap3_func_en = 0x1;
            PERIBLKCTRL_PERI_CLK->u_168.BITS_168.r_timerb_pwm_wrap3_ck_en = 0x1;
            PERIBLKCTRL_PERI_CLK->u_168.BITS_168.r_timerb_pwm_wrap3_clk_sel = PWM_Deazone_ClockSrc;
            if ((PWM_Deadzone_DIV != DISABLE))
            {
                PERIBLKCTRL_PERI_CLK->u_168.BITS_168.r_timerb_pwm_wrap3_div_en = 0x1;
                PERIBLKCTRL_PERI_CLK->u_168.BITS_168.r_timerb_pwm_wrap3_div_sel = PWM_Deadzone_DIV;
            }
            else
            {
                PERIBLKCTRL_PERI_CLK->u_168.BITS_168.r_timerb_pwm_wrap3_div_en = 0x0;
            }

            /* Set Pwm Deadzone Time */
            TIMER_B_PWM_WRAP_CFG_t tim_pwm_0x268 = {.d32 = PWMB_2->TIMER_B_PWM_WRAP_CFG};
            tim_pwm_0x268.b.timer_b_pwm_dead_zone_size = PWM_Deazone_Size;
            tim_pwm_0x268.b.timer_b_pwm_stop_state_0 = PWM_Stop_State_N;
            tim_pwm_0x268.b.timer_b_pwm_stop_state_1 = PWM_Stop_State_P;
            tim_pwm_0x268.b.timer_b_pwm_dead_zone_en = PWMDeadZone_En;
            PWMB_2->TIMER_B_PWM_WRAP_CFG = tim_pwm_0x268.d32;
        }
        else if (timerid == 3)
        {
            /* Config Pwm Deadzone Clock */
            PERIBLKCTRL_PERI_CLK->u_16C.BITS_16C.r_timerb_pwm_wrap4_func_en = 0x1;
            PERIBLKCTRL_PERI_CLK->u_16C.BITS_16C.r_timerb_pwm_wrap4_ck_en = 0x1;
            PERIBLKCTRL_PERI_CLK->u_16C.BITS_16C.r_timerb_pwm_wrap4_clk_sel = PWM_Deazone_ClockSrc;
            if ((PWM_Deadzone_DIV != DISABLE))
            {
                PERIBLKCTRL_PERI_CLK->u_16C.BITS_16C.r_timerb_pwm_wrap4_div_en = 0x1;
                PERIBLKCTRL_PERI_CLK->u_16C.BITS_16C.r_timerb_pwm_wrap4_div_sel = PWM_Deadzone_DIV;
            }
            else
            {
                PERIBLKCTRL_PERI_CLK->u_16C.BITS_16C.r_timerb_pwm_wrap4_div_en = 0x0;
            }

            /* Set Pwm Deadzone Time */
            TIMER_B_PWM_WRAP_CFG_t tim_pwm_0x26C = {.d32 = PWMB_3->TIMER_B_PWM_WRAP_CFG};
            tim_pwm_0x26C.b.timer_b_pwm_dead_zone_size = PWM_Deazone_Size;
            tim_pwm_0x26C.b.timer_b_pwm_stop_state_0 = PWM_Stop_State_N;
            tim_pwm_0x26C.b.timer_b_pwm_stop_state_1 = PWM_Stop_State_P;
            tim_pwm_0x26C.b.timer_b_pwm_dead_zone_en = PWMDeadZone_En;
            PWMB_3->TIMER_B_PWM_WRAP_CFG = tim_pwm_0x26C.d32;
        }
    }
    else
    {
        if (timerid == 0)
        {
            /* Config Pwm Deadzone Clock */
            PERIBLKCTRL_PERI_CLK->u_160.BITS_160.r_timerb_pwm_wrap1_func_en = 0x0;
            PERIBLKCTRL_PERI_CLK->u_160.BITS_160.r_timerb_pwm_wrap1_ck_en = 0x0;

            /* Disable Pwm Deadzone Mode */
            TIMER_B_PWM_WRAP_CFG_t tim_pwm_0x260 = {.d32 = PWMB_0->TIMER_B_PWM_WRAP_CFG};
            tim_pwm_0x260.b.timer_b_pwm_dead_zone_en = 0x0;
            PWMB_0->TIMER_B_PWM_WRAP_CFG = tim_pwm_0x260.d32;
        }
        else if (timerid == 1)
        {
            /* Config Pwm Deadzone Clock */
            PERIBLKCTRL_PERI_CLK->u_164.BITS_164.r_timerb_pwm_wrap2_func_en = 0x0;
            PERIBLKCTRL_PERI_CLK->u_164.BITS_164.r_timerb_pwm_wrap2_ck_en = 0x0;

            /* Disable Pwm Deadzone Mode */
            TIMER_B_PWM_WRAP_CFG_t tim_pwm_0x264 = {.d32 = PWMB_1->TIMER_B_PWM_WRAP_CFG};
            tim_pwm_0x264.b.timer_b_pwm_dead_zone_en = 0x0;
            PWMB_1->TIMER_B_PWM_WRAP_CFG = tim_pwm_0x264.d32;
        }
        else if (timerid == 2)
        {
            /* Config Pwm Deadzone Clock */
            PERIBLKCTRL_PERI_CLK->u_168.BITS_168.r_timerb_pwm_wrap3_func_en = 0x0;
            PERIBLKCTRL_PERI_CLK->u_168.BITS_168.r_timerb_pwm_wrap3_ck_en = 0x0;

            /* Disable Pwm Deadzone Mode */
            TIMER_B_PWM_WRAP_CFG_t tim_pwm_0x268 = {.d32 = PWMB_2->TIMER_B_PWM_WRAP_CFG};
            tim_pwm_0x268.b.timer_b_pwm_dead_zone_en = 0x0;
            PWMB_2->TIMER_B_PWM_WRAP_CFG = tim_pwm_0x268.d32;
        }
        else if (timerid == 3)
        {
            /* Config Pwm Deadzone Clock */
            PERIBLKCTRL_PERI_CLK->u_16C.BITS_16C.r_timerb_pwm_wrap4_func_en = 0x0;
            PERIBLKCTRL_PERI_CLK->u_16C.BITS_16C.r_timerb_pwm_wrap4_ck_en = 0x0;

            /* Disable Pwm Deadzone Mode */
            TIMER_B_PWM_WRAP_CFG_t tim_pwm_0x26C = {.d32 = PWMB_3->TIMER_B_PWM_WRAP_CFG};
            tim_pwm_0x26C.b.timer_b_pwm_dead_zone_en = 0x0;
            PWMB_3->TIMER_B_PWM_WRAP_CFG = tim_pwm_0x26C.d32;
        }
    }
}

/**
 * @brief  PWM complementary output emergency stop.
 *         PWM_P emergency stop level state is configured by PWM_Stop_State_P,
 *         PWM_N emergency stop level state is configured by PWM_Stop_State_N.
 * @param  PWMx: Select the PWMx peripheral  .
 * @param  NewState: New state of complementary output.
 *         @arg DISABLE: Resume PWM complementary output.
 *         @arg ENABLE: PWM complementary output emergency stop.
 * @return None.
 * @note   To use this function, need to configure the corresponding timer.
 *         PWMB_0 ->> TIMB_0, PWMB_1 ->> TIMB_1, PWMB_2 ->> TIMB_2, PWMB_3 ->> TIMB_3.
 */
void TIM_PWMComplOutputEMCmd(PWM_TypeDef *PWMx, FunctionalState NewState)
{
    /* Check the parameters. */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    TIMER_B_PWM_WRAP_CFG_t tim_pwm_wrap = {.d32 = PWMx->TIMER_B_PWM_WRAP_CFG};
    tim_pwm_wrap.b.timer_b_pwm_emg_stop = NewState;
    PWMx->TIMER_B_PWM_WRAP_CFG = tim_pwm_wrap.d32;
}

/**
 * @brief  Enable or disable bypass dead zone function of PWM complementary output.
 *         After enabling, PWM_P = ~PWM_N.
 * @param  PWMx: Select the PWMx peripheral  .
 * @param  NewState: New state of the PWMx peripheral.
 *         @arg DISABLE: Disable bypass dead zone function.
 *         @arg ENABLE: Enable bypass dead zone function.
 * @return None.
 * @note   To use this function, need to configure the corresponding timer.
 *         PWMB_0 ->> TIMB_0, PWMB_1 ->> TIMB_1, PWMB_2 ->> TIMB_2, PWMB_3 ->> TIMB_3.
 */
void TIM_PWMDZBypassCmd(PWM_TypeDef *PWMx, FunctionalState NewState)
{
    /* Check the parameters. */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    TIMER_B_PWM_WRAP_CFG_t tim_pwm_wrap = {.d32 = PWMx->TIMER_B_PWM_WRAP_CFG};
    tim_pwm_wrap.b.timer_b_pwm_pwm_pn_invserse_sel = NewState;
    PWMx->TIMER_B_PWM_WRAP_CFG = tim_pwm_wrap.d32;
}

/**
 * @brief  Change the PWM dead zone clock source.
 * @param  PWMx: Where x can be B_0 to B_3 to select the PWMx peripheral.
 * @param  PWM_Deazone_ClockSrc: New state of the PWMx peripheral.
 *         @arg PWM_CK_5M_TIMER: Use 5M clock source.
 *         @arg PWM_CK_32K_TIMER: Use 32k clock source.
 * @return None.
 * @note   To use this function, need to configure the corresponding timer.
 *         PWMB_0 ->> TIMB_0, PWMB_1 ->> TIMB_1, PWMB_2 ->> TIMB_2, PWMB_3 ->> TIMB_3.
 */
void TIM_PWMChangeDZClockSrc(PWM_TypeDef *PWMx, PWMDZClockSrc_TypeDef PWM_Deazone_ClockSrc)
{
    /* Check the parameters. */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    uint8_t tempreg = (uint32_t)PWMx;
    uint8_t pwmid = ((tempreg - TIMER_B_PWM_CR_REG_BASE) / 4);

    /* clk_32k_timer*/
    if (pwmid == 0)
    {
        PERIBLKCTRL_PERI_CLK->u_160.BITS_160.r_timerb_pwm_wrap1_clk_sel = PWM_Deazone_ClockSrc;
    }
    else if (pwmid == 1)
    {
        PERIBLKCTRL_PERI_CLK->u_164.BITS_164.r_timerb_pwm_wrap2_clk_sel = PWM_Deazone_ClockSrc;
    }
    else if (pwmid == 2)
    {
        PERIBLKCTRL_PERI_CLK->u_168.BITS_168.r_timerb_pwm_wrap3_clk_sel = PWM_Deazone_ClockSrc;
    }
    else if (pwmid == 3)
    {
        PERIBLKCTRL_PERI_CLK->u_16C.BITS_16C.r_timerb_pwm_wrap4_clk_sel = PWM_Deazone_ClockSrc;
    }
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

