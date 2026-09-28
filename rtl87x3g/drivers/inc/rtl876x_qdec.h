/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */


#ifndef RTL_QDEC_H
#define RTL_QDEC_H

#ifdef __cplusplus
extern "C" {
#endif


/** @addtogroup 87x3g_QDEC QDEC
  * @brief Qdecoder driver module.
  * @{
  */

/*============================================================================*
 *                         Includes
 *============================================================================*/
#include <stdbool.h>
#include "rtl876x.h"
#include "rtl876x_qdec_def.h"

/*============================================================================*
 *                         Constants
 *============================================================================*/

/** @defgroup 87x3g_QDEC_Exported_Constants     QDEC Exported Constants
  * @{
  */

/**
 * \brief       QDEC Axis Counter Scale
 */

typedef enum
{
    CounterScale_1_Phase = 0x00,  //!< Update counter when 1 phase change.
    CounterScale_2_Phase = 0x01,  //!< Update counter when 2 phase change.
} QDECAxisCntScale_TypeDef;

#define IS_QDEC_AXIS_CNT_SCALE_TYPE(TYPE) ((TYPE) <= 0x01)  //!< Check whether is the counter scale type.

/**
 * \brief       QDEC Init Phase
 */

typedef enum
{
    phaseMode0 = 0x00,      //!< Set the initial phase to 00.
    phaseMode1 = 0x01,      //!< Set the initial phase to 01.
    phaseMode2 = 0x02,      //!< Set the initial phase to 10.
    phaseMode3 = 0x03,      //!< Set the initial phase to 11.
} QDECInitPhase_TypeDef;

#define IS_QDEC_INIT_PHASE_TYPE(TYPE) ((TYPE) <= 0x03)    //!< Check whether is the init phase.

/**
 * \brief       QDEC Axis Direction
 */

typedef enum
{
    QDEC_AXIS_DIR_DOWN = 0x00,    //!< The direction of QDEC is down.
    QDEC_AXIS_DIR_UP = 0x01,      //!< The direction of QDEC is up.
} QDECAxisDir_TypeDef;

#define IS_QDEC_AXIS_DIR(QDEC_AXIS)     ((QDEC_AXIS == QDEC_AXIS_DIR_UP) || (QDEC_AXIS == QDEC_AXIS_DIR_DOWN))  //!< Check whether is the direction of QDEC.

/** @defgroup 87x3g_QDEC_Interrupts_Definition  QDEC Interrupts Definition
  * @{
  */

#define QDEC_X_INT_NEW_DATA           BIT0    //!< The counter interrupt for the X axis triggers when the counter value changes.
#define QDEC_X_INT_ILLEAGE            BIT1    //!< The illegal interrupt for X axis.
#define QDEC_Y_INT_NEW_DATA           BIT2    //!< The counter interrupt for the Y axis triggers when the counter value changes.
#define QDEC_Y_INT_ILLEAGE            BIT3    //!< The illegal interrupt for Y axis.
#define QDEC_Z_INT_NEW_DATA           BIT4    //!< The counter interrupt for the Z axis triggers when the counter value changes.
#define QDEC_Z_INT_ILLEAGE            BIT5    //!< The illegal interrupt for Z axis.

#define IS_QDEC_INT_CONFIG(CONFIG) (((CONFIG) == QDEC_X_INT_NEW_DATA) || ((CONFIG) == QDEC_X_INT_ILLEAGE)\
                                    || ((CONFIG) == QDEC_Y_INT_NEW_DATA) || ((CONFIG) == QDEC_Y_INT_ILLEAGE)\
                                    || ((CONFIG) == QDEC_Z_INT_NEW_DATA) || ((CONFIG) == QDEC_Z_INT_ILLEAGE))   //!< Check whether is the QDEC interrupt.
/** End of group 87x3g_QDEC_Interrupts_Definition
  * @}
  */

/** @defgroup 87x3g_QDEC_Interrupts_Mask    QDEC Interrupts Mask
  * @{
  */

