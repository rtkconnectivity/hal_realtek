/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL876X_SPI_H
#define RTL876X_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_spi_master_def.h"
#include "rtl876x_spi_master_jdi_def.h"
#include "rtl876x_spi_slave_def.h"

/** @addtogroup 87x3g_SPI SPI
  * @brief SPI driver module.
  * @{
  */
/*============================================================================*
 *                         Constants
 *============================================================================*/
/** @defgroup 87x3g_SPI_Exported_Constants SPI Exported Constants
  * @{
  */

/**
 * \defgroup    87x3g_SPI_clock_speed SPI Clock Speed
 * \{
 */
#define IS_SPI_CLOCK_SPEED(SPEED) (((SPEED) >= 0x01) && \
                                   ((SPEED) <= 50000000)) //!< SPI clock speed is between 1 and 50000000.

/** End of 87x3g_SPI_clock_speed
  * \}
  */

/**
 * \defgroup    87x3g_SPI_data_direction SPI Data Direction
 * \{
 */
typedef enum
{
    SPI_Direction_FullDuplex = 0x00, //!< Data can be transmitted and received at the same time.
    SPI_Direction_TxOnly     = 0x01, //!< Data can only be transmitted at a time.
    SPI_Direction_RxOnly     = 0x02, //!< Data can only be received at a time.
    SPI_Direction_EEPROM     = 0x03, //!< Send data first to read target numbers of data.
} SPIDataDirection_TypeDef;

#define IS_SPI_DIRECTION_MODE(MODE) (((MODE) == SPI_Direction_FullDuplex) || \
                                     ((MODE) == SPI_Direction_RxOnly) || \
                                     ((MODE) == SPI_Direction_TxOnly) || \
                                     ((MODE) == SPI_Direction_EEPROM)) //!< Check if the input parameter is valid.

/** End of 87x3g_SPI_data_direction
  * \}
  */

/**
 * \defgroup    87x3g_SPI_data_size SPI Data Size
 * \{
 */
typedef enum
{
    SPI_DataSize_4b  = 0x03, //!< The data frame size is programmed to 4bits.
    SPI_DataSize_5b  = 0x04, //!< The data frame size is programmed to 5bits.
    SPI_DataSize_6b  = 0x05, //!< The data frame size is programmed to 6bits.
    SPI_DataSize_7b  = 0x06, //!< The data frame size is programmed to 7bits.
    SPI_DataSize_8b  = 0x07, //!< The data frame size is programmed to 8bits.
    SPI_DataSize_9b  = 0x08, //!< The data frame size is programmed to 9bits.
    SPI_DataSize_10b = 0x09, //!< The data frame size is programmed to 10bits.
    SPI_DataSize_11b = 0x0a, //!< The data frame size is programmed to 11bits.
    SPI_DataSize_12b = 0x0b, //!< The data frame size is programmed to 12bits.
    SPI_DataSize_13b = 0x0c, //!< The data frame size is programmed to 13bits.
    SPI_DataSize_14b = 0x0d, //!< The data frame size is programmed to 14bits.
    SPI_DataSize_15b = 0x0e, //!< The data frame size is programmed to 15bits.
    SPI_DataSize_16b = 0x0f, //!< The data frame size is programmed to 16bits.
#if (!SPI_SUPPORT_DFS_4BIT_TO_16BIT)
    SPI_DataSize_17b = 0x10, //!< The data frame size is programmed to 17bits.
    SPI_DataSize_18b = 0x11, //!< The data frame size is programmed to 18bits.
    SPI_DataSize_19b = 0x12, //!< The data frame size is programmed to 19bits.
    SPI_DataSize_20b = 0x13, //!< The data frame size is programmed to 20bits.
    SPI_DataSize_21b = 0x14, //!< The data frame size is programmed to 21bits.
    SPI_DataSize_22b = 0x15, //!< The data frame size is programmed to 22bits.
    SPI_DataSize_23b = 0x16, //!< The data frame size is programmed to 23bits.
    SPI_DataSize_24b = 0x17, //!< The data frame size is programmed to 24bits.
    SPI_DataSize_25b = 0x18, //!< The data frame size is programmed to 25bits.
    SPI_DataSize_26b = 0x19, //!< The data frame size is programmed to 26bits.
    SPI_DataSize_27b = 0x1A, //!< The data frame size is programmed to 27bits.
    SPI_DataSize_28b = 0x1B, //!< The data frame size is programmed to 28bits.
    SPI_DataSize_29b = 0x1C, //!< The data frame size is programmed to 29bits.
    SPI_DataSize_30b = 0x1D, //!< The data frame size is programmed to 30bits.
    SPI_DataSize_31b = 0x1E, //!< The data frame size is programmed to 31bits.
    SPI_DataSize_32b = 0x1F, //!< The data frame size is programmed to 32bits.
#endif
} SPIDataSize_TypeDef;

#if (!SPI_SUPPORT_DFS_4BIT_TO_16BIT)
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
                                   ((DATASIZE) == SPI_DataSize_32b)) //!< Check if the input parameter is valid.
#else
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
                                   ((DATASIZE) == SPI_DataSize_16b)) //!< Check if the input parameter is valid.
#endif


/** End of 87x3g_SPI_data_size
  * \}
  */

/**
 * \defgroup    87x3g_SPI_Clock_Polarity SPI Clock Polarity
 * \{
 */
typedef enum
{
    SPI_CPOL_Low = 0x00, //!< Inactive state of serial clock is low.
    SPI_CPOL_High = 0x01, //!< Inactive state of serial clock is high.
} SPIClockPolarity_TypeDef;

#define IS_SPI_CPOL(CPOL) (((CPOL) == SPI_CPOL_Low) || \
                           ((CPOL) == SPI_CPOL_High)) //!< Check if the input parameter is valid.

/** End of 87x3g_SPI_Clock_Polarity
  * \}
  */

/**
 * \defgroup    87x3g_SPI_Clock_Phase SPI Clock Phase
 * \{
 */
typedef enum
{
    SPI_CPHA_1Edge = 0x00, //!< Serial clock toggles in middle of first data bit.
    SPI_CPHA_2Edge = 0x01, //!< Serial clock toggles at start of first data bit.
} SPIClockPhase_TypeDef;

