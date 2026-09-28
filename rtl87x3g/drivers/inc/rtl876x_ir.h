/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL876X_IR_H
#define RTL876X_IR_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_ir_def.h"

/** @addtogroup 87x3g_IR IR
  * @brief IR driver module.
  * @{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** @defgroup 87x3g_IR_Exported_Constants IR Exported Constants
  * @{
  */

/**
 * \defgroup    87x3g_IR_FIFO_SIZE IR FIFO SIZE
 * \{
 */
#define IR_TX_FIFO_SIZE                   32 //!< IR TX FIFO SIZE is 32.
#define IR_RX_FIFO_SIZE                   32 //!< IR RX FIFO SIZE is 32.

/** End of 87x3g_IR_FIFO_SIZE
  * \}
  */

/**
 * \defgroup    87x3g_IR_Mode IR Mode
 * \{
 */
typedef enum
{
    IR_MODE_TX = 0x00, //!< IR TX mode.
    IR_MODE_RX = 0x01, //!< IR RX mode.
} IRMode_TypeDef;

#define IS_IR_MODE(MODE) (((MODE) == IR_MODE_TX) || ((MODE) == IR_MODE_RX)) //!< Check if the input parameter is valid.

/** End of 87x3g_IR_Mode
  * \}
  */

/**
 * \defgroup    87x3g_IR_Idle_Status IR Idle Status
 * \{
 */
typedef enum
{
    IR_IDLE_OUTPUT_LOW = 0x00, //!< TX output high level in idle.
    IR_IDLE_OUTPUT_HIGH = 0x01, //!< TX output low level in idle.
} IRIdleStatus_TypeDef;

#define IS_IR_IDLE_STATUS(LEVEL) (((LEVEL) == IR_IDLE_OUTPUT_HIGH) || ((LEVEL) == IR_IDLE_OUTPUT_LOW)) //!< Check if the input parameter is valid.

/** End of 87x3g_IR_Idle_Status
  * \}
  */

/**
 * \defgroup    87x3g_IR_TX_Data_Type IR TX Data Type
 * \{
 */
typedef enum
{
    IR_TX_DATA_NORMAL = 0x00,  //!< Not inverse TX FIFO define.
    IR_TX_DATA_INVERSE = 0x01, //!< Inverse TX FIFO define.
} IRTxDataType_TypeDef;

#define IS_IR_TX_DATA_TYPE(TYPE) (((TYPE) == IR_TX_DATA_NORMAL) || ((TYPE) == IR_TX_DATA_INVERSE)) //!< Check if the input parameter is valid.

/** End of 87x3g_IR_TX_Data_Type
  * \}
  */

/**
 * \defgroup    87x3g_IR_Threshold IR Threshold
 * \{
 */
#define IS_IR_TX_THRESHOLD(THD)  ((THD) <= IR_TX_FIFO_SIZE) //!< IR TX Threshold value must range from 0 to 32.
#define IS_IR_RX_THRESHOLD(THD) ((THD) <= IR_RX_FIFO_SIZE) //!< IR RX Threshold value must range from 0 to 32.

/** End of 87x3g_IR_Threshold
  * \}
  */

/**
 * \defgroup    87x3g_RX_Start_Mode RX Start Mode
 * \{
 */
typedef enum
{
    IR_RX_MANUAL_MODE = 0x00, //!< IR RX is started by calling API \ref IR_StartManualRxTrigger.
    IR_RX_AUTO_MODE = 0x01,   //!< IR RX is started automatically, and starts when the RX trigger mode is met.
} IRRxStartMode_TypeDef;

#define IS_RX_START_MODE(MODE) (((MODE) == IR_RX_AUTO_MODE) || ((MODE) == IR_RX_MANUAL_MODE)) //!< Check if the input parameter is valid.

/** End of 87x3g_RX_Start_Mode
  * \}
  */

/**
 * \defgroup   87x3g_IR_RX_FIFO_Discard_Setting IR RX FIFO Discard Setting
 * \{
 */
typedef enum
{
    IR_RX_FIFO_FULL_DISCARD_NEWEST = 0x00, //!< Reject new data data send to FIFO when RX FIFO is full.
    IR_RX_FIFO_FULL_DISCARD_OLDEST = 0x01, //!< Discard oldest data in FIFO when RX FIFO is full and new data send to FIFO.
} IRRxFifoDiscardSetting_TypeDef;

#define IS_IR_RX_FIFO_FULL_CTRL(CTRL)  (((CTRL) == IR_RX_FIFO_FULL_DISCARD_NEWEST) || ((CTRL) == IR_RX_FIFO_FULL_DISCARD_OLDEST)) //!< Check if the input parameter is valid.

/** End of 87x3g_IR_RX_FIFO_Discard_Setting
  * \}
  */

/**
 * \defgroup    87x3g_RX_Trigger_Mode RX Trigger Mode
 * \{
 */
typedef enum
{
    IR_RX_FALL_EDGE = 0x00,   //!< IR RX is triggered by falling edge.
    IR_RX_RISING_EDGE = 0x01, //!< IR RX is triggered by rising edge.
    IR_RX_DOUBLE_EDGE = 0x02, //!< IR RX is triggered by double edge.
} IRRxTriggerMode_TypeDef;

#define IS_RX_RX_TRIGGER_EDGE(EDGE) (((EDGE) == IR_RX_FALL_EDGE) || ((EDGE) == IR_RX_RISING_EDGE) || ((EDGE) == IR_RX_DOUBLE_EDGE)) //!< Check if the input parameter is valid.

/** End of 87x3g_RX_Trigger_Mode
  * \}
  */

/**
 * \defgroup    87x3g_RX_Filter_Time RX Filter Time
 * \{
 */
