/**
*****************************************************************************************
*     Copyright(c) 2017, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file    mem_config.h
  * @brief   Memory Configuration
  * @date    2017.6.6
  * @version v1.0
  * *************************************************************************************
   * @attention
   * <h2><center>&copy; COPYRIGHT 2017 Realtek Semiconductor Corporation</center></h2>
   * *************************************************************************************
  */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef MEM_CONFIG_H
#define MEM_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup MEM_CONFIG Memory Configure
  * @brief Memory configuration for user application
  * @{
  */
// Build Bank Configure
#define BUILD_BANK              0   //Bank0 as default
/*============================================================================*
 *                        Constants
 *============================================================================*/
#define BUILD_BANK                0

/** @defgroup MEM_CONFIG_Exported_Constant Mem Config Exported Constants
  * @{
  */
/*============================================================================*
 *                        1. Remap layout
 *============================================================================*/
/* null */

/*============================================================================*
 *                        2. Data RAM layout
 *============================================================================*/
/* Data RAM layout:                       104K
example:
   1) ROM Global:                        6.5K
   2) Main Stack:                        1.5K
   3) Lowerstack Global + RAM Code:       10K -128
   4) proprietary Global + RAM Code:     128Byte
   5) Platform Patch Global + RAM Code:    8K
   6) Stack Patch Global + RAM Code:       8K
   7) Upperstack Global + RAM Code:        2K
   8) APP Global + RAM Code:              16K
   9) Heap:                               50K
*/
/* --------------------The following macros should be updated by APP------------------------- */
/** @brief shared cache ram block */
#define SHARE_CACHE_RAM_BLOCK             (0) //each block size 4KB
/** @brief upperstack ram size */
#define DATA_RAM_UPPERSTACK_SIZE          (2 * 1024)
/** @brief data ram size for app global variables and code */
#define APP_GLOBAL_SIZE                   (16 * 1024)
/** @brief data ram size for heap */
#define HEAP_DATA_ON_SIZE                 (52 * 1024)
/* --------------------The following macros can be modified ------------------------------- */
/** @brief  data ram start address */
#define DATA_RAM_TOTAL_SIZE               (104 * 1024)
#define DATA_RAM_ROM_GLOBAL_SIZE          (6 * 1024 + 512)
#define MAIN_STACK_SIZE                   (1024 + 512)
#define DATA_RAM_LOWSTACK_GLOBAL_SIZE     (10 * 1024 - 128)
#define DATA_RAM_PROPRIETARY_SIZE         (128)
#define DATA_RAM_PATCH_SIZE               (8 * 1024)
#define DATA_RAM_STACKPATCH_SIZE          (8 * 1024)
/* --------------------Check memroy layout is reasonable --------------------- */
#if (DATA_RAM_ROM_GLOBAL_SIZE + DATA_RAM_LOWSTACK_GLOBAL_SIZE + MAIN_STACK_SIZE + DATA_RAM_PROPRIETARY_SIZE + DATA_RAM_PATCH_SIZE + DATA_RAM_STACKPATCH_SIZE + DATA_RAM_UPPERSTACK_SIZE + APP_GLOBAL_SIZE + HEAP_DATA_ON_SIZE != DATA_RAM_TOTAL_SIZE)
#error "data ram total size should be 104 KB"
#endif


/*============================================================================*
 *                        3. Buffer RAM layout
 *============================================================================*/
/* Buffer RAM layout:                16K
example:
   1) rom global:                     2K
   2) Heap ON:                       14K
*/

#define BUFFER_RAM_TOTAL_SIZE             (16*1024)
#define BUFFER_RAM_ROM_GLOBAL_SIZE        (2*1024)


/* --------------------The following macros should not be modified!------------------------- */
/*****************************Determined final RAM layout**********************/
#define DATA_RAM_START_ADDR               0x00200000
#define MAIN_STACK_START_ADDR             (DATA_RAM_START_ADDR + DATA_RAM_ROM_GLOBAL_SIZE)
#define DATA_RAM_LOWSTACK_GLOBAL_ADDR     (MAIN_STACK_START_ADDR + MAIN_STACK_SIZE)
#define DATA_RAM_PROPRIETARY_GLOBAL_ADDR  (DATA_RAM_LOWSTACK_GLOBAL_ADDR + DATA_RAM_LOWSTACK_GLOBAL_SIZE)
#define DATA_RAM_PATCH_ADDR               (DATA_RAM_PROPRIETARY_GLOBAL_ADDR + DATA_RAM_PROPRIETARY_SIZE)
#define DATA_RAM_STACKPATCH_ADDR          (DATA_RAM_PATCH_ADDR + DATA_RAM_PATCH_SIZE)
#define DATA_RAM_UPPERSTACK_ADDR          (DATA_RAM_STACKPATCH_ADDR + DATA_RAM_STACKPATCH_SIZE)
#define APP_GLOBAL_ADDR                   (DATA_RAM_UPPERSTACK_ADDR + DATA_RAM_UPPERSTACK_SIZE)


#define BUFFER_RAM_START_ADDR             0x00280000
#define BUFFER_HEAP_ADDR                  (BUFFER_RAM_START_ADDR + BUFFER_RAM_ROM_GLOBAL_SIZE)
#define BUFFER_HEAP_SIZE                  (BUFFER_RAM_TOTAL_SIZE - BUFFER_RAM_ROM_GLOBAL_SIZE)


/*============================================================================*
 *                        4. Flash layout
 *============================================================================*/
#define SPIC0_ADDR                  0x00800000
#define SPIC0_SIZE                  (16*1024*1024)


/* --------------------The following macros should not be modified!------------------------- */
#define FMC_MAIN                   (0x00800000) /* SPIC0 */
#define FMC_MAIN1                  (0x06800000) /* SPIC1 */
#define SOCV_OEM_SIZE              (8 * 1024)
#define OTA_HEADER_SIZE            (4 * 1024)



/** @} */ /* End of group MEM_CONFIG_Exported_Constents */
#ifdef __cplusplus
}
#endif


/** @} */ /* End of group MEM_CONFIG */
#endif
