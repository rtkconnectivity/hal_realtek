/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL876X_ADC_H
#define RTL876X_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_adc_def.h"
#include "platform_utils.h"

/** @addtogroup 87x3g_ADC ADC
  * @brief ADC driver module.
  * @{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/


/** @defgroup 87x3g_ADC_Exported_Constants ADC Exported Constants
  * @{
  */

/** @defgroup 87x3g_ADC_Channel_Index ADC Channel Index
  * @{
  */
#define ADC_Channel_Index_0           0     //!< ADC channel index 0.
#define ADC_Channel_Index_1           1     //!< ADC channel index 1.
#define ADC_Channel_Index_2           2     //!< ADC channel index 2.
#define ADC_Channel_Index_3           3     //!< ADC channel index 3.
#define ADC_Channel_Index_4           4     //!< ADC channel index 4.
#if (CHIP_ADC_CHANNEL_NUM > 4)
#define ADC_Channel_Index_5           5     //!< ADC channel index 5.
#define ADC_Channel_Index_6           6     //!< ADC channel index 6.
#define ADC_Channel_Index_7           7     //!< ADC channel index 7.
#endif
#if (CHIP_ADC_CHANNEL_NUM > 8)
#define ADC_Channel_Index_8           8     //!< ADC channel index 8.
#define ADC_Channel_Index_9           9     //!< ADC channel index 9.
#define ADC_Channel_Index_10          10    //!< ADC channel index 10.
#define ADC_Channel_Index_11          11    //!< ADC channel index 11.
#define ADC_Channel_Index_12          12    //!< ADC channel index 12.
#define ADC_Channel_Index_13          13    //!< ADC channel index 13.
#define ADC_Channel_Index_14          14    //!< ADC channel index 14.
#define ADC_Channel_Index_15          15    //!< ADC channel index 15.
#endif
#define IS_ADC_EXTERNAL_CHANNEL(ch)      ((ch) < CHIP_ADC_CHANNEL_NUM)  //!< Check whether is the ADC channel index.

/** End of Group 87x3g_ADC_Channel_Index
  * @}
  */

/** @defgroup 87x3g_ADC_Schedule_Index ADC Schedule Index
  * @{
  */
#define ADC_Schedule_Index_0          0     //!< ADC schedule index 0.
#define ADC_Schedule_Index_1          1     //!< ADC schedule index 1.
#define ADC_Schedule_Index_2          2     //!< ADC schedule index 2.
#define ADC_Schedule_Index_3          3     //!< ADC schedule index 3.
#define ADC_Schedule_Index_4          4     //!< ADC schedule index 4.
#define ADC_Schedule_Index_5          5     //!< ADC schedule index 5.
#define ADC_Schedule_Index_6          6     //!< ADC schedule index 6.
#define ADC_Schedule_Index_7          7     //!< ADC schedule index 7.
#define ADC_Schedule_Index_8          8     //!< ADC schedule index 8.
#define ADC_Schedule_Index_9          9     //!< ADC schedule index 9.
#define ADC_Schedule_Index_10         10    //!< ADC schedule index 10.
#define ADC_Schedule_Index_11         11    //!< ADC schedule index 11.
#define ADC_Schedule_Index_12         12    //!< ADC schedule index 12.
#define ADC_Schedule_Index_13         13    //!< ADC schedule index 13.
#define ADC_Schedule_Index_14         14    //!< ADC schedule index 14.
#define ADC_Schedule_Index_15         15    //!< ADC schedule index 15.
#if (CHIP_ADC_SCHEDULE_NUM > 16)
#define ADC_Schedule_Index_16         16    //!< ADC schedule index 16.
#define ADC_Schedule_Index_17         17    //!< ADC schedule index 17.
#define ADC_Schedule_Index_18         18    //!< ADC schedule index 18.
#define ADC_Schedule_Index_19         19    //!< ADC schedule index 19.
#endif
#define IS_ADC_SCH_INDEX(IDEX) ((IDEX) < CHIP_ADC_SCHEDULE_NUM)   //!< Check whether is the ADC schedule index.

/** End of Group 87x3g_ADC_Schedule_Index
  * @}
  */

/** @defgroup 87x3g_ADC_Schedule_Table ADC Channel and Mode
  * @{
  */
#define SCHEDULE_TABLE(Index)         (Index)     //!< ADC schedule table index.
#define EXT_SINGLE_ENDED(Index)       ((uint16_t)((ADC_MODE_SINGLE_ENDED_VALUE << CHIP_ADC_MODE_OFFSET) | (Index)))   /**< External single-ended mode. */

#define INTERNAL_VBAT_MODE            ((uint16_t)((ADC_MODE_INTERNAL_VALUE << CHIP_ADC_MODE_OFFSET) | 0x00))    //!< Internal VBAT mode.
#if ADC_SUPPORT_VADPIN_MODE
#define INTERNAL_VADPIN_MODE          ((uint16_t)((ADC_MODE_INTERNAL_VALUE << CHIP_ADC_MODE_OFFSET) | 0x01))    //!< Internal VADPIN mode.
#endif

#if ADC_SUPPORT_VADPIN_MODE
#define IS_ADC_SCHEDULE_INDEX_CONFIG(CONFIG) (((CONFIG) & (0xffff << 2 << CHIP_ADC_MODE_OFFSET)) == 0 && \
                                              ((IS_ADC_SCH_INDEX((CONFIG) & (~(0xffff << CHIP_ADC_MODE_OFFSET))) && \
                                                (CONFIG & BIT(CHIP_ADC_MODE_OFFSET + 1) == 0)) || \
                                               (CONFIG) == INTERNAL_VBAT_MODE || \
                                               (CONFIG) == INTERNAL_VADPIN_MODE))   //!< Check whether is the ADC channel and mode.