typedef enum
{
    IR_RX_FILTER_TIME_50ns  = 0x00, //!< IR RX filter time is 50ns.
    IR_RX_FILTER_TIME_75ns  = 0x01, //!< IR RX filter time is 75ns.
    IR_RX_FILTER_TIME_100ns = 0x02, //!< IR RX filter time is 100ns.
    IR_RX_FILTER_TIME_125ns = 0x03, //!< IR RX filter time is 125ns.
    IR_RX_FILTER_TIME_150ns = 0x04, //!< IR RX filter time is 150ns.
    IR_RX_FILTER_TIME_175ns = 0x05, //!< IR RX filter time is 175ns.
    IR_RX_FILTER_TIME_200ns = 0x06, //!< IR RX filter time is 200ns.
    IR_RX_FILTER_TIME_225ns = 0x07, //!< IR RX filter time is 225ns.
} IRRxFilterTime_TypeDef;

#define IS_IR_RX_FILTER_TIME_CTRL(CTRL)  (((CTRL) == IR_RX_FILTER_TIME_50ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_75ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_100ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_125ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_150ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_175ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_200ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_225ns)) //!< Check if the input parameter is valid.

/** End of 87x3g_RX_Filter_Time
  * \}
  */

/**
 * \defgroup    87x3g_IR_RX_Counter_Level IR RX Counter Level
 * \{
 */
typedef enum
{
    IR_RX_Count_Low_Level  = 0x00, //!< \ref IR_INT_RX_CNT_THR is triggered when low level couner >= threshold.
    IR_RX_Count_High_Level  = 0x01, //!< \ref IR_INT_RX_CNT_THR is triggered when high level couner >= threshold.
} IRRxCounterThresholdType_TypeDef;

#define IS_IR_RX_COUNT_LEVEL_CTRL(CTRL)  (((CTRL) == IR_RX_Count_Low_Level) || ((CTRL) == IR_RX_Count_High_Level)) //!< Check if the input parameter is valid.

/** End of 87x3g_IR_RX_Counter_Level
  * \}
  */

/** @defgroup 87x3g_IR_Compensation_Flag IR Compensation Flag
  * @{
  */
typedef enum
{
    IR_COMPEN_FLAG_1_2_CARRIER = BIT29, //!< 1/2 carrier freqency.
    IR_COMPEN_FLAG_1_4_CARRIER = BIT28, //!< 1/4 carrier freqency.
    IR_COMPEN_FLAG_1_N_SYSTEM_CLK = BIT28 | BIT29, //!< 3/4 carrier freqency.
} IRTxCompen_TypeDef;

/** End of group 87x3g_IR_Compensation_Flag
  * @}
  */

/**
 * \defgroup    87x3g_IR_RX_Counter_Threshold IR RX Counter Threshold
 * \{
 */
#define IS_IR_RX_COUNTER_THRESHOLD(THD) ((THD) <= 0x7fffffffUL) //!< IR RX counter threshold value must range from 0x0 to 0x7FFFFFFF.

/** End of 87x3g_IR_RX_Counter_Threshold
  * \}
  */

#if IR_SUPPORT_RAP_MODE
typedef enum
{
    IR_QACTIVE_FW_FORCE_SCLK = 0x0,
    IR_QACTIVE_FW_FORCE_PCLK = 0x1,
} IRQactiveForce_TypeDef;
#endif

/**
 * \defgroup    87x3g_IR_Interrupts_Definition IR Interrupt
 * \{
 */
/* All interrupts in transmission mode */
#define IR_INT_TF_EMPTY                             BIT0 //!< When TX FIFO is empty, TX FIFO empty interrupt will be triggered.
#define IR_INT_TF_LEVEL                             BIT1 //!< When TX FIFO offset <= threshold value, trigger TX FIFO level interrupt.
#define IR_INT_TF_OF                                BIT4 //!< When TX FIFO is full, data continues to be wrote to TX FIFO, TX FIFO overflow interrupt will be triggered.
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IR_INT_TX_FINISH                            BIT5 //!< When TX finished, TX finish interrupt will be triggered.
#endif

/* All interrupts in receiving mode */
#define IR_INT_RF_FULL                              BIT0 //!< When RX FIFO offset = 32, RX FIFO full interrupt will be triggered.
#define IR_INT_RF_LEVEL                             BIT1 //!< When RX FIFO offset >= threshold value, trigger RX FIFO Level Interrupt.
#define IR_INT_RX_CNT_OF                            BIT2 //!< When RX counter is overflow, RX counter overflow interrupt will be triggered.
#define IR_INT_RF_OF                                BIT3 //!< When RX FIFO is full and continue to be wrote, RX FIFO overflow interrupt will be triggered.
#define IR_INT_RX_CNT_THR                           BIT4 //!< When RX counter >= IR_RxCntThr, RX counter threshold interrupt will be triggered.
#define IR_INT_RF_ERROR                             BIT5 //!< When RX FIFO is empty and continue to be read, RX FIFO error read interrupt will be triggered.
#define IR_INT_RISING_EDGE                          ((uint32_t)(IR_RX_EXTENSION_INT | BIT1)) //!< When RX FIFO receives a low to high pulse, RX rising edge interrupt will be triggered.
#define IR_INT_FALLING_EDGE                         ((uint32_t)(IR_RX_EXTENSION_INT | BIT0)) //!< When RX FIFO receives a high to low pulse, RX falling edge interrupt will be triggered.

#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IS_IR_TX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_TF_EMPTY)   || \
                                       ((CONFIG) == IR_INT_TF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_TF_OF)      || \
                                       ((CONFIG) == IR_INT_TX_FINISH)) //!< Contains all IR TX interrupt.
#else
#define IS_IR_TX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_TF_EMPTY)   || \
                                       ((CONFIG) == IR_INT_TF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_TF_OF))) //!< Contains all IR TX interrupt.
#endif

#define IS_IR_RX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_RF_FULL)     || \
                                       ((CONFIG) == IR_INT_RF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_RX_CNT_OF)  || \
                                       ((CONFIG) == IR_INT_RF_OF)      || \
                                       ((CONFIG) == IR_INT_RX_CNT_THR) || \
                                       ((CONFIG) == IR_INT_RF_ERROR)      || \
                                       ((CONFIG) == IR_INT_RISING_EDGE) || \
                                       ((CONFIG) == IR_INT_FALLING_EDGE)) //!< Contains all IR RX interrupt.