#define QDEC_X_CT_INT_MASK            BIT0    //!< Mask the counter interrupt for the X axis.
#define QDEC_X_ILLEAGE_INT_MASK       BIT4    //!< Mask the illegal interrupt for X axis.
#define QDEC_Y_CT_INT_MASK            BIT1    //!< Mask the counter interrupt for the Y axis.
#define QDEC_Y_ILLEAGE_INT_MASK       BIT5    //!< Mask the illegal interrupt for Y axis.
#define QDEC_Z_CT_INT_MASK            BIT2    //!< Mask the counter interrupt for the Z axis.
#define QDEC_Z_ILLEAGE_INT_MASK       BIT6    //!< Mask the illegal interrupt for Z axis.

#define IS_QDEC_INT_MASK_CONFIG(CONFIG) (((CONFIG) == QDEC_X_CT_INT_MASK) || ((CONFIG) == QDEC_X_ILLEAGE_INT_MASK)\
                                         || ((CONFIG) == QDEC_Y_CT_INT_MASK) || ((CONFIG) == QDEC_Y_ILLEAGE_INT_MASK)\
                                         || ((CONFIG) == QDEC_Z_CT_INT_MASK) || ((CONFIG) == QDEC_Z_ILLEAGE_INT_MASK))    //!< Check whether is the mask of QDEC interrupt.
/** End of group 87x3g_QDEC_Interrupts_Mask
  * @}
  */

/** @defgroup 87x3g_QDEC_Clr_Flag   QDEC Clear Flag
  * @{
  */

#define QDEC_CLR_ILLEGAL_CT_X       BIT20   //!< Clear the illegal counter for X axis.
#define QDEC_CLR_ILLEGAL_CT_Y       BIT21   //!< Clear the illegal counter for Y axis.
#define QDEC_CLR_ILLEGAL_CT_Z       BIT22   //!< Clear the illegal counter for Z axis.

#define QDEC_CLR_ACC_CT_X           BIT16   //!< Clear the counter for X axis.
#define QDEC_CLR_ACC_CT_Y           BIT17   //!< Clear the counter for Y axis.
#define QDEC_CLR_ACC_CT_Z           BIT18   //!< Clear the counter for Z axis.

#define QDEC_CLR_ILLEGAL_INT_X      BIT12   //!< Clear the illegal interrupt for X axis.
#define QDEC_CLR_ILLEGAL_INT_Y      BIT13   //!< Clear the illegal interrupt for Y axis.
#define QDEC_CLR_ILLEGAL_INT_Z      BIT14   //!< Clear the illegal interrupt for Z axis.

#define QDEC_CLR_UNDERFLOW_X        BIT8    //!< Clear the unferflow interrupt for X axis.
#define QDEC_CLR_UNDERFLOW_Y        BIT9    //!< Clear the unferflow interrupt for Y axis.
#define QDEC_CLR_UNDERFLOW_Z        BIT10   //!< Clear the unferflow interrupt for Z axis.

#define QDEC_CLR_OVERFLOW_X         BIT4    //!< Clear the overflow interrupt for X axis.
#define QDEC_CLR_OVERFLOW_Y         BIT5    //!< Clear the overflow interrupt for Y axis.
#define QDEC_CLR_OVERFLOW_Z         BIT6    //!< Clear the overflow interrupt for Z axis.

#define QDEC_CLR_NEW_CT_X           BIT0    //!< Clear the counter interrupt for X axis.
#define QDEC_CLR_NEW_CT_Y           BIT1    //!< Clear the counter interrupt for Y axis.
#define QDEC_CLR_NEW_CT_Z           BIT2    //!< Clear the counter interrupt for Z axis.

