#ifndef _CLOCK_MANAGER_POWER_INFERFACE_H
#define _CLOCK_MANAGER_POWER_INFERFACE_H

#include "power_manager_unit_platform.h"

typedef enum
{
    POWER_OFF        = 0,
    POWER_ON         = 1,
    POWER_UNDEF      = 2,
} CLOCK_SRC_STATUS_TYPE;

typedef enum
{
    SW_CAL         = 0,
    HW_CAL         = 1,
    CAL_UNDEF      = 2,
} OSC_32_CAL_STATUS_TYPE;

typedef enum
{
    XTAL_MODE_NM    = 0,
    XTAL_MODE_LP    = 1,
    XTAL_MODE_BUF   = 2,
    XTAL_MODE_HP    = 4,
    XTAL_MODE_UNDEF = 5,
} XTAL_MODE_TYPE;

/**
 * @brief Clock 40M LOP Config
 *
 */
typedef union
{
    uint16_t d16;
    struct
    {
        uint16_t osc40_pow : 2;
        uint16_t xtal40_pow: 2;
        uint16_t xtal_mode : 3;
        uint16_t rsvd      : 9;
    };

} CLOCK_40M_CONFIG_Type;


/**
 * @brief 32K Clock LOP Config
 *
 */
typedef union
{
    uint8_t d8;
    struct
    {
        uint8_t osc32_pow   : 2;
        uint8_t lop_pof_cal : 2;
        uint8_t rsvd        : 4;
    };
} CLOCK_32K_CONFIG_Type;

typedef struct
{
    CLOCK_40M_CONFIG_Type pon_40m_config[PLATFORM_POWER_MODE_MAX];
    CLOCK_40M_CONFIG_Type pof_40m_config[PLATFORM_POWER_MODE_MAX];

    CLOCK_32K_CONFIG_Type pon_32k_config[PLATFORM_POWER_MODE_MAX];
    CLOCK_32K_CONFIG_Type pof_32k_config[PLATFORM_POWER_MODE_MAX];

} CLOCK_MANAGER_STATUS;

extern bool (*clock_pm_check)(PlatformPowerMode power_mode);
extern void (*clock_pm_enter)(PlatformPowerMode power_mode);
extern void (*clock_pm_exit)(void);

#endif  /* _CLOCK_MANAGER_POWER_INFERFACE_H */
