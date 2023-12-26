/**
*********************************************************************************************************
*               Copyright(c) 2015, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* @file      rtl876x_spi.h
* @brief
* @details
* @author    elliot chen
* @date      2015-5-6
* @version   v1.0
* *********************************************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RTL876X_SPI_H
#define __RTL876X_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "rtl876x.h"
#include "rtl876x_bitfields.h"


/** @addtogroup 87x3d_SPI SPI
  * @brief SPI driver module
  * @{
  */

/*============================================================================*
 *                         Types
 *============================================================================*/


/** @defgroup SPI_Exported_Types SPI Exported Types
  * @{
  */

/**
  * @brief  SPI Init structure definition
  */

typedef struct
{
    uint16_t SPI_Direction;         /*!< Specifies the SPI unidirectional or bidirectional data mode.
                                                    This parameter can be a value of @ref SPI_data_direction */

    uint16_t SPI_Mode;              /*!< Specifies the SPI operating mode.
                                                    This parameter can be a value of @ref SPI_mode */

    uint16_t SPI_DataSize;          /*!< Specifies the SPI data size.
                                                    This parameter can be a value of @ref SPI_data_size */

    uint16_t SPI_CPOL;              /*!< Specifies the serial clock steady state.
                                                    This parameter can be a value of @ref SPI_Clock_Polarity */

    uint16_t SPI_CPHA;              /*!< Specifies the clock active edge for the bit capture.
                                                    This parameter can be a value of @ref SPI_Clock_Phase */

    uint32_t SPI_SwapTxBitEn;              /*!< Specifies whether to swap spi tx data bit */

    uint32_t SPI_SwapRxBitEn;              /*!< Specifies whether to swap spi rx data bit */

    uint32_t SPI_SwapTxByteEn;              /*!< Specifies whether to swap spi tx data bit */

    uint32_t SPI_SwapRxByteEn;              /*!< Specifies whether to swap spi rx data bit */

    uint32_t SPI_ToggleEn;            /*!< Specifies whether CS to toggle between successive frames, default is DISABLE
                                        ENABLE: CS toggle between successive frames ,
                                        DISABLE: CS doesnot toggle between successive frames
                                      enable SPI_ToggleEn should make sure SPI_CPHA = 0(SPI_CPHA_1Edge)*/

    uint32_t SPI_BaudRatePrescaler;        /*!< Specifies the speed of SCK clock. SPI Clock Speed = clk source/SPI_ClkDIV
                                                    @note The communication clock is derived from the master
                                                    clock. The slave clock does not need to be set. */
    uint16_t SPI_FrameFormat;       /*!< Specifies which serial protocol transfers the data.
                                                    This parameter can be a value of @ref SPI_frame_format */

    uint32_t SPI_TxThresholdLevel;  /*!<  Specifies the transmit FIFO Threshold */

    uint32_t SPI_RxThresholdLevel;  /*!< Specifies the receive FIFO Threshold */

    uint32_t SPI_NDF;               /*!< Specifies the trigger condition in EEPROM mode.
                                                    This parameter should be the value of the length of read data. */

    uint16_t SPI_TxDmaEn;               /*!< Specifies the Tx dma mode.*/

    uint16_t SPI_RxDmaEn;               /*!< Specifies the Rx dma mode >*/

    uint8_t SPI_TxWaterlevel;           /*!< Specifies the DMA tx water level >*/

    uint8_t SPI_RxWaterlevel;           /*!< Specifies the DMA rx water level >*/

    uint8_t SPI_RxSampleDly;           /*!< Specifies the sample delay of receive data.
                                                    @note If set the spi master clock greater than 10M, rx
                                                    sample dly need to be set to 1*/

} SPI_InitTypeDef;

/** End of group SPI_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/


/** @defgroup SPI_Exported_Constants SPI Exported Constants
  * @{
  */

#define IS_SPI_ALL_PERIPH(PERIPH) (((PERIPH) == SPI0) || \
                                   ((PERIPH) == SPI0_HS) || \
                                   ((PERIPH) == SPI1) || \
                                   ((PERIPH) == SPI2))


/** @defgroup SPI_clock_speed SPI Clock Speed
  * @{
  */

