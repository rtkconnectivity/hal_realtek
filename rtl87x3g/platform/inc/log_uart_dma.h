/**
*********************************************************************************************************
*               Copyright(c) 2016, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     log_uart_dma.h
* @brief    This file provides APIs of log uart with DMA channel.
* @details
* @author   Lory Xu
* @date     2016-01-11
* @version  v0.1
*********************************************************************************************************
*/

#ifndef LOG_UART_DMA_H
#define LOG_UART_DMA_H

#include "pingpong_buffer.h"
#include "trace.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    STATE_LOG_DMA_IDLE = 0,
    STATE_LOG_DMA_PROCESS_MCU,
    STATE_LOG_DMA_PROCESS_DSP,
    STATE_LOG_DMA_PENDING_MCU,
    STATE_LOG_DMA_PENDING_DSP,
    STATE_LOG_DMA_MAX
} LogDMA_State;

typedef enum
{
    SIGNAL_LOG_DMA_MCU_REQUEST = 0,
    SIGNAL_LOG_DMA_DSP_REQUEST,
    SIGNAL_LOG_DMA_DONE,
    SIGNAL_LOG_DMA_MAX
} LogDMA_Signal;

typedef enum
{
    LOG_CHANNEL_UART0,
    LOG_CHANNEL_UART1,
    LOG_CHANNEL_UART2
} LogChannel_TypeDef;

typedef struct
{
    volatile LogDMA_State State;
    LogDMA_State LastState;
    uint32_t SavedDSP_ReadIndex;    /* Saved DSP read index */
    bool DspLogContinue;
} LogDMA_SM;

typedef struct
{
    uint32_t ReadIndex;     /* DSP uses ring buffer */
    uint32_t WriteIndex;
    uint8_t *Buffer;
    uint16_t BufferSize;    /* MCU uses ping pong buffer */
    LogDMA_Signal Signal;
} LogDMA_Evt;

extern PingpongBuffer *pMCU_PPB;
extern LogDMA_SM      *pLogDMA_SM;

extern void (*sys_timestamp_init)(void);
extern void (*timestamp_enter_dlps_cb)(void);
extern void (*sys_timestamp_exit)(void);
extern void (*log_uart_dma_init)(void);
extern void (*dsp_log_output)(void);
extern bool (*dsp_log_transport)(LogDMA_SM *me);
extern void (*log_dma_state_machine[])(LogDMA_SM *me,  LogDMA_Signal signal);
extern void (*log_uart_dma_idle_hook)(void);
extern void (*log_uart_dma_start)(uint8_t *p_outputbuf, uint16_t output_size);
extern bool (*log_pm_check)(void);
extern void (*log_pm_exit)(void);
extern void (*log_pm_enter)(void);
extern void (*log_dma_sm_dispatch)(LogDMA_SM *me, LogDMA_Signal signal);
extern void (*dump_dsp_log)(void);
extern bool (*get_dsp_log_buf)(uint32_t **buf, uint32_t *length, uint32_t *r_index_record,
                               bool *is_continue);
extern void (*dsp_log_output_done)(uint32_t r_index);
void log_uart_dma_isr(void);
bool log_buf_init(void);
bool is_log_dma_is_idle(void);

#ifdef __cplusplus
}
#endif

#endif
