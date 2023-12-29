/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     rtl_gpio_int.c
* @brief    This file provides all the GPIO firmware internal functions.
* @details
* @author   Bert
* @date     2023-07-05
* @version  v1.0
*********************************************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "rtl_i2c.h"
#include "rtl_rcc.h"

uint8_t I2C_GetCompIndex(I2C_TypeDef *I2Cx)
{
    uint8_t compensate_index = 3;

    if (I2Cx == I2C0)
    {
        compensate_index = PERIBLKCTRL_PERI_CLK->u_154.BITS_154.i2c0_div_sel;
    }
    else if (I2Cx == I2C1)
    {
        compensate_index = PERIBLKCTRL_PERI_CLK->u_154.BITS_154.i2c1_div_sel;
    }
    else if (I2Cx == I2C2)
    {
        compensate_index = PERIBLKCTRL_PERI_CLK->u_154.BITS_154.i2c2_div_sel;
    }
    else if (I2Cx == I2C3)
    {
        /* I2C3 not support setting div select */
    }

    return compensate_index;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