#else
#define IS_ADC_SCHEDULE_INDEX_CONFIG(CONFIG) (((CONFIG) & (0xffff << 2 << CHIP_ADC_MODE_OFFSET)) == 0 && \
                                              ((IS_ADC_SCH_INDEX((CONFIG) & (~(0xffff << CHIP_ADC_MODE_OFFSET))) && \
                                                (CONFIG & BIT(CHIP_ADC_MODE_OFFSET + 1) == 0)) || \
                                               (CONFIG) == INTERNAL_VBAT_MODE))     //!< Check whether is the ADC channel and mode.
#endif

/** End of Group 87x3g_ADC_Schedule_Table
  * @}
  */

/** @defgroup 87x3g_ADC_CONVERT_TIME   ADC Convert Time
  * @{
  */
typedef enum
{
    ADC_CONVERT_TIME_500NS,     //!< ADC convert time is 500ns.
    ADC_CONVERT_TIME_700NS,     //!< ADC convert time is 700ns.
    ADC_CONVERT_TIME_900NS,     //!< ADC convert time is 900ns.
    ADC_CONVERT_TIME_1100NS,    //!< ADC convert time is 1100ns.
} ADCConvertTim_TypeDef;

#define IS_ADC_CONVERT_TIME(TIME) (((TIME) == ADC_CONVERT_TIME_500NS) || \
                                   ((TIME) == ADC_CONVERT_TIME_700NS) || \
                                   ((TIME) == ADC_CONVERT_TIME_900NS) || \
                                   ((TIME) == ADC_CONVERT_TIME_1100NS))   //!< Check whether is the ADC convert time.

/** End of Group 87x3g_ADC_CONVERT_TIME
  * @}
  */

/** @defgroup 87x3g_ADC_Latch_Data_Edge ADC Latch Data Edge
  * @{
  */
typedef enum
{
    ADC_LATCH_DATA_Positive,    //!< ADC latch ADC data at positive clock edge.
    ADC_LATCH_DATA_Negative,    //!< ADC latch ADC data at negative clock edge.
} ADCDataLatchEdge_TypeDef;

#define IS_ADC_LATCH_MODE(MODE) (((MODE) == ADC_LATCH_DATA_Positive) || ((MODE) == ADC_LATCH_DATA_Negative))  //!< Check whether is the ADC latch data edge.

/** End of Group 87x3g_ADC_Latch_Data_Edge
  * @}
  */

/** @defgroup 87x3g_ADC_Data_Align ADC Data Align
  * @{
  */
typedef enum
{
    ADC_DATA_ALIGN_LSB,     //!< ADC data storage format is LSB.
    ADC_DATA_ALIGN_MSB,     //!< ADC data storage format is MSB.
} ADCAlign_TypeDef;

#define IS_ADC_DATA_ALIGN(DATA_ALIGN) (((DATA_ALIGN) == ADC_DATA_ALIGN_LSB) || ((DATA_ALIGN) == ADC_DATA_ALIGN_MSB))    //!< Check whether is the ADC data align.

/** End of Group 87x3g_ADC_Data_Align
  * @}
  */

/** @defgroup 87x3g_ADC_Clock_Config ADC Sample Clock
  * @brief ADC sample clock frequency default value as follow, other vaule (0x1~0x3fff) is also support if user wanted.
  * @{
  */
#define ADC_CLK_625K                  (0x0f)    //!< ADC sample clock frequency is 625KHz.
#define ADC_CLK_312_5K                (0x1f)    //!< ADC sample clock frequency is 312.5KHz.
#define ADC_CLK_156_25K               (0x3f)    //!< ADC sample clock frequency is 156.25KHz.
#define ADC_CLK_78_125K               (0x7f)    //!< ADC sample clock frequency is 78.125KHz.
#define ADC_CLK_39K                   (0xff)    //!< ADC sample clock frequency is 39KHz.

#define ADC_CLK_19_5K                 (0x1ff)   //!< ADC sample clock frequency is 19.5KHz.
#define ADC_CLK_9_8K                  (0x3ff)   //!< ADC sample clock frequency is 9.8KHz.
#define ADC_CLK_4_88K                 (0x7ff)   //!< ADC sample clock frequency is 4.88KHz.
#define ADC_CLK_2_44K                 (0xfff)   //!< ADC sample clock frequency is 2.44KHz.
#define ADC_CLK_1_22K                 (0x1fff)  //!< ADC sample clock frequency is 1.22KHz.

/** End of Group 87x3g_ADC_Clock_Config
  * @}
  */

/** @defgroup 87x3g_ADC_AVG_Select ADC Averaged Select
  * @{
  */

/**
 * @brief ADC hardware averaged select.
 */
typedef enum
{
    ADC_DATA_AVERAGE_OF_2,    //!< ADC data averaged by 2.
    ADC_DATA_AVERAGE_OF_4,    //!< ADC data averaged by 4.
    ADC_DATA_AVERAGE_OF_8,    //!< ADC data averaged by 8.
    ADC_DATA_AVERAGE_OF_16,   //!< ADC data averaged by 16.
    ADC_DATA_AVERAGE_OF_32,   //!< ADC data averaged by 32.
    ADC_DATA_AVERAGE_OF_64,   //!< ADC data averaged by 64.
    ADC_DATA_AVERAGE_OF_128,  //!< ADC data averaged by 128.
    ADC_DATA_AVERAGE_OF_256,  //!< ADC data averaged by 256.
    ADC_DATA_AVERAGE_MAX,     //!< The maximum value that can be selected for ADC data average times.
} ADCDataAvgSel_TypeDef;

