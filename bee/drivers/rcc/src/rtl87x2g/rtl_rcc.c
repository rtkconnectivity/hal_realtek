/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl_rcc.c
* \brief    This file provides all the IO clock firmware functions..
* \details
* \author   Echo
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include <stdint.h>
#include "rtl876x.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                          Private Macros
 *============================================================================*/
#define PERI_ON_CLOCK_CTRL            *((volatile uint32_t *)PERI_ON_RCC_REG_BASE)
#define PERI_ON_AUDIO_CLOCK_CTRL      *((volatile uint32_t *)PERIBLKCTRL_AUDIO_REG_BASE)

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Enables or disables the APB peripheral clock.
  * \param  APBPeriph: specifies the APB peripheral to gates its clock.
  *         This parameter can refer APB Peripheral.
  * \param  APBPeriph_Clock: specifies the APB peripheral clock config.
  *         This parameter can refer to APB Peripheral Clock (must be the same with APBPeriph).
  * \param  NewState: new state of the specified peripheral clock.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void RCC_PeriphClockCmd(uint32_t APBPeriph, uint32_t APBPeriph_Clock, FunctionalState NewState)
{
    /* Check the parameters. */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    uint32_t tmp_1 = APBPeriph & 0x800;
    uint32_t apbRegOff = (APBPeriph & (0XFF));
    uint32_t clk = APBPeriph_Clock;
    uint32_t clk_func = APBPeriph_Clock;

    if (tmp_1 == 0x800)
    {
        clk_func += clk << 1;
    }
    else
    {
        clk_func += clk >> 1;
    }


    if (NewState == ENABLE)
    {
        if (APBPeriph == APBPeriph_CODEC)
        {
            *((uint32_t *)(&(PERI_ON_AUDIO_CLOCK_CTRL)) + apbRegOff) |= clk_func;
        }

        else
        {
            if (APBPeriph == APBPeriph_SPI0)
            {
                if (APBPeriph_Clock == APBPeriph_SPI0_CLOCK)
                {
                    PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_mux_clk_cg_en = 1;
                }
                else if (APBPeriph_Clock == APBPeriph_SPI0_SLAVE_CLOCK)
                {
                    PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_mux_clk_cg_en = 1;
                }
            }
            if (APBPeriph == APBPeriph_IR)
            {
                if (APBPeriph_Clock == APBPeriph_IR_CLOCK)
                {
                    PERIBLKCTRL_PERI_CLK->u_320.BITS_320.r_ir_mux_clk_cg_en = 1;
                }
            }
            /* Enable peripheral and peripheral clock */
            *((uint32_t *)(&(PERI_ON_CLOCK_CTRL)) + apbRegOff) |= clk_func;
        }
    }
    else
    {
        if (APBPeriph == APBPeriph_CODEC)
        {
            *((uint32_t *)(&(PERI_ON_AUDIO_CLOCK_CTRL)) + apbRegOff) &= ~clk_func;
        }
        else
        {
            if (APBPeriph == APBPeriph_SPI0)
            {
                if (APBPeriph_Clock == APBPeriph_SPI0_CLOCK)
                {
                    PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_mux_clk_cg_en = 0;
                }
                else if (APBPeriph_Clock == APBPeriph_SPI0_SLAVE_CLOCK)
                {
                    PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_mux_clk_cg_en = 0;
                }
            }
            if (APBPeriph == APBPeriph_IR)
            {
                if (APBPeriph_Clock == APBPeriph_IR_CLOCK)
                {
                    PERIBLKCTRL_PERI_CLK->u_320.BITS_320.r_ir_mux_clk_cg_en = 0;
                }
            }
            /* Disable peripheral and peripheral clock */
            *((uint32_t *)(&(PERI_ON_CLOCK_CTRL)) + apbRegOff) &= (~clk_func);
        }

    }

    return;
}