#define IS_QDEC_INT_CLR_CONFIG(CONFIG) (((CONFIG) == QDEC_CLR_ACC_CT_X) || ((CONFIG) == QDEC_CLR_ACC_CT_Y)\
                                        || ((CONFIG) == QDEC_CLR_ACC_CT_Z) || ((CONFIG) == QDEC_CLR_ILLEGAL_INT_Y)\
                                        || ((CONFIG) == QDEC_CLR_ILLEGAL_INT_Z) || ((CONFIG) == QDEC_CLR_UNDERFLOW_X)\
                                        || ((CONFIG) == QDEC_CLR_UNDERFLOW_Y) || ((CONFIG) == QDEC_CLR_UNDERFLOW_Z)\
                                        || ((CONFIG) == QDEC_CLR_OVERFLOW_X) || ((CONFIG) == QDEC_CLR_OVERFLOW_Y)\
                                        || ((CONFIG) == QDEC_CLR_OVERFLOW_Z) || ((CONFIG) == QDEC_CLR_NEW_CT_X)\
                                        || ((CONFIG) == QDEC_CLR_NEW_CT_Y) || ((CONFIG) == QDEC_CLR_NEW_CT_Z))  //!< Check whether is the clear bit of QDEC.
/** End of group 87x3g_QDEC_Clr_Flag
  * @}
  */

/** @defgroup 87x3g_QDEC_Flag QDEC Flag
  * @{
  */

#define QDEC_FLAG_NEW_CT_STATUS_X       BIT0    //!< The counter flag for X axis.
#define QDEC_FLAG_NEW_CT_STATUS_Y       BIT1    //!< The counter flag for Y axis.
#define QDEC_FLAG_NEW_CT_STATUS_Z       BIT2    //!< The counter flag for Z axis.
#define QDEC_FLAG_OVERFLOW_X            BIT3    //!< The overflow flag for X axis.
#define QDEC_FLAG_OVERFLOW_Y            BIT4    //!< The overflow flag for Y axis.
#define QDEC_FLAG_OVERFLOW_Z            BIT5    //!< The overflow flag for Z axis.
#define QDEC_FLAG_UNDERFLOW_X           BIT6    //!< The underflow flag for X axis.
#define QDEC_FLAG_UNDERFLOW_Y           BIT7    //!< The underflow flag for Y axis.
#define QDEC_FLAG_UNDERFLOW_Z           BIT8    //!< The underflow flag for Z axis.
#define QDEC_FLAG_ILLEGAL_STATUS_X      BIT12   //!< The illegal flag for X axis.
#define QDEC_FLAG_ILLEGAL_STATUS_Y      BIT13   //!< The illegal flag for Y axis.
#define QDEC_FLAG_ILLEGAL_STATUS_Z      BIT14   //!< The illegal flag for Z axis.

#define IS_QDEC_INT_STATUS(INT) (((INT) == QDEC_FLAG_ILLEGAL_STATUS_X) || ((INT) == QDEC_FLAG_ILLEGAL_STATUS_Y)\
                                 || ((INT) == QDEC_FLAG_ILLEGAL_STATUS_Z) || ((INT) == QDEC_FLAG_NEW_CT_STATUS_X)\
                                 || ((INT) == QDEC_FLAG_NEW_CT_STATUS_Y) || ((INT) == QDEC_FLAG_NEW_CT_STATUS_Z)\
                                 || ((INT) == QDEC_FLAG_OVERFLOW_X) || ((INT) == QDEC_FLAG_OVERFLOW_Y)\
                                 || ((INT) == QDEC_FLAG_OVERFLOW_Z) || ((INT) == QDEC_FLAG_UNDERFLOW_X)\
                                 || ((INT) == QDEC_FLAG_UNDERFLOW_Y) || ((INT) == QDEC_FLAG_UNDERFLOW_Z))
/** End of group 87x3g_QDEC_Flag
  * @}
  */

/** @defgroup 87x3g_QDEC_Axis   QDEC Axis
  * @{
  */
#define QDEC_AXIS_X                 BIT0    //!< The X axis of QDEC.
#define QDEC_AXIS_Y                 BIT2    //!< The Y axis of QDEC.
#define QDEC_AXIS_Z                 BIT3    //!< The Z axis of QDEC.