#define IS_ADC_DATA_AVG_NUM(NUM) (((NUM) == ADC_DATA_AVERAGE_OF_2) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_4) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_8) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_16) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_32) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_64) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_128) || \
                                  ((NUM) == ADC_DATA_AVERAGE_OF_256))   //!< Check whether is the ADC data average number.

/** End of Group 87x3g_ADC_AVG_Select
  * @}
  */

/** @defgroup 87x3g_ADC_RG2X_0_Delay_Time  ADC Power On Delay Time of RG2X_AUXADC[0]
  * @{
  */
typedef enum
{
    ADC_POW_AD1_DELAY_10_US,  //!< ADC power on delay time of RG2X_AUXADC[0] is 10us.
    ADC_POW_AD1_DELAY_20_US,  //!< ADC power on delay time of RG2X_AUXADC[0] is 20us.
    ADC_POW_AD1_DELAY_40_US,  //!< ADC power on delay time of RG2X_AUXADC[0] is 40us.
    ADC_POW_AD1_DELAY_80_US,  //!< ADC power on delay time of RG2X_AUXADC[0] is 80us.
} ADCPowAD1Delay_TypeDef;

#define IS_ADC_RG2X_0_DELAY_TIME(TIME) (((TIME) == ADC_POW_AD1_DELAY_10_US) || \
                                        ((TIME) == ADC_POW_AD1_DELAY_20_US) || \
                                        ((TIME) == ADC_POW_AD1_DELAY_40_US) || \
                                        ((TIME) == ADC_POW_AD1_DELAY_80_US))  //!< Check whether is the ADC power on delay time of RG2X_AUXADC[0].

/** End of Group 87x3g_ADC_RG2X_0_Delay_Time
  * @}
  */

/** @defgroup 87x3g_ADC_RG0X_1_Delay_Time  ADC Power On Delay Time of RG0X_AUXADC[1]
  * @{
  */
typedef enum
{
    ADC_POW_AD2_DELAY_20_US,    //!< ADC power on delay time of RG0X_AUXADC[1] is 20us.
    ADC_POW_AD2_DELAY_40_US,    //!< ADC power on delay time of RG0X_AUXADC[1] is 40us.
    ADC_POW_AD2_DELAY_80_US,    //!< ADC power on delay time of RG0X_AUXADC[1] is 80us.
    ADC_POW_AD2_DELAY_160_US,   //!< ADC power on delay time of RG0X_AUXADC[1] is 160us.
} ADCPowAD2Delay_TypeDef;

#define IS_ADC_RG0X_1_DELAY_TIME(TIME) (((TIME) == ADC_POW_AD2_DELAY_20_US) || \
                                        ((TIME) == ADC_POW_AD2_DELAY_40_US) || \
                                        ((TIME) == ADC_POW_AD2_DELAY_80_US) || \
                                        ((TIME) == ADC_POW_AD2_DELAY_160_US))   //!< Check whether is the ADC power on delay time of RG0X_AUXADC[1].

/** End of Group 87x3g_ADC_RG0X_1_Delay_Time
  * @}
  */

/** @defgroup 87x3g_ADC_RG0X_0_Delay_Time ADC Power On Delay Time of RG0X_AUXADC[0]
  * @{
  */
typedef enum
{
    ADC_POW_REF_DELAY_30_US,    //!< ADC power on delay time of RG0X_AUXADC[0] is 30us.
    ADC_POW_REF_DELAY_60_US,    //!< ADC power on delay time of RG0X_AUXADC[0] is 60us.
    ADC_POW_REF_DELAY_120_US,   //!< ADC power on delay time of RG0X_AUXADC[0] is 120us.
    ADC_POW_REF_DELAY_240_US,   //!< ADC power on delay time of RG0X_AUXADC[0] is 240us.
} ADCPowRefDelay_TypeDef;

#define IS_ADC_RG0X_0_DELAY_TIME(TIME) (((TIME) == ADC_POW_REF_DELAY_30_US) || \
                                        ((TIME) == ADC_POW_REF_DELAY_60_US) || \
                                        ((TIME) == ADC_POW_REF_DELAY_120_US) || \
                                        ((TIME) == ADC_POW_REF_DELAY_240_US))   //!< Check whether is the ADC power on delay time of RG0X_AUXADC[0].

/** End of Group 87x3g_ADC_RG0X_0_Delay_Time
  * @}
  */

/** @defgroup 87x3g_ADC_FIFO_Threshold ADC FIFO Threshold
  * @{
  */
#define IS_ADC_FIFO_THRESHOLD(THD) ((THD) <= 0x20)    //!< ADC FIFO threshold is between 0 and 0x20.

/** End of Group 87x3g_ADC_FIFO_Threshold
  * @}
  */

/** @defgroup 87x3g_ADC_Burst_Size ADC Burst Size
  * @{
  */
#define IS_ADC_BURST_SIZE_CONFIG(CONFIG) ((CONFIG) <= 0x20)   //!< ADC burst size is between 0 and 0x20.

/** End of Group 87x3g_ADC_Burst_Size
  * @}
  */

/** @defgroup 87x3g_ADC_operation_Mode   ADC Operation Mode
  * @{
  */
typedef enum
{
    ADC_CONTINUOUS_MODE,    //!< ADC continuous mode.
    ADC_ONE_SHOT_MODE,      //!< ADC one shot mode.
} ADCOperationMode_TypeDef;

#define IS_ADC_MODE(MODE) (((MODE) == ADC_CONTINUOUS_MODE) || ((MODE) == ADC_ONE_SHOT_MODE))  //!< Check whether is the ADC operation mode.

/** End of Group 87x3g_ADC_operation_Mode
  * @}
  */

/** @defgroup 87x3g_ADC_Data_Minus ADC Data Minus
  * @{
  */
