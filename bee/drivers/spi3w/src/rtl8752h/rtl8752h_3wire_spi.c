/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_3wire_spi.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * @brief  SPI2W enter dlps callback function(Save SPI2W register values when system enter DLPS)
  * @param  None
  * @retval None
  */

void SPI2W_DLPS_Enter(void *PeriReg, void *StoreBuf)
{
    SPI3WIRE_TypeDef *SPI3Wx = (SPI3WIRE_TypeDef *)PeriReg;
    SPI3WStoreReg_Typedef *store_buf = (SPI3WStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_SPI2W, APBPeriph_SPI2W_CLOCK, ENABLE);

    SPI2W_StoreReg[0] = SPI3Wx->CFGR;
}

/**
  * @brief  SPI2W exit dlps callback function(Resume SPI2W register values when system exit DLPS)
  * @param  None
  * @retval None
  */
void SPI2W_DLPS_Exit(void *PeriReg, void *StoreBuf)
{
    SPI3WIRE_TypeDef *SPI3Wx = (SPI3WIRE_TypeDef *)PeriReg;
    SPIStoreReg_Typedef *store_buf = (SPIStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_SPI2W, APBPeriph_SPI2W_CLOCK, ENABLE);

    SPI3Wx->CFGR = SPI2W_StoreReg[0];
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

