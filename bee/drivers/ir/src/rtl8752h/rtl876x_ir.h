/**
*********************************************************************************************************
*               Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl876x_ir.h
* \brief    The header file of the peripheral IR driver.
* \details  This file provides all IR firmware functions.
* \author   yuan
* \date     2024-01-22
* \version  v2.1.2
* *********************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef _RTL876x_IR_H_
#define _RTL876x_IR_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup  IO          Peripheral Drivers
 * \defgroup    IR          IR
 *
 * \brief       Manage the IR peripheral functions.
 *
 * \ingroup     IO
 */

/*============================================================================*
 *                        Includes
 *============================================================================*/
#include "rtl876x.h"

/*============================================================================*
 *                         Types
 *============================================================================*/
/**
 * \defgroup    IR_Exported_Types   IR Exported Types
 * \{
 * \ingroup     IR
 */

/**
 * \brief       IR init structure definition.
 *
 * \ingroup     IR_Exported_Types
 */
typedef struct
{
    uint32_t IR_Clock;              /*!< Specify the source clock frequency, the unit is Hz. */
    uint32_t IR_Freq;               /*!< Specify the ir carrier frequency, the unit is Hz. */
    float    IR_DutyCycle;          /*!< Specify the IR duty cycle. */
    uint32_t IR_Mode;               /*!< Specify the IR mode.
                                              This parameter can be a value of \ref IR_Mode */
    uint32_t IR_TxIdleLevel;        /*!< Specify the IR output level in Tx mode
                                              This parameter can be a value of \ref IR_Idle_Status */
    uint32_t IR_TxInverse;          /*!< Specify inverse FIFO data or not in TX mode
                                              This parameter can be a value of \ref IR_TX_Data_Type */
    uint32_t IR_TxFIFOThrLevel;     /*!< Specify TX FIFO interrupt threshold in TX mode. When TX FIFO depth <= threshold value, trigger interrupt.
                                              This parameter can be a value of 0 ~ 31. */
    uint32_t IR_RxStartMode;        /*!< Specify Start mode in RX mode
                                              This parameter can be a value of \ref IR_Rx_Start_Mode. */
    uint32_t IR_RxFIFOThrLevel;     /*!< Specify RX FIFO interrupt threshold in RX mode. when RX FIFO depth > threshold value, trigger interrupt.
                                              This parameter can be a value of 0 ~ 31. */
    uint32_t IR_RxFIFOFullCtrl;     /*!< Specify data discard mode in RX mode when RX FIFO is full and receiving new data.
                                              This parameter can be a value of \ref IR_RX_FIFO_DISCARD_SETTING. */
    uint32_t IR_RxTriggerMode;      /*!< Specify trigger mode in RX mode
                                              This parameter can be a value of \ref IR_RX_Trigger_Mode. */
    uint32_t IR_RxFilterTime;       /*!< Specify filter time in RX mode
                                              This parameter can be a value of \ref IR_RX_Filter_Time. */
    uint32_t IR_RxCntThrType;       /*!< Specify counter level type when trigger IR_INT_RX_CNT_THR interrupt in RX mode.
                                              This parameter can be a value of \ref IR_RX_COUNTER_THRESHOLD_TYPE. */
    uint32_t IR_RxCntThr;           /*!< Specify counter threshold value when trigger IR_INT_RX_CNT_THR interrupt in RX mode. */
    uint8_t IR_TxDmaEn;             /*!< Specify the Tx dma mode.
                                              This parameter must be a value of DISABLE and ENABLE. */
    uint8_t IR_TxWaterLevel;        /*!< Specify the DMA tx water level.
                                              This parameter must range from 0 to 32.*/
    uint8_t IR_RxDmaEn;             /*!< Specify the Rx dma mode.
                                              This parameter must be a value of DISABLE and ENABLE. */
    uint8_t IR_RxWaterLevel;        /*!< Specify the DMA rx water level.
                                              This parameter must range from 0 to 32.*/
} IR_InitTypeDef;

/** End of IR_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Register Defines
 *============================================================================*/

/* Peripheral: IR */
/* Description: IR register defines */

/* Register: TX_CONFIG -------------------------------------------------------*/
/* Description: IR TX CONFIG register. Offset: 0x04. Address: 0x40015804. */

/* TX_CONFIG[31] :IR_MODE_SEL. 0x1: RX mode. 0x0: TX mode. */
#define IR_MODE_SEL_Pos                 (31UL)
#define IR_MODE_SEL_Msk                 (0x1UL << IR_MODE_SEL_Pos)
#define IR_MODE_SEL_CLR                 (~IR_MODE_SEL_Msk)
/* TX_CONFIG[30] :IR_TX_START. 0x1: Start TX. 0x0: Stop TX. */
#define IR_TX_START_Pos                 (30UL)
#define IR_TX_START_Msk                 (0x1UL << IR_TX_START_Pos)
#define IR_TX_START_CLR                 (~IR_TX_START_Msk)
/* TX_CONFIG[16] :IR_TX_DUTY_NUM. Duty cycle setting for modulation frequency. */
/* Example : for 1/3 duty cycle, IR_DUTY_NUM = (IR_DIV_NUM+1)/3 -1. */
#define IR_TX_DUTY_NUM_Pos              (16UL)
#define IR_TX_DUTY_NUM_Msk              (0x1FFFUL << IR_TX_DUTY_NUM_Pos)
/* TX_CONFIG[14] :IR_OUTPUT_INVERSE. 0x1: Inverse  active output. 0x0: Not inverse active output. */
#define IR_OUTPUT_INVERSE_Pos           (14UL)
#define IR_OUTPUT_INVERSE_Msk           (0x1UL << IR_OUTPUT_INVERSE_Pos)
#define IR_OUTPUT_INVERSE_CLR           (~IR_OUTPUT_INVERSE_Msk)
/* TX_CONFIG[13] :IR_FIFO_INVERSE. 0x1: Inverse FIFO define. 0x0: Not inverse FIFO define. */
#define IR_FIFO_INVERSE_Pos             (13UL)
#define IR_FIFO_INVERSE_Msk             (0x1UL << IR_FIFO_INVERSE_Pos)
#define IR_FIFO_INVERSE_CLR             (~IR_FIFO_INVERSE_Msk)
/* TX_CONFIG[8] :IR_TX_FIFO_THRESHOLD. TX FIFO interrupt threshold. when TX FIFO depth <= threshold value, trigger interrupt. */
#define IR_TX_FIFO_THRESHOLD_Pos        (8UL)
#define IR_TX_FIFO_THRESHOLD_Msk        (0x1fUL << IR_TX_FIFO_THRESHOLD_Pos)
#define IR_TX_FIFO_THRESHOLD_CLR        (~IR_TX_FIFO_THRESHOLD_Msk)
/* TX_CONFIG[6] :IR_TX_IDLE_STATE. TX output State in idle. 0x1: High. 0x0: Low. */
#define IR_TX_IDLE_STATE_Pos            (6UL)
#define IR_TX_IDLE_STATE_Msk            (0x1UL << IR_TX_IDLE_STATE_Pos)
#define IR_TX_IDLE_STATE_CLR            (~IR_TX_IDLE_STATE_Msk)
/* TX_CONFIG[5] :IR_TX_FIFO_OVER_INT_MASK. TX FIFO empty Interrupt. 0x1: Mask. 0x0: Unmask. */
#define IR_TX_FIFO_OVER_INT_MASK_Pos    (5UL)
#define IR_TX_FIFO_OVER_INT_MASK_Msk    (0x1UL << IR_TX_FIFO_OVER_INT_MASK_Pos)
#define IR_TX_FIFO_OVER_INT_MASK_CLR    (~IR_TX_FIFO_OVER_INT_MASK_Msk)
/* TX_CONFIG[4] :IR_TX_FIFO_OVER_INT_EN. TX FIFO overflow Interrupt. 0x1: Enable. 0x0: Disable. */
#define IR_TX_FIFO_OVER_INT_EN_Pos      (4UL)
#define IR_TX_FIFO_OVER_INT_EN_Msk      (0x1UL << IR_TX_FIFO_OVER_INT_EN_Pos)
#define IR_TX_FIFO_OVER_INT_EN_CLR      (~IR_TX_FIFO_OVER_INT_EN_Msk)
#define IR_TX_FIFO_OVER_MSK_TO_EN_Pos   (IR_TX_FIFO_OVER_INT_MASK_Pos - IR_TX_FIFO_OVER_INT_EN_Pos)
/* TX_CONFIG[3] :IR_TX_FIFO_LEVEL_INT_MASK. TX FIFO threshold Interrupt. 0x1: Mask. 0x0: Unmask. */
#define IR_TX_FIFO_LEVEL_INT_MASK_Pos   (3UL)
#define IR_TX_FIFO_LEVEL_INT_MASK_Msk   (0x1UL << IR_TX_FIFO_LEVEL_INT_MASK_Pos)
#define IR_TX_FIFO_LEVEL_INT_MASK_CLR   (~IR_TX_FIFO_LEVEL_INT_MASK_Msk)
/* TX_CONFIG[2] :IR_TX_FIFO_EMPTY_INT_MASK. TX FIFO empty Interrupt. 0x1: Mask. 0x0: Unmask. */
#define IR_TX_FIFO_EMPTY_INT_MASK_Pos   (2UL)
#define IR_TX_FIFO_EMPTY_INT_MASK_Msk   (0x1UL << IR_TX_FIFO_EMPTY_INT_MASK_Pos)
#define IR_TX_FIFO_EMPTY_INT_MASK_CLR   (~IR_TX_FIFO_EMPTY_INT_MASK_Msk)
/* TX_CONFIG[1] :IR_TX_FIFO_LEVEL_INT_EN. TX FIFO threshold Interrupt. 0x1: Enable. 0x0: Disable. */
#define IR_TX_FIFO_LEVEL_INT_EN_Pos     (1UL)
#define IR_TX_FIFO_LEVEL_INT_EN_Msk     (0x1UL << IR_TX_FIFO_LEVEL_INT_EN_Pos)
#define IR_TX_FIFO_LEVEL_INT_EN_CLR     (~IR_TX_FIFO_LEVEL_INT_EN_Msk)
/* TX_CONFIG[0] :IR_TX_FIFO_EMPTY_INT_EN. TX FIFO empty Interrupt. 0x1: Enable. 0x0: Disable. */
#define IR_TX_FIFO_EMPTY_INT_EN_Pos     (0UL)
#define IR_TX_FIFO_EMPTY_INT_EN_Msk     (0x1UL << IR_TX_FIFO_EMPTY_INT_EN_Pos)
#define IR_TX_FIFO_EMPTY_INT_EN_CLR     (~IR_TX_FIFO_EMPTY_INT_EN_Msk)
#define IR_TX_MSK_TO_EN_Pos             (IR_TX_FIFO_EMPTY_INT_MASK_Pos - IR_TX_FIFO_EMPTY_INT_EN_Pos)
#define IR_TX_STATUS_TO_EN_Pos          (IR_TX_FIFO_OVER_INT_EN_Pos - IR_TX_FIFO_EMPTY_INT_MASK_Pos)

