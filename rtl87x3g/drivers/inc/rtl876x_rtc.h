/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL876X_RTC_H
#define RTL876X_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x.h"
#include "rtl876x_rtc_def.h"

/** @addtogroup 87x3g_RTC RTC
  * @brief RTC driver module.
  * @{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup 87x3g_RTC_Exported_Constants RTC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    87x3g_RTC_Comparator_Index RTC Comparator Index
 * \{
 */

typedef enum
{
    RTC_COMP0 = 0x00, //!< RTC comparator index0.
    RTC_COMP1 = 0x01, //!< RTC comparator index1.
    RTC_COMP2 = 0x02, //!< RTC comparator index2.
    RTC_COMP3 = 0x03, //!< RTC comparator index3.
} RTCComIndex_TypeDef;

#define IS_RTC_COMP(COMP) (((COMP) == RTC_COMP0) || \
                           ((COMP) == RTC_COMP1) || \
                           ((COMP) == RTC_COMP2) || \
                           ((COMP) == RTC_COMP3)) //!< Check if RTC comparator index is valid.

/** End of 87x3g_RTC_Comparator_Index
  * \}
  */

#if (RTC_SUPPORT_COMPARE_GUARDTIME == 1)
/**
 * \defgroup    87x3g_RTC_ComparatorGT_Definition RTC Comparator GT Definition
 * \{
 */

typedef enum
{
    RTC_COMP0GT = 0x0, //!< RTC comparator GT index0.
    RTC_COMP1GT = 0x1, //!< RTC comparator GT index1.
    RTC_COMP2GT = 0x2, //!< RTC comparator GT index2.
    RTC_COMP3GT = 0x3, //!< RTC comparator GT index3.
} RTCCmopGTIndex_TypeDef;

#define IS_RTC_COMPGT(COMP) (((COMP) == RTC_COMP0GT) || \
                             ((COMP) == RTC_COMP1GT) || \
                             ((COMP) == RTC_COMP2GT) || \
                             ((COMP) == RTC_COMP3GT)) //!< Check if the input parameter is valid.

/** End of 87x3g_RTC_ComparatorGT_Definition
  * \}
  */
#endif

/**
 * \defgroup    87x3g_RTC_Interrupts RTC Interrupts
 * \{
 */
typedef enum _RTC_INT
{
    RTC_INT_TICK        = BIT(8),   //!< RTC tick interrupt.
    RTC_INT_OVF         = BIT(9),   //!< RTC overflow interrupt.
    RTC_PRECMP_INT      = BIT(10),  //!< RTC PRECOMP interrupt.
    RTC_PRECMP_CMP3_INT = BIT(11),  //!< RTC PRECOMP&CMP3 interrupt.

    RTC_CMP0_NV_INT     = BIT(16),     //!< RTC CMP0 interrupt.
    RTC_INT_CMP0        = BIT(16),     //!< RTC CMP0 interrupt.

    RTC_CMP1_NV_INT     = BIT(17),     //!< RTC CMP1 interrupt.
    RTC_INT_CMP1        = BIT(17),     //!< RTC CMP1 interrupt.

    RTC_CMP2_NV_INT     = BIT(18),     //!< RTC CMP2 interrupt.
    RTC_INT_CMP2        = BIT(18),     //!< RTC CMP2 interrupt.

    RTC_CMP3_NV_INT     = BIT(19),     //!< RTC CMP3 interrupt.
    RTC_INT_CMP3        = BIT(19),     //!< RTC CMP3 interrupt.

    RTC_CMP0_WK_INT     = BIT(20),  //!< RTC CMP0 GT wakeup interrupt.
    RTC_CMP1_WK_INT     = BIT(21),  //!< RTC CMP1 GT wakeup interrupt.
    RTC_CMP2_WK_INT     = BIT(22),  //!< RTC CMP2 GT wakeup interrupt.
    RTC_CMP3_WK_INT     = BIT(23),  //!< RTC CMP3 GT wakeup interrupt.

} RTC_INT_t;

