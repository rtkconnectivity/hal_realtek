/**
 *****************************************************************************************
 *     Copyright(c) 2018, Realtek Semiconductor Corporation. All rights reserved.
 *****************************************************************************************
 * @file    spic_basic.h
 * @brief   RXI-312 SPI controller platform independent implementation header file
 * @author  Yao-Yu
 * @date    2020-07-08
 * @version v0.1
 * ***************************************************************************************
 */

#ifndef _SPIC_INT_H
#define _SPIC_INT_H

#include <stdbool.h>
#include "spic.h"

#define SPIC_NUM      2
extern SPIC_TypeDef *spic_reg_base_map[SPIC_NUM];

/****************************************************************************************
 * spic Type Define
 ****************************************************************************************/
typedef union _SPIC_ACCESS_INFO
{
    /* Insert rsvd0 & rsvd1 to avoid unalign access for performance
       consideration */
    uint32_t d32[3];
    struct
    {
        uint32_t cmd: 16;
        uint32_t cmd_len: 2;
        uint32_t rsvd0: 14;
        uint32_t addr;
        uint32_t addr_len: 3;
        uint32_t cmd_ch: 2;
        uint32_t addr_ch: 2;
        uint32_t data_ch: 2;
        uint32_t dummy_len: 15;
        uint32_t rsvd1: 8;
    };
} SPIC_ACCESS_INFO;

typedef enum
{
    SPIC_SING_CH,
    SPIC_DUAL_CH,
    SPIC_QUAD_CH,
    SPIC_OCTAL_CH,
} SPIC_CFG_CH;

/****************************************************************************************
 * spic Function Prototype
 ****************************************************************************************/
bool spic_set_max_retry(SPIC_TypeDef *spic, uint32_t max_retry);
uint32_t spic_get_max_retry(SPIC_TypeDef *spic);
bool spic_in_busy(SPIC_TypeDef *spic);
void spic_set_device(SPIC_TypeDef *spic, SPIC_DEVICE_TYPE dev);
bool spic_lock_rom(SPIC_TypeDef *spic, uint8_t *lock_flag);
bool spic_unlock_rom(SPIC_TypeDef *spic, uint8_t *lock_flag);
void spic_set_lock_enable(bool enable);
void spic_enable(SPIC_TypeDef *spic, bool enable);
void spic_disable_interrupt(SPIC_TypeDef *spic);
void spic_enable_frd_single(SPIC_TypeDef *spic);
void spic_set_ctrlr0_ch(SPIC_TypeDef *spic, bool enable);
void spic_set_sipol(SPIC_TypeDef *spic, uint8_t sipol, bool enable);
void spic_set_rx_mode(SPIC_TypeDef *spic);
void spic_set_tx_mode(SPIC_TypeDef *spic);
void spic_set_auto_mode(SPIC_TypeDef *spic);
void spic_set_user_mode(SPIC_TypeDef *spic);
void spic_set_ck_times(SPIC_TypeDef *spic, uint8_t ck_times);
void spic_set_cs_tcem(SPIC_TypeDef *spic, uint8_t tcem);
void spic_set_cs_seq_timeout(SPIC_TypeDef *spic, uint8_t timeout);
void spic_set_cs_active_hold(SPIC_TypeDef *spic, uint8_t hold_time);
void spic_set_cs_h_wr_dum_len(SPIC_TypeDef *spic, uint8_t dum_len);
void spic_set_cs_h_rd_dum_len(SPIC_TypeDef *spic, uint8_t dum_len);
void spic_set_atom_size(SPIC_TypeDef *spic, SPIC_ATOM_SIZE_TYPE atom_size);
void spic_set_data_unit_2b(SPIC_TypeDef *spic, bool enable);
void spic_set_rd_page_en(SPIC_TypeDef *spic, bool enable);
void spic_set_page_size(SPIC_TypeDef *spic, uint8_t page_size);
void spic_set_full_write(SPIC_TypeDef *spic, bool enable);
void spic_set_rd_weight(SPIC_TypeDef *spic, uint8_t rd_weight);
void spic_set_wr_dummy_length(SPIC_TypeDef *spic, uint16_t wr_dummy_length);
void spic_set_read_fast_single(SPIC_TypeDef *spic, uint16_t rd_cmd);
void spic_set_write_single(SPIC_TypeDef *spic, uint16_t wr_cmd);
void spic_set_full_write(SPIC_TypeDef *spic, bool enable);
void spic_set_rd_valid_en(SPIC_TypeDef *spic, bool enable);
void spic_set_ddr_en(SPIC_TypeDef *spic, bool enable);
void spic_set_rxndf(SPIC_TypeDef *spic, uint32_t ndf);
void spic_set_txndf(SPIC_TypeDef *spic, uint32_t ndf);
void spic_set_dr(SPIC_TypeDef *spic, uint32_t data, SPIC_CFG_DATA_LEN len);
uint32_t spic_get_dr(SPIC_TypeDef *spic, SPIC_CFG_DATA_LEN len);
void spic_set_cmd_len(SPIC_TypeDef *spic, uint8_t len);
void spic_set_user_addr_len(SPIC_TypeDef *spic, uint8_t len);
void spic_set_auto_addr_len(SPIC_TypeDef *spic, uint8_t len);
void spic_set_delay_len(SPIC_TypeDef *spic, uint8_t delay_len);
void spic_set_user_dummy_len(SPIC_TypeDef *spic, uint8_t dummy_len);
void spic_set_auto_dummy_len(SPIC_TypeDef *spic, uint8_t dummy_len);
void spic_set_baud(SPIC_TypeDef *spic, uint16_t baud);
uint16_t spic_get_baud(SPIC_TypeDef *spic);
void spic_set_multi_ch(SPIC_TypeDef *spic, SPIC_CFG_CH cmd, SPIC_CFG_CH addr,
                       SPIC_CFG_CH data);
void spic_set_seq_trans(SPIC_TypeDef *spic, bool enable);
void spic_clean_valid_cmd(SPIC_TypeDef *spic);
void spic_set_rx_fifo_valid_entry(SPIC_TypeDef *spic, uint8_t valid_entry_size);
void spic_set_tx_fifo_valid_entry(SPIC_TypeDef *spic, uint8_t valid_entry_size);
void spic_backup_reg(SPIC_TypeDef *spic, SPIC_BACKUP_REG_TYPE *backup_reg);
void spic_restore_reg(SPIC_TypeDef *spic, SPIC_BACKUP_REG_TYPE *restore_reg);
void spic_set_dum_byte(SPIC_TypeDef *spic, bool enable);
bool spic_check_boot_finish(SPIC_TypeDef *spic);
void spic_enable_dum_byte(SPIC_TypeDef *spic, bool enable);

/****************************************************************************************
 * spic Extern Variables
 ****************************************************************************************/
/* *INDENT-OFF* */
extern bool (*spic_cmd_rx)(SPIC_TypeDef *spic, SPIC_ACCESS_INFO *info, uint8_t *buf, uint8_t buf_len);
extern bool (*spic_cmd_tx)(SPIC_TypeDef *spic, SPIC_ACCESS_INFO *info, uint8_t *buf, uint8_t buf_len);
extern bool (*spic_lock)(SPIC_TypeDef *spic, uint8_t *lock_flag);
extern bool (*spic_unlock)(SPIC_TypeDef *spic, uint8_t *lock_flag);
extern SPIC_BACKUP_REG_TYPE spic0_backup;

#endif