/**
  * \brief  Enables or disables the APB peripheral clock.
  * \param  APBPeriph: specifies the APB peripheral to gates its clock.
  *         This parameter can refer APB Peripheral.
  * \param  APBPeriph_Clock: specifies the APB peripheral clock config.
  *         This parameter can refer to APB Peripheral Clock (must be the same with APBPeriph).
  * \param  NewState: new state of the specified peripheral clock.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void RCC_PeriFunctionConfig(uint32_t APBPeriph, uint32_t APBPeriph_Clock, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_APB_PERIPH(APBPeriph));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    uint32_t tmp_1 = APBPeriph & 0x800;
    uint32_t apbRegOff = (APBPeriph & (0XFF));
    uint32_t clk = APBPeriph_Clock;
    uint32_t clk_func = APBPeriph_Clock;

    if (tmp_1 == 0x800)
    {
        clk_func = clk << 1;
    }
    else
    {
        clk_func = clk >> 1;
    }


    if (NewState == ENABLE)
    {
        if (APBPeriph == APBPeriph_CODEC)
        {
            *((uint32_t *)(&(PERI_ON_AUDIO_CLOCK_CTRL)) + apbRegOff) |= clk_func;
        }
        else
        {
            /* Enable peripheral and peripheral clock */
            *((uint32_t *)(&(PERI_ON_CLOCK_CTRL)) + apbRegOff) |= clk_func;
        }
    }
    else
    {
        if (APBPeriph == APBPeriph_CODEC)
        {
            *((uint32_t *)(&(PERI_ON_AUDIO_CLOCK_CTRL)) + apbRegOff) &= ~clk_func;
        }
        else
        {
            /* Disable peripheral and peripheral clock */
            *((uint32_t *)(&(PERI_ON_CLOCK_CTRL)) + apbRegOff) &= (~clk_func);
        }

    }
    return;
}

/**
  * \brief  Enables or disables the APB peripheral clock.
  * \param  APBPeriph: specifies the APB peripheral to gates its clock.
  *         This parameter can refer APB Peripheral.
  * \param  APBPeriph_Clock: specifies the APB peripheral clock config.
  *         This parameter can refer to APB Peripheral Clock (must be the same with APBPeriph).
  * \param  NewState: new state of the specified peripheral clock.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void RCC_PeriClockConfig(uint32_t APBPeriph, uint32_t APBPeriph_Clock, FunctionalState NewState)
{
    /* Check the parameters. */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    uint32_t apbRegOff = (APBPeriph & (0XFF));
    uint32_t clk_func = APBPeriph_Clock;

    if (NewState == ENABLE)
    {

        if (APBPeriph == APBPeriph_CODEC)
        {
            *((uint32_t *)(&(PERI_ON_AUDIO_CLOCK_CTRL)) + apbRegOff) |= clk_func;
        }
        else
        {
            /* Enable peripheral and peripheral clock */
            *((uint32_t *)(&(PERI_ON_CLOCK_CTRL)) + apbRegOff) |= clk_func;
        }
    }
    else
    {
        if (APBPeriph == APBPeriph_CODEC)
        {
            *((uint32_t *)(&(PERI_ON_AUDIO_CLOCK_CTRL)) + apbRegOff) &= ~clk_func;
        }
        else
        {
            /* Disable peripheral and peripheral clock */
            *((uint32_t *)(&(PERI_ON_CLOCK_CTRL)) + apbRegOff) &= (~clk_func);
        }

    }

    return;
}

/**
  * \brief  I2C clock divider config.
  * \param  I2Cx: Select the I2C peripheral. \ref I2C_Declaration
  * \param  ClockDiv: specifies the APB peripheral to gates its clock.
  *         This parameter can be one of the following values:
  *         \arg CLOCK_DIV_1
  *         \arg CLOCK_DIV_2
  *         \arg CLOCK_DIV_4
  *         \arg CLOCK_DIV_8
  *         \arg CLOCK_DIV_16
  *         \arg CLOCK_DIV_32
  *         \arg CLOCK_DIV_40
  *         \arg CLOCK_DIV_64
  * \return None
  */
void RCC_I2CClkDivConfig(I2C_TypeDef *I2Cx, uint16_t ClockDiv)
{
    assert_param(IS_I2C_DIV(ClockDiv));

    /* Config I2C clock divider */
    if (I2Cx == I2C0)
    {
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c0_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c0_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c0_div_en = 1;
    }
    else if (I2Cx == I2C1)
    {
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c1_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c1_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c1_div_en = 1;
    }
    else if (I2Cx == I2C2)
    {
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c2_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c2_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c2_div_en = 1;
    }
    else if (I2Cx == I2C3)
    {
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c3_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c3_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_314.BITS_314.i2c3_div_en = 1;
    }
    return;
}