#define IS_RTC_INT(INT) (((INT) == RTC_INT_TICK) || \
                         ((INT) == RTC_INT_OVF) || \
                         ((INT) == RTC_INT_CMP0) || \
                         ((INT) == RTC_INT_CMP1) || \
                         ((INT) == RTC_INT_CMP2) || \
                         ((INT) == RTC_INT_CMP3) || \
                         ((INT) == RTC_PRECMP_INT) || \
                         ((INT) == RTC_PRECMP_CMP3_INT)) //!< Check if the input parameter is valid.


/** End of 87x3g_RTC_Interrupts
  * \}
  */

/**
 * \defgroup    87x3g_RTC_Wakeup RTC Wakeup
 * \{
 */
#if (RTC_SUPPORT_PRE_COMP_OVF_TICK_WAKE_UP == 1)
#define RTC_WK_TICK            BIT8 //!< RTC tick wakeup function.
#define RTC_WK_OVF             BIT9 //!< RTC counter overflow wakeup function.
#define RTC_WK_PRE_COMP        BIT10 //!< RTC prescale comparator wakeup function.
#define RTC_WK_PRE_COMP3       BIT11 //!< RTC prescale & comparator 3 wakeup function.
#endif
#if (RTC_SUPPORT_COMPARE_GUARDTIME == 1)
#define RTC_WK_COMP0GT         BIT12 //!< RTC comparator 0 GT wakeup function.
#define RTC_WK_COMP1GT         BIT13 //!< RTC comparator 1 GT wakeup function.
#define RTC_WK_COMP2GT         BIT14 //!< RTC comparator 2 GT wakeup function.
#define RTC_WK_COMP3GT         BIT15 //!< RTC comparator 3 GT wakeup function.
#endif

#if (RTC_SUPPORT_PRE_COMP_OVF_TICK_WAKE_UP == 1)
#define IS_RTC_WK(WK) (((WK) == RTC_WK_TICK) || \
                       ((WK) == RTC_WK_OVF) || \
                       ((WK) == RTC_WK_PRE_COMP) || \
                       ((WK) == RTC_WK_PRE_COMP3) || \
                       ((WK) == RTC_CMP0_WK_INT) || \
                       ((WK) == RTC_CMP1_WK_INT) || \
                       ((WK) == RTC_CMP2_WK_INT) || \
                       ((WK) == RTC_CMP3_WK_INT)) //!< Check if the input parameter is valid.
#else
#define IS_RTC_WK(WK) (((WK) == RTC_CMP0_WK_INT) || \
                       ((WK) == RTC_CMP1_WK_INT) || \
                       ((WK) == RTC_CMP2_WK_INT) || \
                       ((WK) == RTC_CMP3_WK_INT)) //!< Check if the input parameter is valid.
#endif

/** End of 87x3g_RTC_Wakeup
  * \}
  */

/**
 * \defgroup    87x3g_RTC_Int_Clear RTC Interrupt Clear
 * \{
 */
#define RTC_COMP3_CLR               (RTC_INT_CMP3     >> 8) //!< RTC comparator 3 interrupt clear.
#define RTC_COMP2_CLR               (RTC_INT_CMP2     >> 8) //!< RTC comparator 2 interrupt clear.
#define RTC_COMP1_CLR               (RTC_INT_CMP1     >> 8) //!< RTC comparator 1 interrupt clear.
#define RTC_COMP0_CLR               (RTC_INT_CMP0     >> 8) //!< RTC comparator 0 interrupt clear.
#define RTC_PRE_COMP3_CLR           (RTC_PRECMP_CMP3_INT >> 8) //!< RTC prescale & comparator 3 interrupt clear.
#define RTC_PRE_COMP_CLR            (RTC_PRECMP_INT  >> 8) //!< RTC prescale comparator interrupt clear.
#define RTC_OVERFLOW_CLR            (RTC_INT_OVF       >> 8) //!< RTC counter overflow interrupt clear.
#define RTC_TICK_CLR                (RTC_INT_TICK      >> 8) //!< RTC tick interrupt clear.