#define IS_IR_INT_CONFIG(CONFIG)      (IS_IR_TX_INT_CONFIG(CONFIG) || IS_IR_RX_INT_CONFIG(CONFIG)) //!< Contains all IR TX and RX interrupt.

/** End of 87x3g_IR_Interrupts_Definition
  * \}
  */

/**
 * \defgroup    87x3g_IR_Interrupts_Clear_Flag IR Interrupts Clear Flag
 * \{
 */
/* Clear all interrupts in transmission mode */
#define IR_TF_CLR                                   BIT0 //!< Clear TX FIFO.
#define IR_INT_TF_EMPTY_CLR                         BIT1 //!< Clear TX FIFO empty interrupt status.
#define IR_INT_TF_LEVEL_CLR                         BIT2 //!< Clear TX FIFO threshold interrupt status.
#define IR_INT_TF_OF_CLR                            BIT3 //!< Clear TX FIFO overflow interrupt status.
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IR_INT_TX_FINISH_CLR                        BIT4 //!< Clear TX finish interrupt status.
#endif

#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IR_TX_INT_ALL_CLR                  (IR_INT_TF_EMPTY_CLR | \
                                            IR_INT_TF_LEVEL_CLR | \
                                            IR_INT_TF_OF_CLR    | \
                                            IR_INT_TX_FINISH_CLR) //!< Contains all IR TX interrupt clear flag.
#else
#define IR_TX_INT_ALL_CLR                  (IR_INT_TF_EMPTY_CLR | \
                                            IR_INT_TF_LEVEL_CLR | \
                                            IR_INT_TF_OF_CLR) //!< Contains all IR TX interrupt clear flag.
#endif

/* Clear all interrupts in receiving mode */
#define IR_INT_RF_FULL_CLR                         BIT0 //!< Clear RX FIFO full interrupt status.
#define IR_INT_RF_LEVEL_CLR                        BIT1 //!< Clear RX FIFO threshold interrupt status.
#define IR_INT_RX_CNT_OF_CLR                       BIT2 //!< Clear RX counter overflow interrupt status.
#define IR_INT_RF_OF_CLR                           BIT3 //!< Clear RX FIFO overflow interrupt status.
#define IR_INT_RX_CNT_THR_CLR                      BIT4 //!< Clear RX counter timeout interrupt status.
#define IR_INT_RF_ERROR_CLR                        BIT5 //!< Clear RX FIFO error read interrupt status.
#define IR_INT_RX_FALLING_EDGE_CLR                 BIT6 //!< Clear RX falling edge interrupt status.
#define IR_INT_RX_RISING_EDGE_CLR                  BIT7 //!< Clear RX rising edge interrupt status.
#define IR_RF_CLR                                  BIT8 //!< Clear RX FIFO.

#define IR_RX_INT_ALL_CLR                (IR_INT_RF_FULL_CLR | IR_INT_RF_LEVEL_CLR | \
                                          IR_INT_RX_CNT_OF_CLR | IR_INT_RF_OF_CLR | \
                                          IR_INT_RX_CNT_THR_CLR | IR_INT_RF_ERROR_CLR | \
                                          IR_INT_RX_RISING_EDGE_CLR|IR_INT_RX_FALLING_EDGE_CLR) //!< Contains all IR RX interrupt clear flag.

#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IS_IR_INT_CLEAR(INT)            (((INT) == IR_INT_TF_EMPTY_CLR) || ((INT) == IR_INT_TF_LEVEL_CLR) || \
                                         ((INT) == IR_INT_TF_OF_CLR) || ((INT) == IR_INT_TX_FINISH_CLR) || ((INT) == IR_INT_RF_FULL_CLR) || \
                                         ((INT) == IR_INT_RF_LEVEL_CLR) || ((INT) == IR_INT_RX_CNT_OF_CLR) || \
                                         ((INT) == IR_INT_RF_OF_CLR) || ((INT) == IR_INT_RX_CNT_THR_CLR) || \
                                         ((INT) == IR_INT_RX_RISING_EDGE_CLR) || ((INT) == IR_INT_RX_FALLING_EDGE_CLR) || \
                                         ((INT) == IR_INT_RF_ERROR_CLR)) //!< Contains all IR TX and RX interrupt clear flag.
#else
#define IS_IR_INT_CLEAR(INT)            (((INT) == IR_INT_TF_EMPTY_CLR) || ((INT) == IR_INT_TF_LEVEL_CLR) || \
                                         ((INT) == IR_INT_TF_OF_CLR) || ((INT) == IR_INT_RF_FULL_CLR) || \
                                         ((INT) == IR_INT_RF_LEVEL_CLR) || ((INT) == IR_INT_RX_CNT_OF_CLR) || \
                                         ((INT) == IR_INT_RF_OF_CLR) || ((INT) == IR_INT_RX_CNT_THR_CLR) || \
                                         ((INT) == IR_INT_RX_RISING_EDGE_CLR) || ((INT) == IR_INT_RX_FALLING_EDGE_CLR) || \
                                         ((INT) == IR_INT_RF_ERROR_CLR)) //!< Contains all IR TX and RX interrupt clear flag.
#endif

/** End of 87x3g_IR_Interrupts_Clear_Flag
  * \}
  */

/**
 * \defgroup    87x3g_IR_Flag IR Flag
 * \{
 */
#define IR_FLAG_TF_EMPTY                       BIT15 //!< TX FIFO is empty or not.
#define IR_FLAG_TF_FULL                        BIT14 //!< TX FIFO is full or not.
#define IR_FLAG_TX_RUN                         BIT4 //!< TX state is running or idle.
#define IR_FLAG_RF_EMPTY                       BIT17 //!< RX FIFO is empty or not.
#define IR_FLAG_RF_FULL                        BIT16 //!< RX FIFO is full or not.
#define IR_FLAG_RX_RUN                         BIT7 //!< RX state is running or idle.

#define IS_IR_FLAG(FLAG)                (((FLAG) == IR_FLAG_TF_EMPTY) || ((FLAG) == IR_FLAG_TF_FULL) || \
                                         ((FLAG) == IR_FLAG_TX_RUN) || ((FLAG) == IR_FLAG_RF_EMPTY) || \
                                         ((FLAG) == IR_FLAG_RF_FULL) || ((FLAG) == IR_FLAG_RX_RUN)) //!< Check if the input parameter is valid.

