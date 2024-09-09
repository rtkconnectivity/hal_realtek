#ifndef _RTL876X_AON_REG_H
#define _RTL876X_AON_REG_H
#include <stdint.h>

/* Auto gen based on RL6950_All_register_table_230217D.xlsx */
#define AON_REG_AON_RG0X    0x0
#define AON_REG_AON_RG1X    0x4
#define AON_REG_AON_RG2X    0x8
#define AON_REG_AON_RG3X    0xc
#define AON_REG_AON_RG4X    0x18
#define AON_REG_AON_RG5X    0x1c
#define AON_FAST_REG_REG0X_FW_GENERAL               0x0
#define AON_FAST_REG_REG1X_FW_GENERAL               0x2
#define AON_FAST_REG_REG2X_FW_GENERAL               0x4
#define AON_FAST_REG_0x5                            0x5
#define AON_FAST_REG_REG3X_FW_GENERAL               0x6
#define AON_FAST_DEBUG_PASSWORD                     0x8    // 0x8 ~ 0x17 store the debug password
#define AON_FAST_REG_REG5X_FW_GENERAL               0xa
#define AON_FAST_REG_REG6X_FW_GENERAL               0xc
#define AON_FAST_REG_REG7X_FW_GENERAL               0xe
#define AON_FAST_REG_REG8X_FW_GENERAL               0x10
#define AON_FAST_REG_REG9X_FW_GENERAL               0x12
#define AON_FAST_REG_REG10X_FW_GENERAL              0x14
#define AON_FAST_REG_REG11X_FW_GENERAL              0x16
#define AON_FAST_REG_REG0X_AON_SYS                  0x18
#define AON_FAST_REG_RO_EXTRA_DELAY_XTAL            0x1a
#define AON_FAST_REG_RO_WK_REG0X                    0x1c
#define AON_FAST_REG_REG1X_AON_SYS                  0x24
#define AON_FAST_REG_REG2X_AON_SYS                  0x26
#define AON_FAST_REG_REG0X_XPDCK                    0x28
#define AON_FAST_REG_REG0X_DEBIO                    0x2a
#define AON_FAST_REG_REG0X_BUCK                     0x30
#define AON_FAST_REG_REG1X_BUCK                     0x32
#define AON_FAST_REG_REG2X_BUCK                     0x34
#define AON_FAST_REG_REG3X_BUCK                     0x36
#define AON_FAST_REG_REG4X_BUCK                     0x38
#define AON_FAST_REG_REG5X_BUCK                     0x3a
#define AON_FAST_REG_REG6X_BUCK                     0x3c
#define AON_FAST_REG_REG7X_BUCK                     0x3e
#define AON_FAST_REG_REG8X_BUCK                     0x40
#define AON_FAST_REG_CKOUT0X_BUCK                   0x42
#define AON_FAST_REG_CKOUT1X_BUCK                   0x44
#define AON_FAST_REG_REG0X_LDO                      0x46
#define AON_FAST_REG_REG1X_LDO                      0x48
#define AON_FAST_REG_REG2X_LDO                      0x4a
#define AON_FAST_REG_REG3X_LDO                      0x4c
#define AON_FAST_REG_REG4X_LDO                      0x4e
#define AON_FAST_REG_CKOUT0X_LDO                    0x50
#define AON_FAST_REG_REG0X_MBIAS                    0x52
#define AON_FAST_REG_REG1X_MBIAS                    0x54
#define AON_FAST_REG_REG2X_MBIAS                    0x56
#define AON_FAST_REG_REG3X_MBIAS                    0x58
#define AON_FAST_REG_REG4X_MBIAS                    0x5a
#define AON_FAST_REG_CKOUT0X_MBIAS                  0x5c
#define AON_FAST_REG_REG0X_EFUSE                    0x5e
#define AON_FAST_REG_CORE_FLASH_PC                  0x60
#define AON_FAST_REG_REG0X_P1_5_CFG                 0x80
#define AON_FAST_REG_REG0X_P1_6_CFG                 0x82
#define AON_FAST_REG_REG0X_P1_7_CFG                 0x84
#define AON_FAST_REG_REG0X_P3_0_CFG                 0x86
#define AON_FAST_REG_REG0X_P3_1_CFG                 0x88
#define AON_FAST_REG_REG0X_P3_2_CFG                 0x8a
#define AON_FAST_REG_REG0X_P3_3_CFG                 0x8c
#define AON_FAST_REG_REG0X_P3_4_CFG                 0x8e
#define AON_FAST_REG_REG0X_P3_5_CFG                 0x90
#define AON_FAST_REG_REG0X_P3_6_CFG                 0x92
#define AON_FAST_REG_REG0X_P5_1_CFG                 0x96
#define AON_FAST_REG_REG0X_P5_2_CFG                 0x98
#define AON_FAST_REG_REG0X_TOP_PAD_STS              0x9a
#define AON_FAST_REG_REG0X_TOP_PAD_CFG              0x9c
#define AON_FAST_REG_REG0X_P0_5_CFG                 0xa0
#define AON_FAST_REG_REG0X_P0_6_CFG                 0xa2
#define AON_FAST_REG_REG0X_P0_7_CFG                 0xa4
#define AON_FAST_REG_REG0X_P4_0_CFG                 0xa6
#define AON_FAST_REG_REG0X_P4_1_CFG                 0xa8
#define AON_FAST_REG_REG0X_P4_2_CFG                 0xaa
#define AON_FAST_REG_REG0X_P4_3_CFG                 0xac
#define AON_FAST_REG_REG0X_BOT_PAD_STS              0xae
#define AON_FAST_REG_REG0X_P2_0_CFG                 0xc0
#define AON_FAST_REG_REG0X_P2_1_CFG                 0xc2
#define AON_FAST_REG_REG0X_P2_2_CFG                 0xc4
#define AON_FAST_REG_REG0X_P2_3_CFG                 0xc6
#define AON_FAST_REG_REG0X_P2_4_CFG                 0xc8
#define AON_FAST_REG_REG0X_P2_5_CFG                 0xca
#define AON_FAST_REG_REG0X_P2_6_CFG                 0xcc
#define AON_FAST_REG_REG0X_P2_7_CFG                 0xce
#define AON_FAST_REG_REG0X_P_MICBIAS_CFG            0xd0
#define AON_FAST_REG_REG0X_LEFT_PAD_STS             0xd2
#define AON_FAST_REG_REG0X_LEFT_PAD_CFG             0xd4
#define AON_FAST_REG_REG0X_P0_0_CFG                 0xe0
#define AON_FAST_REG_REG0X_P0_1_CFG                 0xe2
#define AON_FAST_REG_REG0X_P0_2_CFG                 0xe4
#define AON_FAST_REG_REG0X_P0_3_CFG                 0xe6
#define AON_FAST_REG_REG0X_P0_4_CFG                 0xe8
#define AON_FAST_REG_REG0X_P1_0_CFG                 0xea
#define AON_FAST_REG_REG0X_P1_1_CFG                 0xec
#define AON_FAST_REG_REG0X_P1_2_CFG                 0xee
#define AON_FAST_REG_REG0X_P1_3_CFG                 0xf0
#define AON_FAST_REG_REG0X_P1_4_CFG                 0xf2
#define AON_FAST_REG_REG0X_RIGHT_PAD_STS            0xf4
#define AON_FAST_REG_REG0X_P_SPI_CFG                0xf6
#define AON_FAST_REG_REG0X_RIGHT_PAD_CFG            0xf8
#define AON_FAST_REG_RG0X_32KOSC                    0x106
#define AON_FAST_REG_RG1X_32KOSC                    0x10a
#define AON_FAST_REG_REG0X_AUX_LDO                  0x110
#define AON_FAST_REG_REG1X_AUX_LDO                  0x112
#define AON_FAST_REG_REG0X_SD                       0x114
#define AON_FAST_REG_REG0X_AUX                      0x116
#define AON_FAST_REG_REG1X_AUX                      0x118
#define AON_FAST_REG_AUX_CONTROL                    0x11a
#define AON_FAST_REG_BT_ANAPAR_LDO_ADDA             0x120
#define AON_FAST_REG_BT_ANAPAR_XTAL_MODE            0x140
#define AON_FAST_REG_BT_ANAPAR_XTAL0                0x142
#define AON_FAST_REG_BT_ANAPAR_XTAL1                0x144
#define AON_FAST_REG_BT_ANAPAR_XTAL2                0x146
#define AON_FAST_REG_BT_ANAPAR_XTAL3                0x148
#define AON_FAST_REG_BT_ANAPAR_XTAL4                0x14a
#define AON_FAST_REG_BT_ANAPAR_XTAL5                0x14c
#define AON_FAST_REG_BT_ANAPAR_XTAL6                0x14e
#define AON_FAST_REG_BT_ANAPAR_XTAL7                0x150
#define AON_FAST_REG_BT_ANAPAR_XTAL8                0x152
#define AON_FAST_REG_BT_ANAPAR_XTAL9                0x154
#define AON_FAST_REG_BT_ANAPAR_XTAL10               0x156
#define AON_FAST_REG_BT_ANAPAR_XTAL11               0x158
#define AON_FAST_REG_BT_ANAPAR_XTAL12               0x15a
#define AON_FAST_REG_BT_ANAPAR_XTAL13               0x15c
#define AON_FAST_REG_BT_ANAPAR_XTAL14               0x15e
#define AON_FAST_REG_BT_ANAPAR_XTAL15               0x160
#define AON_FAST_REG_BT_ANAPAR_XTAL16               0x162
#define AON_FAST_REG_BT_ANAPAR_XTAL17               0x164
#define AON_FAST_REG_REG0X_XTAL                     0x166
#define AON_FAST_REG_REG1X_XTAL                     0x168
#define AON_FAST_REG_AON_REG_LOP_PON_RG0X           0x180
#define AON_FAST_REG_AON_REG_LOP_PON_RG1X           0x182
#define AON_FAST_REG_AON_REG_LOP_PON_RG2X           0x184
#define AON_FAST_REG_AON_REG_LOP_PON_RG3X           0x186
#define AON_FAST_REG_AON_REG_LOP_PON_RG4X           0x188
#define AON_FAST_REG_AON_REG_LOP_PON_RG5X           0x18a
#define AON_FAST_REG_AON_REG_LOP_POF_RG0X           0x190
#define AON_FAST_REG_AON_REG_LOP_POF_RG1X           0x192
#define AON_FAST_REG_AON_REG_LOP_POF_RG2X           0x194
#define AON_FAST_REG_AON_REG_LOP_POF_RG3X           0x196
#define AON_FAST_REG_AON_REG_LOP_POF_RG4X           0x198
#define AON_FAST_REG_AON_REG_LOP_POF_RG5X           0x19a
#define AON_FAST_REG_AON_REG_LOP_RG0X               0x1a0
#define AON_FAST_REG_AON_REG_LOP_RG1X               0x1a2
#define AON_FAST_REG_AON_REG_LOP_RG2X               0x1a4
#define AON_FAST_REG_AON_REG_LOP_RG3X               0x1a6
#define AON_FAST_REG_FAON_READ_RG0X                 0x1c0
#define AON_FAST_REG_FAON_READ_RG1X                 0x1c2
#define AON_FAST_REG_FAON_READ_RG2X                 0x1c4
#define AON_FAST_REG_FAON_READ_RG3X                 0x1c6
#define AON_FAST_REG_FAON_READ_RG4X                 0x1c8
#define AON_FAST_REG_FAON_READ_RG5X                 0x1ca
#define AON_FAST_REG_FAON_READ_RG6X                 0x1cc
#define AON_FAST_REG_FAON_READ_RG7X                 0x1ce
#define AON_FAST_REG_FAON_READ_RG8X                 0x1d0
#define AON_FAST_REG_FAON_READ_RG9X                 0x1d2
#define AON_FAST_REG_FAON_READ_RG10X                0x1d4
#define AON_FAST_REG_FAON_READ_RG11X                0x1d6
#define AON_FAST_REG_REG0X_LDO_VDDANA_POS           0x1e0
#define AON_FAST_REG_REG1X_LDO_VDDANA_POS           0x1e2
#define AON_FAST_REG_REG2X_LDO_VDDANA_POS           0x1e4
#define AON_FAST_REG_REG3X_LDO_VDDANA_POS           0x1e6
#define AON_FAST_REG_REG4X_LDO_VDDANA_POS           0x1e8
#define AON_FAST_REG_REG5X_LDO_VDDANA_POS           0x1ea
#define AON_FAST_REG_REG6X_LDO_VDDANA_POS           0x1ec
#define AON_FAST_REG_REG7X_LDO_VDDANA_POS           0x1ee
#define AON_FAST_REG_C_KOUT0X_LDO_VDDANA_POS        0x1f0
#define AON_FAST_REG_C_KOUT1X_LDO_VDDANA_POS        0x1f2
#define AON_FAST_REG_REG0X_LDO_VDDCORE_POS          0x1f4
#define AON_FAST_REG_REG1X_LDO_VDDCORE_POS          0x1f6
#define AON_FAST_REG_REG2X_LDO_VDDCORE_POS          0x1f8
#define AON_FAST_REG_REG3X_LDO_VDDCORE_POS          0x1fa
#define AON_FAST_REG_REG4X_LDO_VDDCORE_POS          0x1fc
#define AON_FAST_REG_REG5X_LDO_VDDCORE_POS          0x1fe
#define AON_FAST_REG_REG6X_LDO_VDDCORE_POS          0x200
#define AON_FAST_REG_REG7X_LDO_VDDCORE_POS          0x202
#define AON_FAST_REG_C_KOUT0X_LDO_VDDCORE_POS       0x204
#define AON_FAST_REG_C_KOUT1X_LDO_VDDCORE_POS       0x206
#define AON_FAST_REG_REG0X_LDO_ANA_POS              0x208
#define AON_FAST_REG_REG1X_LDO_ANA_POS              0x20a
#define AON_FAST_REG_REG2X_LDO_ANA_POS              0x20c
#define AON_FAST_REG_REG3X_LDO_ANA_POS              0x20e
#define AON_FAST_REG_REG4X_LDO_ANA_POS              0x210
#define AON_FAST_REG_REG5X_LDO_ANA_POS              0x212
#define AON_FAST_REG_REG6X_LDO_ANA_POS              0x214
#define AON_FAST_REG_REG7X_LDO_ANA_POS              0x216
#define AON_FAST_REG_C_KOUT0X_LDO_ANA_POS           0x218
#define AON_FAST_REG_C_KOUT1X_LDO_ANA_POS           0x21a
#define AON_FAST_REG_REG0X_SWR_VDDANA_VREF_POS      0x21c
#define AON_FAST_REG_REG1X_SWR_VDDANA_VREF_POS      0x21e
#define AON_FAST_REG_REG2X_SWR_VDDANA_VREF_POS      0x220
#define AON_FAST_REG_REG3X_SWR_VDDANA_VREF_POS      0x222
#define AON_FAST_REG_REG4X_SWR_VDDANA_VREF_POS      0x224
#define AON_FAST_REG_REG5X_SWR_VDDANA_VREF_POS      0x226
#define AON_FAST_REG_REG6X_SWR_VDDANA_VREF_POS      0x228
#define AON_FAST_REG_REG7X_SWR_VDDANA_VREF_POS      0x22a
#define AON_FAST_REG_C_KOUT0X_SWR_VDDANA_VREF_POS   0x22c
#define AON_FAST_REG_C_KOUT1X_SWR_VDDANA_VREF_POS   0x22e
#define AON_FAST_REG_REG0X_SWR_VDDANA_VDIV_POS      0x230
#define AON_FAST_REG_REG1X_SWR_VDDANA_VDIV_POS      0x232
#define AON_FAST_REG_REG2X_SWR_VDDANA_VDIV_POS      0x234
#define AON_FAST_REG_REG3X_SWR_VDDANA_VDIV_POS      0x236
#define AON_FAST_REG_REG4X_SWR_VDDANA_VDIV_POS      0x238
#define AON_FAST_REG_REG5X_SWR_VDDANA_VDIV_POS      0x23a
#define AON_FAST_REG_REG6X_SWR_VDDANA_VDIV_POS      0x23c
#define AON_FAST_REG_REG7X_SWR_VDDANA_VDIV_POS      0x23e
#define AON_FAST_REG_C_KOUT0X_SWR_VDDANA_VDIV_POS   0x240
#define AON_FAST_REG_C_KOUT1X_SWR_VDDANA_VDIV_POS   0x242
#define AON_FAST_REG_REG0X_SWR_VDDCORE_VREF_POS     0x244
#define AON_FAST_REG_REG1X_SWR_VDDCORE_VREF_POS     0x246
#define AON_FAST_REG_REG2X_SWR_VDDCORE_VREF_POS     0x248
#define AON_FAST_REG_REG3X_SWR_VDDCORE_VREF_POS     0x24a
#define AON_FAST_REG_REG4X_SWR_VDDCORE_VREF_POS     0x24c
#define AON_FAST_REG_REG5X_SWR_VDDCORE_VREF_POS     0x24e
#define AON_FAST_REG_REG6X_SWR_VDDCORE_VREF_POS     0x250
#define AON_FAST_REG_REG7X_SWR_VDDCORE_VREF_POS     0x252
#define AON_FAST_REG_C_KOUT0X_SWR_VDDCORE_VREF_POS  0x254
#define AON_FAST_REG_C_KOUT1X_SWR_VDDCORE_VREF_POS  0x256
#define AON_FAST_REG_REG0X_SWR_VDDCORE_VDIV_POS     0x258
#define AON_FAST_REG_REG1X_SWR_VDDCORE_VDIV_POS     0x25a
#define AON_FAST_REG_REG2X_SWR_VDDCORE_VDIV_POS     0x25c
#define AON_FAST_REG_REG3X_SWR_VDDCORE_VDIV_POS     0x25e
#define AON_FAST_REG_REG4X_SWR_VDDCORE_VDIV_POS     0x260
#define AON_FAST_REG_REG5X_SWR_VDDCORE_VDIV_POS     0x262
#define AON_FAST_REG_REG6X_SWR_VDDCORE_VDIV_POS     0x264
#define AON_FAST_REG_REG7X_SWR_VDDCORE_VDIV_POS     0x266
#define AON_FAST_REG_C_KOUT0X_SWR_VDDCORE_VDIV_POS  0x268
#define AON_FAST_REG_C_KOUT1X_SWR_VDDCORE_VDIV_POS  0x26a
#define AON_FAST_REG_REG_SRAM_CTRL1                 0x280
#define AON_FAST_REG_REG_SRAM_CTRL2                 0x282
#define AON_FAST_REG_REG_SRAM_CTRL3                 0x284
#define AON_FAST_REG_REG_SRAM_CTRL4                 0x286
#define AON_FAST_REG_REG_SRAM_CTRL5                 0x288
#define AON_FAST_REG_REG_SRAM_CTRL6                 0x28a
#define AON_FAST_REG_REG_SRAM_CTRL7                 0x28c
#define AON_FAST_REG_REG_SRAM_CTRL8                 0x28e
#define AON_FAST_REG_REG_SRAM_CTRL9                 0x290
#define AON_FAST_REG_REG_SRAM_CTRL10                0x292
#define AON_FAST_REG_REG_SRAM_CTRL11                0x294
#define AON_FAST_REG_REG_SRAM_CTRL12                0x296
#define AON_FAST_REG_REG_SRAM_CTRL13                0x298
#define AON_FAST_REG_REG_SRAM_CTRL14                0x29a
#define AON_FAST_REG_REG_SRAM_CTRL15                0x29c
#define AON_FAST_REG_REG_SRAM_CTRL16                0x29e
#define AON_FAST_REG_REG_SRAM_CTRL17                0x2a0
#define AON_FAST_REG_REG_SRAM_CTRL18                0x2a2
#define AON_FAST_REG_REG_SRAM_CTRL19                0x2a4
#define AON_FAST_REG_REG_SRAM_CTRL20                0x2a6
/* 0x0      0x4000_0000
    0       R/W PMU_ST_PON_RET_DMY              1'b0
    2:1     R/W PMU_ST_PON_RST_DMY[1:0]         2'b00
    4:3     R/W PMU_ST_PON_CORE_DMY[1:0]        2'b00
    6:5     R/W PMU_ST_PON_POS_DMY[1:0]         2'b00
    9:7     R/W PMU_ST_PON_SWR_DMY[2:0]         3'b000
    12:10   R/W PMU_ST_PON_SWR_BIAS_DMY[2:0]    3'b000
    14:13   R/W PMU_ST_PON_BIAS_DMY[1:0]        2'b10
    15      R/W BUCK_EN_FLASH_PD_DISCHG         1'b1
    16      R/W LDO_POW_LDORET                  1'b0
    17      R/W LDO_POW_BIAS_LDOANA             1'b0
    18      R/W LDO_ENPC_LDOANA                 1'b0
    19      R/W LDO_POW_LDOANA                  1'b0
    20      R/W LDO_POW_VDDANA                  1'b0
    21      R/W LDO_POW_VDDCORE                 1'b0
    22      R/W FLASH_PC_VG2                    1'b1
    23      R/W FLASH_PC_VG1                    1'b1
    24      R/W LDO_EN_VAON_VANA_PC             1'b0
    25      R/W LDO_EN_LDO311_DMY_LITE          1'b1
    26      R/W LDO_POW_LDO311                  1'b1
    27      R/W LDO_EN_LDO311_VDIV              1'b1
    28      R/W MBIAS_POR_VIO_EN                1'b1
    29      R/W MBIAS_POR_DVDDCORE_EN           1'b0
    30      R/W MBIAS_POW_BG_EBIAS_AUXADC       1'b0
    31      R/W MBIAS_BIAS50NA_EN               1'b0
 */
typedef volatile union _AON_REG_AON_RG0X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t PMU_ST_PON_RET_DMY: 1;
        uint32_t PMU_ST_PON_RST_DMY_1_0: 2;
        uint32_t PMU_ST_PON_CORE_DMY_1_0: 2;
        uint32_t PMU_ST_PON_POS_DMY_1_0: 2;
        uint32_t PMU_ST_PON_SWR_DMY_2_0: 3;
        uint32_t PMU_ST_PON_SWR_BIAS_DMY_2_0: 3;
        uint32_t PMU_ST_PON_BIAS_DMY_1_0: 2;
        uint32_t BUCK_EN_FLASH_PD_DISCHG: 1;
        uint32_t LDO_POW_LDORET: 1;
        uint32_t LDO_POW_BIAS_LDOANA: 1;
        uint32_t LDO_ENPC_LDOANA: 1;
        uint32_t LDO_POW_LDOANA: 1;
        uint32_t LDO_POW_VDDANA: 1;
        uint32_t LDO_POW_VDDCORE: 1;
        uint32_t FLASH_PC_VG2: 1;
        uint32_t FLASH_PC_VG1: 1;
        uint32_t LDO_EN_VAON_VANA_PC: 1;
        uint32_t LDO_EN_LDO311_DMY_LITE: 1;
        uint32_t LDO_POW_LDO311: 1;
        uint32_t LDO_EN_LDO311_VDIV: 1;
        uint32_t MBIAS_POR_VIO_EN: 1;
        uint32_t MBIAS_POR_DVDDCORE_EN: 1;
        uint32_t MBIAS_POW_BG_EBIAS_AUXADC: 1;
        uint32_t MBIAS_BIAS50NA_EN: 1;
    };
} AON_REG_AON_RG0X_TYPE;

/* 0x4      0x4000_0004
    4:0     R/W LDO_VDDANA_TUNE_VDIV            5'b10100
    5       R/W AON_RG1X_DUMMY[5]               1'b0
    6       R/W LDO_POW_BIAS_VDDANA             1'b0
    7       R/W LDO_POW_BIAS_VDDCORE            1'b0
    12:8    R/W LDO_VDDCORE_TUNE_VDIV           5'b01110
    13      R/W AON_RG1X_DUMMY[13]              1'b0
    14      R/W SEL_IPTAT                       1'b0
    15      R/W SEL_LV                          1'b0
    16      R/W ISO_DIG_40M                     1'b1
    20:17   R/W REG1X_BUCK_DUMMY[3:0]           4'b0000
    21      R/W BUCK_SEL_LPPFM2                 1'b0
    22      R/W BUCK_SEL_LPPFM1                 1'b0
    23      R/W BUCK_POW_SWR                    1'b0
    24      R/W BUCK_POW_PFM2_LQ                1'b0
    25      R/W BUCK_POW_PFM1_LQ                1'b0
    26      R/W BUCK_POW_PFM2_HQ                1'b0
    27      R/W BUCK_POW_PFM1_HQ                1'b0
    28      R/W BUCK_POW_VDIV2_LQ               1'b0
    29      R/W BUCK_POW_VDIV1_LQ               1'b0
    30      R/W BUCK_POW_VDIV2                  1'b0
    31      R/W BUCK_POW_VDIV1                  1'b0
 */
typedef volatile union _AON_REG_AON_RG1X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t LDO_VDDANA_TUNE_VDIV: 5;
        uint32_t AON_RG1X_DUMMY_5: 1;
        uint32_t LDO_POW_BIAS_VDDANA: 1;
        uint32_t LDO_POW_BIAS_VDDCORE: 1;
        uint32_t LDO_VDDCORE_TUNE_VDIV: 5;
        uint32_t AON_RG1X_DUMMY_13: 1;
        uint32_t SEL_IPTAT: 1;
        uint32_t SEL_LV: 1;
        uint32_t ISO_DIG_40M: 1;
        uint32_t REG1X_BUCK_DUMMY_3_0: 4;
        uint32_t BUCK_SEL_LPPFM2: 1;
        uint32_t BUCK_SEL_LPPFM1: 1;
        uint32_t BUCK_POW_SWR: 1;
        uint32_t BUCK_POW_PFM2_LQ: 1;
        uint32_t BUCK_POW_PFM1_LQ: 1;
        uint32_t BUCK_POW_PFM2_HQ: 1;
        uint32_t BUCK_POW_PFM1_HQ: 1;
        uint32_t BUCK_POW_VDIV2_LQ: 1;
        uint32_t BUCK_POW_VDIV1_LQ: 1;
        uint32_t BUCK_POW_VDIV2: 1;
        uint32_t BUCK_POW_VDIV1: 1;
    };
} AON_REG_AON_RG1X_TYPE;

/* 0x8      0x4000_0008
    0       R/W AON_RG2X_DUMMY[0]               1'b0
    1       R/W SWR_VDDCORE_VDIV_POS_EXT_RST_B  1'b0
    2       R/W SWR_VDDANA_VDIV_POS_EXT_RST_B   1'b0
    3       R/W SWR_VDDCORE_VREF_POS_EXT_RST_B  1'b0
    4       R/W SWR_VDDANA_VREF_POS_EXT_RST_B   1'b0
    5       R/W LDO_ANA_POS_EXT_RST_B           1'b0
    6       R/W LDO_VDDCORE_POS_EXT_RST_B       1'b0
    7       R/W LDO_VDDANA_POS_EXT_RST_B        1'b0
    8       R/W AON_RG2X_DUMMY[8]               1'b0
    9       R/W SWR_VDDCORE_VDIV_POS_EN_POS     1'b0
    10      R/W SWR_VDDANA_VDIV_POS_EN_POS      1'b0
    11      R/W SWR_VDDCORE_VREF_POS_EN_POS     1'b0
    12      R/W SWR_VDDANA_VREF_POS_EN_POS      1'b0
    13      R/W LDO_ANA_POS_EN_POS              1'b0
    14      R/W LDO_VDDCORE_POS_EN_POS          1'b0
    15      R/W LDO_VDDANA_POS_EN_POS           1'b0
    16      R/W BT_anapar_pow_xtal              1'b0
    19:17   R/W XTAL_MODE                       3'b000
    20      R/W POW_32KOSC                      1'b1
    21      R/W POW_OSC40                       1'b0
    22      R/W AON_GATED_EN                    1'b1
    23      R/W LDO_ENB_DMYL_200U_LDOANA        1'b1
    28:24   R/W LDO_TUNE_LDOANA                 5'b10100
    29      R/W MBIAS_POR_VIO_SIG_SEL           1'b0
    30      R/W VCORE_PC_VG2                    1'b1
    31      R/W VCORE_PC_VG1                    1'b1
 */
typedef volatile union _AON_REG_AON_RG2X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t AON_RG2X_DUMMY_0: 1;
        uint32_t SWR_VDDCORE_VDIV_POS_EXT_RST_B: 1;
        uint32_t SWR_VDDANA_VDIV_POS_EXT_RST_B: 1;
        uint32_t SWR_VDDCORE_VREF_POS_EXT_RST_B: 1;
        uint32_t SWR_VDDANA_VREF_POS_EXT_RST_B: 1;
        uint32_t LDO_ANA_POS_EXT_RST_B: 1;
        uint32_t LDO_VDDCORE_POS_EXT_RST_B: 1;
        uint32_t LDO_VDDANA_POS_EXT_RST_B: 1;
        uint32_t AON_RG2X_DUMMY_8: 1;
        uint32_t SWR_VDDCORE_VDIV_POS_EN_POS: 1;
        uint32_t SWR_VDDANA_VDIV_POS_EN_POS: 1;
        uint32_t SWR_VDDCORE_VREF_POS_EN_POS: 1;
        uint32_t SWR_VDDANA_VREF_POS_EN_POS: 1;
        uint32_t LDO_ANA_POS_EN_POS: 1;
        uint32_t LDO_VDDCORE_POS_EN_POS: 1;
        uint32_t LDO_VDDANA_POS_EN_POS: 1;
        uint32_t BT_anapar_pow_xtal: 1;
        uint32_t XTAL_MODE: 3;
        uint32_t POW_32KOSC: 1;
        uint32_t POW_OSC40: 1;
        uint32_t AON_GATED_EN: 1;
        uint32_t LDO_ENB_DMYL_200U_LDOANA: 1;
        uint32_t LDO_TUNE_LDOANA: 5;
        uint32_t MBIAS_POR_VIO_SIG_SEL: 1;
        uint32_t VCORE_PC_VG2: 1;
        uint32_t VCORE_PC_VG1: 1;
    };
} AON_REG_AON_RG2X_TYPE;

/* 0xc      0x4000_000c
    31:0    R   reserved                        32'h0
 */
typedef volatile union _AON_REG_AON_RG3X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t reserved;
    };
} AON_REG_AON_RG3X_TYPE;

/* 0x18     0x4000_0018
    8:0     R/W AON_RG4X_DUMMY[8:0]             9'h0
    9       R/W EFUSE_RSTB                      1'b0
    10      R/W ZB_STORE                        1'b0
    11      R/W ZB_RESTORE                      1'b0
    12      R/W RFC_STORE                       1'b0
    13      R/W RFC_RESTORE                     1'b0
    14      R/W MODEM_STORE                     1'b0
    15      R/W MODEM_RESTORE                   1'b0
    16      R/W BZ_STORE                        1'b0
    17      R/W BZ_RESTORE                      1'b0
    18      R/W BLE_STORE                       1'b0
    19      R/W BLE_RESTORE                     1'b0
    20      R/W PF_STORE                        1'b0
    21      R/W PF_RESTORE                      1'b0
    22      R/W DP_MODEM_STORE                  1'b0
    23      R/W DP_MODEM_RESTORE                1'b0
    24      R/W BT_CORE_RSTB                    1'b0
    25      R/W BT_PON_RSTB                     1'b0
    26      R/W BT_RET_RSTB                     1'b1
    27      R/W ISO_XTAL                        1'b1
    28      R/W ISO_BT_CORE                     1'b1
    29      R/W ISO_BT_PON                      1'b1
    30      R/W ISO_VDDON_XTAL                  1'b1
    31      R/W ISO_OSC                         1'b1
 */