#define IS_SPI_CLOCK_SPEED(SPEED) (((SPEED) >= 0x01) && ((SPEED) <= 40000000))

/** End of group SPI_clock_speed
  * @}
  */

/** @defgroup SPI_data_direction SPI Data Direction
  * @{
  */

#define SPI_Direction_FullDuplex        ((uint16_t)0x0000)
#define SPI_Direction_TxOnly            ((uint16_t)0x0001)
#define SPI_Direction_RxOnly            ((uint16_t)0x0002)
#define SPI_Direction_EEPROM            ((uint16_t)0x0003)

#define IS_SPI_DIRECTION_MODE(MODE) (((MODE) == SPI_Direction_FullDuplex) || \
                                     ((MODE) == SPI_Direction_RxOnly) || \
                                     ((MODE) == SPI_Direction_TxOnly) || \
                                     ((MODE) == SPI_Direction_EEPROM))

/** End of group SPI_data_direction
  * @}
  */

/** @defgroup SPI_mode SPI Mode
  * @{
  */

#define SPI_Mode_Master                         ((uint16_t)0x0104)
#define SPI_Mode_Slave                          ((uint16_t)0x0000)
#define IS_SPI_MODE(MODE) (((MODE) == SPI_Mode_Master) || \
                           ((MODE) == SPI_Mode_Slave))

/** End of group SPI_mode
  * @}
  */

/** @defgroup SPI_data_size SPI Data Size
  * @{
  */

#define SPI_DataSize_4b                 ((uint16_t)0x0003)
#define SPI_DataSize_5b                 ((uint16_t)0x0004)
#define SPI_DataSize_6b                 ((uint16_t)0x0005)
#define SPI_DataSize_7b                 ((uint16_t)0x0006)
#define SPI_DataSize_8b                 ((uint16_t)0x0007)
#define SPI_DataSize_9b                 ((uint16_t)0x0008)
#define SPI_DataSize_10b                 ((uint16_t)0x0009)
#define SPI_DataSize_11b                 ((uint16_t)0x000a)
#define SPI_DataSize_12b                 ((uint16_t)0x000b)
#define SPI_DataSize_13b                 ((uint16_t)0x000c)
#define SPI_DataSize_14b                 ((uint16_t)0x000d)
#define SPI_DataSize_15b                 ((uint16_t)0x000e)
#define SPI_DataSize_16b                 ((uint16_t)0x000f)
#define SPI_DataSize_17b                 ((uint16_t)0x0010)
#define SPI_DataSize_18b                 ((uint16_t)0x0011)
#define SPI_DataSize_19b                 ((uint16_t)0x0012)
#define SPI_DataSize_20b                 ((uint16_t)0x0013)
#define SPI_DataSize_21b                 ((uint16_t)0x0014)
#define SPI_DataSize_22b                 ((uint16_t)0x0015)
#define SPI_DataSize_23b                 ((uint16_t)0x0016)
#define SPI_DataSize_24b                 ((uint16_t)0x0017)
#define SPI_DataSize_25b                 ((uint16_t)0x0018)
#define SPI_DataSize_26b                 ((uint16_t)0x0019)
#define SPI_DataSize_27b                 ((uint16_t)0x001A)
#define SPI_DataSize_28b                 ((uint16_t)0x001B)
#define SPI_DataSize_29b                 ((uint16_t)0x001C)
#define SPI_DataSize_30b                 ((uint16_t)0x001D)
#define SPI_DataSize_31b                 ((uint16_t)0x001E)
#define SPI_DataSize_32b                 ((uint16_t)0x001F)
#define IS_SPI_DATASIZE(DATASIZE) (((DATASIZE) == SPI_DataSize_4b)  || \
                                   ((DATASIZE) == SPI_DataSize_5b)  || \
                                   ((DATASIZE) == SPI_DataSize_6b)  || \
                                   ((DATASIZE) == SPI_DataSize_7b)  || \
                                   ((DATASIZE) == SPI_DataSize_8b)  || \
                                   ((DATASIZE) == SPI_DataSize_9b)  || \
                                   ((DATASIZE) == SPI_DataSize_10b) || \
                                   ((DATASIZE) == SPI_DataSize_11b) || \
                                   ((DATASIZE) == SPI_DataSize_12b) || \
                                   ((DATASIZE) == SPI_DataSize_13b) || \
                                   ((DATASIZE) == SPI_DataSize_14b) || \
                                   ((DATASIZE) == SPI_DataSize_15b) || \
                                   ((DATASIZE) == SPI_DataSize_16b) || \
                                   ((DATASIZE) == SPI_DataSize_17b) || \
                                   ((DATASIZE) == SPI_DataSize_18b) || \
                                   ((DATASIZE) == SPI_DataSize_19b) || \
                                   ((DATASIZE) == SPI_DataSize_20b) || \
                                   ((DATASIZE) == SPI_DataSize_21b) || \
                                   ((DATASIZE) == SPI_DataSize_22b) || \
                                   ((DATASIZE) == SPI_DataSize_23b) || \
                                   ((DATASIZE) == SPI_DataSize_24b) || \
                                   ((DATASIZE) == SPI_DataSize_25b) || \
                                   ((DATASIZE) == SPI_DataSize_26b) || \
                                   ((DATASIZE) == SPI_DataSize_27b) || \
                                   ((DATASIZE) == SPI_DataSize_28b) || \
                                   ((DATASIZE) == SPI_DataSize_29b) || \
                                   ((DATASIZE) == SPI_DataSize_30b) || \
                                   ((DATASIZE) == SPI_DataSize_31b) || \
                                   ((DATASIZE) == SPI_DataSize_32b))