#define RTC_ALL_INT_CLR             (RTC_PRE_COMP3_CLR | RTC_PRE_COMP_CLR | \
                                     RTC_COMP3_CLR | RTC_COMP2_CLR | \
                                     RTC_COMP1_CLR | RTC_COMP0_CLR | \
                                     RTC_OVERFLOW_CLR | RTC_TICK_CLR) //!< Check if the input parameter is valid.

/** End of 87x3g_RTC_Int_Clear
  * \}
  */

/**
 * \defgroup    87x3g_RTC_WK_Clear RTC Wakeup Clear
 * \{
 */
#define RTC_COMP3_WK_CLR            (RTC_CMP3_WK_INT   >> 8) //!< RTC comparator 3 wakeup clear.
#define RTC_COMP2_WK_CLR            (RTC_CMP2_WK_INT   >> 8) //!< RTC comparator 2 wakeup clear.
#define RTC_COMP1_WK_CLR            (RTC_CMP1_WK_INT   >> 8) //!< RTC comparator 1 wakeup clear.
#define RTC_COMP0_WK_CLR            (RTC_CMP0_WK_INT   >> 8) //!< RTC comparator 0 wakeup clear.
#if (RTC_SUPPORT_COMPARE_GUARDTIME == 1)
#define RTC_COMP3GT_CLR             (RTC_WK_COMP3GT >> 8) //!< RTC comparator 3 GT wakeup clear.
#define RTC_COMP2GT_CLR             (RTC_WK_COMP2GT >> 8) //!< RTC comparator 2 GT wakeup clear.
#define RTC_COMP1GT_CLR             (RTC_WK_COMP1GT >> 8) //!< RTC comparator 1 GT wakeup clear.
#define RTC_COMP0GT_CLR             (RTC_WK_COMP0GT >> 8) //!< RTC comparator 0 GT wakeup clear.
#endif

#define RTC_ALL_WAKEUP_CLR          (RTC_COMP3_WK_CLR | RTC_COMP2_WK_CLR | \
                                     RTC_COMP1_WK_CLR | RTC_COMP0_WK_CLR) //!< Check if the input parameter is valid.

/** End of 87x3g_RTC_WK_Clear
  * \}
  */

/** End of 87x3g_RTC_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup 87x3g_RTC_Exported_Functions RTC Exported Functions
  * \brief
  * \{
  */

/**
 * \brief     Deinitializes the RTC peripheral registers to their default reset values(turn off clock).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 * }
 * \endcode
 */
void RTC_DeInit(void);

/**
 * \brief     Set RTC prescaler value.
 *
 * \param[in] value: The prescaler value to be set. Should be no more than 12 bits!
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_CMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetComp(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *
 *     RTC_CpuNVICEnable(ENABLE);
 *     RTC_RunCmd(ENABLE);
 * }
 * \endcode
 */
void RTC_SetPrescaler(uint16_t value);

/**
 * \brief     Start or stop RTC peripheral.
 *
 * \param[in] NewState: New state of RTC peripheral.
 *            This parameter can be one of the following values:
 *            - ENABLE: Start RTC.
 *            - DISABLE: Stop RTC.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_CMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetComp(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *
 *     RTC_CpuNVICEnable(ENABLE);
 *     RTC_RunCmd(ENABLE);
 * }
 * \endcode
 */
void RTC_RunCmd(FunctionalState NewState);

/**
 * \brief     Enable or disable the specified RTC interrupt.
 *
 * \param[in] RTC_INT: Specifies the RTC interrupt which to be enabled or disabled, please refer to \ref x3g_RTC_Interrupts.
 *            This parameter can be any combination of the following values:
 *            - RTC_INT_TICK: RTC tick interrupt.
 *            - RTC_INT_OVF: RTC counter overflow interrupt.
 *            - RTC_INT_CMP0: RTC comparator 0 interrupt.
 *            - RTC_INT_CMP1: RTC comparator 1 interrupt.
 *            - RTC_INT_CMP2: RTC comparator 2 interrupt.
 *            - RTC_INT_CMP3: RTC comparator 3 interrupt.
 *            - RTC_PRECMP_INT: RTC prescale comparator interrupt.
 *            - RTC_PRECMP_CMP3_INT: RTC prescale & comparator 3 interrupt.
 *
 * \param[in] NewState: New state of the specified RTC interrupt.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified interrupt of RTC.
 *            - DISABLE: Disable the specified interrupt of RTC.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_CMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetComp(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *
 *     RTC_CpuNVICEnable(ENABLE);
 *     RTC_RunCmd(ENABLE);
 * }
 * \endcode
 */