#define IS_SPI_CPHA(CPHA) (((CPHA) == SPI_CPHA_1Edge) || \
                           ((CPHA) == SPI_CPHA_2Edge)) //!< Check if the input parameter is valid.

/** End of 87x3g_SPI_Clock_Phase
  * \}
  */

/**
 * \defgroup    87x3g_SPI_BaudRate_Prescaler_Value SPI BaudRate Prescaler Value
 * \{
 */
#define SPI_BaudRatePrescaler_2      0x02 //!< SPI baud rate prescaler value is 2.
#define SPI_BaudRatePrescaler_4      0x04 //!< SPI baud rate prescaler value is 4.
#define SPI_BaudRatePrescaler_6      0x06 //!< SPI baud rate prescaler value is 6.
#define SPI_BaudRatePrescaler_8      0x08 //!< SPI baud rate prescaler value is 8.
#define SPI_BaudRatePrescaler_10     0x0A //!< SPI baud rate prescaler value is 10.
#define SPI_BaudRatePrescaler_12     0x0C //!< SPI baudrate prescaler value is 12.
#define SPI_BaudRatePrescaler_14     0x0E //!< SPI baud rate prescaler value is 14.
#define SPI_BaudRatePrescaler_16     0x10 //!< SPI baud rate prescaler value is 16.
#define SPI_BaudRatePrescaler_32     0x20 //!< SPI baud rate prescaler value is 32.
#define SPI_BaudRatePrescaler_64     0x40 //!< SPI baud rate prescaler value is 64.
#define SPI_BaudRatePrescaler_128    0x80 //!< SPI baud rate prescaler value is 128.
#define SPI_BaudRatePrescaler_256    0x100 //!< SPI baud rate prescaler value is 256.

#define IS_SPI_BAUDRATE_PRESCALER(PRESCALER) ((PRESCALER) <= 0xFFFF) //!< SPI baudRate prescaler value must less then 0xFFFF.

/** End of 87x3g_SPI_BaudRate_Prescaler_Value
  * \}
  */

/**
 * \defgroup    87x3g_SPI_Swap_Enable SPI Swap Enable
 * \{
 */
#define IS_SPI_SWAPMODE(mode) (((mode) == DISABLE) || \
                               ((mode) == ENABLE)) //!< Check if the SPI swap mode config is valid.

/** End of 87x3g_SPI_Swap_Enable
  * \}
  */

/**
 * \defgroup    87x3g_SPI_frame_format SPI Frame Format
 * \{
 */
typedef enum
{
    SPI_Frame_Motorola      = 0x00, //!< Standard SPI frame format.
    SPI_Frame_TI_SSP        = 0x01, //!< Texas instruments SSP frame format.
    SPI_Frame_NS_MICROWIRE  = 0x02, //!< National microwire frame format.
    SPI_Frame_Reserve       = 0x03, //!< Reserved value.
} SPIFrameFormat_TypeDef;

#define IS_SPI_FRAME_FORMAT(FRAME) (((FRAME) == SPI_Frame_Motorola) || \
                                    ((FRAME) == SPI_Frame_TI_SSP) || \
                                    ((FRAME) == SPI_Frame_NS_MICROWIRE) || \
                                    ((FRAME) == SPI_Frame_Reserve)) //!< Check if the input parameter is valid.

/** End of 87x3g_SPI_frame_format
  * \}
  */

/**
 * \defgroup    87x3g_SPI_GDMA_transfer_requests SPI GDMA Transfer Request
 * \{
 */
typedef enum
{
    SPI_GDMAReq_Rx = 0x01, //!< TX buffer GDMA transfer request.
    SPI_GDMAReq_Tx = 0x02, //!< RX buffer GDMA transfer request.
} SPIGdmaTransferRequests_TypeDef;

#define IS_SPI_GDMAREQ(GDMAREQ) (((GDMAREQ)  == SPI_GDMAReq_Rx) || \
                                 ((GDMAREQ) == SPI_GDMAReq_Tx)) //!< Check if the input parameter is valid.

/** End of 87x3g_SPI_GDMA_transfer_requests
  * \}
  */

/**
 * \defgroup    87x3g_SPI_flags_definition SPI Flags Definition
 * \{
 */
#define SPI_FLAG_BUSY                   BIT0 //!< SPI Busy flag. Set if it is actively transferring data. Reset if it is idle or disabled.
#define SPI_FLAG_TFNF                   BIT1 //!< Transmit FIFO not full flag. Set if transmit FIFO is not full.
#define SPI_FLAG_TFE                    BIT2 //!< Transmit FIFO empty flag. Set if transmit FIFO is empty.
#define SPI_FLAG_RFNE                   BIT3 //!< Receive FIFO not empty flag. Set if receive FIFO is not empty.
#define SPI_FLAG_RFF                    BIT4 //!< Receive FIFO full flag. Set if the receive FIFO is completely full.
#define SPI_FLAG_TXE                    BIT5 //!< Transmission error flag. Set if the transmit FIFO is empty when a transfer is started in slave mode.
#define SPI_FLAG_DCOL                   BIT6 //!< Data collision error flag. Set if it is actively transmitting in master mode when another master selects this device as a slave.
#if (SPI_SUPPORT_WRAP_MODE == 1) || (SPI1_SUPPORT_WRAP_MODE == 1)
#define SPI_FLAG_WRAP_CS_EN             BIT8 //!< SPI wrap CS enable flag. When set, indicates that the chip select signal is active.
#define SPI_FLAG_WRAP_TFNF              BIT9 //!< SPI wrap transmit FIFO not full flag. Set when the transmit FIFO contains one or more empty locations, and is cleared when the FIFO is full.
#define SPI_FLAG_WRAP_TFE               BIT10 //!< SPI wrap transmit FIFO empty flag. When the transmit FIFO is completely empty, this bit is set. 
#endif

