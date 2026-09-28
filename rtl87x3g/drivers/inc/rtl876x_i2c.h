/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef __RTL876X_I2C_H
#define __RTL876X_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x.h"
#include "rtl876x_i2c_def.h"

/** @addtogroup 87x3g_I2C I2C
  * @brief I2C driver module.
  * @{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup 87x3g_I2C_Exported_Constants I2C Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    87x3g_I2C_Clock_Speed I2C Clock Speed
 * \{
 */
#define IS_I2C_CLOCK_SPEED(SPEED) (((SPEED) >= 0x01) && ((SPEED) <= I2C_CLOCK_MAX_SPEED)) //!< I2C clock speed is between 1 and 1000000.

/** End of 87x3g_I2C_Clock_Speed
  * \}
  */

/**
 * \defgroup    87x3g_I2C_Device_Mode I2C Device Mode
 * \{
 */
typedef enum
{
    I2C_DeviveMode_Slave = 0x00,  //!< I2C device operating mode as slave.
    I2C_DeviveMode_Master = 0x01, //!< I2C device operating mode as master.
} I2CDeviceMode_TypeDef;

#define IS_I2C_DEVICE_MODE(MODE) (((MODE) == I2C_DeviveMode_Slave) || ((MODE) == I2C_DeviveMode_Master))

/** End of 87x3g_I2C_Device_Mode
  * \}
  */

/**
 * \defgroup    87x3g_I2C_Address_Mode I2C Address Mode
 * \{
 */
typedef enum
{
    I2C_AddressMode_7BIT = 0x00,  //!< I2C address mode using 7-bit addressing.
    I2C_AddressMode_10BIT = 0x01, //!< I2C address mode using 10-bit addressing.
} I2CAddressMode_TypeDef;

#define IS_I2C_ADDRESS_MODE(ADDR) (((ADDR) == I2C_AddressMode_7BIT) || ((ADDR) == I2C_AddressMode_10BIT))

/** End of 87x3g_I2C_Address_Mode
  * \}
  */

/**
 * \defgroup    87x3g_I2C_Acknowledgement I2C Acknowledgement
 * \{
 */
#define IS_I2C_ACKNOWLEDGEMENT(ACK) (((ACK) == ENABLE) || ((ACK) == DISABLE)) //!< Check I2C acknowledgment is enabled or disabled.

/** End of 87x3g_I2C_Acknowledgement
  * \}
  */

/**
 * \defgroup    87x3g_I2C_send_stop I2C Send Stop
 * \{
 */
typedef enum
{
    I2C_STOP_DISABLE = 0x00, //!< I2C stop will not be issued.
    I2C_STOP_ENABLE = 0x01,  //!< I2C stop will be issued.
} I2CStopBit_TypeDef;

#define IS_I2C_STOP(CMD) (((CMD) == I2C_STOP_ENABLE) || ((CMD) == I2C_STOP_DISABLE))

/** End of 87x3g_I2C_send_stop
  * \}
  */

/**
 * \defgroup    87x3g_I2C_send_command I2C Send Command
 * \{
 */
typedef enum
{
    I2C_WRITE_CMD = 0x00, //!< I2C write command.
    I2C_READ_CMD = 0x01,  //!< I2C read command.
} I2CSendCommend_TypeDef;

#define IS_I2C_CMD(CMD) (((CMD) == I2C_WRITE_CMD) || ((CMD) == I2C_READ_CMD))

/** End of 87x3g_I2C_send_command
  * \}
  */

/**
 * \defgroup    87x3g_I2C_GDMA_transfer_requests I2C GDMA Transfer Requests
 * \{
 */
typedef enum
{
    I2C_GDMAReq_Rx = 0x01, //!< RX buffer GDMA transfer request.
    I2C_GDMAReq_Tx = 0x02, //!< TX buffer GDMA transfer request.
} I2CGdmaTransferRequests_TypeDef;

#define IS_I2C_GDMAREQ(GDMAREQ) (((GDMAREQ) == I2C_GDMAReq_Rx) || ((GDMAREQ) == I2C_GDMAReq_Tx))

/** End of 87x3g_I2C_GDMA_transfer_requests
  * \}
  */

/**
 * \defgroup    87x3g_I2C_Status  I2C Status
 * \{
 */

typedef enum
{
    I2C_Success,              //!< I2C success.
    I2C_ARB_LOST,             //!< Master or slave transmitter losed arbitration.
    I2C_ABRT_MASTER_DIS,      //!< User tried to initiate a master operation with the master mode disabled.
    I2C_ABRT_TXDATA_NOACK,    //!< Master sent data byte(s) following the address, but it did not receive an acknowledge from the remote slave.
    I2C_ABRT_10ADDR2_NOACK,   //!< Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
    I2C_ABRT_10ADDR1_NOACK,   //!< Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
    I2C_ABRT_7B_ADDR_NOACK,   //!< Master is in 7-bit address mode and the address sent was not acknowledged by any slave.
    I2C_ERR_TIMEOUT           //!< I2C timeout.
} I2C_Status;

/** End of 87x3g_I2C_Status
  * \}
  */

/**
 * \defgroup    87x3g_I2C_interrupts_definition I2C Interrupts
 * \{
 */

#define I2C_INT_MST_ON_HOLD                     BIT13 //!< I2C master hold bus interrupt. Indicates whether a master is holding the bus.
#define I2C_INT_GEN_CALL                        BIT11 //!< I2C general call interrupt. When a general call address is received and it is acknowledged.
#define I2C_INT_START_DET                       BIT10 //!< I2C start detect interrupt. When a start or restart condition has occurred on the I2C interface.
#define I2C_INT_STOP_DET                        BIT9  //!< I2C stop detect interrupt. When a stop condition has occurred on the I2C interface.
#define I2C_INT_ACTIVITY                        BIT8  //!< I2C activity interrupt. When I2C is activity on the bus.
#define I2C_INT_RX_DONE                         BIT7  //!< I2C slave RX done interrupt. When the I2C is acting as a slave-transmitter and the master does not acknowledge a transmitted byte. This occurs on the last byte of the transmission, indicating that the transmission is done.
#define I2C_INT_TX_ABRT                         BIT6  //!< I2C TX abort interrupt. When an I2C transmitter is unable to complete the intended actions on the contents of the transmit FIFO.
#define I2C_INT_RD_REQ                          BIT5  //!< I2C slave RX request interrupt. When I2C is acting as a slave and another I2C master is attempting to read data from I2C.
#define I2C_INT_TX_EMPTY                        BIT4  //!< I2C TX FIFO empty interrupt. When the transmit buffer is at or below the threshold value.
#define I2C_INT_TX_OVER                         BIT3  //!< I2C TX FIFO overflow interrupt. When transmit buffer is filled to 24 and the processor attempts to issue another I2C command.
#define I2C_INT_RX_FULL                         BIT2  //!< I2C RX FIFO full interrupt. When the receive buffer reaches or goes above the RX FIFO threshold value.
#define I2C_INT_RX_OVER                         BIT1  //!< I2C RX FIFO overflow interrupt. When the receive buffer is completely filled to 40 and an additional byte is received from an external I2C device.
#define I2C_INT_RX_UNDER                        BIT0  //!< I2C RX FIFO underflow interrupt. When the processor attempts to read the receive buffer when it is empty.