typedef volatile union _AON_REG_AON_RG4X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t AON_RG4X_DUMMY_8_0: 9;
        uint32_t EFUSE_RSTB: 1;
        uint32_t ZB_STORE: 1;
        uint32_t ZB_RESTORE: 1;
        uint32_t RFC_STORE: 1;
        uint32_t RFC_RESTORE: 1;
        uint32_t MODEM_STORE: 1;
        uint32_t MODEM_RESTORE: 1;
        uint32_t BZ_STORE: 1;
        uint32_t BZ_RESTORE: 1;
        uint32_t BLE_STORE: 1;
        uint32_t BLE_RESTORE: 1;
        uint32_t PF_STORE: 1;
        uint32_t PF_RESTORE: 1;
        uint32_t DP_MODEM_STORE: 1;
        uint32_t DP_MODEM_RESTORE: 1;
        uint32_t BT_CORE_RSTB: 1;
        uint32_t BT_PON_RSTB: 1;
        uint32_t BT_RET_RSTB: 1;
        uint32_t ISO_XTAL: 1;
        uint32_t ISO_BT_CORE: 1;
        uint32_t ISO_BT_PON: 1;
        uint32_t ISO_VDDON_XTAL: 1;
        uint32_t ISO_OSC: 1;
    };
} AON_REG_AON_RG4X_TYPE;

/* 0x1c     0x4000_001c
    0       R/W FW_enter_lps                    1'b0
    1       R/W FW_PON_SEQ_RST_N                1'b0
    31:2    R   reserved                        30'h0
 */
typedef volatile union _AON_REG_AON_RG5X_TYPE
{
    uint32_t d32;
    struct
    {
        uint32_t FW_enter_lps: 1;
        uint32_t FW_PON_SEQ_RST_N: 1;
        uint32_t reserved: 30;
    };
} AON_REG_AON_RG5X_TYPE;

/* 0x0
    6:0     R/W freg0[6:0]                              7'h0
    7       W1P reg_rom_trace_prot                      1'h0
    15:8    R   reserved                                8'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_FW_GENERAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t aon_boot_done : 1;
        uint16_t pon_boot_done : 1;
        uint16_t rsvd : 5;
        uint16_t reg_rom_trace_port : 1;
        uint16_t is_disable_set_reg_by_otp: 1;
        uint16_t RESERVED_0: 7;
    };
} AON_FAST_REG_REG0X_FW_GENERAL_TYPE;

/* 0x2
    15:0    R/W freg1                                   16'h0
 */
typedef volatile union _AON_FAST_REG_REG1X_FW_GENERAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t is_airplane_mode : 1;      /* bit[0]: is airplane mode ?                   */
        uint16_t is_rom_code_patch : 1;     /* bit[1]: is rom code patch ?                  */
        uint16_t is_fw_trig_wdg_to : 1;     /* bit[2]: does fw trigger watchdog timeout ?   */
        uint16_t is_h5_link_reset : 1;      /* bit[3]: does h5 link reset ?                 */
        uint16_t is_send_patch_end_evt : 1; /* bit[4]: does we send patch end event ?       */
        uint16_t is_ota : 1;                /* bit[5]: enter ota mode after reset           */
        uint16_t is_ft_mode : 1;            /* bit[6]: is FT mode ?                         */
        uint16_t is_hci_mode : 1;           /* bit[7]: switch to hci mode?                  */
        uint16_t is_password_mpl_cmd: 1;    /* bit[8]: is password mpl cmd?                 */
        uint16_t XTAL_GM_OUT : 6;
        uint16_t reserved : 1;              /* have not been used                           */
    };
} AON_FAST_REG_REG1X_FW_GENERAL_TYPE;

/* 0x4
    15:0    R/W freg2                                   16'h0
 */
typedef volatile union _AON_FAST_REG_REG2X_FW_GENERAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t efuse_invalid_cnt : 4; /* bit[3:0]: efuse invalid retry fail count */
        uint16_t flash_invalid_cnt : 4; /* bit[7:4]: flash invalid retry fail count */
        uint16_t reserved : 8;         /* have not been used                        */
    };
} AON_FAST_REG_REG2X_FW_GENERAL_TYPE;

/* 0x6
    0       w1o is_disable_hci_read_chip_info       1'b0
    1       w1o is_disable_hci_mac_rf_access        1'b0
    2       w1o is_disable_hci_wifi_coexist_func    1'b0
    3       w1o is_disable_hci_set_uart_baudrate    1'b0
    4       w1o is_disable_hci_bt_extension         1'b0
    5       w1o is_disable_hci_bt_dbg_func          1'b0
    6       w1o is_disable_hci_bt_test              1'b0
    7       w1o is_disable_mpl_flash_access         1'b0
    8       w1o is_disable_mpl_system_access        1'b0
    9       w1o is_disable_mpl_otp_access           1'b0
    10      w1o is_disable_hci_rf_dbg_func          1'b0
    11      w1o is_disable_hci_rf_test              1'b0
    15:12   w1o reserved                            4'h0
 */
typedef volatile union _AON_FAST_REG_REG3X_FW_GENERAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t is_disable_hci_read_chip_info: 1;
        uint16_t is_disable_hci_mac_rf_access: 1;
        uint16_t is_disable_hci_wifi_coexist_func: 1;
        uint16_t is_disable_hci_set_uart_baudrate: 1;
        uint16_t is_disable_hci_bt_extension: 1;
        uint16_t is_disable_hci_bt_dbg_func: 1;
        uint16_t is_disable_hci_bt_test: 1;
        uint16_t is_disable_mpl_flash_access: 1;
        uint16_t is_disable_mpl_system_access: 1;
        uint16_t is_disable_mpl_otp_access: 1;
        uint16_t is_disable_hci_rf_dbg_func: 1;
        uint16_t is_disable_hci_rf_test: 1;
        uint16_t reserved: 4;
    };
} AON_FAST_REG_REG3X_FW_GENERAL_TYPE;

/* 0x8
    15:0    w1o freg4                                   16'h0
 */
typedef volatile union _AON_FAST_REG_REG4X_FW_GENERAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t freg4;
    };
} AON_FAST_REG_REG4X_FW_GENERAL_TYPE;

/* 0xa
    15:0    R/W freg5                                   16'h0
 */
typedef volatile union _AON_FAST_REG_REG5X_FW_GENERAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t freg5;
    };
} AON_FAST_REG_REG5X_FW_GENERAL_TYPE;

/* 0xc
    15:0    R/W freg6                                   16'h0
 */
typedef volatile union _AON_FAST_REG_REG6X_FW_GENERAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t freg6;
    };
} AON_FAST_REG_REG6X_FW_GENERAL_TYPE;

/* 0xe
    15:0    R/W freg7                                   16'h0
 */
typedef volatile union _AON_FAST_REG_REG7X_FW_GENERAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t freg7;
    };
} AON_FAST_REG_REG7X_FW_GENERAL_TYPE;

/* 0x10
    15:0    R/W freg8                                   16'h0
 */
typedef volatile union _AON_FAST_REG_REG8X_FW_GENERAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t freg8;
    };
} AON_FAST_REG_REG8X_FW_GENERAL_TYPE;

/* 0x12
    15:0    R/W freg9                                   16'h0
 */
typedef volatile union _AON_FAST_REG_REG9X_FW_GENERAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t freg9;
    };
} AON_FAST_REG_REG9X_FW_GENERAL_TYPE;

/* 0x14
    15:0    R/W freg10                                  16'h0
 */
typedef volatile union _AON_FAST_REG_REG10X_FW_GENERAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t freg10;
    };
} AON_FAST_REG_REG10X_FW_GENERAL_TYPE;

/* 0x16
    15:0    R/W freg11                                  16'h0
 */
typedef volatile union _AON_FAST_REG_REG11X_FW_GENERAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t freg11;
    };
} AON_FAST_REG_REG11X_FW_GENERAL_TYPE;

/* 0x18
    0       R/W REG0X_AON_SYS_DUMMY[0]                  1'b1
    1       R/W WAIT_XTAL_CLK_OK                        1'b0
    2       R/W WAIT_VDDCORE_POR_DET                    1'b0
    12:3    R/W REG0X_AON_SYS_DUMMY[15:3]               10'h0
    13      R   enable_32k_osc                          1'b1
    14      R   enable_32k_lp                           1'b0
    15      R   enable_1m                               1'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_AON_SYS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t REG0X_AON_SYS_DUMMY_0: 1;
        uint16_t WAIT_XTAL_CLK_OK: 1;
        uint16_t WAIT_VDDCORE_POR_DET: 1;
        uint16_t REG0X_AON_SYS_DUMMY_15_3: 10;
        uint16_t enable_32k_osc: 1;
        uint16_t enable_32k_lp: 1;
        uint16_t enable_1m: 1;
    };
} AON_FAST_REG_REG0X_AON_SYS_TYPE;

/* 0x1a
    15:0    R   RO_AON_CNT_EXTRA_DELAY_PON_XTAL         16'h0
 */
typedef volatile union _AON_FAST_REG_RO_EXTRA_DELAY_XTAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t RO_AON_CNT_EXTRA_DELAY_PON_XTAL;
    };
} AON_FAST_REG_RO_EXTRA_DELAY_XTAL_TYPE;

/* 0x1c
    4:0     R   RO_WK_REASON                            5'h0
    7:5     R   reserved                                3'h0
    15:8    R   RO_AON_CNT_EXTRA_DELAY_PON_POS          8'h0
 */
typedef volatile union _AON_FAST_REG_RO_WK_REG0X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t RO_WK_REASON: 5;
        uint16_t reserved: 3;
        uint16_t RO_AON_CNT_EXTRA_DELAY_PON_POS: 8;
    };
} AON_FAST_REG_RO_WK_REG0X_TYPE;

/* 0x24
    7:0     R/W REG1X_AON_SYS_DUMMY[7:0]                8'b00001111
    10:8    R/W AON_DBG_SEL                             3'h0
    11      R/W SEL_32K_LP_nonAON                       1'b0
    12      R/W SEL_1M_reg                              1'b0
    13      R/W EN_RESTART_NO_CLK                       1'b1
    14      R/W SEL_32K_LP                              1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG1X_AON_SYS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t REG1X_AON_SYS_DUMMY_7_0: 8;
        uint16_t AON_DBG_SEL: 3;
        uint16_t SEL_32K_LP_nonAON: 1;
        uint16_t SEL_1M_reg: 1;
        uint16_t EN_RESTART_NO_CLK: 1;
        uint16_t SEL_32K_LP: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG1X_AON_SYS_TYPE;

/* 0x26
    0       R/W SPC_disable                             1'b0
    1       R/W reg_SCAN_MODE                           1'b0
    2       R/W PAD_BONDING_SHDN                        1'b1
    3       R/W SWR_BY_CORE                             1'b0
    4       R/W PIN_CLK_OUT_SEL[0]                      1'b0
    5       R/W r_cpu_clk_src_sel_1                     1'b1
    6       W1P aon_w1o_xo_lock                         1'b0
    7       R/W PIN_CLK_OUT_SEL[1]                      1'b0
    9:8     R/W rtc_in_selsy                            2'b00
    10      R/W en_gpio_32k                             1'b0
    11      R/W SEL_GPIO_32K_rtc                        1'b0
    12      W1P aon_w1o_xo_disable                      1'b0
    13      R   reg_aon_wdt_reset                       1'b0
    14      R/W pinmux_auxtest_sel                      1'b0
    15      W1O reg_aon_w1o_pa_func_dis                 1'b0
 */
typedef volatile union _AON_FAST_REG_REG2X_AON_SYS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SPC_disable: 1;
        uint16_t reg_SCAN_MODE: 1;
        uint16_t PAD_BONDING_SHDN: 1;
        uint16_t SWR_BY_CORE: 1;
        uint16_t PIN_CLK_OUT_SEL_0: 1;
        uint16_t r_cpu_clk_src_sel_1: 1;
        uint16_t aon_w1o_xo_lock: 1;
        uint16_t PIN_CLK_OUT_SEL_1: 1;
        uint16_t rtc_in_selsy: 2;
        uint16_t en_gpio_32k: 1;
        uint16_t SEL_GPIO_32K_rtc: 1;
        uint16_t aon_w1o_xo_disable: 1;
        uint16_t reg_aon_wdt_reset: 1;
        uint16_t pinmux_auxtest_sel: 1;
        uint16_t reg_aon_w1o_pa_func_dis: 1;
    };
} AON_FAST_REG_REG2X_AON_SYS_TYPE;

/* 0x28
    4:0     R   XTAL_PDCK_LP                            5'd0
    5       R   XTAL_PDCK_OK                            1'b0
    6       R   XTAL_PDCK_BUSY                          1'b0
    7       R/W xtal_pdck_rslt_latch                    1'b0
    12:8    R   XPDCK_VREF_OUT                          5'b11111
    13      R   XPDCK_READY                             1'b0
    14      R   XPDCK_BUSY                              1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_XPDCK_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_PDCK_LP: 5;
        uint16_t XTAL_PDCK_OK: 1;
        uint16_t XTAL_PDCK_BUSY: 1;
        uint16_t xtal_pdck_rslt_latch: 1;
        uint16_t XPDCK_VREF_OUT: 5;
        uint16_t XPDCK_READY: 1;
        uint16_t XPDCK_BUSY: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG0X_XPDCK_TYPE;

/* 0x2a
    7:0     R   reserved                                8'b0
    13:8    R/W debIO_cnt_lmt                           6'b0
    14      R/W debIO_wakeup_en                         1'b0
    15      W1C debIO_wakeup_sts                        1'b1
 */
typedef volatile union _AON_FAST_REG_REG0X_DEBIO_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved: 8;
        uint16_t debIO_cnt_lmt: 6;
        uint16_t debIO_wakeup_en: 1;
        uint16_t debIO_wakeup_sts: 1;
    };
} AON_FAST_REG_REG0X_DEBIO_TYPE;

/* 0x30
    0       R/W BUCK_TUNE_POS_VREFOT2                   1'b1
    1       R/W BUCK_TUNE_POS_VREFOT1                   1'b1
    3:2     R/W BUCK_SEL_VREFPFM2                       2'b01
    5:4     R/W BUCK_SEL_VREFPFM1                       2'b01
    6       R   BUCK_POW_PFM2_LQ                        1'b0
    7       R   BUCK_POW_PFM1_LQ                        1'b0
    8       R   BUCK_POW_PFM2_HQ                        1'b0
    9       R   BUCK_POW_PFM1_HQ                        1'b0
    10      R   BUCK_POW_VDIV2                          1'b0
    11      R   BUCK_POW_VDIV1                          1'b0
    12      R/W BUCK_EN_DBGO                            1'b0
    13      R   BUCK_POW_VDIV2_LQ                       1'b0
    14      R   BUCK_POW_VDIV1_LQ                       1'b0
    15      R   BUCK_POW_SWR                            1'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_BUCK_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t BUCK_TUNE_POS_VREFOT2: 1;
        uint16_t BUCK_TUNE_POS_VREFOT1: 1;
        uint16_t BUCK_SEL_VREFPFM2: 2;
        uint16_t BUCK_SEL_VREFPFM1: 2;
        uint16_t BUCK_POW_PFM2_LQ: 1;
        uint16_t BUCK_POW_PFM1_LQ: 1;
        uint16_t BUCK_POW_PFM2_HQ: 1;
        uint16_t BUCK_POW_PFM1_HQ: 1;
        uint16_t BUCK_POW_VDIV2: 1;
        uint16_t BUCK_POW_VDIV1: 1;
        uint16_t BUCK_EN_DBGO: 1;
        uint16_t BUCK_POW_VDIV2_LQ: 1;
        uint16_t BUCK_POW_VDIV1_LQ: 1;
        uint16_t BUCK_POW_SWR: 1;
    };
} AON_FAST_REG_REG0X_BUCK_TYPE;

/* 0x32
    3:0     R/W REG1X_BUCK_DUMMY[3:0]                   4'b0111
    6:4     R/W BUCK_TUNE_ZCDDELAY[2:0]                 3'b100
    9:7     R/W BUCK_TUNE_TREADY[2:0]                   3'b100
    11:10   R/W BUCK_TUNE_CLK_ZCDDELAY[1:0]             2'b01
    13:12   R/W BUCK_TUNE_CLK_TREADY[1:0]               2'b01
    14      R/W BUCK_SEL_IB_IPTAT                       1'b0
    15      R/W BUCK_SEL_CLK_32K                        1'b0
 */
typedef volatile union _AON_FAST_REG_REG1X_BUCK_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t REG1X_BUCK_DUMMY_3_0: 4;
        uint16_t BUCK_TUNE_ZCDDELAY_2_0: 3;
        uint16_t BUCK_TUNE_TREADY_2_0: 3;
        uint16_t BUCK_TUNE_CLK_ZCDDELAY_1_0: 2;
        uint16_t BUCK_TUNE_CLK_TREADY_1_0: 2;
        uint16_t BUCK_SEL_IB_IPTAT: 1;
        uint16_t BUCK_SEL_CLK_32K: 1;
    };
} AON_FAST_REG_REG1X_BUCK_TYPE;

/* 0x34
    6:0     R/W BUCK_TUNE_VDIV2_LQ                      7'b0100000
    7       R/W REG2X_BUCK_DUMMY[7]                     1'b0
    15:8    R/W BUCK_TUNE_VDIV1_LQ                      8'b10001010
 */
typedef volatile union _AON_FAST_REG_REG2X_BUCK_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t BUCK_TUNE_VDIV2_LQ: 7;
        uint16_t REG2X_BUCK_DUMMY_7: 1;
        uint16_t BUCK_TUNE_VDIV1_LQ: 8;
    };
} AON_FAST_REG_REG2X_BUCK_TYPE;

/* 0x36
    0       R   PMU_ST_PON_RET_DMY                      1'b0
    2:1     R   PMU_ST_PON_RST_DMY[1:0]                 2'b00
    4:3     R   PMU_ST_PON_CORE_DMY[1:0]                2'b00
    6:5     R   PMU_ST_PON_POS_DMY[1:0]                 2'b00
    9:7     R   PMU_ST_PON_SWR_DMY[2:0]                 3'b000
    12:10   R   PMU_ST_PON_SWR_BIAS_DMY[2:0]            3'b000
    14:13   R   PMU_ST_PON_BIAS_DMY[1:0]                2'b10
    15      R   BUCK_EN_FLASH_PD_DISCHG                 1'b1
 */
typedef volatile union _AON_FAST_REG_REG3X_BUCK_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PMU_ST_PON_RET_DMY: 1;
        uint16_t PMU_ST_PON_RST_DMY_1_0: 2;
        uint16_t PMU_ST_PON_CORE_DMY_1_0: 2;
        uint16_t PMU_ST_PON_POS_DMY_1_0: 2;
        uint16_t PMU_ST_PON_SWR_DMY_2_0: 3;
        uint16_t PMU_ST_PON_SWR_BIAS_DMY_2_0: 3;
        uint16_t PMU_ST_PON_BIAS_DMY_1_0: 2;
        uint16_t BUCK_EN_FLASH_PD_DISCHG: 1;
    };
} AON_FAST_REG_REG3X_BUCK_TYPE;

/* 0x38
    4:0     R/W BUCK_TUNE_PFM_CCOT2                     5'b00111
    6:5     R/W BUCK_TUNE_PFM_ICOT2                     2'b01
    7       R/W BUCK_SEL_PFM_COT2                       1'b0
    12:8    R/W BUCK_TUNE_PFM_CCOT1                     5'b00111
    14:13   R/W BUCK_TUNE_PFM_ICOT1                     2'b01
    15      R/W BUCK_SEL_PFM_COT1                       1'b0
 */
typedef volatile union _AON_FAST_REG_REG4X_BUCK_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t BUCK_TUNE_PFM_CCOT2: 5;
        uint16_t BUCK_TUNE_PFM_ICOT2: 2;
        uint16_t BUCK_SEL_PFM_COT2: 1;
        uint16_t BUCK_TUNE_PFM_CCOT1: 5;
        uint16_t BUCK_TUNE_PFM_ICOT1: 2;
        uint16_t BUCK_SEL_PFM_COT1: 1;
    };
} AON_FAST_REG_REG4X_BUCK_TYPE;

/* 0x3a
    0       R   reserved                                1'b0
    1       R   reserved                                1'b0
    2       R   reserved                                1'b0
    3       R   reserved                                1'b0
    4       R   reserved                                1'b0
    5       R   reserved                                1'b0
    6       R   reserved                                1'b0
    7       R   reserved                                1'b0
    8       R/W REG5X_BUCK_DUMMY[8]                     1'b0
    9       R/W REG5X_BUCK_DUMMY[9]                     1'b0
    10      R   BUCK_SEL_LPPFM2                         1'b0
    11      R   BUCK_SEL_LPPFM1                         1'b0
    12      R/W BUCK_EN_PFM_WaitSampleOver              1'b1
    13      R/W BUCK_EN_PFM_ForceOFFtoZCD               1'b1
    14      R/W BUCK_X4_PFM2_COMP_IB                    1'b0
    15      R/W BUCK_X4_PFM1_COMP_IB                    1'b0
 */
typedef volatile union _AON_FAST_REG_REG5X_BUCK_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
        uint16_t REG5X_BUCK_DUMMY_8: 1;
        uint16_t REG5X_BUCK_DUMMY_9: 1;
        uint16_t BUCK_SEL_LPPFM2: 1;
        uint16_t BUCK_SEL_LPPFM1: 1;
        uint16_t BUCK_EN_PFM_WaitSampleOver: 1;
        uint16_t BUCK_EN_PFM_ForceOFFtoZCD: 1;
        uint16_t BUCK_X4_PFM2_COMP_IB: 1;
        uint16_t BUCK_X4_PFM1_COMP_IB: 1;
    };
} AON_FAST_REG_REG5X_BUCK_TYPE;

/* 0x3c
    6:0     R/W BUCK_TUNE_ZCD_FORCECODE2                7'b0100100
    7       R/W REG6X_BUCK_DUMMY[7]                     1'b0
    14:8    R/W BUCK_TUNE_ZCD_FORCECODE1                7'b0100100
    15      R/W REG6X_BUCK_DUMMY[15]                    1'b0
 */
typedef volatile union _AON_FAST_REG_REG6X_BUCK_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t BUCK_TUNE_ZCD_FORCECODE2: 7;
        uint16_t REG6X_BUCK_DUMMY_7: 1;
        uint16_t BUCK_TUNE_ZCD_FORCECODE1: 7;
        uint16_t REG6X_BUCK_DUMMY_15: 1;
    };
} AON_FAST_REG_REG6X_BUCK_TYPE;

/* 0x3e
    0       R/W REG7X_BUCK_DUMMY[0]                     1'b0
    1       R/W REG7X_BUCK_DUMMY[1]                     1'b0
    2       R/W REG7X_BUCK_DUMMY[2]                     1'b0
    3       R/W BUCK_STICKY_ZCD_CODE2                   1'b0
    4       R/W BUCK_FORCE_ZCD_CODE2                    1'b0
    5       R/W BUCK_STICKY_ZCD_CODE1                   1'b0
    6       R/W BUCK_FORCE_ZCD_CODE1                    1'b0
    7       R/W BUCK_EN_ZCD_ClampLX                     1'b1
    8       R/W BUCK_EN_ZCD_LowIQ                       1'b0
    10:9    R/W BUCK_TUNE_ZCD_SDZ2d                     2'b00
    13:11   R/W BUCK_TUNE_ZCD_SDZ2                      3'b001
    15:14   R/W BUCK_TUNE_ZCD_SDZ1                      2'b00
 */
typedef volatile union _AON_FAST_REG_REG7X_BUCK_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t REG7X_BUCK_DUMMY_0: 1;
        uint16_t REG7X_BUCK_DUMMY_1: 1;
        uint16_t REG7X_BUCK_DUMMY_2: 1;
        uint16_t BUCK_STICKY_ZCD_CODE2: 1;
        uint16_t BUCK_FORCE_ZCD_CODE2: 1;
        uint16_t BUCK_STICKY_ZCD_CODE1: 1;
        uint16_t BUCK_FORCE_ZCD_CODE1: 1;
        uint16_t BUCK_EN_ZCD_ClampLX: 1;
        uint16_t BUCK_EN_ZCD_LowIQ: 1;
        uint16_t BUCK_TUNE_ZCD_SDZ2d: 2;
        uint16_t BUCK_TUNE_ZCD_SDZ2: 3;
        uint16_t BUCK_TUNE_ZCD_SDZ1: 2;
    };
} AON_FAST_REG_REG7X_BUCK_TYPE;

/* 0x40
    0       R/W REG8X_BUCK_DUMMY[0]                     1'b0
    1       R/W REG8X_BUCK_DUMMY[1]                     1'b0
    2       R/W REG8X_BUCK_DUMMY[2]                     1'b0
    3       R/W REG8X_BUCK_DUMMY[3]                     1'b1
    5:4     R/W BUCK_TUNE_PREDRV_O_SN                   2'b11
    7:6     R/W BUCK_TUNE_PREDRV_O_SP                   2'b11
    9:8     R/W BUCK_TUNE_PREDRV_N_SN                   2'b11
    11:10   R/W BUCK_TUNE_PREDRV_N_SP                   2'b11
    13:12   R/W BUCK_TUNE_PREDRV_P_SN                   2'b11
    15:14   R/W BUCK_TUNE_PREDRV_P_SP                   2'b11
 */
typedef volatile union _AON_FAST_REG_REG8X_BUCK_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t REG8X_BUCK_DUMMY_0: 1;
        uint16_t REG8X_BUCK_DUMMY_1: 1;
        uint16_t REG8X_BUCK_DUMMY_2: 1;
        uint16_t REG8X_BUCK_DUMMY_3: 1;
        uint16_t BUCK_TUNE_PREDRV_O_SN: 2;
        uint16_t BUCK_TUNE_PREDRV_O_SP: 2;
        uint16_t BUCK_TUNE_PREDRV_N_SN: 2;
        uint16_t BUCK_TUNE_PREDRV_N_SP: 2;
        uint16_t BUCK_TUNE_PREDRV_P_SN: 2;
        uint16_t BUCK_TUNE_PREDRV_P_SP: 2;
    };
} AON_FAST_REG_REG8X_BUCK_TYPE;

/* 0x42
    0       R   BUCK_STOP                               1'b0
    1       R   BUCK_VREFSS_START                       1'b0
    2       R   BUCK_OUT2_OCCUPY                        1'b0
    3       R   BUCK_OUT1_OCCUPY                        1'b0
    4       R   BUCK_ONTIME_OVER2                       1'b0
    5       R   BUCK_ONTIME_OVER1                       1'b0
    6       R   BUCK_ONTIME_SET2pre                     1'b0
    7       R   BUCK_ONTIME_SET1pre                     1'b0
    8       R   reserved                                1'b0
    9       R   BUCK_CK_CTRL                            1'b0
    10      R   BUCK_NI                                 1'b0
    11      R   BUCK_PI                                 1'b0
    12      R   BUCK_OUT2GATE_HV                        1'b0
    13      R   BUCK_OUT1GATE_HV                        1'b0
    14      R   BUCK_NGATE_HV                           1'b0
    15      R   BUCK_PGATE_HV                           1'b0
 */
typedef volatile union _AON_FAST_REG_CKOUT0X_BUCK_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t BUCK_STOP: 1;
        uint16_t BUCK_VREFSS_START: 1;
        uint16_t BUCK_OUT2_OCCUPY: 1;
        uint16_t BUCK_OUT1_OCCUPY: 1;
        uint16_t BUCK_ONTIME_OVER2: 1;
        uint16_t BUCK_ONTIME_OVER1: 1;
        uint16_t BUCK_ONTIME_SET2pre: 1;
        uint16_t BUCK_ONTIME_SET1pre: 1;
        uint16_t reserved: 1;
        uint16_t BUCK_CK_CTRL: 1;
        uint16_t BUCK_NI: 1;
        uint16_t BUCK_PI: 1;
        uint16_t BUCK_OUT2GATE_HV: 1;
        uint16_t BUCK_OUT1GATE_HV: 1;
        uint16_t BUCK_NGATE_HV: 1;
        uint16_t BUCK_PGATE_HV: 1;
    };
} AON_FAST_REG_CKOUT0X_BUCK_TYPE;

/* 0x44
    6:0     R   BUCK_ZCDQ                               1'b0
    7       R   BUCK_SampleOver                         1'b0
    8       R   BUCK_ZCD_SET_NEW                        1'b0
    9       R   BUCK_ZCD_new                            1'b0
    10      R   BUCK_ZCD_DELAY                          1'b0
    11      R   BUCK_SLEEP                              1'b0
    12      R   BUCK_VCOMP_LPPFM2                       1'b0
    13      R   BUCK_VCOMP_LPPFM1                       1'b0
    14      R   BUCK_CLK_ZCDDELAY                       1'b0
    15      R   BUCK_CLK_TREADY                         1'b0
 */
typedef volatile union _AON_FAST_REG_CKOUT1X_BUCK_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t BUCK_ZCDQ: 7;
        uint16_t BUCK_SampleOver: 1;
        uint16_t BUCK_ZCD_SET_NEW: 1;
        uint16_t BUCK_ZCD_new: 1;
        uint16_t BUCK_ZCD_DELAY: 1;
        uint16_t BUCK_SLEEP: 1;
        uint16_t BUCK_VCOMP_LPPFM2: 1;
        uint16_t BUCK_VCOMP_LPPFM1: 1;
        uint16_t BUCK_CLK_ZCDDELAY: 1;
        uint16_t BUCK_CLK_TREADY: 1;
    };
} AON_FAST_REG_CKOUT1X_BUCK_TYPE;

/* 0x46
    0       R   LDO_POW_LDORET                          1'b0
    2:1     R/W LDO_LDORET_COMPTUNE                     2'b11
    5:3     R/W LDO_VDDCORE_OCP                         3'b101
    9:6     R/W LDO_VDDCORE_COMP_C                      4'b1010
    10      R   LDO_POW_VDDCORE                         1'b0
    15:11   R   LDO_VDDCORE_TUNE_VDIV                   5'b01110
 */
typedef volatile union _AON_FAST_REG_REG0X_LDO_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_POW_LDORET: 1;
        uint16_t LDO_LDORET_COMPTUNE: 2;
        uint16_t LDO_VDDCORE_OCP: 3;
        uint16_t LDO_VDDCORE_COMP_C: 4;
        uint16_t LDO_POW_VDDCORE: 1;
        uint16_t LDO_VDDCORE_TUNE_VDIV: 5;
    };
} AON_FAST_REG_REG0X_LDO_TYPE;

