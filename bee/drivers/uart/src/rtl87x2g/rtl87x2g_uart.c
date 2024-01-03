/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl87x2g_uart.c
* \brief    This file provides all the UART firmware internal functions.
* \details
* \author   Bert
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "uart/inc/rtl_uart.h"
#include "rcc/inc/rtl_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
 * \brief   UART one wire config.
 * \param   UARTx: Select the UART peripheral. \ref UART_Declaration
 * \param   NewState: UART one wire config is set or not.
 *          This parameter can be one of the following values:
 *          \arg true: UART one wire config is set.
 *          \arg false: UART one wire config is unset.
 * \return  None.
 */
void UART_OneWireConfig(UART_TypeDef *UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    if (UARTx == UART0)
    {
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.r_PMUX_1_WIRE_UART0_EN = NewState;
    }
    else if (UARTx == UART1)
    {
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.r_PMUX_1_WIRE_UART1_EN = NewState;
    }
    else if (UARTx == UART2)
    {
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.r_PMUX_1_WIRE_UART2_EN = NewState;
    }
    else if (UARTx == UART3)
    {
        PERIBLKCTRL_PERI_CLK->u_318.BITS_318.r_PMUX_1_WIRE_UART3_EN = NewState;
    }
    else if (UARTx == UART4)
    {
        PERIBLKCTRL_PERI_CLK->u_38C.BITS_38C.r_PMUX_1_WIRE_UART4_EN = NewState;
    }
    else if (UARTx == UART5)
    {
        PERIBLKCTRL_PERI_CLK->u_38C.BITS_38C.r_PMUX_1_WIRE_UART5_EN = NewState;
    }
}

/**
  * \brief  Store UART register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the UART peripheral.
  * \param  StoreBuf: Store buffer to store UART register data.
  * \return None.
  */
void UART_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    UART_TypeDef *UARTx = (UART_TypeDef *)PeriReg;
    UARTStoreReg_Typedef *store_buf = (UARTStoreReg_Typedef *)StoreBuf;

    if (UARTx == UART0)
    {
        RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE);
        store_buf->uart_reg[12] = PERIBLKCTRL_PERI_CLK->u_318.REG_UART_PERI_CTL0;
    }
    else if (UARTx == UART1)
    {
        RCC_PeriphClockCmd(APBPeriph_UART1, APBPeriph_UART1_CLOCK, ENABLE);
        store_buf->uart_reg[12] = PERIBLKCTRL_PERI_CLK->u_318.REG_UART_PERI_CTL0;
    }
    else if (UARTx == UART2)
    {
        RCC_PeriphClockCmd(APBPeriph_UART2, APBPeriph_UART2_CLOCK, ENABLE);
        store_buf->uart_reg[12] = PERIBLKCTRL_PERI_CLK->u_318.REG_UART_PERI_CTL0;
    }
    else if (UARTx == UART3)
    {
        RCC_PeriphClockCmd(APBPeriph_UART3, APBPeriph_UART3_CLOCK, ENABLE);
        store_buf->uart_reg[12] = PERIBLKCTRL_PERI_CLK->u_318.REG_UART_PERI_CTL0;
    }
    else if (UARTx == UART4)
    {
        RCC_PeriphClockCmd(APBPeriph_UART4, APBPeriph_UART4_CLOCK, ENABLE);
        store_buf->uart_reg[12] = PERIBLKCTRL_PERI_CLK->u_38C.REG_UART_PERI_CTL1;
    }
    else if (UARTx == UART5)
    {
        RCC_PeriphClockCmd(APBPeriph_UART5, APBPeriph_UART5_CLOCK, ENABLE);
        store_buf->uart_reg[12] = PERIBLKCTRL_PERI_CLK->u_38C.REG_UART_PERI_CTL1;
    }

    //access DLH and DLL
    UARTx->UART_LCR |= (1 << 7);
    store_buf->uart_reg[0] = UARTx->UART_DLL;
    store_buf->uart_reg[1] = UARTx->UART_DLM_IER;
    UARTx->UART_LCR &= (~(1 << 7));

    //save other registers
    store_buf->uart_reg[2] = UARTx->UART_DLM_IER;
    store_buf->uart_reg[4] = UARTx->UART_LCR;
    store_buf->uart_reg[5] = UARTx->UART_CTRL0;
    store_buf->uart_reg[6] = UARTx->UART_SCR;
    store_buf->uart_reg[7] = UARTx->UART_STSR;
    store_buf->uart_reg[8] = UARTx->UART_RX_TIMEOUT;
    store_buf->uart_reg[9] = UARTx->UART_RX_TIMEOUT_EN;
    store_buf->uart_reg[10] = UARTx->UART_MISCR;
    store_buf->uart_reg[11] = UARTx->UART_INT_MASK;

    return;
}