void RTC_INTConfig(uint32_t RTC_INT, FunctionalState NewState);

/**
 * \brief  Enable or disable the specified RTC wakeup function.
 *
 * \param[in] RTC_WK: Specifies the RTC wakeup function to be enabled or disabled, please refer to \ref x3g_RTC_Wakeup.
 *            This parameter can be any combination of the following values:
 *            - RTC_WK_TICK: RTC tick wakeup function.
 *            - RTC_WK_OVF: RTC counter overflow wakeup function.
 *            - RTC_WK_PRE_CMP: RTC prescale comparator wakeup function.
 *            - RTC_WK_PRE_CMP3: RTC prescale & comparator 3 wakeup function.
 *            - RTC_WK_COMPxGT: RTC comparator x GT wakeup function, x = 0~3.
 *            - RTC_WK_CMPx: RTC comparator x wakeup function, x = 0~3.
 * \param[in] NewState: New state of the specified RTC wakeup function.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified RTC wakeup function.
 *            - DISABLE: Disable the specified RTC wakeup function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_WK      RTC_CMP2_WK_INT
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetComp(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_WKConfig(RTC_COMP_INDEX_WK, ENABLE);
 *
 *     RTC_SystemWakeupConfig(ENABLE);
 *     RTC_RunCmd(ENABLE);
 * }
 * \endcode
 */
void RTC_WKConfig(uint32_t RTC_WK, FunctionalState NewState);

/**
 * \brief     Enable or disable RTC interrupt signal to CPU NVIC.
 *
 * \param[in] NewState: Enable or disable RTC interrupt signal to CPU NVIC.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the RTC interrupt signal to CPU NVIC.
 *            - DISABLE: Disable the RTC interrupt signal to CPU NVIC.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_CMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetComp(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *
 *     RTC_CpuNVICEnable(ENABLE);
 *     RTC_RunCmd(ENABLE);
 * }
 * \endcode
 */
void RTC_CpuNVICEnable(FunctionalState NewState);

/**
 * \brief     Enable or disable system wake up function of RTC.
 *
 * \param[in] NewState: New state of the RTC wake up function.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable system wake up function of RTC.
 *            - DISABLE: Disable system wake up function of RTC.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_SystemWakeupConfig(ENABLE);
 * }
 * \endcode
 */
void RTC_SystemWakeupConfig(FunctionalState NewState);

/**
 * \brief     Reset counter value of RTC.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ResetCounter();
 *     RTC_RunCmd(ENABLE);
 * }
 * \endcode
 */
void RTC_ResetCounter(void);

/**
 * \brief     Reset prescaler counter value of RTC.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ResetPrescalerCounter();
 *     RTC_RunCmd(ENABLE);
 * }
 * \endcode
 */
void RTC_ResetPrescalerCounter(void);

/**
 * \brief  Check whether the specified RTC interrupt is set.
 *
 * \param[in] RTC_INT: Specifies the RTC interrupt, please refer to \ref x3g_RTC_Interrupts.
 *            This parameter can be any combination of the following values:
 *            - RTC_INT_TICK: RTC tick interrupt.
 *            - RTC_INT_OVF: RTC counter overflow interrupt.
 *            - RTC_INT_CMP0: RTC comparator 0 interrupt.
 *            - RTC_INT_CMP1: RTC comparator 1 interrupt.
 *            - RTC_INT_CMP2: RTC comparator 2 interrupt.
 *            - RTC_INT_CMP3: RTC comparator 3 interrupt.
 *            - RTC_PRECMP_INT: RTC prescale comparator interrupt.
 *            - RTC_PRECMP_CMP3_INT: RTC prescale & comparator 3 interrupt.
 *
 * \return The status of RTC interrupt.
 * \retval SET: The specified RTC interrupt has occurred.
 * \retval RESET: The specified RTC interrupt has not occurred.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     ITStatus int_status = RTC_GetINTStatus(RTC_INT_CMP0);
 * }
 * \endcode
 */