/* 0x48
    0       R/W REG1X_LDO_DUMMY[0]                      1'b1
    1       R   LDO_POW_BIAS_VDDANA                     1'b0
    2       R   LDO_POW_BIAS_VDDCORE                    1'b0
    5:3     R/W LDO_VDDANA_OCP                          3'b101
    9:6     R/W LDO_VDDANA_COMP_C                       4'b1010
    10      R   LDO_POW_VDDANA                          1'b0
    15:11   R   LDO_VDDANA_TUNE_VDIV                    5'b10100
 */
typedef volatile union _AON_FAST_REG_REG1X_LDO_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t REG1X_LDO_DUMMY_0: 1;
        uint16_t LDO_POW_BIAS_VDDANA: 1;
        uint16_t LDO_POW_BIAS_VDDCORE: 1;
        uint16_t LDO_VDDANA_OCP: 3;
        uint16_t LDO_VDDANA_COMP_C: 4;
        uint16_t LDO_POW_VDDANA: 1;
        uint16_t LDO_VDDANA_TUNE_VDIV: 5;
    };
} AON_FAST_REG_REG1X_LDO_TYPE;

/* 0x4a
    0       R   LDO_POW_BIAS_LDOANA                     1'b0
    1       R   LDO_ENPC_LDOANA                         1'b0
    2       R   LDO_POW_LDOANA                          1'b0
    5:3     R/W REG2X_LDO_DUMMY[5:3]                    3'b000
    6       R/W LDO_POW_LDOANA_FB                       1'b0
    8:7     R/W REG2X_LDO_DUMMY[8:7]                    2'b11
    13:9    R   LDO_TUNE_LDOANA                         5'b10100
    14      R/W LDO_ENB_DMYL_50U_LDOANA                 1'b1
    15      R   LDO_ENB_DMYL_200U_LDOANA                1'b1
 */
typedef volatile union _AON_FAST_REG_REG2X_LDO_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_POW_BIAS_LDOANA: 1;
        uint16_t LDO_ENPC_LDOANA: 1;
        uint16_t LDO_POW_LDOANA: 1;
        uint16_t REG2X_LDO_DUMMY_5_3: 3;
        uint16_t LDO_POW_LDOANA_FB: 1;
        uint16_t REG2X_LDO_DUMMY_8_7: 2;
        uint16_t LDO_TUNE_LDOANA: 5;
        uint16_t LDO_ENB_DMYL_50U_LDOANA: 1;
        uint16_t LDO_ENB_DMYL_200U_LDOANA: 1;
    };
} AON_FAST_REG_REG2X_LDO_TYPE;

/* 0x4c
    0       R   LDO_POW_LDO311                          1'b1
    1       R   LDO_EN_LDO311_VDIV                      1'b1
    2       R   LDO_EN_LDO311_DMY_LITE                  1'b1
    3       R   LDO_EN_VAON_VANA_PC                     1'b0
    4       R/W REG3X_LDO_DUMMY[4]                      1'b0
    5       R/W REG3X_LDO_DUMMY[5]                      1'b0
    6       R/W LDO_EN_V311_TSW                         1'b0
    9:7     R/W TUNE_DMY_LITE                           3'b100
    14:10   R/W LDO_TUNE_LDO311_VDIV                    5'b01111
    15      R/W REG3X_LDO_DUMMY[15]                     1'b0
 */
typedef volatile union _AON_FAST_REG_REG3X_LDO_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_POW_LDO311: 1;
        uint16_t LDO_EN_LDO311_VDIV: 1;
        uint16_t LDO_EN_LDO311_DMY_LITE: 1;
        uint16_t LDO_EN_VAON_VANA_PC: 1;
        uint16_t REG3X_LDO_DUMMY_4: 1;
        uint16_t REG3X_LDO_DUMMY_5: 1;
        uint16_t LDO_EN_V311_TSW: 1;
        uint16_t TUNE_DMY_LITE: 3;
        uint16_t LDO_TUNE_LDO311_VDIV: 5;
        uint16_t REG3X_LDO_DUMMY_15: 1;
    };
} AON_FAST_REG_REG3X_LDO_TYPE;

/* 0x4e
    1:0     R   reserved                                2'b00
    3:2     R   reserved                                2'b00
    5:4     R   reserved                                2'b00
    12:6    R/W REG4X_LDO_DUMMY[12:6]                   7'b0000000
    13      R/W LDO_EN_DMY_1MA                          1'b0
    14      R/W LDO_EN_LDO311_FT_US                     1'b0
    15      R/W LDO_EN_LDO311_FT_OS                     1'b0
 */
typedef volatile union _AON_FAST_REG_REG4X_LDO_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_2: 2;
        uint16_t reserved_1: 2;
        uint16_t reserved: 2;
        uint16_t REG4X_LDO_DUMMY_12_6: 7;
        uint16_t LDO_EN_DMY_1MA: 1;
        uint16_t LDO_EN_LDO311_FT_US: 1;
        uint16_t LDO_EN_LDO311_FT_OS: 1;
    };
} AON_FAST_REG_REG4X_LDO_TYPE;

/* 0x50
    15:0    R   reserved                                16'h0
 */
typedef volatile union _AON_FAST_REG_CKOUT0X_LDO_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved;
    };
} AON_FAST_REG_CKOUT0X_LDO_TYPE;

/* 0x52
    5:0     R/W MBIAS_REG0X_SD_TUNE                     6'b000000
    8:6     R/W REG0X_MBIAS_DUMMY[15:6]                 3'b010
    15:9    R   reserved                                7'b0000000
 */
typedef volatile union _AON_FAST_REG_REG0X_MBIAS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t MBIAS_REG0X_SD_TUNE: 6;
        uint16_t REG0X_MBIAS_DUMMY_15_6: 3;
        uint16_t reserved: 7;
    };
} AON_FAST_REG_REG0X_MBIAS_TYPE;

/* 0x54
    2:0     R/W MBIAS_LPBG_VR1200                       3'b100
    5:3     R/W MBIAS_LPBG_R2                           3'b100
    8:6     R/W MBIAS_BG_BG_R1[2:0]                     3'b100
    9       R   MBIAS_POW_BG_EBIAS_AUXADC               1'b0
    12:10   R/W MBIAS_VR_SEL_LDO311                     3'b100
    14:13   R/W REG1X_MBIAS_DUMMY[14:13]                2'b00
    15      R/W REG1X_MBIAS_DUMMY[15]                   1'b1
 */
typedef volatile union _AON_FAST_REG_REG1X_MBIAS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t MBIAS_LPBG_VR1200: 3;
        uint16_t MBIAS_LPBG_R2: 3;
        uint16_t MBIAS_BG_BG_R1_2_0: 3;
        uint16_t MBIAS_POW_BG_EBIAS_AUXADC: 1;
        uint16_t MBIAS_VR_SEL_LDO311: 3;
        uint16_t REG1X_MBIAS_DUMMY_14_13: 2;
        uint16_t REG1X_MBIAS_DUMMY_15: 1;
    };
} AON_FAST_REG_REG1X_MBIAS_TYPE;

/* 0x56
    2:0     R/W REG2X_MBIAS_DUMMY[2:0]                  3'b101
    6:3     R/W MBIAS_VR_SEL_LDORET                     4'b0110
    9:7     R/W MBIAS_BG_VREF_SEL_L                     3'b001
    12:10   R/W MBIAS_BG_VREF_SEL_H                     3'b010
    13      R/W MBIAS_BG_Efuse_Data_H                   1'b0
    14      R/W MBIAS_BG_DIGI_RST_H                     1'b0
    15      R/W REG2X_MBIAS_DUMMY[15]                   1'b1
 */
typedef volatile union _AON_FAST_REG_REG2X_MBIAS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t REG2X_MBIAS_DUMMY_2_0: 3;
        uint16_t MBIAS_VR_SEL_LDORET: 4;
        uint16_t MBIAS_BG_VREF_SEL_L: 3;
        uint16_t MBIAS_BG_VREF_SEL_H: 3;
        uint16_t MBIAS_BG_Efuse_Data_H: 1;
        uint16_t MBIAS_BG_DIGI_RST_H: 1;
        uint16_t REG2X_MBIAS_DUMMY_15: 1;
    };
} AON_FAST_REG_REG2X_MBIAS_TYPE;

/* 0x58
    2:0     R/W MBIAS_BG_VIO_VREF_SEL_L                 3'b011
    5:3     R/W MBIAS_BG_VIO_VREF_SEL_H                 3'b101
    10:6    R/W MBIAS_VREF_SEL_XOSC                     5'b10101
    15:11   R/W MBIAS_VREF_SEL_LDO311_LIQ               5'b10000
 */
typedef volatile union _AON_FAST_REG_REG3X_MBIAS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t MBIAS_BG_VIO_VREF_SEL_L: 3;
        uint16_t MBIAS_BG_VIO_VREF_SEL_H: 3;
        uint16_t MBIAS_VREF_SEL_XOSC: 5;
        uint16_t MBIAS_VREF_SEL_LDO311_LIQ: 5;
    };
} AON_FAST_REG_REG3X_MBIAS_TYPE;

/* 0x5a
    10:0    R   reserved                                11'h0
    11      R   MBIAS_POR_VIO_SIG_SEL                   1'b0
    12      R/W MBIAS_SWR_VREF_SEL                      1'b0
    13      R   MBIAS_BIAS50NA_EN                       1'b0
    14      R   MBIAS_POR_DVDDCORE_EN                   1'b0
    15      R   MBIAS_POR_VIO_EN                        1'b1
 */
typedef volatile union _AON_FAST_REG_REG4X_MBIAS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved: 11;
        uint16_t MBIAS_POR_VIO_SIG_SEL: 1;
        uint16_t MBIAS_SWR_VREF_SEL: 1;
        uint16_t MBIAS_BIAS50NA_EN: 1;
        uint16_t MBIAS_POR_DVDDCORE_EN: 1;
        uint16_t MBIAS_POR_VIO_EN: 1;
    };
} AON_FAST_REG_REG4X_MBIAS_TYPE;

/* 0x5c
    0       R   MBIAS_Q1_Efuse                          1'b0
    1       R   MBIAS_Q2_Efuse                          1'b0
    11:2    R   MBIAS_CKOUT0X_DUMMY<10:0>               10'h0
    12      R   MBIAS_PORB33V_L                         1'b0
    13      R   MBIAS_PORB_VDDCORE_L                    1'b0
    14      R   MBIAS_BGOK_L                            1'b0
    15      R   MBIAS_PORB_LDO311_L                     1'b0
 */
typedef volatile union _AON_FAST_REG_CKOUT0X_MBIAS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t MBIAS_Q1_Efuse: 1;
        uint16_t MBIAS_Q2_Efuse: 1;
        uint16_t MBIAS_CKOUT0X_DUMMY_10_0: 10;
        uint16_t MBIAS_PORB33V_L: 1;
        uint16_t MBIAS_PORB_VDDCORE_L: 1;
        uint16_t MBIAS_BGOK_L: 1;
        uint16_t MBIAS_PORB_LDO311_L: 1;
    };
} AON_FAST_REG_CKOUT0X_MBIAS_TYPE;

/* 0x5e
    0       R/W DIGI_Efuse_CK_L                         1'b0
    15:1    R   reserved                                30'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_EFUSE_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t DIGI_Efuse_CK_L: 1;
        uint16_t reserved: 15;
    };
} AON_FAST_REG_REG0X_EFUSE_TYPE;

/* 0x60
    11:0    R   reserved                                12'h0
    12      R   FLASH_PC_VG1                            1'b1
    13      R   FLASH_PC_VG2                            1'b1
    14      R   VCORE_PC_VG1                            1'b1
    15      R   VCORE_PC_VG2                            1'b1
 */
typedef volatile union _AON_FAST_REG_CORE_FLASH_PC_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved: 12;
        uint16_t FLASH_PC_VG1: 1;
        uint16_t FLASH_PC_VG2: 1;
        uint16_t VCORE_PC_VG1: 1;
        uint16_t VCORE_PC_VG2: 1;
    };
} AON_FAST_REG_CORE_FLASH_PC_TYPE;

/* 0x80
    0       R/W PAD_P1_O[5]                             1'b0
    1       R/W PAD_P1_E[5]                             1'b0
    2       R/W PAD_P1_PU_EN[5]                         1'b1
    3       R/W AON_PAD_P1_PD[5]                        1'b0
    4       R/W PAD_P1_PUPDC[5]                         1'b0
    5       R/W PAD_P1_WKEN[5]                          1'b0
    6       R/W PAD_P1_WKPOL[5]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P1_SHDN[5]                          1'b1
    9       R/W PAD_P1_S[5]                             1'b0
    10      R/W PAD_P1_DEB[5]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P1_5_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P1_O_5: 1;
        uint16_t PAD_P1_E_5: 1;
        uint16_t PAD_P1_PU_EN_5: 1;
        uint16_t AON_PAD_P1_PD_5: 1;
        uint16_t PAD_P1_PUPDC_5: 1;
        uint16_t PAD_P1_WKEN_5: 1;
        uint16_t PAD_P1_WKPOL_5: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P1_SHDN_5: 1;
        uint16_t PAD_P1_S_5: 1;
        uint16_t PAD_P1_DEB_5: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P1_5_CFG_TYPE;

/* 0x82
    0       R/W PAD_P1_O[6]                             1'b0
    1       R/W PAD_P1_E[6]                             1'b0
    2       R/W PAD_P1_PU_EN[6]                         1'b1
    3       R/W AON_PAD_P1_PD[6]                        1'b1
    4       R/W PAD_P1_PUPDC[6]                         1'b0
    5       R/W PAD_P1_WKEN[6]                          1'b0
    6       R/W PAD_P1_WKPOL[6]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P1_SHDN[6]                          1'b1
    9       R/W PAD_P1_S[6]                             1'b0
    10      R/W PAD_P1_DEB[6]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P1_6_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P1_O_6: 1;
        uint16_t PAD_P1_E_6: 1;
        uint16_t PAD_P1_PU_EN_6: 1;
        uint16_t AON_PAD_P1_PD_6: 1;
        uint16_t PAD_P1_PUPDC_6: 1;
        uint16_t PAD_P1_WKEN_6: 1;
        uint16_t PAD_P1_WKPOL_6: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P1_SHDN_6: 1;
        uint16_t PAD_P1_S_6: 1;
        uint16_t PAD_P1_DEB_6: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P1_6_CFG_TYPE;

/* 0x84
    0       R/W PAD_P1_O[7]                             1'b0
    1       R/W PAD_P1_E[7]                             1'b0
    2       R/W PAD_P1_PU_EN[7]                         1'b1
    3       R/W AON_PAD_P1_PD[7]                        1'b1
    4       R/W PAD_P1_PUPDC[7]                         1'b0
    5       R/W PAD_P1_WKEN[7]                          1'b0
    6       R/W PAD_P1_WKPOL[7]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P1_SHDN[7]                          1'b1
    9       R/W PAD_P1_S[7]                             1'b0
    10      R/W PAD_P1_DEB[7]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P1_7_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P1_O_7: 1;
        uint16_t PAD_P1_E_7: 1;
        uint16_t PAD_P1_PU_EN_7: 1;
        uint16_t AON_PAD_P1_PD_7: 1;
        uint16_t PAD_P1_PUPDC_7: 1;
        uint16_t PAD_P1_WKEN_7: 1;
        uint16_t PAD_P1_WKPOL_7: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P1_SHDN_7: 1;
        uint16_t PAD_P1_S_7: 1;
        uint16_t PAD_P1_DEB_7: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P1_7_CFG_TYPE;

/* 0x86
    0       R/W PAD_P3_O[0]                             1'b0
    1       R/W PAD_P3_E[0]                             1'b0
    2       R/W PAD_P3_PU_EN[0]                         1'b1
    3       R/W AON_PAD_P3_PD[0]                        1'b0
    4       R/W PAD_P3_PUPDC[0]                         1'b0
    5       R/W PAD_P3_WKEN[0]                          1'b0
    6       R/W PAD_P3_WKPOL[0]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P3_SHDN[0]                          1'b1
    9       R/W PAD_P3_S[0]                             1'b0
    10      R/W PAD_P3_DEB[0]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P3_0_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P3_O_0: 1;
        uint16_t PAD_P3_E_0: 1;
        uint16_t PAD_P3_PU_EN_0: 1;
        uint16_t AON_PAD_P3_PD_0: 1;
        uint16_t PAD_P3_PUPDC_0: 1;
        uint16_t PAD_P3_WKEN_0: 1;
        uint16_t PAD_P3_WKPOL_0: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P3_SHDN_0: 1;
        uint16_t PAD_P3_S_0: 1;
        uint16_t PAD_P3_DEB_0: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P3_0_CFG_TYPE;

/* 0x88
    0       R/W PAD_P3_O[1]                             1'b0
    1       R/W PAD_P3_E[1]                             1'b0
    2       R/W PAD_P3_PU_EN[1]                         1'b1
    3       R/W AON_PAD_P3_PD[1]                        1'b0
    4       R/W PAD_P3_PUPDC[1]                         1'b0
    5       R/W PAD_P3_WKEN[1]                          1'b0
    6       R/W PAD_P3_WKPOL[1]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P3_SHDN[1]                          1'b1
    9       R/W PAD_P3_S[1]                             1'b0
    10      R/W PAD_P3_DEB[1]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P3_1_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P3_O_1: 1;
        uint16_t PAD_P3_E_1: 1;
        uint16_t PAD_P3_PU_EN_1: 1;
        uint16_t AON_PAD_P3_PD_1: 1;
        uint16_t PAD_P3_PUPDC_1: 1;
        uint16_t PAD_P3_WKEN_1: 1;
        uint16_t PAD_P3_WKPOL_1: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P3_SHDN_1: 1;
        uint16_t PAD_P3_S_1: 1;
        uint16_t PAD_P3_DEB_1: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P3_1_CFG_TYPE;

/* 0x8a
    0       R/W PAD_P3_O[2]                             1'b0
    1       R/W PAD_P3_E[2]                             1'b0
    2       R/W PAD_P3_PU_EN[2]                         1'b1
    3       R/W AON_PAD_P3_PD[2]                        1'b1
    4       R/W PAD_P3_PUPDC[2]                         1'b0
    5       R/W PAD_P3_WKEN[2]                          1'b0
    6       R/W PAD_P3_WKPOL[2]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P3_SHDN[2]                          1'b1
    9       R/W PAD_P3_S[2]                             1'b0
    10      R/W PAD_P3_DEB[2]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P3_2_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P3_O_2: 1;
        uint16_t PAD_P3_E_2: 1;
        uint16_t PAD_P3_PU_EN_2: 1;
        uint16_t AON_PAD_P3_PD_2: 1;
        uint16_t PAD_P3_PUPDC_2: 1;
        uint16_t PAD_P3_WKEN_2: 1;
        uint16_t PAD_P3_WKPOL_2: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P3_SHDN_2: 1;
        uint16_t PAD_P3_S_2: 1;
        uint16_t PAD_P3_DEB_2: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P3_2_CFG_TYPE;

/* 0x8c
    0       R/W PAD_P3_O[3]                             1'b0
    1       R/W PAD_P3_E[3]                             1'b0
    2       R/W PAD_P3_PU_EN[3]                         1'b1
    3       R/W AON_PAD_P3_PD[3]                        1'b1
    4       R/W PAD_P3_PUPDC[3]                         1'b0
    5       R/W PAD_P3_WKEN[3]                          1'b0
    6       R/W PAD_P3_WKPOL[3]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P3_SHDN[3]                          1'b1
    9       R/W PAD_P3_S[3]                             1'b0
    10      R/W PAD_P3_DEB[3]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P3_3_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P3_O_3: 1;
        uint16_t PAD_P3_E_3: 1;
        uint16_t PAD_P3_PU_EN_3: 1;
        uint16_t AON_PAD_P3_PD_3: 1;
        uint16_t PAD_P3_PUPDC_3: 1;
        uint16_t PAD_P3_WKEN_3: 1;
        uint16_t PAD_P3_WKPOL_3: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P3_SHDN_3: 1;
        uint16_t PAD_P3_S_3: 1;
        uint16_t PAD_P3_DEB_3: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P3_3_CFG_TYPE;

/* 0x8e
    0       R/W PAD_P3_O[4]                             1'b0
    1       R/W PAD_P3_E[4]                             1'b0
    2       R/W PAD_P3_PU_EN[4]                         1'b1
    3       R/W AON_PAD_P3_PD[4]                        1'b1
    4       R/W PAD_P3_PUPDC[4]                         1'b0
    5       R/W PAD_P3_WKEN[4]                          1'b0
    6       R/W PAD_P3_WKPOL[4]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P3_SHDN[4]                          1'b1
    9       R/W PAD_P3_S[4]                             1'b0
    10      R/W PAD_P3_DEB[4]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P3_4_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P3_O_4: 1;
        uint16_t PAD_P3_E_4: 1;
        uint16_t PAD_P3_PU_EN_4: 1;
        uint16_t AON_PAD_P3_PD_4: 1;
        uint16_t PAD_P3_PUPDC_4: 1;
        uint16_t PAD_P3_WKEN_4: 1;
        uint16_t PAD_P3_WKPOL_4: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P3_SHDN_4: 1;
        uint16_t PAD_P3_S_4: 1;
        uint16_t PAD_P3_DEB_4: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P3_4_CFG_TYPE;

/* 0x90
    0       R/W PAD_P3_O[5]                             1'b0
    1       R/W PAD_P3_E[5]                             1'b0
    2       R/W PAD_P3_PU_EN[5]                         1'b1
    3       R/W AON_PAD_P3_PD[5]                        1'b1
    4       R/W PAD_P3_PUPDC[5]                         1'b0
    5       R/W PAD_P3_WKEN[5]                          1'b0
    6       R/W PAD_P3_WKPOL[5]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P3_SHDN[5]                          1'b1
    9       R/W PAD_P3_S[5]                             1'b0
    10      R/W PAD_P3_DEB[5]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P3_5_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P3_O_5: 1;
        uint16_t PAD_P3_E_5: 1;
        uint16_t PAD_P3_PU_EN_5: 1;
        uint16_t AON_PAD_P3_PD_5: 1;
        uint16_t PAD_P3_PUPDC_5: 1;
        uint16_t PAD_P3_WKEN_5: 1;
        uint16_t PAD_P3_WKPOL_5: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P3_SHDN_5: 1;
        uint16_t PAD_P3_S_5: 1;
        uint16_t PAD_P3_DEB_5: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P3_5_CFG_TYPE;

/* 0x92
    0       R/W PAD_P3_O[6]                             1'b0
    1       R/W PAD_P3_E[6]                             1'b0
    2       R/W PAD_P3_PU_EN[6]                         1'b1
    3       R/W AON_PAD_P3_PD[6]                        1'b1
    4       R/W PAD_P3_PUPDC[6]                         1'b0
    5       R/W PAD_P3_WKEN[6]                          1'b0
    6       R/W PAD_P3_WKPOL[6]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P3_SHDN[6]                          1'b1
    9       R/W PAD_P3_S[6]                             1'b0
    10      R/W PAD_P3_DEB[6]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P3_6_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P3_O_6: 1;
        uint16_t PAD_P3_E_6: 1;
        uint16_t PAD_P3_PU_EN_6: 1;
        uint16_t AON_PAD_P3_PD_6: 1;
        uint16_t PAD_P3_PUPDC_6: 1;
        uint16_t PAD_P3_WKEN_6: 1;
        uint16_t PAD_P3_WKPOL_6: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P3_SHDN_6: 1;
        uint16_t PAD_P3_S_6: 1;
        uint16_t PAD_P3_DEB_6: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P3_6_CFG_TYPE;

/* 0x96
    0       R/W PAD_P5_1_O                              1'b0
    1       R/W PAD_P5_1_E                              1'b0
    2       R/W PAD_P5_1_PU_EN                          1'b1
    3       R/W AON_PAD_P5_1_PD                         1'b1
    4       R/W PAD_P5_1_PUPDC                          1'b0
    5       R/W PAD_P5_1_WKEN                           1'b0
    6       R/W PAD_P5_1_WKPOL                          1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P5_1_SHDN                           1'b1
    9       R/W PAD_P5_1_S                              1'b0
    10      R/W PAD_P5_1_DEB                            1'b0
    11      R/W PAD_P5_E2[1]                            1'b0
    12      R/W PAD_P5_E2_AUX[1]                        1'b0
    13      R/W PAD_P5_1_dbg_en                         1'b0
    15:14   R   reserved                                2'b00
 */
typedef volatile union _AON_FAST_REG_REG0X_P5_1_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P5_1_O: 1;
        uint16_t PAD_P5_1_E: 1;
        uint16_t PAD_P5_1_PU_EN: 1;
        uint16_t AON_PAD_P5_1_PD: 1;
        uint16_t PAD_P5_1_PUPDC: 1;
        uint16_t PAD_P5_1_WKEN: 1;
        uint16_t PAD_P5_1_WKPOL: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P5_1_SHDN: 1;
        uint16_t PAD_P5_1_S: 1;
        uint16_t PAD_P5_1_DEB: 1;
        uint16_t PAD_P5_E2_1: 1;
        uint16_t PAD_P5_E2_AUX_1: 1;
        uint16_t PAD_P5_1_dbg_en: 1;
        uint16_t reserved: 2;
    };
} AON_FAST_REG_REG0X_P5_1_CFG_TYPE;

/* 0x98
    0       R/W PAD_P5_2_O                              1'b0
    1       R/W PAD_P5_2_E                              1'b0
    2       R/W PAD_P5_2_PU_EN                          1'b1
    3       R/W AON_PAD_P5_2_PD                         1'b1
    4       R/W PAD_P5_2_PUPDC                          1'b0
    5       R/W PAD_P5_2_WKEN                           1'b0
    6       R/W PAD_P5_2_WKPOL                          1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P5_2_SHDN                           1'b1
    9       R/W PAD_P5_2_S                              1'b0
    10      R/W PAD_P5_2_DEB                            1'b0
    12:11   R   reserved                                2'b00
    13      R/W PAD_P5_2_dbg_en                         1'b0
    15:14   R   reserved                                2'b00
 */
typedef volatile union _AON_FAST_REG_REG0X_P5_2_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P5_2_O: 1;
        uint16_t PAD_P5_2_E: 1;
        uint16_t PAD_P5_2_PU_EN: 1;
        uint16_t AON_PAD_P5_2_PD: 1;
        uint16_t PAD_P5_2_PUPDC: 1;
        uint16_t PAD_P5_2_WKEN: 1;
        uint16_t PAD_P5_2_WKPOL: 1;
        uint16_t reserved_2: 1;
        uint16_t PAD_P5_2_SHDN: 1;
        uint16_t PAD_P5_2_S: 1;
        uint16_t PAD_P5_2_DEB: 1;
        uint16_t reserved_1: 2;
        uint16_t PAD_P5_2_dbg_en: 1;
        uint16_t reserved: 2;
    };
} AON_FAST_REG_REG0X_P5_2_CFG_TYPE;