/** End of group SPI_data_size
  * @}
  */

/** @defgroup SPI_Clock_Polarity SPI Clock Polarity
  * @{
  */

#define SPI_CPOL_Low                    ((uint16_t)0x0000)
#define SPI_CPOL_High                   ((uint16_t)0x0001)
#define IS_SPI_CPOL(CPOL) (((CPOL) == SPI_CPOL_Low) || \
                           ((CPOL) == SPI_CPOL_High))

/** End of group SPI_Clock_Polarity
  * @}
  */

/** @defgroup SPI_Clock_Phase SPI Clock Phase
  * @{
  */

#define SPI_CPHA_1Edge                  ((uint16_t)0x0000)
#define SPI_CPHA_2Edge                  ((uint16_t)0x0001)
#define IS_SPI_CPHA(CPHA) (((CPHA) == SPI_CPHA_1Edge) || \
                           ((CPHA) == SPI_CPHA_2Edge))

/** End of group SPI_Clock_Phase
  * @}
  */

/** @defgroup SPI_frame_format SPI Frame Format
  * @{
  */

#define SPI_Frame_Motorola              ((uint16_t)0x0000)
#define SPI_Frame_TI_SSP                ((uint16_t)0x0001)
#define SPI_Frame_NS_MICROWIRE          ((uint16_t)0x0002)
#define SPI_Frame_Reserve               ((uint16_t)0x0003)
#define IS_SPI_FRAME_FORMAT(FRAME) (((FRAME) == SPI_Frame_Motorola) || \
                                    ((FRAME) == SPI_Frame_TI_SSP) || \
                                    ((FRAME) == SPI_Frame_NS_MICROWIRE) || \
                                    ((FRAME) == SPI_Frame_Reserve))

/** End of group SPI_frame_format
  * @}
  */

/** @defgroup SPI_flags_definition SPI Flags Definition
  * @{
  */

#define SPI_FLAG_BUSY                   ((uint16_t)0x0001)
#define SPI_FLAG_TFNF                   ((uint16_t)0x0002)
#define SPI_FLAG_TFE                    ((uint16_t)0x0004)
#define SPI_FLAG_RFNE                   ((uint16_t)0x0008)
#define SPI_FLAG_RFF                    ((uint16_t)0x0010)
#define SPI_FLAG_TXE                    ((uint16_t)0x0020)
#define SPI_FLAG_DCOL                   ((uint16_t)0x0040)
#define IS_SPI_GET_FLAG(FLAG)   (((FLAG) == SPI_FLAG_DCOL) || ((FLAG) == SPI_FLAG_TXE) || \
                                 ((FLAG) == SPI_FLAG_RFF) || ((FLAG) == SPI_FLAG_RFNE) || \
                                 ((FLAG) == SPI_FLAG_TFE) || ((FLAG) == SPI_FLAG_TFNF) || \
                                 ((FLAG) == SPI_FLAG_BUSY))

