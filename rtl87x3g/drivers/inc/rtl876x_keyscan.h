/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL876X_KEYSCAN_H
#define RTL876X_KEYSCAN_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_keyscan_def.h"

/** @addtogroup 87x3g_KeyScan KeyScan
  * @brief KeyScan driver module.
  * @{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/


/** @defgroup 87x3g_KeyScan_Exported_Constants KeyScan Exported Constants
  * @{
  */

/** @defgroup 87x3g_Keyscan_Fifo_Depth KeyScan FIFO Depth
  * @{
  */
#define KEYSCAN_FIFO_DEPTH              108   //!< The KeyScan FIFO depth is 108.

/** End of group 87x3g_Keyscan_Fifo_Depth
  * @}
  */

/** @defgroup 87x3g_Keyscan_Row_Number KeyScan Row Number
  * @{
  */
#define IS_KEYSCAN_ROW_NUM(ROW) ((ROW) <= 12)       //!< The row number of the KeyScan need less than or equal to 12.

/** End of group 87x3g_Keyscan_Row_Number
  * @}
  */

/** @defgroup 87x3g_Keyscan_Column_Number KeyScan Column Number
  * @{
  */
#define IS_KEYSCAN_COL_NUM(COL) ((COL) <= 20)     //!< The column number of the KeyScan need less than or equal to 20.

/** End of group 87x3g_Keyscan_Column_Number
  * @}
  */

/** @defgroup 87x3g_Keyscan_Debounce_Config KeyScan Debounce Config
  * @{
  */
#define IS_KEYSCAN_DEBOUNCE_EN(EN) (((EN) == ENABLE) || ((EN) == DISABLE))    //!< Check whether is the status of KeyScan debounce function.

/** End of group 87x3g_Keyscan_Debounce_Config
  * @}
  */

/** @defgroup 87x3g_Keyscan_scan_interval_en KeyScan Scan Interval Timer Enable
  * @{
  */
#define IS_KEYSCAN_SCANINTERVAL_EN(EN) (((EN) == ENABLE) || ((EN) == DISABLE))  //!< Check whether is the status of KeyScan scan interval timer.

/** End of group 87x3g_Keyscan_scan_interval_en
  * @}
  */

/** @defgroup 87x3g_Keyscan_release_detect_timer_en KeyScan Release Detect Timer Enable
  * @{
  */
#define IS_KEYSCAN_RELEASE_DETECT_EN(EN) (((EN) == ENABLE) || ((EN) == DISABLE))  //!< Check whether is the status of KeyScan release detect timer.

/** End of group 87x3g_Keyscan_release_detect_timer_en
  * @}
  */

/** @defgroup 87x3g_Keyscan_scan_mode KeyScan Scan Mode
  * @{
  */
typedef enum
{
    KeyScan_Manual_Scan_Mode = 0x00,    //!< The KeyScan manual scan mode.
    KeyScan_Auto_Scan_Mode = 0x01,      //!< The KeyScan auto scan mode.
} KEYSCANScanMode_TypeDef;

#define IS_KEYSCAN_SCAN_MODE(MODE)  (((MODE) == KeyScan_Manual_Scan_Mode) || ((MODE) == KeyScan_Auto_Scan_Mode))    //!< Check whether is the KeyScan scan mode.

/** End of group 87x3g_Keyscan_scan_mode
  * @}
  */

/** @defgroup 87x3g_Keyscan_Press_Detect_Mode KeyScan Press Detect Mode
  * @{
  */
typedef enum
{
    KeyScan_Detect_Mode_Edge = 0x00,      //!< The key detection mode is edge-triggered.
    KeyScan_Detect_Mode_Level = 0x01,     //!< The key detection mode is level-triggered.
} KEYSCANPressDetectMode_TypeDef;

#define IS_KEYSCAN_DETECT_MODE(MODE)    (((MODE) == KeyScan_Detect_Mode_Edge) || ((MODE) == KeyScan_Detect_Mode_Level))   //!< Check whether is the KeyScan detection mode.

/** End of group 87x3g_Keyscan_Press_Detect_Mode
  * @}
  */

/** @defgroup 87x3g_Keyscan_Fifo_Overflow_Control KeyScan FIFO Overflow Control
  * @{
  */