/* 0x9a
    0       W1C PAD_P1_STS[5]                           1'b1
    1       W1C PAD_P1_STS[6]                           1'b1
    2       W1C PAD_P1_STS[7]                           1'b1
    3       W1C PAD_P3_STS[0]                           1'b1
    4       W1C PAD_P3_STS[1]                           1'b1
    5       W1C PAD_P3_STS[2]                           1'b1
    6       W1C PAD_P3_STS[3]                           1'b1
    7       W1C PAD_P3_STS[4]                           1'b1
    8       W1C PAD_P3_STS[5]                           1'b1
    9       W1C PAD_P3_STS[6]                           1'b1
    10      R   reserved                                1'b0
    11      W1C PAD_P5_1_STS                            1'b1
    12      W1C PAD_P5_2_STS                            1'b1
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG0X_TOP_PAD_STS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P1_STS_5: 1;
        uint16_t PAD_P1_STS_6: 1;
        uint16_t PAD_P1_STS_7: 1;
        uint16_t PAD_P3_STS_0: 1;
        uint16_t PAD_P3_STS_1: 1;
        uint16_t PAD_P3_STS_2: 1;
        uint16_t PAD_P3_STS_3: 1;
        uint16_t PAD_P3_STS_4: 1;
        uint16_t PAD_P3_STS_5: 1;
        uint16_t PAD_P3_STS_6: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P5_1_STS: 1;
        uint16_t PAD_P5_2_STS: 1;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG0X_TOP_PAD_STS_TYPE;

/* 0x9c
    0       R/W TOP_PAD_SMT                             1'b0
    1       R/W TOP_PAD_E2                              1'b1
    2       R/W TOP_PAD_H3L1                            1'b0
    3       R/W TOP_PAD_DUMMY[3]                        1'b0
    15:4    R   reserved                                12'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_TOP_PAD_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t TOP_PAD_SMT: 1;
        uint16_t TOP_PAD_E2: 1;
        uint16_t TOP_PAD_H3L1: 1;
        uint16_t TOP_PAD_DUMMY_3: 1;
        uint16_t reserved: 12;
    };
} AON_FAST_REG_REG0X_TOP_PAD_CFG_TYPE;

/* 0xa0
    0       R/W PAD_P0_O[5]                             1'b0
    1       R/W PAD_P0_E[5]                             1'b0
    2       R/W PAD_P0_PU_EN[5]                         1'b1
    3       R/W AON_PAD_P0_PD[5]                        1'b1
    4       R/W PAD_P0_PUPDC[5]                         1'b0
    5       R/W PAD_P0_WKEN[5]                          1'b0
    6       R/W PAD_P0_WKPOL[5]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P0_SHDN[5]                          1'b1
    9       R/W PAD_P0_S[5]                             1'b0
    10      R/W PAD_P0_DEB[5]                           1'b0
    11      R/W PAD_P0_E2[5]                            1'b0
    12      R/W PAD_P0_E2_AUX[5]                        1'b0
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG0X_P0_5_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P0_O_5: 1;
        uint16_t PAD_P0_E_5: 1;
        uint16_t PAD_P0_PU_EN_5: 1;
        uint16_t AON_PAD_P0_PD_5: 1;
        uint16_t PAD_P0_PUPDC_5: 1;
        uint16_t PAD_P0_WKEN_5: 1;
        uint16_t PAD_P0_WKPOL_5: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P0_SHDN_5: 1;
        uint16_t PAD_P0_S_5: 1;
        uint16_t PAD_P0_DEB_5: 1;
        uint16_t PAD_P0_E2_5: 1;
        uint16_t PAD_P0_E2_AUX_5: 1;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG0X_P0_5_CFG_TYPE;

/* 0xa2
    0       R/W PAD_P0_O[6]                             1'b0
    1       R/W PAD_P0_E[6]                             1'b0
    2       R/W PAD_P0_PU_EN[6]                         1'b1
    3       R/W AON_PAD_P0_PD[6]                        1'b1
    4       R/W PAD_P0_PUPDC[6]                         1'b0
    5       R/W PAD_P0_WKEN[6]                          1'b0
    6       R/W PAD_P0_WKPOL[6]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P0_SHDN[6]                          1'b1
    9       R/W PAD_P0_S[6]                             1'b0
    10      R/W PAD_P0_DEB[6]                           1'b0
    11      R/W PAD_P0_E2[6]                            1'b0
    12      R/W PAD_P0_E2_AUX[6]                        1'b0
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG0X_P0_6_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P0_O_6: 1;
        uint16_t PAD_P0_E_6: 1;
        uint16_t PAD_P0_PU_EN_6: 1;
        uint16_t AON_PAD_P0_PD_6: 1;
        uint16_t PAD_P0_PUPDC_6: 1;
        uint16_t PAD_P0_WKEN_6: 1;
        uint16_t PAD_P0_WKPOL_6: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P0_SHDN_6: 1;
        uint16_t PAD_P0_S_6: 1;
        uint16_t PAD_P0_DEB_6: 1;
        uint16_t PAD_P0_E2_6: 1;
        uint16_t PAD_P0_E2_AUX_6: 1;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG0X_P0_6_CFG_TYPE;

/* 0xa4
    0       R/W PAD_P0_O[7]                             1'b0
    1       R/W PAD_P0_E[7]                             1'b0
    2       R/W PAD_P0_PU_EN[7]                         1'b1
    3       R/W AON_PAD_P0_PD[7]                        1'b1
    4       R/W PAD_P0_PUPDC[7]                         1'b0
    5       R/W PAD_P0_WKEN[7]                          1'b0
    6       R/W PAD_P0_WKPOL[7]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P0_SHDN[7]                          1'b1
    9       R/W PAD_P0_S[7]                             1'b0
    10      R/W PAD_P0_DEB[7]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P0_7_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P0_O_7: 1;
        uint16_t PAD_P0_E_7: 1;
        uint16_t PAD_P0_PU_EN_7: 1;
        uint16_t AON_PAD_P0_PD_7: 1;
        uint16_t PAD_P0_PUPDC_7: 1;
        uint16_t PAD_P0_WKEN_7: 1;
        uint16_t PAD_P0_WKPOL_7: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P0_SHDN_7: 1;
        uint16_t PAD_P0_S_7: 1;
        uint16_t PAD_P0_DEB_7: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P0_7_CFG_TYPE;

/* 0xa6
    0       R/W PAD_P4_O[0]                             1'b0
    1       R/W PAD_P4_E[0]                             1'b0
    2       R/W PAD_P4_PU_EN[0]                         1'b1
    3       R/W AON_PAD_P4_PD[0]                        1'b1
    4       R/W PAD_P4_PUPDC[0]                         1'b0
    5       R/W PAD_P4_WKEN[0]                          1'b0
    6       R/W PAD_P4_WKPOL[0]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P4_SHDN[0]                          1'b1
    9       R/W PAD_P4_S[0]                             1'b0
    10      R/W PAD_P4_DEB[0]                           1'b0
    12:11   R   reserved                                2'b00
    14:13   R/W PAD_P4_0_CFG                            2'b00
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_P4_0_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P4_O_0: 1;
        uint16_t PAD_P4_E_0: 1;
        uint16_t PAD_P4_PU_EN_0: 1;
        uint16_t AON_PAD_P4_PD_0: 1;
        uint16_t PAD_P4_PUPDC_0: 1;
        uint16_t PAD_P4_WKEN_0: 1;
        uint16_t PAD_P4_WKPOL_0: 1;
        uint16_t reserved_2: 1;
        uint16_t PAD_P4_SHDN_0: 1;
        uint16_t PAD_P4_S_0: 1;
        uint16_t PAD_P4_DEB_0: 1;
        uint16_t reserved_1: 2;
        uint16_t PAD_P4_0_CFG: 2;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG0X_P4_0_CFG_TYPE;

/* 0xa8
    0       R/W PAD_P4_O[1]                             1'b0
    1       R/W PAD_P4_E[1]                             1'b0
    2       R/W PAD_P4_PU_EN[1]                         1'b1
    3       R/W AON_PAD_P4_PD[1]                        1'b1
    4       R/W PAD_P4_PUPDC[1]                         1'b0
    5       R/W PAD_P4_WKEN[1]                          1'b0
    6       R/W PAD_P4_WKPOL[1]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P4_SHDN[1]                          1'b1
    9       R/W PAD_P4_S[1]                             1'b0
    10      R/W PAD_P4_DEB[1]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P4_1_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P4_O_1: 1;
        uint16_t PAD_P4_E_1: 1;
        uint16_t PAD_P4_PU_EN_1: 1;
        uint16_t AON_PAD_P4_PD_1: 1;
        uint16_t PAD_P4_PUPDC_1: 1;
        uint16_t PAD_P4_WKEN_1: 1;
        uint16_t PAD_P4_WKPOL_1: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P4_SHDN_1: 1;
        uint16_t PAD_P4_S_1: 1;
        uint16_t PAD_P4_DEB_1: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P4_1_CFG_TYPE;

/* 0xaa
    0       R/W PAD_P4_O[2]                             1'b0
    1       R/W PAD_P4_E[2]                             1'b0
    2       R/W PAD_P4_PU_EN[2]                         1'b1
    3       R/W AON_PAD_P4_PD[2]                        1'b1
    4       R/W PAD_P4_PUPDC[2]                         1'b0
    5       R/W PAD_P4_WKEN[2]                          1'b0
    6       R/W PAD_P4_WKPOL[2]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P4_SHDN[2]                          1'b1
    9       R/W PAD_P4_S[2]                             1'b0
    10      R/W PAD_P4_DEB[2]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P4_2_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P4_O_2: 1;
        uint16_t PAD_P4_E_2: 1;
        uint16_t PAD_P4_PU_EN_2: 1;
        uint16_t AON_PAD_P4_PD_2: 1;
        uint16_t PAD_P4_PUPDC_2: 1;
        uint16_t PAD_P4_WKEN_2: 1;
        uint16_t PAD_P4_WKPOL_2: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P4_SHDN_2: 1;
        uint16_t PAD_P4_S_2: 1;
        uint16_t PAD_P4_DEB_2: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P4_2_CFG_TYPE;

/* 0xac
    0       R/W PAD_P4_O[3]                             1'b0
    1       R/W PAD_P4_E[3]                             1'b0
    2       R/W PAD_P4_PU_EN[3]                         1'b1
    3       R/W AON_PAD_P4_PD[3]                        1'b0
    4       R/W PAD_P4_PUPDC[3]                         1'b0
    5       R/W PAD_P4_WKEN[3]                          1'b0
    6       R/W PAD_P4_WKPOL[3]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P4_SHDN[3]                          1'b1
    9       R/W PAD_P4_S[3]                             1'b0
    10      R/W PAD_P4_DEB[3]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P4_3_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P4_O_3: 1;
        uint16_t PAD_P4_E_3: 1;
        uint16_t PAD_P4_PU_EN_3: 1;
        uint16_t AON_PAD_P4_PD_3: 1;
        uint16_t PAD_P4_PUPDC_3: 1;
        uint16_t PAD_P4_WKEN_3: 1;
        uint16_t PAD_P4_WKPOL_3: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P4_SHDN_3: 1;
        uint16_t PAD_P4_S_3: 1;
        uint16_t PAD_P4_DEB_3: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P4_3_CFG_TYPE;

/* 0xae
    0       W1C PAD_P0_STS[5]                           1'b1
    1       W1C PAD_P0_STS[6]                           1'b1
    2       W1C PAD_P0_STS[7]                           1'b1
    3       W1C PAD_P4_STS[0]                           1'b1
    4       W1C PAD_P4_STS[1]                           1'b1
    5       W1C PAD_P4_STS[2]                           1'b1
    6       W1C PAD_P4_STS[3]                           1'b1
    7       R   reserved                                1'b0
    8       R/W POWPAD1                                 1'b1
    9       R/W BOT_PAD_SMT                             1'b0
    10      R/W BOT_PAD_E2                              1'b1
    11      R/W BOT_PAD_H3L1                            1'b0
    12      R/W BOT_PAD_DUMMY[12]                       1'b0
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG0X_BOT_PAD_STS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P0_STS_5: 1;
        uint16_t PAD_P0_STS_6: 1;
        uint16_t PAD_P0_STS_7: 1;
        uint16_t PAD_P4_STS_0: 1;
        uint16_t PAD_P4_STS_1: 1;
        uint16_t PAD_P4_STS_2: 1;
        uint16_t PAD_P4_STS_3: 1;
        uint16_t reserved_1: 1;
        uint16_t POWPAD1: 1;
        uint16_t BOT_PAD_SMT: 1;
        uint16_t BOT_PAD_E2: 1;
        uint16_t BOT_PAD_H3L1: 1;
        uint16_t BOT_PAD_DUMMY_12: 1;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG0X_BOT_PAD_STS_TYPE;

/* 0xc0
    0       R/W PAD_P2_O[0]                             1'b0
    1       R/W PAD_P2_E[0]                             1'b0
    2       R/W PAD_P2_PU_EN[0]                         1'b1
    3       R/W AON_PAD_P2_PD[0]                        1'b1
    4       R/W PAD_P2_PUPDC[0]                         1'b0
    5       R/W PAD_P2_WKEN[0]                          1'b0
    6       R/W PAD_P2_WKPOL[0]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P2_SHDN[0]                          1'b1
    9       R/W PAD_P2_S[0]                             1'b0
    10      R/W PAD_P2_DEB[0]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P2_0_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P2_O_0: 1;
        uint16_t PAD_P2_E_0: 1;
        uint16_t PAD_P2_PU_EN_0: 1;
        uint16_t AON_PAD_P2_PD_0: 1;
        uint16_t PAD_P2_PUPDC_0: 1;
        uint16_t PAD_P2_WKEN_0: 1;
        uint16_t PAD_P2_WKPOL_0: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P2_SHDN_0: 1;
        uint16_t PAD_P2_S_0: 1;
        uint16_t PAD_P2_DEB_0: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P2_0_CFG_TYPE;

/* 0xc2
    0       R/W PAD_P2_O[1]                             1'b0
    1       R/W PAD_P2_E[1]                             1'b0
    2       R/W PAD_P2_PU_EN[1]                         1'b1
    3       R/W AON_PAD_P2_PD[1]                        1'b1
    4       R/W PAD_P2_PUPDC[1]                         1'b0
    5       R/W PAD_P2_WKEN[1]                          1'b0
    6       R/W PAD_P2_WKPOL[1]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P2_SHDN[1]                          1'b1
    9       R/W PAD_P2_S[1]                             1'b0
    10      R/W PAD_P2_DEB[1]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P2_1_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P2_O_1: 1;
        uint16_t PAD_P2_E_1: 1;
        uint16_t PAD_P2_PU_EN_1: 1;
        uint16_t AON_PAD_P2_PD_1: 1;
        uint16_t PAD_P2_PUPDC_1: 1;
        uint16_t PAD_P2_WKEN_1: 1;
        uint16_t PAD_P2_WKPOL_1: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P2_SHDN_1: 1;
        uint16_t PAD_P2_S_1: 1;
        uint16_t PAD_P2_DEB_1: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P2_1_CFG_TYPE;

/* 0xc4
    0       R/W PAD_P2_O[2]                             1'b0
    1       R/W PAD_P2_E[2]                             1'b0
    2       R/W PAD_P2_PU_EN[2]                         1'b1
    3       R/W AON_PAD_P2_PD[2]                        1'b1
    4       R/W PAD_P2_PUPDC[2]                         1'b0
    5       R/W PAD_P2_WKEN[2]                          1'b0
    6       R/W PAD_P2_WKPOL[2]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P2_SHDN[2]                          1'b1
    9       R/W PAD_P2_S[2]                             1'b0
    10      R/W PAD_P2_DEB[2]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P2_2_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P2_O_2: 1;
        uint16_t PAD_P2_E_2: 1;
        uint16_t PAD_P2_PU_EN_2: 1;
        uint16_t AON_PAD_P2_PD_2: 1;
        uint16_t PAD_P2_PUPDC_2: 1;
        uint16_t PAD_P2_WKEN_2: 1;
        uint16_t PAD_P2_WKPOL_2: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P2_SHDN_2: 1;
        uint16_t PAD_P2_S_2: 1;
        uint16_t PAD_P2_DEB_2: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P2_2_CFG_TYPE;

/* 0xc6
    0       R/W PAD_P2_O[3]                             1'b0
    1       R/W PAD_P2_E[3]                             1'b0
    2       R/W PAD_P2_PU_EN[3]                         1'b1
    3       R/W AON_PAD_P2_PD[3]                        1'b1
    4       R/W PAD_P2_PUPDC[3]                         1'b0
    5       R/W PAD_P2_WKEN[3]                          1'b0
    6       R/W PAD_P2_WKPOL[3]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P2_SHDN[3]                          1'b1
    9       R/W PAD_P2_S[3]                             1'b0
    10      R/W PAD_P2_DEB[3]                           1'b0
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG0X_P2_3_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P2_O_3: 1;
        uint16_t PAD_P2_E_3: 1;
        uint16_t PAD_P2_PU_EN_3: 1;
        uint16_t AON_PAD_P2_PD_3: 1;
        uint16_t PAD_P2_PUPDC_3: 1;
        uint16_t PAD_P2_WKEN_3: 1;
        uint16_t PAD_P2_WKPOL_3: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P2_SHDN_3: 1;
        uint16_t PAD_P2_S_3: 1;
        uint16_t PAD_P2_DEB_3: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P2_3_CFG_TYPE;

/* 0xc8
    0       R/W PAD_P2_O[4]                             1'b0
    1       R/W PAD_P2_E[4]                             1'b0
    2       R/W PAD_P2_PU_EN[4]                         1'b1
    3       R/W AON_PAD_P2_PD[4]                        1'b1
    4       R/W PAD_P2_PUPDC[4]                         1'b0
    5       R/W PAD_P2_WKEN[4]                          1'b0
    6       R/W PAD_P2_WKPOL[4]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P2_SHDN[4]                          1'b1
    9       R/W PAD_P2_S[4]                             1'b0
    10      R/W PAD_P2_DEB[4]                           1'b0
    12:11   R   reserved                                2'b00
    15:13   R/W PAD_P2_4_CFG                            3'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_P2_4_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P2_O_4: 1;
        uint16_t PAD_P2_E_4: 1;
        uint16_t PAD_P2_PU_EN_4: 1;
        uint16_t AON_PAD_P2_PD_4: 1;
        uint16_t PAD_P2_PUPDC_4: 1;
        uint16_t PAD_P2_WKEN_4: 1;
        uint16_t PAD_P2_WKPOL_4: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P2_SHDN_4: 1;
        uint16_t PAD_P2_S_4: 1;
        uint16_t PAD_P2_DEB_4: 1;
        uint16_t reserved: 2;
        uint16_t PAD_P2_4_CFG: 3;
    };
} AON_FAST_REG_REG0X_P2_4_CFG_TYPE;

/* 0xca
    0       R/W PAD_P2_O[5]                             1'b0
    1       R/W PAD_P2_E[5]                             1'b0
    2       R/W PAD_P2_PU_EN[5]                         1'b1
    3       R/W AON_PAD_P2_PD[5]                        1'b1
    4       R/W PAD_P2_PUPDC[5]                         1'b0
    5       R/W PAD_P2_WKEN[5]                          1'b0
    6       R/W PAD_P2_WKPOL[5]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P2_SHDN[5]                          1'b1
    9       R/W PAD_P2_S[5]                             1'b0
    10      R/W PAD_P2_DEB[5]                           1'b0
    12:11   R   reserved                                2'b0
    14:13   R/W PAD_P2_5_CFG                            2'b00
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_P2_5_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P2_O_5: 1;
        uint16_t PAD_P2_E_5: 1;
        uint16_t PAD_P2_PU_EN_5: 1;
        uint16_t AON_PAD_P2_PD_5: 1;
        uint16_t PAD_P2_PUPDC_5: 1;
        uint16_t PAD_P2_WKEN_5: 1;
        uint16_t PAD_P2_WKPOL_5: 1;
        uint16_t reserved_2: 1;
        uint16_t PAD_P2_SHDN_5: 1;
        uint16_t PAD_P2_S_5: 1;
        uint16_t PAD_P2_DEB_5: 1;
        uint16_t reserved_1: 2;
        uint16_t PAD_P2_5_CFG: 2;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG0X_P2_5_CFG_TYPE;

/* 0xcc
    0       R/W PAD_P2_O[6]                             1'b0
    1       R/W PAD_P2_E[6]                             1'b0
    2       R/W PAD_P2_PU_EN[6]                         1'b1
    3       R/W AON_PAD_P2_PD[6]                        1'b1
    4       R/W PAD_P2_PUPDC[6]                         1'b0
    5       R/W PAD_P2_WKEN[6]                          1'b0
    6       R/W PAD_P2_WKPOL[6]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P2_SHDN[6]                          1'b1
    9       R/W PAD_P2_S[6]                             1'b0
    10      R/W PAD_P2_DEB[6]                           1'b0
    12:11   R   reserved                                2'b00
    13      R/W PAD_P2_6_dbg_en                         1'b0
    15:14   R   reserved                                2'b00
 */
typedef volatile union _AON_FAST_REG_REG0X_P2_6_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P2_O_6: 1;
        uint16_t PAD_P2_E_6: 1;
        uint16_t PAD_P2_PU_EN_6: 1;
        uint16_t AON_PAD_P2_PD_6: 1;
        uint16_t PAD_P2_PUPDC_6: 1;
        uint16_t PAD_P2_WKEN_6: 1;
        uint16_t PAD_P2_WKPOL_6: 1;
        uint16_t reserved_2: 1;
        uint16_t PAD_P2_SHDN_6: 1;
        uint16_t PAD_P2_S_6: 1;
        uint16_t PAD_P2_DEB_6: 1;
        uint16_t reserved_1: 2;
        uint16_t PAD_P2_6_dbg_en: 1;
        uint16_t reserved: 2;
    };
} AON_FAST_REG_REG0X_P2_6_CFG_TYPE;

/* 0xce
    0       R/W PAD_P2_O[7]                             1'b0
    1       R/W PAD_P2_E[7]                             1'b0
    2       R/W PAD_P2_PU_EN[7]                         1'b1
    3       R/W AON_PAD_P2_PD[7]                        1'b1
    4       R/W PAD_P2_PUPDC[7]                         1'b0
    5       R/W PAD_P2_WKEN[7]                          1'b0
    6       R/W PAD_P2_WKPOL[7]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P2_SHDN[7]                          1'b1
    9       R/W PAD_P2_S[7]                             1'b0
    10      R/W PAD_P2_DEB[7]                           1'b0
    12:11   R   reserved                                2'b00
    13      R/W PAD_P2_7_dbg_en                         1'b0
    15:14   R   reserved                                2'b00
 */
typedef volatile union _AON_FAST_REG_REG0X_P2_7_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P2_O_7: 1;
        uint16_t PAD_P2_E_7: 1;
        uint16_t PAD_P2_PU_EN_7: 1;
        uint16_t AON_PAD_P2_PD_7: 1;
        uint16_t PAD_P2_PUPDC_7: 1;
        uint16_t PAD_P2_WKEN_7: 1;
        uint16_t PAD_P2_WKPOL_7: 1;
        uint16_t reserved_2: 1;
        uint16_t PAD_P2_SHDN_7: 1;
        uint16_t PAD_P2_S_7: 1;
        uint16_t PAD_P2_DEB_7: 1;
        uint16_t reserved_1: 2;
        uint16_t PAD_P2_7_dbg_en: 1;
        uint16_t reserved: 2;
    };
} AON_FAST_REG_REG0X_P2_7_CFG_TYPE;

/* 0xd0
    0       R/W PAD_MICBIAS_O                           1'b0
    1       R/W PAD_MICBIAS_E                           1'b0
    2       R/W PAD_MICBIAS_PU_EN                       1'b1
    3       R/W AON_PAD_MICBIAS_PD                      1'b1
    4       R/W PAD_MICBIAS_PUPDC                       1'b0
    5       R/W PAD_MICBIAS_WKEN                        1'b0
    6       R/W PAD_MICBIAS_WKPOL                       1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_MICBIAS_SHDN                        1'b1
    9       R/W PAD_MICBIAS_S                           1'b0
    10      R/W PAD_MICBIAS_DEB                         1'b0
    12:11   R   reserved                                2'b00
    13      R/W PAD_MICBIAS_dbg_en                      1'b0
    15:14   R   reserved                                2'b00
 */
typedef volatile union _AON_FAST_REG_REG0X_P_MICBIAS_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_MICBIAS_O: 1;
        uint16_t PAD_MICBIAS_E: 1;
        uint16_t PAD_MICBIAS_PU_EN: 1;
        uint16_t AON_PAD_MICBIAS_PD: 1;
        uint16_t PAD_MICBIAS_PUPDC: 1;
        uint16_t PAD_MICBIAS_WKEN: 1;
        uint16_t PAD_MICBIAS_WKPOL: 1;
        uint16_t reserved_2: 1;
        uint16_t PAD_MICBIAS_SHDN: 1;
        uint16_t PAD_MICBIAS_S: 1;
        uint16_t PAD_MICBIAS_DEB: 1;
        uint16_t reserved_1: 2;
        uint16_t PAD_MICBIAS_dbg_en: 1;
        uint16_t reserved: 2;
    };
} AON_FAST_REG_REG0X_P_MICBIAS_CFG_TYPE;

/* 0xd2
    0       W1C PAD_P2_STS[0]                           1'b1
    1       W1C PAD_P2_STS[1]                           1'b1
    2       W1C PAD_P2_STS[2]                           1'b1
    3       W1C PAD_P2_STS[3]                           1'b1
    4       W1C PAD_P2_STS[4]                           1'b1
    5       W1C PAD_P2_STS[5]                           1'b1
    6       W1C PAD_P2_STS[6]                           1'b1
    7       W1C PAD_P2_STS[7]                           1'b1
    8       W1C PAD_MICBIAS_STS                         1'b1
    15:9    R   reserved                                7'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_LEFT_PAD_STS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P2_STS_0: 1;
        uint16_t PAD_P2_STS_1: 1;
        uint16_t PAD_P2_STS_2: 1;
        uint16_t PAD_P2_STS_3: 1;
        uint16_t PAD_P2_STS_4: 1;
        uint16_t PAD_P2_STS_5: 1;
        uint16_t PAD_P2_STS_6: 1;
        uint16_t PAD_P2_STS_7: 1;
        uint16_t PAD_MICBIAS_STS: 1;
        uint16_t reserved: 7;
    };
} AON_FAST_REG_REG0X_LEFT_PAD_STS_TYPE;

/* 0xd4
    0       R/W LEFT_PAD_SMT                            1'b0
    1       R/W LEFT_PAD_E2                             1'b1
    2       R/W LEFT_PAD_E3                             1'b0
    3       R/W LEFT_PAD_H3L1                           1'b0
    15:4    R   reserved                                12'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_LEFT_PAD_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LEFT_PAD_SMT: 1;
        uint16_t LEFT_PAD_E2: 1;
        uint16_t LEFT_PAD_E3: 1;
        uint16_t LEFT_PAD_H3L1: 1;
        uint16_t reserved: 12;
    };
} AON_FAST_REG_REG0X_LEFT_PAD_CFG_TYPE;

/* 0xe0
    0       R/W PAD_P0_O[0]                             1'b0
    1       R/W PAD_P0_E[0]                             1'b0
    2       R/W PAD_P0_PU_EN[0]                         1'b1
    3       R/W AON_PAD_P0_PD[0]                        1'b1
    4       R/W PAD_P0_PUPDC[0]                         1'b0
    5       R/W PAD_P0_WKEN[0]                          1'b0
    6       R/W PAD_P0_WKPOL[0]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P0_SHDN[0]                          1'b1
    9       R/W PAD_P0_S[0]                             1'b0
    10      R/W PAD_P0_DEB[0]                           1'b0
    11      R/W PAD_P0_E2[0]                            1'b0
    12      R/W PAD_P0_E2_AUX[0]                        1'b0
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG0X_P0_0_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P0_O_0: 1;
        uint16_t PAD_P0_E_0: 1;
        uint16_t PAD_P0_PU_EN_0: 1;
        uint16_t AON_PAD_P0_PD_0: 1;
        uint16_t PAD_P0_PUPDC_0: 1;
        uint16_t PAD_P0_WKEN_0: 1;
        uint16_t PAD_P0_WKPOL_0: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P0_SHDN_0: 1;
        uint16_t PAD_P0_S_0: 1;
        uint16_t PAD_P0_DEB_0: 1;
        uint16_t PAD_P0_E2_0: 1;
        uint16_t PAD_P0_E2_AUX_0: 1;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG0X_P0_0_CFG_TYPE;

/* 0xe2
    0       R/W PAD_P0_O[1]                             1'b0
    1       R/W PAD_P0_E[1]                             1'b0
    2       R/W PAD_P0_PU_EN[1]                         1'b1
    3       R/W AON_PAD_P0_PD[1]                        1'b1
    4       R/W PAD_P0_PUPDC[1]                         1'b0
    5       R/W PAD_P0_WKEN[1]                          1'b0
    6       R/W PAD_P0_WKPOL[1]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P0_SHDN[1]                          1'b1
    9       R/W PAD_P0_S[1]                             1'b0
    10      R/W PAD_P0_DEB[1]                           1'b0
    12:11   R   reserved                                2'b00
    13      R/W PAD_P0_1_CLK_OUT                        1'b0
    15:14   R   reserved                                2'b00
 */
typedef volatile union _AON_FAST_REG_REG0X_P0_1_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P0_O_1: 1;
        uint16_t PAD_P0_E_1: 1;
        uint16_t PAD_P0_PU_EN_1: 1;
        uint16_t AON_PAD_P0_PD_1: 1;
        uint16_t PAD_P0_PUPDC_1: 1;
        uint16_t PAD_P0_WKEN_1: 1;
        uint16_t PAD_P0_WKPOL_1: 1;
        uint16_t reserved_2: 1;
        uint16_t PAD_P0_SHDN_1: 1;
        uint16_t PAD_P0_S_1: 1;
        uint16_t PAD_P0_DEB_1: 1;
        uint16_t reserved_1: 2;
        uint16_t PAD_P0_1_CLK_OUT: 1;
        uint16_t reserved: 2;
    };
} AON_FAST_REG_REG0X_P0_1_CFG_TYPE;

/* 0xe4
    0       R/W PAD_P0_O[2]                             1'b0
    1       R/W PAD_P0_E[2]                             1'b0
    2       R/W PAD_P0_PU_EN[2]                         1'b1
    3       R/W AON_PAD_P0_PD[2]                        1'b1
    4       R/W PAD_P0_PUPDC[2]                         1'b0
    5       R/W PAD_P0_WKEN[2]                          1'b0
    6       R/W PAD_P0_WKPOL[2]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P0_SHDN[2]                          1'b1
    9       R/W PAD_P0_S[2]                             1'b0
    10      R/W PAD_P0_DEB[2]                           1'b0
    15:11   R   reserved                                5'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_P0_2_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P0_O_2: 1;
        uint16_t PAD_P0_E_2: 1;
        uint16_t PAD_P0_PU_EN_2: 1;
        uint16_t AON_PAD_P0_PD_2: 1;
        uint16_t PAD_P0_PUPDC_2: 1;
        uint16_t PAD_P0_WKEN_2: 1;
        uint16_t PAD_P0_WKPOL_2: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P0_SHDN_2: 1;
        uint16_t PAD_P0_S_2: 1;
        uint16_t PAD_P0_DEB_2: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P0_2_CFG_TYPE;

/* 0xe6
    0       R/W PAD_P0_O[3]                             1'b0
    1       R/W PAD_P0_E[3]                             1'b0
    2       R/W PAD_P0_PU_EN[3]                         1'b1
    3       R/W AON_PAD_P0_PD[3]                        1'b0
    4       R/W PAD_P0_PUPDC[3]                         1'b0
    5       R/W PAD_P0_WKEN[3]                          1'b0
    6       R/W PAD_P0_WKPOL[3]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P0_SHDN[3]                          1'b1
    9       R/W PAD_P0_S[3]                             1'b0
    10      R/W PAD_P0_DEB[3]                           1'b0
    12:11   R   reserved                                2'b00
    13      R   PAD_P0_3_I                              1'b0
    15:14   R   reserved                                2'b00
 */
typedef volatile union _AON_FAST_REG_REG0X_P0_3_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P0_O_3: 1;
        uint16_t PAD_P0_E_3: 1;
        uint16_t PAD_P0_PU_EN_3: 1;
        uint16_t AON_PAD_P0_PD_3: 1;
        uint16_t PAD_P0_PUPDC_3: 1;
        uint16_t PAD_P0_WKEN_3: 1;
        uint16_t PAD_P0_WKPOL_3: 1;
        uint16_t reserved_2: 1;
        uint16_t PAD_P0_SHDN_3: 1;
        uint16_t PAD_P0_S_3: 1;
        uint16_t PAD_P0_DEB_3: 1;
        uint16_t reserved_1: 2;
        uint16_t PAD_P0_3_I: 1;
        uint16_t reserved: 2;
    };
} AON_FAST_REG_REG0X_P0_3_CFG_TYPE;

/* 0xe8
    0       R/W PAD_P0_O[4]                             1'b0
    1       R/W PAD_P0_E[4]                             1'b0
    2       R/W PAD_P0_PU_EN[4]                         1'b1
    3       R/W AON_PAD_P0_PD[4]                        1'b1
    4       R/W PAD_P0_PUPDC[4]                         1'b0
    5       R/W PAD_P0_WKEN[4]                          1'b0
    6       R/W PAD_P0_WKPOL[4]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P0_SHDN[4]                          1'b1
    9       R/W PAD_P0_S[4]                             1'b0
    10      R/W PAD_P0_DEB[4]                           1'b0
    12:11   R   reserved                                2'b00
    13      R/W PAD_P0_4_dbg_en                         1'b0
    15:14   R   reserved                                2'b00
 */
typedef volatile union _AON_FAST_REG_REG0X_P0_4_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P0_O_4: 1;
        uint16_t PAD_P0_E_4: 1;
        uint16_t PAD_P0_PU_EN_4: 1;
        uint16_t AON_PAD_P0_PD_4: 1;
        uint16_t PAD_P0_PUPDC_4: 1;
        uint16_t PAD_P0_WKEN_4: 1;
        uint16_t PAD_P0_WKPOL_4: 1;
        uint16_t reserved_2: 1;
        uint16_t PAD_P0_SHDN_4: 1;
        uint16_t PAD_P0_S_4: 1;
        uint16_t PAD_P0_DEB_4: 1;
        uint16_t reserved_1: 2;
        uint16_t PAD_P0_4_dbg_en: 1;
        uint16_t reserved: 2;
    };
} AON_FAST_REG_REG0X_P0_4_CFG_TYPE;