/** End of group SPI_flags_definition
  * @}
  */

/** @defgroup SPI_interrupts_definition SPI Interrupts Definition
  * @{
  */

#define SPI_INT_TXE                  ((uint8_t)BIT(0))
#define SPI_INT_TXO                  ((uint8_t)BIT(1))
#define SPI_INT_RXU                  ((uint8_t)BIT(2))
#define SPI_INT_RXO                  ((uint8_t)BIT(3))
#define SPI_INT_RXF                  ((uint8_t)BIT(4))
#define SPI_INT_MST                  ((uint8_t)BIT(5))
#define SPI_INT_TUF                  ((uint8_t)BIT(6))
#define SPI_INT_RIG                  ((uint8_t)BIT(7))

#define IS_SPI_CONFIG_IT(IT) (((IT) == SPI_INT_TXE) || \
                              ((IT) == SPI_INT_TXO) || \
                              ((IT) == SPI_INT_RXU) || \
                              ((IT) == SPI_INT_RXO) || \
                              ((IT) == SPI_INT_RXF) || \
                              ((IT) == SPI_INT_MST) || \
                              ((IT) == SPI_INT_TUF) || \
                              ((IT) == SPI_INT_RIG) )
/**
  * @}
  */

/** @defgroup SPI_GDMA_transfer_requests  SPI GDMA transfer requests
  * @{
  */

#define SPI_GDMAReq_Tx               ((uint16_t)0x0002)
#define SPI_GDMAReq_Rx               ((uint16_t)0x0001)
#define IS_SPI_GDMAREQ(GDMAREQ) ((((GDMAREQ) & (uint16_t)0xFFFC) == 0x00) && ((GDMAREQ) != 0x00))

/** End of group SPI_GDMA_transfer_requests
  * @}
  */

/** @defgroup SPI_GDMA_transfer_requests  SPI GDMA transfer requests
  * @{
  */

#define SPI_SWAP_ENABLE                ((uint32_t)0x0001)
#define SPI_SWAP_DISABLE               ((uint32_t)0x0000)
#define IS_SPI_SWAPMODE(mode) (((mode) == SPI_SWAP_ENABLE) || \
                               ((mode) == SPI_SWAP_DISABLE))

/** End of group SPI_GDMA_transfer_requests
  * @}
  */

/** End of group SPI_Exported_Constants
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/


/** @defgroup SPI_Exported_functions SPI Exported Functions
 * @{
 */

/**
 * rtl876x_spi.h
 *
 * \brief   Deinitializes the SPIx peripheral registers to their default reset values.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     SPI_DeInit(SPI0);
 * }
 * \endcode
 */
void SPI_DeInit(SPI_TypeDef *SPIx);

/**
 * rtl876x_spi.h
 *
 * \brief   Initializes the SPIx peripheral according to the specified
 *          parameters in the SPI_InitStruct.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 * \param[in] SPI_InitStruct: Pointer to a SPI_InitTypeDef structure that
 *            contains the configuration information for the specified SPI peripheral.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);
 *
 *     SPI_InitTypeDef  SPI_InitStruct;
 *     SPI_StructInit(&SPI_InitStruct);
 *
 *     SPI_InitStruct.SPI_Direction   = SPI_Direction_EEPROM;
 *     SPI_InitStruct.SPI_Mode        = SPI_Mode_Master;
 *     SPI_InitStruct.SPI_DataSize    = SPI_DataSize_8b;
 *     SPI_InitStruct.SPI_CPOL        = SPI_CPOL_High;
 *     SPI_InitStruct.SPI_CPHA        = SPI_CPHA_2Edge;
 *     SPI_InitStruct.SPI_BaudRatePrescaler  = 100;
 *     SPI_InitStruct.SPI_RxThresholdLevel  = 1 - 1;
 *     SPI_InitStruct.SPI_FrameFormat = SPI_Frame_Motorola;
 *
 *     SPI_Init(SPI0, &SPI_InitStruct);
 * }
 * \endcode
 */