#define IS_ADC_DATA_MINUS(DATA_MINUS) (((DATA_MINUS) == ENABLE) || ((DATA_MINUS) == DISABLE)) //!< Check whether is the ADC data minus.

/** End of Group 87x3g_ADC_Data_Minus
  * @}
  */

/** @defgroup 87x3g_ADC_over_write_enable ADC FIFO Over Write
  * @{
  */
#define IS_ADC_OVERWRITE_MODE(MODE) (((MODE) == ENABLE) || ((MODE) == DISABLE)) //!< Check whether is the status of ADC overwrite function.

/** End of Group 87x3g_ADC_over_write_enable
  * @}
  */

/** @defgroup 87x3g_ADC_Power_Always_On_Cmd ADC Power Always on CMD
  * @{
  */
#define IS_ADC_POWER_ALWAYS_ON(CMD) (((CMD) == ENABLE) || ((CMD) == DISABLE))   //!< Check whether is the status of ADC the power always on function.

/** End of Group 87x3g_ADC_Power_Always_On_Cmd
  * @}
  */

/** @defgroup 87x3g_ADC_Interrupts_Definition ADC Interrupts Definition
  * @{
  */
#define ADC_INT_FIFO_RD_REQ           ((uint32_t)(1 << 0))  //!< ADC GDMA request interrupt: When the FIFO data level reaches the GDMA threshold level (adcBurstSize), this interrupt is triggered.
#define ADC_INT_FIFO_RD_ERR           ((uint32_t)(1 << 1))  //!< ADC FIFO read error interrupt: This interrupt is triggered when an attempt is made to read from an empty FIFO.
#define ADC_INT_FIFO_THD              ((uint32_t)(1 << 2))  //!< ADC FIFO threshold interrupt: When the FIFO data number is greater than or equal to the threshold level (adcFifoThd), this interrupt is triggered.
#define ADC_INT_FIFO_FULL             ((uint32_t)(1 << 3))  //!< ADC FIFO full interrupt: When the FIFO is full, this interrupt is triggered.
#define ADC_INT_ONE_SHOT_DONE         ((uint32_t)(1 << 4))  //!< ADC one shot mode done interrupt: When the ADC conversion is done, this interrupt is triggered.

#define IS_ADC_INT(INT) (((INT) == ADC_INT_FIFO_RD_REQ) || \
                         ((INT) == ADC_INT_FIFO_RD_ERR) || \
                         ((INT) == ADC_INT_FIFO_THD) || \
                         ((INT) == ADC_INT_ONE_SHOT_DONE) || \
                         ((INT) == ADC_INT_FIFO_FULL))  //!< Check whether is the ADC interrupt.

/** End of Group 87x3g_ADC_Interrupts_Definition
  * @}
  */

/** End of Group 87x3g_ADC_Exported_Constants
  * @}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/


/** @defgroup 87x3g_ADC_Exported_Types ADC Exported Types
  * @{
  */

/**
 * @brief ADC initialize parameters.
 *
 */
typedef struct
{
    uint16_t adcClock;                        /*!< Specifies the ADC sample clock. ADC sample period = (adcClock+1) cycles from 10MHz.
                                                    This parameter can be a value of 0x1~0x3fff. */

    ADCConvertTim_TypeDef ADC_ConvertTime;        /*!< Specifies the ADC sample convert time.
                                                    This parameter can be a value of @ref x3g_ADC_CONVERT_TIME. */

    FunctionalState
    dataWriteToFifo;          /*!< Enable or disable the function that assign ADC output data write into FIFO in one shot mode.
                                                     This parameter can be a value of ENABLE or DISABLE. */

    uint8_t adcFifoThd;                       /*!< Specifies the ADC FIFO threshold to trigger interrupt @ref ADC_INT_FIFO_THD.
                                                    This parameter can be a value of 0 to 32. */

    uint8_t adcBurstSize;                         /*!< Specifies the ADC FIFO burst size to trigger GDMA.
                                                    This parameter can be a value of 0 to 32. */

    FunctionalState
    ADC_FifoOverWriteEn;            /*!< Specifies if over write FIFO when FIFO overflow.
                                                    This parameter can be a value of ENABLE or DISABLE. */

#if ADC_SUPPORT_DMA_EN
    FunctionalState ADC_DmaEn;                      /*!< Specifies the ADC GDMA mode.
                                                         This parameter can be a value of ENABLE or DISABLE. */
#endif

    uint16_t schIndex[CHIP_ADC_SCHEDULE_NUM];   /*!< Specifies ADC mode and channel for schedule table. This parameter can be a value of @ref x3g_ADC_Schedule_Table. */

    uint32_t bitmap;                            /*!< Specify whether the schedule table is enabled.
                                                  Each bit in the 16-bit bitmap corresponds to a schedule index from schIndex[0] to schIndex[15].
                                                  If a bit is set to 1, the corresponding schedule index is enabled; if it's 0, the schedule index is disabled.
                                                  Given bitmap 0x0003, in binary it is 16'b0000000000000011. This means:
                                                  - The schIndex[0] is enabled (bit 0 is 1).
                                                  - The schIndex[1] is enabled (bit 1 is 1).
                                                  - The schIndex[2] to schIndex[15] are disabled (bits 2 to 15 are 0). */

    FunctionalState
    ADC_TimerTriggerEn;                     /*!< To control whether the TIMER1 channel4 peripheral triggers ADC one-shot mode sampling.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    ADCAlign_TypeDef ADC_DataAlign;                /*!< Specifies ADC data storage format.
                                                   This parameter can be a value of @ref x3g_ADC_Data_Align. */

    FunctionalState
    ADC_DataMinusEn;                 /*!< Enable or disable the function that data minuses the offset before writes to register/FIFO.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint16_t ADC_DataMinusOffset;                   /*!< Offset to be minused from ADC raw data latched. This parameter can be a value of 0 to 4095. */

    ADCDataAvgSel_TypeDef ADC_DataAvgSel;        /*!< Specifies ADC hardware average times.
                                                    This parameter can be a value of @ref x3g_ADC_AVG_Select. */

    uint8_t ADC_DataAvgEn;                          /*!< Enable or disable ADC hardware average function.
                                              ADC hardware average function can only be used for one-shot mode,
                                              and ADC can only use schedule table 0.
                                              This parameter can be a value of ENABLE or DISABLE. */

    uint8_t ADC_DataLatchDly;                       /*!< Specifiy the delay time interval that postpone the ADC controller to latched the output code. The time unit is based on ADC controller system clock (40MHz).
                                                    This parameter can be a value of 0x1 to 0x7. */

    ADCPowAD1Delay_TypeDef
    ADC_PowAD1Dly;           /*!< Specifies the power on delay time selection of RG2X_AUXADC[0].
                                                    This parameter can be a value of @ref x3g_ADC_RG2X_0_Delay_Time. */

    ADCPowAD2Delay_TypeDef
    ADC_PowAD2Dly;           /*!< Specifies the power on delay time selection of RG0X_AUXADC[1].
                                                    This parameter can be a value of @ref x3g_ADC_RG0X_1_Delay_Time. */

    ADCPowRefDelay_TypeDef
    ADC_PowRefDly;           /*!< Specifies the power on delay time selection of RG0X_AUXADC[0].
                                                    This parameter can be a value of @ref x3g_ADC_RG0X_0_Delay_Time. */

    FunctionalState
    ADC_FifoStopWriteEn;            /*!< Stop FIFO from writing data. This bit will be asserted automatically as FIFO overflow,
                                                    (not automatically when ADC_FifoOverWriteEn is ENABLE), need to be cleared in order to write
                                                    data again. This will not stop overwrite mode.
                                                        This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState
    ADC_PowerAlwaysOnEn;             /*!< Enable or disable the power always on function.
                                                    This parameter can be a value of ENABLE or DISABLE. */

#if ADC_SUPPORT_POWER_ON_DELAY
    FunctionalState
    ADC_PowerOnDlyEn;               /*!< Enable or Disable ADC 8ms delay after adc power on.
                                        This parameter can be a value of ENABLE or DISABLE. */
#endif
} ADC_InitTypeDef;