/** End of group 87x3g_QDEC_Axis
  * @}
  */

/** End of group 87x3g_QDEC_Exported_Constants
  * @}
  */

/// \cond

/**
 * \brief       QDEC Immediate Number definition
 */
#define QDEC_0X00_CNT_PAUSE         BIT3
#define QDEC_0X08_CNT_DIR           BIT16
#define QDEC_0X04_AXIS_EN           BIT31
/// \endcond
/*============================================================================*
 *                         Types
 *============================================================================*/

/** @defgroup 87x3g_QDEC_Exported_Types QDEC Exported Types
  * @{
  */

/**
 * @brief Qdecoder initialize parameters.
 */
typedef struct
{
#if (QDEC_CLOCK_INIT_USE_KHZ == 1)
    uint16_t ScanClockKHZ;                 /*!< Specifies the scan clock(KHz).
                                                  Scan clock = source clock / (DIV+1), source clock is 20000KHz, DIV range is 0x0 to 0xFFF*/

    uint16_t DebonceClockKHZ;             /*!< Specifies the debounce clock(KHz).
                                                  Debounce clock = scan clock / (DEB_DIV+1), DEB_DIV range is 0x0 to 0xF  */
#else
    uint16_t scanClockDiv;                 /*!< Specifies DIV for Scan clock. */
    uint16_t debounceClockDiv;             /*!< Specifies DEB_DIV for debounce clock. */
#endif
    uint8_t axisConfigX;                   /*!< Specifies the axis X function.
                                                 This parameter can be a value of ENABLE or DISABLE. */
    uint8_t axisConfigY;                   /*!< Specifies the axis Y function.
                                                This parameter can be a value of ENABLE or DISABLE. */
    uint8_t axisConfigZ;                   /*!< Specifies the axis Z function.
                                                This parameter can be a value of ENABLE or DISABLE. */
    FunctionalState manualLoadInitPhase;   /*!< Specifies manual-load Initphase function.
                                                This parameter can be a value of ENABLE or DISABLE. */
    QDECAxisCntScale_TypeDef counterScaleX;/*!< Specifies the axis X conter scale.
                                                This parameter can be a value of @ref QDECAxisCntScale_TypeDef.*/
    FunctionalState debounceEnableX;       /*!< Specifies the axis X debounce.
                                                This parameter can be a value of ENABLE or DISABLE. */
    uint16_t debounceTimeX;                /*!< Specifies the axis X debounce time.
                                                This parameter can be a value from 0 to 0xFF. */
    QDECInitPhase_TypeDef initPhaseX;      /*!< Specifies the axis X init phase.
                                                This parameter can be a value of @ref QDECInitPhase_TypeDef. */
    QDECAxisCntScale_TypeDef counterScaleY;/*!< Specifies the axis Y conter scale.
                                                  This parameter can be a value of @ref QDECAxisCntScale_TypeDef. */
    FunctionalState debounceEnableY;       /*!< Specifies the axis Y debounce.
                                                This parameter can be a value of ENABLE or DISABLE. */
    uint16_t debounceTimeY;                /*!< Specifies the axis Y debounce time.
                                                  This parameter can be a value from 0 to 0xFF. */
    QDECInitPhase_TypeDef initPhaseY;      /*!< Specifies the axis Y init phase.
                                                  This parameter can be a value of @ref QDECInitPhase_TypeDef.  */
    QDECAxisCntScale_TypeDef counterScaleZ;/*!< Specifies the axis Z conter scale.
                                                  This parameter can be a value of @ref QDECAxisCntScale_TypeDef. */
    FunctionalState debounceEnableZ;       /*!< Specifies the axis Z debounce.
                                                This parameter can be a value of ENABLE or DISABLE. */
    uint16_t debounceTimeZ;                /*!< Specifies the axis Z debounce time.
                                                  This parameter can be a value from 0 to 0xFF. */
    QDECInitPhase_TypeDef initPhaseZ;      /*!< Specifies the axis Z init phase.
                                                  This parameter can be a value of @ref QDECInitPhase_TypeDef. */
} QDEC_InitTypeDef;

