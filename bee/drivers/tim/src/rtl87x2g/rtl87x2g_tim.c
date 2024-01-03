/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl87x2g_tim.c
* \brief    This file provides all the TIMER firmware internal functions.
* \details
* \author   Bert
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "tim/inc/rtl_tim.h"
#include "rcc/inc/rtl_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
uint32_t TIM_GetTimerID(TIM_TypeDef *TIMx)
{
    uint32_t tempreg = (uint32_t)TIMx;
    uint32_t timerid = (tempreg - TIMER_REG_BASE) / 20;

    return timerid;
}

void TIM_SetHighLoadCount(TIM_TypeDef *TIMx, uint32_t TIM_PWM_High_Count)
{
    uint32_t timerid = TIM_GetTimerID(TIMx);

    *(&TIMER0_LOAD_COUNT2 + timerid) = TIM_PWM_High_Count;
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
        if (timerid  == 2)
        {
            PWM_Deazone_ClockSrc &= 0x1;
            TIMER_PWM_CLK_CR &= ~(0X7 << 9);
            TIMER_PWM_CLK_CR |= BIT10 | BIT11 | (PWM_Deazone_ClockSrc << 9);
            /* set pwm deadzone time */
            TIMER_PWM_CR &= ~0xFF;
            TIMER_PWM_CR |= ((PWM_Deazone_Size) \
                             | (PWM_Stop_State_N << 9) \
                             | (PWM_Stop_State_P << 10) \
                             | BIT12);
        }
        else if (timerid == 3)
        {
            TIMER_PWM_CLK_CR &= ~(0X7 << 25);
            TIMER_PWM_CLK_CR |= ((BIT10 | BIT11 | (PWM_Deazone_ClockSrc << 9)) << 16);
            /* set pwm deadzone time */
            TIMER_PWM_CR &= ~(0xFF << 16);
            TIMER_PWM_CR |= (((PWM_Deazone_Size) \
                              | (PWM_Stop_State_N << 9) \
                              | (PWM_Stop_State_P << 10) \
                              | BIT12) << 16);
        }
    }
    else
    {
        if (timerid == 2)
        {
            /*disable pwm0 deadzone mode*/
            TIMER_PWM_CR &= ~(BIT12);
            TIMER_PWM_CLK_CR &= ~(0X3 << 10);
        }
        else if (timerid == 3)
        {
            /*disable pwm1 deadzone mode*/
            TIMER_PWM_CR &= ~(BIT28);
            TIMER_PWM_CLK_CR &= ~(0X3 << 26);
        }
    }
}

/**
 * \brief  PWM complementary output emergency stop.
 *         PWM_P emergency stop level state is configured by PWM_Stop_State_P,
 *         PWM_N emergency stop level state is configured by PWM_Stop_State_N.
 * \param  PWMx: Select the PWM peripheral. \ref PWM_Declaration
 * \param  NewState: New state of complementary output.
 *         \arg DISABLE: Resume PWM complementary output.
 *         \arg ENABLE: PWM complementary output emergency stop.
 * \return None.
 * \note   To use this function, need to configure the corresponding timer.
 *         PWM2 ->> TIM2, PWM3 ->> TIM3.
 */
void TIM_PWMComplOutputEMCmd(PWM_TypeDef *PWMx, FunctionalState NewState)
{
    /* Check the parameters. */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    if (NewState != DISABLE)
    {
        if (PWMx  == PWM2)
        {
            /* PWM2 complementary output emergency stop. */
            *((uint32_t *)TIMER_PWM_REG_BASE) |= BIT8;
        }
        else if (PWMx  == PWM3)
        {
            /* PWM3 complementary output emergency stop. */
            *((uint32_t *)TIMER_PWM_REG_BASE) |= BIT24;
        }
    }
    else
    {
        if (PWMx  == PWM2)
        {
            /* Resume PWM2 complementary output. */
            *((uint32_t *)TIMER_PWM_REG_BASE) &= (~BIT8);
        }
        else if (PWMx  == PWM3)
        {
            /* Resume PWM3 complementary output. */
            *((uint32_t *)TIMER_PWM_REG_BASE) &= (~BIT24);
        }
    }
}

/**
 * \brief  Enable or disable bypass dead zone function of PWM complementary output.
 *         After enabling, PWM_P = ~PWM_N.
 * \param  PWMx: Select the PWM peripheral. \ref PWM_Declaration
 * \param  NewState: New state of the PWMx peripheral.
 *         \arg DISABLE: Disable bypass dead zone function.
 *         \arg ENABLE: Enable bypass dead zone function.
 * \return None.
 * \note   To use this function, need to configure the corresponding timer.
 *         PWM2 ->> TIM2, PWM3 ->> TIM3.
 */