/* TX_CONFIG[] :IR_TX_FINISH_INT_EN. TX Finish Interrupt. 0x1: Enable. 0x0: Disable. */
#define IR_TX_FINISH_INT_EN_Pos     (5UL)
#define IR_TX_FINISH_INT_EN_Msk     (0x1UL << IR_TX_FINISH_INT_EN_Pos)
#define IR_TX_FINISH_INT_EN_CLR     (~IR_TX_FINISH_INT_EN_Msk)

/* Register: TX_SR -----------------------------------------------------------*/
/* Description: TX_SR register. Offset: 0x08. Address: 0x40015808. */

/* TX_SR[15] :IR_TX_FIFO_EMPTY. 0x1: empty. 0x0: not empty. */
#define IR_TX_FIFO_EMPTY_Pos            (15UL)
#define IR_TX_FIFO_EMPTY_Msk            (0x1UL << IR_TX_FIFO_EMPTY_Pos)
/* TX_SR[14] :IR_TX_FIFO_FULL. 0x1: full. 0x0: not full. */
#define IR_TX_FIFO_FULL_Pos             (14UL)
#define IR_TX_FIFO_FULL_Msk             (0x1UL << IR_TX_FIFO_FULL_Pos)
/* TX_SR[13:8] :IR_TX_FIFO_OFFSET. */
#define IR_TX_FIFO_OFFSET_Pos           (8UL)
#define IR_TX_FIFO_OFFSET_Msk           (0x7fUL << IR_TX_FIFO_OFFSET_Pos)
/* TX_SR[4] :IR_TX_STATUS. */
#define IR_TX_STATUS_Pos                (4UL)
#define IR_TX_STATUS_Msk                (0x1UL << IR_TX_STATUS_Pos)
/* TX_SR[2] :IR_TX_FIFO_OVER_INT_STATUS. */
#define IR_TX_FIFO_OVER_INT_STATUS_Pos  (2UL)
#define IR_TX_FIFO_OVER_INT_STATUS_Msk  (0x1UL << IR_TX_FIFO_OVER_INT_STATUS_Pos)
/* TX_SR[1] :IR_TX_FIFO_LEVEL_INT_STATUS. */
#define IR_TX_FIFO_LEVEL_INT_STATUS_Pos (1UL)
#define IR_TX_FIFO_LEVEL_INT_STATUS_Msk (0x1UL << IR_TX_FIFO_LEVEL_INT_STATUS_Pos)
/* TX_SR[0] :IR_TX_FIFO_EMPTY_INT_STATUS. */
#define IR_TX_FIFO_EMPTY_INT_STATUS_Pos (0UL)
#define IR_TX_FIFO_EMPTY_INT_STATUS_Msk (0x1UL << IR_TX_FIFO_EMPTY_INT_STATUS_Pos)

/* Register: TX_INT_CLR -----------------------------------------------------------*/
/* Description: TX_INT_CLR register. Offset: 0x10. Address: 0x40015810. */
/* TX_INT_CLR[4] :IR_TX_FINISH_CLR. Write 1 clear. */
#define IR_TX_FINISH_INT_CLR_Pos     (4UL)
#define IR_TX_FINISH_INT_CLR_Msk     (0x1UL << IR_TX_FINISH_INT_CLR_Pos)
/* TX_INT_CLR[3] :IR_TX_FIFO_OVER_INT_CLR. Write 1 clear. */
#define IR_TX_FIFO_OVER_INT_CLR_Pos     (3UL)
#define IR_TX_FIFO_OVER_INT_CLR_Msk     (0x1UL << IR_TX_FIFO_OVER_INT_CLR_Pos)
/* TX_INT_CLR[2] :IR_TX_FIFO_LEVEL_INT_CLR. Write 1 clear. */
#define IR_TX_FIFO_LEVEL_INT_CLR_Pos    (2UL)
#define IR_TX_FIFO_LEVEL_INT_CLR_Msk    (0x1UL << IR_TX_FIFO_LEVEL_INT_CLR_Pos)
/* TX_INT_CLR[1] :IR_TX_FIFO_EMPTY_INT_CLR. Write 1 clear. */
#define IR_TX_FIFO_EMPTY_INT_CLR_Pos    (1UL)
#define IR_TX_FIFO_EMPTY_INT_CLR_Msk    (0x1UL << IR_TX_FIFO_EMPTY_INT_CLR_Pos)
/* TX_INT_CLR[0] :IR_TX_FIFO_CLR. Write 1 clear. */
#define IR_TX_FIFO_CLR_Pos              (0UL)
#define IR_TX_FIFO_CLR_Msk              (0x1UL << IR_TX_FIFO_CLR_Pos)

#define IR_INT_ALL_CLR                  (IR_TX_FIFO_OVER_INT_CLR_Msk | \
                                         IR_TX_FIFO_LEVEL_INT_CLR_Msk | \
                                         IR_TX_FIFO_EMPTY_INT_CLR_Msk)

/* Register: TX_FIFO ---------------------------------------------------------*/
/* Description: TX_FIFO register. Offset: 0x14. Address: 0x40015814. */

/* TX_FIFO[31] :IR_DATA_TYPE. 0x1: active carrier. 0x0: incative carrier. */
#define IR_DATA_TYPE_Pos                (31UL)
#define IR_DATA_TYPE_Msk                (0x1UL << IR_DATA_TYPE_Pos)
#define IR_DATA_TYPE_CLR                (~IR_DATA_TYPE_Msk)
/* TX_FIFO[30] :IR_TX_LAST_PACKEET. 0x1: last packet. 0x0: normal packet. */
#define IR_TX_LAST_PACKEET_Pos          (30UL)
#define IR_TX_LAST_PACKEET_Msk          (0x1UL << IR_TX_LAST_PACKEET_Pos)
#define IR_TX_LAST_PACKEET_CLR          (~IR_TX_LAST_PACKEET_Msk)
/* TX_FIFO[29:28] :IR_LOW_PERIOD_COMPENSATION */
#define IR_LOW_PERIOD_COMPENSATION_Pos  (28UL)
#define IR_LOW_PERIOD_COMPENSATION_Msk  (0x3UL << IR_LOW_PERIOD_COMPENSATION_Pos)
#define IR_LOW_PERIOD_COMPENSATION_CLR  (~IR_LOW_PERIOD_COMPENSATION_Msk)

/* Register: RX_CONFIG ------------------------------------------------------*/
/* Description: IR RX CONFIG register. Offset: 0x18. Address: 0x40015818. */

