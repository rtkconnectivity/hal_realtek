/**
 *****************************************************************************************
 *     Copyright(c) 2018, Realtek Semiconductor Corporation. All rights reserved.
 *****************************************************************************************
 * @file    flash_nor_basic.h
 * @brief   Nor flash basic implementation header file
 * @author  Yao-Yu
 * @date    2020-07-08
 * @version v0.1
 * ***************************************************************************************
 */

#ifndef _FLASH_NOR_BASIC_H
#define _FLASH_NOR_BASIC_H

#include <stdint.h>
#include "spic_int.h"
#include "string.h"
#include "patch_header_check.h"
#include "vector_table.h"
#include "fmc_platform.h"

typedef void (*FlashCB)(void);

#define CAL_ADDR get_header_addr_by_img_id(OTA) + offsetof(T_IMG_HEADER_FORMAT, magic_pattern)
#define IS_SPIC0_ADDR(addr) (((addr >= FMC_MAIN) && (addr < FMC_MAIN + SPIC0_SIZE)) || ((addr >= (FMC_MAIN | FLASH_OFFSET_TO_NO_CACHE)) && (addr < (FMC_MAIN | FLASH_OFFSET_TO_NO_CACHE) + SPIC0_SIZE)))

#define _PACKED_                __attribute__((packed))
/****************************************************************************************
 * Nor Flash Device Definition
 ****************************************************************************************/
#define FLASH_NOR_PAGE_SIZE                     (256)
#define FLASH_NOR_SECTOR_SIZE                   (0x1000)
#define FLASH_NOR_BLOCK_SIZE                    (0x10000)
#define FLASH_NOR_BP_FIELDS_OFFSET              (0x02)
#define FLASH_NOR_STATUS_WIP_BIT                (0x01)
#define FLASH_NOR_STATUS_WEL_BIT                (0x02)

/****************************************************************************************
 * Nor Flash Macro
 ****************************************************************************************/
#define FLASH_NOR_TABLE_MAGIC_PATTERN                   (0x5A5A12A5)
#define FLASH_OFFSET_TO_NO_CACHE                        (0x01000000)
#define IS_FLASH_SIZE_LARGER_THAN_16MB(size)            (size > (1 << 24))
#define IS_SAME_FLASH_NOR_PAGE(addr0, addr1)            (((addr0) & 0xFFFFFF00) == ((addr1) & 0xFFFFFF00))

/****************************************************************************************
 * Nor Flash Enumeration
 ****************************************************************************************/
typedef enum
{
    FLASH_MASTER_INTERNAL   = 0,    //!< Master Role with Internal Interface
    FLASH_MASTER_EXTERNAL   = 1,    //!< Master Role with External Interface
    FLASH_SLAVE_EXTERNAL    = 2     //!< Slave Role with External Interface
} FLASH_NOR_INTERFACE_TYPE;

typedef enum
{
    FLASH_NOR_WREN_REG,
    FLASH_NOR_WREN_DATA,
} FLASH_NOR_WREN_MODE;

typedef enum
{
    FLASH_NOR_XTAL_10MHZ,
    FLASH_NOR_XTAL_20MHZ,
    FLASH_NOR_PLL_30MHZ,
    FLASH_NOR_PLL_40MHZ,
    FLASH_NOR_PLL_60MHZ,
    FLASH_NOR_PLL_80MHZ,
    FLASH_NOR_CLK_MAX
} FLASH_NOR_CLK_FREQ;

typedef enum
{
    FLASH_NOR_EXIST_NONE        = 0,
    FLASH_NOR_EXIST_BASIC_CMD   = 1,
    FLASH_NOR_EXIST_ADV_CMD     = 2,
    FLASH_NOR_EXIST_QUERY_INFO  = 4,
    FLASH_NOR_EXIST_ALL         = 7,
} FLASH_NOR_EXIST_LV;

typedef enum
{
    FLASH_NOR_REQ_NONE          = 0x00,
    FLASH_NOR_REQ_READ          = 0x01,
    FLASH_NOR_REQ_WRITE         = 0x02,
    FLASH_NOR_REQ_RW_MASK       = 0x03,

    FLASH_NOR_REQ_ERASE_SECTOR  = 0x04,
    FLASH_NOR_REQ_ERASE_BLOCK   = 0x08,
    FLASH_NOR_REQ_ERASE_CHIP    = 0x10,
    FLASH_NOR_REQ_ERASE_MASK    = 0x1C,

    FLASH_NOR_REQ_DMA_READ      = 0x20,
    FLASH_NOR_REQ_DMA_WRITE     = 0x40,
    FLASH_NOR_REQ_DMA_MASK      = 0x60,

    FLASH_NOR_REQ_RW_SR         = 0x80,
} FLASH_NOR_REQ_TYPE;