/**
  * \brief  Restore UART register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the UART peripheral.
  * \param  StoreBuf: Restore buffer to restore UART register data.
  * \return None
  */
void UART_DLPSExit(void *PeriReg, void *StoreBuf)
{
    UART_TypeDef *UARTx = (UART_TypeDef *)PeriReg;
    UARTStoreReg_Typedef *store_buf = (UARTStoreReg_Typedef *)StoreBuf;

    if (UARTx == UART0)
    {
        RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE);
        store_buf->uart_reg[12] = PERIBLKCTRL_PERI_CLK->u_318.REG_UART_PERI_CTL0;
    }
    else if (UARTx == UART1)
    {
        RCC_PeriphClockCmd(APBPeriph_UART1, APBPeriph_UART1_CLOCK, ENABLE);
        store_buf->uart_reg[12] = PERIBLKCTRL_PERI_CLK->u_318.REG_UART_PERI_CTL0;
    }
    else if (UARTx == UART2)
    {
        RCC_PeriphClockCmd(APBPeriph_UART2, APBPeriph_UART2_CLOCK, ENABLE);
        store_buf->uart_reg[12] = PERIBLKCTRL_PERI_CLK->u_318.REG_UART_PERI_CTL0;
    }
    else if (UARTx == UART3)
    {
        RCC_PeriphClockCmd(APBPeriph_UART3, APBPeriph_UART3_CLOCK, ENABLE);
        store_buf->uart_reg[12] = PERIBLKCTRL_PERI_CLK->u_318.REG_UART_PERI_CTL0;
    }
    else if (UARTx == UART4)
    {
        RCC_PeriphClockCmd(APBPeriph_UART4, APBPeriph_UART4_CLOCK, ENABLE);
        store_buf->uart_reg[12] = PERIBLKCTRL_PERI_CLK->u_38C.REG_UART_PERI_CTL1;
    }
    else if (UARTx == UART5)
    {
        RCC_PeriphClockCmd(APBPeriph_UART5, APBPeriph_UART5_CLOCK, ENABLE);
        store_buf->uart_reg[12] = PERIBLKCTRL_PERI_CLK->u_38C.REG_UART_PERI_CTL1;
    }

    //access DLH and DLL
    UARTx->UART_LCR         |= (1 << 7);
    UARTx->UART_STSR        = store_buf->uart_reg[7];
    UARTx->UART_SCR         = store_buf->uart_reg[6];
    UARTx->UART_DLL         = store_buf->uart_reg[0];
    UARTx->UART_DLM_IER     = store_buf->uart_reg[1];
    UARTx->UART_LCR         &= (~(1 << 7));

    //access other registers
    UARTx->UART_IIR_FCR = (((store_buf->uart_reg[7] & BIT24) >> 21) | \
                           ((store_buf->uart_reg[7] & 0x7C000000) >> 18) | \
                           (1));
    UARTx->UART_LCR         = store_buf->uart_reg[4];
    UARTx->UART_CTRL0       = store_buf->uart_reg[5];
    UARTx->UART_DLM_IER     = store_buf->uart_reg[2];
    UARTx->UART_RX_TIMEOUT  = store_buf->uart_reg[8];
    UARTx->UART_RX_TIMEOUT_EN = store_buf->uart_reg[9];
    UARTx->UART_MISCR       = store_buf->uart_reg[10];
    UARTx->UART_INT_MASK    = store_buf->uart_reg[11];

    return;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