ITStatus RTC_GetINTStatus(uint32_t RTC_INT);

/**
 * \brief     Clear the interrupt pending bits of RTC.
 *
 * \param[in] RTC_INT: Specifies the RTC interrupt, please refer to \ref x3g_RTC_Interrupts.
 *            This parameter can be any combination of the following values:
 *            - RTC_INT_TICK: RTC tick interrupt.
 *            - RTC_INT_OVF: RTC counter overflow interrupt.
 *            - RTC_INT_CMP0: RTC comparator 0 interrupt.
 *            - RTC_INT_CMP1: RTC comparator 1 interrupt.
 *            - RTC_INT_CMP2: RTC comparator 2 interrupt.
 *            - RTC_INT_CMP3: RTC comparator 3 interrupt.
 *            - RTC_PRECMP_INT: RTC prescale comparator interrupt.
 *            - RTC_PRECMP_CMP3_INT: RTC prescale & comparator 3 interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClearINTPendingBit(RTC_INT_CMP0);
 * }
 * \endcode
 */
void RTC_ClearINTPendingBit(uint32_t RTC_INT);

/**
 * \brief  Checks whether the specified RTC wakeup state is set or not.
 *
 * \param[in] RTC_WK: Specifies the RTC wakeup function, please refer to \ref x3g_RTC_Wakeup.
 *            This parameter can be any combination of the following values:
 *            - RTC_WK_TICK: RTC tick wakeup function.
 *            - RTC_WK_OVF: RTC counter overflow wakeup function.
 *            - RTC_WK_PRE_CMP: RTC prescale comparator wakeup function.
 *            - RTC_WK_PRE_CMP3: RTC prescale & comparator 3 wakeup function.
 *            - RTC_WK_COMPxGT: RTC comparator x GT wakeup function, x = 0~3.
 *            - RTC_WK_CMPx: RTC comparator x wakeup function, x = 0~3.
 *
 * \return The RTC wakeup state is set or not.
 * \retval SET: The specified RTC wakeup is set.
 * \retval RESET: The specified RTC wakeup is not set.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     ITStatus status = RTC_GetWakeupStatus(RTC_WK_CMP0);
 * }
 * \endcode
 */
ITStatus RTC_GetWakeupStatus(uint32_t RTC_WK);

/**
 * \brief  Clear the wakeup status bits of RTC.
 *
 * \param[in] RTC_WK: Specifies the RTC wakeup function, please refer to \ref x3g_RTC_Wakeup.
 *            This parameter can be any combination of the following values:
 *            - RTC_WK_TICK: RTC tick wakeup function.
 *            - RTC_WK_OVF: RTC counter overflow wakeup function.
 *            - RTC_WK_PRE_CMP: RTC prescale comparator wakeup function.
 *            - RTC_WK_PRE_CMP3: RTC prescale & comparator 3 wakeup function.
 *            - RTC_WK_COMPxGT: RTC comparator x GT wakeup function, x = 0~3.
 *            - RTC_WK_CMPx: RTC comparator x wakeup function, x = 0~3.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClearWakeupStatusBit(RTC_WK_CMP0);
 * }
 * \endcode
 */
void RTC_ClearWakeupStatusBit(uint32_t RTC_WK);

/**
 *
 * \brief     Clear wakeup interrupt of the select comparator of RTC.
 *
 * \param[in] index: The comparator number to be set, please refer to \ref x3g_RTC_Comparator_Index.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void RTC_Handler(void)
 * {
 *     if (RTC_GetINTStatus(RTC_INT_CMP0) == SET)
 *    {
 *         //add user here.
 *         RTC_ClearCompINT(RTC_COMP0);
 *         RTC_ClearCompWkINT(RTC_COMP0);
 *    }
 * }
 * \endcode
 */
void RTC_ClearCompWkINT(RTCComIndex_TypeDef index);