typedef struct _PACKED_ _FLASH_NOR_BASIC_CMD_STRUCT
{
    uint8_t cmd_rd_id;              /* Read nor flash ID cmd */
    uint8_t cmd_rd_sr;              /* Read status register */
    uint8_t cmd_wr_sr;              /* Write status register */
    uint8_t cmd_rd_data;            /* Single read cmd */
    uint8_t cmd_fast_rd_data;       /* Fast single read cmd */
    uint8_t cmd_pp;                 /* Single page program cmd */
    uint8_t cmd_sector_e;           /* Erase cmd for nor flash sector (4kB) */
    uint8_t cmd_block_e;            /* Erase cmd for nor flash block (64KB) */
    uint8_t cmd_chip_e;             /* Erase cmd for whole nor flash */
    uint8_t cmd_wr_en;              /* Write enable cmd */
    uint8_t cmd_wr_en_vol;          /* Write enable for volatile status register cmd */
    uint8_t cmd_wr_di;              /* Write disable cmd */
    uint8_t cmd_dp;                 /* Enter deep power down mode cmd */
    uint8_t cmd_dp_release;         /* Release from deep power down mode cmd */
    uint8_t cmd_en_reset;           /* Enable software reset cmd */
    uint8_t cmd_reset;              /* Software reset cmd */
} FLASH_NOR_BASIC_CMD_STRUCT;

typedef struct _PACKED_ _FLASH_NOR_ADV_CMD_STRUCT
{
    uint8_t cmd_rd_dual_o;          /* Dual data read cmd */
    uint8_t cmd_rd_dual_io;         /* Dual data/addr read cmd */
    uint8_t cmd_rd_quad_o;          /* Quad data read cmd */
    uint8_t cmd_rd_quad_io;         /* Quad data/addr read cmd */
    uint8_t cmd_pp_quad_i;          /* Quad page program cmd (1-1-4) */
    uint8_t cmd_pp_quad_ii;         /* Quad page program cmd (1-4-4) */
    uint8_t cmd_rd_sr2;             /* Read status register 2 */
    uint8_t cmd_rd_sr3;             /* Read status register 3 */
    uint8_t cmd_rd_scur;            /* Read secure register */
    uint8_t cmd_wr_sr2;             /* Write status register 2 */
    uint8_t cmd_wr_sr3;             /* Write status register 3 */
    uint8_t cmd_wr_scur;            /* Write secure register */
    uint8_t cmd_rd_cr;              /* Read config cmd */
    uint8_t cmd_hpm;                /* High-performance or continuous read cmd */
    uint8_t cmd_suspend;            /* Suspend cmd */
    uint8_t cmd_resume;             /* Resume cmd */
    uint8_t cmd_enter_4byte_mode;       /* Enter 4 byte address mode cmd */
    uint8_t cmd_exit_4byte_mode;        /* Exit 4 byte address mode cmd */
} FLASH_NOR_ADV_CMD_STRUCT;

typedef struct
{
    uint8_t              channel_num; /*!< Log DMA Channel Number          */
    GDMA_ChannelTypeDef *channel;     /*!< Log DMA Channel (Register Base) */
    IRQn_Type            irq_no;      /*!< Log DMA Channel IRQ Number      */
    VECTORn_Type         vector_no;   /*!< Log DMA Channel Vector Number   */
    IRQ_Fun              isr;         /*!< Log DMA Channel ISR Handler     */
} T_FLASH_DMA_CFG;

typedef struct _PACKED_ _FLASH_NOR_ACCESS_CH
{
    SPIC_CFG_CH cmd;
    SPIC_CFG_CH addr;
    SPIC_CFG_CH data;
} FLASH_NOR_ACCESS_CH;

typedef struct _PACKED_ _FLASH_NOR_QUERY_INFO_STRUCT
{
    /* If tbbo equals to 0x7F means BP supports lock all, lock half, lock none,
       and if tbbo equals to 0xFF means BP only supports lock all, lock none */
    /* If adsbo equals to 0xFF means flash size is smaller than 16MB, so only
       needs 3 bytes address */
    uint32_t flash_size;                /* Nor flash size in byte */
    uint8_t qebo;                       /* QE bit offset in status register */
    uint8_t wsbo;                       /* Write suspend flag bit offset in status register */
    uint8_t esbo;                       /* Erase suspend flag bit offset in status register */
    uint8_t tbbo;                       /* Top-bottom bit offset in status register */
    uint8_t cmpbo;                      /* Complement bit offset in status register */
    uint8_t adsbo;                      /* Current address mode bit offset in status register */
    uint8_t bp_all;                     /* Block protect all level in status register */
    uint8_t bp_mask;                    /* Block protect configurable bit mask in status register */
    uint32_t resume_to_suspend_delay_us;/* Delay time for a resume command to next suspend command */
} FLASH_NOR_QUERY_INFO_STRUCT;