/* RX_CONFIG[28] :IR_RX_START. 0x1: Run. 0x0: Stop. */
#define IR_RX_START_Pos                 (28UL)
#define IR_RX_START_Msk                 (0x1UL << IR_RX_START_Pos)
#define IR_RX_START_CLR                 (~IR_RX_START_Msk)
/* RX_CONFIG[27] :IR_RX_START_MODE. 0x1: auto mode. 0x0: manual mode. */
#define IR_RX_START_MODE_Pos            (27UL)
#define IR_RX_START_MODE_Msk            (0x1UL << IR_RX_START_MODE_Pos)
#define IR_RX_START_MODE_CLR            (~IR_RX_START_MODE_Msk)
/* RX_CONFIG[26] :IR_RX_MAN_START. 0x1: Start check waveform. */
#define IR_RX_MAN_START_Pos             (26UL)
#define IR_RX_MAN_START_Msk             (0x1UL << IR_RX_MAN_START_Pos)
#define IR_RX_MAN_START_CLR             (~IR_RX_MAN_START_Msk)
/* RX_CONFIG[24] :IR_TRIGGER_MODE. 0x1: Run. */
/* 0x0: high->low  trigger. 0x1: low->high trigger. 0x02: high->low  or low->high trigger. */
#define IR_TRIGGER_MODE_Pos             (24UL)
#define IR_TRIGGER_MODE_Msk             (0x3UL << IR_TRIGGER_MODE_Pos)
#define IR_TRIGGER_MODE_CLR             (~IR_TRIGGER_MODE_Msk)
/* RX_CONFIG[21] :IR_FILTER_TIME. */
#define IR_FILTER_TIME_Pos              (21UL)
#define IR_FILTER_TIME_Msk              (0x3UL << IR_FILTER_TIME_Pos)
#define IR_FILTER_TIME_CLR              (~IR_FILTER_TIME_Msk)
/* RX_CONFIG[19] :IR_RX_FIFO_ERROR_MASK_INT. 0x1: mask. 0x0: unmask.*/
#define IR_RX_FIFO_ERROR_MASK_INT_Pos   (19UL)
#define IR_RX_FIFO_ERROR_MASK_INT_Msk   (0x1UL << IR_RX_FIFO_ERROR_MASK_INT_Pos)
#define IR_RX_FIFO_ERROR_MASK_INT_CLR   (~IR_RX_FIFO_ERROR_MASK_INT_Msk)
/* RX_CONFIG[18] :IR_RX_CNT_THR_MASK_INT. 0x1: enable. 0x0: disable.*/
#define IR_RX_CNT_THR_MASK_INT_Pos      (18UL)
#define IR_RX_CNT_THR_MASK_INT_Msk      (0x1UL << IR_RX_CNT_THR_MASK_INT_Pos)
#define IR_RX_CNT_THR_MASK_INT_CLR      (~IR_RX_CNT_THR_MASK_INT_Msk)
/* RX_CONFIG[17] :IR_RX_FIFO_OF_MASK_INT. 0x1: enable. 0x0: disable.*/
#define IR_RX_FIFO_OF_MASK_INT_Pos      (17UL)
#define IR_RX_FIFO_OF_MASK_INT_Msk      (0x1UL << IR_RX_FIFO_OF_MASK_INT_Pos)
#define IR_RX_FIFO_OF_MASK_INT_CLR      (~IR_RX_FIFO_OF_MASK_INT_Msk)
/* RX_CONFIG[16] :IR_RX_CNT_OF_MASK_INT. 0x1: enable. 0x0: disable.*/
#define IR_RX_CNT_OF_MASK_INT_Pos       (16UL)
#define IR_RX_CNT_OF_MASK_INT_Msk       (0x1UL << IR_RX_CNT_OF_MASK_INT_Pos)
#define IR_RX_CNT_OF_MASK_INT_CLR       (~IR_RX_CNT_OF_MASK_INT_Msk)
/* RX_CONFIG[15] :IR_RX_FIFO_LEVEL_MASK_INT. 0x1: enable. 0x0: disable.*/
#define IR_RX_FIFO_LEVEL_MASK_INT_Pos   (15UL)
#define IR_RX_FIFO_LEVEL_MASK_INT_Msk   (0x1UL << IR_RX_FIFO_LEVEL_MASK_INT_Pos)
#define IR_RX_FIFO_LEVEL_MASK_INT_CLR   (~IR_RX_FIFO_LEVEL_MASK_INT_Msk)
/* RX_CONFIG[14] :IR_RX_FIFO_FULL_MASK_INT. 0x1: enable. 0x0: disable.*/
#define IR_RX_FIFO_FULL_MASK_INT_Pos    (14UL)
#define IR_RX_FIFO_FULL_MASK_INT_Msk    (0x1UL << IR_RX_FIFO_FULL_MASK_INT_Pos)
#define IR_RX_FIFO_FULL_MASK_INT_CLR    (~IR_RX_FIFO_FULL_MASK_INT_Msk)
/* RX_CONFIG[13] :IR_RX_FIFO_DISCARD_SET. 0x1: reject new data send to FIFO. 0x0: discard oldest data in FIFO.*/
#define IR_RX_FIFO_DISCARD_SET_Pos      (13UL)
#define IR_RX_FIFO_DISCARD_SET_Msk      (0x1UL << IR_RX_FIFO_DISCARD_SET_Pos)
#define IR_RX_FIFO_DISCARD_SET_CLR      (~IR_RX_FIFO_DISCARD_SET_Msk)
/* RX_CONFIG[7] :IR_RX_FIFO_LEVE. */
#define IR_RX_FIFO_LEVEL_Pos            (8UL)
#define IR_RX_FIFO_LEVEL_Msk            (0x1fUL << IR_RX_FIFO_LEVEL_Pos)
#define IR_RX_FIFO_LEVEL_CLR            (~IR_RX_FIFO_LEVEL_Msk)
/* RX_CONFIG[5] :IR_RX_FIFO_ERROR_INT. 0x1: enable. 0x0: disable.*/
#define IR_RX_FIFO_ERROR_INT_Pos        (5UL)
#define IR_RX_FIFO_ERROR_INT_Msk        (0x1UL << IR_RX_FIFO_ERROR_INT_Pos)
#define IR_RX_FIFO_ERROR_INT_CLR        (~IR_RX_FIFO_ERROR_INT_Msk)
/* RX_CONFIG[4] :IR_RX_CNT_THR_INT. 0x1: enable. 0x0: disable.*/
#define IR_RX_CNT_THR_INT_Pos           (4UL)
#define IR_RX_CNT_THR_INT_Msk           (0x1UL << IR_RX_CNT_THR_INT_Pos)
#define IR_RX_CNT_THR_INT_CLR           (~IR_RX_CNT_THR_INT_Msk)
/* RX_CONFIG[3] :IR_RX_FIFO_OF_INT. 0x1: enable. 0x0: disable.*/
#define IR_RX_FIFO_OF_INT_Pos           (3UL)
#define IR_RX_FIFO_OF_INT_Msk           (0x1UL << IR_RX_FIFO_OF_INT_Pos)
#define IR_RX_FIFO_OF_INT_CLR           (~IR_RX_FIFO_OF_INT_Msk)
/* RX_CONFIG[2] :IR_RX_CNT_OF_INT. 0x1: enable. 0x0: disable.*/
#define IR_RX_CNT_OF_INT_Pos            (2UL)
#define IR_RX_CNT_OF_INT_Msk            (0x1UL << IR_RX_CNT_OF_INT_Pos)
#define IR_RX_CNT_OF_INT_CLR            (~IR_RX_CNT_OF_INT_Msk)
/* RX_CONFIG[1] :IR_RX_FIFO_LEVEL_INT. 0x1: enable. 0x0: disable.*/
#define IR_RX_FIFO_LEVEL_INT_Pos        (1UL)
#define IR_RX_FIFO_LEVEL_INT_Msk        (0x1UL << IR_RX_FIFO_LEVEL_INT_Pos)
#define IR_RX_FIFO_LEVEL_INT_CLR        (~IR_RX_FIFO_LEVEL_INT_Msk)
/* RX_CONFIG[0] :IR_RX_FIFO_FULL_INT. 0x1: enable. 0x0: disable.*/
#define IR_RX_FIFO_FULL_INT_Pos         (0UL)
#define IR_RX_FIFO_FULL_INT_Msk         (0x1UL << IR_RX_FIFO_FULL_INT_Pos)
#define IR_RX_FIFO_FULL_INT_CLR         (~IR_RX_FIFO_FULL_INT_Msk)
#define IR_RX_MSK_TO_EN_Pos             (IR_RX_FIFO_FULL_MASK_INT_Pos - IR_RX_FIFO_FULL_INT_Pos)

#define IR_RX_MASK_ALL_INT              (IR_RX_FIFO_ERROR_MASK_INT_Msk | IR_RX_CNT_THR_MASK_INT_Msk | \
                                         IR_RX_FIFO_OF_MASK_INT_Msk | IR_RX_CNT_OF_MASK_INT_Msk | \
                                         IR_RX_FIFO_LEVEL_MASK_INT_Msk | IR_RX_FIFO_FULL_MASK_INT_Msk)

/* Register: RX_SR -----------------------------------------------------------*/
/* Description: RX_SR register. Offset: 0x1C. Address: 0x4001581C. */

/* RX_SR[17] :IR_TX_FIFO_EMPTY. 0x1: empty. 0x0: not empty. */
#define IR_RX_FIFO_EMPTY_Pos            (17UL)
#define IR_RX_FIFO_EMPTY_Msk            (0x1UL << IR_RX_FIFO_EMPTY_Pos)
/* RX_SR[16] :IR_TX_FIFO_FULL. 0x1: full. 0x0: not full. */
#define IR_RX_FIFO_FULL_Pos            (16UL)
#define IR_RX_FIFO_FULL_Msk            (0x1UL << IR_RX_FIFO_FULL_Pos)
/* RX_SR[8] :IR_RX_FIFO_OFFSET. */
#define IR_RX_FIFO_OFFSET_Pos           (8UL)
#define IR_RX_FIFO_OFFSET_Msk           (0x7fUL << IR_RX_FIFO_OFFSET_Pos)
#define IR_RX_FIFO_OFFSET_CLR           (~IR_RX_FIFO_OFFSET_Msk)
/* RX_SR[7] :IR_RX_STATUS. */
#define IR_RX_STATUS_Pos                (7UL)
#define IR_RX_STATUS_Msk                (0x1UL << IR_RX_STATUS_Pos)

/* Register: RX_INT_CLR -----------------------------------------------------------*/
/* Description: RX_INT_CLR register. Offset: 0x20. Address: 0x40015820. */