typedef enum
{
    KeyScan_FIFO_OVR_CTRL_DIS_ALL = 0x00,     //!< Discard the new scan data when FIFO is full.
    KeyScan_FIFO_OVR_CTRL_DIS_LAST = 0x01,    //!< Discard the oldest scan data when FIFO is full.
} KEYSCANFifoOverflowControl_TypeDef;

#define IS_KEYSCAN_FIFO_OVR_CTRL(CTRL)  (((CTRL) == KeyScan_FIFO_OVR_CTRL_DIS_ALL) || ((CTRL) == KeyScan_FIFO_OVR_CTRL_DIS_LAST))   //!< Check whether is the KeyScan FIFO overflow control.

/** End of group 87x3g_Keyscan_Fifo_Overflow_Control
  * @}
  */

/** @defgroup 87x3g_Keyscan_Manual_Scan_Trigger_Mode KeyScan Manual Scan Trigger Mode
  * @{
  */
typedef enum
{
    KeyScan_Manual_Sel_Bit = 0x00,     //!< Manual scan will be triggered by calling the API KeyScan_Cmd.
    KeyScan_Manual_Sel_Key = 0x01,     //!< Manual scan will be triggered by key.
} KEYSCANManualMode_TypeDef;
/** End of group 87x3g_Keyscan_Manual_Scan_Trigger_Mode
  * @}
  */

/** @defgroup 87x3g_Keyscan_Key_Limit KeyScan Key Limit
  * @{
  */
#define IS_KEYSCAN_KEY_LIMIT(DATA_NUM) ((DATA_NUM) <= KEYSCAN_FIFO_DEPTH)    //Specify the maximum allowable scan data for each scan, 0 means no limit.

/** End of group 87x3g_Keyscan_Key_Limit
  * @}
  */

/** @defgroup 87x3g_Keyscan_Interrupt_Definition KeyScan Interrupt Definition
  * @{
  */

#define KEYSCAN_INT_THRESHOLD                    BIT4   //!< KeyScan FIFO threshold interrupt. When data in the FIFO reaches the threshold level, the interrupt is triggered.
#define KEYSCAN_INT_OVER_READ                    BIT3   //!< KeyScan FIFO over read interrupt. When there is no data in the FIFO, reading the FIFO will trigger this interrupt to prevent over-reading.
#define KEYSCAN_INT_SCAN_END                     BIT2   //!< KeyScan finish interrupt. Whether the key value is scanned or not, the interrupt will be triggered as long as the scanning action is completed.
#define KEYSCAN_INT_FIFO_NOT_EMPTY               BIT1   //!< KeyScan FIFO not empty interrupt. If there is data in the FIFO, the interrupt will be triggered.
#define KEYSCAN_INT_ALL_RELEASE                  BIT0   //!< KeyScan all release interrupt. When the release time count reaches the set value, if no key is pressed, the interrupt is triggered.
#define IS_KEYSCAN_CONFIG_IT(IT) ((((IT) & (uint32_t)0xFFF8) == 0x00) && ((IT) != 0x00))    //!< Check whether is the KeyScan interrupt.

/** End of group 87x3g_Keyscan_Interrupt_Definition
  * @}
  */

/**
  * @defgroup  87x3g_Keyscan_Flags KeyScan Flags
  * @{
  */
#define KEYSCAN_FLAG_FIFOLIMIT                       BIT20    //!< When data filtering occurs, this bit will be set to 1.
#define KEYSCAN_INT_FLAG_THRESHOLD                   BIT19    //!< FIFO threshold interrupt status.
#define KEYSCAN_INT_FLAG_OVER_READ                   BIT18    //!< FIFO over read interrupt status.
#define KEYSCAN_INT_FLAG_SCAN_END                    BIT17    //!< Scan finish interrupt status.
#define KEYSCAN_INT_FLAG_FIFO_NOT_EMPTY              BIT16    //!< FIFO not empty interrupt status.
#define KEYSCAN_INT_FLAG_ALL_RELEASE                 BIT15    //!< All release interrupt status.
#define KEYSCAN_FLAG_DATAFILTER                      BIT3     //!< FIFO data filter status.
#define KEYSCAN_FLAG_OVR                             BIT2     //!< FIFO overflow status.
#define KEYSCAN_FLAG_FULL                            BIT1     //!< FIFO full status.
#define KEYSCAN_FLAG_EMPTY                           BIT0     //!< FIFO empty status.
#define IS_KEYSCAN_FLAG(FLAG)       ((((FLAG) & (uint32_t)0x01FF) == 0x00) && ((FLAG) != (uint32_t)0x00))   //!< Check whether is the KeyScan flag.
#define IS_KEYSCAN_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0x00C0) == 0x00) && ((FLAG) != (uint32_t)0x00))   //!< Check whether is the definition of KeyScan flag clear.

