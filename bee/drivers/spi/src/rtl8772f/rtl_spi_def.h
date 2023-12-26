/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* \file     rtl_spi_def.h
* \brief    SPI Structures Section and parameter definition for RTL8772F
* \details
* \author   renee
* \date     2023-11-15
* \version  v1.1
* *********************************************************************************************************
*/

#ifndef RTL_SPI_DEF_H
#define RTL_SPI_DEF_H

#include <stdint.h>
#include <stdbool.h>
#include "rtl876x.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                         SPI Features
 *============================================================================*/

#define CHIP_SPI_NUM                                   (5)
#define SPI_TX_FIFO_SIZE                               (64)
#define SPI_RX_FIFO_SIZE                               (64)
#define SPI0_SLAVE_TX_FIFO_SIZE                        (63)
#define SPI0_SLAVE_RX_FIFO_SIZE                        (64)
#define SPI_SUPPORT_WRAP_MODE                          (1)
#define SPI0_SUPPORT_MASTER_SLAVE                      (0)

/*============================================================================*
 *                         SPI Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO  uint32_t SPI_M_S_CTRL0;               /*!< 0x00 */
    __IO  uint32_t SPI_M_CTRL1;                 /*!< 0x04 */
    __IO  uint32_t SPI_SPIENR;                  /*!< 0x08 */
    __IO  uint32_t RSVD_0C;                     /*!< 0x0C */
    __IO  uint32_t SPI_M_SER;                   /*!< 0x10 */
    __IO  uint32_t SPI_M_BAUDR;                 /*!< 0x14 */
    __IO  uint32_t SPI_TXFTLR;                  /*!< 0x18 */
    __IO  uint32_t SPI_RXFTLR;                  /*!< 0x1C */
    __I   uint32_t SPI_TXFLR;                   /*!< 0x20 */
    __I   uint32_t SPI_RXFLR;                   /*!< 0x24 */
    __I   uint32_t SPI_M_S_SR;                  /*!< 0x28 */
    __IO  uint32_t SPI_M_S_IMR;                 /*!< 0x2C */
    __I   uint32_t SPI_M_S_ISR;                 /*!< 0x30 */
    __I   uint32_t SPI_M_S_RISR;                /*!< 0x34 */
    __I   uint32_t SPI_TXOICR;                  /*!< 0x38 */
    __I   uint32_t SPI_RXOICR;                  /*!< 0x3C */
    __I   uint32_t SPI_RXUICR;                  /*!< 0x40 */
    __I   uint32_t SPI_M_S_MSTICR_FAEICR;       /*!< 0x44 */
    __I   uint32_t SPI_ICR;                     /*!< 0x48 */
    __IO  uint32_t SPI_DMACR;                   /*!< 0x4C */
    __IO  uint32_t SPI_DMATDLR;                 /*!< 0x50 */
    __IO  uint32_t SPI_DMARDLR;                 /*!< 0x54 */
    __I   uint32_t SPI_M_S_IDR_TXUICR;          /*!< 0x58 */
    __I   uint32_t SPI_M_S_VERSION_ID_SSRICR;   /*!< 0x5C */
    __IO  uint32_t SPI_DR[36];                  /*!< 0x60 - 0xEC */
    __IO  uint32_t SPI_M_RSDR;                  /*!< 0xF0 */
    __I   uint32_t RSVD_F4[67];                 /*!< 0xF4 - 0x1FC */
    __IO uint32_t  SPI_WRAP_CTRL;               /*!< 0x200 */
    __IO uint32_t  SPI_WRAP_TXFTLR;             /*!< 0x204 */
    __I  uint32_t  SPI_MST_TXFLR;               /*!< 0x208 */
    __I  uint32_t  SPI_WRAP_SR;                 /*!< 0x20C */
    __IO uint32_t  SPI_WRAP_IMR;                /*!< 0x210 */
    __I  uint32_t  SPI_WRAP_ISR;                /*!< 0x214 */
    __I  uint32_t  SPI_WRAP_RISR;               /*!< 0x218 */
    __I  uint32_t  SPI_WRAP_ICR;                /*!< 0x21C */
    __IO uint32_t  SPI_WRAP_DMACR;              /*!< 0x220 */
    __IO uint32_t  SPI_WRAP_DMATDLR;            /*!< 0x224 */
    __I  uint32_t  SPI_WRAP_TXNDF_CNT;          /*!< 0x228 */
} SPI_TypeDef;


/*============================================================================*
 *                         SPI Declaration
 *============================================================================*/
