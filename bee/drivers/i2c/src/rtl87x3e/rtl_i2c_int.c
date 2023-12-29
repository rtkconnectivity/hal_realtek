/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     rtl_i2c_int.c
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
        compensate_index = SYSBLKCTRL->u_35C.BITS_35C.BIT_PERI_I2C0_CLK_DIV;
    }
    else if (I2Cx == I2C1)
    {
        compensate_index = SYSBLKCTRL->u_35C.BITS_35C.BIT_PERI_I2C1_CLK_DIV;
    }
    else if (I2Cx == I2C2)
    {
        compensate_index = SYSBLKCTRL->u_35C.BITS_35C.BIT_PERI_I2C2_CLK_DIV;
    }

    return compensate_index;
}
/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

