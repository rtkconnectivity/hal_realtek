/**
 *****************************************************************************************
 *     Copyright(c) 2018, Realtek Semiconductor Corporation. All rights reserved.
 *****************************************************************************************
 * @file    flash_nor_driver.h
 * @brief   Nor flash driver implementation header file
 * @author  Yao-Yu
 * @date    2020-08-31
 * @version v0.1
 * ***************************************************************************************
 */

#ifndef _FLASH_NOR_DRIVER_H
#define _FLASH_NOR_DRIVER_H

#include "FreeRTOS.h"
#include "task.h"
#include "slist.h"
#include "flash_nor_basic.h"

/****************************************************************************************
 * Nor Flash Configuration
 ****************************************************************************************/
#define FLASH_NOR_FIXED_DMA_CHANNEL         0

/****************************************************************************************
 * Nor Flash Constrains
 ****************************************************************************************/
#define FLASH_NOR_IOCTL_MAX_BUF_LEN         0xFF
#define FLASH_NOR_NORMAL_READ_CLOCK_MAX     33300000

/****************************************************************************************
 * Nor Flash Enumeration
 ****************************************************************************************/
typedef enum
{
    FLASH_NOR_REQ_NONE              = 0x00,
    FLASH_NOR_REQ_READ              = 0x01,
    FLASH_NOR_REQ_WRITE             = 0x02,
    FLASH_NOR_REQ_RW_MASK           = 0x03,

    FLASH_NOR_REQ_ERASE_SECTOR      = 0x04,
    FLASH_NOR_REQ_ERASE_BLOCK       = 0x08,
    FLASH_NOR_REQ_ERASE_CHIP        = 0x10,
    FLASH_NOR_REQ_ERASE_MASK        = 0x1C,

    FLASH_NOR_REQ_DMA_READ          = 0x20,
    FLASH_NOR_REQ_DMA_WRITE         = 0x40,
    FLASH_NOR_REQ_DMA_MASK          = 0x60,

    FLASH_NOR_REQ_SET_BP            = 0x080,
    FLASH_NOR_REQ_SET_TB            = 0x100,
    FLASH_NOR_REQ_SET_BP_TB_MASK    = 0x180,
} FLASH_NOR_REQ_TYPE;

typedef enum
{
    FLASH_NOR_NODE_STATUS_IDLE,
    FLASH_NOR_NODE_STATUS_SUSPEND,
    FLASH_NOR_NODE_STATUS_BUSY,
} FLASH_NOR_CMD_NODE_STATUS_TYPE;

/****************************************************************************************
 * Nor Flash Callback Definition
 ****************************************************************************************/
typedef void (*FLASH_NOR_ASYNC_CB)(void);

/****************************************************************************************
 * Nor Flash Structure
 ****************************************************************************************/
typedef struct _FLASH_NOR_CMD_NODE_TYPE
{
    uint32_t addr;
    uint32_t len;
#ifndef _IS_BB_SERIES_
    uint8_t *data;              // for async write; make sure the address pointed by data still exists in flash task
#endif
    uint8_t dma_ch;             // in order to record the dma channel used by this node when multiple channel dma is applied
    TCB_t *owner;
    FLASH_NOR_IDX_TYPE idx;
    FLASH_NOR_REQ_TYPE req;
    FLASH_NOR_CMD_NODE_STATUS_TYPE status;
    FLASH_NOR_ASYNC_CB cb;
    TAILQ_ENTRY(struct _FLASH_NOR_CMD_NODE_TYPE) flash_cmd_list_entry;
} FLASH_NOR_CMD_NODE_TYPE;

TAILQ_HEAD(FLASH_NOR_CMD_LIST_TYPE, FLASH_NOR_CMD_NODE_TYPE);

/* *INDENT-OFF* */

/****************************************************************************************
 * Nor Flash Function Prototype
 ****************************************************************************************/
uint32_t flash_nor_get_addr_base(FLASH_NOR_IDX_TYPE idx);
void flash_nor_init_bp_lv(void);
void flash_nor_get_erase_range(FLASH_NOR_REQ_TYPE req, uint32_t *addr, uint32_t *len);
FLASH_NOR_RET_TYPE flash_nor_check_suspend_resume_support(FLASH_NOR_IDX_TYPE idx);
void flash_nor_auto_dma_handler(void);
void flash_nor_set_delay_chain(FLASH_NOR_IDX_TYPE idx, uint8_t delay_chain);

/****************************************************************************************
 * Nor Flash Extern Variables
 ****************************************************************************************/
