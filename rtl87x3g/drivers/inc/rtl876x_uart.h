/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */


#ifndef _RTL876X_UART_H_
#define _RTL876X_UART_H_

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x.h"
#include <stdbool.h>
#include "rtl876x_uart_def.h"

/** @addtogroup 87x3g_UART UART
  * @brief UART driver module.
  * @{
  */
/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup 87x3g_UART_Exported_Constants UART Exported Constants
  * \{
  */

/**
 * \defgroup    87x3g_UART_FIFO_SIZE UART FIFO SIZE
 * \{
 */
#define UART_TX_FIFO_SIZE           16 //!< UART TX FIFO size is 16.
#define UART_RX_FIFO_SIZE           32 //!< UART RX FIFO size is 32.

/** End of 87x3g_UART_FIFO_SIZE
  * \}
  */

/**
 * \defgroup    87x3g_UART_Baudrate UART Baudrate
 * \{
 */
typedef enum
{
    BAUD_RATE_1200,    //!< UART baud rate is 1200 Hz.
    BAUD_RATE_4800,    //!< UART baud rate is 4800 Hz.
    BAUD_RATE_7200,    //!< UART baud rate is 7200 Hz.
    BAUD_RATE_9600,    //!< UART baud rate is 9600 Hz.
    BAUD_RATE_14400,   //!< UART baud rate is 14400 Hz.
    BAUD_RATE_19200,   //!< UART baud rate is 19200 Hz.
    BAUD_RATE_28800,   //!< UART baud rate is 28800 Hz.
    BAUD_RATE_38400,   //!< UART baud rate is 38400 Hz.
    BAUD_RATE_57600,   //!< UART baud rate is 57600 Hz.
    BAUD_RATE_76800,   //!< UART baud rate is 76800 Hz.
    BAUD_RATE_115200,  //!< UART baud rate is 115200 Hz.
    BAUD_RATE_128000,  //!< UART baud rate is 128000 Hz.
    BAUD_RATE_153600,  //!< UART baud rate is 153600 Hz.
    BAUD_RATE_230400,  //!< UART baud rate is 230400 Hz.
    BAUD_RATE_460800,  //!< UART baud rate is 460800 Hz.
    BAUD_RATE_500000,  //!< UART baud rate is 500000 Hz.
    BAUD_RATE_921600,  //!< UART baud rate is 921600 Hz.
    BAUD_RATE_1000000, //!< UART baud rate is 1000000 Hz.
    BAUD_RATE_1382400, //!< UART baud rate is 1382400 Hz.
    BAUD_RATE_1444400, //!< UART baud rate is 1444400 Hz.
    BAUD_RATE_1500000, //!< UART baud rate is 1500000 Hz.
    BAUD_RATE_1843200, //!< UART baud rate is 1843200 Hz.
    BAUD_RATE_2000000, //!< UART baud rate is 2000000 Hz.
    BAUD_RATE_3000000, //!< UART baud rate is 3000000 Hz.
    BAUD_RATE_4000000, //!< UART baud rate is 4000000 Hz.
} UartBaudRate_TypeDef;

/** End of 87x3g_UART_Baudrate
  * \}
  */

/**
 * \defgroup    87x3g_UART_Parity UART Parity
 * \{
 */
typedef enum
{
    UART_PARITY_NO_PARTY = 0x0, //!< Select no parity.
    UART_PARITY_ODD = 0x1, //!< Select odd parity.
    UART_PARITY_EVEN = 0x3, //!< Select even parity.
} UARTParity_TypeDef;

#define IS_UART_PARITY(PARITY) (((PARITY) == UART_PARITY_NO_PARTY) || \
                                ((PARITY) == UART_PARITY_ODD) || \
                                ((PARITY) == UART_PARITY_EVEN)) //!< Check if the input parameter is valid.

/** End of 87x3g_UART_Parity
  * \}
  */

/**
 * \defgroup    87x3g_UART_Stop_Bits UART Stop Bits
 * \{
 */
typedef enum
{
    UART_STOP_BITS_1 = 0x0, //!< 1-bit stop bits.
    UART_STOP_BITS_2 = 0x1, //!< 2-bit stop bits.
} UARTStopBits_TypeDef;

#define IS_UART_STOPBITS(STOP) (((STOP) == UART_STOP_BITS_1) || \
                                ((STOP) == UART_STOP_BITS_2)) //!< Check if the input parameter is valid.

/** End of 87x3g_UART_Stop_Bits
  * \}
  */

/**
 * \defgroup    87x3g_UART_Word_Length UART Word Length
 * \{
 */
typedef enum
{
    UART_WORD_LENGTH_7BIT = 0x0, //!< Data format is 7 bit word length.
    UART_WORD_LENGTH_8BIT = 0x1, //!< Data format is 8 bit word length.
} UARTWordLen_TypeDef;

#define IS_UART_WORD_LENGTH(LEN) ((((LEN)) == UART_WORD_LENGTH_7BIT) || \
                                  (((LEN)) == UART_WORD_LENGTH_8BIT)) //!< Check if the input parameter is valid.

/** End of 87x3g_UART_Word_Length
  * \}
  */

/**
 * \defgroup    87x3g_UART_Hardware_Flow_Control UART Hardware Flow Control
 * \{
 */
typedef enum
{
    UART_HW_FLOW_CTRL_DISABLE = 0x0, //!< Disable auto flow control.
    UART_HW_FLOW_CTRL_ENABLE = 0x1, //!< Enable auto flow control.
} UARTHwFlowCtrl_TypeDef;

#define IS_UART_AUTO_FLOW_CTRL(CTRL) (((CTRL) == UART_HW_FLOW_CTRL_ENABLE) || \
                                      ((CTRL) == UART_HW_FLOW_CTRL_DISABLE)) //!< Check if the input parameter is valid.

/** End of 87x3g_UART_Hardware_Flow_Control
  * \}
  */

/**
 * \defgroup    87x3g_UART_DMA UART DMA
 * \{
 */
typedef enum
{
    UART_DMA_DISABLE = 0x0, //!< Disable UART DMA.
    UART_DMA_ENABLE  = 0x1, //!< Enable UART DMA.
} UARTDma_TypeDef;