/** End of Group 87x3g_ADC_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/


/** @defgroup 87x3g_ADC_Exported_Functions ADC Exported Functions
  * @{
  */

/**
 *
 * \brief   Disable the ADCx peripheral clock, and restore registers to their default values.
 *
 * \param[in]  ADCx: Selected ADC peripheral, which can be ADC.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     ADC_DeInit(ADC);
 * }
 * \endcode
 */
void ADC_DeInit(ADC_TypeDef *ADCx);

/**
 *
 * \brief  Initializes the ADC peripheral according to the specified
 *         parameters in the ADC_InitStruct.
 *
 * \param[in]  ADCx: Selected ADC peripheral, which can be ADC.
 * \param[in]  ADC_InitStruct: Pointer to a ADC_InitTypeDef structure that
 *             contains the configuration information for the specified ADC peripheral.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);
 *
 *     ADC_InitTypeDef adc_init_struct;
 *     ADC_StructInit(&adc_init_struct);
 *     adc_init_struct.adcClock        = ADC_CLK_39K;
 *     adc_init_struct.schIndex[0]     = EXT_SINGLE_ENDED(1);
 *     adc_init_struct.schIndex[1]     = INTERNAL_VBAT_MODE;
 *     adc_init_struct.schIndex[2]     = INTERNAL_VADPIN_MODE;
 *     adc_init_struct.bitmap          = 0x07;
 *     ADC_Init(ADC, &adc_init_struct);
 * }
 * \endcode
 */
void ADC_Init(ADC_TypeDef *ADCx, ADC_InitTypeDef *ADC_InitStruct);

/**
 *
 * \brief  Fills each ADC_InitStruct member with its default value.
 *
 * \note   The default settings for the ADC_InitStruct member are shown in the following table:
 *         | ADC_InitStruct Member   | Default Value                   |
 *         |:-----------------------:|:-------------------------------:|
 *         | adcClock                | \ref ADC_CLK_78_125K            |
 *         | ADC_ConvertTime         | \ref ADC_CONVERT_TIME_500NS     |
 *         | dataWriteToFifo         | DISABLE                         |
 *         | adcFifoThd              | 0x06                            |
 *         | adcBurstSize            | 0x1                             |
 *         | ADC_FifoOverWriteEn     | ENABLE                          |
 *         | schIndex[16]            | 0                               |
 *         | bitmap                  | 0                               |
 *         | ADC_TimerTriggerEn      | DISABLE                         |
 *         | ADC_DataAlign           | \ref ADC_DATA_ALIGN_LSB         |
 *         | ADC_DataMinusEn         | DISABLE                         |
 *         | ADC_DataMinusOffset     | 0                               |
 *         | ADC_DmaEn               | ENABLE                          |
 *         | ADC_FifoStopWriteEn     | DISABLE                         |
 *         | ADC_DataAvgEn           | DISABLE                         |
 *         | ADC_DataAvgSel          | \ref ADC_DATA_AVERAGE_OF_2      |
 *         | ADC_PowerAlwaysOnEn     | DISABLE                         |
 *         | ADC_DataLatchDly        | 0x1                             |
 *         | ADC_PowerOnDlyEn        | DISABLE                         |
 *         | ADC_PowAD1Dly           | \ref ADC_POW_AD1_DELAY_40_US    |
 *         | ADC_PowAD2Dly           | \ref ADC_POW_AD2_DELAY_20_US    |
 *         | ADC_PowRefDly           | \ref ADC_POW_REF_DELAY_30_US    |
 *
 * \param[in]  ADC_InitStruct: Pointer to a ADC_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);
 *
 *     ADC_InitTypeDef adcInitStruct;
 *     ADC_StructInit(&adcInitStruct);
 *     adcInitStruct.schIndex[0]             = EXT_SINGLE_ENDED(0);
 *     adcInitStruct.schIndex[1]             = EXT_SINGLE_ENDED(1);
 *     adcInitStruct.schIndex[2]             = INTERNAL_VBAT_MODE;
 *     adcInitStruct.schIndex[3]             = INTERNAL_VADPIN_MODE;
 *     adcInitStruct.bitmap                  = 0x0f;
 *     ADC_Init(ADC, &adcInitStruct);
 * }
 * \endcode
 */