/* 0xea
    0       R/W PAD_P1_O[0]                             1'b0
    1       R/W PAD_P1_E[0]                             1'b0
    2       R/W PAD_P1_PU_EN[0]                         1'b1
    3       R/W AON_PAD_P1_PD[0]                        1'b0
    4       R/W PAD_P1_PUPDC[0]                         1'b0
    5       R/W PAD_P1_WKEN[0]                          1'b0
    6       R/W PAD_P1_WKPOL[0]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P1_SHDN[0]                          1'b1
    9       R/W PAD_P1_S[0]                             1'b0
    10      R/W PAD_P1_DEB[0]                           1'b0
    15:11   R   reserved                                5'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_P1_0_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P1_O_0: 1;
        uint16_t PAD_P1_E_0: 1;
        uint16_t PAD_P1_PU_EN_0: 1;
        uint16_t AON_PAD_P1_PD_0: 1;
        uint16_t PAD_P1_PUPDC_0: 1;
        uint16_t PAD_P1_WKEN_0: 1;
        uint16_t PAD_P1_WKPOL_0: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P1_SHDN_0: 1;
        uint16_t PAD_P1_S_0: 1;
        uint16_t PAD_P1_DEB_0: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P1_0_CFG_TYPE;

/* 0xec
    0       R/W PAD_P1_O[1]                             1'b0
    1       R/W PAD_P1_E[1]                             1'b0
    2       R/W PAD_P1_PU_EN[1]                         1'b1
    3       R/W AON_PAD_P1_PD[1]                        1'b0
    4       R/W PAD_P1_PUPDC[1]                         1'b0
    5       R/W PAD_P1_WKEN[1]                          1'b0
    6       R/W PAD_P1_WKPOL[1]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P1_SHDN[1]                          1'b1
    9       R/W PAD_P1_S[1]                             1'b0
    10      R/W PAD_P1_DEB[1]                           1'b0
    15:11   R   reserved                                5'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_P1_1_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P1_O_1: 1;
        uint16_t PAD_P1_E_1: 1;
        uint16_t PAD_P1_PU_EN_1: 1;
        uint16_t AON_PAD_P1_PD_1: 1;
        uint16_t PAD_P1_PUPDC_1: 1;
        uint16_t PAD_P1_WKEN_1: 1;
        uint16_t PAD_P1_WKPOL_1: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P1_SHDN_1: 1;
        uint16_t PAD_P1_S_1: 1;
        uint16_t PAD_P1_DEB_1: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P1_1_CFG_TYPE;

/* 0xee
    0       R/W PAD_P1_O[2]                             1'b0
    1       R/W PAD_P1_E[2]                             1'b0
    2       R/W PAD_P1_PU_EN[2]                         1'b1
    3       R/W AON_PAD_P1_PD[2]                        1'b1
    4       R/W PAD_P1_PUPDC[2]                         1'b0
    5       R/W PAD_P1_WKEN[2]                          1'b0
    6       R/W PAD_P1_WKPOL[2]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P1_SHDN[2]                          1'b1
    9       R/W PAD_P1_S[2]                             1'b0
    10      R/W PAD_P1_DEB[2]                           1'b0
    15:11   R   reserved                                5'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_P1_2_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P1_O_2: 1;
        uint16_t PAD_P1_E_2: 1;
        uint16_t PAD_P1_PU_EN_2: 1;
        uint16_t AON_PAD_P1_PD_2: 1;
        uint16_t PAD_P1_PUPDC_2: 1;
        uint16_t PAD_P1_WKEN_2: 1;
        uint16_t PAD_P1_WKPOL_2: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P1_SHDN_2: 1;
        uint16_t PAD_P1_S_2: 1;
        uint16_t PAD_P1_DEB_2: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P1_2_CFG_TYPE;

/* 0xf0
    0       R/W PAD_P1_O[3]                             1'b0
    1       R/W PAD_P1_E[3]                             1'b0
    2       R/W PAD_P1_PU_EN[3]                         1'b1
    3       R/W AON_PAD_P1_PD[3]                        1'b1
    4       R/W PAD_P1_PUPDC[3]                         1'b0
    5       R/W PAD_P1_WKEN[3]                          1'b0
    6       R/W PAD_P1_WKPOL[3]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P1_SHDN[3]                          1'b1
    9       R/W PAD_P1_S[3]                             1'b0
    10      R/W PAD_P1_DEB[3]                           1'b0
    15:11   R   reserved                                5'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_P1_3_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P1_O_3: 1;
        uint16_t PAD_P1_E_3: 1;
        uint16_t PAD_P1_PU_EN_3: 1;
        uint16_t AON_PAD_P1_PD_3: 1;
        uint16_t PAD_P1_PUPDC_3: 1;
        uint16_t PAD_P1_WKEN_3: 1;
        uint16_t PAD_P1_WKPOL_3: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P1_SHDN_3: 1;
        uint16_t PAD_P1_S_3: 1;
        uint16_t PAD_P1_DEB_3: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P1_3_CFG_TYPE;

/* 0xf2
    0       R/W PAD_P1_O[4]                             1'b0
    1       R/W PAD_P1_E[4]                             1'b0
    2       R/W PAD_P1_PU_EN[4]                         1'b1
    3       R/W AON_PAD_P1_PD[4]                        1'b1
    4       R/W PAD_P1_PUPDC[4]                         1'b0
    5       R/W PAD_P1_WKEN[4]                          1'b0
    6       R/W PAD_P1_WKPOL[4]                         1'b0
    7       R   reserved                                1'b0
    8       R/W PAD_P1_SHDN[4]                          1'b1
    9       R/W PAD_P1_S[4]                             1'b0
    10      R/W PAD_P1_DEB[4]                           1'b0
    15:11   R   reserved                                5'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_P1_4_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P1_O_4: 1;
        uint16_t PAD_P1_E_4: 1;
        uint16_t PAD_P1_PU_EN_4: 1;
        uint16_t AON_PAD_P1_PD_4: 1;
        uint16_t PAD_P1_PUPDC_4: 1;
        uint16_t PAD_P1_WKEN_4: 1;
        uint16_t PAD_P1_WKPOL_4: 1;
        uint16_t reserved_1: 1;
        uint16_t PAD_P1_SHDN_4: 1;
        uint16_t PAD_P1_S_4: 1;
        uint16_t PAD_P1_DEB_4: 1;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG0X_P1_4_CFG_TYPE;

/* 0xf4
    0       W1C PAD_P0_STS[0]                           1'b1
    1       W1C PAD_P0_STS[1]                           1'b1
    2       W1C PAD_P0_STS[2]                           1'b1
    3       W1C PAD_P0_STS[3]                           1'b1
    4       W1C PAD_P0_STS[4]                           1'b1
    5       W1C PAD_P1_STS[0]                           1'b1
    6       W1C PAD_P1_STS[1]                           1'b1
    7       W1C PAD_P1_STS[2]                           1'b1
    8       W1C PAD_P1_STS[3]                           1'b1
    9       W1C PAD_P1_STS[4]                           1'b1
    15:10   R   reserved                                6'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_RIGHT_PAD_STS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t PAD_P0_STS_0: 1;
        uint16_t PAD_P0_STS_1: 1;
        uint16_t PAD_P0_STS_2: 1;
        uint16_t PAD_P0_STS_3: 1;
        uint16_t PAD_P0_STS_4: 1;
        uint16_t PAD_P1_STS_0: 1;
        uint16_t PAD_P1_STS_1: 1;
        uint16_t PAD_P1_STS_2: 1;
        uint16_t PAD_P1_STS_3: 1;
        uint16_t PAD_P1_STS_4: 1;
        uint16_t reserved: 6;
    };
} AON_FAST_REG_REG0X_RIGHT_PAD_STS_TYPE;

/* 0xf6
    0       R/W AON_PAD_SPI_FLASH_S                     1'b1
    1       R/W PAD_SPI_FLASH_SHDN                      1'b1
    2       R/W AON_PAD_SPI_SCK_PU_EN                   1'b0
    3       R/W AON_PAD_SPI_SCK_PD                      1'b0
    4       R/W PAD_SPI_SCK_PUPDC                       1'b0
    5       R/W AON_PAD_SPI_CSN_PU_EN                   1'b0
    6       R/W AON_PAD_SPI_CSN_PD                      1'b0
    7       R/W PAD_SPI_CSN_PUPDC                       1'b0
    8       R/W AON_PAD_SPI_SIO0_PU_EN                  1'b0
    9       R/W AON_PAD_SPI_SIO0_PD                     1'b0
    10      R/W PAD_SPI_SIO0_PUPDC                      1'b0
    11      R/W AON_PAD_SPI_SIO1_PU_EN                  1'b0
    12      R/W AON_PAD_SPI_SIO1_PD                     1'b0
    13      R/W PAD_SPI_SIO1_PUPDC                      1'b0
    14      R/W REG0X_P_SPI_CFG_DUMMY[14]               1'b1
    15      R/W REG0X_P_SPI_CFG_DUMMY[15]               1'b1
 */
typedef volatile union _AON_FAST_REG_REG0X_P_SPI_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t AON_PAD_SPI_FLASH_S: 1;
        uint16_t PAD_SPI_FLASH_SHDN: 1;
        uint16_t AON_PAD_SPI_SCK_PU_EN: 1;
        uint16_t AON_PAD_SPI_SCK_PD: 1;
        uint16_t PAD_SPI_SCK_PUPDC: 1;
        uint16_t AON_PAD_SPI_CSN_PU_EN: 1;
        uint16_t AON_PAD_SPI_CSN_PD: 1;
        uint16_t PAD_SPI_CSN_PUPDC: 1;
        uint16_t AON_PAD_SPI_SIO0_PU_EN: 1;
        uint16_t AON_PAD_SPI_SIO0_PD: 1;
        uint16_t PAD_SPI_SIO0_PUPDC: 1;
        uint16_t AON_PAD_SPI_SIO1_PU_EN: 1;
        uint16_t AON_PAD_SPI_SIO1_PD: 1;
        uint16_t PAD_SPI_SIO1_PUPDC: 1;
        uint16_t REG0X_P_SPI_CFG_DUMMY_14: 1;
        uint16_t REG0X_P_SPI_CFG_DUMMY_15: 1;
    };
} AON_FAST_REG_REG0X_P_SPI_CFG_TYPE;

/* 0xf8
    0       R/W RIGHT_PAD_SMT                           1'b0
    1       R/W RIGHT_PAD_E2                            1'b1
    2       R/W RIGHT_PAD_H3L1                          1'b0
    3       R/W RIGHT_PAD_DUMMY[3]                      1'b0
    4       R/W SPIC_PAD_SMT                            1'b0
    5       R/W SPIC_PAD_E2                             1'b1
    6       R/W SPIC_PAD_H3L1                           1'b0
    15:7    R   reserved                                9'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_RIGHT_PAD_CFG_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t RIGHT_PAD_SMT: 1;
        uint16_t RIGHT_PAD_E2: 1;
        uint16_t RIGHT_PAD_H3L1: 1;
        uint16_t RIGHT_PAD_DUMMY_3: 1;
        uint16_t SPIC_PAD_SMT: 1;
        uint16_t SPIC_PAD_E2: 1;
        uint16_t SPIC_PAD_H3L1: 1;
        uint16_t reserved: 9;
    };
} AON_FAST_REG_REG0X_RIGHT_PAD_CFG_TYPE;

/* 0x106
    5:0     R/W RCAL                                    6'b100000
    9:6     R/W RG0X_32KOSC_DUMMY[9:6]                  4'b0000
    10      R/W EN_TESTOUT_32K                          1'b0
    11      R   SEL_IPTAT                               1'b0
    12      R/W reserved                                1'b0
    13      R   SEL_LV                                  1'b0
    14      R/W GATED_STUP_OK                           1'b0
    15      R/W SEL_LDO_VREF                            1'b0
 */
typedef volatile union _AON_FAST_REG_RG0X_32KOSC_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t RCAL: 6;
        uint16_t RG0X_32KOSC_DUMMY_9_6: 4;
        uint16_t EN_TESTOUT_32K: 1;
        uint16_t SEL_IPTAT: 1;
        uint16_t reserved: 1;
        uint16_t SEL_LV: 1;
        uint16_t GATED_STUP_OK: 1;
        uint16_t SEL_LDO_VREF: 1;
    };
} AON_FAST_REG_RG0X_32KOSC_TYPE;

/* 0x10a
    0       R   reserved                                1'b0
    1       R/W RCAL_32_SEL                             1'b0
    15:2    R   reserved                                15'b0
 */
typedef volatile union _AON_FAST_REG_RG1X_32KOSC_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 1;
        uint16_t RCAL_32_SEL: 1;
        uint16_t reserved: 14;
    };
} AON_FAST_REG_RG1X_32KOSC_TYPE;

/* 0x110
    0       R/W aux_anapar_pow_ldo33[0]                 1'b0
    1       R/W aux_anapar_pow_ldo33[1]                 1'b0
    2       R/W aux_anapar_pow_ldo33[2]                 1'b0
    3       R/W EN_ILIMIT                               1'b0
    4       R/W EN_VREF_SW                              1'b0
    5       R/W VREF_I                                  1'b0
    6       R/W reserved                                1'b0
    7       R/W hw_pd                                   1'b1
    8       R/W POW_LDO318                              1'b0
    9       R/W EN_ILIMIT2                              1'b0
    11:10   R/W VSET                                    2'b10
    15:12   R/W LDO1211_SW[3:0]                         4'b1101
 */
typedef volatile union _AON_FAST_REG_REG0X_AUX_LDO_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t aux_anapar_pow_ldo33_0: 1;
        uint16_t aux_anapar_pow_ldo33_1: 1;
        uint16_t aux_anapar_pow_ldo33_2: 1;
        uint16_t EN_ILIMIT: 1;
        uint16_t EN_VREF_SW: 1;
        uint16_t VREF_I: 1;
        uint16_t reserved: 1;
        uint16_t hw_pd: 1;
        uint16_t POW_LDO318: 1;
        uint16_t EN_ILIMIT2: 1;
        uint16_t VSET: 2;
        uint16_t LDO1211_SW_3_0: 4;
    };
} AON_FAST_REG_REG0X_AUX_LDO_TYPE;

/* 0x112
    6:0     R/W REG_LDO_TUNE                            7'b1011111
    7       R/W EN_ADC_LDO_CPT_SW                       1'b0
    9:8     R/W reserved                                2'b00
    10      R/W AUX_LDO_VPULSE                          1'b0
    11      R/W SEL_LDO                                 1'b1
    12      R/W DOUBLE_OP_I                             1'b0
    14:13   R/W LDO_BW                                  2'b11
    15      R/W Powe                                    1'b1
 */
typedef volatile union _AON_FAST_REG_REG1X_AUX_LDO_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t REG_LDO_TUNE: 7;
        uint16_t EN_ADC_LDO_CPT_SW: 1;
        uint16_t reserved: 2;
        uint16_t AUX_LDO_VPULSE: 1;
        uint16_t SEL_LDO: 1;
        uint16_t DOUBLE_OP_I: 1;
        uint16_t LDO_BW: 2;
        uint16_t Powe: 1;
    };
} AON_FAST_REG_REG1X_AUX_LDO_TYPE;

/* 0x114
    0       R/W POW_SD_H                                1'b0
    4:1     R/W CH_NUM_H                                4'b0
    5       R/W SD_POSEDGE_H                            1'b1
    15:6    R/W REG0X_SD_DUMMY[15:6]                    10'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_SD_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t POW_SD_H: 1;
        uint16_t CH_NUM_H: 4;
        uint16_t SD_POSEDGE_H: 1;
        uint16_t REG0X_SD_DUMMY_15_6: 10;
    };
} AON_FAST_REG_REG0X_SD_TYPE;

/* 0x116
    0       R/W pow                                     1'b0
    1       R/W pow_ref                                 1'b0
    2       R/W reg_ck                                  1'b0
    3       R/W reg_delay                               1'b0
    5:4     R/W reg_vref_sel                            2'b10
    6       R/W reg_revck                               1'b0
    8:7     R/W reg_cmpdec                              2'b00
    9       R/W reg_meta                                1'b0
    10      R/W sel_ln                                  1'b0
    11      R/W sel_lna                                 1'b1
    13:12   R/W reg_vcm_sel                             2'b11
    14      R/W reg_enTG                                1'b0
    15      R/W reg_diode                               1'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_AUX_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t pow: 1;
        uint16_t pow_ref: 1;
        uint16_t reg_ck: 1;
        uint16_t reg_delay: 1;
        uint16_t reg_vref_sel: 2;
        uint16_t reg_revck: 1;
        uint16_t reg_cmpdec: 2;
        uint16_t reg_meta: 1;
        uint16_t sel_ln: 1;
        uint16_t sel_lna: 1;
        uint16_t reg_vcm_sel: 2;
        uint16_t reg_enTG: 1;
        uint16_t reg_diode: 1;
    };
} AON_FAST_REG_REG0X_AUX_TYPE;

/* 0x118
    7:0     R/W bypassen                                8'h0
    15:8    R/W REG1X_AUX_dummy                         8'h0
 */
typedef volatile union _AON_FAST_REG_REG1X_AUX_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t bypassen: 8;
        uint16_t REG1X_AUX_dummy: 8;
    };
} AON_FAST_REG_REG1X_AUX_TYPE;

/* 0x11a
    0       R/W aux_core_sel                            1'b0
    15:1    R   reserved                                15'h0
 */
typedef volatile union _AON_FAST_REG_AUX_CONTROL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t aux_core_sel: 1;
        uint16_t reserved: 15;
    };
} AON_FAST_REG_AUX_CONTROL_TYPE;

/* 0x120
    0       R/W ADDA_SW_LDO2PWRCUT                      1'b0
    1       R/W ADDA_POW_LDO_VREF                       1'b1
    2       R/W ADDA_POW_LDO_OP                         1'b1
    3       R/W ADDA_LDO_VPULSE                         1'b0
    7:4     R/W ADDA_LDO_SW                             4'b1000
    8       R/W ADDA_DOUBLE_OP_I                        1'b0
    9       R/W SW_LDO2PWRCUT                           1'b0
    10      R/W POW_LDO                                 1'b0
    11      R/W LDO_VPULSE                              1'b0
    14:12   R/W LDO_SW[2:0]                             3'b100
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_LDO_ADDA_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t ADDA_SW_LDO2PWRCUT: 1;
        uint16_t ADDA_POW_LDO_VREF: 1;
        uint16_t ADDA_POW_LDO_OP: 1;
        uint16_t ADDA_LDO_VPULSE: 1;
        uint16_t ADDA_LDO_SW: 4;
        uint16_t ADDA_DOUBLE_OP_I: 1;
        uint16_t SW_LDO2PWRCUT: 1;
        uint16_t POW_LDO: 1;
        uint16_t LDO_VPULSE: 1;
        uint16_t LDO_SW_2_0: 3;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_BT_ANAPAR_LDO_ADDA_TYPE;

/* 0x140
    2:0     R   XTAL_MODE                               3'b000
    3       R/W XTAL_DEBUG                              1'b0
    6:4     R/W XTAL_MODE_DEBUG                         3'b100
    7       R/W XTAL_MODE_NMPC                          1'b1
    15:8    R/W BT_ANAPAR_XTAL_MODE_DUMMY[15:8]         8'h0
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL_mode_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_MODE: 3;
        uint16_t XTAL_DEBUG: 1;
        uint16_t XTAL_MODE_DEBUG: 3;
        uint16_t XTAL_MODE_NMPC: 1;
        uint16_t BT_ANAPAR_XTAL_MODE_DUMMY_15_8: 8;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL_mode_TYPE;

/* 0x142
    0       R/W XTAL_EN_XTAL_AAC_GM                     1'b0
    1       R/W XTAL_EN_XTAL_AAC_PKDET                  1'b0
    2       R/W XTAL_EN_XTAL_LPS                        1'b0
    3       R/W XTAL_GATED_XTAL_OK0                     1'b0
    6:4     R/W XTAL_AAC_PK_SEL                         3'b101
    10:7    R/W XTAL_AAC_PK_LP_SEL                      4'b0101
    15:11   R/W XTAL_BUF_GMN                            5'b01000
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL0_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_EN_XTAL_AAC_GM: 1;
        uint16_t XTAL_EN_XTAL_AAC_PKDET: 1;
        uint16_t XTAL_EN_XTAL_LPS: 1;
        uint16_t XTAL_GATED_XTAL_OK0: 1;
        uint16_t XTAL_AAC_PK_SEL: 3;
        uint16_t XTAL_AAC_PK_LP_SEL: 4;
        uint16_t XTAL_BUF_GMN: 5;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL0_TYPE;

/* 0x144
    4:0     R/W XTAL_BUF_GMN_LP                         5'b01000
    9:5     R/W XTAL_BUF_GMP                            5'b01000
    14:10   R/W XTAL_BUF_GMP_LP                         5'b01000
    15      R/W XTAL_BK_BG                              1'b0
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL1_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_BUF_GMN_LP: 5;
        uint16_t XTAL_BUF_GMP: 5;
        uint16_t XTAL_BUF_GMP_LP: 5;
        uint16_t XTAL_BK_BG: 1;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL1_TYPE;

/* 0x146
    0       R/W XTAL_DELAY_AFE                          1'b0
    1       R/W XTAL_DELAY_USB                          1'b0
    2       R/W XTAL_DOUBLE_OP_I                        1'b0
    4:3     R/W XTAL_DRV_AFE                            2'b11
    6:5     R/W XTAL_DRV_USB                            2'b11
    8:7     R/W XTAL_DRV_RF                             2'b11
    9       R/W XTAL_DRV_RF_LATCH                       1'b0
    10      R/W XTAL_GATED_AFEP                         1'b0
    11      R/W XTAL_GATED_AFEN                         1'b0
    12      R/W XTAL_GATED_USBP                         1'b0
    13      R/W XTAL_GATED_USBN                         1'b0
    14      R/W XTAL_GATED_RFP                          1'b0
    15      R/W XTAL_GATED_RFN                          1'b0
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL2_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_DELAY_AFE: 1;
        uint16_t XTAL_DELAY_USB: 1;
        uint16_t XTAL_DOUBLE_OP_I: 1;
        uint16_t XTAL_DRV_AFE: 2;
        uint16_t XTAL_DRV_USB: 2;
        uint16_t XTAL_DRV_RF: 2;
        uint16_t XTAL_DRV_RF_LATCH: 1;
        uint16_t XTAL_GATED_AFEP: 1;
        uint16_t XTAL_GATED_AFEN: 1;
        uint16_t XTAL_GATED_USBP: 1;
        uint16_t XTAL_GATED_USBN: 1;
        uint16_t XTAL_GATED_RFP: 1;
        uint16_t XTAL_GATED_RFN: 1;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL2_TYPE;

/* 0x148
    5:0     R/W XTAL_GM                                 6'b111111
    11:6    R/W XTAL_GM_LP                              6'b111111
    12      R/W XTAL_GM_SEP                             1'b0
    13      R/W XTAL_IDOUBLE                            1'b0
    14      R/W XTAL_IS_FINE_MANU                       1'b0
    15      R/W XTAL_SW_LDO2PWRCUT                      1'b0
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL3_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_GM: 6;
        uint16_t XTAL_GM_LP: 6;
        uint16_t XTAL_GM_SEP: 1;
        uint16_t XTAL_IDOUBLE: 1;
        uint16_t XTAL_IS_FINE_MANU: 1;
        uint16_t XTAL_SW_LDO2PWRCUT: 1;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL3_TYPE;

/* 0x14a
    5:0     R/W XTAL_GM_OK0                             6'b111111
    11:6    R/W XTAL_IS                                 6'b111111
    15:12   R/W XTAL_REG4X_DUMMY[15:12]                 4'b0000
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL4_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_GM_OK0: 6;
        uint16_t XTAL_IS: 6;
        uint16_t XTAL_REG4X_DUMMY_15_12: 4;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL4_TYPE;

/* 0x14c
    7:0     R/W XTAL_IS_FINE                            8'b11111111
    13:8    R/W XTAL_IS_LP                              6'b000000
    15:14   R/W XTAL_PKDET_LP_TSEL                      2'b01
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL5_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_IS_FINE: 8;
        uint16_t XTAL_IS_LP: 6;
        uint16_t XTAL_PKDET_LP_TSEL: 2;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL5_TYPE;

/* 0x14e
    2:0     R/W XTAL_LPS_CKMODE                         3'b110
    5:3     R/W XTAL_LDO                                3'b011
    8:6     R/W XTAL_LDO_OK                             3'b011
    11:9    R/W XTAL_LPM_CKO_SEL                        3'b011
    14:12   R/W XTAL_SEL_TOK                            3'b101
    15      R/W XTAL_reg_fast_settling                  1'b1
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL6_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_LPS_CKMODE: 3;
        uint16_t XTAL_LDO: 3;
        uint16_t XTAL_LDO_OK: 3;
        uint16_t XTAL_LPM_CKO_SEL: 3;
        uint16_t XTAL_SEL_TOK: 3;
        uint16_t XTAL_reg_fast_settling: 1;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL6_TYPE;

/* 0x150
    7:0     R/W XTAL_SC_XI                              8'b00111111
    15:8    R/W XTAL_SC_XI_LP                           8'b11111111
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL7_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_SC_XI: 8;
        uint16_t XTAL_SC_XI_LP: 8;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL7_TYPE;

/* 0x152
    7:0     R/W XTAL_SC_XI_OK0                          8'b11110000
    15:8    R/W XTAL_SC_XO                              8'b00111111
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL8_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_SC_XI_OK0: 8;
        uint16_t XTAL_SC_XO: 8;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL8_TYPE;

/* 0x154
    7:0     R/W XTAL_SC_XO_LP                           8'b11111111
    15:8    R/W XTAL_SC_XO_OK0                          8'b11110000
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL9_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_SC_XO_LP: 8;
        uint16_t XTAL_SC_XO_OK0: 8;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL9_TYPE;

/* 0x156
    2:0     R/W XTAL_XORES_SEL                          3'b000
    4:3     R/W XTAL_reg_stp                            2'b00
    8:5     R/W XTAL_reg_dout_offset                    4'b0011
    9       R/W XTAL_GATED_LPMODE                       1'b0
    10      R/W XTAL_GATED_EN_PEAKDET_LP                1'b0
    11      R/W XTAL_LDOPC_SEL                          1'b0
    12      R/W XTAL_BUF_LPS_SEL                        1'b0
    13      R/W XTAL_LPMODE_CLK_SEL                     1'b0
    14      R/W XTAL_reg_fast_always_on                 1'b0
    15      R/W XTAL_LPMODE_CLK_AON                     1'b0
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL10_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_XORES_SEL: 3;
        uint16_t XTAL_reg_stp: 2;
        uint16_t XTAL_reg_dout_offset: 4;
        uint16_t XTAL_GATED_LPMODE: 1;
        uint16_t XTAL_GATED_EN_PEAKDET_LP: 1;
        uint16_t XTAL_LDOPC_SEL: 1;
        uint16_t XTAL_BUF_LPS_SEL: 1;
        uint16_t XTAL_LPMODE_CLK_SEL: 1;
        uint16_t XTAL_reg_fast_always_on: 1;
        uint16_t XTAL_LPMODE_CLK_AON: 1;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL10_TYPE;

/* 0x158
    0       R/W XTAL_IOP_SEL                            1'b0
    1       R/W XTAL_EN_XTAL_PDCK_LP                    1'b0
    4:2     R/W XTAL_LDO_SW_LP                          3'b000
    9:5     R/W XTAL_PDC_LP                             5'b10000
    10      R/W XTAL_PDC_MANUAL                         1'b0
    11      R/W XTAL_PKDET_CMP_SWAP                     1'b0
    12      R/W XTAL_PKDET_LOAD_SWAP                    1'b0
    15:13   R/W XTAL_SEL_TOK01                          3'b100
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL11_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_IOP_SEL: 1;
        uint16_t XTAL_EN_XTAL_PDCK_LP: 1;
        uint16_t XTAL_LDO_SW_LP: 3;
        uint16_t XTAL_PDC_LP: 5;
        uint16_t XTAL_PDC_MANUAL: 1;
        uint16_t XTAL_PKDET_CMP_SWAP: 1;
        uint16_t XTAL_PKDET_LOAD_SWAP: 1;
        uint16_t XTAL_SEL_TOK01: 3;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL11_TYPE;

/* 0x15a
    3:0     R/W XTAL_LPSCLK_CNTRL                       4'b0000
    4       R/W XTAL_EN_XTAL_SEL_TOK01                  1'b0
    5       R/W XTAL_EN_XO_CLK_SW                       1'b0
    6       R/W XTAL_FASTSET_MANU                       1'b0
    8:7     R/W XTAL_OV_RATIO                           2'b01
    11:9    R/W XTAL_OV_UNIT                            3'b010
    12      R/W XTAL_LPS_CAP_CTRL                       1'b1
    14:13   R/W XTAL_LPS_CAP_CYC                        2'b00
    15      R/W XTAL_MD_LPOW                            1'b0
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL12_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_LPSCLK_CNTRL: 4;
        uint16_t XTAL_EN_XTAL_SEL_TOK01: 1;
        uint16_t XTAL_EN_XO_CLK_SW: 1;
        uint16_t XTAL_FASTSET_MANU: 1;
        uint16_t XTAL_OV_RATIO: 2;
        uint16_t XTAL_OV_UNIT: 3;
        uint16_t XTAL_LPS_CAP_CTRL: 1;
        uint16_t XTAL_LPS_CAP_CYC: 2;
        uint16_t XTAL_MD_LPOW: 1;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL12_TYPE;

/* 0x15c
    5:0     R/W XTAL_WAIT_CYC                           6'b000010
    7:6     R/W XTAL_LPS_CAP_STEP                       2'b01
    8       R/W XTAL_BYPASS_CTRL                        1'b0
    11:9    R/W XTAL_RDY_SEL_TOK                        3'b100
    15:12   R/W XTAL_CTRL_OUT_SEL                       4'b0000
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL13_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_WAIT_CYC: 6;
        uint16_t XTAL_LPS_CAP_STEP: 2;
        uint16_t XTAL_BYPASS_CTRL: 1;
        uint16_t XTAL_RDY_SEL_TOK: 3;
        uint16_t XTAL_CTRL_OUT_SEL: 4;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL13_TYPE;

/* 0x15e
    15:0    R/W XTAL_CTRL1                              16'b0000000000000000
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL14_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_CTRL1;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL14_TYPE;

/* 0x160
    15:0    R/W XTAL_CTRL2                              16'b0000000000000000
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL15_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_CTRL2;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL15_TYPE;

/* 0x162
    15:0    R/W XTAL_REG16X_DUMMY[15:0]                 16'b0000000000000000
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL16_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_REG16X_DUMMY_15_0;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL16_TYPE;

/* 0x164
    15:0    R/W XTAL_REG17X_DUMMY[15:0]                 16'b0000000000000000
 */
typedef volatile union _AON_FAST_REG_BT_ANAPAR_XTAL17_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_REG17X_DUMMY_15_0;
    };
} AON_FAST_REG_BT_ANAPAR_XTAL17_TYPE;