typedef struct _PACKED_ _FLASH_NOR_QUERY_INFO_TABLE_STRUCT
{
    uint8_t manu_id;
    uint16_t device_id;
    uint8_t flash_info; // BIT0 = is_sr2_exist
    FLASH_NOR_QUERY_INFO_STRUCT query;
} FLASH_NOR_QUERY_INFO_TABLE_STRUCT;

typedef struct _PACKED_ _FLASH_NOR_DELAY_INFO_STRUCT
{
    uint16_t path_len: 4;           /* Path delay from pad to internal SPI controller */
    uint16_t dummy_len: 12;         /* Delay cycles for data read, not include path delay */
} FLASH_NOR_DELAY_INFO_STRUCT;

typedef struct _PACKED_ _FLASH_NOR_INFO_STRUCT
{
    uint8_t manu_id;
    uint16_t device_id;

    uint8_t rd_cmd;                 /* Specify the read cmd for current bit mode */
    uint8_t wr_cmd;                 /* Specify the write cmd for current bit mode */

    FLASH_NOR_BASIC_CMD_STRUCT basic;
    FLASH_NOR_ADV_CMD_STRUCT adv;
    FLASH_NOR_QUERY_INFO_STRUCT query;

    FLASH_NOR_ACCESS_CH rd_ch;
    FLASH_NOR_ACCESS_CH wr_ch;
    FLASH_NOR_DELAY_INFO_STRUCT delay;
} FLASH_NOR_INFO_STRUCT;


/****************************************************************************************
* Nor Flash Inter-Function Patch Prototype
****************************************************************************************/
typedef FLASH_NOR_RET_TYPE(*FLASH_NOR_PATCH_FUNC)();

/****************************************************************************************
 * Nor Flash Functions
 ****************************************************************************************/
FLASH_NOR_EXIST_LV flash_nor_get_exist(FLASH_NOR_IDX_TYPE idx);
void flash_nor_get_basic_info(FLASH_NOR_INFO_STRUCT *p_ns_flash_nor_info,
                              uint32_t flash_nor_info_len);
extern FLASH_NOR_RET_TYPE(*flash_nor_cmd_rx)(FLASH_NOR_IDX_TYPE idx, SPIC_ACCESS_INFO *info,
                                             uint8_t *buf, uint8_t len);
extern FLASH_NOR_RET_TYPE(*flash_nor_cmd_tx)(FLASH_NOR_IDX_TYPE idx, SPIC_ACCESS_INFO *info,
                                             uint8_t *buf, uint8_t len);
extern FLASH_NOR_RET_TYPE(*flash_nor_wait_busy)(FLASH_NOR_IDX_TYPE idx);
extern FLASH_NOR_RET_TYPE(*flash_nor_get_status_wip)(FLASH_NOR_IDX_TYPE idx, bool *is_wip);
extern FLASH_NOR_RET_TYPE(*flash_nor_load_query_info)(FLASH_NOR_IDX_TYPE idx);
extern FLASH_NOR_RET_TYPE(*flash_nor_get_bit_mode)(FLASH_NOR_IDX_TYPE idx,
                                                   FLASH_NOR_BIT_MODE *mode);
extern FLASH_NOR_RET_TYPE(*flash_nor_set_bit_mode)(FLASH_NOR_IDX_TYPE idx, FLASH_NOR_BIT_MODE mode);
extern FLASH_NOR_RET_TYPE(*flash_nor_set_auto_mode)(FLASH_NOR_IDX_TYPE idx,
                                                    FLASH_NOR_BIT_MODE mode);
extern FLASH_NOR_INFO_STRUCT flash_nor_info[FLASH_NOR_IDX_MAX];
FLASH_NOR_RET_TYPE flash_nor_hook_func(void);
uint32_t flash_nor_get_flash_size(FLASH_NOR_IDX_TYPE idx);
uint32_t flash_nor_get_resume_to_suspend_delay_time(FLASH_NOR_IDX_TYPE idx);
FLASH_NOR_RET_TYPE flash_nor_get_bp_all_lv(FLASH_NOR_IDX_TYPE idx, uint8_t *bp_lv);
FLASH_NOR_IDX_TYPE flash_nor_get_idx_by_addr(uint32_t addr);
FLASH_NOR_RET_TYPE flash_nor_get_offset_by_idx(FLASH_NOR_IDX_TYPE idx, uint32_t *addr);
extern FLASH_NOR_RET_TYPE(*flash_nor_write_enable)(FLASH_NOR_IDX_TYPE idx,
                                                   FLASH_NOR_WREN_MODE mode);