void ADC_StructInit(ADC_InitTypeDef *ADC_InitStruct);

/**
 *
 * \brief  Enable or disable the specified ADC peripheral.
 *
 * \param[in] ADCx: Selected ADC peripheral, which can be ADC.
 * \param[in] AdcMode: The ADC work mode to select, refer to \ref x3g_ADC_operation_Mode.
 *            This parameter can be one of the following values:
 *            - ADC_ONE_SHOT_MODE: ADC one shot mode.
 *            - ADC_CONTINUOUS_MODE: ADC continuous mode.
 * \param[in] NewState: New state of the specified ADC peripheral.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified ADC peripheral to start sampling.
 *            - DISABLE: Disable the specified ADC peripheral to stop sampling.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 * }
 * \endcode
 */
void ADC_Cmd(ADC_TypeDef *ADCx, ADCOperationMode_TypeDef AdcMode, FunctionalState NewState);

/**
 *
 * \brief  Enable or disable the specified ADC interrupts.
 *
 * \param[in] ADCx: Selected ADC peripheral, which can be ADC.
 * \param[in] ADC_INT: Specifies the ADC interrupt sources to be enabled or disabled, refer to \ref x3g_ADC_Interrupts_Definition.
 *            This parameter can be one of the following values:
 *            - ADC_INT_ONE_SHOT_DONE: ADC one shot mode done interrupt.
 *            - ADC_INT_FIFO_FULL: ADC FIFO full interrupt.
 *            - ADC_INT_FIFO_RD_REQ: ADC GDMA request interrupt.
 *            - ADC_INT_FIFO_RD_ERR: ADC FIFO read error interrupt.
 *            - ADC_INT_FIFO_THD: ADC FIFO threshold interrupt.
 * \param[in] NewState: New state of the specified ADC interrupts.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified ADC interrupts.
 *            - DISABLE: Disable the specified ADC interrupts.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = ADC_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 2;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 *
 *     ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 * }
 * \endcode
 */
void ADC_INTConfig(ADC_TypeDef *ADCx, uint32_t ADC_INT, FunctionalState NewState);

/**
 *
 * \brief  Read ADC data according to specific channel.
 *
 * \param[in] ADCx: Selected ADC peripheral, which can be ADC.
 * \param[in] Index: Schedule table index, the value can be 0 ~ 15.
 *
 * \return The 12-bit converted ADC data.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_polling_demo(void)
 * {
 *     uint16_t data[3];
 *
 *     //ADC one shot sampling mode, read data from schedule table.
 *     data[0] = ADC_Read(ADC, 0);
 *     data[1] = ADC_Read(ADC, 1);
 *     data[2] = ADC_Read(ADC, 2);
 *     APP_PRINT_INFO3("ADC data[0] = %d, ADC data[1] =%d ADC data[2] =%d",
 *                     data[0], data[1], data[2]);
 * }
 * \endcode
 */
uint16_t ADC_Read(ADC_TypeDef *ADCx, uint8_t Index);

/**
 *
 * \brief  Read the data after ADC turn on hardware average function.
 *
 * \param[in] ADCx: Selected ADC peripheral, which can be ADC.
 *
 * \return The converted data after ADC turn on hardware average.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ADC_Handler(void)
 * {
 *     uint16_t data;
 *     int32_t result;
 *     if (ADC_GetIntFlagStatus(ADC, ADC_INT_ONE_SHOT_DONE) == SET)
 *     {
 *         ADC_ClearINTPendingBit(ADC, ADC_INT_ONE_SHOT_DONE);
 *         data = ADC_HwEvgRead(ADC);
 *         result = ADC_GetRes(data, EXT_SINGLE_ENDED(1));
 *         APP_PRINT_INFO1("ADC Result = %d", result);
 *     }
 * }
 * \endcode
 */
uint16_t ADC_HwEvgRead(ADC_TypeDef *ADCx);

/**
 *
 * \brief  Get one data from ADC FIFO.
 *
 * \param[in] ADCx: Selected ADC peripheral, which can be ADC.
 *
 * \return  The data of ADC FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_handler(void)
 * {
 *     uint16_t data_fifo = 0;
 *     data_fifo = ADC_ReadFIFO(ADC);
 *     result_fifo = ADC_GetRes(data_fifo, EXT_SINGLE_ENDED(0));
 * }
 * \endcode
 */
uint16_t ADC_ReadFIFO(ADC_TypeDef *ADCx);