/* 0x166
    7:0     R   XTAL_IS_FINEO                           8'b11111111
    15:8    R   reserved                                8'h0
 */
typedef volatile union _AON_FAST_REG_REG0X_XTAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t XTAL_IS_FINEO: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG0X_XTAL_TYPE;

/* 0x168
    2:0     R   reserved                                3'b000
    3       R/W AAC_SEL                                 1'b0
    9:4     R/W AAC_GM1                                 6'h1f
    15:10   R/W AAC_GM                                  6'h1f
 */
typedef volatile union _AON_FAST_REG_REG1X_XTAL_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved: 3;
        uint16_t AAC_SEL: 1;
        uint16_t AAC_GM1: 6;
        uint16_t AAC_GM: 6;
    };
} AON_FAST_REG_REG1X_XTAL_TYPE;

/* 0x180
    0       R/W LOP_PON_LDO_POW_LDORET                  1'b0
    1       R/W LOP_PON_LDO_POW_BIAS_LDOANA             1'b1
    2       R/W LOP_PON_LDO_ENPC_LDOANA                 1'b0
    3       R/W LOP_PON_LDO_POW_LDOANA                  1'b1
    4       R/W LOP_PON_LDO_POW_VDDANA                  1'b1
    5       R/W LOP_PON_LDO_POW_VDDCORE                 1'b1
    6       R/W LOP_PON_FLASH_PC_VG2                    1'b0
    7       R/W LOP_PON_FLASH_PC_VG1                    1'b0
    8       R/W LOP_PON_LDO_EN_VAON_VANA_PC             1'b0
    9       R/W LOP_PON_LDO_EN_LDO311_DMY_LITE          1'b1
    10      R/W LOP_PON_LDO_POW_LDO311                  1'b1
    11      R/W LOP_PON_LDO_EN_LDO311_VDIV              1'b1
    12      R/W LOP_PON_MBIAS_POR_VIO_EN                1'b1
    13      R/W LOP_PON_MBIAS_POR_DVDDCORE_EN           1'b1
    14      R/W LOP_PON_MBIAS_POW_BG_EBIAS_AUXADC       1'b1
    15      R/W LOP_PON_MBIAS_BIAS50NA_EN               1'b1
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_PON_RG0X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_PON_LDO_POW_LDORET: 1;
        uint16_t LOP_PON_LDO_POW_BIAS_LDOANA: 1;
        uint16_t LOP_PON_LDO_ENPC_LDOANA: 1;
        uint16_t LOP_PON_LDO_POW_LDOANA: 1;
        uint16_t LOP_PON_LDO_POW_VDDANA: 1;
        uint16_t LOP_PON_LDO_POW_VDDCORE: 1;
        uint16_t LOP_PON_FLASH_PC_VG2: 1;
        uint16_t LOP_PON_FLASH_PC_VG1: 1;
        uint16_t LOP_PON_LDO_EN_VAON_VANA_PC: 1;
        uint16_t LOP_PON_LDO_EN_LDO311_DMY_LITE: 1;
        uint16_t LOP_PON_LDO_POW_LDO311: 1;
        uint16_t LOP_PON_LDO_EN_LDO311_VDIV: 1;
        uint16_t LOP_PON_MBIAS_POR_VIO_EN: 1;
        uint16_t LOP_PON_MBIAS_POR_DVDDCORE_EN: 1;
        uint16_t LOP_PON_MBIAS_POW_BG_EBIAS_AUXADC: 1;
        uint16_t LOP_PON_MBIAS_BIAS50NA_EN: 1;
    };
} AON_FAST_REG_AON_REG_LOP_PON_RG0X_TYPE;

/* 0x182
    0       R/W LOP_PON_PMU_ST_PON_RET_DMY              1'b0
    2:1     R/W LOP_PON_PMU_ST_PON_RST_DMY[1:0]         2'b00
    4:3     R/W LOP_PON_PMU_ST_PON_CORE_DMY[1:0]        2'b00
    6:5     R/W LOP_PON_PMU_ST_PON_POS_DMY[1:0]         2'b00
    9:7     R/W LOP_PON_PMU_ST_PON_SWR_DMY[2:0]         3'b000
    12:10   R/W LOP_PON_PMU_ST_PON_SWR_BIAS_DMY[2:0]    3'b000
    14:13   R/W LOP_PON_PMU_ST_PON_BIAS_DMY[1:0]        2'b10
    15      R/W LOP_PON_BUCK_EN_FLASH_PD_DISCHG         1'b0
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_PON_RG1X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_PON_PMU_ST_PON_RET_DMY: 1;
        uint16_t LOP_PON_PMU_ST_PON_RST_DMY_1_0: 2;
        uint16_t LOP_PON_PMU_ST_PON_CORE_DMY_1_0: 2;
        uint16_t LOP_PON_PMU_ST_PON_POS_DMY_1_0: 2;
        uint16_t LOP_PON_PMU_ST_PON_SWR_DMY_2_0: 3;
        uint16_t LOP_PON_PMU_ST_PON_SWR_BIAS_DMY_2_0: 3;
        uint16_t LOP_PON_PMU_ST_PON_BIAS_DMY_1_0: 2;
        uint16_t LOP_PON_BUCK_EN_FLASH_PD_DISCHG: 1;
    };
} AON_FAST_REG_AON_REG_LOP_PON_RG1X_TYPE;

/* 0x184
    0       R/W LOP_PON_ISO_DIG_40M                     1'b0
    4:1     R/W LOP_PON_REG1X_BUCK_DUMMY[3:0]           4'b0000
    5       R/W LOP_PON_BUCK_SEL_LPPFM2                 1'b0
    6       R/W LOP_PON_BUCK_SEL_LPPFM1                 1'b0
    7       R/W LOP_PON_BUCK_POW_SWR                    1'b0
    8       R/W LOP_PON_BUCK_POW_PFM2_LQ                1'b0
    9       R/W LOP_PON_BUCK_POW_PFM1_LQ                1'b0
    10      R/W LOP_PON_BUCK_POW_PFM2_HQ                1'b0
    11      R/W LOP_PON_BUCK_POW_PFM1_HQ                1'b0
    12      R/W LOP_PON_BUCK_POW_VDIV2_LQ               1'b0
    13      R/W LOP_PON_BUCK_POW_VDIV1_LQ               1'b0
    14      R/W LOP_PON_BUCK_POW_VDIV2                  1'b0
    15      R/W LOP_PON_BUCK_POW_VDIV1                  1'b0
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_PON_RG2X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_PON_ISO_DIG_40M: 1;
        uint16_t LOP_PON_REG1X_BUCK_DUMMY_3_0: 4;
        uint16_t LOP_PON_BUCK_SEL_LPPFM2: 1;
        uint16_t LOP_PON_BUCK_SEL_LPPFM1: 1;
        uint16_t LOP_PON_BUCK_POW_SWR: 1;
        uint16_t LOP_PON_BUCK_POW_PFM2_LQ: 1;
        uint16_t LOP_PON_BUCK_POW_PFM1_LQ: 1;
        uint16_t LOP_PON_BUCK_POW_PFM2_HQ: 1;
        uint16_t LOP_PON_BUCK_POW_PFM1_HQ: 1;
        uint16_t LOP_PON_BUCK_POW_VDIV2_LQ: 1;
        uint16_t LOP_PON_BUCK_POW_VDIV1_LQ: 1;
        uint16_t LOP_PON_BUCK_POW_VDIV2: 1;
        uint16_t LOP_PON_BUCK_POW_VDIV1: 1;
    };
} AON_FAST_REG_AON_REG_LOP_PON_RG2X_TYPE;

/* 0x186
    4:0     R/W LOP_PON_LDO_VDDANA_TUNE_VDIV            5'b10100
    5       R/W AON_REG_LOP_PON_RG3X_DUMMY[5]           1'b0
    6       R/W LOP_PON_LDO_POW_BIAS_VDDANA             1'b1
    7       R/W LOP_PON_LDO_POW_BIAS_VDDCORE            1'b1
    12:8    R/W LOP_PON_LDO_VDDCORE_TUNE_VDIV           5'b01110
    15:13   R/W AON_REG_LOP_PON_RG3X_DUMMY[15:13]       3'b000
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_PON_RG3X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_PON_LDO_VDDANA_TUNE_VDIV: 5;
        uint16_t AON_REG_LOP_PON_RG3X_DUMMY_5: 1;
        uint16_t LOP_PON_LDO_POW_BIAS_VDDANA: 1;
        uint16_t LOP_PON_LDO_POW_BIAS_VDDCORE: 1;
        uint16_t LOP_PON_LDO_VDDCORE_TUNE_VDIV: 5;
        uint16_t AON_REG_LOP_PON_RG3X_DUMMY_15_13: 3;
    };
} AON_FAST_REG_AON_REG_LOP_PON_RG3X_TYPE;

/* 0x188
    0       R/W LOP_PON_BT_anapar_pow_xtal              1'b1
    3:1     R/W LOP_PON_XTAL_MODE                       3'b000
    4       R/W LOP_PON_POW_32KOSC                      1'b1
    5       R/W LOP_PON_POW_OSC40                       1'b1
    6       R/W AON_REG_LOP_PON_RG4X_DUMMY[6]           1'b0
    7       R/W LOP_PON_LDO_ENB_DMYL_200U_LDOANA        1'b1
    12:8    R/W LOP_PON_LDO_TUNE_LDOANA                 5'b10100
    13      R/W LOP_PON_MBIAS_POR_VIO_SIG_SEL           1'b0
    15:14   R/W AON_REG_LOP_PON_RG4X_DUMMY[15:14]       2'b00
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_PON_RG4X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_PON_BT_anapar_pow_xtal: 1;
        uint16_t LOP_PON_XTAL_MODE: 3;
        uint16_t LOP_PON_POW_32KOSC: 1;
        uint16_t LOP_PON_POW_OSC40: 1;
        uint16_t AON_REG_LOP_PON_RG4X_DUMMY_6: 1;
        uint16_t LOP_PON_LDO_ENB_DMYL_200U_LDOANA: 1;
        uint16_t LOP_PON_LDO_TUNE_LDOANA: 5;
        uint16_t LOP_PON_MBIAS_POR_VIO_SIG_SEL: 1;
        uint16_t AON_REG_LOP_PON_RG4X_DUMMY_15_14: 2;
    };
} AON_FAST_REG_AON_REG_LOP_PON_RG4X_TYPE;

/* 0x18a
    0       R/W AON_REG_LOP_PON_RG5X_DUMMY[0]           1'b0
    1       R/W LOP_PON_SWR_VDDCORE_VDIV_POS_EXT_RST_B  1'b1
    2       R/W LOP_PON_SWR_VDDANA_VDIV_POS_EXT_RST_B   1'b1
    3       R/W LOP_PON_SWR_VDDCORE_VREF_POS_EXT_RST_B  1'b1
    4       R/W LOP_PON_SWR_VDDANA_VREF_POS_EXT_RST_B   1'b1
    5       R/W LOP_PON_LDO_ANA_POS_EXT_RST_B           1'b1
    6       R/W LOP_PON_LDO_VDDCORE_POS_EXT_RST_B       1'b1
    7       R/W LOP_PON_LDO_VDDANA_POS_EXT_RST_B        1'b1
    8       R/W AON_REG_LOP_PON_RG5X_DUMMY[8]           1'b0
    9       R/W LOP_PON_SWR_VDDCORE_VDIV_POS_EN_POS     1'b0
    10      R/W LOP_PON_SWR_VDDANA_VDIV_POS_EN_POS      1'b0
    11      R/W LOP_PON_SWR_VDDCORE_VREF_POS_EN_POS     1'b0
    12      R/W LOP_PON_SWR_VDDANA_VREF_POS_EN_POS      1'b0
    13      R/W LOP_PON_LDO_ANA_POS_EN_POS              1'b1
    14      R/W LOP_PON_LDO_VDDCORE_POS_EN_POS          1'b1
    15      R/W LOP_PON_LDO_VDDANA_POS_EN_POS           1'b1
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_PON_RG5X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t AON_REG_LOP_PON_RG5X_DUMMY_0: 1;
        uint16_t LOP_PON_SWR_VDDCORE_VDIV_POS_EXT_RST_B: 1;
        uint16_t LOP_PON_SWR_VDDANA_VDIV_POS_EXT_RST_B: 1;
        uint16_t LOP_PON_SWR_VDDCORE_VREF_POS_EXT_RST_B: 1;
        uint16_t LOP_PON_SWR_VDDANA_VREF_POS_EXT_RST_B: 1;
        uint16_t LOP_PON_LDO_ANA_POS_EXT_RST_B: 1;
        uint16_t LOP_PON_LDO_VDDCORE_POS_EXT_RST_B: 1;
        uint16_t LOP_PON_LDO_VDDANA_POS_EXT_RST_B: 1;
        uint16_t AON_REG_LOP_PON_RG5X_DUMMY_8: 1;
        uint16_t LOP_PON_SWR_VDDCORE_VDIV_POS_EN_POS: 1;
        uint16_t LOP_PON_SWR_VDDANA_VDIV_POS_EN_POS: 1;
        uint16_t LOP_PON_SWR_VDDCORE_VREF_POS_EN_POS: 1;
        uint16_t LOP_PON_SWR_VDDANA_VREF_POS_EN_POS: 1;
        uint16_t LOP_PON_LDO_ANA_POS_EN_POS: 1;
        uint16_t LOP_PON_LDO_VDDCORE_POS_EN_POS: 1;
        uint16_t LOP_PON_LDO_VDDANA_POS_EN_POS: 1;
    };
} AON_FAST_REG_AON_REG_LOP_PON_RG5X_TYPE;

/* 0x190
    0       R/W LOP_POF_LDO_POW_LDORET                  1'b0
    1       R/W LOP_POF_LDO_POW_BIAS_LDOANA             1'b1
    2       R/W LOP_POF_LDO_ENPC_LDOANA                 1'b0
    3       R/W LOP_POF_LDO_POW_LDOANA                  1'b1
    4       R/W LOP_POF_LDO_POW_VDDANA                  1'b0
    5       R/W LOP_POF_LDO_POW_VDDCORE                 1'b0
    6       R/W LOP_POF_FLASH_PC_VG2                    1'b0
    7       R/W LOP_POF_FLASH_PC_VG1                    1'b0
    8       R/W LOP_POF_LDO_EN_VAON_VANA_PC             1'b0
    9       R/W LOP_POF_LDO_EN_LDO311_DMY_LITE          1'b1
    10      R/W LOP_POF_LDO_POW_LDO311                  1'b1
    11      R/W LOP_POF_LDO_EN_LDO311_VDIV              1'b1
    12      R/W LOP_POF_MBIAS_POR_VIO_EN                1'b1
    13      R/W LOP_POF_MBIAS_POR_DVDDCORE_EN           1'b1
    14      R/W LOP_POF_MBIAS_POW_BG_EBIAS_AUXADC       1'b1
    15      R/W LOP_POF_MBIAS_BIAS50NA_EN               1'b1
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_POF_RG0X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_POF_LDO_POW_LDORET: 1;
        uint16_t LOP_POF_LDO_POW_BIAS_LDOANA: 1;
        uint16_t LOP_POF_LDO_ENPC_LDOANA: 1;
        uint16_t LOP_POF_LDO_POW_LDOANA: 1;
        uint16_t LOP_POF_LDO_POW_VDDANA: 1;
        uint16_t LOP_POF_LDO_POW_VDDCORE: 1;
        uint16_t LOP_POF_FLASH_PC_VG2: 1;
        uint16_t LOP_POF_FLASH_PC_VG1: 1;
        uint16_t LOP_POF_LDO_EN_VAON_VANA_PC: 1;
        uint16_t LOP_POF_LDO_EN_LDO311_DMY_LITE: 1;
        uint16_t LOP_POF_LDO_POW_LDO311: 1;
        uint16_t LOP_POF_LDO_EN_LDO311_VDIV: 1;
        uint16_t LOP_POF_MBIAS_POR_VIO_EN: 1;
        uint16_t LOP_POF_MBIAS_POR_DVDDCORE_EN: 1;
        uint16_t LOP_POF_MBIAS_POW_BG_EBIAS_AUXADC: 1;
        uint16_t LOP_POF_MBIAS_BIAS50NA_EN: 1;
    };
} AON_FAST_REG_AON_REG_LOP_POF_RG0X_TYPE;

/* 0x192
    0       R/W LOP_POF_PMU_ST_PON_RET_DMY              1'b0
    2:1     R/W LOP_POF_PMU_ST_PON_RST_DMY[1:0]         2'b00
    4:3     R/W LOP_POF_PMU_ST_PON_CORE_DMY[1:0]        2'b00
    6:5     R/W LOP_POF_PMU_ST_PON_POS_DMY[1:0]         2'b00
    9:7     R/W LOP_POF_PMU_ST_PON_SWR_DMY[2:0]         3'b000
    12:10   R/W LOP_POF_PMU_ST_PON_SWR_BIAS_DMY[2:0]    3'b000
    14:13   R/W LOP_POF_PMU_ST_PON_BIAS_DMY[1:0]        2'b10
    15      R/W LOP_POF_BUCK_EN_FLASH_PD_DISCHG         1'b0
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_POF_RG1X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_POF_PMU_ST_PON_RET_DMY: 1;
        uint16_t LOP_POF_PMU_ST_PON_RST_DMY_1_0: 2;
        uint16_t LOP_POF_PMU_ST_PON_CORE_DMY_1_0: 2;
        uint16_t LOP_POF_PMU_ST_PON_POS_DMY_1_0: 2;
        uint16_t LOP_POF_PMU_ST_PON_SWR_DMY_2_0: 3;
        uint16_t LOP_POF_PMU_ST_PON_SWR_BIAS_DMY_2_0: 3;
        uint16_t LOP_POF_PMU_ST_PON_BIAS_DMY_1_0: 2;
        uint16_t LOP_POF_BUCK_EN_FLASH_PD_DISCHG: 1;
    };
} AON_FAST_REG_AON_REG_LOP_POF_RG1X_TYPE;

/* 0x194
    0       R/W LOP_POF_ISO_DIG_40M                     1'b1
    4:1     R/W LOP_POF_REG1X_BUCK_DUMMY[3:0]           4'b0000
    5       R/W LOP_POF_BUCK_SEL_LPPFM2                 1'b0
    6       R/W LOP_POF_BUCK_SEL_LPPFM1                 1'b0
    7       R/W LOP_POF_BUCK_POW_SWR                    1'b0
    8       R/W LOP_POF_BUCK_POW_PFM2_LQ                1'b0
    9       R/W LOP_POF_BUCK_POW_PFM1_LQ                1'b0
    10      R/W LOP_POF_BUCK_POW_PFM2_HQ                1'b0
    11      R/W LOP_POF_BUCK_POW_PFM1_HQ                1'b0
    12      R/W LOP_POF_BUCK_POW_VDIV2_LQ               1'b0
    13      R/W LOP_POF_BUCK_POW_VDIV1_LQ               1'b0
    14      R/W LOP_POF_BUCK_POW_VDIV2                  1'b0
    15      R/W LOP_POF_BUCK_POW_VDIV1                  1'b0
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_POF_RG2X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_POF_ISO_DIG_40M: 1;
        uint16_t LOP_POF_REG1X_BUCK_DUMMY_3_0: 4;
        uint16_t LOP_POF_BUCK_SEL_LPPFM2: 1;
        uint16_t LOP_POF_BUCK_SEL_LPPFM1: 1;
        uint16_t LOP_POF_BUCK_POW_SWR: 1;
        uint16_t LOP_POF_BUCK_POW_PFM2_LQ: 1;
        uint16_t LOP_POF_BUCK_POW_PFM1_LQ: 1;
        uint16_t LOP_POF_BUCK_POW_PFM2_HQ: 1;
        uint16_t LOP_POF_BUCK_POW_PFM1_HQ: 1;
        uint16_t LOP_POF_BUCK_POW_VDIV2_LQ: 1;
        uint16_t LOP_POF_BUCK_POW_VDIV1_LQ: 1;
        uint16_t LOP_POF_BUCK_POW_VDIV2: 1;
        uint16_t LOP_POF_BUCK_POW_VDIV1: 1;
    };
} AON_FAST_REG_AON_REG_LOP_POF_RG2X_TYPE;

/* 0x196
    4:0     R/W LOP_POF_LDO_VDDANA_TUNE_VDIV            5'b10100
    5       R/W AON_REG_LOP_POF_RG3X_DUMMY[5]           1'b0
    6       R/W LOP_POF_LDO_POW_BIAS_VDDANA             1'b1
    7       R/W LOP_POF_LDO_POW_BIAS_VDDCORE            1'b1
    12:8    R/W LOP_POF_LDO_VDDCORE_TUNE_VDIV           5'b10000
    13      R/W AON_REG_LOP_POF_RG3X_DUMMY[13]          1'b0
    14      R/W LOP_POF_SEL_IPTAT                       1'b1
    15      R/W LOP_POF_SEL_LV                          1'b1
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_POF_RG3X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_POF_LDO_VDDANA_TUNE_VDIV: 5;
        uint16_t AON_REG_LOP_POF_RG3X_DUMMY_5: 1;
        uint16_t LOP_POF_LDO_POW_BIAS_VDDANA: 1;
        uint16_t LOP_POF_LDO_POW_BIAS_VDDCORE: 1;
        uint16_t LOP_POF_LDO_VDDCORE_TUNE_VDIV: 5;
        uint16_t AON_REG_LOP_POF_RG3X_DUMMY_13: 1;
        uint16_t LOP_POF_SEL_IPTAT: 1;
        uint16_t LOP_POF_SEL_LV: 1;
    };
} AON_FAST_REG_AON_REG_LOP_POF_RG3X_TYPE;

/* 0x198
    0       R/W LOP_POF_BT_anapar_pow_xtal              1'b1
    3:1     R/W LOP_POF_XTAL_MODE                       3'b000
    4       R/W LOP_POF_POW_32KOSC                      1'b1
    5       R/W LOP_POF_POW_OSC40                       1'b0
    6       R/W LOP_POF_AON_GATED_EN                    1'b1
    7       R/W LOP_POF_CAL                             1'b0
    12:8    R/W LOP_POF_LDO_TUNE_LDOANA                 5'b10100
    13      R/W LOP_POF_MBIAS_POR_VIO_SIG_SEL           1'b0
    14      R/W LOP_POF_VCORE_PC_VG2                    1'b1
    15      R/W LOP_POF_VCORE_PC_VG1                    1'b1
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_POF_RG4X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_POF_BT_anapar_pow_xtal: 1;
        uint16_t LOP_POF_XTAL_MODE: 3;
        uint16_t LOP_POF_POW_32KOSC: 1;
        uint16_t LOP_POF_POW_OSC40: 1;
        uint16_t LOP_POF_AON_GATED_EN: 1;
        uint16_t LOP_POF_CAL: 1;
        uint16_t LOP_POF_LDO_TUNE_LDOANA: 5;
        uint16_t LOP_POF_MBIAS_POR_VIO_SIG_SEL: 1;
        uint16_t LOP_POF_VCORE_PC_VG2: 1;
        uint16_t LOP_POF_VCORE_PC_VG1: 1;
    };
} AON_FAST_REG_AON_REG_LOP_POF_RG4X_TYPE;

/* 0x19a
    0       R/W AON_REG_LOP_POF_RG5X_DUMMY[0]           1'b0
    1       R/W LOP_POF_SWR_VDDCORE_VDIV_POS_EXT_RST_B  1'b1
    2       R/W LOP_POF_SWR_VDDANA_VDIV_POS_EXT_RST_B   1'b1
    3       R/W LOP_POF_SWR_VDDCORE_VREF_POS_EXT_RST_B  1'b1
    4       R/W LOP_POF_SWR_VDDANA_VREF_POS_EXT_RST_B   1'b1
    5       R/W LOP_POF_LDO_ANA_POS_EXT_RST_B           1'b1
    6       R/W LOP_POF_LDO_VDDCORE_POS_EXT_RST_B       1'b1
    7       R/W LOP_POF_LDO_VDDANA_POS_EXT_RST_B        1'b1
    8       R/W AON_REG_LOP_POF_RG5X_DUMMY[8]           1'b0
    9       R/W LOP_POF_SWR_VDDCORE_VDIV_POS_EN_POS     1'b0
    10      R/W LOP_POF_SWR_VDDANA_VDIV_POS_EN_POS      1'b0
    11      R/W LOP_POF_SWR_VDDCORE_VREF_POS_EN_POS     1'b0
    12      R/W LOP_POF_SWR_VDDANA_VREF_POS_EN_POS      1'b0
    13      R/W LOP_POF_LDO_ANA_POS_EN_POS              1'b0
    14      R/W LOP_POF_LDO_VDDCORE_POS_EN_POS          1'b0
    15      R/W LOP_POF_LDO_VDDANA_POS_EN_POS           1'b0
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_POF_RG5X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t AON_REG_LOP_POF_RG5X_DUMMY_0: 1;
        uint16_t LOP_POF_SWR_VDDCORE_VDIV_POS_EXT_RST_B: 1;
        uint16_t LOP_POF_SWR_VDDANA_VDIV_POS_EXT_RST_B: 1;
        uint16_t LOP_POF_SWR_VDDCORE_VREF_POS_EXT_RST_B: 1;
        uint16_t LOP_POF_SWR_VDDANA_VREF_POS_EXT_RST_B: 1;
        uint16_t LOP_POF_LDO_ANA_POS_EXT_RST_B: 1;
        uint16_t LOP_POF_LDO_VDDCORE_POS_EXT_RST_B: 1;
        uint16_t LOP_POF_LDO_VDDANA_POS_EXT_RST_B: 1;
        uint16_t AON_REG_LOP_POF_RG5X_DUMMY_8: 1;
        uint16_t LOP_POF_SWR_VDDCORE_VDIV_POS_EN_POS: 1;
        uint16_t LOP_POF_SWR_VDDANA_VDIV_POS_EN_POS: 1;
        uint16_t LOP_POF_SWR_VDDCORE_VREF_POS_EN_POS: 1;
        uint16_t LOP_POF_SWR_VDDANA_VREF_POS_EN_POS: 1;
        uint16_t LOP_POF_LDO_ANA_POS_EN_POS: 1;
        uint16_t LOP_POF_LDO_VDDCORE_POS_EN_POS: 1;
        uint16_t LOP_POF_LDO_VDDANA_POS_EN_POS: 1;
    };
} AON_FAST_REG_AON_REG_LOP_POF_RG5X_TYPE;

/* 0x1a0
    7:0     R/W LOP_SWR_BIAS_delay                      8'h10
    15:8    R/W LOP_BIAS_delay                          8'h10
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_RG0X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_SWR_BIAS_delay: 8;
        uint16_t LOP_BIAS_delay: 8;
    };
} AON_FAST_REG_AON_REG_LOP_RG0X_TYPE;

/* 0x1a2
    7:0     R/W LOP_POS_delay                           8'h40
    15:8    R/W LOP_SWR_delay                           8'h10
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_RG1X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_POS_delay: 8;
        uint16_t LOP_SWR_delay: 8;
    };
} AON_FAST_REG_AON_REG_LOP_RG1X_TYPE;

/* 0x1a4
    0       R/W LOP_ZB_RET                              1'b0
    1       R/W LOP_RFC_RET                             1'b0
    2       R/W LOP_MODEM_RET                           1'b0
    3       R/W LOP_BZ_RET                              1'b0
    4       R/W LOP_BLE_RET                             1'b0
    5       R/W LOP_PF_RET                              1'b0
    6       R/W LOP_DP_MODEM_RET                        1'b0
    7       R   reserved                                1'b0
    15:8    R/W LOP_POF_RET_DELAY                       8'h00
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_RG2X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_ZB_RET: 1;
        uint16_t LOP_RFC_RET: 1;
        uint16_t LOP_MODEM_RET: 1;
        uint16_t LOP_BZ_RET: 1;
        uint16_t LOP_BLE_RET: 1;
        uint16_t LOP_PF_RET: 1;
        uint16_t LOP_DP_MODEM_RET: 1;
        uint16_t reserved: 1;
        uint16_t LOP_POF_RET_DELAY: 8;
    };
} AON_FAST_REG_AON_REG_LOP_RG2X_TYPE;

/* 0x1a6
    7:0     R/W LOP_CORE_delay                          8'h10
    15:8    R/W LOP_XTAL_DELAY                          8'h40
 */
typedef volatile union _AON_FAST_REG_AON_REG_LOP_RG3X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LOP_CORE_delay: 8;
        uint16_t LOP_XTAL_DELAY: 8;
    };
} AON_FAST_REG_AON_REG_LOP_RG3X_TYPE;

/* 0x1c0
    15:0    R   corewdt_cpu_pc_LSB[15:0]                16'b0
 */
typedef volatile union _AON_FAST_REG_FAON_READ_RG0X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t corewdt_cpu_pc_LSB_15_0;
    };
} AON_FAST_REG_FAON_READ_RG0X_TYPE;

/* 0x1c2
    14:0    R   corewdt_cpu_pc_MSB[14:0]                15'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_FAON_READ_RG1X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t corewdt_cpu_pc_MSB_14_0: 15;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_FAON_READ_RG1X_TYPE;

/* 0x1c4
    15:0    R   corewdt_cpu_lr_LSB[15:0]                16'b0
 */
typedef volatile union _AON_FAST_REG_FAON_READ_RG2X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t corewdt_cpu_lr_LSB_15_0;
    };
} AON_FAST_REG_FAON_READ_RG2X_TYPE;

/* 0x1c6
    15:0    R   corewdt_cpu_lr_MSB[15:0]                16'b0
 */
typedef volatile union _AON_FAST_REG_FAON_READ_RG3X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t corewdt_cpu_lr_MSB_15_0;
    };
} AON_FAST_REG_FAON_READ_RG3X_TYPE;

/* 0x1c8
    15:0    R   corewdt_cpu_psr_LSB[15:0]               16'b0
 */
typedef volatile union _AON_FAST_REG_FAON_READ_RG4X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t corewdt_cpu_psr_LSB_15_0;
    };
} AON_FAST_REG_FAON_READ_RG4X_TYPE;

/* 0x1ca
    15:0    R   corewdt_cpu_psr_MSB[15:0]               16'b0
 */
typedef volatile union _AON_FAST_REG_FAON_READ_RG5X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t corewdt_cpu_psr_MSB_15_0;
    };
} AON_FAST_REG_FAON_READ_RG5X_TYPE;

/* 0x1cc
    15:0    R   aonwdt_cpu_pc_LSB[15:0]                 16'b0
 */
typedef volatile union _AON_FAST_REG_FAON_READ_RG6X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t aonwdt_cpu_pc_LSB_15_0;
    };
} AON_FAST_REG_FAON_READ_RG6X_TYPE;

/* 0x1ce
    14:0    R   aonwdt_cpu_pc_MSB[14:0]                 15'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_FAON_READ_RG7X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t aonwdt_cpu_pc_MSB_14_0: 15;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_FAON_READ_RG7X_TYPE;

/* 0x1d0
    15:0    R   aonwdt_cpu_lr_LSB[15:0]                 16'b0
 */