/* RX_INT_CLR[8] :IR_RX_FIFO_CLR. Write 1 clear. */
#define IR_RX_FIFO_CLR_Pos              (8UL)
#define IR_RX_FIFO_CLR_Msk              (0x1UL << IR_RX_FIFO_CLR_Pos)
/* RX_INT_CR[7] :IR_RX_RISING_EDGE_INT_CLR. */
#define IR_RX_RISING_EDGE_INT_CLR_Pos       (7UL)
#define IR_RX_RISING_EDGE_INT_CLR_Msk       (0x1UL << IR_RX_RISING_EDGE_INT_CLR_Pos)
#define IR_RX_RISING_EDGE_INT_CLR_CLR       (~IR_RX_RISING_EDGE_INT_CLR_Msk)
/* RX_INT_CR[6] :IR_RX_FALLING_EDGE_INT_CLR. */
#define IR_RX_FALLING_EDGE_INT_CLR_Pos      (6UL)
#define IR_RX_FALLING_EDGE_INT_CLR_Msk      (0x1UL << IR_RX_FALLING_EDGE_INT_CLR_Pos)
#define IR_RX_FALLING_EDGE_INT_CLR_CLR      (~IR_RX_FALLING_EDGE_INT_CLR_Msk)
/* RX_INT_CLR[5] :IR_RX_FIFO_ERROR_INT_CLR. Write 1 clear. */
#define IR_RX_FIFO_ERROR_INT_CLR_Pos    (5UL)
#define IR_RX_FIFO_ERROR_INT_CLR_Msk    (0x1UL << IR_RX_FIFO_ERROR_INT_CLR_Pos)
/* RX_INT_CLR[4] :IR_RX_CNT_THR_INT_CLR. Write 1 clear. */
#define IR_RX_CNT_THR_INT_CLR_Pos       (4UL)
#define IR_RX_CNT_THR_INT_CLR_Msk       (0x1UL << IR_RX_CNT_THR_INT_CLR_Pos)
/* RX_INT_CLR[3] :IR_RX_FIFO_OF_INT_CLR. Write 1 clear. */
#define IR_RX_FIFO_OF_INT_CLR_Pos       (3UL)
#define IR_RX_FIFO_OF_INT_CLR_Msk       (0x1UL << IR_RX_FIFO_OF_INT_CLR_Pos)
/* RX_INT_CLR[2] :IR_RX_CNT_OF_INT_CLR. Write 1 clear. */
#define IR_RX_CNT_OF_INT_CLR_Pos        (2UL)
#define IR_RX_CNT_OF_INT_CLR_Msk        (0x1UL << IR_RX_CNT_OF_INT_CLR_Pos)
/* RX_INT_CLR[1] :IR_RX_FIFO_LEVEL_INT_CLR. Write 1 clear. */
#define IR_RX_FIFO_LEVEL_INT_CLR_Pos    (1UL)
#define IR_RX_FIFO_LEVEL_INT_CLR_Msk    (0x1UL << IR_RX_FIFO_LEVEL_INT_CLR_Pos)
/* RX_INT_CLR[0] :IR_RX_FIFO_FULL_INT_CLR. Write 1 clear. */
#define IR_RX_FIFO_FULL_INT_CLR_Pos     (0UL)
#define IR_RX_FIFO_FULL_INT_CLR_Msk     (0x1UL << IR_RX_FIFO_FULL_INT_CLR_Pos)

#define IR_RX_INT_ALL_CLR               (IR_RX_FIFO_CLR_Msk | IR_RX_FIFO_ERROR_INT_CLR_Msk | \
                                         IR_RX_CNT_THR_INT_CLR_Msk | IR_RX_FIFO_OF_INT_CLR_Msk | \
                                         IR_RX_CNT_OF_INT_CLR_Msk | IR_RX_FIFO_LEVEL_INT_CLR_Msk | \
                                         IR_RX_FIFO_FULL_INT_CLR_Msk|IR_RX_RISING_EDGE_INT_CLR_Msk|IR_RX_FALLING_EDGE_INT_CLR_Msk)

/* Register: RX_CNT_INT_SEL -------------------------------------------------*/
/* Description: IR RX counter interrupt setting register. Offset: 0x24. Address: 0x40015824. */

/* RX_CNT_INT_SEL[31] :IR_RX_CNT_THR_TRIGGER_LV. */
/* 0x1: high level couner >= threshlod trigger interrupt. 0x0: low level couner >= threshlod trigger interrupt. */
#define IR_RX_CNT_THR_TYPE_Pos          (31UL)
#define IR_RX_CNT_THR_TYPE_Msk          (0x1UL << IR_RX_CNT_THR_TYPE_Pos)
#define IR_RX_CNT_THR_TYPE_CLR          (~IR_RX_CNT_THR_TYPE_Msk)
/* RX_CNT_INT_SEL[30:0] :IR_RX_CNT_THR. */
#define IR_RX_CNT_THR_Pos               (0UL)
#define IR_RX_CNT_THR_Msk               (0x7fffffffUL << IR_RX_CNT_THR_Pos)
#define IR_RX_CNT_THR_CLR               (~IR_RX_CNT_THR_Msk)

/* Register: RX_INT_CR -------------------------------------------------*/
/* Description: IR RX interrupt config register. Offset: 0x34. Address: 0x40015834. */

/* RX_INT_CR[5] :IR_RX_RISING_EDGE_INT_STATUS. */
#define IR_RX_RISING_EDGE_INT_STATUS_Pos    (5UL)
#define IR_RX_RISING_EDGE_INT_STATUS_Msk    (0x1UL << IR_RX_RISING_EDGE_INT_STATUS_Pos)
#define IR_RX_RISING_EDGE_INT_STATUS_CLR    (~IR_RX_RISING_EDGE_INT_STATUS_Msk)
/* RX_INT_CR[4] :IR_RX_FALLING_EDGE_INT_STATUS. */
#define IR_RX_FALLING_EDGE_INT_STATUS_Pos   (4UL)
#define IR_RX_FALLING_EDGE_INT_STATUS_Msk   (0x1UL << IR_RX_FALLING_EDGE_INT_STATUS_Pos)
#define IR_RX_FALLING_EDGE_INT_STATUS_CLR   (~IR_RX_FALLING_EDGE_INT_STATUS_Msk)
/* RX_INT_CR[3] :IR_RX_RISING_EDGE_INT_MASK. */
#define IR_RX_RISING_EDGE_INT_MASK_Pos      (3UL)
#define IR_RX_RISING_EDGE_INT_MASK_Msk      (0x1UL << IR_RX_RISING_EDGE_INT_MASK_Pos)
#define IR_RX_RISING_EDGE_INT_MASK_CLR      (~IR_RX_RISING_EDGE_INT_MASK_Msk)
/* RX_INT_CR[2] :IR_RX_FALLING_EDGE_INT_MASK. */
#define IR_RX_FALLING_EDGE_INT_MASK_Pos     (2UL)
#define IR_RX_FALLING_EDGE_INT_MASK_Msk     (0x1UL << IR_RX_FALLING_EDGE_INT_MASK_Pos)
#define IR_RX_FALLING_EDGE_INT_MASK_CLR     (~IR_RX_FALLING_EDGE_INT_MASK_Msk)
/* RX_INT_CR[1] :IR_RX_RISING_EDGE_INT_EN. */
#define IR_RX_RISING_EDGE_INT_EN_Pos        (1UL)
#define IR_RX_RISING_EDGE_INT_EN_Msk        (0x1UL << IR_RX_RISING_EDGE_INT_EN_Pos)
#define IR_RX_RISING_EDGE_INT_EN_CLR        (~IR_RX_RISING_EDGE_INT_EN_Msk)
/* RX_INT_CR[0] :IR_RX_FALLING_EDGE_INT_EN. */
#define IR_RX_FALLING_EDGE_INT_EN_Pos       (0UL)
#define IR_RX_FALLING_EDGE_INT_EN_Msk       (0x1UL << IR_RX_FALLING_EDGE_INT_EN_Pos)
#define IR_RX_FALLING_EDGE_INT_EN_CLR       (~IR_RX_FALLING_EDGE_INT_EN_Msk)

#define IR_RX_EXTENSION_INT                 0x8000

/* Register: DMA_CONFIG -------------------------------------------------*/
/* Description: IR dma config register. Offset: 0x50. Address: 0x40015850. */

/* DMA_CONFIG[0] : IR_TX_DMA_ENABLE. */
#define IR_TX_DMA_EN_Pos                (0UL)
#define IR_TX_DMA_EN_Msk                (0x1UL << IR_TX_DMA_EN_Pos)
#define IR_TX_DMA_EN_CLR                (~IR_TX_DMA_EN_Msk)
/* DMA_CONFIG[6:1] : IR_TX_WATER_LEVEL. */
#define IR_TX_WATER_LEVEL_Pos           (1UL)
#define IR_TX_WATER_LEVEL_Msk           (0x3FUL << IR_TX_WATER_LEVEL_Pos)
#define IR_TX_WATER_LEVEL_CLR           (~IR_TX_WATER_LEVEL_Msk)
/* DMA_CONFIG[8] : IR_RX_DMA_ENABLE. */
#define IR_RX_DMA_EN_Pos                (8UL)
#define IR_RX_DMA_EN_Msk                (0x1UL << IR_RX_DMA_EN_Pos)
#define IR_RX_DMA_EN_CLR                (~IR_RX_DMA_EN_Msk)
/* DMA_CONFIG[14:9] : IR_RX_WATER_LEVEL. */
#define IR_RX_WATER_LEVEL_Pos           (9UL)
#define IR_RX_WATER_LEVEL_Msk           (0x3FUL << IR_RX_WATER_LEVEL_Pos)
#define IR_RX_WATER_LEVEL_CLR           (~IR_RX_WATER_LEVEL_Msk)