/** End of group 87x3g_QDEC_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/

/** @defgroup 87x3g_QDEC_Exported_Functions QDEC Exported Functions
 * @{
 */


/**
 * \brief   Deinitializes the Qdecoder peripheral registers to their default reset values(turn off Qdecoder clock).
 *
 * \param[in] QDECx: Selected Qdecoder peripheral. \ref x3g_QDEC_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_qdec_init(void)
 * {
 *     QDEC_DeInit();
 * }
 * \endcode
 */
void QDEC_DeInit(QDEC_TypeDef *QDECx);

/**
 * \brief   Initializes the Qdecoder peripheral according to the specified
 *          parameters in the QDEC_InitStruct
 *
 * \param[in]  QDECx: Selected Qdecoder peripheral. \ref x3g_QDEC_Declaration.
 * \param[in]  QDEC_InitStruct: Pointer to a \ref _X3G_QDEC_InitTypeDef structure that
 *             contains the configuration information for the specified Qdecoder peripheral
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_qdec_init(void)
 * {
 *     QDEC_DeInit(QDEC);
 *     RCC_PeriphClockCmd(APBPeriph_QDEC, APBPeriph_QDEC_CLOCK, ENABLE);
 *
 *     QDEC_InitTypeDef QDEC_InitStruct;
 *     QDEC_StructInit(&QDEC_InitStruct);
 *     QDEC_InitStruct.axisConfigY       = ENABLE;
 *     QDEC_InitStruct.debounceEnableY   = Debounce_Enable;
 *     QDEC_Init(QDEC, &QDEC_InitStruct);
 *
 *     QDEC_Cmd(QDEC, QDEC_AXIS_Y, ENABLE);
 * }
 * \endcode
 */
void QDEC_Init(QDEC_TypeDef *QDECx, QDEC_InitTypeDef *QDEC_InitStruct);

/**
 * \brief  Fills each QDEC_InitStruct member with its default value.
 *
 * \note   The default settings for the QDEC_InitStruct member are shown in the following table:
 *         | QDEC_InitStruct Member | Default Value             |
 *         |:----------------------:|:-------------------------:|
 *         | ScanClockKHZ           | 50                        |
 *         | DebonceClockKHZ        | 5                         |
 *         | axisConfigX            | DISABLE                   |
 *         | debounceTimeX          | 25                        |
 *         | counterScaleX          | \ref CounterScale_1_Phase |
 *         | debounceEnableX        | \ref ENABLE               |
 *         | initPhaseX             | \ref phaseMode0           |
 *         | axisConfigY            | DISABLE                   |
 *         | debounceTimeY          | 25                        |
 *         | counterScaleY          | \ref CounterScale_1_Phase |
 *         | debounceEnableY        | \ref ENABLE               |
 *         | initPhaseY             | \ref phaseMode0           |
 *         | axisConfigZ            | DISABLE                   |
 *         | debounceTimeZ          | 25                        |
 *         | counterScaleZ          | \ref CounterScale_1_Phase |
 *         | debounceEnableZ        | \ref ENABLE               |
 *         | initPhaseZ             | \ref phaseMode0           |
 *
 * \param[in]  QDEC_InitStruct: Pointer to a \ref _X3G_QDEC_InitTypeDef structure which will be initialized.
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_qdec_init(void)
 * {
 *     QDEC_DeInit(QDEC);
 *     RCC_PeriphClockCmd(APBPeriph_QDEC, APBPeriph_QDEC_CLOCK, ENABLE);
 *
 *     QDEC_InitTypeDef QDEC_InitStruct;
 *     QDEC_StructInit(&QDEC_InitStruct);
 *     QDEC_InitStruct.axisConfigY       = ENABLE;
 *     QDEC_InitStruct.debounceEnableY   = Debounce_Enable;
 *     QDEC_Init(QDEC, &QDEC_InitStruct);
 *
 *     QDEC_Cmd(QDEC, QDEC_AXIS_Y, ENABLE);
 * }
 * \endcode
 */