/** End of 87x3g_IR_Flag
  * \}
  */

/** @cond private
  * @defgroup 87x3g_IR_Immediate_Number IR Immediate Number
  * @{
  */
#define IR_RX_EXTENSION_INT                         0x8000
#define IR_RX_MSK_TO_EN_Pos                         14
#define IR_TX_FIFO_OVER_MSK_TO_EN_Pos               1
#define IR_TX_MSK_TO_EN_Pos                         2
#define IR_TX_STATUS_TO_EN_Pos                      2

#define IR_DATA_TYPE_Msk                          BIT31
#define IR_TX_LAST_PACKEET_Msk                    BIT30
/** End of Group 87x3g_IR_Immediate_Number
  * @}
  * @endcond
  */

/** End of 87x3g_IR_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** @defgroup 87x3g_IR_Exported_Types IR Exported Types
  * @{
  */


/**
 * \brief       IR init structure definition.
 */
typedef struct
{
    IRClock_TypeDef
    IR_Clock;                        /*!< Specifies the IR clock source, default 40000000. */

    uint32_t IR_Freq;                                /*!< Specifies the IR clock frequency. This parameter is the IR TX carrier frequency or RX sample clock, unit KHz.
                                              This parameter can be a value of @ref x3g_IR_Frequency. IR_CLK_DIV = (IR_Clock / IR_Freq * 1000) - 1 .  */

    float IR_DutyCycle;                              /*!< Specifies the IR duty cycle. This parameter must range from 0x1 to 0x3FFF. IR_TX_DUTY_NUM = (IR_CLK_DIV + 1)/IR_DutyCycle - 1 . */

    IRMode_TypeDef IR_Mode;                          /*!< Specifies the IR mode.
                                              This parameter can be a value of @ref x3g_IR_Mode. */

    IRIdleStatus_TypeDef IR_TxIdleLevel;             /*!< Specifies the IR TX output level in idle.
                                              This parameter can be a value of @ref x3g_IR_Idle_Status. */

    IRTxDataType_TypeDef
    IR_TxInverse;               /*!< Specifies inverse FIFO data or not in TX mode.
                                              This parameter can be a value of @ref x3g_IR_TX_Data_Type. */

    uint32_t IR_TxFIFOThrLevel;                      /*!< Specifies TX FIFO threshold value in TX mode. When TX FIFO offset <= IR_TxFIFOThrLevel, trigger interrupt \ref IR_INT_TF_LEVEL.
                                              This parameter can be a value of @ref x3g_IR_Tx_Threshold. This parameter must range from 0 to 32. */

    IRRxStartMode_TypeDef IR_RxStartMode;            /*!< Specifies the IR RX start mode.
                                              This parameter can be a value of @ref x3g_IR_Rx_Start_Mode. */
    uint32_t IR_RxFIFOThrLevel;                      /*!< Specifies RX FIFO threshold value in RX mode. When RX FIFO offset >= IR_RxFIFOThrLevel, trigger interrupt \ref IR_INT_RF_LEVEL.
                                              This parameter can be a value of @ref x3g_IR_Rx_Threshold. This parameter must range from 0 to 32. */

    IRRxFifoDiscardSetting_TypeDef
    IR_RxFIFOFullCtrl;        /*!< Specifies data discard mode in RX mode when RX FIFO is full and receiving new data.
                                              This parameter can be a value of @ref x3g_IR_RX_FIFO_DISCARD_SETTING. */

    IRRxTriggerMode_TypeDef IR_RxTriggerMode;                 /*!< Specifies IR RX trigger mode.
                                              This parameter can be a value of @ref x3g_IR_RX_Trigger_Mode. */

    IRRxFilterTime_TypeDef IR_RxFilterTime;                   /*!< Specifies IR RX filter time.
                                              This parameter can be a value of @ref x3g_IR_RX_Filter_Time. */

    IRRxCounterThresholdType_TypeDef
    IR_RxCntThrType;        /*!< Specifies counter level type when trigger @ref IR_INT_RX_CNT_THR interrupt in RX mode.
                                              This parameter can be a value of @ref x3g_IR_RX_COUNTER_THRESHOLD_TYPE. */

    uint32_t IR_RxCntThr;                                  /*!< Specifies counter threshold value when trigger @ref IR_INT_RX_CNT_THR interrupt in RX mode.
                                              This parameter must range from 0x0 to 0x7FFFFFFF. This parameter can be a value of @ref x3g_IR_Rx_Counter_Threshold. */

    FunctionalState IR_TxDmaEn;                            /*!< Specifies the IR TX DMA mode.
                                              This parameter must be a value of DISABLE and ENABLE. */

    uint8_t IR_TxWaterLevel;                               /*!< Specifies the IR DMA TX water level.
                                              This parameter must range from 0 to 32. */

    FunctionalState IR_RxDmaEn;                            /*!< Specifies the IR RX DMA mode.
                                              This parameter must be a value of DISABLE and ENABLE. */

    uint8_t IR_RxWaterLevel;                               /*!< Specifies the IR DMA RX water level.
                                              This parameter must range from 0 to 32. */
} IR_InitTypeDef;

/** End of 87x3g_IR_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** @defgroup 87x3g_IR_Exported_Functions IR Exported Functions
  * @{
  */

/**
 *
 * \brief  Disable the IR peripheral clock, and restore registers to their default values.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_ir_init(void)
 * {
 *     IR_DeInit();
 * }
 * \endcode
 */
void IR_DeInit(void);