/** End of group 87x3g_Keyscan_Flags
  * @}
  */

/** End of group 87x3g_KeyScan_Exported_Constants
  * @}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/

/** @defgroup 87x3g_KeyScan_Exported_Types KeyScan Exported Types
  * @{
  */

/**
 * @brief KeyScan initialize parameters.
 */
typedef struct
{
    uint16_t rowSize;                               /*!< Specifies KeyScan row size.
                                                        This parameter can be set to a value of 12 or less. */

    uint16_t colSize;                               /*!< Specifies KeyScan column size.
                                                         This parameter can be set to a value of 20 or less. */

    uint16_t clockdiv;                              /*!< Specifies KeyScan clock divider.
                                                         Scan clock = system clock/(clockdiv+1). */

    uint8_t delayclk;                               /*!< Specifies KeyScan delay clock divider.
                                                         Delay clock = scan clock/(delayclk+1). */

    FunctionalState debounceEn;                     /*!< Enable or disable debounce function.
                                                         This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState scantimerEn;                    /*!< Enable or disable scan interval timer.
                                                         This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState detecttimerEn;                  /*!< Enable or disable release detect timer.
                                                         This parameter can be a value of ENABLE or DISABLE. */

    uint16_t debouncecnt;                            /*!< Specifies KeyScan debounce count.
                                                          Debounce time = delay clock * debouncecnt.
                                                          This parameter can be a value of 0 ~ 0x1FF. */

    uint16_t scanInterval;                          /*!< Specifies KeyScan scan interval.
                                                         Scan interval time = delay clock * scanInterval.
                                                         This parameter can be a value of 0 ~ 0x1FF. */

    uint16_t releasecnt;                             /*!< Specifies KeyScan release count.
                                                          Release time = delay clock * releasecnt.
                                                          This parameter can be a value of 0 ~ 0x1FF. */

    KEYSCANScanMode_TypeDef scanmode;               /*!< Specifies KeyScan scan mode.
                                                         This parameter can be a value of @ref x3g_Keyscan_scan_mode. */

    KEYSCANPressDetectMode_TypeDef detectMode;      /*!< Specify key detection mode of KeyScan.
                                                         This parameter can be a value of @ref x3g_Keyscan_Press_Detect_Mode. */

    uint16_t fifotriggerlevel;                      /*!< Specifies KeyScan FIFO threshold to trigger interrupt @ref KEYSCAN_INT_THRESHOLD.
                                                         This parameter can be a value of 0 ~ 108. */

    KEYSCANFifoOverflowControl_TypeDef
    fifoOvrCtrl;                                    /*!< Specifies KeyScan FIFO over flow control.
                                                         This parameter can be a value of @ref x3g_Keyscan_Fifo_Overflow_Control. */

    uint8_t keylimit;                               /*!< Specify the maximum allowable scan data for each scan.
                                                         This parameter can be a value of 0 ~ 108. */

    KEYSCANManualMode_TypeDef
    manual_sel;                                     /*!< Specifies trigger mode in manual mode.
                                                         This parameter can be a value of @ref x3g_Keyscan_Manual_Scan_Trigger_Mode. */

#if KEYSCAN_SUPPORT_ROW_LEVEL_CONFIGURE
    FunctionalState rowpullhighEn;                  /*!< Configure KeyScan row pull.
                                                         This parameter can be a value of DISABLE or ENABLE. */
#endif
#if KEYSCAN_SUPPORT_COLUNM_LEVEL_CONFIGURE
    FunctionalState colunmoutputhighEn;             /*!< Configure KeyScan column output.
                                                         This parameter can be a value of DISABLE or ENABLE. */
#endif
} KEYSCAN_InitTypeDef;

/** End of group 87x3g_KeyScan_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/


/** @defgroup 87x3g_KeyScan_Exported_Functions KeyScan Exported Functions
 * @{
 */