typedef volatile union _AON_FAST_REG_FAON_READ_RG8X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t aonwdt_cpu_lr_LSB_15_0;
    };
} AON_FAST_REG_FAON_READ_RG8X_TYPE;

/* 0x1d2
    15:0    R   aonwdt_cpu_lr_MSB[15:0]                 16'b0
 */
typedef volatile union _AON_FAST_REG_FAON_READ_RG9X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t aonwdt_cpu_lr_MSB_15_0;
    };
} AON_FAST_REG_FAON_READ_RG9X_TYPE;

/* 0x1d4
    15:0    R   aonwdt_cpu_psr_LSB[15:0]                16'b0
 */
typedef volatile union _AON_FAST_REG_FAON_READ_RG10X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t aonwdt_cpu_psr_LSB_15_0;
    };
} AON_FAST_REG_FAON_READ_RG10X_TYPE;

/* 0x1d6
    15:0    R   aonwdt_cpu_psr_MSB[15:0]                16'b0
 */
typedef volatile union _AON_FAST_REG_FAON_READ_RG11X_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t aonwdt_cpu_psr_MSB_15_0;
    };
} AON_FAST_REG_FAON_READ_RG11X_TYPE;

/* 0x1e0
    0       R/W LDO_VDDANA_POS_INT_RST_B                1'b0
    1       R   LDO_VDDANA_POS_EXT_RST_B                1'b1
    2       R/W LDO_VDDANA_POS_SEL_EXT_RST_B            1'b1
    3       R   LDO_VDDANA_POS_EN_POS                   1'b0
    6:4     R/W LDO_VDDANA_POS_DIV_CLK                  3'b000
    7       R/W LDO_VDDANA_POS_EN_DR_FIX                1'b0
    8       R   reserved                                1'b0
    9       R   reserved                                1'b0
    10      R   reserved                                1'b0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_LDO_VDDANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_VDDANA_POS_INT_RST_B: 1;
        uint16_t LDO_VDDANA_POS_EXT_RST_B: 1;
        uint16_t LDO_VDDANA_POS_SEL_EXT_RST_B: 1;
        uint16_t LDO_VDDANA_POS_EN_POS: 1;
        uint16_t LDO_VDDANA_POS_DIV_CLK: 3;
        uint16_t LDO_VDDANA_POS_EN_DR_FIX: 1;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG0X_LDO_VDDANA_POS_TYPE;

/* 0x1e2
    2:0     R/W LDO_VDDANA_POS_POF_STEP                 3'b001
    3       R   reserved                                1'b0
    6:4     R/W LDO_VDDANA_POS_PON_STEP                 3'b001
    7       R   reserved                                1'b0
    10:8    R/W LDO_VDDANA_POS_POF_WAIT                 3'b000
    13:11   R/W LDO_VDDANA_POS_PON_WAIT                 3'b001
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG1X_LDO_VDDANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_VDDANA_POS_POF_STEP: 3;
        uint16_t reserved_3: 1;
        uint16_t LDO_VDDANA_POS_PON_STEP: 3;
        uint16_t reserved_2: 1;
        uint16_t LDO_VDDANA_POS_POF_WAIT: 3;
        uint16_t LDO_VDDANA_POS_PON_WAIT: 3;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG1X_LDO_VDDANA_POS_TYPE;

/* 0x1e4
    2:0     R/W LDO_VDDANA_POS_PON_OVER                 3'b111
    7:3     R   reserved                                5'b00000
    10:8    R/W LDO_VDDANA_POS_PON_START                3'b000
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG2X_LDO_VDDANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_VDDANA_POS_PON_OVER: 3;
        uint16_t reserved_1: 5;
        uint16_t LDO_VDDANA_POS_PON_START: 3;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG2X_LDO_VDDANA_POS_TYPE;

/* 0x1e6
    2:0     R/W LDO_VDDANA_POS_POF_OVER                 3'b000
    7:3     R   reserved                                5'b00000
    10:8    R/W LDO_VDDANA_POS_POF_START                3'b111
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG3X_LDO_VDDANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_VDDANA_POS_POF_OVER: 3;
        uint16_t reserved_1: 5;
        uint16_t LDO_VDDANA_POS_POF_START: 3;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG3X_LDO_VDDANA_POS_TYPE;

/* 0x1e8
    7:0     R   reserved                                8'b00000001
    15:8    R   reserved                                8'b00000000
 */
typedef volatile union _AON_FAST_REG_REG4X_LDO_VDDANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG4X_LDO_VDDANA_POS_TYPE;

/* 0x1ea
    7:0     R   reserved                                8'b00000111
    15:8    R   reserved                                8'b00000110
 */
typedef volatile union _AON_FAST_REG_REG5X_LDO_VDDANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG5X_LDO_VDDANA_POS_TYPE;

/* 0x1ec
    7:0     R   reserved                                8'b00000110
    15:8    R   reserved                                8'b00000111
 */
typedef volatile union _AON_FAST_REG_REG6X_LDO_VDDANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG6X_LDO_VDDANA_POS_TYPE;

/* 0x1ee
    7:0     R   reserved                                8'b00000000
    15:8    R   reserved                                8'b00000001
 */
typedef volatile union _AON_FAST_REG_REG7X_LDO_VDDANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG7X_LDO_VDDANA_POS_TYPE;

/* 0x1f0
    0       R   LDO_VDDANA_POS_POF_FLAG4                1'b0
    1       R   LDO_VDDANA_POS_POF_FLAG3                1'b0
    2       R   LDO_VDDANA_POS_POF_FLAG2                1'b0
    3       R   LDO_VDDANA_POS_POF_FLAG1                1'b0
    4       R   LDO_VDDANA_POS_PON_FLAG4                1'b0
    5       R   LDO_VDDANA_POS_PON_FLAG3                1'b0
    6       R   LDO_VDDANA_POS_PON_FLAG2                1'b0
    7       R   LDO_VDDANA_POS_PON_FLAG1                1'b0
    10:8    R   LDO_VDDANA_POS_FSM_CS                   3'h0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_C_KOUT0X_LDO_VDDANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_VDDANA_POS_POF_FLAG4: 1;
        uint16_t LDO_VDDANA_POS_POF_FLAG3: 1;
        uint16_t LDO_VDDANA_POS_POF_FLAG2: 1;
        uint16_t LDO_VDDANA_POS_POF_FLAG1: 1;
        uint16_t LDO_VDDANA_POS_PON_FLAG4: 1;
        uint16_t LDO_VDDANA_POS_PON_FLAG3: 1;
        uint16_t LDO_VDDANA_POS_PON_FLAG2: 1;
        uint16_t LDO_VDDANA_POS_PON_FLAG1: 1;
        uint16_t LDO_VDDANA_POS_FSM_CS: 3;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT0X_LDO_VDDANA_POS_TYPE;

/* 0x1f2
    7:0     R   LDO_VDDANA_POS_DR                       8'h0
    8       R   reserved                                1'h0
    9       R   reserved                                1'h0
    10      R   reserved                                1'h0
    11      R   reserved                                1'h0
    12      R   reserved                                1'h0
    13      R   reserved                                1'h0
    14      R   reserved                                1'h0
    15      R   reserved                                1'h0
 */
typedef volatile union _AON_FAST_REG_C_KOUT1X_LDO_VDDANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_VDDANA_POS_DR: 8;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT1X_LDO_VDDANA_POS_TYPE;

/* 0x1f4
    0       R/W LDO_VDDCORE_POS_INT_RST_B               1'b0
    1       R   LDO_VDDCORE_POS_EXT_RST_B               1'b1
    2       R/W LDO_VDDCORE_POS_SEL_EXT_RST_B           1'b1
    3       R   LDO_VDDCORE_POS_EN_POS                  1'b0
    6:4     R/W LDO_VDDCORE_POS_DIV_CLK                 3'b000
    7       R/W LDO_VDDCORE_POS_EN_DR_FIX               1'b0
    8       R   reserved                                1'b0
    9       R   reserved                                1'b0
    10      R   reserved                                1'b0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_LDO_VDDCORE_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_VDDCORE_POS_INT_RST_B: 1;
        uint16_t LDO_VDDCORE_POS_EXT_RST_B: 1;
        uint16_t LDO_VDDCORE_POS_SEL_EXT_RST_B: 1;
        uint16_t LDO_VDDCORE_POS_EN_POS: 1;
        uint16_t LDO_VDDCORE_POS_DIV_CLK: 3;
        uint16_t LDO_VDDCORE_POS_EN_DR_FIX: 1;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG0X_LDO_VDDCORE_POS_TYPE;

/* 0x1f6
    2:0     R/W LDO_VDDCORE_POS_POF_STEP                3'b001
    3       R   reserved                                1'b0
    6:4     R/W LDO_VDDCORE_POS_PON_STEP                3'b001
    7       R   reserved                                1'b0
    10:8    R/W LDO_VDDCORE_POS_POF_WAIT                3'b000
    13:11   R/W LDO_VDDCORE_POS_PON_WAIT                3'b001
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG1X_LDO_VDDCORE_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_VDDCORE_POS_POF_STEP: 3;
        uint16_t reserved_3: 1;
        uint16_t LDO_VDDCORE_POS_PON_STEP: 3;
        uint16_t reserved_2: 1;
        uint16_t LDO_VDDCORE_POS_POF_WAIT: 3;
        uint16_t LDO_VDDCORE_POS_PON_WAIT: 3;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG1X_LDO_VDDCORE_POS_TYPE;

/* 0x1f8
    2:0     R/W LDO_VDDCORE_POS_PON_OVER                3'b111
    7:3     R   reserved                                5'b00000
    10:8    R/W LDO_VDDCORE_POS_PON_START               3'b000
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG2X_LDO_VDDCORE_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_VDDCORE_POS_PON_OVER: 3;
        uint16_t reserved_1: 5;
        uint16_t LDO_VDDCORE_POS_PON_START: 3;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG2X_LDO_VDDCORE_POS_TYPE;

/* 0x1fa
    2:0     R/W LDO_VDDCORE_POS_POF_OVER                3'b000
    7:3     R   reserved                                5'b00000
    10:8    R/W LDO_VDDCORE_POS_POF_START               3'b111
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG3X_LDO_VDDCORE_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_VDDCORE_POS_POF_OVER: 3;
        uint16_t reserved_1: 5;
        uint16_t LDO_VDDCORE_POS_POF_START: 3;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG3X_LDO_VDDCORE_POS_TYPE;

/* 0x1fc
    7:0     R   reserved                                8'b00000001
    15:8    R   reserved                                8'b00000000
 */
typedef volatile union _AON_FAST_REG_REG4X_LDO_VDDCORE_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG4X_LDO_VDDCORE_POS_TYPE;

/* 0x1fe
    7:0     R   reserved                                8'b00000111
    15:8    R   reserved                                8'b00000110
 */
typedef volatile union _AON_FAST_REG_REG5X_LDO_VDDCORE_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG5X_LDO_VDDCORE_POS_TYPE;

/* 0x200
    7:0     R   reserved                                8'b00000110
    15:8    R   reserved                                8'b00000111
 */
typedef volatile union _AON_FAST_REG_REG6X_LDO_VDDCORE_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG6X_LDO_VDDCORE_POS_TYPE;

/* 0x202
    7:0     R   reserved                                8'b00000000
    15:8    R   reserved                                8'b00000001
 */
typedef volatile union _AON_FAST_REG_REG7X_LDO_VDDCORE_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG7X_LDO_VDDCORE_POS_TYPE;

/* 0x204
    0       R   LDO_VDDCORE_POS_POF_FLAG4               1'b0
    1       R   LDO_VDDCORE_POS_POF_FLAG3               1'b0
    2       R   LDO_VDDCORE_POS_POF_FLAG2               1'b0
    3       R   LDO_VDDCORE_POS_POF_FLAG1               1'b0
    4       R   LDO_VDDCORE_POS_PON_FLAG4               1'b0
    5       R   LDO_VDDCORE_POS_PON_FLAG3               1'b0
    6       R   LDO_VDDCORE_POS_PON_FLAG2               1'b0
    7       R   LDO_VDDCORE_POS_PON_FLAG1               1'b0
    10:8    R   LDO_VDDCORE_POS_FSM_CS                  3'h0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_C_KOUT0X_LDO_VDDCORE_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_VDDCORE_POS_POF_FLAG4: 1;
        uint16_t LDO_VDDCORE_POS_POF_FLAG3: 1;
        uint16_t LDO_VDDCORE_POS_POF_FLAG2: 1;
        uint16_t LDO_VDDCORE_POS_POF_FLAG1: 1;
        uint16_t LDO_VDDCORE_POS_PON_FLAG4: 1;
        uint16_t LDO_VDDCORE_POS_PON_FLAG3: 1;
        uint16_t LDO_VDDCORE_POS_PON_FLAG2: 1;
        uint16_t LDO_VDDCORE_POS_PON_FLAG1: 1;
        uint16_t LDO_VDDCORE_POS_FSM_CS: 3;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT0X_LDO_VDDCORE_POS_TYPE;

/* 0x206
    7:0     R   LDO_VDDCORE_POS_DR                      8'h0
    8       R   reserved                                1'h0
    9       R   reserved                                1'h0
    10      R   reserved                                1'h0
    11      R   reserved                                1'h0
    12      R   reserved                                1'h0
    13      R   reserved                                1'h0
    14      R   reserved                                1'h0
    15      R   reserved                                1'h0
 */
typedef volatile union _AON_FAST_REG_C_KOUT1X_LDO_VDDCORE_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_VDDCORE_POS_DR: 8;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT1X_LDO_VDDCORE_POS_TYPE;

/* 0x208
    0       R/W LDO_ANA_POS_INT_RST_B                   1'b0
    1       R   LDO_ANA_POS_EXT_RST_B                   1'b1
    2       R/W LDO_ANA_POS_SEL_EXT_RST_B               1'b1
    3       R   LDO_ANA_POS_EN_POS                      1'b0
    6:4     R/W LDO_ANA_POS_DIV_CLK                     3'b001
    7       R/W LDO_ANA_POS_EN_DR_FIX                   1'b0
    8       R   reserved                                1'b0
    9       R   reserved                                1'b0
    10      R   reserved                                1'b0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_LDO_ANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_ANA_POS_INT_RST_B: 1;
        uint16_t LDO_ANA_POS_EXT_RST_B: 1;
        uint16_t LDO_ANA_POS_SEL_EXT_RST_B: 1;
        uint16_t LDO_ANA_POS_EN_POS: 1;
        uint16_t LDO_ANA_POS_DIV_CLK: 3;
        uint16_t LDO_ANA_POS_EN_DR_FIX: 1;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG0X_LDO_ANA_POS_TYPE;

/* 0x20a
    2:0     R/W LDO_ANA_POS_POF_STEP                    3'b001
    3       R   reserved                                1'b0
    6:4     R/W LDO_ANA_POS_PON_STEP                    3'b001
    7       R   reserved                                1'b0
    10:8    R/W LDO_ANA_POS_POF_WAIT                    3'b000
    13:11   R/W LDO_ANA_POS_PON_WAIT                    3'b000
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG1X_LDO_ANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_ANA_POS_POF_STEP: 3;
        uint16_t reserved_3: 1;
        uint16_t LDO_ANA_POS_PON_STEP: 3;
        uint16_t reserved_2: 1;
        uint16_t LDO_ANA_POS_POF_WAIT: 3;
        uint16_t LDO_ANA_POS_PON_WAIT: 3;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG1X_LDO_ANA_POS_TYPE;

/* 0x20c
    2:0     R/W LDO_ANA_POS_PON_OVER                    3'b111
    7:3     R   reserved                                5'b00000
    10:8    R/W LDO_ANA_POS_PON_START                   3'b000
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG2X_LDO_ANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_ANA_POS_PON_OVER: 3;
        uint16_t reserved_1: 5;
        uint16_t LDO_ANA_POS_PON_START: 3;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG2X_LDO_ANA_POS_TYPE;

/* 0x20e
    2:0     R/W LDO_ANA_POS_POF_OVER                    3'b000
    7:3     R   reserved                                5'b00000
    10:8    R/W LDO_ANA_POS_POF_START                   3'b111
    15:11   R   reserved                                5'b00000
 */
typedef volatile union _AON_FAST_REG_REG3X_LDO_ANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_ANA_POS_POF_OVER: 3;
        uint16_t reserved_1: 5;
        uint16_t LDO_ANA_POS_POF_START: 3;
        uint16_t reserved: 5;
    };
} AON_FAST_REG_REG3X_LDO_ANA_POS_TYPE;

/* 0x210
    7:0     R   reserved                                8'b00000001
    15:8    R   reserved                                8'b00000000
 */
typedef volatile union _AON_FAST_REG_REG4X_LDO_ANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG4X_LDO_ANA_POS_TYPE;

/* 0x212
    7:0     R   reserved                                8'b00000111
    15:8    R   reserved                                8'b00000110
 */
typedef volatile union _AON_FAST_REG_REG5X_LDO_ANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG5X_LDO_ANA_POS_TYPE;

/* 0x214
    7:0     R   reserved                                8'b00000110
    15:8    R   reserved                                8'b00000111
 */
typedef volatile union _AON_FAST_REG_REG6X_LDO_ANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG6X_LDO_ANA_POS_TYPE;

/* 0x216
    7:0     R   reserved                                8'b00000000
    15:8    R   reserved                                8'b00000001
 */
typedef volatile union _AON_FAST_REG_REG7X_LDO_ANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG7X_LDO_ANA_POS_TYPE;

/* 0x218
    0       R   LDO_ANA_POS_POF_FLAG4                   1'b0
    1       R   LDO_ANA_POS_POF_FLAG3                   1'b0
    2       R   LDO_ANA_POS_POF_FLAG2                   1'b0
    3       R   LDO_ANA_POS_POF_FLAG1                   1'b0
    4       R   LDO_ANA_POS_PON_FLAG4                   1'b0
    5       R   LDO_ANA_POS_PON_FLAG3                   1'b0
    6       R   LDO_ANA_POS_PON_FLAG2                   1'b0
    7       R   LDO_ANA_POS_PON_FLAG1                   1'b0
    10:8    R   LDO_ANA_POS_FSM_CS                      3'h0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_C_KOUT0X_LDO_ANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_ANA_POS_POF_FLAG4: 1;
        uint16_t LDO_ANA_POS_POF_FLAG3: 1;
        uint16_t LDO_ANA_POS_POF_FLAG2: 1;
        uint16_t LDO_ANA_POS_POF_FLAG1: 1;
        uint16_t LDO_ANA_POS_PON_FLAG4: 1;
        uint16_t LDO_ANA_POS_PON_FLAG3: 1;
        uint16_t LDO_ANA_POS_PON_FLAG2: 1;
        uint16_t LDO_ANA_POS_PON_FLAG1: 1;
        uint16_t LDO_ANA_POS_FSM_CS: 3;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT0X_LDO_ANA_POS_TYPE;

/* 0x21a
    7:0     R   LDO_ANA_POS_DR                          8'h0
    8       R   reserved                                1'h0
    9       R   reserved                                1'h0
    10      R   reserved                                1'h0
    11      R   reserved                                1'h0
    12      R   reserved                                1'h0
    13      R   reserved                                1'h0
    14      R   reserved                                1'h0
    15      R   reserved                                1'h0
 */
typedef volatile union _AON_FAST_REG_C_KOUT1X_LDO_ANA_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LDO_ANA_POS_DR: 8;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT1X_LDO_ANA_POS_TYPE;

/* 0x21c
    0       R/W SWR_VDDANA_VREF_POS_INT_RST_B           1'b0
    1       R   SWR_VDDANA_VREF_POS_EXT_RST_B           1'b1
    2       R/W SWR_VDDANA_VREF_POS_SEL_EXT_RST_B       1'b1
    3       R   SWR_VDDANA_VREF_POS_EN_POS              1'b0
    6:4     R/W SWR_VDDANA_VREF_POS_DIV_CLK             3'b000
    7       R/W SWR_VDDANA_VREF_POS_EN_DR_FIX           1'b0
    8       R   reserved                                1'b0
    9       R   reserved                                1'b0
    10      R   reserved                                1'b0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_SWR_VDDANA_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VREF_POS_INT_RST_B: 1;
        uint16_t SWR_VDDANA_VREF_POS_EXT_RST_B: 1;
        uint16_t SWR_VDDANA_VREF_POS_SEL_EXT_RST_B: 1;
        uint16_t SWR_VDDANA_VREF_POS_EN_POS: 1;
        uint16_t SWR_VDDANA_VREF_POS_DIV_CLK: 3;
        uint16_t SWR_VDDANA_VREF_POS_EN_DR_FIX: 1;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG0X_SWR_VDDANA_VREF_POS_TYPE;

/* 0x21e
    3:0     R/W SWR_VDDANA_VREF_POS_POF_STEP            4'b0010
    7:4     R/W SWR_VDDANA_VREF_POS_PON_STEP            4'b0010
    10:8    R/W SWR_VDDANA_VREF_POS_POF_WAIT            3'b000
    13:11   R/W SWR_VDDANA_VREF_POS_PON_WAIT            3'b000
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG1X_SWR_VDDANA_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VREF_POS_POF_STEP: 4;
        uint16_t SWR_VDDANA_VREF_POS_PON_STEP: 4;
        uint16_t SWR_VDDANA_VREF_POS_POF_WAIT: 3;
        uint16_t SWR_VDDANA_VREF_POS_PON_WAIT: 3;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG1X_SWR_VDDANA_VREF_POS_TYPE;

/* 0x220
    4:0     R/W SWR_VDDANA_VREF_POS_PON_OVER            5'b11111
    7:5     R   reserved                                3'b000
    12:8    R/W SWR_VDDANA_VREF_POS_PON_START           5'b00000
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG2X_SWR_VDDANA_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VREF_POS_PON_OVER: 5;
        uint16_t reserved_1: 3;
        uint16_t SWR_VDDANA_VREF_POS_PON_START: 5;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG2X_SWR_VDDANA_VREF_POS_TYPE;

/* 0x222
    4:0     R/W SWR_VDDANA_VREF_POS_POF_OVER            5'b00000
    7:5     R   reserved                                3'b000
    12:8    R/W SWR_VDDANA_VREF_POS_POF_START           5'b11111
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG3X_SWR_VDDANA_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VREF_POS_POF_OVER: 5;
        uint16_t reserved_1: 3;
        uint16_t SWR_VDDANA_VREF_POS_POF_START: 5;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG3X_SWR_VDDANA_VREF_POS_TYPE;

/* 0x224
    4:0     R/W SWR_VDDANA_VREF_POS_SET_PON_FLAG2       5'b00010
    7:5     R   reserved                                3'b000
    12:8    R/W SWR_VDDANA_VREF_POS_SET_PON_FLAG1       5'b00000
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG4X_SWR_VDDANA_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VREF_POS_SET_PON_FLAG2: 5;
        uint16_t reserved_1: 3;
        uint16_t SWR_VDDANA_VREF_POS_SET_PON_FLAG1: 5;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG4X_SWR_VDDANA_VREF_POS_TYPE;

/* 0x226
    4:0     R/W SWR_VDDANA_VREF_POS_SET_PON_FLAG4       5'b11111
    7:5     R   reserved                                3'b000
    12:8    R/W SWR_VDDANA_VREF_POS_SET_PON_FLAG3       5'b01100
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG5X_SWR_VDDANA_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VREF_POS_SET_PON_FLAG4: 5;
        uint16_t reserved_1: 3;
        uint16_t SWR_VDDANA_VREF_POS_SET_PON_FLAG3: 5;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG5X_SWR_VDDANA_VREF_POS_TYPE;

/* 0x228
    4:0     R/W SWR_VDDANA_VREF_POS_SET_POF_FLAG2       5'b01100
    7:5     R   reserved                                3'b000
    12:8    R/W SWR_VDDANA_VREF_POS_SET_POF_FLAG1       5'b11111
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG6X_SWR_VDDANA_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VREF_POS_SET_POF_FLAG2: 5;
        uint16_t reserved_1: 3;
        uint16_t SWR_VDDANA_VREF_POS_SET_POF_FLAG1: 5;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG6X_SWR_VDDANA_VREF_POS_TYPE;

/* 0x22a
    4:0     R/W SWR_VDDANA_VREF_POS_SET_POF_FLAG4       5'b00000
    7:5     R   reserved                                3'b000
    12:8    R/W SWR_VDDANA_VREF_POS_SET_POF_FLAG3       5'b00010
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG7X_SWR_VDDANA_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VREF_POS_SET_POF_FLAG4: 5;
        uint16_t reserved_1: 3;
        uint16_t SWR_VDDANA_VREF_POS_SET_POF_FLAG3: 5;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG7X_SWR_VDDANA_VREF_POS_TYPE;

/* 0x22c
    0       R   SWR_VDDANA_VREF_POS_POF_FLAG4           1'b0
    1       R   SWR_VDDANA_VREF_POS_POF_FLAG3           1'b0
    2       R   SWR_VDDANA_VREF_POS_POF_FLAG2           1'b0
    3       R   SWR_VDDANA_VREF_POS_POF_FLAG1           1'b0
    4       R   SWR_VDDANA_VREF_POS_PON_FLAG4           1'b0
    5       R   SWR_VDDANA_VREF_POS_PON_FLAG3           1'b0
    6       R   SWR_VDDANA_VREF_POS_PON_FLAG2           1'b0
    7       R   SWR_VDDANA_VREF_POS_PON_FLAG1           1'b0
    10:8    R   SWR_VDDANA_VREF_POS_FSM_CS              3'h0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_C_KOUT0X_SWR_VDDANA_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VREF_POS_POF_FLAG4: 1;
        uint16_t SWR_VDDANA_VREF_POS_POF_FLAG3: 1;
        uint16_t SWR_VDDANA_VREF_POS_POF_FLAG2: 1;
        uint16_t SWR_VDDANA_VREF_POS_POF_FLAG1: 1;
        uint16_t SWR_VDDANA_VREF_POS_PON_FLAG4: 1;
        uint16_t SWR_VDDANA_VREF_POS_PON_FLAG3: 1;
        uint16_t SWR_VDDANA_VREF_POS_PON_FLAG2: 1;
        uint16_t SWR_VDDANA_VREF_POS_PON_FLAG1: 1;
        uint16_t SWR_VDDANA_VREF_POS_FSM_CS: 3;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT0X_SWR_VDDANA_VREF_POS_TYPE;

/* 0x22e
    7:0     R   SWR_VDDANA_VREF_POS_DR                  8'h0
    8       R   reserved                                1'h0
    9       R   reserved                                1'h0
    10      R   reserved                                1'h0
    11      R   reserved                                1'h0
    12      R   reserved                                1'h0
    13      R   reserved                                1'h0
    14      R   reserved                                1'h0
    15      R   reserved                                1'h0
 */
typedef volatile union _AON_FAST_REG_C_KOUT1X_SWR_VDDANA_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VREF_POS_DR: 8;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT1X_SWR_VDDANA_VREF_POS_TYPE;

/* 0x230
    0       R/W SWR_VDDANA_VDIV_POS_INT_RST_B           1'b0
    1       R   SWR_VDDANA_VDIV_POS_EXT_RST_B           1'b1
    2       R/W SWR_VDDANA_VDIV_POS_SEL_EXT_RST_B       1'b1
    3       R   SWR_VDDANA_VDIV_POS_EN_POS              1'b0
    6:4     R/W SWR_VDDANA_VDIV_POS_DIV_CLK             3'b000
    7       R/W SWR_VDDANA_VDIV_POS_EN_DR_FIX           1'b0
    8       R   reserved                                1'b0
    9       R   reserved                                1'b0
    10      R   reserved                                1'b0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_SWR_VDDANA_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VDIV_POS_INT_RST_B: 1;
        uint16_t SWR_VDDANA_VDIV_POS_EXT_RST_B: 1;
        uint16_t SWR_VDDANA_VDIV_POS_SEL_EXT_RST_B: 1;
        uint16_t SWR_VDDANA_VDIV_POS_EN_POS: 1;
        uint16_t SWR_VDDANA_VDIV_POS_DIV_CLK: 3;
        uint16_t SWR_VDDANA_VDIV_POS_EN_DR_FIX: 1;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG0X_SWR_VDDANA_VDIV_POS_TYPE;

/* 0x232
    3:0     R/W SWR_VDDANA_VDIV_POS_POF_STEP            4'b1010
    7:4     R/W SWR_VDDANA_VDIV_POS_PON_STEP            4'b1010
    10:8    R/W SWR_VDDANA_VDIV_POS_POF_WAIT            3'b000
    13:11   R/W SWR_VDDANA_VDIV_POS_PON_WAIT            3'b000
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG1X_SWR_VDDANA_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VDIV_POS_POF_STEP: 4;
        uint16_t SWR_VDDANA_VDIV_POS_PON_STEP: 4;
        uint16_t SWR_VDDANA_VDIV_POS_POF_WAIT: 3;
        uint16_t SWR_VDDANA_VDIV_POS_PON_WAIT: 3;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG1X_SWR_VDDANA_VDIV_POS_TYPE;

/* 0x234
    7:0     R/W SWR_VDDANA_VDIV_POS_PON_OVER            8'b10001010
    15:8    R/W SWR_VDDANA_VDIV_POS_PON_START           8'b10001010
 */
typedef volatile union _AON_FAST_REG_REG2X_SWR_VDDANA_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VDIV_POS_PON_OVER: 8;
        uint16_t SWR_VDDANA_VDIV_POS_PON_START: 8;
    };
} AON_FAST_REG_REG2X_SWR_VDDANA_VDIV_POS_TYPE;

/* 0x236
    7:0     R/W SWR_VDDANA_VDIV_POS_POF_OVER            8'b10001010
    15:8    R/W SWR_VDDANA_VDIV_POS_POF_START           8'b10001010
 */
typedef volatile union _AON_FAST_REG_REG3X_SWR_VDDANA_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VDIV_POS_POF_OVER: 8;
        uint16_t SWR_VDDANA_VDIV_POS_POF_START: 8;
    };
} AON_FAST_REG_REG3X_SWR_VDDANA_VDIV_POS_TYPE;

/* 0x238
    7:0     R   reserved                                8'b00000001
    15:8    R   reserved                                8'b00000000
 */
typedef volatile union _AON_FAST_REG_REG4X_SWR_VDDANA_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG4X_SWR_VDDANA_VDIV_POS_TYPE;

/* 0x23a
    7:0     R   reserved                                8'b00000111
    15:8    R   reserved                                8'b00000110
 */
typedef volatile union _AON_FAST_REG_REG5X_SWR_VDDANA_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG5X_SWR_VDDANA_VDIV_POS_TYPE;

/* 0x23c
    7:0     R   reserved                                8'b00000110
    15:8    R   reserved                                8'b00000111
 */
typedef volatile union _AON_FAST_REG_REG6X_SWR_VDDANA_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG6X_SWR_VDDANA_VDIV_POS_TYPE;

/* 0x23e
    7:0     R   reserved                                8'b00000000
    15:8    R   reserved                                8'b00000001
 */