#define I2C_GET_INT(INT)    (((INT) == I2C_INT_GEN_CALL) || ((INT) == I2C_INT_START_DET) || \
                             ((INT) == I2C_INT_STOP_DET) || ((INT) == I2C_INT_ACTIVITY) || \
                             ((INT) == I2C_INT_RX_DONE)  || ((INT) == I2C_INT_TX_ABRT) || \
                             ((INT) == I2C_INT_RD_REQ)   || ((INT) == I2C_INT_TX_EMPTY) || \
                             ((INT) == I2C_INT_TX_OVER)  || ((INT) == I2C_INT_RX_FULL) || \
                             ((INT) == I2C_INT_RX_OVER)  || ((INT) == I2C_INT_RX_UNDER) || \
                             ((INT) == I2C_INT_MST_ON_HOLD)) //!< Check if the input parameter is valid.

/** End of 87x3g_I2C_interrupts_definition
  * \}
  */

/**
 * \defgroup    87x3g_I2C_flags_definition I2C Flags
 * \{
 */
#define I2C_FLAG_SLV_HOLD_RX_FIFO_FULL          BIT10 //!< This bit indicates the bus hold in slave mode due to the RX FIFO being full and an additional byte being received.
#define I2C_FLAG_SLV_HOLD_TX_FIFO_EMPTY         BIT9 //!< This bit indicates the bus hold in slave mode for the read request when the TX FIFO is empty. The bus is in hold until the TX FIFO has data to transmit for the read request.
#define I2C_FLAG_MST_HOLD_RX_FIFO_FULL          BIT8 //!< This bit indicates the bus hold in master mode due to RX FIFO is full and additional byte has been received
#define I2C_FLAG_MST_HOLD_TX_FIFO_EMPTY         BIT7 //!< The I2C master stalls the write transfer when TX FIFO is empty, and the last byte does not have the stop bit.
#define I2C_FLAG_SLV_ACTIVITY                   BIT6 //!< Slave FSM(finite state machine) activity status.#define I2C_FLAG_MST_ACTIVITY                   BIT5 //!< Master FSM(finite state machine) activity status.
#define I2C_FLAG_RFF                            BIT4 //!< Receive FIFO completely full.
#define I2C_FLAG_RFNE                           BIT3 //!< Receive FIFO not empty.
#define I2C_FLAG_TFE                            BIT2 //!< Transmit FIFO completely empty.
#define I2C_FLAG_TFNF                           BIT1 //!< Transmit FIFO not full.
#define I2C_FLAG_ACTIVITY                       BIT0 //!< I2C activity status.

#define IS_I2C_GET_FLAG(FLAG) (((FLAG) == I2C_FLAG_SLV_ACTIVITY) || ((FLAG) == I2C_FLAG_MST_ACTIVITY) || \
                               ((FLAG) == I2C_FLAG_RFF) || ((FLAG) == I2C_FLAG_RFNE) || \
                               ((FLAG) == I2C_FLAG_TFE) || ((FLAG) == I2C_FLAG_TFNF) || \
                               ((FLAG) == I2C_FLAG_ACTIVITY) || ((FLAG) == I2C_FLAG_MST_HOLD_TX_FIFO_EMPTY) || \
                               ((FLAG) == I2C_FLAG_MST_HOLD_RX_FIFO_FULL) || ((FLAG) == I2C_FLAG_SLV_HOLD_TX_FIFO_EMPTY) || \
                               ((FLAG) == I2C_FLAG_SLV_HOLD_RX_FIFO_FULL)) //!< Check if the input parameter is valid.

/** End of 87x3g_I2C_flags_definition
  * \}
  */

/**
 * \defgroup    87x3g_I2C_transmit_Abort_Source I2C Transmit Abort Source
 * \{
 */

#define ABRT_SLVRD_INTX                         ((uint32_t)BIT(15)) //!< When the processor side responds to a slave mode request for data to be transmitted to a remote master and user send read command.
#define ABRT_SLV_ARBLOST                        ((uint32_t)BIT(14)) //!< Slave lost the bus while transmitting data to a remote master.
#define ABRT_SLVFLUSH_TXFIFO                    ((uint32_t)BIT(13)) //!< Slave has received a read command and some data exists in the TX FIFO so the slave issues TX abort interrupt to flush old data in TX FIFO.
#define ARB_LOST                                ((uint32_t)BIT(12)) //!< Master has lost arbitration or the slave transmitter has lost arbitration.
#define ABRT_MASTER_DIS                         ((uint32_t)BIT(11)) //!< User tries to initiate a master operation with the master mode disabled.
#define ABRT_10B_RD_NORSTRT                     ((uint32_t)BIT(10)) //!< The restart is disabled and the master sends a read command in 10-bit addressing mode.
#define ABRT_SBYTE_NORSTRT                      ((uint32_t)BIT(9))  //!< The restart is disabled and the user is trying to send a start byte.
#define ABRT_HS_NORSTRT                         ((uint32_t)BIT(8))  //!< The restart is disabled and the user is trying to use the master to transfer data in high speed mode.
#define ABRT_SBYTE_ACKDET                       ((uint32_t)BIT(7))  //!< Master has sent a start byte and the start byte was acknowledged (wrong behavior).
#define ABRT_HS_ACKDET                          ((uint32_t)BIT(6))  //!< Master is in high speed mode and the high speed master code was acknowledged (wrong behavior).
#define ABRT_GCALL_READ                         ((uint32_t)BIT(5))  //!< I2C in master mode sent a general call but the user programmed the byte following the general call to be a read from the bus.
#define ABRT_GCALL_NOACK                        ((uint32_t)BIT(4))  //!< I2C in master mode sent a general call and no slave on the bus acknowledged the general call.
#define ABRT_TXDATA_NOACK                       ((uint32_t)BIT(3))  //!< This is a master-mode only bit. Master has received an acknowledgement for the address, but when it sent data byte(s) following the address, it did not receive an acknowledge from the remote slave(s).
#define ABRT_10ADDR2_NOACK                      ((uint32_t)BIT(2))  //!< Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
#define ABRT_10ADDR1_NOACK                      ((uint32_t)BIT(1))  //!< Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
#define ABRT_7B_ADDR_NOACK                      ((uint32_t)BIT(0))  //!< Master is in 7-bit address mode and the address sent was not acknowledged by any slave.

