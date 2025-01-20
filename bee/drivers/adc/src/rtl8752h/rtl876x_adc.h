/**
*********************************************************************************************************
*               Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl876x_adc.h
* \brief    The header file of the peripheral ADC driver.
* \details  This file provides all ADC firmware functions.
* \author   yuan
* \date     2024-01-25
* \version  v1.0.0
* *********************************************************************************************************
*/

#ifndef _RTL876X_ADC_H_
#define _RTL876X_ADC_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup  IO          Peripheral Drivers
 * \defgroup    ADC         ADC
 *
 * \brief       Manage the ADC peripheral functions.
 *
 * \ingroup     IO
 */

/*============================================================================*
 *                         Includes
 *============================================================================*/
#include "rtl876x.h"
#include "rtl876x_alias.h"
#include "platform_utils.h"
#include "adc_lib.h"
#include "trace.h"

typedef struct
{
    uint32_t adc_reg[16];
} ADCStoreReg_TypeDef;

/*============================================================================*
 *                         Types
 *============================================================================*/
#define ADC_UNSUPPORT_P2_6 0x1

#if ADC_UNSUPPORT_P2_6
#define ASSERT(e)                                                                                  \
    do {                                                                                           \
        if (!(e)) {                                                                                \
            platform_delay_ms(1000);                                                               \
            DBG_DIRECT("(" #e ") assert failed! Func: %s. Line: %d.", __func__, __LINE__);         \
            DBG_DIRECT("(" #e ") assert failed! Func: %s. Line: %d.", __func__, __LINE__);         \
            *(volatile int *)0x1 = 0;                                                              \
        }                                                                                          \
    } while (0)
#else
#define ASSERT(e) ((void)0)
#endif // NDEBUG
/**
 * \defgroup    ADC_Exported_Types  ADC Exported Types
 * \{
 * \ingroup     ADC
 */

/**
 * \brief       ADC init structure definition.
 *
 * \ingroup     ADC_Exported_Types
 */
typedef struct
{
    uint32_t ADC_SampleTime;  /**< Specifies the ADC sample clock, adc_sample_period = (n+1) cycles
                                 from 10MHz.  This parameter can be a value of 0 or 16383. */
    uint32_t ADC_ConvertTime; /**< Specifies the ADC Sample convert time.
                                      This parameter can be a value of \ref ADC_Convert_Time*/
    uint32_t
    ADC_DataWriteToFifo; /**< Enable or disable writing ADC sampling data to FIFO in one shot
                                mode. This parameter can be a value of \ref ADC_Data_Write_To_Fifo*/
    uint32_t
    ADC_FifoThdLevel;    /**< Specifies the ADC FIFO threshold to trigger \ref ADC_INT_FIFO_THD
                                interrupt.    This parameter can be a value of 0 to 31. */
    uint32_t ADC_WaterLevel; /**< Specifies the ADC FIFO burst size to trigger GDMA.
                                     This parameter can be a value of 0 to 31. */
    uint32_t
    ADC_FifoOverWriteEn; /**< Specifies if over write FIFO when FIFO overflow.
                                     This parameter can be a value of \ref ADC_Over_Write_Enable. */
    uint32_t
    ADC_DataLatchEdge;       /**< Specifies ADC data latch edge.
                                         This parameter can be a value of \ref ADC_Latch_Data_Edge. */
    uint16_t ADC_SchIndex[16];   /**< Specifies ADC mode and channel for schedule table.
                                         This parameter can be a value of \ref ADC_Schedule_Table. */
    uint16_t ADC_Bitmap;         /**< Specifies the schedule table channel map.
                                         This parameter can be a value of 16-bit map. */
    uint32_t ADC_TimerTriggerEn; /**< ADC one-shot mode no tim toggles. */
    uint32_t ADC_DataAlign;      /**< ADC data MSB or LSB aligned. */
    uint32_t ADC_DataMinusEn; /**< Enable or disable function that adc data latched minus the given
                                 offset before writes to reg/FIFO. */
    uint32_t ADC_DataMinusOffset; /**< Offset to be minused from adc data latched. */
    uint32_t ADC_DataAvgSel;      /**< Number of data for calculate average.
                                          This parameter can be a value of \ref ADC_Data_Avg_Num. */
    uint32_t ADC_DataAvgEn;   /**< Enable the calculation for average result of the one-shot data.
                                      This parameter can be a value of \ref ADC_Data_Avg_En. */
    uint32_t ADC_PowerOnMode; /**< Specifies ADC power on mode.
                                      This parameter can be a value of \ref ADC_Power_On_Mode. */
    uint32_t ADC_PowerAlwaysOnEn; /**< Specifies the power always on.
                                          This parameter can be a value of \ref
                                     ADC_Power_Always_On_Cmd. */
    uint32_t ADC_DataLatchDly;    /**< Specifies delay of ck_ad to latch data.*/
    uint32_t ADC_RG2X0Dly;     /**< Specifies the power on delay time selection of RG2X_AUXADC[0].
                                       This parameter can be a value of \ref ADC_RG2X_0_Delay_Time */
    uint32_t ADC_RG0X1Dly;     /**< Specifies the power on delay time selection of RG0X_AUXADC[1].
                                       This parameter can be a value of \ref ADC_RG0X_1_Delay_Time */
    uint32_t ADC_RG0X0Dly;     /**< Specifies the power on delay time selection of RG0X_AUXADC[0].
                                       This parameter can be a value of \ref ADC_RG0X_0_Delay_Time */
    uint32_t ADC_PowerOnDlyEn; /**< Enable or Disable ADC 8ms delay after adc power on. */
} ADC_InitTypeDef;

/** End of ADC_Exported_Types
 * \}
 */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/**
 * \defgroup    ADC_Exported_Constants  ADC Exported Constants
 *
 * \ingroup     ADC
 */
#define ADC_FIFO_LENGTH 32

#define ADC_FIFO_WIDTH 16

#define MAX_ADC_SCH_NUM 8

#define IS_ADC_PERIPH(PERIPH) ((PERIPH) == ADC)

/**
 * \defgroup    ADC_Data_Write_To_Fifo  Write DATA To FIFO
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_DATA_WRITE_TO_FIFO_DISABLE ((uint32_t)(0 << 27))
#define ADC_DATA_WRITE_TO_FIFO_ENABLE ((uint32_t)(1 << 27))
/** \} */

#define IS_ADC_DATA_WRITE_TO_FIFO_CMD(CMD)                                                         \
    (((CMD) == ADC_DATA_WRITE_TO_FIFO_DISABLE) || ((CMD) == ADC_DATA_WRITE_TO_FIFO_ENABLE))

/**
 * \def     ADC_FIFO_Threshold  ADC FIFO Threshold
 */
#define IS_ADC_FIFO_THRESHOLD(THD) ((THD) <= 0x3F)

/**
 * \def     ADC_Burst_Size  ADC Burst Size
 */
#define IS_ADC_WATER_LEVEL_CONFIG(CONFIG) ((CONFIG) <= 0x3F)

/**
 * \defgroup    ADC_Over_Write_Enable ADC FIFO Over Write
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_FIFO_OVER_WRITE_DISABLE ((uint32_t)(0 << 13))
#define ADC_FIFO_OVER_WRITE_ENABLE ((uint32_t)(1 << 13))
/** \} */

#define IS_ADC_OVERWRITE_MODE(MODE)                                                                \
    (((MODE) == ADC_FIFO_OVER_WRITE_DISABLE) || ((MODE) == ADC_FIFO_OVER_WRITE_ENABLE))

/**
 * \defgroup    ADC_Latch_Data_Edge ADC Latch Data Edge
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_LATCH_DATA_Positive ((uint32_t)(0 << 2))
#define ADC_LATCH_DATA_Negative ((uint32_t)(1 << 2))
/** \} */

#define IS_ADC_LATCH_DATA_EDGE(EDGE)                                                               \
    (((EDGE) == ADC_LATCH_DATA_Positive) || ((EDGE) == ADC_LATCH_DATA_Negative))

/**
 * \defgroup    ADC_Operation_Mode ADC Operation Mode
 * \{
 * \ingroup     ADC_Exported_Constants
 */

#define ADC_CONTINUOUS_MODE ((uint32_t)(1 << 0))
#define ADC_ONE_SHOT_MODE ((uint32_t)(1 << 1))
/** \} */

#define IS_ADC_SAMPLE_MODE(MODE) (((MODE) == ADC_CONTINUOUS_MODE) || ((MODE) == ADC_ONE_SHOT_MODE))

/**
 * \defgroup    ADC_Interrupts_Definition ADC Interrupts Definition
 * \{
 * \ingroup     ADC_Exported_Constants
 */

#define ADC_INT_FIFO_RD_REQ ((uint32_t)(1 << 0))
#define ADC_INT_FIFO_RD_ERR ((uint32_t)(1 << 1))
#define ADC_INT_FIFO_THD ((uint32_t)(1 << 2))
#define ADC_INT_FIFO_FULL ((uint32_t)(1 << 3))
#define ADC_INT_ONE_SHOT_DONE ((uint32_t)(1 << 4))
#define ADC_INT_FIFO_OVERFLOW ((uint32_t)(1 << 5))
/** \} */

// #define IS_ADC_INT(INT) ((((INT) & 0xFFFFFFE0) == 0x00) && ((INT) != 0x00))

#define IS_ADC_INT(INT)                                                                            \
    (((INT) == ADC_INT_FIFO_RD_REQ) || ((INT) == ADC_INT_FIFO_RD_ERR) ||                           \
     ((INT) == ADC_INT_FIFO_THD) || ((INT) == ADC_INT_FIFO_FULL) ||                                \
     ((INT) == ADC_INT_ONE_SHOT_DONE || ((INT) == ADC_INT_FIFO_OVERFLOW)))

/**
 * \defgroup    ADC_Schedule_Table ADC Channel and Mode
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define EXT_SINGLE_ENDED(index) ((uint16_t)((0x00 << 3) | (index)))
#define EXT_DIFFERENTIAL(index) ((uint16_t)((0x01 << 3) | (index)))
#define INTERNAL_VBAT_MODE ((uint16_t)((0x02 << 3) | 0x00))
#define EXT_CTC(index) ((uint16_t)((0x03 << 3) | (index)))
/** \} */
#if ADC_UNSUPPORT_P2_6
#define IS_SCHEDULE_TABLE(CONFIG) ((((CONFIG) & 0xF) != 0x6) && ((CONFIG) != 0xF))
#endif

#define SCHEDULE_TABLE(index) (index)
#define IS_ADC_SCHEDULE_INDEX_CONFIG(CONFIG)                                                       \
    ((((CONFIG) & 0xFFE0) == 0) &&                                                                 \
     ((((~(CONFIG)) & (0x18)) != 0) || ((CONFIG) == INTERNAL_VBAT_MODE)))

/**
 * \defgroup    ADC_Data_Avg_Num ADC Data Averge Num
 * \{
 * \brief       Number of raw data for calculate average.
 * \ingroup     ADC_Exported_Constants
 */

#define ADC_DATA_AVERAGE_OF_2 ((uint32_t)(0 << 25))
#define ADC_DATA_AVERAGE_OF_4 ((uint32_t)(1 << 25))
#define ADC_DATA_AVERAGE_OF_8 ((uint32_t)(2 << 25))
#define ADC_DATA_AVERAGE_OF_16 ((uint32_t)(3 << 25))
#define ADC_DATA_AVERAGE_OF_32 ((uint32_t)(4 << 25))
#define ADC_DATA_AVERAGE_OF_64 ((uint32_t)(5 << 25))
#define ADC_DATA_AVERAGE_OF_128 ((uint32_t)(6 << 25))
#define ADC_DATA_AVERAGE_OF_256 ((uint32_t)(7 << 25))
/** \} */

#define IS_ADC_DATA_AVG_NUM(NUM)                                                                   \
    (((NUM) == ADC_DATA_AVERAGE_OF_2) || ((NUM) == ADC_DATA_AVERAGE_OF_4) ||                       \
     ((NUM) == ADC_DATA_AVERAGE_OF_8) || ((NUM) == ADC_DATA_AVERAGE_OF_16) ||                      \
     ((NUM) == ADC_DATA_AVERAGE_OF_32) || ((NUM) == ADC_DATA_AVERAGE_OF_64) ||                     \
     ((NUM) == ADC_DATA_AVERAGE_OF_128) || ((NUM) == ADC_DATA_AVERAGE_OF_256))

/**
 * \defgroup    ADC_Data_Avg_En ADC Data Average Enable
 * \brief       Enable the calculation for average result of the one-shot mode.
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_DATA_AVERAGE_DISABLE ((uint32_t)(0 << 24))
#define ADC_DATA_AVERAGE_ENABLE ((uint32_t)(1 << 24))
/** \} */

#define IS_ADC_DATA_AVG_EN(CMD)                                                                    \
    (((CMD) == ADC_DATA_AVERAGE_DISABLE) || ((CMD) == ADC_DATA_AVERAGE_ENABLE))

/**
 * \defgroup    ADC_Power_On_Mode ADC Power On Mode
 * \{
 * \ingroup     ADC_Exported_Constants
 */

#define ADC_POWER_ON_AUTO ((uint32_t)(0 << 19))
#define ADC_POWER_ON_MANUAL ((uint32_t)(1 << 19))
/** \} */

#define IS_ADC_POWER_ON_MODE(MODE)                                                                 \
    (((MODE) == ADC_POWER_ON_AUTO) || ((MODE) == ADC_POWER_ON_MANUAL))

/**
 * \brief       ADC set power on procedure.
 */
#define IS_ADC_POWER_ON_PROCEDURE(CONFIG) (((CONFIG) == ADC_POWERON_VBAT) || ((CONFIG) == ADC_POWERON_VA11)\
                                           || ((CONFIG) == ADC_POWERON_RG1X_AUXADC_12) || ((CONFIG) == ADC_POWERON_RG2X_AUXADC_3))\
|| ((CONFIG) == ADC_POWERON_ERC_VA11) || ((CONFIG) == ADC_POWERON_RG2X_AUXADC_0))\
|| ((CONFIG) == ADC_POWERON_VA18) || ((CONFIG) == ADC_POWERON_RG0X_AUXADC_1))\
|| ((CONFIG) == ADC_POWERON_RG0X_AUXADC_0)))