/*============================================================================*
 *                         Constants
 *============================================================================*/
/**
 * \defgroup    IR_Exported_Constants   IR Exported Constants
 * \{
 * \ingroup     IR
 */

/**
 * \defgroup    IR_FIFO_SIZE    IR FIFO SIZE
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IS_IR_PERIPH(PERIPH) ((PERIPH) == IR)
#define IR_TX_FIFO_SIZE                   32
#define IR_RX_FIFO_SIZE                   32
/** \} */

/**
 * \defgroup    IR_CLOCK    IR Clock
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IR_CLOCK_40M                                (40000000)
#define IR_CLOCK_90M                                (90000000)
#define IR_CLOCK_100M                               (100000000)

#define IS_IR_CLOCK(CLK) (((CLK) == IR_CLOCK_40M)\
                          || ((CLK) == IR_CLOCK_90M)\
                          || ((CLK) == IR_CLOCK_100M))

#define IS_IR_FREQUENCY_40M(F) (((F) >= 2442) && ((F) <= 2000000))
#define IS_IR_FREQUENCY_90M(F) (((F) >= 5494) && ((F) <= 2000000))
#define IS_IR_FREQUENCY_100M(F) (((F) >= 6104) && ((F) <= 2000000))
/** \} */

/**
 * \defgroup    IR_Mode IR Mode
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IR_MODE_TX                                  ((uint32_t)((uint32_t)0x0 << IR_MODE_SEL_Pos))
#define IR_MODE_RX                                  ((uint32_t)((uint32_t)0x1 << IR_MODE_SEL_Pos))

#define IS_IR_MODE(MODE) (((MODE) == IR_MODE_TX) || ((MODE) == IR_MODE_RX))
/** \} */

/**
 * \defgroup    IR_Idle_Status IR Idle Status
 * \{
 * \ingroup     IR_Exported_Constants
 */

#define IR_IDLE_OUTPUT_HIGH                         ((uint32_t)(0x01 << IR_TX_IDLE_STATE_Pos))
#define IR_IDLE_OUTPUT_LOW                          ((uint32_t)(0x00 << IR_TX_IDLE_STATE_Pos))

#define IS_IR_IDLE_STATUS(LEVEL) (((LEVEL) == IR_IDLE_OUTPUT_HIGH) || ((LEVEL) == IR_IDLE_OUTPUT_LOW))
/** \} */

/**
 * \defgroup    IR_TX_Data_Type IR TX Data Type
 * \{
 * \ingroup     IR_Exported_Constants
 */

#define IR_TX_DATA_NORMAL                           ((uint32_t)(0 << IR_FIFO_INVERSE_Pos))
#define IR_TX_DATA_INVERSE                          ((uint32_t)(1 << IR_FIFO_INVERSE_Pos))

#define IS_IR_TX_DATA_TYPE(TYPE) (((TYPE) == IR_TX_DATA_NORMAL) || ((TYPE) == IR_TX_DATA_INVERSE))
/** \} */

/**
 * \defgroup     IR_Tx_Threshold IR TX Threshold
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IS_IR_TX_THRESHOLD(THD)  ((THD) < IR_TX_FIFO_SIZE)
/** \} */

/**
 * \defgroup     IR_Rx_Threshold IR RX Threshold
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IS_IR_RX_THRESHOLD(THD) ((THD) < IR_RX_FIFO_SIZE)
/** \} */

/**
 * \defgroup    IR_Rx_Start_Mode IR RX Start Mode
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IR_RX_AUTO_MODE                             ((uint32_t)((0x1) << IR_RX_START_MODE_Pos))
#define IR_RX_MANUAL_MODE                           ((uint32_t)((0x0) << IR_RX_START_MODE_Pos))

#define IS_RX_START_MODE(MODE) (((MODE) == IR_RX_AUTO_MODE) || ((MODE) == IR_RX_MANUAL_MODE))
/** \} */

/**
 * \defgroup    IR_RX_Trigger_Mode IR RX Trigger Mode
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IR_RX_FALL_EDGE                             ((uint32_t)((0x0) << IR_TRIGGER_MODE_Pos))
#define IR_RX_RISING_EDGE                           ((uint32_t)((0x1) << IR_TRIGGER_MODE_Pos))
#define IR_RX_DOUBLE_EDGE                           ((uint32_t)((0x2) << IR_TRIGGER_MODE_Pos))

#define IS_RX_RX_TRIGGER_EDGE(EDGE) (((EDGE) == IR_RX_FALL_EDGE) || ((EDGE) == IR_RX_RISING_EDGE) || ((EDGE) == IR_RX_DOUBLE_EDGE))
/** \} */

/**
 * \defgroup    IR_RX_FIFO_DISCARD_SETTING IR RX FIFO Discard Setting
 * \{
 * \ingroup     IR_Exported_Constants
 */

#define IR_RX_FIFO_FULL_DISCARD_NEWEST              ((uint32_t)(0 << IR_RX_FIFO_DISCARD_SET_Pos))
#define IR_RX_FIFO_FULL_DISCARD_OLDEST              ((uint32_t)(1 << IR_RX_FIFO_DISCARD_SET_Pos))

#define IS_IR_RX_FIFO_FULL_CTRL(CTRL)  (((CTRL) == IR_RX_FIFO_FULL_DISCARD_NEWEST) || ((CTRL) == IR_RX_FIFO_FULL_DISCARD_OLDEST))
/** \} */

/**
 * \defgroup    IR_RX_Filter_Time IR RX Filter Time
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IR_RX_FILTER_TIME_50ns                      ((uint32_t)((0x0) << IR_FILTER_TIME_Pos))
#define IR_RX_FILTER_TIME_75ns                      ((uint32_t)((0x2) << IR_FILTER_TIME_Pos))
#define IR_RX_FILTER_TIME_100ns                     ((uint32_t)((0x3) << IR_FILTER_TIME_Pos))
#define IR_RX_FILTER_TIME_125ns                     ((uint32_t)((0x4) << IR_FILTER_TIME_Pos))
#define IR_RX_FILTER_TIME_150ns                     ((uint32_t)((0x5) << IR_FILTER_TIME_Pos))
#define IR_RX_FILTER_TIME_175ns                     ((uint32_t)((0x6) << IR_FILTER_TIME_Pos))
#define IR_RX_FILTER_TIME_200ns                     ((uint32_t)((0x7) << IR_FILTER_TIME_Pos))

#define IS_IR_RX_FILTER_TIME_CTRL(CTRL)  (((CTRL) == IR_RX_FILTER_TIME_50ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_75ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_100ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_125ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_150ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_175ns) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_200ns))
/** \} */

/**
 * \defgroup    IR_RX_COUNTER_THRESHOLD_TYPE IR RX Counter Threshold Type
 * \{
 * \ingroup     IR_Exported_Constants
 */

#define IR_RX_Count_Low_Level                       ((uint32_t)0 << IR_RX_CNT_THR_TYPE_Pos)
#define IR_RX_Count_High_Level                      ((uint32_t)1 << IR_RX_CNT_THR_TYPE_Pos)

#define IS_IR_RX_COUNT_LEVEL_CTRL(CTRL)  (((CTRL) == IR_RX_Count_Low_Level) || ((CTRL) == IR_RX_Count_High_Level))
/** \} */

/**
 * \defgroup    IR_Rx_Counter_Threshold IR RX Counter Threshold
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IS_IR_RX_COUNTER_THRESHOLD(THD) ((THD) <= IR_RX_CNT_THR_Msk)
/** \} */

/**
 * \defgroup    IR_Interrupt_Definition IR Interrupt Definition
 * \{
 * \ingroup     IR_Exported_Constants
 */
/* All interrupts in transmission mode */
#define IR_INT_TF_EMPTY                             ((uint32_t)IR_TX_FIFO_EMPTY_INT_EN_Msk)
#define IR_INT_TF_LEVEL                             ((uint32_t)IR_TX_FIFO_LEVEL_INT_EN_Msk)
#define IR_INT_TF_OF                                ((uint32_t)IR_TX_FIFO_OVER_INT_EN_Msk)
#define IR_INT_TX_FINISH                            ((uint32_t)IR_TX_FINISH_INT_EN_Msk)
/* All interrupts in receiving mode */
#define IR_INT_RF_FULL                              ((uint32_t)IR_RX_FIFO_FULL_INT_Msk)
#define IR_INT_RF_LEVEL                             ((uint32_t)IR_RX_FIFO_LEVEL_INT_Msk)
#define IR_INT_RX_CNT_OF                            ((uint32_t)IR_RX_CNT_OF_INT_Msk)
#define IR_INT_RF_OF                                ((uint32_t)IR_RX_FIFO_OF_INT_Msk)
#define IR_INT_RX_CNT_THR                           ((uint32_t)IR_RX_CNT_THR_INT_Msk)
#define IR_INT_RF_ERROR                             ((uint32_t)IR_RX_FIFO_ERROR_INT_Msk)
#define IR_INT_RISING_EDGE                          ((uint32_t)(IR_RX_EXTENSION_INT | IR_RX_RISING_EDGE_INT_EN_Msk))
#define IR_INT_FALLING_EDGE                         ((uint32_t)(IR_RX_EXTENSION_INT | IR_RX_FALLING_EDGE_INT_EN_Msk))

#define IS_IR_TX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_TF_EMPTY)   || \
                                       ((CONFIG) == IR_INT_TF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_TF_OF)      || \
                                       ((CONFIG) == IR_INT_TX_FINISH))