void QDEC_StructInit(QDEC_InitTypeDef *QDEC_InitStruct);

/**
 * \brief  Enables or disables the specified Qdecoder interrupt source.
 *
 * \param[in] QDECx: Selected Qdecoder peripheral. \ref x3g_QDEC_Declaration.
 * \param[in] QDEC_IT: Specifies the QDECODER interrupts sources to be enabled or disabled. \ref x3g_QDEC_Interrupts_Definition.
 *            This parameter parameter can be one of the following values:
 *            -  QDEC_X_INT_NEW_DATA: The counter interrupt for X axis.
 *            -  QDEC_X_INT_ILLEAGE: The illegal interrupt for X axis.
 *            -  QDEC_Y_INT_NEW_DATA: The counter interrupt for Y axis.
 *            -  QDEC_Y_INT_ILLEAGE: The illegal interrupt for Y axis.
 *            -  QDEC_Z_INT_NEW_DATA: The counter interrupt for Z axis.
 *            -  QDEC_Z_INT_ILLEAGE: The illegal interrupt for Z axis.
 * \param[in] NewState: New state of the specified QDECODER interrupt.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified Qdecoder interrupt.
 *            - DISABLE: Disable the specified Qdecoder interrupt.
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_qdec_init(void)
 * {
 *     QDEC_INTConfig(QDEC, QDEC_Y_INT_NEW_DATA, ENABLE);
 * }
 * \endcode
 */
void QDEC_INTConfig(QDEC_TypeDef *QDECx, uint32_t QDEC_IT, FunctionalState NewState);

/**
 * \brief  Check whether the specified Qdecoder flag is set.
 *
 * \param[in] QDECx: Selected Qdecoder peripheral. \ref x3g_QDEC_Declaration.
 * \param[in] QDEC_FLAG: Specifies the flag to check. \ref x3g_QDEC_Flag.
 *            This parameter can be one of the following values:
 *            - QDEC_FLAG_NEW_CT_STATUS_X: Status of the counter interrupt for X axis.
 *            - QDEC_FLAG_NEW_CT_STATUS_Y: Status of the counter interrupt for Y axis.
 *            - QDEC_FLAG_NEW_CT_STATUS_Z: Status of the counter interrupt for Z axis.
 *            - QDEC_FLAG_ILLEGAL_STATUS_X: Status of the illegal interrupt for X axis.
 *            - QDEC_FLAG_ILLEGAL_STATUS_Y: Status of the illegal interrupt for Y axis.
 *            - QDEC_FLAG_ILLEGAL_STATUS_Z: Status of the illegal interrupt for Z axis.
 *            - QDEC_FLAG_OVERFLOW_X: The overflow flag for x-axis accumulation counter.
 *            - QDEC_FLAG_OVERFLOW_Y: The overflow flag for y-axis accumulation counter.
 *            - QDEC_FLAG_OVERFLOW_Z: The overflow flag for z-axis accumulation counter.
 *            - QDEC_FLAG_UNDERFLOW_X: The underflow flag for x-axis accumulation counter.
 *            - QDEC_FLAG_UNDERFLOW_Y: The underflow flag for y-axis accumulation counter.
 *            - QDEC_FLAG_UNDERFLOW_Z: The underflow flag for z-axis accumulation counter.
 *
 * \return The new state of QDEC_FLAG (SET or RESET).
 * \retval SET: The specified Qdecoder flag is set.
 * \retval RESET: The specified Qdecoder flag is unset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void qdec_demo(void)
 * {
 *     FlagStatus flag_status = QDEC_GetFlagState(QDEC, QDEC_Y_INT_NEW_DATA);
 * }
 * \endcode
 */
FlagStatus QDEC_GetFlagState(QDEC_TypeDef *QDECx, uint32_t QDEC_FLAG);