/**
 *
 * \brief  Disable the KeyScan peripheral clock, and restore registers to their default values.
 *
 * \param[in]  KeyScan: Selected KeyScan peripheral, which can be KEYSCAN.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_keyscan_init(void)
 * {
 *     KeyScan_DeInit(KEYSCAN);
 * }
 * \endcode
 */
void KeyScan_DeInit(KEYSCAN_TypeDef *KeyScan);

/**
 *
 * \brief   Initializes the KeyScan peripheral according to the specified
 *          parameters in the KeyScan_InitStruct.
 *
 * \param[in]  KeyScan: Selected KeyScan peripheral, which can be KEYSCAN.
 * \param[in]  KeyScan_InitStruct: Pointer to a KEYSCAN_InitTypeDef structure that
 *             contains the configuration information for the specified KeyScan peripheral.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_keyscan_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);
 *
 *     KEYSCAN_InitTypeDef KEYSCAN_InitStruct;
 *     KeyScan_StructInit(&KEYSCAN_InitStruct);
 *
 *     KEYSCAN_InitStruct.rowSize  = KEYBOARD_ROW_SIZE;
 *     KEYSCAN_InitStruct.colSize  = KEYBOARD_COLUMN_SIZE;
 *     KEYSCAN_InitStruct.scanmode     = KeyScan_Manual_Scan_Mode;
 *     KEYSCAN_InitStruct.debounceEn   = ENABLE;
 *     KeyScan_Init(KEYSCAN, &KEYSCAN_InitStruct);
 * }
 * \endcode
 */
void KeyScan_Init(KEYSCAN_TypeDef *KeyScan, KEYSCAN_InitTypeDef *KeyScan_InitStruct);

/**
 *
 * \brief  Fills each Keyscan_InitStruct member with its default value.
 *
 * \note   The default settings for the KeyScan_InitStruct member are shown in the following table:
 *         | KeyScan_InitStruct Member | Default Value                       |
 *         |:-------------------------:|:-----------------------------------:|
 *         | colSize                   | 2                                   |
 *         | rowSize                   | 2                                   |
 *         | clockdiv                  | 0x1f8                               |
 *         | delayclk                  | 0x01                                |
 *         | debounceEn                | \ref ENABLE                         |
 *         | scantimerEn               | \ref ENABLE                         |
 *         | detecttimerEn             | \ref ENABLE                         |
 *         | debouncecnt               | 0x10                                |
 *         | scanInterval              | 0x10                                |
 *         | releasecnt                | 0x1                                 |
 *         | scanmode                  | \ref KeyScan_Auto_Scan_Mode         |
 *         | detectMode                | \ref KeyScan_Detect_Mode_Level      |
 *         | manual_sel                | \ref KeyScan_Manual_Sel_Key         |
 *         | fifotriggerlevel          | 1                                   |
 *         | fifoOvrCtrl               | \ref KeyScan_FIFO_OVR_CTRL_DIS_LAST |
 *         | keylimit                  | 0x03                                |
 *         | rowpullhighEn             | \ref ENABLE                         |
 *         | colunmoutputhighEn        | \ref DISABLE                        |
 *
 * \param[in]  KeyScan_InitStruct: Pointer to a KEYSCAN_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_keyscan_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);
 *
 *     KEYSCAN_InitTypeDef KEYSCAN_InitStruct;
 *     KeyScan_StructInit(&KEYSCAN_InitStruct);
 *
 *     KEYSCAN_InitStruct.rowSize  = KEYBOARD_ROW_SIZE;
 *     KEYSCAN_InitStruct.colSize  = KEYBOARD_COLUMN_SIZE;
 *     KEYSCAN_InitStruct.scanmode     = KeyScan_Manual_Scan_Mode;
 *     KEYSCAN_InitStruct.debounceEn   = ENABLE;
 *     KeyScan_Init(KEYSCAN, &KEYSCAN_InitStruct);
 * }
 * \endcode
 */
void KeyScan_StructInit(KEYSCAN_InitTypeDef *KeyScan_InitStruct);