extern SPIC_BACKUP_REG_TYPE *flash_nor_spic_backup[FLASH_NOR_IDX_MAX];
extern FLASH_NOR_CMD_LIST_TYPE flash_nor_free_list;
extern FLASH_NOR_CMD_LIST_TYPE flash_nor_work_list;
extern FLASH_NOR_CMD_NODE_TYPE *flash_nor_cmd_list_mem;
extern FLASH_NOR_RET_TYPE(*flash_nor_set_bp_lv_by_size)(FLASH_NOR_IDX_TYPE idx, bool from_bottom, uint32_t num_bp_sector, FLASH_NOR_BP_INFO_STRUCT *bp_info);
extern FLASH_NOR_RET_TYPE(*flash_nor_suspend_erase)(FLASH_NOR_IDX_TYPE idx);
extern FLASH_NOR_RET_TYPE(*flash_nor_resume_erase)(FLASH_NOR_IDX_TYPE idx);
extern FLASH_NOR_RET_TYPE(*flash_nor_suspend_dma)(FLASH_NOR_IDX_TYPE idx, uint8_t dma_ch);
extern FLASH_NOR_RET_TYPE(*flash_nor_resume_dma)(FLASH_NOR_IDX_TYPE idx, uint8_t dma_ch);
extern FLASH_NOR_RET_TYPE(*flash_nor_enter_lpm)(FLASH_NOR_IDX_TYPE idx, bool backup_spic);
extern FLASH_NOR_RET_TYPE(*flash_nor_exit_lpm)(FLASH_NOR_IDX_TYPE idx, bool restore_spic);
extern FLASH_NOR_CMD_NODE_TYPE *(*flash_nor_move_cmd_node)(FLASH_NOR_CMD_LIST_TYPE *src_list, FLASH_NOR_CMD_LIST_TYPE *dst_list, FLASH_NOR_CMD_NODE_TYPE *cmd_node);
extern void(*flash_nor_cmd_node_assign)(void);
extern bool(*flash_nor_cmd_list_init)(void);
extern void (*flash_nor_remaining_work_check_in_idle)(void);
extern void(*flash_nor_context_switch_suspend_resume_check)(FLASH_NOR_IDX_TYPE idx);
extern FLASH_NOR_CMD_NODE_TYPE *(*flash_nor_get_blocking_cmd_node)(FLASH_NOR_REQ_TYPE req, uint32_t addr, uint32_t len);
extern FLASH_NOR_RET_TYPE(*flash_nor_suspend_cmd_node)(FLASH_NOR_CMD_NODE_TYPE *cmd_node);
extern FLASH_NOR_RET_TYPE(*flash_nor_resume_cmd_node)(FLASH_NOR_CMD_NODE_TYPE *cmd_node);
extern FLASH_NOR_CMD_NODE_TYPE *(*flash_nor_resume_highest_priority_dma)(void);
extern void (*flash_nor_wait_cmd_node_done)(FLASH_NOR_CMD_NODE_TYPE *cmd_node);
extern uint32_t (*flash_nor_lock_rw_operation)(FLASH_NOR_REQ_TYPE req, uint32_t addr, uint32_t len);
extern uint32_t (*flash_nor_lock_erase_operation)(FLASH_NOR_REQ_TYPE req, uint32_t addr, FLASH_NOR_CMD_NODE_TYPE **cmd_node);
extern uint32_t(*flash_nor_lock)(FLASH_NOR_REQ_TYPE req, uint32_t addr, uint32_t len, FLASH_NOR_CMD_NODE_TYPE **req_cmd_node);
extern void(*flash_nor_unlock)(FLASH_NOR_REQ_TYPE req, uint32_t lock_flag);
extern void (*flash_nor_suspend_all_busy_nodes)(FLASH_NOR_IDX_TYPE idx);
extern FLASH_NOR_RET_TYPE(*flash_nor_malloc_for_query_info)(FLASH_NOR_IDX_TYPE idx);
extern FLASH_NOR_RET_TYPE (*flash_nor_get_bp_info_from_protected_range)(FLASH_NOR_IDX_TYPE idx,
                                                                  bool from_bottom, uint32_t num_bp_sector, FLASH_NOR_BP_INFO_STRUCT *bp_info);
extern bool (*flash_nor_check_is_erasing)(FLASH_NOR_IDX_TYPE idx, FLASH_NOR_CMD_NODE_TYPE **cmd_node);
extern bool (*flash_nor_erase_suspend_check)(uint8_t primask, FLASH_NOR_CMD_NODE_TYPE **node);
extern void (*flash_nor_erase_resume_check)(uint8_t primask, FLASH_NOR_CMD_NODE_TYPE *node, bool ret);
/****************************************************************************************
 * Nor Flash Hook Function
 ****************************************************************************************/
extern FLASH_NOR_RET_TYPE (*flash_nor_get_bp_info_from_protected_range_hook)(FLASH_NOR_IDX_TYPE idx, bool from_bottom, uint32_t num_bp_sector, FLASH_NOR_BP_INFO_STRUCT *bp_info);

#endif