/**
  * \brief  SPI clock divider config.
  * \param  SPIx: Select the SPI peripheral. \ref SPI_Declaration
  * \param  ClockDiv: specifies the APB peripheral to gates its clock.
  *         This parameter can be one of the following values:
  *         \arg CLOCK_DIV_1
  *         \arg CLOCK_DIV_2
  *         \arg CLOCK_DIV_4
  *         \arg CLOCK_DIV_8
  *         \arg CLOCK_DIV_16
  *         \arg CLOCK_DIV_32
  *         \arg CLOCK_DIV_40
  *         \arg CLOCK_DIV_64
  * \return None
  */
void RCC_SPIClkDivConfig(SPI_TypeDef *SPIx, uint16_t ClockDiv)
{
    assert_param(IS_SPI_DIV(ClockDiv));

    /* Config SPI clock divider */
    if (SPIx == SPI0)
    {
        /* disable clock first */
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_div_sel =  ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_div_en = 1;
    }
    else if (SPIx == SPI1)
    {
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi1_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi1_div_sel =  ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi1_div_en = 1;

    }
    else if (SPIx == SPI0_SLAVE)
    {
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_div_sel =  ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_310.BITS_310.spi0_s_div_en = 1;
    }
    return;
}

/**
  * \brief  UART clock divider config.
  * \param  UARTx: Select the UART peripheral. \ref UART_Declaration
  * \param  ClockDiv: specifies the APB peripheral to gates its clock.
  *         This parameter can be one of the following values:
  *         \arg CLOCK_DIV_1
  *         \arg CLOCK_DIV_2
  *         \arg CLOCK_DIV_4
  *         \arg CLOCK_DIV_8
  *         \arg CLOCK_DIV_16
  *         \arg CLOCK_DIV_32
  *         \arg CLOCK_DIV_40
  *         \arg CLOCK_DIV_64
  * \return None
  */
void RCC_UARTClkDivConfig(UART_TypeDef *UARTx, uint16_t ClockDiv)
{
    assert_param(IS_UART_DIV(ClockDiv));

    /* Config UART clock divider */
    if (UARTx == UART0)
    {
        /* disable clock first */
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.rtk_uart0_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.rtk_uart0_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.rtk_uart0_div_en = 1;
    }
    else if (UARTx == UART1)
    {
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.rtk_uart1_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.rtk_uart1_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.rtk_uart1_div_en = 1;
    }
    else if (UARTx == UART2)
    {
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.rtk_uart2_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.rtk_uart2_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.rtk_uart2_div_en = 1;
    }
    else if (UARTx == UART3)
    {
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.rtk_uart3_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.rtk_uart3_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.rtk_uart3_div_en = 1;
    }
    else if (UARTx == UART4)
    {
        PERIBLKCTRL_PERI_CLK->u_38C.BITS_38C.rtk_uart4_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_38C.BITS_38C.rtk_uart4_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_38C.BITS_38C.rtk_uart4_div_en = 1;
    }
    else if (UARTx == UART5)
    {
        PERIBLKCTRL_PERI_CLK->u_38C.BITS_38C.rtk_uart5_div_en = 0;
        PERIBLKCTRL_PERI_CLK->u_38C.BITS_38C.rtk_uart5_div_sel = ClockDiv;
        PERIBLKCTRL_PERI_CLK->u_38C.BITS_38C.rtk_uart5_div_en = 1;
    }
    return;
}

/**
  * \brief  TIM clock config.
  * \param  TIMx: Select the TIM peripheral. \ref TIMER_Declaration
  * \param  ClockSrc: specifies the clock source to gates its clock.
  * \param  ClockDiv: specifies the clock divide to gates its clock.
  * \return None
  */