/**
 *
 * \brief  Enable or disable the specified KeyScan interrupts.
 *
 * \param[in]  KeyScan: Selected KeyScan peripheral, which can be KEYSCAN.
 * \param[in]  KeyScan_IT: Specifies the KeyScan interrupt sources to be enabled or disabled, refer to \ref x3g_Keyscan_Interrupt_Definition.
 *             This parameter can be any combination of the following values:
 *             - KEYSCAN_INT_OVER_READ: KeyScan FIFO over read interrupt. When there is no data in the FIFO, reading the FIFO will trigger this interrupt to prevent over-reading.
 *             - KEYSCAN_INT_THRESHOLD: KeyScan FIFO threshold interrupt. When data in the FIFO reaches the threshold level, the interrupt is triggered.
 *             - KEYSCAN_INT_SCAN_END: KeyScan finish interrupt. Whether the key value is scanned or not, the interrupt will be triggered as long as the scanning action is completed.
 *             - KEYSCAN_INT_FIFO_NOT_EMPTY: KeyScan FIFO not empty interrupt. If there is data in the FIFO, the interrupt will be triggered.
 *             - KEYSCAN_INT_ALL_RELEASE: KeyScan all release interrupt. When the release time count reaches the set value, if no key is pressed, the interrupt is triggered.
 * \param[in]  newState: New state of the specified KeyScan interrupts.
 *             This parameter can be one of the following values:
 *             - ENABLE: Enable the specified KeyScan interrupts.
 *             - DISABLE: Disable the specified KeyScan interrupts.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_keyscan_init(void)
 * {
 *     KeyScan_INTConfig(KEYSCAN, KEYSCAN_INT_SCAN_END | KEYSCAN_INT_ALL_RELEASE, ENABLE);
 *     KeyScan_Cmd(KEYSCAN, ENABLE);
 * }
 * \endcode
 */
void KeyScan_INTConfig(KEYSCAN_TypeDef *KeyScan, uint32_t KeyScan_IT,
                       FunctionalState NewState);

/**
 *
 * \brief  Mask or unmask the specified KeyScan interrupts.
 *
 * \param[in]  KeyScan: Selected KeyScan peripheral, which can be KEYSCAN.
 * \param[in]  KeyScan_IT: Specifies the KeyScan interrupt sources, refer to \ref x3g_Keyscan_Interrupt_Definition.
 *             This parameter can be any combination of the following values:
 *             - KEYSCAN_INT_OVER_READ: KeyScan FIFO over read interrupt. When there is no data in the FIFO, reading the FIFO will trigger this interrupt to prevent over-reading.
 *             - KEYSCAN_INT_THRESHOLD: KeyScan FIFO threshold interrupt. When data in the FIFO reaches the threshold level, the interrupt is triggered.
 *             - KEYSCAN_INT_SCAN_END: KeyScan finish interrupt. Whether the key value is scanned or not, the interrupt will be triggered as long as the scanning action is completed.
 *             - KEYSCAN_INT_FIFO_NOT_EMPTY: KeyScan FIFO not empty interrupt. If there is data in the FIFO, the interrupt will be triggered.
 *             - KEYSCAN_INT_ALL_RELEASE: KeyScan all release interrupt. When the release time count reaches the set value, if no key is pressed, the interrupt is triggered.
 * \param[in]  newState: New state of the specified KeyScan interrupt mask.
 *             This parameter can be one of the following values:
 *             - ENABLE: Enable the interrupt mask of KeyScan.
 *             - DISABLE: Disable the interrupt mask of KeyScan.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void KeyScan_Handler(void)
 * {
 *     if (KeyScan_GetFlagState(KEYSCAN, KEYSCAN_INT_FLAG_ALL_RELEASE) == SET)
 *     {
 *         //add user code here.
 *         KeyScan_ClearINTPendingBit(KEYSCAN, KEYSCAN_INT_ALL_RELEASE);
 *         KeyScan_INTMask(KEYSCAN, KEYSCAN_INT_ALL_RELEASE, DISABLE);
 *     }
 * }
 * \endcode
 */
void KeyScan_INTMask(KEYSCAN_TypeDef *KeyScan, uint32_t KeyScan_IT,
                     FunctionalState NewState);

/**
 *
 * \brief  Read data from KeyScan FIFO.
 *
 * \param[in]  KeyScan: Selected KeyScan peripheral, which can be KEYSCAN.
 * \param[out] outBuf: Buffer to save data read from KeyScan FIFO.
 * \param[in]  count: Data length to be read.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     uint16_t data[3] = {0};
 *     KeyScan_Read(KEYSCAN, data, 3);
 * }
 * \endcode
 */