#define IS_UART_DMA_CFG(CFG) (((CFG) == UART_DMA_ENABLE) || \
                              ((CFG) == UART_DMA_DISABLE)) //!< Check if the input parameter is valid.

/** End of 87x3g_UART_DMA
  * \}
  */

/**
 * \defgroup    87x3g_UART_Rx_idle_time UART RX Idle Time
 * \{
 */
typedef enum
{
    UART_RX_IDLE_1BYTE = 0x0, //!< RX idle timeout value is 8 bit time.
    UART_RX_IDLE_2BYTE = 0x1, //!< RX idle timeout value is 16 bit time.
    UART_RX_IDLE_4BYTE = 0x2, //!< RX idle timeout value is 32 bit time.
    UART_RX_IDLE_8BYTE = 0x3, //!< RX idle timeout value is 64 bit time.
    UART_RX_IDLE_16BYTE = 0x4, //!< RX idle timeout value is 128 bit time.
    UART_RX_IDLE_32BYTE = 0x5, //!< RX idle timeout value is 256 bit time.
    UART_RX_IDLE_64BYTE = 0x6, //!< RX idle timeout value is 512 bit time.
    UART_RX_IDLE_128BYTE = 0x7, //!< RX idle timeout value is 1024 bit time.
    UART_RX_IDLE_256BYTE = 0x8, //!< RX idle timeout value is 2048 bit time.
    UART_RX_IDLE_512BYTE = 0x9, //!< RX idle timeout value is 4096 bit time.
    UART_RX_IDLE_1024BYTE = 0xA, //!< RX idle timeout value is 8192 bit time.
    UART_RX_IDLE_2048BYTE = 0xB, //!< RX idle timeout value is 16384 bit time.
    UART_RX_IDLE_4096BYTE = 0xC, //!< RX idle timeout value is 32768 bit time.
    UART_RX_IDLE_8192BYTE = 0xD, //!< RX idle timeout value is 65535 bit time.
    UART_RX_IDLE_16384BYTE = 0xE, //!< RX idle timeout value is 131072 bit time.
    UART_RX_IDLE_32768BYTE = 0xF, //!< RX idle timeout value is 262144 bit time.
} UARTTimeout_TypeDef;

#define IS_UART_IDLE_TIME(TIME) ((TIME) <= 0x0F) //!< Check if the input parameter is valid.

/** End of 87x3g_UART_Rx_idle_time
  * \}
  */

/**
 * \defgroup    87x3g_UART_RX_FIFO_Level UART RX FIFO Level
 * \{
 */
typedef enum
{
    UART_RX_FIFO_TRIGGER_LEVEL_1BYTE = 0x1, //!< Receiver FIFO interrupt trigger level is 1 byte.
    UART_RX_FIFO_TRIGGER_LEVEL_4BYTE = 0x4, //!< Receiver FIFO interrupt trigger level is 4 bytes.
    UART_RX_FIFO_TRIGGER_LEVEL_8BYTE = 0x8, //!< Receiver FIFO interrupt trigger level is 8 bytes.
    UART_RX_FIFO_TRIGGER_LEVEL_14BYTE = 0xE, //!< Receiver FIFO interrupt trigger level is 14 bytes.
} UARTRxFifoTriggerLevel_TypeDef;

#define IS_UART_RX_FIFO_TRIGGER_LEVEL(BYTES) ((BYTES) <= 29) //!< Check if the input parameter is valid.

/** End of 87x3g_UART_RX_FIFO_Level
  * \}
  */

/**
 * \defgroup    87x3g_UART_Interrupts_Definition UART Interrupts Definition
 * \{
 */
#define UART_INT_RD_AVA                 BIT0 //!< Receive data avaliable interrupt, includes RX FIFO trigger level or RX timeout.
#define UART_INT_TX_FIFO_EMPTY          BIT1 //!< TX FIFO empty interrupt.
#define UART_INT_RX_LINE_STS            BIT2 //!< Receiver line status interrupt.
#if UART_SUPPORT_TX_DONE
#define UART_INT_TX_DONE                BIT4 //!< TX done(TX FIFO empty and TX waveform sent done) interrupt.
#endif
#if UART_SUPPORT_TX_THD
#define UART_INT_TX_THD                 BIT5 //!< TX FIFO threshold interrupt. TX FIFO level is less than or equal to TX FIFO threshold.
#endif
#define UART_INT_RX_IDLE                BIT7 //!< RX bus idle interrupt.

#define IS_UART_INT(INT) ((((INT) & 0xFFFFFF80) == 0x00) && ((INT) != 0x00)) //!< Check if the input parameter is valid.

#define IS_UART_GET_INT(INT) ((INT) & (UART_INT_RD_AVA | \
                                       UART_INT_TX_FIFO_EMPTY | \
                                       UART_INT_RX_LINE_STS | \
                                       UART_INT_TX_DONE | \
                                       UART_INT_TX_THD | \
                                       UART_INT_RX_IDLE)) //!< Check if the input parameter is valid.

/** End of 87x3g_UART_Interrupts_Definition
  * \}
  */

/**
 * \defgroup    87x3g_UART_Interrupt_Identifier UART Interrupt Identifier
 * \{
 */
#define UART_INT_PENDING                ((uint16_t)(0x01 << 0)) //!< Indicates whether an interrupt is pending.
#define UART_INT_ID_LINE_STATUS         ((uint16_t)(0x03 << 1)) //!< RX line status interrupt identification.
#define UART_INT_ID_RX_LEVEL_REACH      ((uint16_t)(0x02 << 1)) //!< RX trigger level reached interrupt identification.
#define UART_INT_ID_RX_DATA_TIMEOUT     ((uint16_t)(0x06 << 1)) //!< RX FIFO data timeout interrupt identification.
#define UART_INT_ID_TX_FIFO_EMPTY       ((uint16_t)(0x01 << 1)) //!< TX FIFO empty interrupt identification.

#define IS_UART_INT_ID(ID) (((ID) == UART_INT_ID_LINE_STATUS) || \
                            ((ID) == UART_INT_ID_RX_LEVEL_REACH) || \
                            ((ID) == UART_INT_ID_RX_DATA_TIMEOUT) || \
                            ((ID) == UART_INT_ID_TX_FIFO_EMPTY)) //!< Check if the input parameter is valid.