/**
 * \defgroup    ADC_RG2X_0_Delay_Time ADC RG2X_0 Delay Time
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_RG2X_0_DELAY_10_US ((uint32_t)(0 << 4))
#define ADC_RG2X_0_DELAY_20_US ((uint32_t)(1 << 4))
#define ADC_RG2X_0_DELAY_40_US ((uint32_t)(2 << 4))
#define ADC_RG2X_0_DELAY_80_US ((uint32_t)(3 << 4))
/** \} */

#define IS_ADC_RG2X_0_DELAY_TIME(TIME)                                                             \
    (((TIME) == ADC_RG2X_0_DELAY_10_US) || ((TIME) == ADC_RG2X_0_DELAY_20_US) ||                   \
     ((TIME) == ADC_RG2X_0_DELAY_40_US) || ((TIME) == ADC_RG2X_0_DELAY_80_US))

/**
 * \defgroup    ADC_RG0X_1_Delay_Time ADC RG0X_1 Delay Time
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_RG0X_1_DELAY_20_US ((uint32_t)(0 << 2))
#define ADC_RG0X_1_DELAY_40_US ((uint32_t)(1 << 2))
#define ADC_RG0X_1_DELAY_80_US ((uint32_t)(2 << 2))
#define ADC_RG0X_1_DELAY_160_US ((uint32_t)(3 << 2))
/** \} */