/**
 * \brief  Enables or disables mask the specified Qdecoder axis interrupts.
 *
 * \param[in] QDECx: Selected Qdecoder peripheral. \ref x3g_QDEC_Declaration.
 * \param[in] QDEC_AXIS: Specifies the Qdecoder axis. \ref x3g_QDEC_Interrupts_Mask.
 *            This parameter can be one or logical OR of the following values:
 *            - QDEC_X_CT_INT_MASK: The x-axis counter interrupt mask.
 *            - QDEC_X_ILLEAGE_INT_MASK: The x-axis illegal interrupt mask.
 *            - QDEC_Y_CT_INT_MASK: The y-axis counter interrupt mask.
 *            - QDEC_Y_ILLEAGE_INT_MASK: The y-axis illegal interrupt mask.
 *            - QDEC_Z_CNT_INT_MASK: The z-axis counter interrupt mask.
 *            - QDEC_Z_ILLEAGE_INT_MASK: The z-axis illegal interrupt mask.
 * \param[in] NewState: New state of the specified Qdecoder interrupts mask.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable mask the specified Qdecoder axis interrupts.
 *            - DISABLE: Disable mask the specified Qdecoder axis interrupts
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void qdec_demo(void)
 * {
 *
 *     QDEC_INTMask(QDEC, QDEC_X_CT_INT_MASK, ENABLE);
 *
 * }
 * \endcode
 */
void QDEC_INTMask(QDEC_TypeDef *QDECx, uint32_t QDEC_AXIS, FunctionalState NewState);

/**
 * \brief  Enable or disable the selected Qdecoder axis(x/y/z).
 *
 * \param[in] QDECx: Selected Qdecoder peripheral. \ref x3g_QDEC_Declaration.
 * \param[in] QDEC_AXIS: Specifies the Qdecoder axis. \ref x3g_QDEC_Axis.
 *            This parameter can be one of the following values:
 *            - QDEC_AXIS_X: The qdecoder X axis.
 *            - QDEC_AXIS_Y: The qdecoder Y axis.
 *            - QDEC_AXIS_Z: The qdecoder Z axis.
 * \param[in] NewState: New state of the selected Qdecoder axis.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the selected Qdecoder axis(x/y/z).
 *            - DISABLE: Disable the selected Qdecoder axis(x/y/z).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void qdec_demo(void)
 * {
 *     QDEC_Cmd(QDEC, QDEC_AXIS_X, ENABLE);
 * }
 * \endcode
 */
void QDEC_Cmd(QDEC_TypeDef *QDECx, uint32_t QDEC_AXIS, FunctionalState NewState);

/**
 * \brief   Clear Qdecoder interrupt pending bit.
 *
 * \param[in] QDECx: Selected Qdecoder peripheral. \ref x3g_QDEC_Declaration.
 * \param[in] QDEC_FLAG: Specifies the flag to clear. \ref x3g_QDEC_Clr_Flag.
 *            This parameter parameter can be one of the following values:
 *            - QDEC_CLR_OVERFLOW_X: The overflow flag for x-axis accumulation counter.
 *            - QDEC_CLR_OVERFLOW_Y: The overflow flag for y-axis accumulation counter.
 *            - QDEC_CLR_OVERFLOW_Z: The overflow flag for z-axis accumulation counter.
 *            - QDEC_CLR_ILLEGAL_INT_X: The illegal interrupt for X axis.
 *            - QDEC_CLR_ILLEGAL_INT_Y: The illegal interrupt for Y axis.
 *            - QDEC_CLR_ILLEGAL_INT_Z: The illegal interrupt for Z axis.
 *            - QDEC_CLR_UNDERFLOW_X: The underflow flag for x-axis accumulation counter.
 *            - QDEC_CLR_UNDERFLOW_Y: The underflow flag for y-axis accumulation counter.
 *            - QDEC_CLR_UNDERFLOW_Z: The underflow flag for z-axis accumulation counter.
 *            - QDEC_CLR_NEW_CT_X: The counter interrupt for X axis.
 *            - QDEC_CLR_NEW_CT_Y: The counter interrupt for Y axis.
 *            - QDEC_CLR_NEW_CT_Z: The counter interrupt for Z axis.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void qdec_demo(void)
 * {
 *     QDEC_ClearFlags(QDEC, QDEC_CLR_OVERFLOW_X);
 * }
 * \endcode
 */