void RCC_TIMClkConfig(TIM_TypeDef *TIMx, uint16_t ClockSrc, uint16_t ClockDiv)
{
    /* Select clock source which can be system clock or 40 MHz  or pll*/
    uint32_t tempreg = (uint32_t)TIMx;
    uint32_t timerid = (tempreg - TIMER_REG_BASE) / 20;
    uint32_t tim_id_odd = timerid % 2;
    uint32_t tim_id_temp = timerid / 2;
    uint8_t ClockDivEn = ClockDiv == 0 ? DISABLE : ENABLE;

    /*div the clock source,actually it need enable TIM_SOURCE_CLOCK_DIV_EN*/
    if (timerid < 2)
    {
        /*set TIM clock src*/
        if (ClockDivEn != DISABLE)
        {
            TIMER_CLK_SOURCE_REG_328 |= (0x1 << (3 + (timerid * 16)));
            TIMER_CLK_SOURCE_REG_328 &= ~(0x7 << (timerid * 16));
            TIMER_CLK_SOURCE_REG_328 |= ((ClockDiv) << (timerid * 16));
        }
        else
        {
            TIMER_CLK_SOURCE_REG_328 &= ~(0x1 << (3 + (timerid * 16)));
        }
    }
    else if ((timerid >= 2) && (timerid < 8))
    {
        /*set TIM clock src*/
        if (ClockSrc == CK_PLL1_TIMER)
        {
            *((uint32_t *)(&(TIMER_CLK_SOURCE_REG_328)) + tim_id_temp) |= ((BIT0) << (4 + 16 * tim_id_odd));
        }
        else if (ClockSrc == CK_PLL2_TIMER)
        {
            *((uint32_t *)(&(TIMER_CLK_SOURCE_REG_328)) + tim_id_temp) &= ~(BIT0 << (4 + (tim_id_odd * 16)));
            *((uint32_t *)(&(TIMER_CLK_SOURCE_REG_328)) + tim_id_temp) |= ((BIT0) << (12 + 16 * tim_id_odd));
        }
        else
        {
            *((uint32_t *)(&(TIMER_CLK_SOURCE_REG_328)) + tim_id_temp) &= ~(BIT0 << (4 + (tim_id_odd * 16)));
            *((uint32_t *)(&(TIMER_CLK_SOURCE_REG_328)) + tim_id_temp) &= ~(BIT0 << (12 + (tim_id_odd * 16)));
            *((uint32_t *)(&(TIMER_CLK_SOURCE_REG_328)) + tim_id_temp) &= ~(BIT0 << (13 + (tim_id_odd * 16)));
            *((uint32_t *)(&(TIMER_CLK_SOURCE_REG_328)) + tim_id_temp) |= (ClockSrc << (13 + 16 * tim_id_odd));
        }

        /*Clear TIM Clock DIV */
        *((uint32_t *)(&(TIMER_CLK_SOURCE_REG_328)) + tim_id_temp) &= ~(0xF << 16 * tim_id_odd);
        if ((ClockDivEn != DISABLE))
        {
            *((uint32_t *)(&(TIMER_CLK_SOURCE_REG_328)) + tim_id_temp) |= BIT3 << 16 * tim_id_odd;
            *((uint32_t *)(&(TIMER_CLK_SOURCE_REG_328)) + tim_id_temp) |= (ClockDiv << 16 * tim_id_odd);
        }
        else
        {
            *((uint32_t *)(&(TIMER_CLK_SOURCE_REG_328)) + tim_id_temp) &= ~(BIT3 << 16 * tim_id_odd);
        }

    }
}

/**
  * \brief  ENHTIM clock config.
  * \param  ENHTIMx: ENHTIMx: Select the ENHTIM peripheral. \ref ENHTIM_Declaration
  * \param  ClockSrc: specifies the clock source to gates its clock.
  * \param  ClockDiv: specifies the clock divide to gates its clock.
  * \return None
  */
void RCC_ENHTIMClkConfig(ENHTIM_TypeDef *ENHTIMx, uint16_t ClockSrc, uint16_t ClockDiv)
{
    uint32_t enhtim_id = ((uint32_t)ENHTIMx - (uint32_t)ENH_TIM0) / 0x24;
    uint32_t enhtim_id_odd = enhtim_id % 2;
    uint32_t enhtim_id_temp = enhtim_id / 2;
    uint8_t ENHTIM_ClockDiv_En = ClockDiv == 0 ? DISABLE : ENABLE;

    uint32_t id = (4 + 16 * enhtim_id_odd);
    *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) &= ~(0x7 << id);
    *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) |= (ClockSrc << id);

    /*Clear ENHTIM Clock DIV */
    *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) &= ~(0xF << 16 * enhtim_id_odd);
    if ((ENHTIM_ClockDiv_En != DISABLE))
    {
        *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) |= BIT3 << 16 * enhtim_id_odd;
        *((uint32_t *)(&(REG_ENHTIMER_CLOCK_CTRL)) + enhtim_id_temp) |= (ClockDiv << 16 * enhtim_id_odd);
    }
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/
