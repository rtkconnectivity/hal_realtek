/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef _RFC_H_
#define _RFC_H_

/*============================================================================*
 *                               Header Files
 *============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "rtl876x.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                              Compile Flags
 *============================================================================*/
// rf mode
#define SUPPORT_POLAR_TX                                0
#define SUPPORT_IQM_MODE                                0
#define SUPPORT_TPM_MODE                                1

#if (SUPPORT_POLAR_TX + SUPPORT_IQM_MODE + SUPPORT_TPM_MODE == 0)
#error "ERROR!!! At least support one rf mode"
#endif

#if (USE_EXTERNAL_RF == 1)
#undef SUPPORT_IQM_MODE
#define SUPPORT_IQM_MODE                                1
#endif

#define SUPPORT_LEGACY                                  0

#define SUPPORT_ZIGBEE                                  1

#define SUPPORT_PROPRIETARY                             1

/*============================================================================*
 *                              Types
 *============================================================================*/
typedef enum
{
    FUNC_MAC_SET_RADIO_CONTROL_BIT          = 0x00,
    FUNC_MAC_CHECK_RADIO_CONTROL_READY      = 0x01,

    MAC_RFC_FUNC_MAX                        = 0x40,
} MAC_RFC_FUNC_NAME;

typedef enum
{
#if (SUPPORT_POLAR_TX == 1)
    POLAR_TX,
#endif
#if (SUPPORT_IQM_MODE == 1)
    IQM_MODE,
#endif
#if (SUPPORT_TPM_MODE == 1)
    TPM_MODE,
#endif
    NUM_RF_MODE,
} RF_MODE;

typedef enum
{
#if (SUPPORT_LEGACY == 1)
    TXGAIN_BR_1M,
    TXGAIN_EDR_2M,
    TXGAIN_EDR_3M,
#endif
    TXGAIN_LE_1M,
    TXGAIN_LE_2M,
    TXGAIN_LR,
    TXGAIN_LE_1M_ADV,
    TXGAIN_LE_2M_ADV,
    TXGAIN_LE_1M_2402,
    TXGAIN_LE_1M_2480,
    TXGAIN_LE_2M_2402,
    TXGAIN_LE_2M_2480,
#if (SUPPORT_ZIGBEE == 1)
    TXGAIN_ZB,
#endif
    NUM_TXGAIN_TYPE,

#if (SUPPORT_LEGACY == 1)
    TXGAIN_LEGACY_MAX = TXGAIN_EDR_3M + 1,
#endif
    TXGAIN_LE_MAX = TXGAIN_LE_2M_2480 + 1,
#if (SUPPORT_ZIGBEE == 1)
    TXGAIN_ZB_MAX = TXGAIN_ZB + 1,
#endif

    TXGAIN_TYPE_INVALID = 0xFF,
} TXGAIN_TYPE;

/* AFC */
typedef enum
{
    AFC_EN_WHEN_RF_OFF_TO_STANDBY   = BIT0,
    AFC_EN_WHEN_RF_0x3F_SET         = BIT1,
    AFC_EN_WHEN_RF_0x3F_CHANGE      = BIT2,
    AFC_EN_WHEN_RF_CHANNEL_CHANGE   = BIT3,
    AFC_EN_WHEN_RF_OFF_TO_TX        = BIT4,
} AFC_OPTION;

/*============================================================================*
 *                              Variables
 *============================================================================*/
/* dummy function for lowerstack compile */
extern void (*set_rfc_pi_write_lock)(bool);

/* RFC register */
extern uint16_t (*rfc_reg_read)(uint8_t);
extern void (*rfc_reg_write)(uint8_t, uint16_t);
extern void (*rfc_reg_update)(uint8_t, uint16_t, uint16_t);

/* AFC */
extern void (*rfc_set_afc_option)(AFC_OPTION, bool);
extern AFC_OPTION(*rfc_get_afc_option)(void);
/*============================================================================*
 *                              Functions
 *============================================================================*/
bool rfc_check_rf_mode_valid(RF_MODE rf_mode);

#ifdef __cplusplus
}
#endif

#endif /* _RFC_H_ */

