/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef _PHY_COMMON_INT_H_
#define _PHY_COMMON_INT_H_

/*============================================================================*
 *                               Header Files
 *============================================================================*/
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                              Definitions
 *============================================================================*/
#define ABS_DOUBLE(x)     (((x) > 0) ? (x) : (-1 * (x)))

/* BT Vendor Register */
#define BT_SYS_CTRL                         0x0

/* Script Parsing */
#define PHY_INIT_MODEM_REG_WRITE            0x0000
#define PHY_INIT_MODEM_REG_UPDATE           0x1000
#define PHY_INIT_RFC_REG_WRITE              0x2000
#define PHY_INIT_RFC_REG_UPDATE             0x3000
#define PHY_INIT_BLUEWIZ_REG_WRITE          0x4000
#define PHY_INIT_BLUEWIZ_REG_UPDATE         0x5000
#define PHY_INIT_LE_REG_WRITE               0x6000
#define PHY_INIT_LE_REG_UPDATE              0x7000
#define PHY_INIT_VENDOR_REG_WRITE           0x8000
#define PHY_INIT_VENDOR_REG_UPDATE          0x9000
#define PHY_INIT_DELAY_US                   0xA000
#define PHY_INIT_DELAY_MS                   0xB000
#define PHY_INIT_LCK_POLLING                0xC000
#define PHY_INIT_TPMK_POLLING               0xD000
#define PHY_INIT_IQKLOK_POLLING             0xE000
#define PHY_INIT_SET_BIT_MASK               0xF000

#define PHY_INIT_GET_REG_TYPE(x)            (x & 0xF000)
#define PHY_INIT_GET_REG_ADDR(x)            (x & 0x0FFF)
#define PHY_INIT_GET_MODEM_REG_PAGE(x)      ((x & 0x0F00) >> 8)
#define PHY_INIT_GET_MODEM_REG_ADDR(x)      (x & 0x00FF)

/*============================================================================*
 *                              Types
 *============================================================================*/
/* BT Vendor Register */
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t reserved_0_4:                      5;  //bit0~4
        uint32_t modem_rst_n:                       1;  //bit5
        uint32_t reserved_6_15:                     10; //bit6~15
        uint32_t rfc_ret_rst_n:                     1;  //bit16, RFC retention register reset
        uint32_t rfc_rst_n:                         1;  //bit17, RFC off domain register reset
        uint32_t bb_ret_rst_n:                      1;  //bit18, modem retention FF reset
        uint32_t reserved_19:                       1;  //bit19
        uint32_t dp_bb_ret_rst_n:                   1;  //bit20, modem data path retention FF reset
        uint32_t reserved_21_26:                    6;  //bit21~26
        uint32_t r_rfc_clk_force_on:                1;  //bit27, force RFC clock always on
        uint32_t reserved_28_29:                    2;  //bit28~29
        uint32_t force_adda_iso_off:                1;  //bit30, force ADDA isolation release.
        uint32_t force_adda_pwron:                  1;  //bit31, force ADDA LDO on
    };
} BT_SYS_CTRL_TYPE;

/* Script Parsing */
typedef struct
{
    const uint16_t *script;
    uint16_t size;
} PHY_SCRIPT_TYPE;

/* Txgain flatk */
typedef enum
{
    CH0_21,
    CH22_43,
    CH44_61,
    CH62_78,
    TOTAL_CH_GROUP
} CHANNEL_GROUP_TYPE;

typedef union
{
    int8_t value;
    struct
    {
        uint8_t fw_part:                2;        //[1:0] compensation by FW (TBD)
        uint8_t modem_part:             2;        //[3:2] compensation in modem
        int8_t rfc_part:                4;        //[7:4] 1dB compensation in rfc
    };
    struct
    {
        uint8_t rsvd_0p25_dB:           2;        //[1:0] don't care
        int8_t res_0p25dB_part:         6;        //[7:2] flatk, unit 0.25dB
    };
} TXGAIN_FLATK_RAW; //resolution is 0.0625dB

/*============================================================================*
 *                              Variables
 *============================================================================*/
extern void (*phy_init_script_execute)(const uint16_t *, uint16_t);

/*============================================================================*
 *                              Functions
 *============================================================================*/
void phy_error_function(void);

#ifdef __cplusplus
}
#endif

#endif /* _PHY_COMMON_INT_H_ */

