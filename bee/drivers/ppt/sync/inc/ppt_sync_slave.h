/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Add Includes here */
#include <ppt_sync.h>

/** @addtogroup PPT_SYNC_SLAVE_Driver
  * @{
  */

/** @defgroup PPT_SYNC_SLAVE_Driver_Exported_Macros Exported Macros
  * @brief
  * @{
  */


/** @} End of PPT_SYNC_SLAVE_Driver_Exported_Macros */

/** @defgroup PPT_SYNC_SLAVE_Driver_Exported_Types Exported Types
  * @brief
  * @{
  */

/** @} End of PPT_SYNC_SLAVE_Driver_Exported_Types */

/** @defgroup PPT_SYNC_SLAVE_Driver_Exported_Functions Exported Functions
  * @brief
  * @{
  */

/**
  * @brief initialize the protocol
  *
  * The protocol will initiate some default settings.
  * After initialization, the app can set some parameters before @ref sync_slave_enable to the value they like.
  * @return none
  */
void sync_slave_init(void);

/**
  * @brief enable the protocol
  *
  * It shall be called after @ref sync_slave_init to enable the protocol.
  * @return none
  */
void sync_slave_enable(void);
/**
  * @brief start pairing
  *
  * After pairing, the slave will connect the master and bonded together.
  * The pairing result is notified at the event callback registered by @ref sync_event_cb_reg.
  * @return operation result
  */
sync_err_code_t sync_slave_pair(void);

/**
  * @brief start connect
  *
  * If two bonded devices are disconnected, call this api to connect each other.
  * The connection result is notified at the event callback registered by @ref sync_event_cb_reg.
  * @param[in] bond_info: bond information used to create a connection
  * @return operation result
  */
sync_err_code_t sync_slave_connect(sync_bond_info_t *bond_info);

/**
  * @brief stop the connection or the pairing procedure
  *
  * If the device is connecting, pairing or connected, call this api to stop.
  * @return none
  */
void sync_slave_stop(void);

/**
  * @brief deinitiate the protocol to release all resources
  *
  * If the device is running, the api @ref sync_slave_stop shall be called before this.
  * @return none
  */
void sync_slave_deinit(void);

/**
  * @brief initialize the sync protocol dlps setting
  * @return none
  */
void sync_slave_dlps_init(void);

/** @} End of PPT_SYNC_SLAVE_Driver_Exported_Functions */

/** @} End of PPT_SYNC_SLAVE_Driver */