#define SPI0               ((SPI_TypeDef *) SPI0_REG_BASE)
#define SPI1               ((SPI_TypeDef *) SPI1_REG_BASE)
#define SPI2               ((SPI_TypeDef *) SPI2_REG_BASE)
#define SPI3               ((SPI_TypeDef *) SPI3_REG_BASE)
#define SPI0_SLAVE         ((SPI_TypeDef *) SPI0_SLAVE_REG_BASE)
/*============================================================================*
 *                         SPI Registers and Field Descriptions
 *============================================================================*/
/* 0x00
    3:0     R      dfs             4'h0
    5:4     R/W    frf             2'b0
    6       R/W    scph            1'b0
    7       R/W    scpol           1'b0
    9:8     R/W    tmod            2'b0
    10      R/W    slv_oe          1'b0
    11      R/W    srl             1'b0
    15:12   R/W    cfs             4'b0
    20:16   R/W    dfs_32          5'h7
    22:21   R      spi_frf         2'b0
    23      R      reserved23      1'b0
    24      R/W    sste            1'b1
    31:25   R      reserved31_25   7'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t dfs: 4;
        __IO uint32_t frf: 2;
        __IO uint32_t scph: 1;
        __IO uint32_t scpol: 1;
        __IO uint32_t tmod: 2;
        __IO uint32_t slv_oe: 1;
        __IO uint32_t srl: 1;
        __IO uint32_t cfs: 4;
        __IO uint32_t dfs_32: 5;
        __I uint32_t spi_frf: 2;
        __I uint32_t reserved_1: 1;
        __IO uint32_t sste: 1;
        __I uint32_t reserved_0: 7;
    } b;
} SPI_M_CTRL0_t;



/* 0x00
    3:0     R/W    dfs             4'h7
    5:4     R      reserved5_4     2'b0
    6       R/W    scph            1'b0
    7       R/W    scpol           1'b0
    9:8     R      reserved9_8     2'b0
    10      R/W    slv_oe          1'b0
    20:11   R      reserved20_11   10'b0
    21      R/W    tx_byte_swap    1'b0
    22      R/W    tx_bit_swap     1'b0
    23      R/W    rx_byte_swap    1'b0
    24      R/W    rx_bit_swap     1'b0
    31:25   R      reserved31_25   7'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t dfs: 4;
        __I uint32_t reserved_3: 2;
        __IO uint32_t scph: 1;
        __IO uint32_t scpol: 1;
        __I uint32_t reserved_2: 2;
        __IO uint32_t slv_oe: 1;
        __I uint32_t reserved_1: 10;
        __IO uint32_t tx_byte_swap: 1;
        __IO uint32_t tx_bit_swap: 1;
        __IO uint32_t rx_byte_swap: 1;
        __IO uint32_t rx_bit_swap: 1;
        __I uint32_t reserved_0: 7;
    } b;
} SPI_S_CTRL0_t;



/* 0x04
    15:0    R/W    ndf             16'h0
    31:16   R      reserved0       16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t ndf: 16;
        __I uint32_t reserved_0: 16;
    } b;
} SPI_M_CTRL1_t;



/* 0x08
    0       R/W    spi_en          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t spi_en: 1;
        __I uint32_t reserved_0: 31;
    } b;
} SPI_SPIENR_t;



/* 0x10
    0       R/W    ser             3'b0
    31:1    R      reserved0       29'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t ser: 3;
        __I uint32_t reserved_0: 29;
    } b;
} SPI_M_SER_t;



/* 0x14
    15:0    R/W    sckdv           16'b0
    31:16   R      reserved0       16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t sckdv: 16;
        __I uint32_t reserved_0: 16;
    } b;
} SPI_M_BAUDR_t;



/* 0x18
    5:0     R/W    tft             6'b0
    31:6    R      reserved0       26'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t tft: 6;
        __I uint32_t reserved_0: 26;
    } b;
} SPI_TXFTLR_t;



/* 0x1C
    5:0     R/W    rft             6'b0
    31:6    R      reserved0       26'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t rft: 6;
        __I uint32_t reserved_0: 26;
    } b;
} SPI_RXFTLR_t;



/* 0x20
    6:0     R      txtfl           7'b0
    31:7    R      reserved0       25'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t txtfl: 7;
        __I uint32_t reserved_0: 25;
    } b;
} SPI_TXFLR_t;



/* 0x24
    6:0     R      rxtfl           7'b0
    31:7    R      reserved0       25'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t rxtfl: 7;
        __I uint32_t reserved_0: 25;
    } b;
} SPI_RXFLR_t;



/* 0x28
    0       R      busy            1'b0
    1       R      tfnf            1'b1
    2       R      tfe             1'b1
    3       R      rfne            1'b0
    4       R      rff             1'b0
    5       R      txe             1'b0
    6       R      dcol            1'b0
    31:7    R      reserved31_7    25'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t busy: 1;
        __I uint32_t tfnf: 1;
        __I uint32_t tfe: 1;
        __I uint32_t rfne: 1;
        __I uint32_t rff: 1;
        __I uint32_t txe: 1;
        __I uint32_t dcol: 1;
        __I uint32_t reserved_0: 25;
    } b;
} SPI_M_SR_t;



/* 0x28
    0       R      busy            1'b0
    1       R      tfnf            1'b1
    2       R      tfe             1'b1
    3       R      rfne            1'b0
    4       R      rff             1'b0
    5       R      txe             1'b0
    6       R      reserved6       1'b0
    31:7    R      reserved31_7    25'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t busy: 1;
        __I uint32_t tfnf: 1;
        __I uint32_t tfe: 1;
        __I uint32_t rfne: 1;
        __I uint32_t rff: 1;
        __I uint32_t txe: 1;
        __I uint32_t reserved_1: 1;
        __I uint32_t reserved_0: 25;
    } b;
} SPI_S_SR_t;



/* 0x2C
    0       R/W    txeim           1'b1
    1       R/W    txoim           1'b1
    2       R/W    rxuim           1'b1
    3       R/W    rxoim           1'b1
    4       R/W    rxfim           1'b1
    5       R/W    mstim           1'b1
    31:6    R      reserved31_6    26'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t txeim: 1;
        __IO uint32_t txoim: 1;
        __IO uint32_t rxuim: 1;
        __IO uint32_t rxoim: 1;
        __IO uint32_t rxfim: 1;
        __IO uint32_t mstim: 1;
        __I uint32_t reserved_0: 26;
    } b;
} SPI_M_IMR_t;



/* 0x2C
    0       R/W    txeim           1'b1
    1       R/W    txoim           1'b1
    2       R/W    rxuim           1'b1
    3       R/W    rxoim           1'b1
    4       R/W    rxfim           1'b1
    5       R/W    faeim           1'b1
    6       R/W    txuim           1'b1
    7       R/W    ssrim           1'b1
    31:8    R      reserved0       24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t txeim: 1;
        __IO uint32_t txoim: 1;
        __IO uint32_t rxuim: 1;
        __IO uint32_t rxoim: 1;
        __IO uint32_t rxfim: 1;
        __IO uint32_t faeim: 1;
        __IO uint32_t txuim: 1;
        __IO uint32_t ssrim: 1;
        __I uint32_t reserved_0: 24;
    } b;
} SPI_S_IMR_t;



/* 0x30
    0       R      txeis           1'b0
    1       R      txois           1'b0
    2       R      rxuis           1'b0
    3       R      rxois           1'b0
    4       R      rxfis           1'b0
    5       R      mstis           1'b0
    31:6    R      reserved31_6    26'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t txeis: 1;
        __I uint32_t txois: 1;
        __I uint32_t rxuis: 1;
        __I uint32_t rxois: 1;
        __I uint32_t rxfis: 1;
        __I uint32_t mstis: 1;
        __I uint32_t reserved_0: 26;
    } b;
} SPI_M_ISR_t;



/* 0x30
    0       R      txeis           1'b0
    1       R      txois           1'b0
    2       R      rxuis           1'b0
    3       R      rxois           1'b0
    4       R      rxfis           1'b0
    5       R      faeis           1'b0
    6       R      txuis           1'b0
    7       R      ssris           1'b0
    31:8    R      reserved0       24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t txeis: 1;
        __I uint32_t txois: 1;
        __I uint32_t rxuis: 1;
        __I uint32_t rxois: 1;
        __I uint32_t rxfis: 1;
        __I uint32_t faeis: 1;
        __I uint32_t txuis: 1;
        __I uint32_t ssris: 1;
        __I uint32_t reserved_0: 24;
    } b;
} SPI_S_ISR_t;



/* 0x34
    0       R      txeir           1'b0
    1       R      txoir           1'b0
    2       R      rxuir           1'b0
    3       R      rxoir           1'b0
    4       R      rxfir           1'b0
    5       R      mstir           1'b0
    31:6    R      reserved31_6    26'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t txeir: 1;
        __I uint32_t txoir: 1;
        __I uint32_t rxuir: 1;
        __I uint32_t rxoir: 1;
        __I uint32_t rxfir: 1;
        __I uint32_t mstir: 1;
        __I uint32_t reserved_0: 26;
    } b;
} SPI_M_RISR_t;



/* 0x34
    0       R      txeir           1'b0
    1       R      txoir           1'b0
    2       R      rxuir           1'b0
    3       R      rxoir           1'b0
    4       R      rxfir           1'b0
    5       R      faeir           1'b0
    6       R      txuir           1'b0
    7       R      ssrir           1'b0
    31:8    R      reserved0       24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t txeir: 1;
        __I uint32_t txoir: 1;
        __I uint32_t rxuir: 1;
        __I uint32_t rxoir: 1;
        __I uint32_t rxfir: 1;
        __I uint32_t faeir: 1;
        __I uint32_t txuir: 1;
        __I uint32_t ssrir: 1;
        __I uint32_t reserved_0: 24;
    } b;
} SPI_S_RISR_t;



/* 0x38
    0       R      txoicr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t txoicr: 1;
        __I uint32_t reserved_0: 31;
    } b;
} SPI_TXOICR_t;



/* 0x3C
    0       R      rxoicr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t rxoicr: 1;
        __I uint32_t reserved_0: 31;
    } b;
} SPI_RXOICR_t;



/* 0x40
    0       R      rxuicr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t rxuicr: 1;
        __I uint32_t reserved_0: 31;
    } b;
} SPI_RXUICR_t;



/* 0x44
    0       R      msticr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t msticr: 1;
        __I uint32_t reserved_0: 31;
    } b;
} SPI_M_MSTICR_t;



/* 0x44
    0       R      faeicr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t faeicr: 1;
        __I uint32_t reserved_0: 31;
    } b;
} SPI_S_FAEICR_t;



/* 0x48
    0       R      icr             1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t icr: 1;
        __I uint32_t reserved_0: 31;
    } b;
} SPI_ICR_t;



/* 0x4C
    0       R/W    rdmae           1'b0
    1       R/W    tdmae           1'b0
    31:2    R      reserved0       30'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t rdmae: 1;
        __IO uint32_t tdmae: 1;
        __I uint32_t reserved_0: 30;
    } b;
} SPI_DMACR_t;



/* 0x50
    5:0     R/W    dmatdl          6'b0
    31:6    R      reserved0       26'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t dmatdl: 6;
        __I uint32_t reserved_0: 26;
    } b;
} SPI_DMATDLR_t;



/* 0x54
    5:0     R/W    dmardl          6'b0
    31:6    R      reserved0       26'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t dmardl: 6;
        __I uint32_t reserved_0: 26;
    } b;
} SPI_DMARDLR_t;



/* 0x58
    31:0    R      idcode       32'hffffffff
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t idcode: 32;
    } b;
} SPI_M_IDR_t;



/* 0x58
    0       R      txuicr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t txuicr: 1;
        __I uint32_t reserved_0: 31;
    } b;
} SPI_S_TXUICR_t;



/* 0x5C
    31:0    R      ssi_comp_version       32'h3430322a
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t ssi_comp_version: 32;
    } b;
} SPI_M_VERSION_ID_t;



/* 0x5C
    0       R      ssricr          1'b0
    31:1    R      reserved0       31'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t ssricr: 1;
        __I uint32_t reserved_0: 31;
    } b;
} SPI_S_SSRICR_t;



/* 0x60
    31:0    R/W    dr              32'b0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t dr: 32;
    } b;
} SPI_DR_t;



/* 0xF0
    7:0     R/W    rsd             8'b0
    31:8    R      reserved0       24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t rsd: 8;
        __I uint32_t reserved_0: 24;
    } b;
} SPI_M_RSDR_t;


/* 0x200
    0       R/W    wrap_ctrl_mode          1'b0
    1       R/WAC  mst_tx_fifo_en          1'b0
    2       R/WAC  tx_fifo_rst             1'b0
    3       R/W    mosi_pull_en            1'b0
    4       R/W    mosi_drv_low_en         1'b0
    5       R/W    cs_inv_en               1'b0
    9:6     R/W    cs_setup_cnt            4'b0
    15:10   R      reserved15_10           6'b0
    31:16   R/W    mst_tx_ndf              16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t wrap_ctrl_mode: 1;
        __IO uint32_t mst_tx_fifo_en: 1;
        __IO uint32_t tx_fifo_rst: 1;
        __IO uint32_t mosi_pull_en: 1;
        __IO uint32_t mosi_drv_low_en: 1;
        __IO uint32_t cs_inv_en: 1;
        __IO uint32_t cs_setup_cnt: 4;
        __I uint32_t reserved_0: 6;
        __IO uint32_t mst_tx_ndf: 16;
    } b;
} SPI_WRAP_CTRL_t;



/* 0x204
    6:0     R/W    tx_fifo_tl              7'b0
    31:7    R      reserved0               25'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t tx_fifo_tl: 7;
        __I uint32_t reserved_0: 25;
    } b;
} SPI_WRAP_TXFTLR_t;



/* 0x208
    6:0     R      tx_fifo_lv              7'b0
    31:7    R      reserved0               25'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t tx_fifo_lv: 7;
        __I uint32_t reserved_0: 25;
    } b;
} SPI_MST_TXFLR_t;



/* 0x20C
    0       R      cs_en                   1'b0
    1       R      tx_fifo_not_full        1'b1
    2       R      tx_fifo_empty           1'b1
    31:3    R      reserved31_3            29'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t cs_en: 1;
        __I uint32_t tx_fifo_not_full: 1;
        __I uint32_t tx_fifo_empty: 1;
        __I uint32_t reserved_0: 29;
    } b;
} SPI_WRAP_SR_t;



/* 0x210
    0       R/W    tx_fifo_empty_int_m     1'b0
    1       R/W    tx_fifo_ov_int_m        1'b0
    2       R/W    tx_ndf_done_int_m       1'b0
    31:3    R      reserved31_3            29'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t tx_fifo_empty_int_m: 1;
        __IO uint32_t tx_fifo_ov_int_m: 1;
        __IO uint32_t tx_ndf_done_int_m: 1;
        __I uint32_t reserved_0: 29;
    } b;
} SPI_WRAP_IMR_t;



/* 0x214
    0       R      tx_fifo_empty_int_st    1'b0
    1       R      tx_fifo_ov_int_st       1'b0
    2       R      tx_ndf_done_int_st      1'b0
    31:3    R      reserved31_3            29'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t tx_fifo_empty_int_st: 1;
        __I uint32_t tx_fifo_ov_int_st: 1;
        __I uint32_t tx_ndf_done_int_st: 1;
        __I uint32_t reserved_0: 29;
    } b;
} SPI_WRAP_ISR_t;



/* 0x218
    0       R      tx_fifo_empty_r_st      1'b0
    1       R      tx_fifo_ov_r_st         1'b0
    2       R      tx_ndf_done_r_st        1'b0
    31:3    R      reserved31_3            29'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t tx_fifo_empty_r_st: 1;
        __I uint32_t tx_fifo_ov_r_st: 1;
        __I uint32_t tx_ndf_done_r_st: 1;
        __I uint32_t reserved_0: 29;
    } b;
} SPI_WRAP_RISR_t;



/* 0x21C
    0       R      int_clr                 1'b0
    31:1    R      reserved0               31'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t int_clr: 1;
        __I uint32_t reserved_0: 31;
    } b;
} SPI_WRAP_ICR_t;



/* 0x220
    0       R/W    tx_dma_en               1'b0
    31:1    R      reserved0               31'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t tx_dma_en: 1;
        __I uint32_t reserved_0: 31;
    } b;
} SPI_WRAP_DMACR_t;



/* 0x224
    6:0     R/W    dma_tx_dl               7'b0
    31:7    R      reserved0               25'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t dma_tx_dl: 7;
        __I uint32_t reserved_0: 25;
    } b;
} SPI_WRAP_DMATDLR_t;



/* 0x228
    16:0    R      tx_ndf_cnt              17'b0
    31:17   R      reserved0               15'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t tx_ndf_cnt: 17;
        __I uint32_t reserved_0: 15;
    } b;
} SPI_WRAP_TXNDF_CNT_t;

/* ================================================================================ */
/* ================                  SPI  WRAPPER                  ================ */
/* ================================================================================ */

/**
 * \brief    SPI API Wrapper
 *
 * \ingroup  SPI_Exported_Constants
 */
#define SPI_Change_CLK                  SPI_ChangeClock
#define SPI_Inverse_CS_ActivePolarity   SPI_InverseCSActivePolarity
#define SPI_Drive_MOSI_Low              SPI_DriveMOSILow
#define SPI_Pull_MOSI_En                SPI_PullMOSIEn


#ifdef  __cplusplus
}
#endif /* __cplusplus */
#endif /* RTL_SPI_DEF_H */