#if (SPI_SUPPORT_WRAP_MODE == 1) || (SPI1_SUPPORT_WRAP_MODE == 1)
#define IS_SPI_GET_FLAG(FLAG)   (((FLAG) == SPI_FLAG_DCOL) || \
                                 ((FLAG) == SPI_FLAG_TXE) || \
                                 ((FLAG) == SPI_FLAG_RFF) || \
                                 ((FLAG) == SPI_FLAG_RFNE) || \
                                 ((FLAG) == SPI_FLAG_TFE) || \
                                 ((FLAG) == SPI_FLAG_TFNF) || \
                                 ((FLAG) == SPI_FLAG_BUSY) || \
                                 ((FLAG) == SPI_FLAG_WRAP_CS_EN) || \
                                 ((FLAG) == SPI_FLAG_WRAP_TFNF) || \
                                 ((FLAG) == SPI_FLAG_WRAP_TFE)) //!< Check if the input parameter is valid.
#else
#define IS_SPI_GET_FLAG(FLAG)   (((FLAG) == SPI_FLAG_DCOL) || \
                                 ((FLAG) == SPI_FLAG_TXE) || \
                                 ((FLAG) == SPI_FLAG_RFF) || \
                                 ((FLAG) == SPI_FLAG_RFNE) || \
                                 ((FLAG) == SPI_FLAG_TFE) || \
                                 ((FLAG) == SPI_FLAG_TFNF) || \
                                 ((FLAG) == SPI_FLAG_BUSY)) //!< Check if the input parameter is valid.
#endif
/** End of 87x3g_SPI_flags_definition
  * \}
  */

/**
 * \defgroup    87x3g_SPI_interrupts_definition SPI Interrupts Definition
 * \{
 */
#define SPI_INT_TXE                    BIT0 /**< Transmit FIFO empty interrupt. The TX FIFO is equal to or below its threshold value and requires service to prevent an under-run. */
#define SPI_INT_TXO                    BIT1 /**< Transmit FIFO overflow interrupt. An APB access attempts to write into the TX FIFO after it has been completely filled. When set, data written from the APB is discarded. */
#define SPI_INT_RXU                    BIT2 /**< Receive FIFO underflow interrupt. An APB access attempts to read from the RX FIFO when it is empty. When set, zeros are read back from the RX FIFO. */
#define SPI_INT_RXO                    BIT3 /**< Receive FIFO overflow interrupt. The receive logic attempts to place data into the RX FIFO after it has been completely filled. When set, newly received data are discarded. */
#define SPI_INT_RXF                    BIT4 /**< Receive FIFO full interrupt. RX FIFO is equal to or above its threshold value plus 1 and requires service to prevent an overflow. */
#define SPI_INT_MST                    BIT5 /**< Multi-Master contention interrupt, only for master. The interrupt is set when another serial master on the serial bus selects the SPI master as a serial-slave device and is actively transferring data. */
#define SPI_INT_FAE                    BIT5 /**< TX frame alignment interrupt, only for slave. The data received by the slave does not match data frame size. */
#define SPI_INT_TUF                    BIT6 /**< Transmit FIFO underflow interrupt, only for slave. Clocks sent by the master when the slave is at the empty FIFO level. */
#define SPI_INT_RIG                    BIT7 /**< CS rising edge detect interrupt, only for slave. CS line has a rising edge. */
#if (SPI_SUPPORT_WRAP_MODE == 1) || (SPI1_SUPPORT_WRAP_MODE == 1)
#define SPI_INT_WRAP_TXE               BIT8 //!< Transmit FIFO empty interrupt. The TX wrapper FIFO is equal to or below its threshold value and requires service to prevent an under-run.
#define SPI_INT_WRAP_TXO               BIT9 //!< Transmit FIFO overflow interrupt. An APB access attempts to write into the TX wrapper FIFO after it has been completely filled. 
#define SPI_INT_WRAP_TXD               BIT10 //!< Transmit done when TX NDF is reached.
#endif

#if (SPI_SUPPORT_WRAP_MODE == 1) || (SPI1_SUPPORT_WRAP_MODE == 1)
#define IS_SPI_CONFIG_IT(IT) (((IT) == SPI_INT_TXE) || \
                              ((IT) == SPI_INT_TXO) || \
                              ((IT) == SPI_INT_RXU) || \
                              ((IT) == SPI_INT_RXO) || \
                              ((IT) == SPI_INT_RXF) || \
                              ((IT) == SPI_INT_MST) || \
                              ((IT) == SPI_INT_FAE) || \
                              ((IT) == SPI_INT_TUF) || \
                              ((IT) == SPI_INT_RIG) || \
                              ((IT) == SPI_INT_WRAP_TXE) || \
                              ((IT) == SPI_INT_WRAP_TXO) || \
                              ((IT) == SPI_INT_WRAP_TXD)) //!< Check if the input parameter is valid.
#else
#define IS_SPI_CONFIG_IT(IT) (((IT) == SPI_INT_TXE) || \
                              ((IT) == SPI_INT_TXO) || \
                              ((IT) == SPI_INT_RXU) || \
                              ((IT) == SPI_INT_RXO) || \
                              ((IT) == SPI_INT_RXF) || \
                              ((IT) == SPI_INT_MST) || \
                              ((IT) == SPI_INT_FAE) || \
                              ((IT) == SPI_INT_TUF) || \
                              ((IT) == SPI_INT_RIG) ) //!< Check if the input parameter is valid.
#endif

/** End of 87x3g_SPI_interrupts_definition
  * \}
  */

#if (SPI0_SUPPORT_MASTER_SLAVE == 1)

/**
 * \defgroup    87x3g_SPI_mode SPI Mode
 * \{
 */
typedef enum
{
    SPI_Mode_Master = ((uint16_t)0x0104), //!< SPI device operating mode as master.
    SPI_Mode_Slave  = ((uint16_t)0x0000) //!< SPI device operating mode as slave.
} SPIMode_Typedef;

#define IS_SPI_MODE(MODE) (((MODE) == SPI_Mode_Master) || \
                           ((MODE) == SPI_Mode_Slave)) //!< Check if the input parameter is valid.

/** End of 87x3g_SPI_mode
  * \}
  */
#endif


#if SPI_SUPPORT_RAP_FUNCTION
/**
 * \defgroup    87x3g_SPI_Task_Event SPI Task Event
 * \{
 */
typedef enum
{
    SPI_TASK_START  = 0,
    SPI_EVENT_START = 1,
    SPI_EVENT_END   = 2,
} SPITaskEvent_TypeDef;
/** End of 87x3g_SPI_Task_Event
  * \}
  */
#endif

