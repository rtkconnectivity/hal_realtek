/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl87x2g_spi.c
* \brief    This file provides all the ADC firmware internal functions.
* \details
* \author   Bert
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_spi.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store SPI register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the SPI peripheral.
  * \param  StoreBuf: Store buffer to store SPI register data.
  * \return None.
  */
void SPI_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    SPI_TypeDef *SPIx = (SPI_TypeDef *)PeriReg;
    SPIStoreReg_Typedef *store_buf = (SPIStoreReg_Typedef *)StoreBuf;

    if (SPIx == SPI0)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);
    }
    else if (SPIx == SPI0_SLAVE)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI0_SLAVE, APBPeriph_SPI0_SLAVE_CLOCK, ENABLE);
    }
    else if (SPIx == SPI1)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI1, APBPeriph_SPI1_CLOCK, ENABLE);
    }

    store_buf->spi_reg[0] = SPI0->SPI_M_S_CTRL0;        /*!< 0x00 */
    store_buf->spi_reg[1] = SPI0->SPI_M_CTRL1;          /*!< 0x04 */
    store_buf->spi_reg[2] = SPI0->SPI_SPIENR;           /*!< 0x08 */
    store_buf->spi_reg[3] = SPI0->SPI_M_SER;            /*!< 0x10 */
    store_buf->spi_reg[4] = SPI0->SPI_M_BAUDR;          /*!< 0x14 */
    store_buf->spi_reg[5] = SPI0->SPI_TXFTLR;           /*!< 0x18 */
    store_buf->spi_reg[6] = SPI0->SPI_RXFTLR;           /*!< 0x1C */
    store_buf->spi_reg[7] = SPI0->SPI_M_S_IMR;          /*!< 0x2C */
    store_buf->spi_reg[8] = SPI0->SPI_DMACR;            /*!< 0x4C */
    store_buf->spi_reg[9] = SPI0->SPI_DMATDLR;          /*!< 0x50 */
    store_buf->spi_reg[10] = SPI0->SPI_DMARDLR;         /*!< 0x54 */
    store_buf->spi_reg[11] = SPI0->SPI_M_RSDR;          /*!< 0xF0 */
}

/**
  * \brief  Restore SPI register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the SPI peripheral.
  * \param  StoreBuf: Restore buffer to restore SPI register data.
  * \return None
  */
void SPI_DLPSExit(void *PeriReg, void *StoreBuf)
{
    SPI_TypeDef *SPIx = (SPI_TypeDef *)PeriReg;
    SPIStoreReg_Typedef *store_buf = (SPIStoreReg_Typedef *)StoreBuf;

    if (SPIx == SPI0)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);
    }
    else if (SPIx == SPI0_SLAVE)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI0_SLAVE, APBPeriph_SPI0_SLAVE_CLOCK, ENABLE);
    }
    else if (SPIx == SPI1)
    {
        RCC_PeriphClockCmd(APBPeriph_SPI1, APBPeriph_SPI1_CLOCK, ENABLE);
    }

    SPI0->SPI_M_S_CTRL0 = store_buf->spi_reg[0];
    SPI0->SPI_M_CTRL1   = store_buf->spi_reg[1];
    SPI0->SPI_M_SER     = store_buf->spi_reg[3];
    SPI0->SPI_M_BAUDR   = store_buf->spi_reg[4];
    SPI0->SPI_TXFTLR    = store_buf->spi_reg[5];
    SPI0->SPI_RXFTLR    = store_buf->spi_reg[6];
    SPI0->SPI_M_S_IMR   = store_buf->spi_reg[7];
    SPI0->SPI_DMACR     = store_buf->spi_reg[8];
    SPI0->SPI_DMATDLR   = store_buf->spi_reg[9];
    SPI0->SPI_DMARDLR   = store_buf->spi_reg[10];
    SPI0->SPI_M_RSDR    = store_buf->spi_reg[11];

    /* Enable the selected SPI peripheral */
    SPI0->SPI_SPIENR    = store_buf->spi_reg[2];
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

