/**
*****************************************************************************************
*     Copyright(c) 2025, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file    mpu.h
  * @brief   configure mpu
  * @date    2025.6.12
  * @version v1.0
  * *************************************************************************************
   * @attention
   * <h2><center>&copy; COPYRIGHT 2025 Realtek Semiconductor Corporation</center></h2>
   * *************************************************************************************
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef _MPU_H_
#define _MPU_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "stdbool.h"
/** @defgroup 87x3g_MPU Memory Configure
  * @{
  */

/*============================================================================*
 *                               Types
*============================================================================*/
/** @defgroup MPU_Exported_Types MPU Exported Types
  * @{
  */

/**
    * @brief set MPU region.
    * @param  mpu_cfg_rbar     MPU Region Base Address Register (RBAR).
                                  RBAR[31:5], BASE:
                                              Base address and BIT[4:0] is zero extended.
                                  RBAR[4:3],  SH: (Shareability)
                                              0: Non-sharable
                                              1: reserved
                                              2: Outer-sharable
                                              3: Inner-sharable
                                  RBAR[2:1],  AP: (Access permissions.)
                                              0: Read/write by privileged code only
                                              1: Read/write by any privilege level
                                              2: Read-only by privileged code only
                                              3: Read-only by any privilege level
                                  RBAR[0],    XN: (Execute Never.)
                                              0: Execution only permitted if read permitted
                                              1: Execution not permitted
    * @param  limit_addr Limit Address and BIT[4:0] are fixed to 0x1F.
    * @param  region_num MPU region number (0 ~ 11).
    * @param  attribute Memory attributes.
                                  Device, Non-Bufferable:   0x00 (8'b0000_00xx, Device-nGnRnE)
                                                            0x04 (8'b0000_01xx, Device-nGnRE)
                                                            0x08 (8'b0000_10xx, Device-nGRE)
                                  Device, Bufferable:       0x0c (8'b0000_11xx, Device-GRE)
                                  Non-Cacheable:            0x44
                                  Cacheable WT:             0xAA
                                  Cacheable WB, WA:         0xff
    * @param  is_set set flag. true: set region, false: clear region.
    * @return void
    * note: When memory regions overlap, the processor generates a fault if a core access hits the overlapping regions.
    * <b>Example usage</b>
    * \code{.c}
    * int test(void)
    * {
    *     uint32_t mpu_cfg_rbar = DATA_SRAM0_ADDR | (1 << 1); // SH:0, AP:1, XN:0
    *     uint32_t limit_addr = DATA_SRAM0_ADDR + DATA_SRAM0_SIZE; // PXN:0, EN:1
    *     uint8_t region_num = 2;
    *     uint8_t attribute = 0x44;
    *
    *     mpu_config_print();
    *     mpu_set_region(mpu_cfg_rbar, limit_addr, 1, attribute, true);
    *     mpu_config_print();
    *
    *     return 0;
    * }
    * \endcode
    */
int mpu_set_region(uint32_t mpu_cfg_rbar, uint32_t limit_addr, uint8_t region_num,
                   uint8_t attribute, bool is_set);

/**
    * @brief print MPU config.
    * @param  void.
    * @return void
    */
void mpu_config_print(void);

/** @} */ /* End of group MPU_Exported_Types */

/** @} */ /* End of group 87x3g_MPU */


#ifdef __cplusplus
}
#endif

#endif /* _MPU_H_ */
