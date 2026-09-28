/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef _BLE_ADV_H_
#define _BLE_ADV_H_

#include "gap_le.h"
#include "gap_msg.h"

#ifdef __cplusplus
extern "C" {
#endif

///@cond

/** @defgroup BLE_ADV Ble Adv
  * @brief Ble ADV manager module
  * @{
  */


/*============================================================================*
 *                              Macros
 *============================================================================*/
/** @defgroup BLE_ADV_Exported_Macros Ble Adv Macros
  * @{
  */

#define BLE_ADV_STATE_CHANGE 0x01 /**< Used to notify ADV set application callback function about the change of ADV state. */
#define BLE_ADV_MGR_VERSION   1 /**< Used to set ble ADV manager module version. */

/** End of BLE_ADV_Exported_Macros
  * @}
  */

/*============================================================================*
 *                              Types
 *============================================================================*/
/** @defgroup BLE_ADV_Exported_Types Ble Adv Types
  * @{
  */

/**
  * @brief Define application ADV sate, for application only have two ADV state :BLE_ADV_STATE_IDLE or BLE_ADV_STATE_ADVERTISING
  */
typedef enum
{
    BLE_ADV_STATE_IDLE, /**< When call API le_adv_mgr_disable or le_adv_mgr_disable_all, the application ADV state shall be set to BLE_ADV_STATE_IDLE. */
    BLE_ADV_STATE_ADVERTISING, /**< When call API  le_adv_mgr_enable or le_adv_mgr_enable_two, the application ADV state shall be set to BLE_ADV_STATE_ADVERTISING. */
} T_BLE_ADV_STATE;

/**
 * @brief define the reason of  ADV stop
 */
typedef enum
{
    BLE_ADV_STOP_CAUSE_UNKNOWN,
    BLE_ADV_STOP_CAUSE_APP,
    BLE_ADV_STOP_CAUSE_CONN,
    BLE_ADV_STOP_CAUSE_TIMEOUT,
} T_BLE_ADV_STOP_CAUSE;

/**
 * @brief used to notify application callback function about the change of ADV state
 */
typedef struct
{
    uint8_t adv_handle;
    T_BLE_ADV_STATE state;
    T_BLE_ADV_STOP_CAUSE stop_cause; /**< Used when: BLE_ADV_STATE_IDLE. */
    uint8_t app_cause; /**< Used when: BLE_ADV_STATE_IDLE(BLE_ADV_STOP_CAUSE_APP). */
    uint8_t conn_id;  /**< Used when: BLE_ADV_STATE_IDLE(BLE_ADV_STOP_CAUSE_CONN). */
} T_BLE_ADV_STATE_CHANGE;

/**
 * @brief T_BLE_ADV_CB_DATA  @ref T_BLE_ADV_STATE_CHANGE
 */
typedef union
{
    T_BLE_ADV_STATE_CHANGE *p_ble_state_change;
} T_BLE_ADV_CB_DATA;

/** End of BLE_ADV_Exported_Types
  * @}
  */

/*============================================================================*
 *                              Functions
 *============================================================================*/
/** @defgroup BLE_ADV_Exported_Functions Ble Adv Functions
  * @{
  */

/**
 * @brief    Allocate storage space for ble_adv_set_table,the size of ble_adv_set_table = ble_adv_handle_num_max * sizeof(T_LE_ADV_SET)
 * @note     This API shall be used first if you want to use the module of ble_adv_mgr
 * @param[in] adv_handle_num The maximum of ble ADV handle, each ADV set has a ADV handle.
 * @return   @ref T_GAP_CAUSE.
 * @retval   GAP_CAUSE_SUCCESS   Success.
 * @retval   GAP_CAUSE_INVALID_PARAM   The adv_handle_num is 0.
 * @retval   GAP_CAUSE_NO_RESOURCE   No space in OS_MEM_TYPE_DATA to allocate.
 */
T_GAP_CAUSE ble_adv_mgr_init(uint8_t adv_handle_num);

/**
 * @brief     Used to handle @ref T_GAP_DEV_STATE
 * @param[in]  new_state  New AD state: @ref T_GAP_DEV_STATE.
 * @param[in]  cause      Cause.
 */
void ble_adv_mgr_handle_adv_state(T_GAP_DEV_STATE new_state, uint16_t cause);

/**
 * @brief     Used to handle gap callback msg @ref T_LE_CB_DATA
 * @param[in] cb_type Callback type.
 * @param[in] p_data  Pointer to callback data: @ref T_LE_CB_DATA.
 * @return   @ref T_APP_RESULT.
 * @retval   APP_RESULT_SUCCESS Success.
 * @retval   Others             Failed.
 */
T_APP_RESULT ble_adv_mgr_handle_gap_callback(uint8_t cb_type, T_LE_CB_DATA *p_data);

/**
 * @brief    Create ADV handle and register app callback
 * @note     This API is used to create ADV handle for an unused ADV set.
 * @param[in] app_callback Application callback function which want to be registered into ADV set.
 * @return   adv_handle.
 * @retval  0xFF:    All ADV set has been used in ble_adv_set_table or le_adv_mgr_init not called before this API.
 * @retval  other values: the created ADV handle
 */
uint8_t ble_adv_mgr_create_adv_handle(P_FUN_GAP_APP_CB app_callback);

/**
 * @brief    Set ADV parameters into ADV set
 * @note     This API is used to set ADV parameters into ADV set, the ADV set was found by ADV handle.
 *           If there Only one ADV set is enabled, and p_adv->action is BLE_ADV_ACTION_RUNNING then set p_adv->action = BLE_ADV_ACTION_UPDATE
 *           to update ADV param in ble_adv_mgr_check_next_step.
 * @param[in] adv_handle         Identify an advertising set.
 * @param[in] adv_type           @ref T_GAP_ADTYPE.
 * @param[in] adv_interval_min   Minimum advertising interval.
 * @param[in] adv_interval_max   Maximum advertising interval.
 * @param[in] own_address_type   @ref T_GAP_LOCAL_ADDR_TYPE.
 * @param[in] peer_address_type  @ref T_GAP_REMOTE_ADDR_TYPE.
 * @param[in] p_peer_address     If not used, set default value NULL.
 * @param[in] filter_policy      @ref T_GAP_ADV_FILTER_POLICY.
 * @return   @ref T_GAP_CAUSE.
 * @retval  GAP_CAUSE_NOT_FIND  le_adv_mgr_set_adv_param: not find.
 * @retval  GAP_CAUSE_SUCCESS  le_adv_mgr_set_adv_param: success.
 */
T_GAP_CAUSE ble_adv_mgr_set_adv_param(uint8_t adv_handle, T_GAP_ADTYPE adv_type,
                                      uint16_t adv_interval_min, uint16_t adv_interval_max,
                                      T_GAP_LOCAL_ADDR_TYPE own_address_type,
                                      T_GAP_REMOTE_ADDR_TYPE peer_address_type, uint8_t *p_peer_address,
                                      T_GAP_ADV_FILTER_POLICY filter_policy);

/**
 * @brief    Change advertising interval
 * @param[in] adv_handle       Identify an advertising set.
 * @param[in] adv_interval     ADV interval.
 * @return   @ref T_GAP_CAUSE.
 * @retval  GAP_CAUSE_NOT_FIND   Not find.
 * @retval  GAP_CAUSE_SUCCESS  Success.
 */
T_GAP_CAUSE ble_adv_mgr_change_adv_interval(uint8_t adv_handle, uint16_t adv_interval);

/**
 * @brief    Set ADV data into ADV set
 * @note     This API is used to set ADV data into ADV set, the ADV set was found by ADV handle.
 *           If there Only one ADV set is enabled, and p_adv->action is BLE_ADV_ACTION_RUNNING then set p_adv->action = BLE_ADV_ACTION_UPDATE
 *           to update ADV data in ble_adv_mgr_check_next_step.
 * @param[in] adv_handle     Identify an advertising set.
 * @param[in] adv_data_len   Length of advertising data.
 * @param[in] p_adv_data     Pointer to advertising data.
 * @return   @ref T_GAP_CAUSE.
 * @retval  GAP_CAUSE_NOT_FIND  le_adv_mgr_set_adv_data: not find.
 * @retval  GAP_CAUSE_SUCCESS  le_adv_mgr_set_adv_data: success.
 */
T_GAP_CAUSE ble_adv_mgr_set_adv_data(uint8_t adv_handle, uint16_t adv_data_len,
                                     uint8_t *p_adv_data);

/**
 * @brief    Set scan response data
 * @param[in] scan_data_len   Length of scan response data.
 * @param[in] p_scan_data     Pointer to scan response data.
 * @return   @ref T_GAP_CAUSE.
 */
T_GAP_CAUSE ble_adv_mgr_set_scan_response_data(uint16_t scan_data_len, uint8_t *p_scan_data);

/**
 * @brief    Set random address into ADV set
 * @note     This API is used to set random address into ADV set, the ADV set was found by ADV handle.
 *           If there Only one ADV set is enabled, and p_adv->action is BLE_ADV_ACTION_RUNNING then set p_adv->action = BLE_ADV_ACTION_UPDATE
 *           to update random address in ble_adv_mgr_check_next_step.
 * @param[in] adv_handle       Identify an advertising set.
 * @param[in] random_address   Random address.
 * @return   @ref T_GAP_CAUSE.
 * @retval  GAP_CAUSE_NOT_FIND: le_adv_mgr_set_random: not find
 * @retval  GAP_CAUSE_SUCCESS: le_adv_mgr_set_random: success
 */
T_GAP_CAUSE ble_adv_mgr_set_random(uint8_t adv_handle, uint8_t *random_address);

/**
 * @brief    Enable one ADV set
 * @note     This API is used to enbale conn ADV set or unconn ADV set.
 * @param[in] adv_handle Identify an advertising set.
 * @param[in] duration   If non-zero, indicates the duration that advertising set is enabled.
 * \arg                  0x0000:        No advertising duration.
 * \arg                  0x0001-0xFFFF: Advertising duration, in units of 10ms.
 * @return   @ref T_GAP_CAUSE.
 * @retval  GAP_CAUSE_NOT_FIND  p_adv == NULL.
 * @retval  GAP_CAUSE_SUCCESS  Success.
 */
T_GAP_CAUSE ble_adv_mgr_enable(uint8_t adv_handle, uint32_t duration);

/**
 * @brief    Enable two ADV set
 * @note     This API is used to enable connectable ADV set and unconnectable ADV set.
 * @param[in] conn_adv_handle     ADV handle for connectable ADV set.
 * @param[in] nonconn_adv_handle  ADV handle for unconnectable ADV set.
 * @param[in] duration   If non-zero, indicates the duration that advertising set is enabled.
 * \arg                  0x0000:        No advertising duration.
 * \arg                  0x0001-0xFFFF: Advertising duration, in units of 10ms.
 * @return   @ref T_GAP_CAUSE.
 * @retval  GAP_CAUSE_INVALID_STATE   p_conn_enabled_adv_set != NULL ||p_nonconn_enabled_adv_set != NULL.
 * @retval  GAP_CAUSE_INVALID_PARAM   ADV type error.
 * @retval  GAP_CAUSE_NOT_FIND        p_adv == NULL || p_non_conn_adv == NULL.
 * @retval  GAP_CAUSE_SUCCESS         Success.
 */
T_GAP_CAUSE ble_adv_mgr_enable_two(uint8_t conn_adv_handle, uint8_t nonconn_adv_handle,
                                   uint32_t duration);

/**
 * @brief    Disable one ADV set
 * @note     This API is used to disable conn ADV set or unconn ADV set, only one ADV set can be disabled at one time.
 * @param[in] adv_handle Identify an advertising set.
 * @param[in] app_cause  Cause from APP.
 * @return   @ref T_GAP_CAUSE.
 * @retval  GAP_CAUSE_INVALID_STATE       adv_handle not running.
 * @retval  GAP_CAUSE_NOT_FIND            p_adv == NULL.
 * @retval  GAP_CAUSE_SUCCESS             Success.
 */
T_GAP_CAUSE ble_adv_mgr_disable(uint8_t adv_handle, uint8_t app_cause);

/**
 * @brief    Disable all ADV set
 * @note     This API is used to disable conn ADV set and unconn ADV set, if both conn ADV set and unconn ADV set are enabled.
 * @param[in] app_cause  Cause from APP.
 * @return   @ref T_GAP_CAUSE.
 * @retval   GAP_CAUSE_SUCCESS     Success.
 */
T_GAP_CAUSE ble_adv_mgr_disable_all(uint8_t app_cause);

/**
 * @brief     Print info in ADV set
 */
void ble_adv_mgr_print_info(void);


/** @} */ /* End of group APP_DEVICE_Exported_Functions */
/** End of BLE_ADV
 * @}
 */
///@endcond

#ifdef __cplusplus
}
#endif

#endif /* _BLE_ADV_H_ */