/** End of group 87x3g_SPI_Exported_Constants
  * @}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** @defgroup 87x3g_SPI_Exported_Types SPI Exported Types
  * @{
  */

/**
 * \brief       SPI init structure definition.
 */
typedef struct
{
    SPIDataDirection_TypeDef
    SPI_Direction;        /*!< Specifies the SPI unidirectional or bidirectional data mode.
                                                    This parameter can be a value of @ref x3g_SPI_data_direction. */
#if (SPI_SUPPORT_WRAP_MODE == 1) || (SPI1_SUPPORT_WRAP_MODE == 1)
    uint32_t SPI_TXNDF;                        /*!< Specifies the trigger condition in TX only or fullduplex mode.
                                                    This parameter sets the number of data frames to be continuously transmitted,
                                                    from 1 to 65536. */
    FunctionalState SPI_CSHighActiveEn;        /*!< Specifies whether to enable CS high active.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_WrapModeEn;         /*!< Specifies the TX wrapper mode (TX NDF) enable.
                                                    Only SPI1 have txndf mode.
                                                    ENABLE: Hardware won't automatically pull
                                                    SPI_CSN high when TX FIFO is empty.
                                                    DISABLE: SPI_CSN pull high when
                                                    TX data number = SPI_TXNDF + 1.*/

    FunctionalState
    SPI_WrapModeDmaEn;      /*!< Specifies the TX wrapper mode(TX NDF) DMA enable. This parameter can be a value of ENABLE or DISABLE.*/

    uint8_t  SPI_TxNdfWaterlevel;              /*!< Specifies the TX NDF DMA water level. This parameter can be a value less than 32.*/
#endif

    uint32_t SPI_NDF;                         /*!< Specifies the number of data frames in EEPROM and RX only mode.
                                                    This parameter should be the value of the length of read data. This parameter must range from 0x1 to 0xFFFFFFFF. */

#if (SPI0_SUPPORT_MASTER_SLAVE == 1)
    SPIMode_Typedef           SPI_Mode;       /*!< Specifies the SPI operating mode.
                                                    This parameter can be a value of @ref x3g_SPI_mode. */
#endif

    SPIDataSize_TypeDef SPI_DataSize;          /*!< Specifies the SPI data size.
                                                    This parameter can be a value of @ref x3g_SPI_data_size. */

    SPIClockPolarity_TypeDef SPI_CPOL;         /*!< Specifies the serial clock steady state.
                                                    This parameter can be a value of @ref x3g_SPI_Clock_Polarity. */

    SPIClockPhase_TypeDef SPI_CPHA;            /*!< Specifies the clock active edge for the bit capture.
                                                    This parameter can be a value of @ref x3g_SPI_Clock_Phase. */

    SPIFrameFormat_TypeDef
    SPI_FrameFormat;                            /*!< Specifies which serial protocol transfers the data.
                                                    This parameter can be a value of @ref x3g_SPI_frame_format. */

    uint32_t SPI_BaudRatePrescaler;            /*!< Specifies the speed of SCK clock. This parameter should be any even value between 2 and 65534.
                                                SPI Clock Speed = clk source/SPI_ClkDIV/SPI_BaudRatePrescaler,
                                                clk source is 40Mhz by default,
                                                SPI_ClkDIV refer to @ref x3g_SPI_Clock_Divider, set by API \ref SPI_ClkDivConfig.
                                                @note The communication clock is derived from the master
                                                clock. The slave clock does not need to be set. */

#if (SPI_SUPPORT_SWAP == 1)
    FunctionalState SPI_SwapTxBitEn;           /*!< Specifies whether to swap SPI TX data bit.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_SwapRxBitEn;           /*!< Specifies whether to swap SPI RX data bit.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_SwapTxByteEn;          /*!< Specifies whether to swap SPI TX data byte.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_SwapRxByteEn;          /*!< Specifies whether to swap SPI RX data byte.
                                                    This parameter can be a value of ENABLE or DISABLE. */
#endif

    FunctionalState
    SPI_ToggleEn;              /*!< Specifies whether CS to toggle between successive frames, default is DISABLE. This parameter can be a value of DISABLE or ENABLE.
                                                    ENABLE: CS toggle between successive frames.
                                                    DISABLE: CS does not toggle between successive frames.
                                                    Enable SPI_ToggleEn should make sure SPI_CPHA = 0(SPI_CPHA_1Edge). */

    uint32_t SPI_TxThresholdLevel;             /*!<  Specifies the transmit FIFO Threshold to trigger interrupt @ref SPI_INT_TXE or @ref SPI_INT_WRAP_TXE. This parameter can be a value less than TX FIFO depth, with SPI0/2 being 16, SPI1 being 32 and SPI slave being 64. */

    uint32_t SPI_RxThresholdLevel;             /*!< Specifies the receive FIFO Threshold to trigger interrupt @ref SPI_INT_RXF. This parameter can be a value less than RX FIFO depth, with SPI0/2 being 16, SPI1 being 32 and SPI slave being 64. */

    FunctionalState SPI_TxDmaEn;               /*!< Specifies the TX DMA mode.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_RxDmaEn;               /*!< Specifies the RX DMA mode.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint8_t SPI_TxWaterlevel;                  /*!< Specifies the DMA TX water level. This parameter can be a value less than 64. The best value is SPI_TxWaterlevel = SPI TX FIFO depth - SPI TX GDMA MSize. */

    uint8_t SPI_RxWaterlevel;                   /*!< Specifies the DMA RX water level. This parameter can be a value less than 64. The best value is SPI_RxWaterlevel = SPI RX GDMA MSize - 1. */
} SPI_InitTypeDef;

/** End of group 87x3g_SPI_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** @defgroup 87x3g_SPI_Exported_Functions SPI Exported Functions
 * @{
 */