void KeyScan_Read(KEYSCAN_TypeDef *KeyScan, uint16_t *outBuf, uint16_t count);

/**
 *
 * \brief   Enable or disable the KeyScan peripheral.
 *
 * \param[in] KeyScan: Selected KeyScan peripheral, which can be KEYSCAN.
 * \param[in] NewState: New state of the KeyScan peripheral.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the KeyScan peripheral.
 *            - DISABLE: Disable the KeyScan peripheral.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_keyscan_init(void)
 * {
 *     KeyScan_Cmd(KEYSCAN, ENABLE);
 * }
 * \endcode
 */
void KeyScan_Cmd(KEYSCAN_TypeDef *KeyScan, FunctionalState NewState);

/**
 *
 * \brief   Set filter data.
 *
 * \param[in] KeyScan: Selected KeyScan peripheral, which can be KEYSCAN.
 * \param[in] data: Config the data to be filtered. This parameter should not be more than 9 bits.
 * \param[in] NewState: New state of the KeyScan filtering.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable data filtering.
 *            - DISABLE: Disable data filtering.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     KeyScan_FilterDataConfig(KEYSCAN, 0x01, ENABLE);
 * }
 * \endcode
 */
void KeyScan_FilterDataConfig(KEYSCAN_TypeDef *KeyScan, uint16_t data,
                              FunctionalState NewState);

/**
 *
 * \brief   Config the KeyScan debounce time.
 *
 * \param[in] KeyScan: Selected KeyScan peripheral, which can be KEYSCAN.
 * \param[in] time: KeyScan hardware debounce time. Debounce time = delay clock * time.
 * \param[in] NewState: New state of the KeyScan debounce function.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable KeyScan debounce function.
 *            - DISABLE: Disable KeyScan debounce function.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     KeyScan_debounceConfig(KEYSCAN, 10, ENABLE);
 *
 * }
 * \endcode
 */
void KeyScan_debounceConfig(KEYSCAN_TypeDef *KeyScan, uint8_t time,
                            FunctionalState NewState);

/**
 *
 * \brief   Get KeyScan FIFO data number.
 *
 * \param[in]  KeyScan: Selected KeyScan peripheral, which can be KEYSCAN.
 *
 * \return  Data length in FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void KeyScan_Handler(void)
 * {
 *     if (KeyScan_GetFlagState(KEYSCAN, KEYSCAN_INT_FLAG_SCAN_END) == SET)
 *     {
 *         KeyScan_INTMask(KEYSCAN, KEYSCAN_INT_SCAN_END, ENABLE);
 *
 *         //KeyScan FIFO not empty
 *         if (KeyScan_GetFlagState(KEYSCAN, KEYSCAN_FLAG_EMPTY) != SET)
 *         {
 *             uint8_t data_len = KeyScan_GetFifoDataNum(KEYSCAN);
 *             KeyScan_Read(KEYSCAN, data, data_len);
 *             //add user code here.
 *         }
 *     }
 * }
 * \endcode
 */
uint16_t KeyScan_GetFifoDataNum(KEYSCAN_TypeDef *KeyScan);

/**
 *
 * \brief  Clear the KeyScan interrupt pending bit.
 *
 * \param[in]  KeyScan: Selected KeyScan peripheral, which can be KEYSCAN.
 * \param[in]  KeyScan_IT: Specifies the interrupt pending bit to clear, refer to \ref x3g_Keyscan_Interrupt_Definition.
 *             This parameter can be any combination of the following values:
 *             - KEYSCAN_INT_OVER_READ: KeyScan FIFO over read interrupt. When there is no data in the FIFO, reading the FIFO will trigger this interrupt to prevent over-reading.
 *             - KEYSCAN_INT_THRESHOLD: KeyScan FIFO threshold interrupt. When data in the FIFO reaches the threshold level, the interrupt is triggered.
 *             - KEYSCAN_INT_SCAN_END: KeyScan finish interrupt. Whether the key value is scanned or not, the interrupt will be triggered as long as the scanning action is completed.
 *             - KEYSCAN_INT_FIFO_NOT_EMPTY: KeyScan FIFO not empty interrupt. If there is data in the FIFO, the interrupt will be triggered.
 *             - KEYSCAN_INT_ALL_RELEASE: KeyScan all release interrupt. When the release time count reaches the set value, if no key is pressed, the interrupt is triggered.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void KeyScan_Handler(void)
 * {
 *     if (KeyScan_GetFlagState(KEYSCAN, KEYSCAN_INT_FLAG_ALL_RELEASE) == SET)
 *     {
 *         //clear KeyScan interrupt
 *         KeyScan_ClearINTPendingBit(KEYSCAN, KEYSCAN_INT_ALL_RELEASE);
 *     }
 * }
 * \endcode
 */