#define IS_ADC_RG0X_1_DELAY_TIME(TIME)                                                             \
    (((TIME) == ADC_RG0X_1_DELAY_20_US) || ((TIME) == ADC_RG0X_1_DELAY_40_US) ||                   \
     ((TIME) == ADC_RG0X_1_DELAY_80_US) || ((TIME) == ADC_RG0X_1_DELAY_160_US))

/**
 * \defgroup    ADC_RG0X_0_Delay_Time ADC RG0X_0 Delay Time
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_RG0X_0_DELAY_30_US ((uint32_t)(0 << 0))
#define ADC_RG0X_0_DELAY_60_US ((uint32_t)(1 << 0))
#define ADC_RG0X_0_DELAY_120_US ((uint32_t)(2 << 0))
#define ADC_RG0X_0_DELAY_240_US ((uint32_t)(3 << 0))
/** \} */

#define IS_ADC_RG0X_0_DELAY_TIME(TIME)                                                             \
    (((TIME) == ADC_RG0X_0_DELAY_30_US) || ((TIME) == ADC_RG0X_0_DELAY_60_US) ||                   \
     ((TIME) == ADC_RG0X_0_DELAY_120_US) || ((TIME) == ADC_RG0X_0_DELAY_240_US))

/**
 * \defgroup    ADC_Data_Minus_En ADC Data Minus Enable
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_DATA_MINUS_DISABLE ((uint32_t)((uint32_t)0 << 31))
#define ADC_DATA_MINUS_ENABLE ((uint32_t)((uint32_t)1 << 31))
/** \} */