/**
 * \brief   Disable the SPIx peripheral clock, and restore registers to their default values.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
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
 * \brief   Initializes the SPIx peripheral according to the specified
 *          parameters in the SPI_InitStruct.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] SPI_InitStruct: Pointer to a \ref SPI_InitTypeDef structure that
 *            contains the configuration information for the specified SPI peripheral.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);

 *     SPI_InitTypeDef  SPI_InitStruct;
 *     SPI_StructInit(&SPI_InitStruct);
 *
 *     SPI_InitStruct.SPI_Direction   = SPI_Direction_EEPROM;
 *     SPI_InitStruct.SPI_DataSize    = SPI_DataSize_8b;
 *     SPI_InitStruct.SPI_CPOL        = SPI_CPOL_High;
 *     SPI_InitStruct.SPI_CPHA        = SPI_CPHA_2Edge;
 *     SPI_InitStruct.SPI_BaudRatePrescaler  = 100;
 *     SPI_InitStruct.SPI_RxThresholdLevel  = 1 - 1;
 *     SPI_InitStruct.SPI_NDF               = 1 - 1;
 *     SPI_InitStruct.SPI_FrameFormat = SPI_Frame_Motorola;
 *
 *     SPI_Init(SPI0, &SPI_InitStruct);
 * }
 * \endcode
 */
void SPI_Init(SPI_TypeDef *SPIx, SPI_InitTypeDef *SPI_InitStruct);

/**
 * \brief  Fills each SPI_InitStruct member with its default value.
 *
 * \note   The default settings for the SPI_InitStruct member are shown in the following table:
 *         | SPI_InitStruct Member  | Default Value                  |
 *         |:----------------------:|:------------------------------:|
 *         | SPI_DataSize           | \ref SPI_DataSize_8b           |
 *         | SPI_FrameFormat        | \ref SPI_Frame_Motorola        |
 *         | SPI_Direction          | \ref SPI_Direction_FullDuplex  |
 *         | SPI_CPOL               | \ref SPI_CPOL_High             |
 *         | SPI_CPHA               | \ref SPI_CPHA_2Edge            |
 *         | SPI_BaudRatePrescaler  | 128                            |
 *         | SPI_TxThresholdLevel   | 1                              |
 *         | SPI_RxThresholdLevel   | 0                              |
 *         | SPI_RXNDF              | 1                              |
 *         | SPI_SwapRxBitEn        | DISABLE                        |
 *         | SPI_SwapTxBitEn        | DISABLE                        |
 *         | SPI_SwapRxByteEn       | DISABLE                        |
 *         | SPI_SwapTxByteEn       | DISABLE                        |
 *         | SPI_ToggleEn           | DISABLE                        |
 *         | SPI_RxDmaEn            | DISABLE                        |
 *         | SPI_TxDmaEn            | DISABLE                        |
 *         | SPI_RxWaterlevel       | 1                              |
 *         | SPI_TxWaterlevel       | SPI_TX_FIFO_SIZE - 1           |
 *         | SPI_TXNDF              | 1                              |
 *         | SPI_CSHighActiveEn     | DISABLE                        |
 *         | SPI_WrapModeEn         | DISABLE                        |
 *         | SPI_WrapModeDmaEn      | DISABLE                        |
 *         | SPI_TxNdfWaterlevel    | SPI_TX_FIFO_SIZE - 1           |
 *
 * \param[in]  SPI_InitStruct: Pointer to a \ref SPI_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *
 *     RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);

 *     SPI_InitTypeDef  SPI_InitStruct;
 *     SPI_StructInit(&SPI_InitStruct);
 *
 *     SPI_InitStruct.SPI_Direction   = SPI_Direction_EEPROM;
 *     SPI_InitStruct.SPI_DataSize    = SPI_DataSize_8b;
 *     SPI_InitStruct.SPI_CPOL        = SPI_CPOL_High;
 *     SPI_InitStruct.SPI_CPHA        = SPI_CPHA_2Edge;
 *     SPI_InitStruct.SPI_BaudRatePrescaler  = 100;
 *     SPI_InitStruct.SPI_RxThresholdLevel  = 1 - 1;
 *     SPI_InitStruct.SPI_NDF               = 1 - 1;
 *     SPI_InitStruct.SPI_FrameFormat = SPI_Frame_Motorola;
 *
 *     SPI_Init(SPI0, &SPI_InitStruct);
 * }
 * \endcode
 */
void SPI_StructInit(SPI_InitTypeDef *SPI_InitStruct);

/**
 * \brief  Enables or disables the selected SPI peripheral.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] NewState: New state of the SPIx peripheral.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the selected SPI peripheral, allowing it to begin data transfer operations.
 *            - DISABLE: Disable the selected SPI peripheral, all serial transfers are halted immediately.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *
 *     RCC_PeriphClockCmd(APBPeriph_SPI0, APBPeriph_SPI0_CLOCK, ENABLE);
 *
 *     SPI_InitTypeDef  SPI_InitStruct;
 *     SPI_StructInit(&SPI_InitStruct);
 *
 *     SPI_InitStruct.SPI_Direction   = SPI_Direction_EEPROM;
 *     SPI_InitStruct.SPI_DataSize    = SPI_DataSize_8b;
 *     SPI_InitStruct.SPI_CPOL        = SPI_CPOL_High;
 *     SPI_InitStruct.SPI_CPHA        = SPI_CPHA_2Edge;
 *     SPI_InitStruct.SPI_BaudRatePrescaler  = 100;
 *     SPI_InitStruct.SPI_RxThresholdLevel  = 1 - 1;
 *     SPI_InitStruct.SPI_NDF               = 1 - 1;
 *     SPI_InitStruct.SPI_FrameFormat = SPI_Frame_Motorola;
 *
 *     SPI_Init(SPI0, &SPI_InitStruct);
 *     SPI_Cmd(SPI0, ENABLE);
 * }
 * \endcode
 */
void SPI_Cmd(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * \brief  Transmits a number of bytes through the SPIx peripheral.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] pBuf: Bytes to be transmitted. This parameter must range from 0x0 to 0xFF.
 * \param[in] len: Byte length to be transmitted. This parameter must range from 0x1 to 0xFFFF.
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
 * \brief  Transmits a number of halfwords through the SPIx peripheral.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] pBuf: Halfwords to be transmitted. This parameter must range from 0x0 to 0xFFFF.
 * \param[in] len: Halfwords length to be transmitted. This parameter must range from 0x1 to 0xFFFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint16_t data_buf[] = {0x0102,0x0203,0x0304};
 *     SPI_SendHalfWord(SPI0, data_buf, sizeof(data_buf)/sizeof(uint16_t));
 * }
 * \endcode
  */