/**
 *
 * \brief   Initializes the IR peripheral according to the specified
 *          parameters in IR_InitStruct.
 *
 * \param[in] IR_InitStruct: Pointer to a \ref IR_InitTypeDef structure that
 *            contains the configuration information for the specified IR peripheral.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_ir_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);
 *
 *     IR_InitTypeDef IR_InitStruct;
 *     IR_StructInit(&IR_InitStruct);
 *
 *     IR_InitStruct.IR_Freq               = 38;// IR carrier frequency is 38KHz
 *     IR_InitStruct.IR_DutyCycle          = 2; //Duty ratio = 1/IR_DutyCycle
 *     IR_InitStruct.IR_Mode               = IR_MODE_RX;// IR receiveing mode
 *     IR_InitStruct.IR_RxStartMode        = IR_RX_AUTO_MODE;
 *     IR_InitStruct.IR_RxFIFOThrLevel     =
           IR_RX_FIFO_THR_LEVEL; // Configure RX FIFO threshold level to trigger IR_INT_RF_LEVEL interrupt
 *     IR_InitStruct.IR_RxFIFOFullCtrl     =
 *         IR_RX_FIFO_FULL_DISCARD_NEWEST;// Discard the lastest received dta if RX FIFO is full
 *     IR_InitStruct.IR_RxFilterTime       =
           IR_RX_FILTER_TIME_50ns;// If high to low or low to high transition time <= 50ns,Filter out it.
 *     IR_InitStruct.IR_RxTriggerMode      = IR_RX_RISING_EDGE;// Configure trigger type
 *     IR_InitStruct.IR_RxCntThrType       =
           IR_RX_Count_Low_Level;// IR_RX_Count_Low_Level is counting low level
 *     IR_InitStruct.IR_RxCntThr           =
           0x23a;// Configure RX counter threshold.You can use it to decide to stop receiving IR data
 *     IR_Init(&IR_InitStruct);
 * }
 * \endcode
 */
void IR_Init(IR_InitTypeDef *IR_InitStruct);

/**
 *
 * \brief  Fills each IR_InitStruct member with its default value.
 *
 * \param[in] IR_InitStruct: Pointer to an \ref IR_InitTypeDef structure which will be initialized.
 *
 * \note   The default settings for the IR_InitStruct member are shown in the following table:
 *         | IR_InitStruct Member  | Default Value                            |
 *         |:---------------------:|:----------------------------------------:|
 *         | IR_Clock              | 40000000                                 |
 *         | IR_Freq               | 38                                       |
 *         | IR_DutyCycle          | 3                                        |
 *         | IR_Mode               | \ref IR_MODE_TX                          |
 *         | IR_TxIdleLevel        | \ref IR_IDLE_OUTPUT_LOW                  |
 *         | IR_TxInverse          | \ref IR_TX_DATA_NORMAL                   |
 *         | IR_TxFIFOThrLevel     | 0                                        |
 *         | IR_RxStartMode        | \ref IR_RX_AUTO_MODE                     |
 *         | IR_RxFIFOThrLevel     | 0                                        |
 *         | IR_RxFIFOFullCtrl     | \ref IR_RX_FIFO_FULL_DISCARD_NEWEST      |
 *         | IR_RxTriggerMode      | \ref IR_RX_FALL_EDGE                     |
 *         | IR_RxFilterTime       | \ref IR_RX_FILTER_TIME_50ns              |
 *         | IR_RxCntThrType       | \ref IR_RX_Count_Low_Level               |
 *         | IR_RxCntThr           | 0x23a                                    |
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_ir_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);

 *     IR_InitTypeDef IR_InitStruct;
 *     IR_StructInit(&IR_InitStruct);

 *     IR_InitStruct.IR_Freq               = 38;// IR carrier frequency is 38KHz
 *     IR_InitStruct.IR_DutyCycle          = 2; // !< 1/2 duty cycle
 *     IR_InitStruct.IR_Mode               = IR_MODE_TX;
 *     IR_InitStruct.IR_TxInverse          = IR_TX_DATA_NORMAL;
 *     IR_InitStruct.IR_TxFIFOThrLevel     = IR_TX_FIFO_THR_LEVEL;
 *     IR_Init(&IR_InitStruct);
 * }
 * \endcode
 */
void IR_StructInit(IR_InitTypeDef *IR_InitStruct);

/**
 *
 * \brief   Enable or disable the selected IR mode.
 *
 * \param[in] mode: Selected IR operation mode \ref x3g_IR_Mode.
 *            This parameter can be one of the following values:
 *            - IR_MODE_TX: Transmission mode.
 *            - IR_MODE_RX: Receiving mode.
 * \param[in] NewState: New state of the operation mode.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the selected IR mode. IR controller switches to TX or RX mode, allowing it to begin data transfer operations.
 *            - DISABLE: Disable the selected IR mode. Stop IR TX or RX data transfer and enter idle state.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_send_demo_code(void)
 * {
 *     IR_Cmd(IR_MODE_TX, ENABLE);
 * }
 * \endcode
 */
void IR_Cmd(uint32_t mode, FunctionalState NewState);

/**
 *
 * \brief   Start trigger receive, only in manual receive mode.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_StartManualRxTrigger();
 * }
 * \endcode
 */
void IR_StartManualRxTrigger(void);

/**
 *
 * \brief   Config counter threshold value in receiving mode. You can use it to stop receiving IR data.
 *
 * \param[in] IR_RxCntThrType: IR RX Count threshold type \ref x3g_IR_RX_Counter_Level.
 *            This parameter can be the following values:
 *            - IR_RX_Count_Low_Level: Low level counter value >= IR_RxCntThr, trigger \ref IR_INT_RX_CNT_THR interrupt.
 *            - IR_RX_Count_High_Level: High level counter value >= IR_RxCntThr, trigger \ref IR_INT_RX_CNT_THR interrupt.
 * \param[in] IR_RxCntThr: Configure IR RX counter threshold value which can be 0 to 0x7fffffffUL.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_SetRxCounterThreshold(IR_RX_Count_Low_Level, 0x100);
 * }
 * \endcode
 */
void IR_SetRxCounterThreshold(uint32_t IR_RxCntThrType, uint32_t IR_RxCntThr);