#define MS_ALL_ABORT                            (ARB_LOST | ABRT_MASTER_DIS | ABRT_TXDATA_NOACK |\
                                                 ABRT_10ADDR2_NOACK | ABRT_10ADDR1_NOACK | ABRT_7B_ADDR_NOACK) //!< Contains all master abort sources.

#define IS_I2C_EVENT(EVENT) (((EVENT) == ABRT_SLVRD_INTX) || \
                             ((EVENT) == ABRT_SLV_ARBLOST) || \
                             ((EVENT) == ABRT_SLVFLUSH_TXFIFO) || \
                             ((EVENT) == ARB_LOST) || \
                             ((EVENT) == ABRT_MASTER_DIS) || \
                             ((EVENT) == ABRT_10B_RD_NORSTRT) || \
                             ((EVENT) == ABRT_SBYTE_NORSTRT) || \
                             ((EVENT) == ABRT_HS_NORSTRT) || \
                             ((EVENT) == ABRT_SBYTE_ACKDET) || \
                             ((EVENT) == ABRT_HS_ACKDET) || \
                             ((EVENT) == ABRT_GCALL_READ) || \
                             ((EVENT) == ABRT_GCALL_NOACK) || \
                             ((EVENT) == ABRT_TXDATA_NOACK) || \
                             ((EVENT) == ABRT_10ADDR2_NOACK) || \
                             ((EVENT) == ABRT_10ADDR1_NOACK) || \
                             ((EVENT) == ABRT_7B_ADDR_NOACK)) //!< Check if the input parameter is valid.

/** End of 87x3g_I2C_transmit_Abort_Source
  * \}
  */

/**
 * \defgroup    87x3g_I2C_Immediate_Number I2C Immediate Number
 * \{
 */

#define I2C_0X10_CMD         BIT8 //!< This bit controls whether a read or a write is performed.
#define I2C_0X10_STOP        BIT9 //!< This bit controls whether a stop is issued after the byte is sent or received.

/** End of 87x3g_I2C_Immediate_Number
  * \}
  */

/**
 * \defgroup    87x3g_I2C_Clock_Divider I2C Clock Divider
 * \{
 */
#define I2C_CLOCK_DIV_1                    ((uint16_t)0x0) //!< I2C clock divider is set to 1.
#define I2C_CLOCK_DIV_2                    ((uint16_t)0x1) //!< I2C clock divider is set to 2.
#define I2C_CLOCK_DIV_4                    ((uint16_t)0x2) //!< I2C clock divider is set to 4.
#define I2C_CLOCK_DIV_8                    ((uint16_t)0x3) //!< I2C clock divider is set to 8.
#define IS_I2C_DIV(DIV)              (((DIV) == I2C_CLOCK_DIV_1) || \
                                      ((DIV) == I2C_CLOCK_DIV_2) || \
                                      ((DIV) == I2C_CLOCK_DIV_4) || \
                                      ((DIV) == I2C_CLOCK_DIV_8)) //!< Check if the input parameter is valid.
/** End of 87x3g_I2C_Clock_Divider
  * \}
  */

/** End of 87x3g_I2C_Exported_Constants
  * \}
  */