#define IS_ADC_DATA_MINUS_CMD(CMD)                                                                 \
    (((CMD) == ADC_DATA_MINUS_DISABLE) || ((CMD) == ADC_DATA_MINUS_ENABLE))

/**
 * \defgroup    ADC_Data_Align ADC Data Align
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_DATA_ALIGN_LSB (uint32_t)(0 << 30)
#define ADC_DATA_ALIGN_MSB (uint32_t)(1 << 30)
/** \} */

#define IS_ADC_DATA_ALIGN(DATA_ALIGN)                                                              \
    (((DATA_ALIGN) == ADC_DATA_ALIGN_LSB) || ((DATA_ALIGN) == ADC_DATA_ALIGN_MSB))

/**
 * \defgroup    ADC_Timer_Trigger_En ADC Timer Trigger En
 * \brief       ADC trigger one-shot mode with timer7.
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_TIMER_TRIGGER_DISABLE ((uint32_t)(0 << 29))
#define ADC_TIMER_TRIGGER_ENABLE ((uint32_t)(1 << 29))
/** \} */

#define IS_ADC_TIMER_TRIGGER_CMD(CMD)                                                              \
    (((CMD) == ADC_TIMER_TRIGGER_DISABLE) || ((CMD) == ADC_TIMER_TRIGGER_ENABLE))

