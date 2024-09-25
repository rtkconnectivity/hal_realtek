/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ppt_sync.h>

/** @addtogroup PPT_SYNC_MASTER_Driver
  * @{
  */

/** @defgroup PPT_SYNC_MASTER_Driver_Exported_Macros Exported Macros
  * @brief
  * @{
  */

#define SYNC_MASTER_HB_RHY_PERIOD_MAX   0xffffffff

/** @} End of PPT_SYNC_MASTER_Driver_Exported_Macros */

/** @defgroup PPT_SYNC_MASTER_Driver_Exported_Types Exported Types
  * @brief
  * @{
  */

/** tx scheme details */
typedef struct
{
    /** the sync interval will be aligned to the app tx interval if enabled */
    sync_feature_t tx_align;
    /** the stack will use high priority to tx if enabled */
    sync_feature_t early_high_prio;
    /** the stack will retransmit the pkt when attain the ack information if enabled */
    sync_feature_t retrans_at_ack;
    /** the stack will transmit a new pkt if available at the retransmit interval if enabled */
    sync_feature_t tx_new_at_retrans_int;
} sync_master_tx_scheme_t;

/** tx prepare callback function pointer type */
typedef void (*sync_tx_prepare_cb_t)(void);

/** @} End of PPT_SYNC_MASTER_Driver_Exported_Types */

/** @defgroup PPT_SYNC_MASTER_Driver_Exported_Functions Exported Functions
  * @brief
  * @{
  */

/**
  * @brief initialize the protocol
  *
  * The protocol will initiate some default settings.
  * After initialization, the app can set some parameters before @ref sync_master_enable to the value they like.
  * @return none
  */
void sync_master_init(void);

/**
  * @brief set heartbeat parameters
  *
  * The heartbeat supports multi-levels. At each level, there are two parameters, including interval and beat times.
  * The radio will beat in a certain interval by the designed times.
  * Except the maximum level, the heartbeat will enter next level when it beats over the limit times.
  * For level 0, the interval is the connection interval, so the interval parameter is useless.
  * For level Max(2), the heartbeat will beat all the time, so the beat_times parameter is useless.
  * @param[in] level: the heartbeat level, value range from 0 to MAX
  * @param[in] interval: the heartbeat interval in unit of microsecond
  * @param[in] beat_times: the heartbeat repeat times.
  * @return the result
  * <b>Example usage</b>
  * \code{.c}
    // sample: disable heartbeat
    sync_master_set_hb_param(0, 0, SYNC_MASTER_HB_RHY_PERIOD_MAX);

    // sample: enable heartbeat
    // set heartbeat level 0 to sync interval * 40
    sync_master_set_hb_param(0, 0, 40);
    // set heartbeat level 1 to 10ms * 200
    sync_master_set_hb_param(1, 10000, 200);
    // set heartbeat level 2 to 100ms
    sync_master_set_hb_param(2, 100000, 0);
  * \endcode
  */
bool sync_master_set_hb_param(uint8_t level, uint32_t interval, uint32_t beat_times);

/**
  * @brief wakeup heartbeat right now
  * @return true if wakeup by this call, else false
  */
bool sync_master_wakeup_hb(void);

/**
  * @brief set tx scheme
  *
  * Refer to @sync_master_tx_scheme_t for the different tx scheme.
  * @param[in] tx_scheme: the tx scheme
  * @return none
  */
void sync_master_set_tx_scheme(sync_master_tx_scheme_t tx_scheme);

/**
  * @brief register tx prepare callback which will be called at each interval
  * @param[in] cb: the function pointer
  * @return none
  */
void sync_master_reg_tx_prepare_cb(sync_tx_prepare_cb_t cb);

/**
  * @brief enable the protocol
  *
  * It shall be called after @ref sync_master_init to enable the protocol.
  * @return none
  */
void sync_master_enable(void);

/**
  * @brief start pairing
  *
  * After pairing, the master will connect the slave and bonded together.
  * The pairing result is notified at the event callback registered by @ref sync_event_cb_reg.
  * @return operation result
  */
sync_err_code_t sync_master_pair(void);

/**
  * @brief start connect
  *
  * If two bonded devices are disconnected, call this api to connect each other.
  * The connection result is notified at the event callback registered by @ref sync_event_cb_reg.
  * @param[in] bond_info: bond information used to create a connection
  * @return operation result
  */
sync_err_code_t sync_master_connect(sync_bond_info_t *bond_info);

/**
  * @brief stop the connection or the pairing procedure
  *
  * If the device is connecting, pairing or connected, call this api to stop.
  * @return none
  */
void sync_master_stop(void);

/**
  * @brief deinitiate the protocol to release all resources
  *
  * If the device is running, the api @ref sync_master_stop shall be called before this.
  * @return none
  */
void sync_master_deinit(void);

/**
  * @brief initialize the sync protocol dlps setting
  * @return none
  */
void sync_master_dlps_init(void);

/** @} End of PPT_SYNC_MASTER_Driver_Exported_Functions */

/** @} End of PPT_SYNC_MASTER_Driver */
