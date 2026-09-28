/**
*********************************************************************************************************
*               Copyright(c) 2016, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     pingpong_buffer.h
* @brief    This file provides APIs of PingPong Buffer.
* @details
* @author   Lory Xu
* @date     2015-12-20
* @version  v0.1
*********************************************************************************************************
*/

#ifndef PINGPONG_BUFFER_H
#define PINGPONG_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*WriteFullCB)(void);

/** @brief LogMissedCounter records the number of log missed.
    If the value is greater then 0, please reduce logs or speed up log uart/DMA.
    */
typedef enum
{
    BLOCK_IDLE,
    BLOCK_WRITING,
    BLOCK_FULL,
    BLOCK_READING,
} PPB_BLOCK_STATUS;

typedef struct
{
    uint8_t  index;
    PPB_BLOCK_STATUS  status;
    uint16_t length;
} BlockM;

typedef struct
{
    BlockM *block_manage;
    WriteFullCB write_full_cb;
    uint8_t *start;
    uint16_t num_of_block;
    uint16_t size_of_block;
    uint16_t Threshold;
    uint16_t LogMissedCounter;
    uint8_t cur_write_index;
    uint8_t cur_read_index;
} PingpongBuffer;

extern bool (*PPB_Init)(PingpongBuffer *pPPB, WriteFullCB cb);
void PPB_Uninit(PingpongBuffer *pPPB);
void PPB_Init_DLPS_Restore(PingpongBuffer *pPPB);
extern bool (*PPB_Write)(PingpongBuffer *pPPB, const uint8_t *source, uint16_t size);
bool PPB_OutputUpdate(PingpongBuffer *pPPB, void **addr, uint16_t *length, bool is_contniue);
bool PPB_GetRecordData(PingpongBuffer *pPPB, void **addr, uint16_t *length);
bool Is_PPB_Empty(PingpongBuffer *pPPB);




#ifdef __cplusplus
}
#endif

#endif