void SPI_Init(SPI_TypeDef *SPIx, SPI_InitTypeDef *SPI_InitStruct);

/**
 * rtl876x_spi.h
 *
 * \brief  Fills each SPI_InitStruct member with its default value.
 *
 * \param[in]  SPI_InitStruct: Pointer to a SPI_InitTypeDef structure which will be initialized.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);
 *
 *     SPI_InitTypeDef  SPI_InitStruct;
 *     SPI_StructInit(&SPI_InitStruct);
 *
 *     SPI_InitStruct.SPI_Direction   = SPI_Direction_EEPROM;
 *     SPI_InitStruct.SPI_Mode        = SPI_Mode_Master;
 *     SPI_InitStruct.SPI_DataSize    = SPI_DataSize_8b;
 *     SPI_InitStruct.SPI_CPOL        = SPI_CPOL_High;
 *     SPI_InitStruct.SPI_CPHA        = SPI_CPHA_2Edge;
 *     SPI_InitStruct.SPI_BaudRatePrescaler  = 100;
 *     SPI_InitStruct.SPI_RxThresholdLevel  = 1 - 1;
 *     SPI_InitStruct.SPI_FrameFormat = SPI_Frame_Motorola;
 *
 *     SPI_Init(SPI0, &SPI_InitStruct);
 * }
 * \endcode
 */
void SPI_StructInit(SPI_InitTypeDef *SPI_InitStruct);

/**
 * rtl876x_spi.h
 *
 * \brief     Set SPI prescaler value.
 *
 * \note      Fsclk_out = Fssi_clk/prescaler use this api to get spi sclk. before use this api spi should be disable first.
 * \note      The communication clock is derived from the master clock. The slave clock does not need to be set.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 * \param[in] prescaler: any even value is between 2 and 65534, means the prescaler of spi clk source, clk source is 40Mhz by default.
 *            Specifies the speed of SCK clock. SPI Clock Speed = clk source/prescaler.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define SPI_PRESCALER_VALUE     100
 * void driver_rtc_init(void)
 * {
 *     SPI_SetPrescaler(SPI0, SPI_PRESCALER_VALUE);
 * }
 * \endcode
 */
void SPI_SetPrescaler(SPI_TypeDef *SPIx, uint16_t prescaler);

/**
 * rtl876x_spi.h
 *
 * \brief  Enables or disables the selected SPI peripheral.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 * \param[in] NewState: New state of the SPIx peripheral.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable the selected SPI peripheral.
 *            \arg DISABLE: Disable the selected SPI peripheral.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     SPI_Init(SPI0, &SPI_InitStruct);
 *     SPI_Cmd(SPI0, ENABLE);
 * }
 * \endcode
 */
void SPI_Cmd(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * rtl876x_spi.h
 *
 * \brief  Transmits a number of bytes through the SPIx peripheral.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 * \param[in] pBuf: Bytes to be transmitted.
 * \param[in] len: Byte length to be transmitted.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint8_t data_buf[] = {0x01,0x02,0x03};
 *     SPI_SendBuffer(SPI0, data_buf, sizeof(data_buf));
 * }
 * \endcode
 */
void SPI_SendBuffer(SPI_TypeDef *SPIx, uint8_t *pBuf, uint16_t len);

/**
 * rtl876x_spi.h
 *
 * \brief  Transmits a number of words through the SPIx peripheral.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 * \param[in] pBuf: Words to be transmitted.
 * \param[in] len: Word length to be transmitted.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint32_t data_buf[] = {0x01020304,0x02030405,0x03040506};
 *     SPI_SendWord(SPI0, data_buf, sizeof(data_buf));
 * }
 * \endcode
 */
void SPI_SendWord(SPI_TypeDef *SPIx, uint32_t *pBuf, uint16_t len);

/**
 * rtl876x_spi.h
 *
  * \brief  Transmits a number of halfWords through the SPIx peripheral.
  *
  * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
  * \param[in] pBuf: Halfwords to be transmitted.
  * \param[in] len: Halfwords length to be transmitted.
  *
  * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint16_t data_buf[] = {0x0102,0x0203,0x0304};
 *     SPI_SendHalfWord(SPI0, data_buf, sizeof(data_buf));
 * }
 * \endcode
  */