/**
 *
 * \brief   Send data through IR.
 *
 * \param[in] pBuf: Data buffer to send. This parameter must range from 0x0 to 0xFFFFFFFF.
 * \param[in] len: The length of data to send. This parameter must range from 0x1 to 0xFFFFFFFF.
 * \param[in] IsLastPacket: Is it the last package of data.
 *            This parameter can be one of the following values:
 *            - ENABLE: The last data in IR packet and there is no continous data. In other words, an infrared data transmission is completed.
 *            - DISABLE: There is data to be transmitted continuously.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint32_t data_buf[80] = {0};
 *     IR_SendBuf(data_buf, 68, DISABLE);
 * }
 * \endcode
 */
void IR_SendBuf(uint32_t *pBuf, uint32_t len, FunctionalState IsLastPacket);

/**
 *
 * \brief  Send compensation data.
 *
 * \param[in] comp_type: Compensation data type \ref x3g_IR_Compensation_Flag.
 *            This parameter can be one of the following values:
 *            - IR_COMPEN_FLAG_1_2_CARRIER: 1/2 carrier freqency.
 *            - IR_COMPEN_FLAG_1_4_CARRIER: 1/4 carrier freqency.
 *            - IR_COMPEN_FLAG_1_N_SYSTEM_CLK: 3/4 carrier freqency.
 * \param[in] pBuf: Data buffer to send. This parameter must range from 0x0 to 0xFFFFFFFF.
 * \param[in] len: The length of data to send. This parameter must range from 0x1 to 0xFFFFFFFF.
 * \param[in] IsLastPacket: Is it the last package of data.
 *            This parameter can be one of the following values:
 *            - ENABLE: The last data in IR packet and there is no continous data. In other words, an infrared data transmission is completed.
 *            - DISABLE: There is data to be transmitted continuously.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint32_t data_buf[80] = {0};
 *     IR_SendCompenBuf(IR_COMPEN_FLAG_1_2_CARRIER, data_buf, 68, DISABLE);
 * }
 * \endcode
 */
void IR_SendCompenBuf(IRTxCompen_TypeDef comp_type, uint32_t *pBuf, uint32_t len,
                      FunctionalState IsLastPacket);

/**
 *
 * \brief   Read data from RX FIFO.
 *
 * \param[in] pBuf: Buffer address to receive data. This parameter must range from 0x0 to 0xFFFFFFFF.
 * \param[in] length: The length of data to read. This parameter must range from 0x1 to 0xFFFFFFFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint32_t data_buf[80] = {0};
 *     IR_ReceiveBuf(data_buf, 68);
 * }
 * \endcode
 */
void IR_ReceiveBuf(uint32_t *pBuf, uint32_t length);

/**
 *
 * \brief     Enable or disable the specified IR interrupt.
 *
 * \param[in] IR_INT: Specifies the IR interrupt to be enabled or disabled \ref x3g_IR_Interrupts_Definition.
 *            This parameter can be one of the following values:
 *            - IR_INT_TF_EMPTY: When TX FIFO is empty, TX FIFO empty interrupt will be triggered.
 *            - IR_INT_TF_LEVEL: When TX FIFO offset <= threshold value, trigger TX FIFO level interrupt.
 *            - IR_INT_TF_OF: When TX FIFO is full, data continues to be wrote to TX FIFO, TX FIFO overflow interrupt will be triggered.
 *            - IR_INT_TX_FINISH: When TX finished, TX finish interrupt will be triggered.
 *            - IR_INT_RF_FULL: When RX FIFO offset = 32, RX FIFO full interrupt will be triggered.
 *            - IR_INT_RF_LEVEL: When RX FIFO offset >= threshold value, trigger RX FIFO Level Interrupt.
 *            - IR_INT_RX_CNT_OF: When RX counter is overflow, RX counter overflow interrupt will be triggered.
 *            - IR_INT_RF_OF: When RX FIFO is full and continue to be wrote, RX FIFO overflow interrupt will be triggered.
 *            - IR_INT_RX_CNT_THR: When RX counter >= IR_RxCntThr, RX counter threshold interrupt will be triggered.
 *            - IR_INT_RF_ERROR: When RX FIFO is empty and continue to be read, RX FIFO error read interrupt will be triggered.
 *            - IR_INT_RISING_EDGE: When RX FIFO receives a low to high pulse, RX rising edge interrupt will be triggered.
 *            - IR_INT_FALLING_EDGE: When RX FIFO receives a high to low pulse, RX falling edge interrupt will be triggered.
 * \param[in] newState: New state of the specified IR interrupt.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified IR interrupt.
 *            - DISABLE: Disable the specified IR interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_send_demo_code(void)
 * {
 *     //Enable IR threshold interrupt. when TX FIFO offset <= threshold value, trigger interrupt.
 *     IR_INTConfig(IR_INT_TF_LEVEL, ENABLE);
 * }
 * \endcode
 */
void IR_INTConfig(uint32_t IR_INT, FunctionalState NewState);

/**
 *
 * \brief     Mask or unmask the specified IR interrupt.
 *
 * \param[in] IR_INT: Specifies the IR interrupts to be mask or unmask \ref x3g_IR_Interrupts_Definition.
 *            This parameter can be one of the following values:
 *            - IR_INT_TF_EMPTY: When TX FIFO is empty, TX FIFO empty interrupt will be triggered.
 *            - IR_INT_TF_LEVEL: When TX FIFO offset <= threshold value, trigger TX FIFO level interrupt.
 *            - IR_INT_TF_OF: When TX FIFO is full, data continues to be wrote to TX FIFO, TX FIFO overflow interrupt will be triggered.
 *            - IR_INT_TX_FINISH: When TX finished, TX finish interrupt will be triggered.
 *            - IR_INT_RF_FULL: When RX FIFO offset = 32, RX FIFO full interrupt will be triggered.
 *            - IR_INT_RF_LEVEL: When RX FIFO offset >= threshold value, trigger RX FIFO Level Interrupt.
 *            - IR_INT_RX_CNT_OF: When RX counter is overflow, RX counter overflow interrupt will be triggered.
 *            - IR_INT_RF_OF: When RX FIFO is full and continue to be wrote, RX FIFO overflow interrupt will be triggered.
 *            - IR_INT_RX_CNT_THR: When RX counter >= IR_RxCntThr, RX counter threshold interrupt will be triggered.
 *            - IR_INT_RF_ERROR: When RX FIFO is empty and continue to be read, RX FIFO error read interrupt will be triggered.
 *            - IR_INT_RISING_EDGE: When RX FIFO receives a low to high pulse, RX rising edge interrupt will be triggered.
 *            - IR_INT_FALLING_EDGE: When RX FIFO receives a high to low pulse, RX falling edge interrupt will be triggered.
 * \param[in] newState: New state of the specified IR interrupts.
 *            This parameter can be one of the following values:
 *            - ENABLE: Mask the specified IR interrupt.
 *            - DISABLE: Unmask the specified IR interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void IR_Handler(void)
 * {
 *     if (IR_GetINTStatus(IR_INT_TF_LEVEL) == SET)
 *     {
 *         IR_MaskINTConfig(IR_INT_TF_LEVEL, ENABLE);
 *
 *         //add user code here.
 *
 *         IR_ClearINTPendingBit(IR_INT_TF_LEVEL_CLR);
 *         IR_MaskINTConfig(IR_INT_TF_LEVEL, DISABLE);
 *     }
 * }
 * \endcode
 */