/**
 * \defgroup    ADC_Power_Always_On_Cmd ADC Power Always On Cmd
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_POWER_ALWAYS_ON_DISABLE ((uint32_t)(0 << 15))
#define ADC_POWER_ALWAYS_ON_ENABLE ((uint32_t)(1 << 15))
/** \} */

#define IS_ADC_POWER_ALWAYS_ON(CMD)                                                                \
    (((CMD) == ADC_POWER_ALWAYS_ON_DISABLE) || ((CMD) == ADC_POWER_ALWAYS_ON_ENABLE))

/**
 * \defgroup    ADC_Convert_Time ADC Convert Time
 * \{
 * \ingroup     ADC_Exported_Constants
 */
#define ADC_CONVERT_TIME_500NS ((uint32_t)(0 << 30))
/** \} */

#define IS_ADC_CONVERT_TIME(TIME) ((TIME) == ADC_CONVERT_TIME_500NS)

/** End of ADC_Exported_Constants
 * \}
 */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup    ADC_Exported_Functions ADC Exported Functions
 * \{
 * \ingroup     ADC
 */

/**
 * rtl876x_adc.h
 *
 * \brief   Deinitializes the ADC peripheral registers to their
 *          default reset values(turn off ADC clock).
 * \details
 * \param[in] ADCx: Specify ADC peripheral, can only be ADC.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //Turn off the clock.
 *    ADC_DeInit(ADC);
 * }
 * \endcode
 */
void ADC_DeInit(ADC_TypeDef *ADCx);

/**
 * rtl876x_adc.h
 * \brief Initializes the ADC peripheral according to the specified
 *     parameters in the ADC_InitStruct
 * \param[in]  ADCx: selected ADC peripheral.
 * \param[in]  ADC_InitStruct: pointer to a ADC_InitTypeDef structure that
 *     contains the configuration information for the specified ADC peripheral
 * \return      None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //Turn on the clock.
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);

 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters that need to be configured here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 * }
 * \endcode
 */
void ADC_Init(ADC_TypeDef *ADCx, ADC_InitTypeDef *ADC_InitStruct);

/**
 * rtl876x_adc.h
 * \brief   Fills each ADC_InitStruct member with its default value.
 * \param[in] ADC_InitStruct: Pointer to an ADC_InitTypeDef structure which will be initialized.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //Turn on the clock.
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);

 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters that need to be configured here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 * }
 * \endcode
 * \callgraph
 *
 */
void ADC_StructInit(ADC_InitTypeDef *ADC_InitStruct);

/**
 * rtl876x_adc.h
 * \brief   Enables or disables the ADC peripheral.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  adcMode: ADC operation mode selection.
        This parameter can be one of the following values:
 *     \arg ADC_ONE_SHOT_MODE: One shot mode.
 *     \arg ADC_CONTINUOUS_MODE: Continuous sampling mode.
 * \param[in]  NewState: New state of the ADC peripheral.
 *     This parameter can be: ENABLE or DISABLE.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 *
 *     Pad_Config(P2_1, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 * }
 *
 * void driver_adc_init(void)
 * {
 *    //open clock
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 *
 * void adc_demo(void)
 * {
 *    board_adc_init();
 *    driver_adc_init();
 *    ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 * }
 * \endcode
 */
void ADC_Cmd(ADC_TypeDef *ADCx, uint8_t adcMode, FunctionalState NewState);

/**
 * rtl876x_adc.h
 * \brief   Enables or disables the specified ADC interrupts.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  ADC_IT: Specify the ADC interrupts sources to be enabled or disabled.
 *     This parameter can be any combination of the following values:
 *     \arg ADC_INT_FIFO_RD_REQ : ADC FIFO size>=burst size interrupt.
 *     \arg ADC_INT_FIFO_RD_ERR : ADC FIFO underflow interrupt.
 *     \arg ADC_INT_FIFO_THD : ADC FIFO size > thd interrupt.
 *     \arg ADC_INT_FIFO_FULL : ADC FIFO full interrupt.
 *     \arg ADC_INT_ONE_SHOT_DONE : ADC one shot mode done interrupt.
 *     \arg ADC_INT_FIFO_OVERFLOW : ADC FIFO overflow interrupt.
 * \param[in]  newState: New state of the specified ADC interrupt.
 *     This parameter can be: ENABLE or DISABLE.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //open clock
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_FIFO_RD_ERR, ENABLE);
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 * \endcode
 *
 */
void ADC_INTConfig(ADC_TypeDef *ADCx, uint32_t ADC_INT, FunctionalState NewState);

/**
 * rtl876x_adc.h
 * \brief      Read ADC data according to specific channel.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  index: Can be 0 to 15.
 * \return     The 12-bit converted ADC raw data.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 *
 *     Pad_Config(P2_1, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 * }
 *
 * void driver_adc_init(void)
 * {
 *    //open clock
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 *
 * void adc_demo(void)
 * {
 *    board_adc_init();
 *    driver_adc_init();
 *    ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 *    while(ADC_GetINTStatus(ADC, ADC_INT_ONE_SHOT_DONE) == RESET);
 *    uint16_t raw_data_0 = ADC_ReadRawData(ADC, 0);
 *    uint16_t raw_data_1 = ADC_ReadRawData(ADC, 1);
 * }
 * \endcode
 */
uint16_t ADC_ReadRawData(ADC_TypeDef *ADCx, uint8_t index);

/**
 * rtl876x_adc.h
 * \brief   Get ADC average data from ADC schedule table0.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[out] OutBuf: Buffer to save data read from ADC FIFO.
 * \return  The 12-bit converted ADC raw data.
 * \callgraph
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 * }
 *
 * void driver_adc_init(void)
 * {
 *    //open clock
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_Bitmap = 0x01;
 *    ADC_InitStruct.ADC_DataAvgEn  = ADC_DATA_AVERAGE_ENABLE;
 *    ADC_InitStruct.ADC_DataAvgSel = ADC_DATA_AVERAGE_OF_2;
 *    //Add other initialization parameters here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 *
 * void adc_demo(void)
 * {
 *    board_adc_init();
 *    driver_adc_init();
 *    ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 *    while(ADC_GetINTStatus(ADC, ADC_INT_ONE_SHOT_DONE) == RESET);
 *    uint16_t raw_data = 0;
 *    raw_data = ADC_ReadAvgRawData(ADC);
 * }
 * \endcode
 *
 */
uint16_t ADC_ReadAvgRawData(ADC_TypeDef *ADCx);

/**
 * rtl876x_adc.h
 * \brief  Read one byte data from ADC FIFO.
 * \param[in]  ADCx: selected ADC peripheral.
 * \return adc FIFO data.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 * }
 *
 * void driver_adc_init(void)
 * {
 *    //open clock
 *    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_Bitmap = 0x01;
 *    ADC_InitStruct.ADC_DataWriteToFifo = ADC_DATA_WRITE_TO_FIFO_DISABLE;
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 *
 * void adc_demo(void)
 * {
 *    board_adc_init();
 *    driver_adc_init();
 *    ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 *    while(ADC_GetINTStatus(ADC, ADC_INT_ONE_SHOT_DONE) == RESET);
 *    uint16_t raw_data = 0;
 *    raw_data = ADC_ReadFIFO(ADC);
 * }
 * \endcode
 */
uint16_t ADC_ReadFIFO(ADC_TypeDef *ADCx);

/**
 * rtl876x_adc.h
 * \brief   Get data from ADC FIFO.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[out] outBuf: Buffer to save data read from ADC FIFO.
 * \param[in]  num: Number of data to be read.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *    //ADC already start
 *    uint16_t raw_data[32] = {0};
 *    uint8_t data_len = ADC_GetFIFODataLen(ADC);
 *    ADC_ReadFIFOData(ADC,raw_data,data_len);
 * }
 * \endcode
 *
 */
void ADC_ReadFIFOData(ADC_TypeDef *ADCx, uint16_t *outBuf, uint16_t num);

/**
 * rtl876x_adc.h
 * \brief   Get ADC fifo data number.
 * \param[in] ADCx: selected ADC peripheral.
 * \return  Current data number in ADC FIFO.
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *    //ADC already start
 *    uint16_t raw_data[32] = {0};
 *    uint8_t data_len = ADC_GetFIFODataLen(ADC);
 *    ADC_ReadFIFOData(ADC,raw_data,data_len);
 * }
 * \endcode
 *
 */
uint8_t ADC_GetFIFODataLen(ADC_TypeDef *ADCx);

/**
 * rtl876x_adc.h
 * \brief   Config ADC schedule table.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  adcMode: ADC operation mode.
 *     This parameter can be one of the following values:
 *     \arg EXT_SINGLE_ENDED(index)
 *     \arg EXT_DIFFERENTIAL(index)
 *     \arg INTERNAL_VBAT_MODE
 * \param[in]  Index: Schedule table index.
 * \return  None.
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_SchIndexConfig(ADC,INTERNAL_VBAT_MODE,0);
 * }
 * \endcode
 *
 */
void ADC_SchIndexConfig(ADC_TypeDef *ADCx, uint8_t adcMode, uint16_t Index);

/**
 * \brief  Config ADC schedule table.
 * \param[in]  ADCx: selected ADC peripheral.
 * \param[in]  Index: Schedule table index.
 * \param[in]  adcMode: ADC mode.
 *      this parameter can be one of the following values:
 *     \arg EXT_SINGLE_ENDED(index)
 *     \arg EXT_DIFFERENTIAL(index)
 *     \arg VREF_AT_CHANNEL7(index)
 *     \arg INTERNAL_VBAT_MODE
 *     \arg INTERNAL_VADPIN_MODE
 *     \arg INTERNAL_VDDCORE_MODE
 *     \arg INTERNAL_VCORE_MODE
 *     \arg INTERNAL_ICHARGE_MODE
 *     \arg INTERNAL_IDISCHG_MODE
 * \return none.
 */
void ADC_SchTableConfig(ADC_TypeDef *ADCx, uint16_t Index, uint8_t adcMode);

/**
 * rtl876x_adc.h
 * \brief   Config adc schedule table.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  channelMap: ADC channel map.
 * \param[in]  NewState: New state of the ADC peripheral.
 *      This parameter can be: ENABLE or DISABLE.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   uint16_t bit_map = 0x03;
 *   ADC_BitMapConfig(ADC,bit_map,ENABLE);
 * }
 * \endcode
 */
void ADC_BitMapConfig(ADC_TypeDef *ADCx, uint16_t bitMap, FunctionalState NewState);

/**
 * rtl876x_adc.h
 * \brief   Power on ADC manually.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  NewState: New state of the ADC power on.
 *      This parameter can be: ENABLE or DISABLE. If enabled, ADC power will always be on until
 * disabled. \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_ManualPowerOnCmd(ADC,ENABLE);
 * }
 * \endcode
 */
void ADC_ManualPowerOnCmd(ADC_TypeDef *ADCx, FunctionalState NewState);

/**
 * rtl876x_adc.h
 * \brief   Enbale or disable stop FIFO from writing data.
 * \param[in]  ADCx: Specify ADC peripheral.
 * \param[in]  NewState: New state of the ADC FIFO write.
 *     This parameter can be: ENABLE or DISABLE.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_WriteFIFOCmd(ADC, ENABLE);
 * }
 * \endcode
 */
void ADC_WriteFIFOCmd(ADC_TypeDef *ADCx, FunctionalState NewState);

/**
 * rtl876x_adc.h
 * \brief  Config ADC bypass resistor.
 * \param[in] channelNum: External channel number, can be 0~7.
 * \param[in] NewState: Specifies whether the channel enables bypass mode.
 *     This parameter can be: ENABLE or DISABLE.
 * \return  None.
 * \note    The input voltage of channel pin using bypass mode cannot exceed 0.9V!
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_BypassCmd(0,ENABLE);
 * }
 * \endcode
 */
void ADC_BypassCmd(uint8_t ChannelNum, FunctionalState NewState);

/**
 * rtl876x_adc.h
 * \brief  Check whether the specified ADC interrupt flag is set.
 * \param[in]  ADCx: selected ADC peripheral.
 * \param[in]  ADC_INT_FLAG: Specifies the interrupt flag to check.
 *     This parameter can be one of the following values:
 *     \arg ADC_INT_FIFO_OVERFLOW: ADC FIFO overflow interrupt.
 *     \arg ADC_INT_ONE_SHOT_DONE: ADC once convert end interrupt.
 *     \arg ADC_INT_FIFO_FULL : ADC FIFO full interrupt.
 *     \arg ADC_INT_FIFO_THD: FIFO larger than threshold interrupt.
 *     \arg ADC_INT_FIFO_RD_ERR: ADC FIFO underflow interrupt.
 *     \arg ADC_INT_FIFO_RD_REQ: ADC FIFO size>=burst size interrupt.
 *
 * \return The new state of ADC_INT (SET or RESET).
 * \retval SET.
 * \retval RESET.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *     ITStatus int_status = RESET;
 *     int_status = ADC_GetINTStatus(ADC,ADC_INT_FIFO_OVERFLOW);
 * }
 * \endcode
 */
ITStatus ADC_GetINTStatus(ADC_TypeDef *ADCx, uint32_t ADC_INT);

/**
 * rtl876x_adc.h
 * \brief  Clear the ADC interrupt pending bit.
 * \param[in] ADCx: Specify ADC peripheral.
 * \param[in] ADC_INT: Specifies the interrupt pending bit to clear.
 *     This parameter can be any combination of the following values:
 *     \arg ADC_INT_FIFO_OVERFLOW: ADC FIFO overflow interrupt.
 *     \arg ADC_INT_ONE_SHOT_DONE: ADC once convert end interrupt.
 *     \arg ADC_INT_FIFO_FULL: ADC FIFO full interrupt.
 *     \arg ADC_INT_FIFO_THD: FIFO larger than threshold interrupt.
 *     \arg ADC_INT_FIFO_RD_ERR: ADC FIFO underflow interrupt.
 *     \arg ADC_INT_FIFO_RD_REQ: ADC FIFO size>=burst size interrupt.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_ClearINTPendingBit(ADC,ADC_INT_FIFO_OVERFLOW);
 * }
 * \endcode
 */
void ADC_ClearINTPendingBit(ADC_TypeDef *ADCx, uint32_t ADC_INT);

/**
 * rtl876x_adc.h
 * \brief   Clear ADC FIFO.
 * \param[in] ADCx: Specify ADC peripheral.
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_ClearFIFO(ADC);
 * }
 * \endcode
 */
__STATIC_INLINE void ADC_ClearFIFO(ADC_TypeDef *ADCx)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

    ADCx->CR |= BIT26;
}

/**
 * rtl876x_adc.h
 * \brief   Get all adc interrupt flag status.
 * \param[in] ADCx: Specify ADC peripheral.
 * \return  All ADC interrupt status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void adc_demo(void)
 * {
 *   uint8_t all_flag_status = 0;
 *   all_flag_status = ADC_GetAllFlagStatus(ADC);
 * }
 * \endcode
 *
 */
__STATIC_INLINE uint8_t ADC_GetAllFlagStatus(ADC_TypeDef *ADCx)
{
    /* Check the parameters */
    assert_param(IS_ADC_PERIPH(ADCx));

    return ((uint8_t)(((ADCx->INTCR) & (0x1f << 16)) >> 16));
}

/** End of ADC_Exported_Functions
 * \}
 */

/** End of ADC
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif /* _RTL876X_ADC_H_ */

/******************* (C) COPYRIGHT 2024 Realtek Semiconductor *****END OF FILE****/