void SPI_SendHalfWord(SPI_TypeDef *SPIx, uint16_t *pBuf, uint16_t len);

/**
 * rtl876x_spi.h
 *
 * \brief  Enable or disable the specified SPI interrupt source.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 * \param[in] SPI_IT: Specifies the SPI interrupt source to be enabled or disabled.
 *            This parameter can be one of the following values:
 *            \arg SPI_INT_TXE: Transmit FIFO empty interrupt source.
 *            \arg SPI_INT_TXO: Transmit FIFO overflow interrupt source.
 *            \arg SPI_INT_RXU: Receive FIFO underflow interrupt source.
 *            \arg SPI_INT_RXO: Receive FIFO overflow interrupt source.
 *            \arg SPI_INT_RXF: Receive FIFO full interrupt source.
 *            \arg SPI_INT_MST: Multi-Master contention interrupt source.
 *            \arg SPI_INT_TUF: Transmit FIFO underflow interrupt source.
 * \param[in] NewState: New state of the specified SPI interrupt source.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable the specified SPI interrupt source.
 *            \arg DISABLE: Disable the specified SPI interrupt source.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     SPI_INTConfig(SPI0, SPI_INT_RXF, ENABLE);
 *     RamVectorTableUpdate(SPI0_VECTORn, (IRQ_Fun)SPI0_Handler);
 * }
 * \endcode
 */
void SPI_INTConfig(SPI_TypeDef *SPIx, uint8_t SPI_IT, FunctionalState NewState);

/**
 * rtl876x_spi.h
 *
 * \brief  Clear the specified SPI interrupt pending bit.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 * \param[in] SPI_IT: Specifies the SPI interrupt to clear.
 *            This parameter can be one of the following values:
 *            \arg SPI_INT_TXE: Transmit FIFO empty interrupt source.
 *            \arg SPI_INT_TXO: Transmit FIFO overflow interrupt source.
 *            \arg SPI_INT_RXU: Receive FIFO underflow interrupt source.
 *            \arg SPI_INT_RXO: Receive FIFO overflow interrupt source.
 *            \arg SPI_INT_RXF: Receive FIFO full interrupt source.
 *            \arg SPI_INT_MST: Multi-Master contention interrupt source.
 *            \arg SPI_INT_TUF: Transmit FIFO underflow interrupt source.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_handler(void)
 * {
 *     SPI_ClearINTPendingBit(SPI0, SPI_INT_RXF);
 * }
 * \endcode
 */
void SPI_ClearINTPendingBit(SPI_TypeDef *SPIx, uint16_t SPI_IT);