#define IS_IR_RX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_RF_FULL)     || \
                                       ((CONFIG) == IR_INT_RF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_RX_CNT_OF)  || \
                                       ((CONFIG) == IR_INT_RF_OF)      || \
                                       ((CONFIG) == IR_INT_RX_CNT_THR) || \
                                       ((CONFIG) == IR_INT_RF_OF)      || \
                                       ((CONFIG) == IR_INT_RISING_EDGE) || \
                                       ((CONFIG) == IR_INT_FALLING_EDGE))
#define IS_IR_INT_CONFIG(CONFIG)      (IS_IR_TX_INT_CONFIG(CONFIG) || IS_IR_RX_INT_CONFIG(CONFIG))
/** \} */

/**
 * \defgroup   IR_Interrupts_Clear_Flag IR Interrupts Clear Flag
 * \{
 * \ingroup    IR_Exported_Constants
 */
/* Clear all interrupts in transmission mode */
#define IR_INT_TF_EMPTY_CLR                                 ((uint32_t)IR_TX_FIFO_EMPTY_INT_CLR_Msk)
#define IR_INT_TF_LEVEL_CLR                                 ((uint32_t)IR_TX_FIFO_LEVEL_INT_CLR_Msk)
#define IR_INT_TF_OF_CLR                                    ((uint32_t)IR_TX_FIFO_OVER_INT_CLR_Msk)
#define IR_INT_TX_FINISH_CLR                                ((uint32_t)IR_TX_FINISH_INT_CLR_Msk)
/* Clear all interrupts in receiving mode */
#define IR_INT_RF_FULL_CLR                                  ((uint32_t)IR_RX_FIFO_FULL_INT_CLR_Msk)
#define IR_INT_RF_LEVEL_CLR                                 ((uint32_t)IR_RX_FIFO_LEVEL_INT_CLR_Msk)
#define IR_INT_RX_CNT_OF_CLR                                ((uint32_t)IR_RX_CNT_OF_INT_CLR_Msk)
#define IR_INT_RF_OF_CLR                                    ((uint32_t)IR_RX_FIFO_OF_INT_CLR_Msk)
#define IR_INT_RX_CNT_THR_CLR                               ((uint32_t)IR_RX_CNT_THR_INT_CLR_Msk)
#define IR_INT_RF_ERROR_CLR                                 ((uint32_t)IR_RX_FIFO_ERROR_INT_CLR_Msk)
#define IR_INT_RX_RISING_EDGE_CLR                           ((uint32_t)IR_RX_RISING_EDGE_INT_CLR_Msk)
#define IR_INT_RX_FALLING_EDGE_CLR                          ((uint32_t)IR_RX_FALLING_EDGE_INT_CLR_Msk)
#define IR_RF_CLR                                           ((uint32_t)IR_RX_FIFO_CLR_Msk)

#define IS_IR_INT_CLEAR(INT)            (((INT) == IR_INT_TF_EMPTY_CLR) || ((INT) == IR_INT_TF_LEVEL_CLR) || \
                                         ((INT) == IR_INT_TF_OF_CLR) || ((INT) == IR_INT_RF_FULL_CLR) || \
                                         ((INT) == IR_INT_RF_LEVEL_CLR) || ((INT) == IR_INT_RX_CNT_OF_CLR) || \
                                         ((INT) == IR_INT_RF_OF_CLR) || ((INT) == IR_INT_RX_CNT_THR_CLR) || \
                                         ((INT) == IR_INT_RX_RISING_EDGE_CLR) || ((INT) == IR_INT_RX_FALLING_EDGE_CLR) || \
                                         ((INT) == IR_INT_RF_ERROR_CLR) || (INT) == IR_INT_TX_FINISH_CLR)
/** \} */

/**
 * \defgroup    IR_Flag IR Flag
 * \{
 * \ingroup     IR_Exported_Constants
 */
#define IR_FLAG_TF_EMPTY                                    ((uint32_t)IR_TX_FIFO_EMPTY_Msk)
#define IR_FLAG_TF_FULL                                     ((uint32_t)IR_TX_FIFO_FULL_Msk)
#define IR_FLAG_TX_RUN                                      ((uint32_t)IR_TX_STATUS_Msk)
#define IR_FLAG_RF_EMPTY                                    ((uint32_t)IR_RX_FIFO_EMPTY_Msk)
#define IR_FLAG_RF_FULL                                     ((uint32_t)IR_RX_FIFO_FULL_Msk)
#define IR_FLAG_RX_RUN                                      ((uint32_t)IR_RX_STATUS_Msk)

#define IS_IR_FLAG(FLAG)                (((FLAG) == IR_FLAG_TF_EMPTY) || ((FLAG) == IR_FLAG_TF_FULL) || \
                                         ((FLAG) == IR_FLAG_TX_RUN) || ((FLAG) == IR_FLAG_RF_EMPTY) || \
                                         ((FLAG) == IR_FLAG_RF_FULL) || ((FLAG) == IR_FLAG_RX_RUN))
/** \} */

/**
 * \defgroup    IR_Compensation_Flag IR Compensation Flag
 * \{
 * \ingroup     IR_Exported_Constants
 */
typedef enum
{
    IR_COMPEN_FLAG_1_2_CARRIER = ((uint32_t)(1 << IR_LOW_PERIOD_COMPENSATION_Pos)),
    IR_COMPEN_FLAG_1_4_CARRIER = ((uint32_t)(2 << IR_LOW_PERIOD_COMPENSATION_Pos)),
    IR_COMPEN_FLAG_1_N_SYSTEM_CLK = ((uint32_t)(3 << IR_LOW_PERIOD_COMPENSATION_Pos)),
} IR_TX_COMPEN_TYPE;
/** \} */

/** End of IR_Exported_Constants
  * \}
  */
/*============================================================================*
 *                         Functions
 *============================================================================*/
/**
 * \defgroup    IR_Exported_Functions   IR Exported Functions
 * \{
 * \ingroup     IR
 */

/**
 * \brief  Deinitialize the IR peripheral registers to their default values.
 * \param[in]  None.
 * \return None.
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
 * \brief   Initialize the IR peripheral according to the specified
 *          parameters in IR_InitStruct.
 * \param[in] IR_InitStruct: Pointer to an IR_InitTypeDef structure that
 *            contains the configuration information for the specified IR peripheral.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_ir_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);

 *     IR_InitTypeDef IR_InitStruct;
 *     IR_StructInit(&IR_InitStruct);

 *     IR_InitStruct.IR_Freq               = 38000;// IR carrier frequency is 38KHz
 *     IR_InitStruct.IR_Mode               = IR_MODE_RX;// IR receiving mode
 *     IR_InitStruct.IR_RxStartMode        = IR_RX_AUTO_MODE;
 *     IR_InitStruct.IR_RxFIFOThrLevel     =
         IR_RX_FIFO_THR_LEVEL; // Configure RX FIFO threshold level to trigger IR_INT_RF_LEVEL interrupt
 *     IR_InitStruct.IR_RxFIFOFullCtrl     =
 *         IR_RX_FIFO_FULL_DISCARD_NEWEST;// Discard the latest received data if RX FIFO is full
 *     IR_InitStruct.IR_RxFilterTime       =
        IR_RX_FILTER_TIME_50ns;// If high to low or low to high transition time <= 50ns, filter it out.
 *     IR_InitStruct.IR_RxTriggerMode      = IR_RX_FALL_EDGE;// Configure trigger type
 *     IR_InitStruct.IR_RxCntThrType       =
        IR_RX_Count_High_Level;// IR_RX_Count_High_Level is counting high level
 *     IR_InitStruct.IR_RxCntThr           =
        0x1F40;// Configure RX counter threshold. This can be used to decide when to stop receiving IR data
 *     IR_Init(&IR_InitStruct);
 *     IR_Cmd(IR_MODE_RX, ENABLE);
 *     IR_ClearRxFIFO();
 * }
 * \endcode
 */
void IR_Init(IR_InitTypeDef *IR_InitStruct);

/**
 * \brief  Fill each IR_InitStruct member with its default value.
 * \param[in] IR_InitStruct: Pointer to an IR_InitTypeDef structure which will be initialized.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_ir_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);

 *     IR_InitTypeDef IR_InitStruct;
 *     IR_StructInit(&IR_InitStruct);

 *     IR_InitStruct.IR_Freq               = 38000;// IR carrier frequency is 38KHz
 *     IR_InitStruct.IR_Mode               = IR_MODE_RX;// IR receiving mode
 *     IR_InitStruct.IR_RxStartMode        = IR_RX_AUTO_MODE;
 *     IR_InitStruct.IR_RxFIFOThrLevel     =
         IR_RX_FIFO_THR_LEVEL; // Configure RX FIFO threshold level to trigger IR_INT_RF_LEVEL interrupt
 *     IR_InitStruct.IR_RxFIFOFullCtrl     =
 *         IR_RX_FIFO_FULL_DISCARD_NEWEST;// Discard the latest received data if RX FIFO is full
 *     IR_InitStruct.IR_RxFilterTime       =
        IR_RX_FILTER_TIME_50ns;// If high to low or low to high transition time <= 50ns, filter it out.
 *     IR_InitStruct.IR_RxTriggerMode      = IR_RX_FALL_EDGE;// Configure trigger type
 *     IR_InitStruct.IR_RxCntThrType       =
        IR_RX_Count_High_Level;// IR_RX_Count_High_Level is counting high level
 *     IR_InitStruct.IR_RxCntThr           =
        0x1F40;// Configure RX counter threshold. This can be used to decide when to stop receiving IR data
 *     IR_Init(&IR_InitStruct);
 *     IR_Cmd(IR_MODE_RX, ENABLE);
 *     IR_ClearRxFIFO();
 * }
 * \endcode
 */