void KeyScan_ClearINTPendingBit(KEYSCAN_TypeDef *KeyScan, uint32_t KeyScan_IT);

/**
 *
 * \brief   Clear the specified KeyScan flags.
 *
 * \param[in] KeyScan: Selected KeyScan peripheral, which can be KEYSCAN.
 * \param[in] KeyScan_FLAG: Specifies the KeyScan flag to clear, refer to \ref x3g_Keyscan_Flags.
 *            This parameter can be one of the following values:
 *            - KEYSCAN_FLAG_FIFOLIMIT: When data filtering occurs, this bit will be set to 1.
 *            - KEYSCAN_FLAG_DATAFILTER: FIFO data filter status.
 *            - KEYSCAN_FLAG_OVR: FIFO overflow status.
 *
 * \note    KEYSCAN_FLAG_FULL and KEYSCAN_FLAG_EMPTY can't be cleared manually.
 *          They are cleared by hardware automatically.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     KeyScan_ClearFlags(KEYSCAN, KEYSCAN_FLAG_FIFOLIMIT);
 * }
 * \endcode
 */
void KeyScan_ClearFlags(KEYSCAN_TypeDef *KeyScan, uint32_t KeyScan_FLAG);

/**
 *
 * \brief   Get the specified KeyScan flag status.
 *
 * \param[in] KeyScan: Selected KeyScan peripheral, which can be KEYSCAN.
 * \param[in] KeyScan_FLAG: Specifies the KeyScan flag to check, refer to \ref x3g_Keyscan_Flags.
 *            This parameter can be one of the following values:
 *            - KEYSCAN_FLAG_FIFOLIMIT: When data filtering occurs, this bit will be set to 1.
 *            - KEYSCAN_INT_FLAG_THRESHOLD: FIFO threshold interrupt status.
 *            - KEYSCAN_INT_FLAG_OVER_READ: FIFO over read interrupt status.
 *            - KEYSCAN_INT_FLAG_SCAN_END: Scan finish interrupt status.
 *            - KEYSCAN_INT_FLAG_FIFO_NOT_EMPTY: FIFO not empty interrupt status.
 *            - KEYSCAN_INT_FLAG_ALL_RELEASE: All release interrupt status.
 *            - KEYSCAN_FLAG_DATAFILTER: FIFO data filter status.
 *            - KEYSCAN_FLAG_OVR: FIFO overflow status.
 *            - KEYSCAN_FLAG_FULL: FIFO full status.
 *            - KEYSCAN_FLAG_EMPTY: FIFO empty status.
 *
 * \return  The status of KeyScan flag.
 * \retval SET: The specified KeyScan flag is set.
 * \retval RESET: The specified KeyScan flag is unset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void KeyScan_Handler(void)
 * {
 *     if (KeyScan_GetFlagState(KEYSCAN, KEYSCAN_INT_FLAG_ALL_RELEASE) == SET)
 *     {
 *         //add user code here.
 *     }
 * }
 * \endcode
 */
FlagStatus KeyScan_GetFlagState(KEYSCAN_TypeDef *KeyScan, uint32_t KeyScan_FLAG);

/**
 *
 * \brief  Read KeyScan FIFO data.
 *
 * \param[in] KeyScan: Selected KeyScan peripheral, which can be KEYSCAN.
 *
 * \return KeyScan FIFO data.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void keyscan_demo(void)
 * {
 *     uint16_t data = KeyScan_ReadFifoData(KEYSCAN);
 * }
 * \endcode
 */
uint16_t KeyScan_ReadFifoData(KEYSCAN_TypeDef *KeyScan);

#ifdef __cplusplus
}
#endif

#endif /* RTL876X_KEYSCAN_H */

/** @} */ /* End of group 87x3g_KeyScan_Exported_Functions */
/** @} */ /* End of group 87x3g_KeyScan */