/**
 * rtl876x_spi.h
 *
 * \brief  Transmits a data through the SPIx peripheral.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 * \param[in] Data: Data to be transmitted.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint32_t data = 0x01020304;
 *     SPI_SendData(SPI0, data);
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE void SPI_SendData(SPI_TypeDef *SPIx, uint32_t Data)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    SPIx->DR[0] = Data;
    while (!(SPIx->SR & BIT(1)));
}

/**
 * rtl876x_spi.h
 *
 * \brief   Returns the most recent received data by the SPIx/I2Sx peripheral.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 *
 * \retval  The value of the received data.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_handler(void)
 * {
 *     if (SPI_GetINTStatus(SPI0, SPI_INT_RXF) == SET)
 *     {
 *         len = SPI_GetRxFIFOLen(SPI0);
 *         for (idx = 0; idx < len; idx++)
 *         {
 *             SPI_ReadINTBuf[idx] = SPI_ReceiveData(SPI0);
 *         }
 *     }
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE uint32_t SPI_ReceiveData(SPI_TypeDef *SPIx)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    return (uint32_t)SPIx->DR[0];
}

/**
 * rtl876x_spi.h
 *
 * \brief   Read data length in Rx FIFO through the SPIx peripheral.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 *
 * \return  Data length in Rx FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_handler(void)
 * {
 *     if (SPI_GetINTStatus(SPI0, SPI_INT_RXF) == SET)
 *     {
 *         len = SPI_GetRxFIFOLen(SPI0);
 *         //add user code here.
 *     }
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE uint8_t SPI_GetRxFIFOLen(SPI_TypeDef *SPIx)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    return (uint8_t)SPIx->RXFLR;
}

/**
 * rtl876x_spi.h
 *
 * \brief   Read data length in Tx FIFO through the SPIx peripheral.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 *
 * \return  Data length in Tx FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint8_t data_len = SPI_GetTxFIFOLen(SPI0);
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE uint8_t SPI_GetTxFIFOLen(SPI_TypeDef *SPIx)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    return (uint8_t)SPIx->TXFLR;
}

/**
 * rtl876x_spi.h
 *
 * \brief   Change SPI direction mode.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 *
 * \param[in] dir: parameter of direction mode, please refer to "SPI Data Direction" part.
 *            This parameter can be one of the following values:
 *            \arg SPI_Direction_FullDuplex: Data can be transmitted and received at the same time.
 *            \arg SPI_Direction_TxOnly: Data can only be transmitted at a time.
 *            \arg SPI_Direction_RxOnly: Data can only be received at a time.
 *            \arg SPI_Direction_EEPROM: Send data first to read target numbers of data.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_ChangeDirection(SPI0, SPI_Direction_EEPROM);
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE void SPI_ChangeDirection(SPI_TypeDef *SPIx, uint16_t dir)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_DIRECTION_MODE(dir));

    /* Disable the selected SPI peripheral */
    SPIx->SSIENR &= ~0x01;

    /* Change SPI direction mode */
    SPIx->CTRLR0 &= ~(0x03 << 8);
    SPIx->CTRLR0 |= dir << 8;

    /* Enable the selected SPI peripheral */
    SPIx->SSIENR |= 0x01;
}

/**
 * rtl876x_spi.h
 *
 * \brief   Set read Data length in EEPROM mode and RX only mode through the SPIx peripheral,which
            enables you to receive up to 64 KB of data in a continuous transfer.

 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 * \param[in] len: Length of read data which can be 1 to 65536.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_SetReadLen(SPI0, 100);
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE void SPI_SetReadLen(SPI_TypeDef *SPIx, uint16_t len)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    /* Disable the selected SPI peripheral */
    SPIx->SSIENR &= ~0x01;
    /* set read length in SPI EEPROM mode */
    SPIx->CTRLR1 = len - 1;
    /* Enable the selected SPI peripheral */
    SPIx->SSIENR |= 0x01;
}

/**
 * rtl876x_spi.h
 *
 * \brief   Set cs number through the SPIx peripheral.
 *          before call this function please make sure the SPIx been initialized.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 * \param[in] number: If SPIx is SPI0, number must be 0. If SPIx is SPI1, number can be 0 to 2.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_SetCSNumber(SPI1, 0);
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE void SPI_SetCSNumber(SPI_TypeDef *SPIx, uint8_t number)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    /* set cs number */
    SPIx->SER = BIT(number);
}

/**
 * rtl876x_spi.h
 *
 * \brief  Check whether the specified SPI interrupt is set.
 *
 * \param[in]  SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 * \param[in]  SPI_IT: Specifies the SPI interrupt to check.
 *            This parameter can be one of the following values:
 *            \arg SPI_INT_TXE: Transmit FIFO empty interrupt source.
 *            \arg SPI_INT_TXO: Transmit FIFO overflow interrupt source.
 *            \arg SPI_INT_RXU: Receive FIFO underflow interrupt source.
 *            \arg SPI_INT_RXO: Receive FIFO overflow interrupt source.
 *            \arg SPI_INT_RXF: Receive FIFO full interrupt source.
 *            \arg SPI_INT_MST: Multi-Master contention interrupt source.
 *            \arg SPI_INT_TUF: Transmit FIFO underflow interrupt source.
 *
 * \return The new state of SPI_IT.
 * \retval SET: The specified SPI interrupt is set.
 * \retval RESET: The specified SPI interrupt is unset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_handler(void)
 * {
 *     if (SPI_GetINTStatus(SPI0, SPI_INT_RXF) == SET)
 *     {
 *         //add user code here.
 *     }
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE ITStatus SPI_GetINTStatus(SPI_TypeDef *SPIx, uint32_t SPI_IT)
{
    ITStatus bit_status = RESET;

    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_CONFIG_IT(SPI_IT));

    if ((SPIx->ISR & SPI_IT) != (uint32_t)RESET)
    {
        bit_status = SET;
    }

    /* Return the SPI_IT status */
    return  bit_status;
}