void IR_StructInit(IR_InitTypeDef *IR_InitStruct);

/**
 * \brief   Enable or disable the selected IR mode.
 * \param[in] mode: Selected IR operation mode.
 *      This parameter can be one of the following values:
 *      \arg IR_MODE_TX: Transmission mode.
 *      \arg IR_MODE_RX: Receiving mode.
 * \param[in] NewState: New state of the operation mode.
 *      This parameter can be: ENABLE or DISABLE.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_ir_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_IR, APBPeriph_IR_CLOCK, ENABLE);

 *     IR_InitTypeDef IR_InitStruct;
 *     IR_StructInit(&IR_InitStruct);

 *     IR_InitStruct.IR_Freq               = 38000;// IR carrier frequency is 38KHz
 *     IR_InitStruct.IR_Mode               = IR_MODE_RX;// IR receiving mode
 *     IR_InitStruct.IR_RxStartMode        = IR_RX_AUTO_MODE;
 *     IR_InitStruct.IR_RxFIFOThrLevel     =
         IR_RX_FIFO_THR_LEVEL; // Configure RX FIFO threshold level to trigger IR_INT_RF_LEVEL interrupt
 *     IR_InitStruct.IR_RxFIFOFullCtrl     =
 *         IR_RX_FIFO_FULL_DISCARD_NEWEST;// Discard the latest received data if RX FIFO is full
 *     IR_InitStruct.IR_RxFilterTime       =
        IR_RX_FILTER_TIME_50ns;// If high to low or low to high transition time <= 50ns, filter it out.
 *     IR_InitStruct.IR_RxTriggerMode      = IR_RX_FALL_EDGE;// Configure trigger type
 *     IR_InitStruct.IR_RxCntThrType       =
        IR_RX_Count_High_Level;// IR_RX_Count_High_Level is counting high level
 *     IR_InitStruct.IR_RxCntThr           =
        0x1F40;// Configure RX counter threshold. This can be used to decide when to stop receiving IR data
 *     IR_Init(&IR_InitStruct);
 *     IR_Cmd(IR_MODE_RX, ENABLE);
 *     IR_ClearRxFIFO();
 * }
 * \endcode
 */
void IR_Cmd(uint32_t mode, FunctionalState NewState);

/**
 * \brief   Start trigger receive, only in manual receive mode.
 * \param[in]   None.
 * \return  None.
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
 * \brief   Config counter threshold value in receiving mode. It can be used to stop receiving IR data.
 * \param[in] IR_RxCntThrType: Count threshold type.
 *      This parameter can be the following values:
 *      \arg IR_RX_Count_Low_Level: Low level counter value >= IR_RxCntThr, trigger IR_INT_RX_CNT_THR interrupt.
 *      \arg IR_RX_Count_High_Level: High level counter value >= IR_RxCntThr, trigger IR_INT_RX_CNT_THR interrupt.
 * \param[in] IR_RxCntThr: Configure IR Rx counter threshold value which can be 0 to 0x7fffffff.
 * \return  None.
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
 * \brief   Send data buffer.
 * \param[in] pBuf: Data buffer to send.
 * \param[in] len: Send data length.
 * \param[in] IsLastPacket: Is it the last package of data.
 *      This parameter can be one of the following values:
 *      \arg ENABLE: The last data in IR packet and there is no continuous data. In other words, an infrared data transmission is completed.
 *      \arg DISABLE: There is data to be transmitted continuously.
 * \return None.
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
void IR_SendBuf(const uint32_t *pBuf, uint32_t len, FunctionalState IsLastPacket);

/**
 * \brief  Send compensation data.
 * \param[in] comp_type: Compensation data type.
 *      This parameter can be one of the following values:
 *     \arg IR_COMPEN_FLAG_1_2_CARRIER: 1/2 carrier frequency.
 *     \arg IR_COMPEN_FLAG_1_4_CARRIER: 1/4 carrier frequency.
 *     \arg IR_COMPEN_FLAG_1_N_SYSTEM_CLK: MOD((0x48[27:16]+0x00[11:0]), 4095)/40MHz.
            User can call function of IR_ConfigCompParam to configure 0x48[27:16].
 * \param[in] buf: Data buffer to send.
 * \param[in] length: Data length.
 * \param[in] IsLastPacket: Is it the last package of data.
 *      This parameter can be the following values:
 *     \arg ENABLE: The last data in IR packet and there is no continuous data. In other words, an infrared data transmission is completed.
 *     \arg DISABLE: There is data to be transmitted continuously.
 * \return None.
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
void IR_SendCompenBuf(IR_TX_COMPEN_TYPE comp_type, uint32_t *pBuf, uint32_t len,
                      FunctionalState IsLastPacket);

/**
 * \brief   Read data From RX FIO.
 * \param[in] pBuf: Buffer address to receive data.
 * \param[in] length: Read data length.
 * \return None.
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
 * \brief     Enable or disable the specified IR interrupt source.
 * \param[in] IR_INT: Specify the IR interrupt source to be enabled or disabled.
 *            This parameter can be one of the following values:
 *            \arg IR_INT_TF_EMPTY: When TX FIFO is empty, TX FIFO Empty Interrupt will be triggered.
 *            \arg IR_INT_TF_LEVEL: When TX FIFO offset <= threshold value, trigger TX FIFO Level Interrupt.
 *            \arg IR_INT_TF_OF: When TX FIFO is full, data continues to be written to TX FIFO, TX FIFO Over interrupt will be triggered.
 *            \arg IR_INT_TX_FINISH: When TX finished, TX Finish Interrupt will be triggered.
 *            \arg IR_INT_RF_FULL: When RX FIFO offset = 32, RX FIFO Full Interrupt will be triggered.
 *            \arg IR_INT_RF_LEVEL: When RX FIFO offset > threshold value, trigger RX FIFO Level Interrupt.
 *            \arg IR_INT_RX_CNT_OF: When RX counter overflows, RX counter overflow interrupt will be triggered.
 *            \arg IR_INT_RF_OF: When RX FIFO is full and continues to be written, RX FIFO overflow interrupt will be triggered.
 *            \arg IR_INT_RX_CNT_THR: When RX counter >= IR_RX_CNT_THR, RX Counter Threshold Interrupt will be triggered.
 *            \arg IR_INT_RF_ERROR: When RX FIFO is empty and continues to be read, RX FIFO error read interrupt will be triggered.
 *            \arg IR_INT_RISING_EDGE: When RX FIFO receives a low to high pulse, RX Rising Edge Interrupt will be triggered.
 *            \arg IR_INT_FALLING_EDGE: When RX FIFO receives a high to low pulse, RX Falling Edge Interrupt will be triggered.
 * \param[in]  newState: New state of the specified IR interrupt.
 *      This parameter can be: ENABLE or DISABLE.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_INTConfig(IR_INT_TF_EMPTY, ENABLE);
 * }
 * \endcode
 */
void IR_INTConfig(uint32_t IR_INT, FunctionalState newState);

/**
 * \brief     Mask or unmask the specified IR interrupt source.
 * \param[in] IR_INT: Specify the IR interrupts sources to be masked or unmasked.
 *            This parameter can be the following values:
 *            \arg IR_INT_TF_EMPTY: When TX FIFO is empty, TX FIFO Empty Interrupt will be triggered.
 *            \arg IR_INT_TF_LEVEL: When TX FIFO offset <= threshold value, trigger TX FIFO Level Interrupt.
 *            \arg IR_INT_TF_OF: When TX FIFO is full, data continues to be written to TX FIFO, TX FIFO Over interrupt will be triggered.
 *            \arg IR_INT_TX_FINISH: When TX finished, TX Finish Interrupt will be triggered.
 *            \arg IR_INT_RF_FULL: When RX FIFO offset = 32, RX FIFO Full Interrupt will be triggered.
 *            \arg IR_INT_RF_LEVEL: When RX FIFO offset > threshold value, trigger RX FIFO Level Interrupt.
 *            \arg IR_INT_RX_CNT_OF: When RX counter overflows, RX counter overflow interrupt will be triggered.
 *            \arg IR_INT_RF_OF: When RX FIFO is full and continues to be written, RX FIFO overflow interrupt will be triggered.
 *            \arg IR_INT_RX_CNT_THR: When RX counter >= IR_RX_CNT_THR, RX Counter Threshold Interrupt will be triggered.
 *            \arg IR_INT_RF_ERROR: When RX FIFO is empty and continues to be read, RX FIFO error read interrupt will be triggered.
 *            \arg IR_INT_RISING_EDGE: When RX FIFO receives a low to high pulse, RX Rising Edge Interrupt will be triggered.
 *            \arg IR_INT_FALLING_EDGE: When RX FIFO receives a high to low pulse, RX Falling Edge Interrupt will be triggered.
 * \param[in] newState: New state of the specified IR interrupts.
 *            This parameter can be: ENABLE or DISABLE.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_MaskINTConfig(IR_INT_TF_EMPTY, ENABLE);
 * }
 * \endcode
 */
void IR_MaskINTConfig(uint32_t IR_INT, FunctionalState newState);