/**
 *
 * \brief  Get data from ADC FIFO.
 *
 * \param[in]  ADCx: Selected ADC peripheral, which can be ADC.
 * \param[out] outBuf: Buffer to save data read from ADC FIFO.
 * \param[in]  Num: Number of data to be read.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     uint8_t fifo_count = 0;
 *     uint16_t data[33] = {0, 0, 0};
 *
 *     fifo_count = ADC_GetFIFODataLen(ADC);
 *     ADC_ReadFIFOData(ADC, data, fifo_count);
 * }
 * \endcode
 */
void ADC_ReadFIFOData(ADC_TypeDef *ADCx, uint16_t *outBuf, uint16_t Num);

/**
 *
 * \brief  Get the length of ADC FIFO.
 *
 * \param[in]  ADCx: Selected ADC peripheral, which can be ADC.
 *
 * \return  Current data length of ADC FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     uint8_t fifo_size = 0;
 *     fifo_size = ADC_GetFIFODataLen(ADC);
 *     IO_PRINT_TRACE1("fifo_size:%d", fifo_size);
 * }
 * \endcode
 */
uint8_t ADC_GetFIFODataLen(ADC_TypeDef *ADCx);

/**
 *
 * \brief  Config ADC schedule table.
 *
 * \param[in] ADCx: Selected ADC peripheral, which can be ADC.
 * \param[in] Index: The index of schedule table, the value can be 0 ~ 15.
 * \param[in] AdcMode: The ADC channel and mode to select, refer to \ref x3g_ADC_Schedule_Table.
 *            This parameter can be one of the following values:
 *            - EXT_SINGLE_ENDED(index): Single-ended mode, the input is external channel index.
 *            - INTERNAL_VBAT_MODE: The input is internal battery voltage detection channel.
 *            - INTERNAL_VADPIN_MODE: The input is internal adapter voltage detection channel.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     uint16_t index = 0;
 *     ADC_SchTableConfig(ADC, index, EXT_SINGLE_ENDED(index));
 * }
 * \endcode
 */
void ADC_SchTableConfig(ADC_TypeDef *ADCx, uint16_t Index, uint8_t AdcMode);

/**
 *
 * \brief  Enable or Disable setting ADC schedule table.
 *
 * \param[in] ADCx: Selected ADC peripheral, which can be ADC.
 * \param[in] BitMap: Specify whether the schedule table is enabled or disabled.
 * \param[in] NewState: New state of the ADC peripheral.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable setting the ADC schedule table.
 *            - DISABLE: Disable setting the ADC schedule table.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *     ADC_BitMapConfig(ADC, 0x1, ENABLE);
 * }
 * \endcode
 */
void ADC_BitMapConfig(ADC_TypeDef *ADCx, uint16_t BitMap, FunctionalState NewState);

/**
 *
 * \brief  Enable or disable the function that assign ADC output data write into FIFO in one shot mode.
 *
 * \param[in] ADCx: Selected ADC peripheral, which can be ADC.
 * \param[in] NewState: New state of the ADC peripheral.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the function that assign ADC output data write into FIFO in one shot mode.
 *            - DISABLE: Disable the function that assign ADC output data write into FIFO in one shot mode.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *     ADC_WriteFIFOCmd(ADC, ENABLE);
 * }
 * \endcode
 */
void ADC_WriteFIFOCmd(ADC_TypeDef *ADCx, FunctionalState NewState);

/**
 *
 * \brief  Config ADC high bypass resistance mode.
 *
 * \note   Channels using bypass mode cannot over 0.9V!
 *
 * \param[in] ChannelNum: The external channel number, which can be 0 ~ 7.
 * \param[in] NewState: New state of the ADC bypass resistor.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the ADC high bypass resistance mode.
 *            - DISABLE: Disable the ADC high bypass resistance mode.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     ADC_HighBypassCmd(1, ENABLE);
 * }
 * \endcode
 */
void ADC_HighBypassCmd(uint8_t ChannelNum, FunctionalState NewState);

/**
 *
 * \brief  Check whether the specified ADC interrupt status flag is set.
 *
 * \param[in] ADCx: Selected ADC peripheral, which can be ADC.
 * \param[in] ADC_INT: Specifies the interrupt status flag to check, refer to \ref x3g_ADC_Interrupts_Definition.
 *            This parameter can be one of the following values:
 *            - ADC_INT_ONE_SHOT_DONE: ADC one shot mode done interrupt flag.
 *            - ADC_INT_FIFO_FULL: ADC FIFO full interrupt flag.
 *            - ADC_INT_FIFO_RD_REQ: ADC GDMA request interrupt flag.
 *            - ADC_INT_FIFO_RD_ERR: ADC FIFO read error interrupt flag.
 *            - ADC_INT_FIFO_THD: ADC FIFO threshold interrupt flag.
 *
 * \return  The new state of ADC interrupt status flag.
 * \retval SET: The specified ADC interrupt status flag is set.
 * \retval RESET: The specified ADC interrupt status flag is unset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *     while (ADC_GetIntFlagStatus(ADC, ADC_INT_ONE_SHOT_DONE) == RESET);
 *     ADC_ClearINTPendingBit(ADC, ADC_INT_ONE_SHOT_DONE);
 *     //add user code here.
 * }
 * \endcode
 */
ITStatus ADC_GetIntFlagStatus(ADC_TypeDef *ADCx, uint32_t ADC_INT);

/**
 *
 * \brief  Clear the ADC interrupt pending bits.
 *
 * \param[in] ADCx: Selected ADC peripheral, which can be ADC.
 * \param[in] ADC_INT: Specifies the interrupt pending bit to clear, refer to \ref x3g_ADC_Interrupts_Definition.
 *            This parameter can be one of the following values:
 *            - ADC_INT_ONE_SHOT_DONE: ADC one shot mode done interrupt.
 *            - ADC_INT_FIFO_FULL: ADC FIFO full interrupt.
 *            - ADC_INT_FIFO_RD_REQ: ADC GDMA request interrupt.
 *            - ADC_INT_FIFO_RD_ERR: ADC FIFO read error interrupt.
 *            - ADC_INT_FIFO_THD: ADC FIFO threshold interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ADC_Handler(void)
 * {
 *     if (ADC_GetIntFlagStatus(ADC, ADC_INT_ONE_SHOT_DONE) == SET)
 *     {
 *         ADC_ClearINTPendingBit(ADC, ADC_INT_ONE_SHOT_DONE);
 *         //add user code here.
 *     }
 * }
 * \endcode
 */