typedef volatile union _AON_FAST_REG_REG7X_SWR_VDDANA_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG7X_SWR_VDDANA_VDIV_POS_TYPE;

/* 0x240
    0       R   SWR_VDDANA_VDIV_POS_POF_FLAG4           1'b0
    1       R   SWR_VDDANA_VDIV_POS_POF_FLAG3           1'b0
    2       R   SWR_VDDANA_VDIV_POS_POF_FLAG2           1'b0
    3       R   SWR_VDDANA_VDIV_POS_POF_FLAG1           1'b0
    4       R   SWR_VDDANA_VDIV_POS_PON_FLAG4           1'b0
    5       R   SWR_VDDANA_VDIV_POS_PON_FLAG3           1'b0
    6       R   SWR_VDDANA_VDIV_POS_PON_FLAG2           1'b0
    7       R   SWR_VDDANA_VDIV_POS_PON_FLAG1           1'b0
    10:8    R   SWR_VDDANA_VDIV_POS_FSM_CS              3'h0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_C_KOUT0X_SWR_VDDANA_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VDIV_POS_POF_FLAG4: 1;
        uint16_t SWR_VDDANA_VDIV_POS_POF_FLAG3: 1;
        uint16_t SWR_VDDANA_VDIV_POS_POF_FLAG2: 1;
        uint16_t SWR_VDDANA_VDIV_POS_POF_FLAG1: 1;
        uint16_t SWR_VDDANA_VDIV_POS_PON_FLAG4: 1;
        uint16_t SWR_VDDANA_VDIV_POS_PON_FLAG3: 1;
        uint16_t SWR_VDDANA_VDIV_POS_PON_FLAG2: 1;
        uint16_t SWR_VDDANA_VDIV_POS_PON_FLAG1: 1;
        uint16_t SWR_VDDANA_VDIV_POS_FSM_CS: 3;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT0X_SWR_VDDANA_VDIV_POS_TYPE;

/* 0x242
    7:0     R   SWR_VDDANA_VDIV_POS_DR                  8'h0
    8       R   reserved                                1'h0
    9       R   reserved                                1'h0
    10      R   reserved                                1'h0
    11      R   reserved                                1'h0
    12      R   reserved                                1'h0
    13      R   reserved                                1'h0
    14      R   reserved                                1'h0
    15      R   reserved                                1'h0
 */
typedef volatile union _AON_FAST_REG_C_KOUT1X_SWR_VDDANA_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDANA_VDIV_POS_DR: 8;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT1X_SWR_VDDANA_VDIV_POS_TYPE;

/* 0x244
    0       R/W SWR_VDDCORE_VREF_POS_INT_RST_B          1'b0
    1       R   SWR_VDDCORE_VREF_POS_EXT_RST_B          1'b1
    2       R/W SWR_VDDCORE_VREF_POS_SEL_EXT_RST_B      1'b1
    3       R   SWR_VDDCORE_VREF_POS_EN_POS             1'b0
    6:4     R/W SWR_VDDCORE_VREF_POS_DIV_CLK            3'b000
    7       R/W SWR_VDDCORE_VREF_POS_EN_DR_FIX          1'b0
    8       R   reserved                                1'b0
    9       R   reserved                                1'b0
    10      R   reserved                                1'b0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_SWR_VDDCORE_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VREF_POS_INT_RST_B: 1;
        uint16_t SWR_VDDCORE_VREF_POS_EXT_RST_B: 1;
        uint16_t SWR_VDDCORE_VREF_POS_SEL_EXT_RST_B: 1;
        uint16_t SWR_VDDCORE_VREF_POS_EN_POS: 1;
        uint16_t SWR_VDDCORE_VREF_POS_DIV_CLK: 3;
        uint16_t SWR_VDDCORE_VREF_POS_EN_DR_FIX: 1;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG0X_SWR_VDDCORE_VREF_POS_TYPE;

/* 0x246
    3:0     R/W SWR_VDDCORE_VREF_POS_POF_STEP           4'b0010
    7:4     R/W SWR_VDDCORE_VREF_POS_PON_STEP           4'b0010
    10:8    R/W SWR_VDDCORE_VREF_POS_POF_WAIT           3'b000
    13:11   R/W SWR_VDDCORE_VREF_POS_PON_WAIT           3'b000
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG1X_SWR_VDDCORE_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VREF_POS_POF_STEP: 4;
        uint16_t SWR_VDDCORE_VREF_POS_PON_STEP: 4;
        uint16_t SWR_VDDCORE_VREF_POS_POF_WAIT: 3;
        uint16_t SWR_VDDCORE_VREF_POS_PON_WAIT: 3;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG1X_SWR_VDDCORE_VREF_POS_TYPE;

/* 0x248
    4:0     R/W SWR_VDDCORE_VREF_POS_PON_OVER           5'b11111
    7:5     R   reserved                                3'b000
    12:8    R/W SWR_VDDCORE_VREF_POS_PON_START          5'b00000
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG2X_SWR_VDDCORE_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VREF_POS_PON_OVER: 5;
        uint16_t reserved_1: 3;
        uint16_t SWR_VDDCORE_VREF_POS_PON_START: 5;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG2X_SWR_VDDCORE_VREF_POS_TYPE;

/* 0x24a
    4:0     R/W SWR_VDDCORE_VREF_POS_POF_OVER           5'b00000
    7:5     R   reserved                                3'b000
    12:8    R/W SWR_VDDCORE_VREF_POS_POF_START          5'b11111
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG3X_SWR_VDDCORE_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VREF_POS_POF_OVER: 5;
        uint16_t reserved_1: 3;
        uint16_t SWR_VDDCORE_VREF_POS_POF_START: 5;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG3X_SWR_VDDCORE_VREF_POS_TYPE;

/* 0x24c
    4:0     R/W SWR_VDDCORE_VREF_POS_SET_PON_FLAG2      5'b00010
    7:5     R   reserved                                3'b000
    12:8    R/W SWR_VDDCORE_VREF_POS_SET_PON_FLAG1      5'b00000
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG4X_SWR_VDDCORE_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VREF_POS_SET_PON_FLAG2: 5;
        uint16_t reserved_1: 3;
        uint16_t SWR_VDDCORE_VREF_POS_SET_PON_FLAG1: 5;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG4X_SWR_VDDCORE_VREF_POS_TYPE;

/* 0x24e
    4:0     R/W SWR_VDDCORE_VREF_POS_SET_PON_FLAG4      5'b11111
    7:5     R   reserved                                3'b000
    12:8    R/W SWR_VDDCORE_VREF_POS_SET_PON_FLAG3      5'b01100
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG5X_SWR_VDDCORE_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VREF_POS_SET_PON_FLAG4: 5;
        uint16_t reserved_1: 3;
        uint16_t SWR_VDDCORE_VREF_POS_SET_PON_FLAG3: 5;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG5X_SWR_VDDCORE_VREF_POS_TYPE;

/* 0x250
    4:0     R/W SWR_VDDCORE_VREF_POS_SET_POF_FLAG2      5'b00110
    7:5     R   reserved                                3'b000
    12:8    R/W SWR_VDDCORE_VREF_POS_SET_POF_FLAG1      5'b11111
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG6X_SWR_VDDCORE_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VREF_POS_SET_POF_FLAG2: 5;
        uint16_t reserved_1: 3;
        uint16_t SWR_VDDCORE_VREF_POS_SET_POF_FLAG1: 5;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG6X_SWR_VDDCORE_VREF_POS_TYPE;

/* 0x252
    4:0     R/W SWR_VDDCORE_VREF_POS_SET_POF_FLAG4      5'b01100
    7:5     R   reserved                                3'b000
    12:8    R/W SWR_VDDCORE_VREF_POS_SET_POF_FLAG3      5'b00010
    15:13   R   reserved                                3'b000
 */
typedef volatile union _AON_FAST_REG_REG7X_SWR_VDDCORE_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VREF_POS_SET_POF_FLAG4: 5;
        uint16_t reserved_1: 3;
        uint16_t SWR_VDDCORE_VREF_POS_SET_POF_FLAG3: 5;
        uint16_t reserved: 3;
    };
} AON_FAST_REG_REG7X_SWR_VDDCORE_VREF_POS_TYPE;

/* 0x254
    0       R   SWR_VDDCORE_VREF_POS_POF_FLAG4          1'b0
    1       R   SWR_VDDCORE_VREF_POS_POF_FLAG3          1'b0
    2       R   SWR_VDDCORE_VREF_POS_POF_FLAG2          1'b0
    3       R   SWR_VDDCORE_VREF_POS_POF_FLAG1          1'b0
    4       R   SWR_VDDCORE_VREF_POS_PON_FLAG4          1'b0
    5       R   SWR_VDDCORE_VREF_POS_PON_FLAG3          1'b0
    6       R   SWR_VDDCORE_VREF_POS_PON_FLAG2          1'b0
    7       R   SWR_VDDCORE_VREF_POS_PON_FLAG1          1'b0
    10:8    R   SWR_VDDCORE_VREF_POS_FSM_CS             3'h0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_C_KOUT0X_SWR_VDDCORE_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VREF_POS_POF_FLAG4: 1;
        uint16_t SWR_VDDCORE_VREF_POS_POF_FLAG3: 1;
        uint16_t SWR_VDDCORE_VREF_POS_POF_FLAG2: 1;
        uint16_t SWR_VDDCORE_VREF_POS_POF_FLAG1: 1;
        uint16_t SWR_VDDCORE_VREF_POS_PON_FLAG4: 1;
        uint16_t SWR_VDDCORE_VREF_POS_PON_FLAG3: 1;
        uint16_t SWR_VDDCORE_VREF_POS_PON_FLAG2: 1;
        uint16_t SWR_VDDCORE_VREF_POS_PON_FLAG1: 1;
        uint16_t SWR_VDDCORE_VREF_POS_FSM_CS: 3;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT0X_SWR_VDDCORE_VREF_POS_TYPE;

/* 0x256
    7:0     R   SWR_VDDCORE_VREF_POS_DR                 8'h0
    8       R   reserved                                1'h0
    9       R   reserved                                1'h0
    10      R   reserved                                1'h0
    11      R   reserved                                1'h0
    12      R   reserved                                1'h0
    13      R   reserved                                1'h0
    14      R   reserved                                1'h0
    15      R   reserved                                1'h0
 */
typedef volatile union _AON_FAST_REG_C_KOUT1X_SWR_VDDCORE_VREF_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VREF_POS_DR: 8;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT1X_SWR_VDDCORE_VREF_POS_TYPE;

/* 0x258
    0       R/W SWR_VDDCORE_VDIV_POS_INT_RST_B          1'b0
    1       R   SWR_VDDCORE_VDIV_POS_EXT_RST_B          1'b1
    2       R/W SWR_VDDCORE_VDIV_POS_SEL_EXT_RST_B      1'b1
    3       R   SWR_VDDCORE_VDIV_POS_EN_POS             1'b0
    6:4     R/W SWR_VDDCORE_VDIV_POS_DIV_CLK            3'b000
    7       R/W SWR_VDDCORE_VDIV_POS_EN_DR_FIX          1'b0
    8       R   reserved                                1'b0
    9       R   reserved                                1'b0
    10      R   reserved                                1'b0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG0X_SWR_VDDCORE_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VDIV_POS_INT_RST_B: 1;
        uint16_t SWR_VDDCORE_VDIV_POS_EXT_RST_B: 1;
        uint16_t SWR_VDDCORE_VDIV_POS_SEL_EXT_RST_B: 1;
        uint16_t SWR_VDDCORE_VDIV_POS_EN_POS: 1;
        uint16_t SWR_VDDCORE_VDIV_POS_DIV_CLK: 3;
        uint16_t SWR_VDDCORE_VDIV_POS_EN_DR_FIX: 1;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG0X_SWR_VDDCORE_VDIV_POS_TYPE;

/* 0x25a
    3:0     R/W SWR_VDDCORE_VDIV_POS_POF_STEP           4'b1010
    7:4     R/W SWR_VDDCORE_VDIV_POS_PON_STEP           4'b1010
    10:8    R/W SWR_VDDCORE_VDIV_POS_POF_WAIT           3'b000
    13:11   R/W SWR_VDDCORE_VDIV_POS_PON_WAIT           3'b000
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_REG1X_SWR_VDDCORE_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VDIV_POS_POF_STEP: 4;
        uint16_t SWR_VDDCORE_VDIV_POS_PON_STEP: 4;
        uint16_t SWR_VDDCORE_VDIV_POS_POF_WAIT: 3;
        uint16_t SWR_VDDCORE_VDIV_POS_PON_WAIT: 3;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_REG1X_SWR_VDDCORE_VDIV_POS_TYPE;

/* 0x25c
    7:0     R/W SWR_VDDCORE_VDIV_POS_PON_OVER           8'b01101100
    15:8    R/W SWR_VDDCORE_VDIV_POS_PON_START          8'b01101100
 */
typedef volatile union _AON_FAST_REG_REG2X_SWR_VDDCORE_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VDIV_POS_PON_OVER: 8;
        uint16_t SWR_VDDCORE_VDIV_POS_PON_START: 8;
    };
} AON_FAST_REG_REG2X_SWR_VDDCORE_VDIV_POS_TYPE;

/* 0x25e
    7:0     R/W SWR_VDDCORE_VDIV_POS_POF_OVER           8'b01101100
    15:8    R/W SWR_VDDCORE_VDIV_POS_POF_START          8'b01101100
 */
typedef volatile union _AON_FAST_REG_REG3X_SWR_VDDCORE_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VDIV_POS_POF_OVER: 8;
        uint16_t SWR_VDDCORE_VDIV_POS_POF_START: 8;
    };
} AON_FAST_REG_REG3X_SWR_VDDCORE_VDIV_POS_TYPE;

/* 0x260
    7:0     R   reserved                                8'b00000001
    15:8    R   reserved                                8'b00000000
 */
typedef volatile union _AON_FAST_REG_REG4X_SWR_VDDCORE_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG4X_SWR_VDDCORE_VDIV_POS_TYPE;

/* 0x262
    7:0     R   reserved                                8'b00000111
    15:8    R   reserved                                8'b00000110
 */
typedef volatile union _AON_FAST_REG_REG5X_SWR_VDDCORE_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG5X_SWR_VDDCORE_VDIV_POS_TYPE;

/* 0x264
    7:0     R   reserved                                8'b00000110
    15:8    R   reserved                                8'b00000111
 */
typedef volatile union _AON_FAST_REG_REG6X_SWR_VDDCORE_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG6X_SWR_VDDCORE_VDIV_POS_TYPE;

/* 0x266
    7:0     R   reserved                                8'b00000000
    15:8    R   reserved                                8'b00000001
 */
typedef volatile union _AON_FAST_REG_REG7X_SWR_VDDCORE_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t reserved_1: 8;
        uint16_t reserved: 8;
    };
} AON_FAST_REG_REG7X_SWR_VDDCORE_VDIV_POS_TYPE;

/* 0x268
    0       R   SWR_VDDCORE_VDIV_POS_POF_FLAG4          1'b0
    1       R   SWR_VDDCORE_VDIV_POS_POF_FLAG3          1'b0
    2       R   SWR_VDDCORE_VDIV_POS_POF_FLAG2          1'b0
    3       R   SWR_VDDCORE_VDIV_POS_POF_FLAG1          1'b0
    4       R   SWR_VDDCORE_VDIV_POS_PON_FLAG4          1'b0
    5       R   SWR_VDDCORE_VDIV_POS_PON_FLAG3          1'b0
    6       R   SWR_VDDCORE_VDIV_POS_PON_FLAG2          1'b0
    7       R   SWR_VDDCORE_VDIV_POS_PON_FLAG1          1'b0
    10:8    R   SWR_VDDCORE_VDIV_POS_FSM_CS             3'h0
    11      R   reserved                                1'b0
    12      R   reserved                                1'b0
    13      R   reserved                                1'b0
    14      R   reserved                                1'b0
    15      R   reserved                                1'b0
 */
typedef volatile union _AON_FAST_REG_C_KOUT0X_SWR_VDDCORE_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VDIV_POS_POF_FLAG4: 1;
        uint16_t SWR_VDDCORE_VDIV_POS_POF_FLAG3: 1;
        uint16_t SWR_VDDCORE_VDIV_POS_POF_FLAG2: 1;
        uint16_t SWR_VDDCORE_VDIV_POS_POF_FLAG1: 1;
        uint16_t SWR_VDDCORE_VDIV_POS_PON_FLAG4: 1;
        uint16_t SWR_VDDCORE_VDIV_POS_PON_FLAG3: 1;
        uint16_t SWR_VDDCORE_VDIV_POS_PON_FLAG2: 1;
        uint16_t SWR_VDDCORE_VDIV_POS_PON_FLAG1: 1;
        uint16_t SWR_VDDCORE_VDIV_POS_FSM_CS: 3;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT0X_SWR_VDDCORE_VDIV_POS_TYPE;

/* 0x26a
    7:0     R   SWR_VDDCORE_VDIV_POS_DR                 8'h0
    8       R   reserved                                1'h0
    9       R   reserved                                1'h0
    10      R   reserved                                1'h0
    11      R   reserved                                1'h0
    12      R   reserved                                1'h0
    13      R   reserved                                1'h0
    14      R   reserved                                1'h0
    15      R   reserved                                1'h0
 */
typedef volatile union _AON_FAST_REG_C_KOUT1X_SWR_VDDCORE_VDIV_POS_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SWR_VDDCORE_VDIV_POS_DR: 8;
        uint16_t reserved_7: 1;
        uint16_t reserved_6: 1;
        uint16_t reserved_5: 1;
        uint16_t reserved_4: 1;
        uint16_t reserved_3: 1;
        uint16_t reserved_2: 1;
        uint16_t reserved_1: 1;
        uint16_t reserved: 1;
    };
} AON_FAST_REG_C_KOUT1X_SWR_VDDCORE_VDIV_POS_TYPE;

/* 0x280
    1:0     R/W SAW_cache_0                             2'h2
    3:2     R/W SAW_cache_1                             2'h2
    5:4     R/W SAW_cache_2                             2'h2
    7:6     R/W SAW_lemst                               2'h2
    9:8     R/W SAW_lepa                                2'h2
    11:10   R/W RA_retsram                              2'h0
    13:12   R/W RA_buffer                               2'h0
    15:14   R/W RA_audio                                2'h0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL1_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SAW_cache_0: 2;
        uint16_t SAW_cache_1: 2;
        uint16_t SAW_cache_2: 2;
        uint16_t SAW_lemst: 2;
        uint16_t SAW_lepa: 2;
        uint16_t RA_retsram: 2;
        uint16_t RA_buffer: 2;
        uint16_t RA_audio: 2;
    };
} AON_FAST_REG_REG_SRAM_CTRL1_TYPE;

/* 0x282
    1:0     R/W RA_btphy                                2'h0
    3:2     R/W RA_zigbee                               2'h0
    5:4     R/W RA_snps                                 2'h0
    15:6    R   RSVD                                    10'b0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL2_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t RA_btphy: 2;
        uint16_t RA_zigbee: 2;
        uint16_t RA_snps: 2;
        uint16_t RSVD: 10;
    };
} AON_FAST_REG_REG_SRAM_CTRL2_TYPE;

/* 0x284
    4:0     R   RSVD                                    0
    5       R/W TEST1_retsram                           0
    6       R/W TEST1_buffer                            0
    7       R/W TEST1_audio                             0
    8       R/W TEST1_btphy                             0
    9       R/W TEST1_zigbee                            0
    10      R/W TEST1_snps                              0
    15:11   R   RSVD                                    0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL3_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t RSVD_1: 5;
        uint16_t TEST1_retsram: 1;
        uint16_t TEST1_buffer: 1;
        uint16_t TEST1_audio: 1;
        uint16_t TEST1_btphy: 1;
        uint16_t TEST1_zigbee: 1;
        uint16_t TEST1_snps: 1;
        uint16_t RSVD: 5;
    };
} AON_FAST_REG_REG_SRAM_CTRL3_TYPE;

/* 0x286
    0       R/W WAE_cache_0                             1
    1       R/W WAE_cache_1                             1
    2       R/W WAE_cache_2                             1
    3       R/W WAE_lemst                               1
    4       R/W WAE_lepa                                1
    5       R/W RME_retsram                             1
    6       R/W RME_buffer                              1
    7       R/W RME_audio                               1
    8       R/W RME_btphy                               1
    9       R/W RME_zigbee                              1
    10      R/W RME_snps                                1
    11      R/W RME_rom                                 1
    15:12   R   RSVD                                    0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL4_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t WAE_cache_0: 1;
        uint16_t WAE_cache_1: 1;
        uint16_t WAE_cache_2: 1;
        uint16_t WAE_lemst: 1;
        uint16_t WAE_lepa: 1;
        uint16_t RME_retsram: 1;
        uint16_t RME_buffer: 1;
        uint16_t RME_audio: 1;
        uint16_t RME_btphy: 1;
        uint16_t RME_zigbee: 1;
        uint16_t RME_snps: 1;
        uint16_t RME_rom: 1;
        uint16_t RSVD: 4;
    };
} AON_FAST_REG_REG_SRAM_CTRL4_TYPE;

/* 0x288
    3:0     R/W WM_cache_0                              4'b1000
    7:4     R/W WM_cache_1                              4'b1000
    11:8    R/W WM_cache_2                              4'b1000
    15:12   R/W WM_lemst                                4'b1000
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL5_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t WM_cache_0: 4;
        uint16_t WM_cache_1: 4;
        uint16_t WM_cache_2: 4;
        uint16_t WM_lemst: 4;
    };
} AON_FAST_REG_REG_SRAM_CTRL5_TYPE;

/* 0x28a
    3:0     R/W WM_lepa                                 4'b1000
    15:4    R   RSVD                                    0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL6_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t WM_lepa: 4;
        uint16_t RSVD: 12;
    };
} AON_FAST_REG_REG_SRAM_CTRL6_TYPE;

/* 0x28c
    3:0     R/W RM_retsram                              4'b0010
    7:4     R/W RM_cache_0                              4'b0010
    11:8    R/W RM_cache_1                              4'b0010
    15:12   R/W RM_cache_2                              4'b0010
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL7_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t RM_retsram: 4;
        uint16_t RM_cache_0: 4;
        uint16_t RM_cache_1: 4;
        uint16_t RM_cache_2: 4;
    };
} AON_FAST_REG_REG_SRAM_CTRL7_TYPE;

/* 0x28e
    3:0     R/W RM_lemst                                4'b0010
    7:4     R/W RM_lepa                                 4'b0010
    11:8    R/W RM_buffer                               4'b0010
    15:12   R/W RM_audio                                4'b0010
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL8_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t RM_lemst: 4;
        uint16_t RM_lepa: 4;
        uint16_t RM_buffer: 4;
        uint16_t RM_audio: 4;
    };
} AON_FAST_REG_REG_SRAM_CTRL8_TYPE;

/* 0x290
    3:0     R/W RM_btphy                                4'b0010
    7:4     R/W RM_zigbee                               4'b0010
    11:8    R/W RM_snps                                 4'b0010
    15:12   R/W RM_rom                                  4'b0010
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL9_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t RM_btphy: 4;
        uint16_t RM_zigbee: 4;
        uint16_t RM_snps: 4;
        uint16_t RM_rom: 4;
    };
} AON_FAST_REG_REG_SRAM_CTRL9_TYPE;

/* 0x292
    2:0     R/W WA_btphy                                3'b101
    5:3     R/W WA_zigbee                               3'b101
    8:6     R/W WA_snps                                 3'b101
    15:9    R   RSVD                                    0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL10_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t WA_btphy: 3;
        uint16_t WA_zigbee: 3;
        uint16_t WA_snps: 3;
        uint16_t RSVD: 7;
    };
} AON_FAST_REG_REG_SRAM_CTRL10_TYPE;

/* 0x294
    2:0     R/W WPULSE_retsram                          3'h0
    5:3     R/W WPULSE_buffer                           3'h0
    8:6     R/W WPULSE_audio                            3'h0
    11:9    R/W WPULSE_btphy                            3'h0
    14:12   R/W WPULSE_zigbee                           3'h0
    15      R   RSVD                                    0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL11_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t WPULSE_retsram: 3;
        uint16_t WPULSE_buffer: 3;
        uint16_t WPULSE_audio: 3;
        uint16_t WPULSE_btphy: 3;
        uint16_t WPULSE_zigbee: 3;
        uint16_t RSVD: 1;
    };
} AON_FAST_REG_REG_SRAM_CTRL11_TYPE;

/* 0x296
    2:0     R/W WPULSE_snps                             3'h0
    15:3    R   RSVD                                    0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL12_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t WPULSE_snps: 3;
        uint16_t RSVD: 13;
    };
} AON_FAST_REG_REG_SRAM_CTRL12_TYPE;

/* 0x298
    2:0     R/W WA_cache_0                              3'b011
    5:3     R/W WA_cache_1                              3'b001
    8:6     R/W WA_cache_2                              3'b001
    11:9    R/W WA_lepa                                 3'b001
    14:12   R/W WA_lemst                                3'b011
    15      R   RSVD                                    0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL13_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t WA_cache_0: 3;
        uint16_t WA_cache_1: 3;
        uint16_t WA_cache_2: 3;
        uint16_t WA_lepa: 3;
        uint16_t WA_lemst: 3;
        uint16_t RSVD: 1;
    };
} AON_FAST_REG_REG_SRAM_CTRL13_TYPE;

/* 0x29a
    2:0     R/W WA_retsram                              3'b101
    5:3     R/W WA_buffer                               3'b101
    8:6     R/W WA_audio                                3'b101
    15:9    R   RSVD                                    0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL14_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t WA_retsram: 3;
        uint16_t WA_buffer: 3;
        uint16_t WA_audio: 3;
        uint16_t RSVD: 7;
    };
} AON_FAST_REG_REG_SRAM_CTRL14_TYPE;

/* 0x29c
    8:0     R/W DS_cache[8:0]                           9'b0
    9       R/W DS_lepa                                 1'b0
    10      R/W SD_lepa                                 1'b0
    11      R/W DS_lemst                                1'b0
    12      R/W SD_lemst                                1'b0
    14:13   R/W LS_snps[1:0]                            2'b00
    15      R   RSVD                                    0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL15_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t DS_cache_8_0: 9;
        uint16_t DS_lepa: 1;
        uint16_t SD_lepa: 1;
        uint16_t DS_lemst: 1;
        uint16_t SD_lemst: 1;
        uint16_t LS_snps_1_0: 2;
        uint16_t RSVD: 1;
    };
} AON_FAST_REG_REG_SRAM_CTRL15_TYPE;

/* 0x29e
    8:0     R/W SD_cache[8:0]                           9'b0
    15:9    R   RSVD                                    0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL16_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SD_cache_8_0: 9;
        uint16_t RSVD: 7;
    };
} AON_FAST_REG_REG_SRAM_CTRL16_TYPE;

/* 0x2a0
    4:0     R/W LS_retsram[4:0]                         5'b0
    9:5     R/W DS_retsram[4:0]                         5'b0
    14:10   R/W SD_retsram[4:0]                         5'b0
    15      R   RSVD                                    0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL17_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LS_retsram_4_0: 5;
        uint16_t DS_retsram_4_0: 5;
        uint16_t SD_retsram_4_0: 5;
        uint16_t RSVD: 1;
    };
} AON_FAST_REG_REG_SRAM_CTRL17_TYPE;

/* 0x2a2
    4:0     R/W RSVD                                    5'b0
    9:5     R/W RSVD                                    5'b0
    14:10   R/W RSVD                                    5'b0
    15      R   RSVD                                    0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL18_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t RSVD_3: 5;
        uint16_t RSVD_2: 5;
        uint16_t RSVD_1: 5;
        uint16_t RSVD: 1;
    };
} AON_FAST_REG_REG_SRAM_CTRL18_TYPE;

/* 0x2a4
    0       R/W LS_buffer                               1'b0
    1       R/W DS_buffer                               1'b0
    2       R/W SD_buffer                               1'b0
    3       R/W LS_audio                                1'b0
    5:4     R/W RSVD                                    2'b0
    6       R/W LS_rom                                  1'b0
    7       R   RSVD                                    0
    11:8    R/W LS_zigbee_32x32[3:0]                    4'b0
    15:12   R/W DS_zigbee_32x32[3:0]                    4'b0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL19_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t LS_buffer: 1;
        uint16_t DS_buffer: 1;
        uint16_t SD_buffer: 1;
        uint16_t LS_audio: 1;
        uint16_t RSVD_1: 2;
        uint16_t LS_rom: 1;
        uint16_t RSVD: 1;
        uint16_t LS_zigbee_32x32_3_0: 4;
        uint16_t DS_zigbee_32x32_3_0: 4;
    };
} AON_FAST_REG_REG_SRAM_CTRL19_TYPE;

/* 0x2a6
    3:0     R/W SD_zigbee_32x32[3:0]                    4'b0
    5:4     R/W LS_zigbee_40x32[1:0]                    2'b0
    7:6     R/W DS_zigbee_40x32[1:0]                    2'b0
    9:8     R/W SD_zigbee_40x32[1:0]                    2'b0
    10      R/W LS_zigbee_16x32                         1'b0
    11      R/W DS_zigbee_16x32                         1'b0
    12      R/W SD_zigbee_16x32                         1'b0
    15:13   R   RSVD                                    0
 */
typedef volatile union _AON_FAST_REG_REG_SRAM_CTRL20_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t SD_zigbee_32x32_3_0: 4;
        uint16_t LS_zigbee_40x32_1_0: 2;
        uint16_t DS_zigbee_40x32_1_0: 2;
        uint16_t SD_zigbee_40x32_1_0: 2;
        uint16_t LS_zigbee_16x32: 1;
        uint16_t DS_zigbee_16x32: 1;
        uint16_t SD_zigbee_16x32: 1;
        uint16_t RSVD: 3;
    };
} AON_FAST_REG_REG_SRAM_CTRL20_TYPE;

#define AON_REG_BASE 0x40000000

#define AON_REG_READ(Offset)                                            \
    ((uint32_t)*((volatile uint32_t*)(AON_REG_BASE+(Offset))))

#define AON_REG_WRITE(Offset, Value)                                    \
    ((*((volatile uint32_t*)(AON_REG_BASE + (Offset)))) = (Value))

#define AON_REG_UPDATE(Offset, Mask, Value)                             \
    do {                                                                \
        uint32_t temp;                                                  \
        temp = AON_REG_READ(Offset) & ~(Mask);                          \
        AON_REG_WRITE(Offset, (temp | ((Value) & (Mask))));             \
    } while(0)

#define AON_REG_READ_BITFIELD(Offset, Bitfield)                         \
    (((Offset##_TYPE)AON_REG_READ(Offset)).Bitfield)

#define AON_REG_WRITE_BITFIELD(Offset, Bitfield, Value)                 \
    do {                                                                \
        Offset##_TYPE temp = {.d32 = AON_REG_READ(Offset)};             \
        temp.Bitfield = Value;                                          \
        AON_REG_WRITE(Offset, temp.d32);                                \
    } while(0)
#endif