/**
 * rtl876x_spi.h
 *
 * \brief  Check whether the specified SPI flag is set or not.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 * \param[in] SPI_FLAG: Specifies the SPI flag to check.
 *            This parameter can be one of the following values:
 *            \arg SPI_FLAG_DCOL: Data Collision Error flag.Set if it is actively transmitting in master mode when another master selects this device as a slave.
 *            \arg SPI_FLAG_TXE: Transmission error flag.Set if the transmit FIFO is empty when a transfer is started in slave mode.
 *            \arg SPI_FLAG_RFF: Receive FIFO full flag. Set if the receive FIFO is completely full.
 *            \arg SPI_FLAG_RFNE: Receive FIFO Not Empty flag.Set if receive FIFO is not empty.
 *            \arg SPI_FLAG_TFE: Transmit FIFO Empty flag.Set if transmit FIFO is empty.
 *            \arg SPI_FLAG_TFNF: Transmit FIFO Not Full flag.Set if transmit FIFO is not full.
 *            \arg SPI_FLAG_BUSY: SPI Busy flag.Set if it is actively transferring data.reset if it is idle or disabled.
 *
 * \return The new state of SPI_FLAG.
 * \retval SET: The specified SPI flag is set.
 * \retval RESET: The specified SPI flag is unset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_WriteBuf[0] = 0x9f;
 *     SPI_SendBuffer(SPI1, SPI_WriteBuf, 4);
 *
 *     //Waiting for SPI data transfer to end
 *     while (SPI_GetFlagState(SPI1, SPI_FLAG_BUSY));
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE FlagStatus SPI_GetFlagState(SPI_TypeDef *SPIx, uint8_t SPI_FLAG)
{
    FlagStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_GET_FLAG(SPI_FLAG));

    /* Check the status of the specified SPI flag */
    if ((SPIx->SR & SPI_FLAG) != (uint8_t)RESET)
    {
        /* SPI_FLAG is set */
        bitstatus = SET;
    }

    /* Return the SPI_FLAG status */
    return  bitstatus;
}

/**
 * rtl876x_spi.h
 *
 * \brief   Enable or disable the SPIx GDMA interface.
 *
 * \param[in] SPIx: Where x can be 0 to 2 to select the SPI peripheral.
 * \param[in] SPI_GDMAReq: Specifies the SPI GDMA transfer request to be enabled or disabled.
 *            This parameter can be one of the following values:
 *            \arg SPI_GDMAReq_Tx: Tx buffer DMA transfer request.
 *            \arg SPI_GDMAReq_Rx: Rx buffer DMA transfer request.
 * \param[in]  NewState: New state of the selected SPI GDMA transfer request.
 *             This parameter can be one of the following values:
 *             \arg ENABLE: Enable the SPIx GDMA interface.
 *             \arg DISABLE: Disable the SPIx GDMA interface.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_GDMACmd(SPI0, SPI_GDMAReq_Tx, ENABLE);
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE void SPI_GDMACmd(SPI_TypeDef *SPIx, uint16_t SPI_GDMAReq,
                                        FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    assert_param(IS_SPI_GDMAREQ(SPI_GDMAReq));

    if (NewState != DISABLE)
    {
        /* Enable the selected SPI GDMA request */
        SPIx->DMACR |= SPI_GDMAReq;
    }
    else
    {
        /* Disable the selected SPI GDMA request */
        SPIx->DMACR &= (uint16_t)~(SPI_GDMAReq);
    }
}


#ifdef __cplusplus
}
#endif

#endif /*__RTL876X_SPI_H*/

/** @} */ /* End of group SPI_Exported_Functions */
/** @} */ /* End of group 87x3d_SPI */

/******************* (C) COPYRIGHT 2015 Realtek Semiconductor Corporation *****END OF FILE****/