/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup 87x3g_I2C_Exported_Types I2C Exported Types
  * \{
  */

/**
 * \brief       I2C init structure definition.
 */
typedef struct
{
    uint32_t I2C_Clock;                    /*!< Specifies the I2C clock source frequency, default 40000000.
                                                  This parameter can be set with @ref x3g_I2C_Clock_Divider. I2C_Clock = 40000000 / I2C_Clock_Divider. */

    uint32_t I2C_ClockSpeed;               /*!< Specifies the I2C clock speed.
                                                  This parameter must be set to a value lower than 1MHz. */

    I2CDeviceMode_TypeDef I2C_DeviveMode;  /*!< Specifies the I2C device mode.
                                                  This parameter can be a value of @ref x3g_I2C_device_mode. */

    I2CAddressMode_TypeDef I2C_AddressMode; /*!< Specifies the I2C address mode.
                                                                This parameter can be a value of @ref x3g_I2C_address_mode. */

    uint16_t I2C_SlaveAddress;             /*!< Specifies the I2C slave address.
                                                  This parameter can be a 7-bit or 10-bit address, must range from 0x0 to 0x3FF. */

    FunctionalState
    I2C_Ack;               /*!< Enables or disables the acknowledgement only in slave mode.
                                                  This parameter can be a value of ENABLE or DISABLE. */

    uint32_t I2C_TxThresholdLevel;         /*!< Specifies the transmit FIFO threshold to trigger interrupt \ref I2C_INT_TX_EMPTY.
                                                  This parameter can be a value less than I2C_TX_FIFO_SIZE of 24. */

    uint32_t I2C_RxThresholdLevel;         /*!< Specifies the receive FIFO Threshold to trigger interrupt \ref I2C_INT_RX_FULL.
                                                  This parameter can be a value less than I2C_RX_FIFO_SIZE of 24. */

    FunctionalState I2C_TxDmaEn;           /*!< Specifies the I2C TX DMA mode.
                                                  This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState I2C_RxDmaEn;           /*!< Specifies the I2C RX DMA mode.
                                                  This parameter can be a value of ENABLE or DISABLE. */

    uint8_t  I2C_TxWaterlevel;             /*!< Specifies the DMA TX water level. This parameter must range from 1 to 23.
                                                  I2C_TxWaterlevel = I2C TX FIFO depth - I2C TX GDMA MSize. */

    uint8_t  I2C_RxWaterlevel;             /*!< Specifies the DMA RX water level. This parameter must range from 1 to 23.
                                                  I2C_RxWaterlevel = I2C RX GDMA MSize - 1. */

    uint8_t  I2C_RisingTimeNs;            /*!< Specifies the I2C SDA/SCL rising time.
                                                  The unit is ns and must be an integer multiple of clock src period. This parameter must range from 0x1 to 0xff. */

} I2C_InitTypeDef;

/** End of 87x3g_I2C_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/

/** @defgroup 87x3g_I2C_Exported_Functions I2C Exported Functions
 * @{
 */

/**
 *
 * \brief   Disable the I2Cx peripheral clock, and restore registers to their default values.
 *
 * \param[in]  I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c0_init(void)
 * {
 *     I2C_DeInit(I2C0);
 * }
 * \endcode
 */
void I2C_DeInit(I2C_TypeDef *I2Cx);

/**
 *
 * \brief   Initializes the I2Cx peripheral according to the specified
 *          parameters in the I2C_InitStruct.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] I2C_InitStruct: Pointer to a \ref I2C_InitTypeDef structure that
 *            contains the configuration information for the specified I2C peripheral.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c0_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_I2C0, APBPeriph_I2C0_CLOCK, ENABLE);
 *
 *     I2C_InitTypeDef  I2C_InitStruct;
 *     I2C_StructInit(&I2C_InitStruct);
 *
 *     I2C_InitStruct.I2C_ClockSpeed    = 100000;
 *     I2C_InitStruct.I2C_DeviveMode    = I2C_DeviveMode_Master;
 *     I2C_InitStruct.I2C_AddressMode   = I2C_AddressMode_7BIT;
 *     I2C_InitStruct.I2C_SlaveAddress  = 0x50;
 *     I2C_InitStruct.I2C_Ack           = I2C_Ack_Enable;
 *
 *     I2C_Init(I2C0, &I2C_InitStruct);
 * }
 * \endcode
 */
void I2C_Init(I2C_TypeDef *I2Cx, I2C_InitTypeDef *I2C_InitStruct);

/**
 *
 * \brief  Enable or disable the specified I2C peripheral.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] NewState: New state of the I2Cx peripheral.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified I2C peripheral, allowing it to begin data transfer operations.
 *            - DISABLE: Disable the specified I2C peripheral, TX and RX FIFOs are held in an erased state.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c0_init(void)
 * {
 *     I2C_Cmd(I2C0, ENABLE);
 * }
 * \endcode
 */
void I2C_Cmd(I2C_TypeDef *I2Cx, FunctionalState NewState);

/**
 * \brief  Checks whether the last I2Cx abort status.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 *
 * \return I2C status, please refer to \ref x3g_I2C_Status.
 * \retval I2C_Success: I2C success.
 * \retval I2C_ARB_LOST: Master or slave transmitter losed arbitration.
 * \retval I2C_ABRT_MASTER_DIS: User tried to initiate a master operation with the master mode disabled.
 * \retval I2C_ABRT_TXDATA_NOACK: Master sent data byte(s) following the address, but it did not receive an acknowledge from the remote slave.
 * \retval I2C_ABRT_10ADDR2_NOACK: Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
 * \retval I2C_ABRT_10ADDR1_NOACK: Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
 * \retval I2C_ABRT_7B_ADDR_NOACK: Master is in 7-bit address mode and the address sent was not acknowledged by any slave.
 * \retval I2C_ERR_TIMEOUT: I2C timeout.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     I2C_CheckAbortStatus(I2C0);
 * }
 * \endcode
 */
I2C_Status I2C_CheckAbortStatus(I2C_TypeDef *I2Cx);

/**
 *
 * \brief   Fills each I2C_InitStruct member with its default value.
 *
 * \note   The default settings for the I2C_InitStruct member are shown in the following table:
 *         | I2C_InitStruct Member | Default Value                    |
 *         |:---------------------:|:--------------------------------:|
 *         | I2C_Clock             | 40000000                         |
 *         | I2C_ClockSpeed        | 400000                           |
 *         | I2C_DeviveMode        | \ref I2C_DeviveMode_Master       |
 *         | I2C_AddressMode       | \ref I2C_AddressMode_7BIT        |
 *         | I2C_SlaveAddress      | 0                                |
 *         | I2C_Ack               | \ref I2C_Ack_Enable              |
 *         | I2C_TxThresholdLevel  | 0x00                             |
 *         | I2C_RxThresholdLevel  | 0x00                             |
 *         | I2C_TxDmaEn           | DISABLE                          |
 *         | I2C_RxDmaEn           | DISABLE                          |
 *         | I2C_RxWaterlevel      | 1                                |
 *         | I2C_TxWaterlevel      | 15                               |
 *         | I2C_RisingTimeNs      | 50                               |
 *
 * \param[in] I2C_InitStruct: Pointer to a \ref I2C_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c0_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_I2C0, APBPeriph_I2C0_CLOCK, ENABLE);
 *
 *     I2C_InitTypeDef  I2C_InitStruct;
 *     I2C_StructInit(&I2C_InitStruct);
 *
 *     I2C_InitStruct.I2C_ClockSpeed    = 100000;
 *     I2C_InitStruct.I2C_DeviveMode    = I2C_DeviveMode_Master;
 *     I2C_InitStruct.I2C_AddressMode   = I2C_AddressMode_7BIT;
 *     I2C_InitStruct.I2C_SlaveAddress  = 0x50;
 *     I2C_InitStruct.I2C_Ack           = I2C_Ack_Enable;
 *
 *     I2C_Init(I2C0, &I2C_InitStruct);
 * }
 * \endcode
 */
void I2C_StructInit(I2C_InitTypeDef *I2C_InitStruct);

/**
 *
 * \brief   Send data in master mode through the I2Cx peripheral.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] pBuf: Byte to be transmitted. This parameter must range from 0x0 to 0xFF.
 * \param[in] len: Data length to send. This parameter must range from 0x1 to 0xFFFF.
 *
 * \return I2C status, please refer to \ref x3g_I2C_Status.
 * \retval I2C_Success: I2C success.
 * \retval I2C_ARB_LOST: Master or slave transmitter losed arbitration.
 * \retval I2C_ABRT_MASTER_DIS: User tried to initiate a master operation with the master mode disabled.
 * \retval I2C_ABRT_TXDATA_NOACK: Master sent data byte(s) following the address, but it did not receive an acknowledge from the remote slave.
 * \retval I2C_ABRT_10ADDR2_NOACK: Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
 * \retval I2C_ABRT_10ADDR1_NOACK: Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
 * \retval I2C_ABRT_7B_ADDR_NOACK: Master is in 7-bit address mode and the address sent was not acknowledged by any slave.
 * \retval I2C_ERR_TIMEOUT: I2C timeout.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint8_t data[10] = {0x01, x0x02, 0x03, 0x04};
 *     I2C_MasterWrite(I2C0, data, 4);
 * }
 * \endcode
 */
I2C_Status I2C_MasterWrite(I2C_TypeDef *I2Cx, uint8_t *pBuf, uint16_t len);

/**
 *
 * \brief   Send device write data in master mode through the I2Cx peripheral.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] pBuf: Data buffer1 to be transmitted. This parameter must range from 0x0 to 0xFF.
 * \param[in] len: Send data length1. This parameter must range from 0x1 to 0xFFFF.
 * \param[in] pbuf2: Data buffer2 to be transmitted. This parameter must range from 0x0 to 0xFF.
 * \param[in] len2: Send data length2. This parameter must range from 0x1 to 0xFFFF.
 *
 * \return I2C status, please refer to \ref x3g_I2C_Status.
 * \retval I2C_Success: I2C success.
 * \retval I2C_ARB_LOST: Master or slave transmitter losed arbitration.
 * \retval I2C_ABRT_MASTER_DIS: User tried to initiate a master operation with the master mode disabled.
 * \retval I2C_ABRT_TXDATA_NOACK: Master sent data byte(s) following the address, but it did not receive an acknowledge from the remote slave.
 * \retval I2C_ABRT_10ADDR2_NOACK: Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
 * \retval I2C_ABRT_10ADDR1_NOACK: Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
 * \retval I2C_ABRT_7B_ADDR_NOACK: Master is in 7-bit address mode and the address sent was not acknowledged by any slave.
 * \retval I2C_ERR_TIMEOUT: I2C timeout.
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint8_t data[10] = {0x01,x0x02,0x03,0x04};
 *     uint8_t data1[10] = {0x01,x0x02,0x03,0x04};
 *     I2C_MasterWriteDevice(I2C0, data, 4, data, 4);
 * }
 * \endcode
 */
I2C_Status I2C_MasterWriteDevice(I2C_TypeDef *I2Cx, uint8_t *pBuf, uint16_t len, uint8_t *pbuf2,
                                 uint32_t len2);

/**
 *
 * \brief   Read data in master mode through the I2Cx peripheral.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] pBuf: Data buffer to receive data. This parameter must range from 0x0 to 0xFF.
 * \param[in] len: Read data length. This parameter must range from 0x1 to 0xFFFF.
 *
 * \return I2C status, please refer to \ref x3g_I2C_Status.
 * \retval I2C_Success: I2C success.
 * \retval I2C_ARB_LOST: Master or slave transmitter losed arbitration.
 * \retval I2C_ABRT_MASTER_DIS: User tried to initiate a master operation with the master mode disabled.
 * \retval I2C_ABRT_TXDATA_NOACK: Master sent data byte(s) following the address, but it did not receive an acknowledge from the remote slave.
 * \retval I2C_ABRT_10ADDR2_NOACK: Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
 * \retval I2C_ABRT_10ADDR1_NOACK: Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
 * \retval I2C_ABRT_7B_ADDR_NOACK: Master is in 7-bit address mode and the address sent was not acknowledged by any slave.
 * \retval I2C_ERR_TIMEOUT: I2C timeout.
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint8_t data[10] = {0};
 *     I2C_MasterRead(I2C0, data, 10);
 * }
 * \endcode
 */
I2C_Status I2C_MasterRead(I2C_TypeDef *I2Cx, uint8_t *pBuf, uint16_t len);

/**
 *
 * \brief   Read data in master mode through the I2Cx peripheral without stop.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] pBuf: Data buffer to receive data. This parameter must range from 0x0 to 0xFF.
 * \param[in] len: Read data length. This parameter must range from 0x1 to 0xFFFF.
 *
 * \return I2C status, please refer to \ref x3g_I2C_Status.
 * \retval I2C_Success: I2C success.
 * \retval I2C_ARB_LOST: Master or slave transmitter losed arbitration.
 * \retval I2C_ABRT_MASTER_DIS: User tried to initiate a master operation with the master mode disabled.
 * \retval I2C_ABRT_TXDATA_NOACK: Master sent data byte(s) following the address, but it did not receive an acknowledge from the remote slave.
 * \retval I2C_ABRT_10ADDR2_NOACK: Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
 * \retval I2C_ABRT_10ADDR1_NOACK: Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
 * \retval I2C_ABRT_7B_ADDR_NOACK: Master is in 7-bit address mode and the address sent was not acknowledged by any slave.
 * \retval I2C_ERR_TIMEOUT: I2C timeout.
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint8_t data[10] = {0};
 *     I2C_MasterReadNoStop(I2C0, data, 10);
 * }
 * \endcode
 */
I2C_Status I2C_MasterReadNoStop(I2C_TypeDef *I2Cx, uint8_t *pBuf, uint16_t len);

/**
 *
 * \brief   Sends data and read data in master mode through the I2Cx peripheral.
 *          Attention:Read data with time out mechanism.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] pWriteBuf: Data buffer to send before read. This parameter must range from 0x0 to 0xFF.
 * \param[in] Writelen: Data length to send. This parameter must range from 0x1 to 0xFFFF.
 * \param[in] pReadBuf: Data buffer to receive. This parameter must range from 0x0 to 0xFF.
 * \param[in] Readlen: Data length to receive. This parameter must range from 0x1 to 0xFFFF.
 *
 * \return I2C status, please refer to \ref x3g_I2C_Status.
 * \retval I2C_Success: I2C success.
 * \retval I2C_ARB_LOST: Master or slave transmitter losed arbitration.
 * \retval I2C_ABRT_MASTER_DIS: User tried to initiate a master operation with the master mode disabled.
 * \retval I2C_ABRT_TXDATA_NOACK: Master sent data byte(s) following the address, but it did not receive an acknowledge from the remote slave.
 * \retval I2C_ABRT_10ADDR2_NOACK: Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
 * \retval I2C_ABRT_10ADDR1_NOACK: Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
 * \retval I2C_ABRT_7B_ADDR_NOACK: Master is in 7-bit address mode and the address sent was not acknowledged by any slave.
 * \retval I2C_ERR_TIMEOUT: I2C timeout.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint8_t tx_data[10] = {0x01,x0x02,0x03,0x04};
 *     uint8_t rx_data[10] = {0};
 *     I2C_RepeatRead(I2C0, tx_data, 4, rx_data, 10);
 * }
 * \endcode
 */
I2C_Status I2C_RepeatRead(I2C_TypeDef *I2Cx, uint8_t *pWriteBuf, uint16_t Writelen,
                          uint8_t *pReadBuf, uint16_t Readlen);

/**
 *
 * \brief     Mask the specified I2C interrupt or not.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] I2C_IT: Specified the I2C interrupt \ref x3g_I2C_interrupts_definition.
 *            This parameter can be one of the following values:
 *            - I2C_INT_GEN_CALL: I2C general call interrupt. When a general call address is received and it is acknowledged.
 *            - I2C_INT_START_DET: I2C start detect interrupt. When a start or restart condition has occurred on the I2C interface.
 *            - I2C_INT_STOP_DET: I2C stop detect interrupt. When a stop condition has occurred on the I2C interface.
 *            - I2C_INT_ACTIVITY: I2C activity interrupt. When I2C is activity on the bus.
 *            - I2C_INT_RX_DONE: I2C slave RX done interrupt. When the I2C is acting as a slave-transmitter and the master does not acknowledge a transmitted byte. This occurs on the last byte of the transmission, indicating that the transmission is done.
 *            - I2C_INT_TX_ABRT: I2C TX abort interrupt. When an I2C transmitter is unable to complete the intended actions on the contents of the transmit FIFO.
 *            - I2C_INT_RD_REQ: I2C slave RX request interrupt. When I2C is acting as a slave and another I2C master is attempting to read data from I2C.
 *            - I2C_INT_TX_EMPTY: I2C TX FIFO empty interrupt. When the transmit buffer is at or below the threshold value.
 *            - I2C_INT_TX_OVER: I2C TX FIFO overflow interrupt. When transmit buffer is filled to 24 and the processor attempts to issue another I2C command.
 *            - I2C_INT_RX_FULL: I2C RX FIFO full interrupt. When the receive buffer reaches or goes above the RX FIFO threshold value.
 *            - I2C_INT_RX_OVER: I2C RX FIFO overflow interrupt. When the receive buffer is completely filled to 40 and an additional byte is received from an external I2C device.
 *            - I2C_INT_RX_UNDER: I2C RX FIFO underflow interrupt. When the processor attempts to read the receive buffer when it is empty.
 * \param[in] NewState: Mask the specified I2C interrupt or not.
 *            This parameter can be one of the following values:
 *            - ENABLE: Mask the specified I2C interrupt.
 *            - DISABLE: Unmask the specified I2C interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c0_init(void)
 * {
 *     I2C_INTConfig(I2C0, I2C_INT_STOP_DET | I2C_INT_RX_FULL, ENABLE);
 *     RamVectorTableUpdate(I2C0_VECTORn, (IRQ_Fun)I2C0_Handler);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = I2C0_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 * }
 * \endcode
 */
void I2C_INTConfig(I2C_TypeDef *I2Cx, uint16_t I2C_IT, FunctionalState NewState);

/**
 *
 * \brief   Clear the specified I2C interrupt pending bit.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] I2C_IT: Specified the I2C interrupt \ref x3g_I2C_interrupts_definition.
 *            This parameter can be one of the following values:
 *            - I2C_INT_GEN_CALL: I2C general call interrupt. When a general call address is received and it is acknowledged.
 *            - I2C_INT_START_DET: I2C start detect interrupt. When a start or restart condition has occurred on the I2C interface.
 *            - I2C_INT_STOP_DET: I2C stop detect interrupt. When a stop condition has occurred on the I2C interface.
 *            - I2C_INT_ACTIVITY: I2C activity interrupt. When I2C is activity on the bus.
 *            - I2C_INT_RX_DONE: I2C slave RX done interrupt. When the I2C is acting as a slave-transmitter and the master does not acknowledge a transmitted byte. This occurs on the last byte of the transmission, indicating that the transmission is done.
 *            - I2C_INT_TX_ABRT: I2C TX abort interrupt. When an I2C transmitter is unable to complete the intended actions on the contents of the transmit FIFO.
 *            - I2C_INT_RD_REQ: I2C slave RX request interrupt. When I2C is acting as a slave and another I2C master is attempting to read data from I2C.
 *            - I2C_INT_TX_EMPTY: I2C TX FIFO empty interrupt. When the transmit buffer is at or below the threshold value.
 *            - I2C_INT_TX_OVER: I2C TX FIFO overflow interrupt. When transmit buffer is filled to 24 and the processor attempts to issue another I2C command.
 *            - I2C_INT_RX_FULL: I2C RX FIFO full interrupt. When the receive buffer reaches or goes above the RX FIFO threshold value.
 *            - I2C_INT_RX_OVER: I2C RX FIFO overflow interrupt. When the receive buffer is completely filled to 40 and an additional byte is received from an external I2C device.
 *            - I2C_INT_RX_UNDER: I2C RX FIFO underflow interrupt. When the processor attempts to read the receive buffer when it is empty.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void I2C0_Handler(void)
 * {
 *     if (I2C_GetINTStatus(I2C0, I2C_INT_STOP_DET) == SET)
 *     {
 *         //Add user code here.
 *         I2C_ClearINTPendingBit(I2C0, I2C_INT_STOP_DET);
 *     }
 * }
 * \endcode
 */
void I2C_ClearINTPendingBit(I2C_TypeDef *I2Cx, uint16_t I2C_IT);

/**
 * \brief   Set the I2C clock speed, the function need to be called when I2C disabled.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] I2C_ClockSpeed: Specified the I2C clock speed. This parameter must range from 1 to 1000000 (1MHz).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c_demo(void)
 * {
 *     I2C_SetClockSpeed(I2C0, 400000);
 * }
 * \endcode
 */
void I2C_SetClockSpeed(I2C_TypeDef *I2Cx, uint32_t I2C_ClockSpeed);

/**
 *
 * \brief  Config the I2C clock divider.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] ClockDiv: Specifies the I2C clock divider \ref x3g_I2C_Clock_Divider.
 *            This parameter can be one of the following values:
 *            - I2C_CLOCK_DIV_x: Where x can be 1, 2, 4, 8 to select the specified clock divider.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_i2c_init(void)
 * {
 *     I2C_ClkDivConfig(I2C0, I2C_CLOCK_DIV_1);
 * }
 * \endcode
 */
void I2C_ClkDivConfig(I2C_TypeDef *I2Cx, uint16_t ClockDiv);

/**
 *
 * \brief     Set slave device address.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] Address: Specifies the slave address which will be transmitted. This parameter must range from 0x0 to 0xFFFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint16_t slave_address = 0x55;
 *     I2C_SetSlaveAddress(I2C0, slave_address);
 * }
 * \endcode
 */
void I2C_SetSlaveAddress(I2C_TypeDef *I2Cx, uint16_t Address);


/**
 *
 * \brief   Write command through the I2Cx peripheral.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] command: Command of write or read \ref x3g_I2C_send_command.
 *            - I2C_READ_CMD: Read command. Data which want to receive can be 0 in this situation.
 *            - I2C_WRITE_CMD: Write command. Data which want to transmit can be 1 in this situation.
 * \param[in] data: Data which to be transmitted. This parameter must range from 0x0 to 0xFF.
 * \param[in] StopState: Whether a Stop is issued after the byte is sent or received \ref x3g_I2C_send_stop.
 *            - I2C_STOP_ENABLE: Send stop signal.
 *            - I2C_STOP_DISABLE: Do not send stop signal.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     I2C_SendCmd(I2C0, I2C_WRITE_CMD, 0xaa, I2C_STOP_DISABLE);
 * }
 * \endcode
 */
void I2C_SendCmd(I2C_TypeDef *I2Cx, I2CSendCommend_TypeDef command, uint8_t data,
                 I2CStopBit_TypeDef StopState);

/**
 *
 * \brief  Return the most recent received data by the I2Cx peripheral.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 *
 * \return The value of the received data.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t rx_count = 0;
 * uint8_t read_buf = 0;
 *
 * void I2C1_Handler(void)
 * {
 *     if (I2C_GetINTStatus(I2C1, I2C_INT_RX_FULL) == SET)
 *     {
 *         rx_count = I2C_GetRxFIFOLen(I2C1);
 *         for(uint8_t i = 0; i < rx_count; i++)
 *         {
 *             read_buf = I2C_ReceiveData(I2C1);
 *             APP_PRINT_INFO2("I2C1 rx_count:%d, read_buf:%d", rx_count, read_buf);
 *         }
 *         I2C_ClearINTPendingBit(I2C1, I2C_INT_RX_FULL);
 *     }
 * }
 * \endcode
 */
uint8_t I2C_ReceiveData(I2C_TypeDef *I2Cx);

/**
 *
 * \brief   Get data length in RX FIFO through the I2Cx peripheral.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t rx_count = 0;
 *
 * void I2C1_Handler(void)
 * {
 *     rx_count = I2C_GetRxFIFOLen(I2C1);
 * }
 * \endcode
 */
uint8_t I2C_GetRxFIFOLen(I2C_TypeDef *I2Cx);

/**
 *
 * \brief   Get data length in TX FIFO through the I2Cx peripheral.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     uint8_t data_len = I2C_GetTxFIFOLen(I2C0);
 * }
 * \endcode
 */
uint8_t I2C_GetTxFIFOLen(I2C_TypeDef *I2Cx);

/**
 *
 * \brief   Clear all I2C interrupt.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     I2C_ClearAllINT(I2C0);
 * }
 * \endcode
 */
void I2C_ClearAllINT(I2C_TypeDef *I2Cx);


/**
 *
 * \brief  Check whether the specified I2C flag is set or not.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] I2C_FLAG: Specifies the flag to check \ref x3g_I2C_flags_definition.
 *            This parameter can be one of the following values:
 *            - I2C_FLAG_SLV_HOLD_RX_FIFO_FULL: Indicates the bus hold in slave mode due to the RX FIFO being full and an additional byte being received.
 *            - I2C_FLAG_SLV_HOLD_TX_FIFO_EMPTY: Indicates the bus hold in slave mode for the read request when the TX FIFO is empty.
 *            - I2C_FLAG_MST_HOLD_RX_FIFO_FULL: Indicates the bus hold in master mode due to RX FIFO is full and additional byte has been received.
 *            - I2C_FLAG_MST_HOLD_TX_FIFO_EMPTY: Indicates the bus hold when the master holds the bus because of the TX FIFO being empty.
 *            - I2C_FLAG_SLV_ACTIVITY: Slave FSM activity status.
 *            - I2C_FLAG_MST_ACTIVITY: Master FSM activity status.
 *            - I2C_FLAG_RFF: Receive FIFO completely full.
 *            - I2C_FLAG_RFNE: Receive FIFO not empty.
 *            - I2C_FLAG_TFE: Transmit FIFO completely empty.
 *            - I2C_FLAG_TFNF: Transmit FIFO not full.
 *            - I2C_FLAG_ACTIVITY: I2C activity status.
 *
 * \return The new state of I2C_FLAG.
 * \retval SET: The specified I2C flag is set.
 * \retval RESET: The specified I2C flag is unset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c_test_code(void)
 * {
 *     uint8_t cnt = 0;
 *     for (cnt = 0; cnt < TEST_SIZE; cnt++)
 *     {
 *         I2C_SendCmd(I2C1, I2C_READ_CMD, 0, I2C_STOP_DISABLE);
 *     }
 *     while (I2C_GetFlagState(I2C1, I2C_FLAG_TFNF) == RESET);
 * }
 * \endcode
 */
FlagStatus I2C_GetFlagState(I2C_TypeDef *I2Cx, uint32_t I2C_FLAG);

/**
 *
 * \brief  Check whether the last I2Cx event is equal to the one passed as parameter.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] I2C_EVENT: Specifies the event to be checked about I2C Transmit Abort Status Register \ref x3g_I2C_transmit_Abort_Source.
 *      This parameter can be one of the following values:
 *      - ABRT_SLVRD_INTX: When the processor side responds to a slave mode request for data to be transmitted to a remote master and user send read command.
 *      - ABRT_SLV_ARBLOST: Slave lost the bus while transmitting data to a remote master.
 *      - ABRT_SLVFLUSH_TXFIFO: Slave has received a read command and some data exists in the TX FIFO so the slave issues a TX abort interrupt to flush old data in TX FIFO.
 *      - ARB_LOST: Master has lost arbitration or the slave transmitter has lost arbitration.
 *      - ABRT_MASTER_DIS: User tries to initiate a master operation with the master mode disabled.
 *      - ABRT_10B_RD_NORSTRT: The restart is disabled and the master sends a read command in 10-bit addressing mode.
 *      - ABRT_SBYTE_NORSTRT: The restart is disabled and the user is trying to send a start byte.
 *      - ABRT_HS_NORSTRT: The restart is disabled and the user is trying to use the master to transfer data in high speed mode.
 *      - ABRT_SBYTE_ACKDET: Master has sent a start byte and the start byte was acknowledged (wrong behavior).
 *      - ABRT_HS_ACKDET: Master is in high speed mode and the high speed master code was acknowledged (wrong behavior).
 *      - ABRT_GCALL_READ: Sent a general call but the user programmed the byte following the general call to be a read from the bus.
 *      - ABRT_GCALL_NOACK: Sent a general call and no slave on the bus acknowledged the general call.
 *      - ABRT_TXDATA_NOACK: Master sent data byte(s) following the address, it did not receive an acknowledge from the remote slave.
 *      - ABRT_10ADDR2_NOACK: Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
 *      - ABRT_10ADDR1_NOACK: Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
 *      - ABRT_7B_ADDR_NOACK: Master is in 7-bit addressing mode and the address sent was not acknowledged by any slave.
 *
 * \return  An ErrorStatus enumeration value.
 * \retval  SUCCESS: Last event is equal to the I2C_EVENT.
 * \retval  ERROR: Last event is different from the I2C_EVENT.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c_repeatread_demo(void)
 * {
 *     if (I2C_Success != I2C_RepeatRead(I2C1, I2C_WriteBuf, 2, I2C_ReadBuf, 4))
 *     {
 *          APP_PRINT_ERROR0("Send failed");
 *
 *          if (I2C_CheckEvent(I2C1, ABRT_7B_ADDR_NOACK) == SET)
 *          {
 *              APP_PRINT_ERROR0("Wrong addr");
 *          }
 *          if (I2C_CheckEvent(I2C1, ABRT_GCALL_NOACK) == SET)
 *          {
 *              APP_PRINT_ERROR0("General call nack");
 *          }
 *     }
 * }
 * \endcode
 */
FlagStatus I2C_CheckEvent(I2C_TypeDef *I2Cx, uint32_t I2C_EVENT);

/**
 *
 * \brief   Get the specified I2C interrupt status.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] I2C_IT: Specified the I2C interrupt \ref x3g_I2C_interrupts_definition.
 *            This parameter can be one of the following values:
 *            - I2C_INT_GEN_CALL: I2C general call interrupt. When a general call address is received and it is acknowledged.
 *            - I2C_INT_START_DET: I2C start detect interrupt. When a start or restart condition has occurred on the I2C interface.
 *            - I2C_INT_STOP_DET: I2C stop detect interrupt. When a stop condition has occurred on the I2C interface.
 *            - I2C_INT_ACTIVITY: I2C activity interrupt. When I2C is activity on the bus.
 *            - I2C_INT_RX_DONE: I2C slave RX done interrupt. When the I2C is acting as a slave-transmitter and the master does not acknowledge a transmitted byte. This occurs on the last byte of the transmission, indicating that the transmission is done.
 *            - I2C_INT_TX_ABRT: I2C TX abort interrupt. When an I2C transmitter is unable to complete the intended actions on the contents of the transmit FIFO.
 *            - I2C_INT_RD_REQ: I2C slave RX request interrupt. When I2C is acting as a slave and another I2C master is attempting to read data from I2C.
 *            - I2C_INT_TX_EMPTY: I2C TX FIFO empty interrupt. When the transmit buffer is at or below the threshold value.
 *            - I2C_INT_TX_OVER: I2C TX FIFO overflow interrupt. When transmit buffer is filled to 24 and the processor attempts to issue another I2C command.
 *            - I2C_INT_RX_FULL: I2C RX FIFO full interrupt. When the receive buffer reaches or goes above the RX FIFO threshold value.
 *            - I2C_INT_RX_OVER: I2C RX FIFO overflow interrupt. When the receive buffer is completely filled to 40 and an additional byte is received from an external I2C device.
 *            - I2C_INT_RX_UNDER: I2C RX FIFO underflow interrupt. When the processor attempts to read the receive buffer when it is empty.
 *
 * \return The new state of I2C_IT.
 * \retval SET: The specified I2C flag is set.
 * \retval RESET: The specified I2C flag is unset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void I2C0_Handler(void)
 * {
 *     if (I2C_GetINTStatus(I2C0, I2C_INT_STOP_DET) == SET)
 *     {
 *         //Add user code here.
 *         I2C_ClearINTPendingBit(I2C0, I2C_INT_STOP_DET);
 *     }
 * }
 * \endcode
 */
ITStatus I2C_GetINTStatus(I2C_TypeDef *I2Cx, uint32_t I2C_IT);

/**
 *
 * \brief   Enable or disable the I2Cx GDMA interface.
 *
 * \param[in] I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in] I2C_GDMAReq: Specifies the I2C GDMA transfer request to be enabled or disabled \ref x3g_I2C_GDMA_transfer_requests.
 *            This parameter can be one of the following values:
 *            - I2C_GDMAReq_Tx: TX buffer GDMA transfer request.
 *            - I2C_GDMAReq_Rx: RX buffer GDMA transfer request.
 * \param[in] NewState: New state of the selected I2C GDMA transfer request.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the I2Cx GDMA interface.
 *            - DISABLE: Disable the I2Cx GDMA interface.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     I2C_GDMACmd(I2C0, I2C_GDMAReq_Tx, ENABLE);
 * }
 * \endcode
 */
void I2C_GDMACmd(I2C_TypeDef *I2Cx, I2CGdmaTransferRequests_TypeDef I2C_GDMAReq,
                 FunctionalState NewState);

/**
 * \brief  Enable or disable the holding bus function when RX FIFO is full.
 * \param[in]  I2Cx: Where x can be 0 to 2 to select the I2C peripheral \ref x3g_I2C_Declaration.
 * \param[in]  NewState: New state of the holding bus function.
 *             This parameter can be one of the following values:
 *             - ENABLE: Enable the holding bus function when RX FIFO is full.
 *             - DISABLE: Disable the holding bus function when RX FIFO is full.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c0_demo(void)
 * {
 *     I2C_RxFIFOFullHoldCtrl(I2C0, ENABLE);
 * }
 * \endcode
 */
void I2C_RxFIFOFullHoldCtrl(I2C_TypeDef *I2Cx, FunctionalState NewState);

#ifdef __cplusplus
}
#endif

#endif /*__RTL876X_I2C_H*/

/** @} */ /* End of group 87x3g_I2C_Exported_Functions */
/** @} */ /* End of group 87x3g_I2C */