void TIM_PWMDZBypassCmd(PWM_TypeDef *PWMx, FunctionalState NewState)
{
    /* Check the parameters. */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    if (NewState != DISABLE)
    {
        if (PWMx  == PWM2)
        {
            /* Enable bypass dead zone function. */
            *((uint32_t *)TIMER_PWM_REG_BASE) |= BIT13;
        }
        else if (PWMx  == PWM3)
        {
            /* Enable bypass dead zone function. */
            *((uint32_t *)TIMER_PWM_REG_BASE) |= BIT29;
        }
    }
    else
    {
        if (PWMx  == PWM2)
        {
            /* Disable bypass dead zone function. */
            *((uint32_t *)TIMER_PWM_REG_BASE) &= (~BIT13);
        }
        else if (PWMx  == PWM3)
        {
            /* Disable bypass dead zone function. */
            *((uint32_t *)TIMER_PWM_REG_BASE) &= (~BIT29);
        }
    }
}

/**
 * \brief  Change the PWM dead zone clock source.
 * \param  PWMx: Select the PWM peripheral. \ref PWM_Declaration
 * \param  PWM_Deazone_ClockSrc: New state of the PWMx peripheral.
 *         \arg PWM_CK_5M_TIMER: Use 5M clock source.
 *         \arg PWM_CK_32K_TIMER: Use 32k clock source.
 * \return None.
 * \note   To use this function, need to configure the corresponding timer.
 *         PWM2 ->> TIM2, PWM3 ->> TIM3.
 */
void TIM_PWMChangeDZClockSrc(PWM_TypeDef *PWMx, PWMDZClockSrc_TypeDef PWM_Deazone_ClockSrc)
{
    /* Check the parameters. */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    if (PWM_Deazone_ClockSrc == PWM_CK_32K_TIMER)
    {
        if (PWMx  == PWM2)
        {
            /* Use 5M clock source. */
            TIMER_PWM_CLK_CR |= BIT9;
        }
        else if (PWMx  == PWM3)
        {
            /* Use 5M clock source. */
            TIMER_PWM_CLK_CR |= BIT25;
        }
    }
    else
    {
        if (PWMx  == PWM2)
        {
            /* Use 5M clock source. */
            TIMER_PWM_CLK_CR &= (~BIT9);
        }
        else if (PWMx  == PWM3)
        {
            /* Use 5M clock source. */
            TIMER_PWM_CLK_CR &= (~BIT25);
        }
    }
}

/**
  * \brief  Store TIM register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the TIM peripheral.
  * \param  StoreBuf: Store buffer to store TIM register data.
  * \return None.
  */
void TIM_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    TIMStoreReg_Typedef *store_buf = (TIMStoreReg_Typedef *)StoreBuf;

    /* Enable timer IP clock and function */
    RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);
    store_buf->tim_reg[24] = PERIBLKCTRL_PERI_CLK->u_328.REG_TIMER_0_CLOCK_CTRL;
    store_buf->tim_reg[25] = PERIBLKCTRL_PERI_CLK->u_32C.REG_TIMER_1_CLOCK_CTRL;
    store_buf->tim_reg[26] = PERIBLKCTRL_PERI_CLK->u_330.REG_TIMER_2_CLOCK_CTRL;
    store_buf->tim_reg[27] = PERIBLKCTRL_PERI_CLK->u_334.REG_TIMER_3_CLOCK_CTRL;

    store_buf->tim_reg[0] = TIM0->TIMER_LOADCOUNT;
    store_buf->tim_reg[1] = TIM0->TIMER_CONTROLREG;
    store_buf->tim_reg[2] = TIMER0_LOAD_COUNT2;

    store_buf->tim_reg[3] = TIM1->TIMER_LOADCOUNT;
    store_buf->tim_reg[4] = TIM1->TIMER_CONTROLREG;
    store_buf->tim_reg[5] = TIMER1_LOAD_COUNT2;

    store_buf->tim_reg[6] = TIM2->TIMER_LOADCOUNT;
    store_buf->tim_reg[7] = TIM2->TIMER_CONTROLREG;
    store_buf->tim_reg[8] = TIMER2_LOAD_COUNT2;

    store_buf->tim_reg[9]  = TIM3->TIMER_LOADCOUNT;
    store_buf->tim_reg[10] = TIM3->TIMER_CONTROLREG;
    store_buf->tim_reg[11] = TIMER3_LOAD_COUNT2;

    store_buf->tim_reg[12] = TIM4->TIMER_LOADCOUNT;
    store_buf->tim_reg[13] = TIM4->TIMER_CONTROLREG;
    store_buf->tim_reg[14] = TIMER4_LOAD_COUNT2;

    store_buf->tim_reg[15] = TIM5->TIMER_LOADCOUNT;
    store_buf->tim_reg[16] = TIM5->TIMER_CONTROLREG;
    store_buf->tim_reg[17] = TIMER5_LOAD_COUNT2;

    store_buf->tim_reg[18] = TIM6->TIMER_LOADCOUNT;
    store_buf->tim_reg[19] = TIM6->TIMER_CONTROLREG;
    store_buf->tim_reg[20] = TIMER6_LOAD_COUNT2;

    store_buf->tim_reg[21] = TIM7->TIMER_LOADCOUNT;
    store_buf->tim_reg[22] = TIM7->TIMER_CONTROLREG;
    store_buf->tim_reg[23] = TIMER7_LOAD_COUNT2;

    store_buf->tim_reg[28] = PERIBLKCTRL_PERI_CLK->u_33C.REG_TIMER_PWM_WRAP_1_CFG;
}