/** End of 87x3g_UART_Interrupt_Identifier
  * \}
  */

/**
 * \defgroup    87x3g_UART_Flag UART Flag
 * \{
 */
#define UART_FLAG_RX_DATA_AVA           BIT0 //!< RX FIFO data avaliable indicator. At least one character has been received and transferred into the receiver buffer register or the FIFO.
#define UART_FLAG_RX_OVERRUN            BIT1 //!< RX FIFO overrun error indicator. Indicates that data in the RX FIFO was not read by the CPU before the next character was transferred into the RX FIFO.
#define UART_FLAG_RX_PARITY_ERR         BIT2 //!< Parity error indicator. Indicates that the received data character does not have the correct even or odd parity. 
#define UART_FLAG_RX_FRAME_ERR          BIT3 //!< Framing error indicator. The received character at the top of the FIFO did not have a valid stop bit.
#define UART_FLAG_RX_BREAK_ERR          BIT4 //!< Break interrupt indicator. Set to logic 1 whenever the received data input is held in the spacing (logic 0) state for a longer than a full word transmission time.
#define UART_FLAG_TX_FIFO_EMPTY         BIT5 //!< Transmitter holding register (THR) empty indicator.
#define UART_FLAG_TX_EMPTY              BIT6 //!< Transmitter holding register (THR) and the transmitter shift register (TSR) are both empty.
#define UART_FLAG_RX_FIFO_ERR           BIT7 //!< At least one parity error, framing error or break indication in the FIFO.
#define UART_FLAG_RX_IDLE               BIT9 //!< Only to show difference cause the address of UART RX idle flag is isolate.
#if UART_SUPPORT_TX_DONE
#define UART_FLAG_TX_DONE               BIT10 //!< TX done(TX FIFO empty and TX waveform sent done).
#endif
#if UART_SUPPORT_TX_THD
#define UART_FLAG_TX_THD                BIT11 //!< TX FIFO threshold indicator. TX FIFO level is less than or equal to TX FIFO threshold.
#endif

#define IS_UART_GET_FLAG(FLAG) (((FLAG) == UART_FLAG_RX_DATA_AVA) || \
                                ((FLAG) == UART_FLAG_RX_OVERRUN) || \
                                ((FLAG) == UART_FLAG_RX_PARITY_ERR) || \
                                ((FLAG) == UART_FLAG_RX_FRAME_ERR) || \
                                ((FLAG) == UART_FLAG_RX_BREAK_ERR) || \
                                ((FLAG) == UART_FLAG_TX_FIFO_EMPTY) || \
                                ((FLAG) == UART_FLAG_TX_EMPTY) || \
                                ((FLAG) == UART_FLAG_RX_FIFO_ERR) || \
                                ((FLAG) == UART_FLAG_TX_DONE) || \
                                ((FLAG) == UART_FLAG_TX_THD) || \
                                ((FLAG) == UART_FLAG_RX_IDLE)) //!< Check if the input parameter is valid.

/** End of 87x3g_UART_Flag
  * \}
  */

/**
 * \defgroup    87x3g_UART_Interrupts_Mask_Definition UART Interrupts Mask Definition
 * \{
 */
#define UART_INT_MASK_RD_AVA            BIT0 //!< Mask received data avaliable interrupt(RX fifo trigger level or timeout).
#define UART_INT_MASK_TX_FIFO_EMPTY     BIT1 //!< Mask transmitter FIFO empty interrupt.
#define UART_INT_MASK_RX_LINE_STS       BIT2 //!< Mask receiver line status interrupt.
#define UART_INT_MASK_RX_BREAK          BIT4 //!< Mask RX break interrupt.
#define UART_INT_MASK_RX_IDLE           BIT5 //!< Mask RX idle timeout interrupt.
#if UART_SUPPORT_TX_DONE
#define UART_INT_MASK_TX_DONE           BIT6 //!< Mask TX done(TX shift register empty and TX FIFO empty) interrupt.
#endif
#if UART_SUPPORT_TX_THD
#define UART_INT_MASK_TX_THD            BIT7 //!< Mask TX FIFO threshold interrupt.
#endif

#define IS_UART_INT_MASK(INT) ((INT) & (UART_INT_MASK_RD_AVA | \
                                        UART_INT_MASK_TX_FIFO_EMPTY | \
                                        UART_INT_MASK_RX_LINE_STS | \
                                        UART_INT_MASK_RX_BREAK | \
                                        UART_INT_MASK_RX_IDLE | \
                                        UART_INT_MASK_TX_DONE | \
                                        UART_INT_MASK_TX_THD)) //!< Check if the input parameter is valid.

/** End of 87x3g_UART_Interrupts_Mask_Definition
  * \}
  */

/** @cond private
  * @defgroup 87x3g_Uart_Tx_Rx_FIFO_CLEAR_BIT Uart FIFO Clear Bits
  * @{
  */
#define FCR_CLEAR_RX_FIFO_Set           ((uint32_t)(1 << 1))
#define FCR_CLEAR_RX_FIFO_Reset         ((uint32_t)~(1 << 1))
#define FCR_CLEAR_TX_FIFO_Set           ((uint32_t)(1 << 2))
#define FCR_CLEAR_TX_FIFO_Reset         ((uint32_t)~(1 << 2))

/** End of Group 87x3g_Uart_Tx_Rx_FIFO_CLEAR_BIT
  * @}
  * @endcond
  */

/** @defgroup 87x3g_UART_Clock_Divider UART Clock Divider
  * @{
  */
#define UART_CLOCK_DIV_1                    ((uint16_t)0x0) //!< UART clock divider is set to 1.
#define UART_CLOCK_DIV_2                    ((uint16_t)0x1) //!< UART clock divider is set to 2.
#define UART_CLOCK_DIV_4                    ((uint16_t)0x2) //!< UART clock divider is set to 4.
#define UART_CLOCK_DIV_16                   ((uint16_t)0x3) //!< UART clock divider is set to 16.
#define IS_UART_DIV(DIV)              (((DIV) == UART_CLOCK_DIV_1) || \
                                       ((DIV) == UART_CLOCK_DIV_2) || \
                                       ((DIV) == UART_CLOCK_DIV_4) || \
                                       ((DIV) == UART_CLOCK_DIV_16)) //!< Check if the input parameter is valid.