void ADC_ClearINTPendingBit(ADC_TypeDef *ADCx, uint32_t ADC_INT);

/**
 *
 * \brief  Clear ADC FIFO.
 *
 * \param[in] ADCx: Selected ADC peripheral, which can be ADC.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_handler(void)
 * {
 *     ADC_ClearFIFO(ADC);
 * }
 * \endcode
 */
void ADC_ClearFIFO(ADC_TypeDef *ADCx);

/**
 *
 * \brief   Get all ADC interrupt status.
 *
 * \param[in] ADCx: Selected ADC peripheral, which can be ADC.
 *
 * \return The new state of all ADC interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void oneshot_int_handler(void)
 * {
 *     uint8_t int_status = 0;
 *     int_status = ADC_GetAllFlagStatus(ADC);
 * }
 * \endcode
 */
uint8_t ADC_GetAllFlagStatus(ADC_TypeDef *ADCx);

/**
 *
 * \brief  Clear ADC_FIFO_STOP_WRITE status. For ADC_FIFO_STOP_WRITE bit will be asserted automatically
 *         as FIFO overflow, need to be cleared in order to write data again.
 *
 * \param[in] ADCx: Selected ADC peripheral, which can be ADC.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *     ADC_StopwriteFifoStatusClear(ADC);
 * }
 * \endcode
 */
void ADC_StopwriteFifoStatusClear(ADC_TypeDef *ADCx);

#if ADC_SUPPORT_MANUAL_MODE
/**
*
* \brief  Configure ADC manual mode.
*
* <b>Example usage</b>
* \code{.c}
*
* void driver_adc_init(void)
* {
*     ADC_ManualModeConfig();
* }
* \endcode
*/
void ADC_ManualModeConfig(void);

/**
*
* \brief  Configure ADC power on mode.
*
* \param[in] ADCx: Selected ADC peripheral, which can be ADC.
* \param[in] NewState: New state of the ADC power on mode.
*            This parameter can be one of the following values:
*            - ENABLE: ADC power on is manually controlled.
*            - DISABLE: ADC power on is automatically controlled.
*
* <b>Example usage</b>
* \code{.c}
*
* void driver_adc_init(void)
* {
*     ADC_PowerAlwaysOnCmd(ADC, ENABLE);
* }
* \endcode
*/
void ADC_PowerAlwaysOnCmd(ADC_TypeDef *ADCx, FunctionalState NewState);
#endif

#if ADC_SUPPORT_GET_RESULT
/**
 *
 * \brief  Get ADC conversion result.
 *
 * \param[in] RawData: ADC raw data.
 * \param[in] adcMode: The ADC channel and mode to select, refer to \ref x3g_ADC_Schedule_Table.
 *            This parameter can be one of the following values:
 *            - EXT_SINGLE_ENDED(index): Single-ended mode, the input is external channel index.
 *            - INTERNAL_VBAT_MODE: The input is internal battery voltage detection channel.
 *            - INTERNAL_VADPIN_MODE: The input is internal adapter voltage detection channel.
 *
 * \return ADC result.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     uint16_t data[3];
 *     int32_t res[3];
 *
 *     data[0] = ADC_Read(ADC, 0);
 *     data[1] = ADC_Read(ADC, 1);
 *     data[2] = ADC_Read(ADC, 2);
 *
 *     //Get conversion results based on data. The unit of the result is mV.
 *     res[0] = ADC_GetRes(data[0], EXT_SINGLE_ENDED(1));
 *     res[1] = ADC_GetRes(data[1], INTERNAL_VBAT_MODE);
 *     res[2] = ADC_GetRes(data[2], INTERNAL_VADPIN_MODE);
 *     APP_PRINT_INFO3("ADC Result[0] = %d, ADC Result[1] =%d Result[2] =%d",
 *                     res[0], res[1], res[2]);
 * }
 * \endcode
 */
int32_t ADC_GetRes(uint16_t RawData, uint8_t adcMode);

/**
 *
 * \brief  Get ADC result in high bypass resistance mode.
 *
 * \param[in] RawData: ADC raw data.
 * \param[in] adcMode: The ADC channel and mode to select, refer to \ref x3g_ADC_Schedule_Table.
 *            This parameter can be one of the following values:
 *            - EXT_SINGLE_ENDED(index): Single-ended mode, the input is external channel index.
 *
 * \return ADC result.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ADC_Handler(void)
 * {
 *     int32_t data[2];
 *     int32_t res[2];
 *
 *     data[0] = ADC_Read(ADC, 0);
 *     data[1] = ADC_Read(ADC, 1);
 *     res[0] = ADC_GetRes(data[0], EXT_SINGLE_ENDED(0));
 *     res[1] = ADC_GetHighBypassRes(data[1], EXT_SINGLE_ENDED(1));
 *
 * }
 * \endcode
 */
int32_t ADC_GetHighBypassRes(uint16_t RawData, uint8_t adcMode);
#endif

#ifdef __cplusplus
}
#endif

#endif /* RTL876X_ADC_H */

/** @} */ /* End of group 87x3g_ADC_Exported_Functions */
/** @} */ /* End of group 87x3g_ADC */