/**
 *
 * \brief     Clear the interrupt pending bit of the select comparator of RTC.
 *
 * \param[in] index: The comparator number to be set, please refer to \ref x3g_RTC_Comparator_Index.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void RTC_Handler(void)
 * {
 *     if (RTC_GetINTStatus(RTC_INT_CMP0) == SET)
 *     {
 *         RTC_ClearCompINT(RTC_COMP0);
 *     }
 * }
 * \endcode
 */
void RTC_ClearCompINT(RTCComIndex_TypeDef index);

/**
 *
 * \brief     Clear the overflow interrupt pending bit of RTC.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void RTC_Handler(void)
 * {
 *     //RTC overflow interrupt handle
 *     if (RTC_GetINTStatus(RTC_INT_OVF) == SET)
 *    {
 *         // Add application code here
 *         RTC_ClearOverFlowINT();
 *    }
 * }
 * \endcode
 */
void RTC_ClearOverFlowINT(void);

/**
 *
 * \brief     Clear the tick interrupt pending bit of RTC.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void RTC_Handler(void)
 * {
 *     //RTC tick interrupt handle
 *     if (RTC_GetINTStatus(RTC_INT_TICK) == SET)
 *    {
 *         // Add application code here
 *         RTC_ClearTickINT();
 *    }
 * }
 * \endcode
 */
void RTC_ClearTickINT(void);

/**
 * \brief     Set RTC comparator value.
 *
 * \param[in] index: The comparator number to be set, please refer to \ref x3g_RTC_Comparator_Index.
 * \param[in] value: The comparator value to be set. This parameter must range from 0x0 to 0xFFFFFFFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetComp(RTC_COMP_INDEX, RTC_COMP_VALUE);
 * }
 * \endcode
 */
void RTC_SetComp(RTCComIndex_TypeDef index, uint32_t value);

#if (RTC_SUPPORT_COMPARE_GUARDTIME == 1)
/**
 * \brief     Set RTC comparator GT value.
 *
 * \param[in] index: The comparator GT number to be set, please refer to \ref x3g_RTC_ComparatorGT_Definition.
 * \param[in] value: The comparator value to be set. This parameter must range from 0x0 to 0xFFFFFFFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_SetCompGTValue(RTC_COMP0GT, 1000);
 * }
 * \endcode
 */
void RTC_SetCompGTValue(RTCCmopGTIndex_TypeDef index, uint32_t value);
#endif

/**
 * \brief     Set RTC prescaler comparator value.
 *
 * \param[in] value: The prescaler comparator value to be set. Should be no more than 12 bits!
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     (3200 - 1)//max 4095
 * #define RTC_PRECOMP_VALUE       (320)//max 4095
 * #define RTC_COMP3_VALUE         (10)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetPreCompValue(RTC_PRECOMP_VALUE);
 *     RTC_SetComp(RTC_COMP3, RTC_COMP3_VALUE);
 *
 *     RTC_MaskINTConfig(RTC_PRECMP_CMP3_INT, DISABLE);
 *     RTC_INTConfig(RTC_PRECMP_CMP3_INT, ENABLE);
 *
 *     RTC_CpuNVICEnable(ENABLE);
 *     RTC_RunCmd(ENABLE);
 * }
 * \endcode
 */
void RTC_SetPreCompValue(uint32_t value);

/**
 * \brief     Get counter value of RTC.
 *
 * \return    The counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uitn32_t counter = RTC_GetCounter();
 * }
 * \endcode
 */
uint32_t RTC_GetCounter(void);

/**
 * \brief     Get prescaler counter value of RTC.
 *
 * \return    The prescaler counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uitn32_t pre_counter = RTC_GetPreCounter();
 * }
 * \endcode
 */
uint32_t RTC_GetPreCounter(void);

/**
 * \brief     Get RTC comparator value.
 *
 * \param[in] index: The comparator number to be set, please refer to \ref x3g_RTC_Comparator_Index.
 *
 * \return    The comparator value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uint32_t data = RTC_GetCompValue(RTC_COMP0);
 * }
 * \endcode
 */
uint32_t RTC_GetCompValue(RTCComIndex_TypeDef index);