/**
  * \brief  Restore TIM register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the TIM peripheral.
  * \param  StoreBuf: Restore buffer to restore TIM register data.
  * \return None
  */
void TIM_DLPSExit(void *PeriReg, void *StoreBuf)
{
    TIMStoreReg_Typedef *store_buf = (TIMStoreReg_Typedef *)StoreBuf;

    /* Enable timer IP clock and function */
    RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);
    PERIBLKCTRL_PERI_CLK->u_328.REG_TIMER_0_CLOCK_CTRL = store_buf->tim_reg[24];
    PERIBLKCTRL_PERI_CLK->u_32C.REG_TIMER_1_CLOCK_CTRL = store_buf->tim_reg[25];
    PERIBLKCTRL_PERI_CLK->u_330.REG_TIMER_2_CLOCK_CTRL = store_buf->tim_reg[26];
    PERIBLKCTRL_PERI_CLK->u_334.REG_TIMER_3_CLOCK_CTRL = store_buf->tim_reg[27];

    TIM0->TIMER_LOADCOUNT  = store_buf->tim_reg[0];
    TIM0->TIMER_CONTROLREG = store_buf->tim_reg[1];
    TIMER0_LOAD_COUNT2     = store_buf->tim_reg[2];

    TIM1->TIMER_LOADCOUNT  = store_buf->tim_reg[3];
    TIM1->TIMER_CONTROLREG = store_buf->tim_reg[4];
    TIMER1_LOAD_COUNT2     = store_buf->tim_reg[5];

    TIM2->TIMER_LOADCOUNT  = store_buf->tim_reg[6];
    TIM2->TIMER_CONTROLREG = store_buf->tim_reg[7];
    TIMER2_LOAD_COUNT2     = store_buf->tim_reg[8];

    TIM3->TIMER_LOADCOUNT  = store_buf->tim_reg[9];
    TIM3->TIMER_CONTROLREG = store_buf->tim_reg[10];
    TIMER3_LOAD_COUNT2     = store_buf->tim_reg[11];

    TIM4->TIMER_LOADCOUNT  = store_buf->tim_reg[12];
    TIM4->TIMER_CONTROLREG = store_buf->tim_reg[13];
    TIMER4_LOAD_COUNT2     = store_buf->tim_reg[14];

    TIM5->TIMER_LOADCOUNT  = store_buf->tim_reg[15];
    TIM5->TIMER_CONTROLREG = store_buf->tim_reg[16];
    TIMER5_LOAD_COUNT2     = store_buf->tim_reg[17];

    TIM6->TIMER_LOADCOUNT  = store_buf->tim_reg[18];
    TIM6->TIMER_CONTROLREG = store_buf->tim_reg[19];
    TIMER6_LOAD_COUNT2     = store_buf->tim_reg[20];

    TIM7->TIMER_LOADCOUNT  = store_buf->tim_reg[21];
    TIM7->TIMER_CONTROLREG = store_buf->tim_reg[22];
    TIMER7_LOAD_COUNT2     = store_buf->tim_reg[23];

    PERIBLKCTRL_PERI_CLK->u_33C.REG_TIMER_PWM_WRAP_1_CFG = store_buf->tim_reg[28];
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