void SPI_SendHalfWord(SPI_TypeDef *SPIx, uint16_t *pBuf, uint16_t len);

/**
 * \brief  Transmits a number of words through the SPIx peripheral.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] pBuf: Words to be transmitted. This parameter must range from 0x0 to 0xFFFFFFFF.
 * \param[in] len: Word length to be transmitted. This parameter must range from 0x1 to 0xFFFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     uint32_t data_buf[] = {0x01020304,0x02030405,0x03040506};
 *     SPI_SendWord(SPI0, data_buf, sizeof(data_buf)/sizeof(uint32_t));
 * }
 * \endcode
 */
void SPI_SendWord(SPI_TypeDef *SPIx, uint32_t *pBuf, uint16_t len);

/**
 * \brief  Enable or disable the specified SPI interrupt.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] SPI_IT: Specifies the SPI interrupt to be enabled or disabled \ref x3g_SPI_interrupts_definition.
 *            This parameter can be one of the following values:
 *            - SPI_INT_TXE: Transmit FIFO empty interrupt. The TX FIFO is equal to or below its threshold value and requires service to prevent an under-run.
 *            - SPI_INT_TXO: Transmit FIFO overflow interrupt. An APB access attempts to write into the TX FIFO after it has been completely filled. When set, data written from the APB is discarded.
 *            - SPI_INT_RXU: Receive FIFO underflow interrupt. An APB access attempts to read from the RX FIFO when it is empty. When set, zeros are read back from the RX FIFO.
 *            - SPI_INT_RXO: Receive FIFO overflow interrupt. The receive logic attempts to place data into the RX FIFO after it has been completely filled. When set, newly received data are discarded.
 *            - SPI_INT_RXF: Receive FIFO full interrupt. RX FIFO is equal to or above its threshold value plus 1 and requires service to prevent an overflow.
 *            - SPI_INT_MST: Multi-Master contention interrupt, only for master. The interrupt is set when another serial master on the serial bus selects the SPI master as a serial-slave device and is actively transferring data.
 *            - SPI_INT_FAE: TX frame alignment interrupt, only for slave. The data received by the slave does not match data frame size.
 *            - SPI_INT_TUF: Transmit FIFO underflow interrupt, only for slave. Clocks sent by the master when the slave is at the empty FIFO level.
 *            - SPI_INT_RIG: CS rising edge detect interrupt, only for slave. CS line has a rising edge.
 *            - SPI_INT_WRAP_TXE: Transmit FIFO empty interrupt. The TX wrapper FIFO is equal to or below its threshold value and requires service to prevent an under-run.
 *            - SPI_INT_WRAP_TXO: Transmit FIFO overflow interrupt. An APB access attempts to write into the TX wrapper FIFO after it has been completely filled.
 *            - SPI_INT_WRAP_TXD: Transmit done when TX NDF is reached.
 * \param[in] NewState: New state of the specified SPI interrupt.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified SPI interrupt.
 *            - DISABLE: Disable the specified SPI interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_INTConfig(SPI0, SPI_INT_RXF, ENABLE);
 * }
 * \endcode
 */
void SPI_INTConfig(SPI_TypeDef *SPIx, uint16_t SPI_IT, FunctionalState NewState);

/**
 * \brief  Clear the specified SPI interrupt pending bit.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] SPI_IT: Specifies the SPI interrupt to clear \ref x3g_SPI_interrupts_definition.
 *            This parameter can be one of the following values:
 *            - SPI_INT_TXO: Transmit FIFO overflow interrupt. An APB access attempts to write into the TX FIFO after it has been completely filled. When set, data written from the APB is discarded.
 *            - SPI_INT_RXU: Receive FIFO underflow interrupt. An APB access attempts to read from the RX FIFO when it is empty. When set, zeros are read back from the RX FIFO.
 *            - SPI_INT_RXO: Receive FIFO overflow interrupt. The receive logic attempts to place data into the RX FIFO after it has been completely filled. When set, newly received data are discarded.
 *            - SPI_INT_MST: Multi-Master contention interrupt, only for master. The interrupt is set when another serial master on the serial bus selects the SPI master as a serial-slave device and is actively transferring data.
 *            - SPI_INT_FAE: TX frame alignment interrupt, only for slave. The data received by the slave does not match data frame size.
 *            - SPI_INT_TUF: Transmit FIFO underflow interrupt, only for slave. Clocks sent by the master when the slave is at the empty FIFO level.
 *            - SPI_INT_RIG: CS rising edge detect interrupt, only for slave. CS line has a rising edge.
 *            - SPI_INT_WRAP_TXO: Transmit FIFO overflow interrupt. An APB access attempts to write into the TX wrapper FIFO after it has been completely filled.
 *            - SPI_INT_WRAP_TXD: Transmit done when TX NDF is reached.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_ClearINTPendingBit(SPI0, SPI_INT_RXF);
 * }
 * \endcode
 */
void SPI_ClearINTPendingBit(SPI_TypeDef *SPIx, uint16_t SPI_IT);

/**
 * \brief  Transmits a data through the SPIx peripheral.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] Data: Data to be transmitted. This parameter must range from 0x0 to 0xFFFFFFFF.
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
void SPI_SendData(SPI_TypeDef *SPIx, uint32_t Data);

/**
 * \brief   Returns the most recent received data by the SPIx peripheral.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 *
 * \return  The value of the received data.
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
uint32_t SPI_ReceiveData(SPI_TypeDef *SPIx);

/**
 * \brief   Read data length in TX FIFO through the SPIx peripheral.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 *
 * \return  Data length in TX FIFO.
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
uint8_t SPI_GetTxFIFOLen(SPI_TypeDef *SPIx);

/**
 * \brief   Read data length in RX FIFO through the SPIx peripheral.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 *
 * \return  Data length in RX FIFO.
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
uint8_t SPI_GetRxFIFOLen(SPI_TypeDef *SPIx);

/**
 * \brief   Change SPI direction mode.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 *
 * \param[in] dir: The parameter of direction mode, please refer to \ref x3g_SPI_data_direction.
 *            This parameter can be one of the following values:
 *            - SPI_Direction_FullDuplex: Data can be transmitted and received at the same time.
 *            - SPI_Direction_TxOnly: Data can only be transmitted at a time.
 *            - SPI_Direction_RxOnly: Data can only be received at a time.
 *            - SPI_Direction_EEPROM: Send data first to read target numbers of data.
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
void SPI_ChangeDirection(SPI_TypeDef *SPIx, uint16_t dir);

/**
 * \brief   Set read Data length in EEPROM mode and RX only mode through the SPIx peripheral, which
            enables you to receive up to 64 KB of data in a continuous transfer.

 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] len: Length of read data. This parameter must range from 0x1 to 0xFFFF.
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
void SPI_SetReadLen(SPI_TypeDef *SPIx, uint16_t len);

/**
 * \brief   Set CS number through the SPIx peripheral, only support for master.
 *          Please make sure SPIx has been initialized before calling this function.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] number: If SPIx is SPI0 or SPI1, number can be 0 to 2. If SPIx is SPI2, number must be 0.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_SetCSNumber(SPI1, 1);
 * }
 * \endcode
 */