extern FLASH_NOR_RET_TYPE(*flash_nor_get_regs_bits)(FLASH_NOR_IDX_TYPE idx, uint32_t *reg_bits,
                                                    uint32_t reg_mask);
extern FLASH_NOR_RET_TYPE(*flash_nor_set_regs_bits)(FLASH_NOR_IDX_TYPE idx, uint32_t reg_bits,
                                                    uint32_t reg_mask);
extern FLASH_NOR_RET_TYPE(*flash_nor_get_bp_lv)(FLASH_NOR_IDX_TYPE idx, uint8_t *bp_lv);
extern FLASH_NOR_RET_TYPE(*flash_nor_set_bp_lv)(FLASH_NOR_IDX_TYPE idx, uint8_t bp_lv);
extern FLASH_NOR_RET_TYPE(*flash_nor_read)(uint32_t addr, uint8_t *data, uint32_t byte_len);
extern FLASH_NOR_RET_TYPE(*flash_nor_write)(uint32_t addr, uint8_t *data, uint32_t byte_len);
extern FLASH_NOR_RET_TYPE(*flash_nor_erase)(uint32_t addr, FLASH_NOR_ERASE_MODE mode);
extern FLASH_NOR_RET_TYPE(*flash_nor_unlock_bp_by_addr)(uint32_t addr, uint8_t *old_bp_lv);
extern FLASH_NOR_RET_TYPE(*flash_nor_unlock_write)(uint32_t addr, uint8_t *data, uint32_t byte_len);
extern FLASH_NOR_RET_TYPE(*flash_nor_unlock_erase)(uint32_t addr, FLASH_NOR_ERASE_MODE mode);
extern FLASH_NOR_RET_TYPE(*flash_nor_set_dum_byte)(FLASH_NOR_IDX_TYPE idx);
extern FLASH_NOR_RET_TYPE(*flash_nor_set_4_byte_addr_mode)(FLASH_NOR_IDX_TYPE idx, bool enable);
extern FLASH_NOR_RET_TYPE(*flash_nor_set_physical_cyc)(FLASH_NOR_IDX_TYPE idx, uint32_t cyc);
extern FLASH_NOR_RET_TYPE(*flash_nor_find_cyc_cnt)(FLASH_NOR_IDX_TYPE idx, uint32_t cal_addr,
                                                   bool is_cal_rd_dummy_len, uint32_t cfg_max);
extern FLASH_NOR_RET_TYPE(*flash_nor_cal_dly_cyc)(FLASH_NOR_IDX_TYPE idx, uint32_t cal_addr);
extern FLASH_NOR_RET_TYPE(*flash_nor_set_cal_addr)(FLASH_NOR_IDX_TYPE idx, uint32_t cal_addr);
extern FLASH_NOR_RET_TYPE(*flash_nor_cal_dummy_cyc)(FLASH_NOR_IDX_TYPE idx, uint32_t cal_addr,
                                                    FLASH_NOR_BIT_MODE mode);
extern FLASH_NOR_RET_TYPE(*flash_nor_calibration)(FLASH_NOR_IDX_TYPE idx, FLASH_NOR_BIT_MODE mode);
extern FLASH_NOR_RET_TYPE(*flash_nor_get_tb_bit)(FLASH_NOR_IDX_TYPE idx, bool *from_bottom);
extern FLASH_NOR_RET_TYPE(*flash_nor_set_tb_bit)(FLASH_NOR_IDX_TYPE idx, bool from_bottom);
extern void set_flash_interface(FLASH_NOR_INTERFACE_TYPE type);
extern uint32_t flash_nor_get_addr_base(FLASH_NOR_IDX_TYPE idx);
extern bool(*flash_nor_lock)(FLASH_NOR_REQ_TYPE req);
extern void (*flash_nor_unlock)(FLASH_NOR_REQ_TYPE req);
/**
 * @brief check flash bp level before ota copy, if flash is locked, must unlock bp in NVRAM
 * @param none
 * @return none
*/
extern void (*check_flash_bp_before_ota_copy)(void);

/**
 * @brief read flash data via auto mode
 * @param addr    address to read
 * @return value in this address
*/
uint32_t flash_nor_auto_read(uint32_t addr);

extern void (*flash_nor_dma_init)(FLASH_NOR_DMA_TYPE dma_type, uint32_t src_addr, uint32_t dst_addr,
                                  uint32_t data_len);


#endif