void IR_MaskINTConfig(uint32_t IR_INT, FunctionalState NewState);

/**
 *
 * \brief     Get the specified IR interrupt status.
 *
 * \param[in] IR_INT: The specified IR interrupts \ref x3g_IR_Interrupts_Definition.
 *            This parameter can be one of the following values:
 *            - IR_INT_TF_EMPTY: When TX FIFO is empty, TX FIFO empty interrupt will be triggered.
 *            - IR_INT_TF_LEVEL: When TX FIFO offset <= threshold value, trigger TX FIFO level interrupt.
 *            - IR_INT_TF_OF: When TX FIFO is full, data continues to be wrote to TX FIFO, TX FIFO overflow interrupt will be triggered.
 *            - IR_INT_TX_FINISH: When TX finished, TX finish interrupt will be triggered.
 *            - IR_INT_RF_FULL: When RX FIFO offset = 32, RX FIFO full interrupt will be triggered.
 *            - IR_INT_RF_LEVEL: When RX FIFO offset >= threshold value, trigger RX FIFO Level Interrupt.
 *            - IR_INT_RX_CNT_OF: When RX counter is overflow, RX counter overflow interrupt will be triggered.
 *            - IR_INT_RF_OF: When RX FIFO is full and continue to be wrote, RX FIFO overflow interrupt will be triggered.
 *            - IR_INT_RX_CNT_THR: When RX counter >= IR_RxCntThr, RX counter threshold interrupt will be triggered.
 *            - IR_INT_RF_ERROR: When RX FIFO is empty and continue to be read, RX FIFO error read interrupt will be triggered.
 *            - IR_INT_RISING_EDGE: When RX FIFO receives a low to high pulse, RX rising edge interrupt will be triggered.
 *            - IR_INT_FALLING_EDGE: When RX FIFO receives a high to low pulse, RX falling edge interrupt will be triggered.
 *
 * \return  The new state of IR_INT.
 * \retval SET: The specified IR interrupt flag is set.
 * \retval RESET: The specified IR interrupt flag is unset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void IR_Handler(void)
 * {
 *     if (IR_GetINTStatus(IR_INT_RF_LEVEL) == SET)
 *     {
 *         //add user code here.
 *     }
 * }
 * \endcode
 */
ITStatus IR_GetINTStatus(uint32_t IR_INT);

/**
 *
 * \brief     Clear the IR interrupt pending bit.
 *
 * \param[in] IR_CLEAR_INT: Specifies the interrupt pending bit to clear \ref x3g_IR_Interrupts_Clear_Flag.
 *            This parameter can be one or any combination of the following values:
 *            - IR_TF_CLR: Clear TX FIFO.
 *            - IR_INT_TF_EMPTY_CLR: Clear TX FIFO empty interrupt.
 *            - IR_INT_TF_LEVEL_CLR: Clear TX FIFO threshold interrupt.
 *            - IR_INT_TF_OF_CLR: Clear TX FIFO overflow interrupt.
 *            - IR_INT_TX_FINISH_CLR: Clear TX finish interrupt.
 *            - IR_INT_RF_FULL_CLR: Clear RX FIFO full interrupt.
 *            - IR_INT_RF_LEVEL_CLR: Clear RX FIFO threshold interrupt.
 *            - IR_INT_RX_CNT_OF_CLR: Clear RX counter overflow interrupt.
 *            - IR_INT_RF_OF_CLR: Clear RX FIFO overflow interrupt.
 *            - IR_INT_RX_CNT_THR_CLR: Clear RX counter timeout interrupt.
 *            - IR_INT_RF_ERROR_CLR: Clear RX FIFO error read interrupt.
 *            - IR_INT_RX_RISING_EDGE_CLR: Clear RX rising edge interrupt.
 *            - IR_INT_RX_FALLING_EDGE_CLR: Clear RX falling edge interrupt.
 *            - IR_RF_CLR: Clear RX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void IR_Handler(void)
 * {
 *     if (IR_GetINTStatus(IR_INT_RF_LEVEL) == SET)
 *     {
 *         IR_MaskINTConfig(IR_INT_RF_LEVEL, ENABLE);
 *
 *         //add user code here.
 *         IR_ClearINTPendingBit(IR_INT_RF_LEVEL_CLR);
 *         IR_MaskINTConfig(IR_INT_RF_LEVEL, DISABLE);
 *     }
 * }
 * \endcode
 */
void IR_ClearINTPendingBit(uint32_t IR_CLEAR_INT);

/**
 *
 * \brief  Get free size of TX FIFO.
 *
 * \return The free size of TX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint16_t data_len = IR_GetTxFIFOFreeLen();
 * }
 * \endcode
 */
uint16_t IR_GetTxFIFOFreeLen(void);