void SPI_SetCSNumber(SPI_TypeDef *SPIx, uint8_t number);

/**
 *
 * \brief  Check whether the specified SPI interrupt is set.
 *
 * \param[in]  SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in]  SPI_IT: Specifies the SPI interrupt to check \ref x3g_SPI_interrupts_definition.
 *            This parameter can be one of the following values:
 *            - SPI_INT_TXE: Transmit FIFO empty interrupt. The TX FIFO is equal to or below its threshold value and requires service to prevent an under-run.
 *            - SPI_INT_TXO: Transmit FIFO overflow interrupt. An APB access attempts to write into the TX FIFO after it has been completely filled. When set, data written from the APB is discarded.
 *            - SPI_INT_RXU: Receive FIFO underflow interrupt. An APB access attempts to read from the RX FIFO when it is empty. When set, zeros are read back from the RX FIFO.
 *            - SPI_INT_RXO: Receive FIFO overflow interrupt. The receive logic attempts to place data into the RX FIFO after it has been completely filled. When set, newly received data are discarded.
 *            - SPI_INT_RXF: Receive FIFO full interrupt. RX FIFO is equal to or above its threshold value plus 1 and requires service to prevent an overflow.
 *            - SPI_INT_MST: Multi-Master contention interrupt, only for master. The interrupt is set when another serial master on the serial bus selects the SPI master as a serial-slave device and is actively transferring data.
 *            - SPI_INT_FAE: TX frame alignment interrupt, only for slave. The data received by the slave does not match data frame size.
 *            - SPI_INT_TUF: Transmit FIFO underflow interrupt, only for slave. Clocks sent by the master when the slave is at the empty FIFO level.
 *            - SPI_INT_RIG: CS rising edge detect interrupt, only for slave. CS line has a rising edge.
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
ITStatus SPI_GetINTStatus(SPI_TypeDef *SPIx, uint32_t SPI_IT);

/**
 *
 * \brief  Check whether the specified SPI flag is set or not.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] SPI_FLAG: Specifies the SPI flag to check \ref x3g_SPI_flags_definition.
 *            This parameter can be one of the following values:
 *            - SPI_FLAG_DCOL: Data Collision Error flag. Set if it is actively transmitting in master mode when another master selects this device as a slave.
 *            - SPI_FLAG_TXE: Transmission error flag. Set if the transmit FIFO is empty when a transfer is started in slave mode.
 *            - SPI_FLAG_RFF: Receive FIFO full flag. Set if the receive FIFO is completely full.
 *            - SPI_FLAG_RFNE: Receive FIFO Not Empty flag. Set if receive FIFO is not empty.
 *            - SPI_FLAG_TFE: Transmit FIFO Empty flag. Set if transmit FIFO is empty.
 *            - SPI_FLAG_TFNF: Transmit FIFO Not Full flag. Set if transmit FIFO is not full.
 *            - SPI_FLAG_BUSY: SPI Busy flag. Set if it is actively transferring data.reset if it is idle or disabled.
 *            - SPI_FLAG_WRAP_CS_EN: SPI wrap CS enable flag. When set, indicates that the chip select signal is active.
 *            - SPI_FLAG_WRAP_TFNF: SPI wrap transmit FIFO not full flag. Set when the transmit FIFO contains one or more empty locations.
 *            - SPI_FLAG_WRAP_TFE: SPI wrap transmit FIFO empty flag. When the transmit FIFO is completely empty, this bit is set.
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
FlagStatus SPI_GetFlagState(SPI_TypeDef *SPIx, uint16_t SPI_FLAG);

/**
 *
 * \brief   Enable or disable the SPIx GDMA interface.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] SPI_GDMAReq: Specifies the SPI GDMA transfer request to be enabled or disabled \ref x3g_SPI_GDMA_transfer_requests.
 *            This parameter can be one of the following values:
 *            - SPI_GDMAReq_Tx: TX buffer DMA transfer request.
 *            - SPI_GDMAReq_Rx: RX buffer DMA transfer request.
 * \param[in]  NewState: New state of the selected SPI GDMA transfer request.
 *             This parameter can be one of the following values:
 *             - ENABLE: Enable the SPIx GDMA interface.
 *             - DISABLE: Disable the SPIx GDMA interface.
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
void SPI_GDMACmd(SPI_TypeDef *SPIx, SPIGdmaTransferRequests_TypeDef SPI_GDMAReq,
                 FunctionalState NewState);

/**
 * \brief  Change SPI clk speed dynamically.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] precalser: Value of prescaler, please refer to \ref x3g_SPI_BaudRate_Prescaler_Value.
 *            This parameter can be one of the following values:
 *            - SPI_BaudRatePrescaler_2: SPI baud rate prescaler value is 2.
 *            - SPI_BaudRatePrescaler_4: SPI baud rate prescaler value is 4.
 *            - SPI_BaudRatePrescaler_6: SPI baud rate prescaler value is 6.
 *            - SPI_BaudRatePrescaler_8: SPI baud rate prescaler value is 8.
 *            - SPI_BaudRatePrescaler_10: SPI baud rate prescaler value is 10.
 *            - SPI_BaudRatePrescaler_12: SPI baud rate prescaler value is 12.
 *            - SPI_BaudRatePrescaler_14: SPI baud rate prescaler value is 14.
 *            - SPI_BaudRatePrescaler_16: SPI baud rate prescaler value is 16.
 *            - SPI_BaudRatePrescaler_32: SPI baud rate prescaler value is 32.
 *            - SPI_BaudRatePrescaler_64: SPI baud rate prescaler value is 64.
 *            - SPI_BaudRatePrescaler_128: SPI baud rate prescaler value is 128.
 *            - SPI_BaudRatePrescaler_256: SPI baud rate prescaler value is 256.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_ChangeClock(SPI0, SPI_BaudRatePrescaler_2);
 * }
 * \endcode
 */