#if (RTC_SUPPORT_COMPARE_GUARDTIME == 1)
/**
 * \brief     Get RTC comparator GT value.
 *
 * \param[in] index: The comparator GT number to be set, please refer to \ref x3g_RTC_ComparatorGT_Definition.
 *
 * \return    The comparator GT value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uitn32_t data = RTC_GetCompGTValue(RTC_COMP0GT);
 * }
 * \endcode
 */
uint32_t RTC_GetCompGTValue(RTCCmopGTIndex_TypeDef index);
#endif

/**
 * \brief     Get RTC prescaler comparator value.
 *
 * \return    The prescaler comparator value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uitn32_t data = RTC_GetPreCompValue();
 * }
 * \endcode
 */
uint32_t RTC_GetPreCompValue(void);

/**
 * \brief     Write backup register for store time information.
 *
 * \param[in] value: The value which is written to back up register. This parameter must range from 0x0 to 0xFFFFFFFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_WriteBackupReg(0x01020304);
 * }
 * \endcode
 */
void RTC_WriteBackupReg(uint32_t value);

/**
 * \brief     Read the RTC backup register.
 *
 * \return    The RTC backup register value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uint32_t reg_data = RTC_ReadBackupReg();
 * }
 * \endcode
 */
uint32_t RTC_ReadBackupReg(void);


/**
 * \brief     Mask or unmask the selected RTC interrupts.
 * \param[in] RTC_INT: Specifies the RTC interrupt, please refer to \ref x3g_RTC_Interrupts.
 *            This parameter can be any combination of the following values:
 *            - RTC_INT_TICK: RTC tick interrupt.
 *            - RTC_INT_OVF: RTC counter overflow interrupt.
 *            - RTC_INT_CMP0: RTC comparator 0 interrupt.
 *            - RTC_INT_CMP1: RTC comparator 1 interrupt.
 *            - RTC_INT_CMP2: RTC comparator 2 interrupt.
 *            - RTC_INT_CMP3: RTC comparator 3 interrupt.
 *            - RTC_PRECMP_INT: RTC prescale comparator interrupt.
 *            - RTC_PRECMP_CMP3_INT: RTC prescale & comparator 3 interrupt.
 *
 * \param[in] NewState: New state of the specified RTC interrupt.
 *            This parameter can be one of the following values:
 *            - ENABLE: Mask the selected RTC interrupt.
 *            - DISABLE: Unmask the selected RTC interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_MaskINTConfig(RTC_INT_CMP0, DISABLE);
 *     RTC_CompINTConfig(RTC_INT_CMP0, ENABLE);
 * }
 * \endcode
 */
void RTC_MaskINTConfig(uint32_t RTC_INT, FunctionalState NewState);
#define RTC_EN_INTConfig     RTC_MaskINTConfig //!< Please refer to \ref RTC_MaskINTConfig.

/**
 * \brief     Enable or disable the specified RTC interrupts for comparator.
 * \param[in] RTC_INT: Specifies the RTC interrupt, please refer to \ref x3g_RTC_Interrupts.
 *            This parameter can be any combination of the following values:
 *            - RTC_INT_TICK: RTC tick interrupt.
 *            - RTC_INT_OVF: RTC counter overflow interrupt.
 *            - RTC_INT_CMP0: RTC comparator 0 interrupt.
 *            - RTC_INT_CMP1: RTC comparator 1 interrupt.
 *            - RTC_INT_CMP2: RTC comparator 2 interrupt.
 *            - RTC_INT_CMP3: RTC comparator 3 interrupt.
 *            - RTC_PRECMP_INT: RTC prescale comparator interrupt.
 *            - RTC_PRECMP_CMP3_INT: RTC prescale & comparator 3 interrupt.
 *
 * \param[in] NewState: New state of the specified RTC interrupt.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the selected RTC comparator interrupt.
 *            - DISABLE: Disable the selected RTC comparator interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_MaskINTConfig(RTC_INT_CMP0, DISABLE);
 *     RTC_CompINTConfig(RTC_INT_CMP0, ENABLE);
 * }
 * \endcode
 */
void RTC_CompINTConfig(uint32_t RTC_INT, FunctionalState NewState);