/** End of group 87x3g_UART_Clock_Divider
  * @}
  */

/** End of 87x3g_UART_Exported_Constants
  * \}
  */


/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup 87x3g_UART_Exported_Types UART Exported Types
  * \{
  */

/**
 * \brief       UART initialize parameters.
 */
typedef struct
{
    uint16_t ovsr_adj;              /*!< Specifies the baudrate setting of ovsr_adj, please refer to UART_BaudRate_Table in API \ref UART_ComputeDiv.*/
    uint16_t div;                  /*!< Specifies the baudrate setting of div, please refer to UART_BaudRate_Table in API \ref UART_ComputeDiv .*/
    uint16_t ovsr;                 /*!< Specifies the baudrate setting of ovsr, please refer to UART_BaudRate_Table in API \ref UART_ComputeDiv .*/
    UARTWordLen_TypeDef wordLen;   /*!< Specifies the UART word length.
                                        This parameter can be a value of @ref x3g_UART_Word_Length. */
    UARTStopBits_TypeDef stopBits; /*!< Specifies the UART stop bits.
                                        This parameter can be a value of @ref x3g_UART_Stop_Bits. */
    UARTParity_TypeDef parity;     /*!< Specifies the UART parity.
                                        This parameter can be a value of @ref x3g_UART_Parity. */
    uint8_t txTriggerLevel;            /*!< Specifies the TX threshold level. This parameter must range from 1 to 29.*/
    uint8_t rxTriggerLevel;            /*!< Specifies the RX threshold level. This parameter must range from 1 to 29.*/
    UARTTimeout_TypeDef idle_time;  /*!< Specifies the UART RX idle time.
                                        This parameter can be a value of @ref x3g_UART_Rx_idle_time. */
    uint8_t autoFlowCtrl;   /*!< Specifies the UART hardware auto flow control.
                                        This parameter can be a value of @ref x3g_UART_Hardware_Flow_Control. */
    uint8_t dmaEn;                 /*!< Specifies the DMA mode.
                                        This parameter must be a value of DISABLE and ENABLE. */
    uint8_t TxDmaEn;               /*!< Specifies the TX DMA mode.
                                        This parameter must be a value of DISABLE and ENABLE. */
    uint8_t RxDmaEn;               /*!< Specifies the RX DMA mode.
                                        This parameter must be a value of DISABLE and ENABLE. */
    uint8_t TxWaterlevel;          /*!< Specifies the DMA TX water level. This parameter must range from 1 to 16.*/
    uint8_t RxWaterlevel;          /*!< Specifies the DMA RX water level. This parameter must range from 1 to 31.*/
} UART_InitTypeDef;

/** End of 87x3g_UART_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/

/** @defgroup 87x3g_UART_Exported_Functions UART Exported Functions
  * @{
  */

/**
 * \brief   Initialize the selected UART peripheral according to the specified
 *          parameters in UART_InitStruct.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in]   UART_InitStruct: Pointer to a \ref UART_InitTypeDef structure that
 *              contains the configuration information for the selected UART peripheral.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     UART_DeInit(UART0);
 *
 *     RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE);
 *
 *     UART_InitTypeDef UART_InitStruct;
 *     UART_StructInit(&UART_InitStruct);
 *     UART_InitStruct.UART_Div         = 20;
 *     UART_InitStruct.UART_Ovsr        = 12;
 *     UART_InitStruct.UART_OvsrAdj     = 0x252;
 *     UART_InitStruct.UART_RxThdLevel  = 16;
 *    //Add other initialization parameters that need to be configured here.
 *     UART_Init(UART0, &UART_InitStruct);
 * }
 * \endcode
 */
void UART_Init(UART_TypeDef *UARTx, UART_InitTypeDef *UART_InitStruct);

/**
 * \brief   Enable or Disable UART hw clock.
 *
 * \param[in] UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in] enable: Enable or disable UART hw clock.
 *            - true:  enable UART hw clock.
 *            - false: disable UART hw clock.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_uart_init(void)
 * {
 *    UART_HwClock(UART0, true);
 * }
 * \endcode
 */
void UART_HwClock(UART_TypeDef *UARTx, bool enable);

/**
 *
 * \brief   Disable the UART peripheral clock, and restore registers to their default values.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void driver_uart_init(void)
 * {
 *    UART_DeInit(UART0);
 * }
 * \endcode
 */
void UART_DeInit(UART_TypeDef *UARTx);

/**
 *
 * \brief   Set baud rate of UART.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in]   baud_rate: Baud rate to be set. The value can refer to \ref UartBaudRate_TypeDef.
 *
 * \return   Specified the UART baud rate that to be set or not.
 * \retval 0   The baud_rate was set successfully.
 * \retval 1   The selected baud_rate was not supported.
 *
 * <b>Example usage</b>
 * \code{.c}
  * void driver_uart_init(void)
 * {
 *     UART_SetBaudRate(UART0, BAUD_RATE_115200);
 * }
 * \endcode
 */
uint8_t UART_SetBaudRate(UART_TypeDef *UARTx, UartBaudRate_TypeDef baud_rate);

/**
 *
 * \brief   Fills each UART_InitStruct member with its default value.
 *
 * \note   The default settings for the UART_InitStruct member are shown in the following table:
 *         | UART_InitStruct Member   | Default Value                  |
 *         |:------------------------:|:------------------------------:|
 *         | UART_Div                 | 17                             |
 *         | UART_Ovsr                | 15                             |
 *         | UART_OvsrAdj             | 0x52A                          |
 *         | UART_Parity              | \ref UART_PARITY_NO_PARTY      |
 *         | UART_StopBits            | \ref UART_STOP_BITS_1          |
 *         | UART_WordLen             | \ref UART_WORD_LENGTH_8BIT     |
 *         | UART_DmaEn               | \ref DISABLE                   |
 *         | UART_HardwareFlowControl | \ref UART_HW_FLOW_CTRL_DISABLE |
 *         | UART_TxThdLevel          | 16                             |
 *         | UART_RxThdLevel          | 16                             |
 *         | UART_IdleTime            | \ref UART_RX_IDLE_2BYTE        |
 *         | UART_TxWaterLevel        | 15                             |
 *         | UART_RxWaterLevel        | 1                              |
 *         | UART_TxDmaEn             | DISABLE                        |
 *         | UART_RxDmaEn             | DISABLE                        |
 *
 * \param[in]   UART_InitStruct: Pointer to an \ref UART_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void driver_uart_init(void)
 * {
 *     UART_DeInit(UART0);
 *
 *     RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE);
 *
 *     UART_InitTypeDef UART_InitStruct;
 *     UART_StructInit(&UART_InitStruct);
 *     UART_InitStruct.UART_Div         = 20;
 *     UART_InitStruct.UART_Ovsr        = 12;
 *     UART_InitStruct.UART_OvsrAdj     = 0x252;
 *     UART_InitStruct.UART_RxThdLevel  = 16;
 *     //Add other initialization parameters that need to be configured here.
 *     UART_Init(UART0, &UART_InitStruct);
 * }
 * \endcode
 */
void UART_StructInit(UART_InitTypeDef *UART_InitStruct);

/**
 * \brief   Mask or unmask the specified UART interrupts.
 *
 * \param[in] UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in] UART_INT_MASK: Specifies the UART interrupts sources to be masked or unmasked \ref x3g_UART_Interrupts_Mask_Definition.
 *      This parameter can be any combination of the following values:
 *      - UART_INT_MASK_RD_AVA: Mask received data avaliable interrupt(RX fifo trigger level or timeout).
 *      - UART_INT_MASK_TX_FIFO_EMPTY: Mask transmitter FIFO empty interrupt.
 *      - UART_INT_MASK_RX_LINE_STS: Mask receiver line status interrupt.
 *      - UART_INT_MASK_RX_BREAK: Mask RX break interrupt.
 *      - UART_INT_MASK_RX_IDLE: Mask RX idle timeout interrupt.
 *      - UART_INT_MASK_TX_DONE: Mask TX done(TX shift register empty and TX FIFO empty) interrupt.
 *      - UART_INT_MASK_TX_THD: Mask TX FIFO threshold interrupt.
 * \param[in] NewState: New state of the specified UART interrupts.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     UART_DeInit(UART0);
 *
 *     RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE);
 *
 *     UART_InitTypeDef UART_InitStruct;
 *     UART_StructInit(&UART_InitStruct);
 *     UART_InitStruct.UART_Div         = 20;
 *     UART_InitStruct.UART_Ovsr        = 12;
 *     UART_InitStruct.UART_OvsrAdj     = 0x252;
 *     UART_InitStruct.UART_RxThdLevel  = 16;
 *     //Add other initialization parameters that need to be configured here.
 *     UART_Init(UART0, &UART_InitStruct);
 *
 *     UART_MaskINTConfig(UART0, UART_INT_MASK_RD_AVA, ENABLE);
 *     UART_INTConfig(UART0, UART_INT_RD_AVA, ENABLE);
 *     UART_MaskINTConfig(UART0, UART_INT_MASK_RD_AVA, DISABLE);
 * }
 * \endcode
 */
void UART_MaskINTConfig(UART_TypeDef *UARTx, uint32_t UART_INT_MASK,
                        FunctionalState NewState);

/**
 * \brief   Receive data from RX FIFO.
 *
 * \param[in]  UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[out] outBuf: Buffer to store data which read from RX FIFO.
 * \param[in]  count: Length of data to be read.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data[32] = {10};
 *     UART_ReceiveData(UART0, data, 10);
 * }
 * \endcode
 */
void UART_ReceiveData(UART_TypeDef *UARTx, uint8_t *outBuf, uint16_t count);

/**
 * \brief   Send data to TX FIFO directly.
 * \param[in] UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in] inBuf: Buffer of data to be written to TX FIFO. This parameter must range from 0x0 to 0xFF.
 * \param[in] count: Length of data to be written. This parameter must range from 0x1 to 0xFFFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data[] = "UART demo";
 *     UART_SendData(UART0, data, sizeof(data));
 * }
 * \endcode
 */
void UART_SendData(UART_TypeDef *UARTx, const uint8_t *inBuf, uint16_t count);

/**
 *
 * \brief   Send data to TX FIFO by polling mode.
 * \param[in] UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in] data: Buffer of data to be written to TX FIFO. This parameter must range from 0x0 to 0xFF.
 * \param[in] len: Length of data to be written. This parameter must range from 0x1 to 0xFFFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void uart_demo(void)
 * {
 *     uint8_t data[] = "UART demo";
 *     UART_TxData(UART0, data, sizeof(data));
 * }
 * \endcode
 */
void UART_TxData(UART_TypeDef *UARTx, uint8_t *data, uint32_t len);

/**
 * \brief   Set UART communication parameters.
 *
 * \param[in] UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in] wordLen: Data width of the selected UART peripheral, please refer to \ref x3g_UART_Word_Length.
 *            This parameter can be one of the following values:
 *            \arg UART_WORD_LENGTH_7BIT: 7-bit data length.
 *            \arg UART_WORD_LENGTH_8BIT: 8-bit data length.
 * \param[in] parity: Parity of the selected UART peripheral, please refer to \ref x3g_UART_Stop_Bits.
 *            This parameter can be one of the following values:
 *            \arg UART_STOP_BITS_1: 1-bit stop bit.
 *            \arg UART_STOP_BITS_2: 2-bit stop bit.
 * \param[in] stopBits: Stop bits of the selected UART peripheral, please refer to \ref x3g_UART_Parity.
 *            This parameter can be one of the following values:
 *            \arg UART_PARITY_NO_PARTY: No parity.
 *            \arg UART_PARITY_ODD: Odd parity.
 *            \arg UART_PARITY_EVEN: Even parity.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint16_t word_len = UART_WORD_LENGTH_8BIT;
 *     uint16_t parity = UART_PARITY_NO_PARTY;
 *     uint16_t stop_bits = UART_STOP_BITS_1;
 *     UART_SetParams(UART0, wordLen, parity, stopBits);
 * }
 * \endcode
 */
void UART_SetParams(UART_TypeDef *UARTx, uint16_t wordLen, uint16_t parity, uint16_t stopBits);

/**
 * \brief   Enables or disables the specified UART interrupts.
 *
 * \param[in] UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in] UART_IT: Specified the UART interrupt that to be enabled or disabled \ref x3g_UART_Interrupts_Definition.
 *            This parameter can be any combination of the following values:
 *            \arg UART_INT_RD_AVA: Rx data avaliable interrupt.
 *            \arg UART_INT_TX_FIFO_EMPTY: TX FIFO empty interrupt.
 *            \arg UART_INT_RX_LINE_STS: RX line status interrupt.
 *            \arg UART_INT_TX_DONE: TX done(TX FIFO empty and TX waveform sent done) interrupt.
 *            \arg UART_INT_TX_THD: TX threshold(FIFO data length <= thredhold) interrupt.
 *            \arg UART_INT_RX_IDLE: RX bus idle interrupt.
 * \param[in] newState: New state of the specified UART interrupt.
 *      This parameter can be one of the following values:
 *      - ENABLE: Enable the specified UART interrupt.
 *      - DISABLE: Disable the specified UART interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     UART_DeInit(UART0);
 *
 *     RCC_PeriphClockCmd(APBPeriph_UART0, APBPeriph_UART0_CLOCK, ENABLE);
 *
 *     UART_InitTypeDef UART_InitStruct;
 *     UART_StructInit(&UART_InitStruct);
 *     UART_InitStruct.UART_Div         = 20;
 *     UART_InitStruct.UART_Ovsr        = 12;
 *     UART_InitStruct.UART_OvsrAdj     = 0x252;
 *     UART_InitStruct.UART_RxThdLevel  = 16;
 *     //Add other initialization parameters that need to be configured here.
 *     UART_Init(UART0, &UART_InitStruct);
 *
 *     UART_INTConfig(UART0, UART_INT_RD_AVA, ENABLE);
 * }
 * \endcode
 */
void UART_INTConfig(UART_TypeDef *UARTx, uint32_t UART_IT, FunctionalState newState);

/**
 * \brief  Check whether the specified UART flag is set or not.
 *
 * \param[in] UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in] UART_FLAG: Specified UART flag to check \ref x3g_UART_Flag.
 *            This parameter can be one of the following values:
 *            - UART_FLAG_RX_DATA_AVA:RX FIFO data available. At least one character has been received and transferred into the receiver buffer register or the FIFO.
 *            - UART_FLAG_RX_OVERRUN: RX FIFO overrun error. Indicates that data in the RX FIFO was not read by the CPU before the next character was transferred into the RX FIFO.
 *            - UART_FLAG_RX_PARITY_ERR: Parity error. Indicates that the received data character does not have the correct even or odd parity.
 *            - UART_FLAG_RX_FRAME_ERR: Framing error. The received character at the top of the FIFO did not have a valid stop bit.
 *            - UART_FLAG_RX_BREAK_ERR: Break error. Set to logic 1 whenever the received data input is held in the spacing (logic 0) state for a longer than a full word transmission time.
 *            - UART_FLAG_TX_FIFO_EMPTY: Transmitter holding register (THR) empty.
 *            - UART_FLAG_TX_EMPTY: Transmitter holding register (THR) and the transmitter shift register (TSR) are both empty.
 *            - UART_FLAG_RX_FIFO_ERR: At least one parity error, framing error or break indication in the FIFO.
 *            - UART_FLAG_RX_IDLE: RX idle timeout. Only to show difference cause the address of UART RX idle flag is isolate.
 *            - UART_FLAG_TX_DONE:TX done(TX FIFO empty and TX waveform sent done).
 *            - UART_FLAG_TX_THD: TX FIFO threshold indicator. TX FIFO level is less than or equal to TX FIFO threshold.
 *
 * \return New status of UART flag.
 *         \retval SET: The specified UART flag bit is set.
 *         \retval RESET: The specified UART flag is not set.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_senddata_continuous(UART_TypeDef *UARTx, const uint8_t *pSend_Buf, uint16_t vCount)
 * {
 *     uint8_t count;
 *
 *     while (vCount / UART_TX_FIFO_SIZE > 0)
 *     {
 *         while (UART_GetFlagState(UARTx, UART_FLAG_TX_FIFO_EMPTY) == 0);
 *         for (count = UART_TX_FIFO_SIZE; count > 0; count--)
 *         {
 *             UARTx->UART_RBR_THR = *pSend_Buf++;
 *         }
 *         vCount -= UART_TX_FIFO_SIZE;
 *     }
 *
 *     while (UART_GetFlagState(UARTx, UART_FLAG_TX_FIFO_EMPTY) == 0);
 *     while (vCount--)
 *     {
 *         UARTx->UART_RBR_THR = *pSend_Buf++;
 *     }
 * }
 * \endcode
 */
FlagStatus UART_GetFlagState(UART_TypeDef *UARTx, uint32_t UART_FLAG);

/**
 * \brief   Get UART line status.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 *
 * \return   Line status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t line_status = UART_GetLineStatus(UART0);
 *
 * if (line_status & UART_FLAG)
 * {
 *     //Add user code here.
 * }
 *
 * \endcode
 */
uint8_t UART_GetLineStatus(UART_TypeDef *UARTx);

/**
 * \brief   Config the specified UART loopback function.
 *
 * \param[in] UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in] NewState: New state of UART loopback function.
 *      This parameter can be one of the following values:
 *      - ENABLE: Enable the specified UART loopback function. In the loopback mode, data that is transmitted is immediately received.
 *      - DISABLE: Disable the specified UART loopback function, keep in normal operation.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_LoopBackCmd(UART0, ENABLE);
 * }
 * \endcode
 */
void UART_LoopBackCmd(UART_TypeDef *UARTx, FunctionalState NewState);

/**
 *
 * \brief   Baudrate convert to UartBaudRate_TypeDef.
 *
 * \param[in]   baudrate: Select UART uint32_t baudrate. This parameter must range from 0x1 to 0xFFFFFFFF.
 *
 * \return   The converted UartBaudRate_TypeDef baud rate or 0xff.
 * \retval baudrate  UartBaudRate_TypeDef baudrate.
 * \retval 0xff      The selected baud_rate was not supported.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void uart_demo(void)
 * {
 *     UART_ConvUartBaudRate(115200);
 * }
 * \endcode
 */
UartBaudRate_TypeDef UART_ConvUartBaudRate(uint32_t baudrate);

/**
 *
 * \brief   UartBaudRate_TypeDef convert to baudrate.
 *
 * \param[in] baudrate: Select UART baudrate \ref UartBaudRate_TypeDef.
 *
 * \return   The converted UART uint32_t baud rate or 0.
 * \retval baudrate  UART uint32_t baudrate.
 * \retval 0         The selected baud_rate was not supported.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void uart_demo(void)
 * {
 *     UART_ConvRateValue(BAUD_RATE_115200);
 * }
 * \endcode
 */
uint32_t UART_ConvRateValue(UartBaudRate_TypeDef baudrate);

/**
 *
 * \brief   According to baudrate get UART param.
 *
 * \note   The three parameters div, ovsr, and ovsr_adj configure the baud rate calibration settings for UART, as shown in the UART_BaudRate_Table below.
 *         | Baudrate    |   Div     |   Ovsr    |   Ovsr_adj   |
 *         |:-----------:|:---------:|:---------:|:-------------|
 *         | 1200Hz      |   2589    |   7       |   0x7F7      |
 *         | 2400Hz      |   1200    |   8       |   0x3EF      |
 *         | 4800Hz      |   600     |   8       |   0x3EF      |
 *         | 9600Hz      |   271     |   10      |   0x24A      |
 *         | 14400Hz     |   271     |   5       |   0x222      |
 *         | 19200Hz     |   165     |   7       |   0x5AD      |
 *         | 28800Hz     |   110     |   7       |   0x5AD      |
 *         | 38400Hz     |   85      |   7       |   0x222      |
 *         | 57600Hz     |   55      |   7       |   0x5AD      |
 *         | 76800Hz     |   35      |   9       |   0x7EF      |
 *         | 115200Hz    |   20      |   12      |   0x252      |
 *         | 128000Hz    |   25      |   7       |   0x555      |
 *         | 153600Hz    |   15      |   12      |   0x252      |
 *         | 230400Hz    |   10      |   12      |   0x252      |
 *         | 460800Hz    |   5       |   12      |   0x252      |
 *         | 500000Hz    |   8       |   5       |   0          |
 *         | 921600Hz    |   4       |   5       |   0x3F7      |
 *         | 1000000Hz   |   4       |   5       |   0          |
 *         | 1382400Hz   |   2       |   9       |   0x2AA      |
 *         | 1444400Hz   |   2       |   8       |   0x5F7      |
 *         | 1500000Hz   |   2       |   8       |   0x492      |
 *         | 1843200Hz   |   2       |   5       |   0x3F7      |
 *         | 2000000Hz   |   2       |   5       |   0          |
 *         | 2100000Hz   |   1       |   14      |   0x400      |
 *         | 2764800Hz   |   1       |   9       |   0x2AA      |
 *         | 3000000Hz   |   1       |   8       |   0x492      |
 *         | 3250000Hz   |   1       |   7       |   0x112      |
 *         | 3692300Hz   |   1       |   5       |   0x5F7      |
 *         | 3750000Hz   |   1       |   5       |   0x36D      |
 *         | 4000000Hz   |   1       |   5       |   0          |
 *         | 6000000Hz   |   1       |   1       |   0x36D      |
 *
 * \param[out]   div: The div for setting baudrate. This parameter ranges from 0x0 to 0xFFFF.
 * \param[out]   ovsr: The ovsr for setting baudrate. This parameter ranges from 0x0 to 0xFFFF.
 * \param[out]   ovsr_adj: The ovsr_adj for setting baudrate. This parameter ranges from 0x0 to 0xFFFF.
 * \param[in]   rate: Select UART baudrate \ref UartBaudRate_TypeDef.
 *
 * \return   UART param of specified the UART baud rate that to be get or not.
 * \retval true   The UART param was get from baudrate successfully.
 * \retval false  The UART param was failed to get due to unsupport baudrate.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void uart_demo(void)
 * {
 *     UART_ComputeDiv(div, ovsr, ovsr_adj, BAUD_RATE_115200);
 * }
 * \endcode
 */
bool UART_ComputeDiv(uint16_t *div, uint16_t *ovsr, uint16_t *ovsr_adj, UartBaudRate_TypeDef rate);

/**
 *
 * \brief   UART idle interrupt config.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in]   NewState: New state of the UART idle interrupt.
 *      This parameter can be one of the following values:
 *      - ENABLE: Enable UART idle interrupt.
 *      - DISABLE: Disable UART idle interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void uart_demo(void)
 * {
 *     UART_IdleIntConfig(UART0, ENABLE);
 * }
 * \endcode
 */
void UART_IdleIntConfig(UART_TypeDef *UARTx, FunctionalState newState);

/**
 * \brief  Config the UART clock divider.
 *
 * \param[in] UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in] ClockDiv: Specifies the UART clock divider \ref x3g_UART_Clock_Divider.
 *            This parameter can be one of the following values:
 *            - UART_CLOCK_DIV_x: Where x can be 1, 2, 4, 16 to select the specified clock divider.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     UART_ClkDivConfig(UART0, UART_CLOCK_DIV_1);
 * }
 * \endcode
 */
void UART_ClkDivConfig(UART_TypeDef *UARTx, uint16_t ClockDiv);

/**
 * \brief   Send one byte of data to TX FIFO.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in]   data: Byte data to send. This parameter must range from 0x0 to 0xFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data = 0x55;
 *     UART_SendByte(UART0, data);
 * }
 * \endcode
 */
void UART_SendByte(UART_TypeDef *UARTx, uint8_t data);

/**
 * \brief   Read one byte of data from UART RX FIFO.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 *
 * \return   Which byte data has been read.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data = UART_ReceiveByte(UART0);
 *
 * }
 * \endcode
 */
uint8_t UART_ReceiveByte(UART_TypeDef *UARTx);

/**
 * \brief   Get interrupt identifier of the selected UART peripheral.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 *
 * \return The interrupt identifier value \ref x3g_UART_Interrupt_Identifier.
 *      This return value can be one or a combination of the following values:
 *         \retval UART_INT_ID_LINE_STATUS:  RX line status interrupt identification.
 *         \retval UART_INT_ID_RX_LEVEL_REACH: RX trigger level reached interrupt identification.
 *         \retval UART_INT_ID_RX_DATA_TIMEOUT: RX FIFO data timeout interrupt identification.
 *         \retval UART_INT_ID_TX_FIFO_EMPTY: TX FIFO empty interrupt identification.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void UART0_Handler()
 * {
 *     uint16_t rx_len = 0;
 *     uint8_t uart_rev_data[32];
 *
 *     //Get interrupt ID.
 *     uint32_t int_status = UART_GetIID(UART0);
 *
 *     //Disable interrupt.
 *     UART_INTConfig(UART0, UART_INT_RD_AVA, DISABLE);
 *
 *     if (UART_GetFlagStatus(UART0, UART_FLAG_RX_IDLE) == SET)
 *     {
 *         UART_INTConfig(UART0, UART_INT_RX_IDLE, DISABLE);
 *         //Add user code here.
 *         UART_ClearRxFIFO(UART0);
 *         UART_INTConfig(UART0, UART_INT_RX_IDLE, ENABLE);
 *     }
 *
 * }
 * \endcode
 */
uint16_t UART_GetIID(UART_TypeDef *UARTx);

/**
 * \brief   Clear TX FIFO of the selected UART peripheral.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_ClearTxFIFO(UART0);
 * }
 * \endcode
 */
void UART_ClearTxFIFO(UART_TypeDef *UARTx);

/**
 * \brief   Clear RX FIFO of the selected UART peripheral.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_ClearRxFIFO(UART0);
 * }
 * \endcode
 */
void UART_ClearRxFIFO(UART_TypeDef *UARTx);

/**
 * \brief   Get the data length in TX FIFO of the selected UART peripheral.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 *
 * \return   Data length in UART TX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data_len = UART_GetTxFIFOLen(UART0);
 * }
 * \endcode
 */
uint8_t UART_GetTxFIFOLen(UART_TypeDef *UARTx);

/**
 * \brief   Get the data length in RX FIFO of the selected UART peripheral.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 *
 * \return   Data length in UART RX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data_len = UART_GetRxFIFOLen(UART0);
 * }
 * \endcode
 */
uint8_t UART_GetRxFIFOLen(UART_TypeDef *UARTx);

/**
 * \brief    Enable or disable TX DMA mode on UART.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in]   newState: Enable or disable UART TX DMA mode.
 *      This parameter can be one of the following values:
 *      - ENABLE: Enable UART TX DMA mode, can use DMA to send data.
 *      - DISABLE: Disable UART TX DMA mode, cannot use DMA to send data.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void driver_uart_init(void)
 * {
 *     UART_TxDmaCmd(UART0, false);
 * }
 * \endcode
 */
void UART_TxDmaCmd(UART_TypeDef *UARTx, FunctionalState NewState);

/**
 * \brief    Enable or disable RX DMA mode on UART.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in]   newState: Enable or disable UART DMA mode.
 *      This parameter can be one of the following values:
 *      - ENABLE: Enable UART RX DMA mode, can use DMA to receive data.
 *      - DISABLE: Disable UART RX DMA mode, cannot use DMA to receive data.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void driver_uart_init(void)
 * {
 *     UART_RxDmaCmd(UART0, false);
 * }
 * \endcode
 */
void UART_RxDmaCmd(UART_TypeDef *UARTx, FunctionalState newState);

/**
 *
 * \brief   Enable/Disable TX-only mode for UART.
 * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 3 \ref x3g_UART_Declaration.
 * \param[in]   NewState: New state of the TX-only mode.
 *      This parameter can be one of the following values:
 *      - ENABLE: Enable TX-only mode, disables RX functionality.
 *      - DISABLE: Disable TX-only mode, enable normal UART RX/TX mode.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void uart_tx_only_demo(void)
 * {
 *     UART_TxOnlyModeCmd(UART0, ENABLE);  // Enable TX-only mode
 *     // ... send data ...
 *     UART_TxOnlyModeCmd(UART0, DISABLE); // Disable TX-only mode
 * }
 * \endcode
 */
void UART_TxOnlyModeCmd(UART_TypeDef *UARTx, FunctionalState NewState);

/**
 * \brief   UART one wire config.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in]   is_enable: UART one wire config is set or not.
 *      This parameter can be one of the following values:
 *      - true: UART one wire config is set.
 *      - false: UART one wire config is unset.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void uart_demo(void)
 * {
 *     UART_OneWireConfig(UART0, true);
 * }
 * \endcode
 */
void UART_OneWireConfig(UART_TypeDef *UARTx, bool is_enable);

/**
 * \brief   Clear the specified UART flag. Only \ref UART_FLAG_RX_IDLE need to be cleared manually, other interrupt flag cannot be cleared.
 *
 * \param[in]   UARTx: UART peripheral selected, x can be 0 ~ 5 \ref x3g_UART_Declaration.
 * \param[in]   UART_FLAG: Specified UART flag to check \ref x3g_UART_Flag.
 *      This parameter can be one of the following values:
 *      - UART_FLAG_RX_IDLE: RX idle timeout. Only to show difference cause the address of UART RX idle flag is isolate.
 *
 * \return   New state of UART flag.
 * \retval SET: The specified UART flag bit is set.
 * \retval RESET: The specified flag is not set.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void uart_handler(void)
 * {
 *     if(UART_GetFlagState(UART2, UART_FLAG_RX_IDLE) == SET)
 *     {
 *          UART_ClearINT(UART2, UART_FLAG_RX_IDLE);
 *     }
 * }
 * \endcode
 */
void UART_ClearINT(UART_TypeDef *UARTx, uint32_t UART_FLAG);

/** @} */ /* End of group 87x3g_UART_Exported_Functions */
/** @} */ /* End of group 87x3g_UART */

#ifdef __cplusplus
}
#endif

#endif /* _RTL876X_UART_H_ */