/**
 * \brief     Get the specified IR interrupt status.
 * \param[in] IR_INT: the specified IR interrupts.
 *            This parameter can be one of the following values:
 *            \arg IR_INT_TF_EMPTY: When TX FIFO is empty, TX FIFO Empty Interrupt will be triggered.
 *            \arg IR_INT_TF_LEVEL: When TX FIFO offset <= threshold value, trigger TX FIFO Level Interrupt.
 *            \arg IR_INT_TF_OF: When TX FIFO is full, data continues to be written to TX FIFO, TX FIFO Over interrupt will be triggered.
 *            \arg IR_INT_TX_FINISH: When TX finished, TX Finish Interrupt will be triggered.
 *            \arg IR_INT_RF_FULL: When RX FIFO offset = 32, RX FIFO Full Interrupt will be triggered.
 *            \arg IR_INT_RF_LEVEL: When RX FIFO offset > threshold value, trigger RX FIFO Level Interrupt.
 *            \arg IR_INT_RX_CNT_OF: When RX counter overflows, RX counter overflow interrupt will be triggered.
 *            \arg IR_INT_RF_OF: When RX FIFO is full and continues to be written, RX FIFO overflow interrupt will be triggered.
 *            \arg IR_INT_RX_CNT_THR: When RX counter >= IR_RX_CNT_THR, RX Counter Threshold Interrupt will be triggered.
 *            \arg IR_INT_RF_ERROR: When RX FIFO is empty and continues to be read, RX FIFO error read interrupt will be triggered.
 *            \arg IR_INT_RISING_EDGE: When RX FIFO receives a low to high pulse, RX Rising Edge Interrupt will be triggered.
 *            \arg IR_INT_FALLING_EDGE: When RX FIFO receives a high to low pulse, RX Falling Edge Interrupt will be triggered.
 * \return  The new state of IR_INT (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     ITStatus int_status = IR_GetINTStatus(IR_INT_TF_EMPTY);
 * }
 * \endcode
 */
ITStatus IR_GetINTStatus(uint32_t IR_INT);

/**
 * \brief     Clear the IR interrupt pending bit.
 * \param[in] IR_CLEAR_INT: Specify the interrupt pending bit to clear.
 *      This parameter can be any combination of the following values:
 *      \arg IR_INT_TF_EMPTY_CLR: Clear TX FIFO empty interrupt.
 *      \arg IR_INT_TF_LEVEL_CLR: Clear TX FIFO threshold interrupt.
 *      \arg IR_INT_TF_OF_CLR: Clear TX FIFO overflow interrupt.
 *      \arg IR_INT_TX_FINISH_CLR: Clear TX finish interrupt.
 *      \arg IR_INT_RF_FULL_CLR: Clear RX FIFO full interrupt.
 *      \arg IR_INT_RF_LEVEL_CLR: Clear RX FIFO threshold interrupt.
 *      \arg IR_INT_RX_CNT_OF_CLR: Clear RX counter overflow interrupt.
 *      \arg IR_INT_RF_OF_CLR: Clear RX FIFO overflow interrupt.
 *      \arg IR_INT_RX_CNT_THR_CLR: Clear RX counter threshold interrupt.
 *      \arg IR_INT_RF_ERROR_CLR: Clear RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *      \arg IR_INT_RX_RISING_EDGE_CLR: Clear RX Rising edge interrupt.
 *      \arg IR_INT_RX_FALLING_EDGE_CLR: Clear RX Falling edge interrupt.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_ClearINTPendingBit(IR_INT_RX_CNT_OF_CLR);
 * }
 * \endcode
 */
void IR_ClearINTPendingBit(uint32_t IR_CLEAR_INT);

/**
 * \brief  Get free size of TX FIFO.
 * \param[in]  None.
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
__STATIC_INLINE uint16_t IR_GetTxFIFOFreeLen(void)
{
    return (uint16_t)(IR_TX_FIFO_SIZE - ((IR->TX_SR & (IR_TX_FIFO_OFFSET_Msk)) >>
                                         IR_TX_FIFO_OFFSET_Pos));
}

/**
 * \brief   Get data size in RX FIFO.
 * \param[in]   None.
 * \return  Current data size in RX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint16_t data_len = IR_GetRxDataLen();
 * }
 * \endcode
 */
__STATIC_INLINE uint16_t IR_GetRxDataLen(void)
{
    return ((uint16_t)(((IR->RX_SR) & IR_RX_FIFO_OFFSET_Msk) >> IR_RX_FIFO_OFFSET_Pos));
}

/**
 * \brief   Send one data.
 * \param[in] data: Send data.
 * \return  None.
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
__STATIC_INLINE void IR_SendData(uint32_t data)
{
    IR->TX_FIFO = data;
}

/**
 * \brief   Read one data.
 * \param[in]   None.
 * \return  Data which is read from RX FIFO.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     uint32_t data = IR_ReceiveData(30);
 * }
 * \endcode
 */
__STATIC_INLINE uint32_t IR_ReceiveData(void)
{
    return IR->RX_FIFO;
}

/**
 * \brief  Set tx threshold, when TX FIFO depth <= threshold value trigger interrupt.
 * \param[in] thd: Tx threshold.
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     IR_SetTxThreshold(30);
 * }
 * \endcode
 */
__STATIC_INLINE void IR_SetTxThreshold(uint8_t thd)
{
    IR->TX_CONFIG &= IR_TX_FIFO_THRESHOLD_CLR;
    IR->TX_CONFIG |= (thd << IR_TX_FIFO_THRESHOLD_Pos);
}

/**
 * \brief   Set tx threshold, when RX FIFO depth > threshold value trigger interrupt.
 * \param[in] thd: Rx threshold.
 * \return  None.
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
__STATIC_INLINE void IR_SetRxThreshold(uint8_t thd)
{
    IR->RX_CONFIG &= IR_RX_FIFO_LEVEL_CLR;
    IR->RX_CONFIG |= (thd << IR_RX_FIFO_LEVEL_Pos);
}

/**
 * \brief  Get IR RX current count.
 * \param[in]  None.
 * \return Current counter.
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
__STATIC_INLINE uint32_t IR_GetRxCurrentCount(void)
{
    return IR->RX_CUR_CNT ;
}

/**
 * \brief  Clear IR TX FIFO.
 * \param[in]  None.
 * \return None.
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
__STATIC_INLINE void IR_ClearTxFIFO(void)
{
    IR->TX_INT_CLR = IR_TX_FIFO_CLR_Msk;
}

/**
 * \brief   Clear IR RX FIFO.
 * \param[in]   None.
 * \return  None.
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
__STATIC_INLINE void IR_ClearRxFIFO(void)
{
    IR->RX_INT_CLR = IR_RX_FIFO_CLR_Msk;
}

/**
 * \brief  Check whether the specified IR flag is set.
 * \param[in]  IR_FLAG: Specify the flag to check.
 *      This parameter can be one of the following values:
 *      \arg IR_FLAG_TF_EMPTY: TX FIFO empty or not. If SET, TX FIFO is empty.
 *      \arg IR_FLAG_TF_FULL: TX FIFO full or not. If SET, TX FIFO is full.
 *      \arg IR_FLAG_TX_RUN: TX run or not. If SET, TX is running.
 *      \arg IR_FLAG_RF_EMPTY: RX FIFO empty or not. If SET, RX FIFO is empty.
 *      \arg IR_FLAG_RF_FULL: RX FIFO full or not. If SET, RX FIFO is full.
 *      \arg IR_FLAG_RX_RUN: RX run or not. If SET, RX is running.
 * \return  The new state of IR_FLAG (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void ir_demo(void)
 * {
 *     FlagStatus flag_status = IR_GetFlagStatus(IR_FLAG_TF_EMPTY);
 * }
 * \endcode
 */
__STATIC_INLINE FlagStatus IR_GetFlagStatus(uint32_t IR_FLAG)
{
    FlagStatus bitstatus = RESET;

    /* Check the parameters */
    assert_param(IS_IR_FLAG(IR_FLAG));

    if (IR->TX_CONFIG & IR_MODE_SEL_Msk)
    {
        if (IR->RX_SR & IR_FLAG)
        {
            bitstatus = SET;
        }
        return bitstatus;
    }
    else
    {
        if (IR->TX_SR & IR_FLAG)
        {
            bitstatus = SET;
        }
        return bitstatus;
    }
}

/**
 * \brief  Enable TX FIFO define or not.
 * \param[in] NewState: This parameter can be: ENABLE or DISABLE.
 * \return  None.
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
__STATIC_INLINE void IR_SetTxInverse(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        IR->TX_CONFIG |= IR_FIFO_INVERSE_Msk;
    }
    else
    {
        IR->TX_CONFIG &= IR_FIFO_INVERSE_CLR;
    }
}

/**
 * \brief  Enable TX active output inverse or not.
 * \param[in] NewState: This parameter can be: ENABLE or DISABLE.
 * \return None.
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
__STATIC_INLINE void IR_TxOutputInverse(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        IR->TX_CONFIG |= IR_OUTPUT_INVERSE_Msk;
    }
    else
    {
        IR->TX_CONFIG &= IR_OUTPUT_INVERSE_CLR;
    }
}

/**
 * \brief  Get IR RX Level.
 * \param[in]  None.
 * \return Current Level.
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
__STATIC_INLINE uint32_t IR_GetRxCurrentLevel(void)
{
    /* Check the parameters */
    return (IR->IR_RX_LEVEL);

}

/** End of IR_Exported_Functions
  * \}
  */

/** End of IR
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* _RTL876x_IR_H_ */



/******************* (C) COPYRIGHT 2024 Realtek Semiconductor Corporation *****END OF FILE****/