/**
 *
 * \brief   Get data size in RX FIFO.
 *
 * \return  Current data size in RX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void IR_Handler(void)
 * {
 *     //Receive by interrupt.
 *     if (IR_GetINTStatus(IR_INT_RF_LEVEL) == SET)
 *     {
 *         len = IR_GetRxDataLen();
 *         IR_ReceiveBuf(IR_DataStruct.irBuf + rx_count, len);
 *         IR_DataStruct.bufLen += len;
 *         rx_count += len;
 *     }
 * }
 * \endcode
 */
uint16_t IR_GetRxDataLen(void);

/**
 *
 * \brief   Send one data.
 *
 * \param[in] data: The data to send. This parameter must range from 0x0 to 0xFFFFFFFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_SendData(0x80000100);
 * }
 * \endcode
 */
void IR_SendData(uint32_t data);

/**
 *
 * \brief   Read one data.
 *
 * \return  Data which read from RX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint32_t data = IR_ReceiveData();
 * }
 * \endcode
 */
uint32_t IR_ReceiveData(void);

/**
 *
 * \brief  Set TX threshold, when TX FIFO offset <= threshold value will trigger interrupt \ref IR_INT_TF_LEVEL.
 *
 * \param[in] thd: TX threshold. This parameter must range from 0 to 32.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void IR_Handler(void)
 * {
 *     //Configure TX threshold level to zero and trigger interrupt when TX FIFO is empty.
 *     IR_SetTxThreshold(0);
 * }
 * \endcode
 */
void IR_SetTxThreshold(uint8_t thd);

/**
 *
 * \brief   Set RX threshold, when RX FIFO offset >= threshold value will trigger interrupt \ref IR_INT_RF_LEVEL.
 *
 * \param[in] thd: RX threshold. This parameter must range from 0 to 32.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_SetRxThreshold(2);
 * }
 * \endcode
 */
void IR_SetRxThreshold(uint8_t thd);

/**
 * \brief Get IR RX current count.
 *
 * \return The current counter.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint32_t count = IR_GetRxCurrentCount();
 * }
 * \endcode
 */
uint32_t IR_GetRxCurrentCount(void);

/**
 *
 * \brief  Clear IR TX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_ClearTxFIFO();
 * }
 * \endcode
 */
void IR_ClearTxFIFO(void);

/**
 *
 * \brief   Clear IR RX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_ClearRxFIFO();
 * }
 * \endcode
 */
void IR_ClearRxFIFO(void);

/**
 *
 * \brief  Check whether the specified IR flag is set.
 *
 * \param[in] IR_FLAG: Specifies the IR flag to check \ref x3g_IR_Flag.
 *            This parameter can be one of the following values:
 *            - IR_FLAG_TF_EMPTY: TX FIFO empty or not. If SET, TX FIFO is empty.
 *            - IR_FLAG_TF_FULL: TX FIFO full or not. If SET, TX FIFO is full.
 *            - IR_FLAG_TX_RUN: TX run or not. If SET, TX is running.
 *            - IR_FLAG_RF_EMPTY: RX FIFO empty or not. If SET, RX FIFO is empty.
 *            - IR_FLAG_RF_FULL: RX FIFO full or not. If SET, RX FIFO is full.
 *            - IR_FLAG_RX_RUN: RX run or not. If SET, RX is running.
 *
 * \return  The new state of IR_FLAG.
 * \retval SET: The specified IR flag is set.
 * \retval RESET: The specified IR flag is unset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     //add user code here.
 *     while (IR_GetFlagStatus(IR_FLAG_TF_EMPTY) == RESET);
 * }
 * \endcode
 */
FlagStatus IR_GetFlagStatus(uint32_t IR_FLAG);

/**
 *
 * \brief   Set or reset TX waveform definition inverse.
 *
 * \param[in] NewState: This parameter can be: ENABLE or DISABLE.
 *            This parameter can be one of the following values:
 *            - ENABLE: IR TX waveform definition is inversed. Mark waveform changes to space, space waveform changes to mark.
 *            - DISABLE: IR TX waveform definition is not inversed.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_SetTxInverse(ENABLE);
 * }
 * \endcode
 */
void IR_SetTxInverse(FunctionalState NewState);

/**
 *
 * \brief  Enable or disable TX waveform inverse.
 *
 * \param[in] NewState: This parameter can be: ENABLE or DISABLE.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable TX waveform inverse. Mark: The change from high duty to low duty is now a change from low duty to high duty. Space output low changes to output high.
 *            - DISABLE: Disable TX waveform inverse.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_TxOutputInverse(ENABLE);
 * }
 * \endcode
 */
void IR_TxOutputInverse(FunctionalState NewState);

/**
 * \brief Get IR RX current level.
 *
 * \return The current level.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint32_t level = IR_GetRxCurrentLevel();
 * }
 * \endcode
 */
uint32_t IR_GetRxCurrentLevel(void);


#if IR_SUPPORT_CLOCK_SOURCE_CONFIG
/**
 * \brief Config IR clock source.
 *
 * \param[in] ClockSrc: Specifies the clock source to gates its clock \ref x3g_IR_Source_Clock.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_ClkSrcConfig(IR_SRC_CLOCK_40M);
 * }
 * \endcode
 */
void IR_ClkSrcConfig(IRSrcClock_TypeDef ClockSrc);
#endif

#if IR_SUPPORT_CLOCK_SOURCE_DIV_CONFIG
/**
  * \brief  IR clock source and divide config.
  * \param  ClockSrc: specifies the clock source to gates its clock.
  * \param  ClockDiv: specifies the clock divide to gates its clock.
  */
void IR_ClkConfig(IRSrcClock_TypeDef ClockSrc, IRSrcClockDiv_TypeDef ClockDiv);
#endif

#if IR_SUPPORT_RAP_MODE

void IR_RAPModeCmd(FunctionalState NewState);

void IR_RAPTaskStartCtrl(uint32_t mode, FunctionalState NewState);

void IR_RAPICGCtrl(FunctionalState NewState);

void IR_RAPQactiveCtrl(uint32_t Qactive, FunctionalState NewState);

#endif

/** @} */ /* End of group 87x3g_IR_Exported_Functions */
/** @} */ /* End of group 87x3g_IR */

#ifdef __cplusplus
}
#endif

#endif /* RTL876X_IR_H */