void QDEC_ClearFlags(QDEC_TypeDef *QDECx, uint32_t QDEC_CLR_INT);

/**
 * \brief  Get Qdecoder Axis(x/y/z) direction.
 *
 * \param[in] QDECx: Selected Qdecoder peripheral. \ref x3g_QDEC_Declaration.
 * \param[in] QDEC_AXIS: Specifies the Qdecoder axis.  \ref x3g_QDEC_Axis.
 *            This parameter parameter can be one of the following values:
 *            - QDEC_AXIS_X: The qdecoder X axis.
 *            - QDEC_AXIS_Y: The qdecoder Y axis.
 *            - QDEC_AXIS_Z: The qdecoder Z axis.
 *
 * \return The direction of the axis.
 * This parameter parameter can be one of the following values:
 * \retval QDEC_AXIS_DIR_UP: The axis is rolling up.
 * \retval QDEC_AXIS_DIR_DOWN: The axis is rolling down.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void qdec_demo(void)
 * {
 *     uint16_t dir = QDEC_GetAxisDirection(QDEC, QDEC_AXIS_X);
 * }
 * \endcode
 */
uint16_t QDEC_GetAxisDirection(QDEC_TypeDef *QDECx, uint32_t QDEC_AXIS);

/**
 * \brief  Get Qdecoder Axis(x/y/z) count.
 *
 * \param[in] QDECx: Selected Qdecoder peripheral. \ref x3g_QDEC_Declaration.
 * \param[in] QDEC_AXIS: Specifies the Qdecoder axis. \ref x3g_QDEC_Axis.
 *            This parameter parameter can be one of the following values:
 *            - QDEC_AXIS_X: The qdecoder X axis.
 *            - QDEC_AXIS_Y: The qdecoder Y axis.
 *            - QDEC_AXIS_Z: The qdecoder Z axis.
 *
 * \return The count of the axis.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void qdec_demo(void)
 * {
 *     uint16_t counter = QDEC_GetAxisCount(QDEC, QDEC_AXIS_X);
 * }
 * \endcode
 */
uint16_t QDEC_GetAxisCount(QDEC_TypeDef *QDECx, uint32_t QDEC_AXIS);

/**
 * \brief  Pause or resume Qdecoder Axis(x/y/z).
 *
 * \param[in] QDECx: Selected Qdecoder peripheral. \ref x3g_QDEC_Declaration.
 * \param[in] QDEC_AXIS: Specifies the Qdecoder axis. \ref x3g_QDEC_Axis.
 *            This parameter parameter can be one of the following values:
 *            - QDEC_AXIS_X: The qdecoder X axis.
 *            - QDEC_AXIS_Y: The qdecoder Y axis.
 *            - QDEC_AXIS_Z: The qdecoder Z axis.
 * \param[in] NewState: New state of the specified Qdecoder Axis.
 *            This parameter parameter can be one of the following values:
 *            - ENABLE: Pause the selected Qdecoder Axis.
 *            - DISABLE: Resume the selected Qdecoder Axis.
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void qdec_demo(void)
 * {
 *     QDEC_CounterPauseCmd(QDEC, QDEC_AXIS_X, ENABLE);
 * }
 * \endcode
 */
void QDEC_CounterPauseCmd(QDEC_TypeDef *QDECx, uint32_t QDEC_AXIS,
                          FunctionalState NewState);

/** \} */ /* End of group 87x3g_QDEC_Exported_Functions */

/** \} */ /* End of group 87x3g_QDEC */

#ifdef __cplusplus
}
#endif

#endif /* RTL_QDEC_H */




