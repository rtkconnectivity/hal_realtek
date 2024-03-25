/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     rtl_hradc_int.c
* @brief    This file provides all the HRADC firmware internal functions.
* @details
* @author
* @date     2023-10-09
* @version  v1.0
*********************************************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "rtl_hradc.h"
#include "rtl_rcc.h"
#include "rtl_aon_reg.h"

void HRADC_AutoBootPowerConfig(HRADCMode_TypeDef HRADC_Mode)
{
    assert_param(IS_HRADC_MODE(HRADC_Mode));
    AON_NS_REG0X_SDADC_LDO_TYPE sdadc_aon_0x1DC0 = {.d32 = HRADC_LDO_REG1DC0};
    if ((HRADC_Mode == HRADC_18_LDO_MODE) || (HRADC_Mode == HRADC_28_LDO_MODE))
    {
        /* LDO output select=2.8V or 1.8V */
        sdadc_aon_0x1DC0.b.REG_ANAPAR_LDO_5 = 0x1 & HRADC_Mode;
        /* Disable bypass LDO */
        sdadc_aon_0x1DC0.b.REG_ANAPAR_LDO_7 = 0x0;
    }
    else
    {
        sdadc_aon_0x1DC0.b.REG_ANAPAR_LDO_5 = 0x0;
        /* Enable bypass LDO */
        sdadc_aon_0x1DC0.b.REG_ANAPAR_LDO_7 = 0x1;

    }
    HRADC_LDO_REG1DC0 = sdadc_aon_0x1DC0.d32;
}


/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