void SPI_ChangeClock(SPI_TypeDef *SPIx, uint32_t prescaler);

/**
 * \brief   Set SPI RX sample delay.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] delay: Delay value, this parameter can be 0 to 255.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_SetRxSampleDly(SPI0, 1);
 * }
 * \endcode
 */
void SPI_SetRxSampleDly(SPI_TypeDef *SPIx, uint32_t delay);

#if (SPI_SUPPORT_WRAP_MODE == 1) || ((SPI1_SUPPORT_WRAP_MODE == 1))

/**
 * \brief   Enables or disables the specified SPI wrap mode start transfer.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] NewState: New state of the SPI wrap mode start transfer.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_WrapModeStartTx(SPI0, ENABLE);
 * }
 * \endcode
 */
void SPI_WrapModeStartTx(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * \brief   Whether SPI inverse CS active polarity.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] NewState: New state of CS active polarity.
 *            This parameter can be one of the following values:
 *            - ENABLE: Inverse CS active polarity, which means CS is high active.
 *            - DISABLE: Not inverse CS active polarity, which means CS is low active.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_InverseCSActivePolarity(SPI0, ENABLE);
 * }
 * \endcode
 */
void SPI_InverseCSActivePolarity(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * \brief   Whether drive MOSI low in idle state.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] NewState: New state of MOSI low in idle state.
 *            This parameter can be one of the following values:
 *            - ENABLE: Drive MOSI low in idle state.
 *            - DISABLE: Not drive MOSI low in idle state, which means MOSI is Hi-Z in idle state.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_DriveMOSILow(SPI0, ENABLE);
 * }
 * \endcode
 */
void SPI_DriveMOSILow(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * \brief   Whether enable MOSI pull in idle state.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] NewState: New state of MOSI pull state.
 *            This parameter can be one of the following values:
 *            - ENABLE: MOSI is pull down in idle state.
 *            - DISABLE: MOSI is pull none in idle state.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_PullMOSIEn(SPI0, ENABLE);
 * }
 * \endcode
 */
void SPI_PullMOSIEn(SPI_TypeDef *SPIx, FunctionalState NewState);

#endif

/**
 * \brief     Config the SPI clock divider.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] ClockDiv: Specifies the SPI clock divider \ref x3g_SPI_Clock_Divider.
 *            This parameter can be one of the following values:
 *            - SPI_CLOCK_DIVIDER_x: Where x can be 1, 2, 4, 8, 3/4 to select the specified clock divider.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     SPI_ClkDivConfig(SPI0, SPI_CLOCK_DIV_1);
 * }
 * \endcode
 */
void SPI_ClkDivConfig(SPI_TypeDef *SPIx, uint16_t ClockDiv);

#if SPI_SUPPORT_CLOCK_SOURCE_CONFIG
/**
 * \brief     Select the SPI clock source and divider.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] ClockSource: SPI clock source to switch. This parameter can refer to \ref x3g_SPI_clock_source.
 *            This parameter can be one of the following values:
 *            - SPI_CLOCK_SOURCE_40M: Select SPI clock source of 40MHz.
 *            - SPI_CLOCK_SOURCE_PLL1: Select SPI clock source of PLL1 200MHz.
 * \param[in] ClockDiv: Specifies the SPI clock divider \ref x3g_SPI_Clock_Divider.
 *            This parameter can be one of the following values:
 *            - SPI_CLOCK_DIVIDER_x: Where x can be 1, 2, 4, 8, 3/4 to select the specified clock divider.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_spi_init(void)
 * {
 *     SPI_ClkConfig(SPI0, SPI_CLOCK_SOURCE_PLL1, SPI_CLOCK_DIV_1);
 * }
 * \endcode
 */
void SPI_ClkConfig(SPI_TypeDef *SPIx, SPIClockSrc_TypeDef ClockSrc, SPIClockDiv_TypeDef ClockDiv);
#endif

#if SPI_SUPPORT_CLOCK_SOURCE_SWITCH
/**
 * \brief     Switch the SPI clock source.
 *
 * \param[in] SPIx: Select the SPI peripheral \ref x3g_SPI_Declaration.
 * \param[in] ClockSource: SPI clock source to switch. This parameter can refer to \ref x3g_SPI_clock_source.
 *            This parameter can be one of the following values:
 *            - SPI_CLOCK_SOURCE_40M: Select SPI clock source of 40MHz.
 *            - SPI_CLOCK_SOURCE_PLL1: Select SPI clock source of PLL1 200MHz.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void spi_demo(void)
 * {
 *     SPI_ClkSourceSwitch(SPI0, SPI_CLOCK_SOURCE_40M);
 * }
 * \endcode
 */
extern void SPI_ClkSourceSwitch(SPI_TypeDef *SPIx, uint16_t ClockSource);
#endif

#if SPI_SUPPORT_RAP_FUNCTION

void SPI_RAPModeCmd(SPI_TypeDef *SPIx, FunctionalState NewState);

void SPI_SetTaskCmdNum(SPI_TypeDef *SPIx, uint8_t num);

void SPI_SetTaskWaitNum(SPI_TypeDef *SPIx, uint8_t num);

void SPI_SetTaskTransferNum(SPI_TypeDef *SPIx, uint8_t num);

void SPI_TaskTrigger(SPI_TypeDef *SPIx, uint32_t task);

bool SPI_TaskEventStsCheck(SPI_TypeDef *SPIx, uint32_t te);

void SPI_TaskEventStsClear(SPI_TypeDef *SPIx, uint32_t te);

#endif

/** @} */ /* End of group 87x3g_SPI_Exported_Functions */
/** @} */ /* End of group 87x3g_SPI */

#ifdef __cplusplus
}
#endif

#endif /* RTL876X_SPI_H */