/**
 *
 * \brief     Enable or disable RTC tick interrupt.
 *
 * \param[in] NewState: New state of RTC tick interrupt.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable RTC tick interrupt.
 *            - DISABLE: Disable RTC tick interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_PRESCALER_VALUE     0
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_MaskINTConfig(RTC_INT_TICK, DISABLE);
 *     RTC_TickINTConfig(ENABLE);
 * }
 * \endcode
 */
void RTC_TickINTConfig(FunctionalState NewState);

#if (RTC_SUPPORT_COMPARE_AUTO_RELOAD == 1)
/**
 * \brief     Set RTC comparator auto reload value.
 *
 * \param[in] index: The comparator number to be set, please refer to \ref x3g_RTC_Comparator_Index.
 * \param[in] value: The comparator auto reload value to be set. This parameter must range from 0x0 to 0xFFFFFFFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define RTC_COMP_INDEX          RTC_COMP3
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_SetCompReloadValue(RTC_COMP_INDEX, 1000);
 * }
 * \endcode
 */
void RTC_SetCompReloadValue(RTCComIndex_TypeDef index, uint32_t value);

/**
 * \brief     Get RTC comparator auto reload value.
 *
 * \param[in] index: The comparator number to be set, please refer to \ref x3g_RTC_Comparator_Index.
 *
 * \return    The comparator auto reload value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uint32_t data = RTC_GetCompReloadValue(RTC_COMP0);
 * }
 * \endcode
 */
uint32_t RTC_GetCompReloadValue(RTCComIndex_TypeDef index);

/**
 * \brief     Enable RTC comparator auto reload function. When the counter value reaches the value of comparator, it automatically adds the cmp value, which equals current compare + reload value.

 * \param[in] index: The comparator number to be set, please refer to \ref x3g_RTC_Comparator_Index.
 * \param[in] comp_value: The initialize value of comparator. This parameter must range from 0x0 to 0xFFFFFFFF.
 * \param[in] reload_value: The comparator auto reload value. This parameter must range from 0x0 to 0xFFFFFFFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_EnableCompAutoReload(RTC_COMP0, 1000, 1000);
 * }
 * \endcode
 */
void RTC_EnableCompAutoReload(RTCComIndex_TypeDef index, uint32_t comp_value,
                              uint32_t reload_value);

/**
 * \brief     Disable RTC comparator auto reload function.
 *
 * \param[in] index: The comparator number to be set, please refer to \ref x3g_RTC_Comparator_Index.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DisableCompAutoReload(RTC_COMP0);
 * }
 * \endcode
 */
void RTC_DisableCompAutoReload(RTCComIndex_TypeDef index);
#endif

#if (RTC_SUPPORT_CLOCK_OUT_TO_OUTSIDE_PAD == 1)
/**
 * \brief  Enable or disable the clock output to the pad for RTC.
 *
 * \param[in]  ClockOut: Select RTC clock output pad and type, please refer to \ref x3g_RTC_CLOCK_OUT.
 *
 * \param[in] NewState: New state of RTC clock output.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable RTC clock output.
 *            - DISABLE: Disable RTC clock output.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClockOutCmd(RTC_CLOCK_OUT_P2_3, ENABLE);
 * }
 * \endcode
 */
void RTC_ClockOutCmd(RTCClockOut_TypeDef ClockOut, FunctionalState NewState);
#endif

#if (RTC_SUPPORT_CLOCK_IN_FROM_OUTSIDE_PAD == 1)
/**
 * \brief  Enable or disable using external clock for RTC.
 *
 * \param[in] ClockIn: Select which externel pad as RTC clock in, please refer to \ref x3g_RTC_CLOCK_IN.
 *
 * \param[in] NewState: Newstate of RTC clock in.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable RTC clock in.
 *            - DISABLE: Disable RTC clock in.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClockInCmd(RTC_CLOCK_IN_P2_3, ENABLE);
 * }
 * \endcode
 */
void RTC_ClockInCmd(RTCClockIn_TypeDef ClockIn, FunctionalState NewState);
#endif

/** End of 87x3g_RTC_Exported_Functions
  * \}
  */

/** End of 87x3g_RTC
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL876X_RTC_H */



