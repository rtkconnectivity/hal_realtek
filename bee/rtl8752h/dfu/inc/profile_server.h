/**
*****************************************************************************************
*     Copyright(c) 2016, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file     profile_server.h
  * @brief    Header file for server structure.
  * @details  Common data structure definition.
  * @author
  * @date     2017-02-18
  * @version  v1.0
  * *************************************************************************************
  */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef PROFILE_SERVER_H
#define PROFILE_SERVER_H

#ifdef  __cplusplus
extern "C" {
#endif      /* __cplusplus */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "bt_types.h"
#include "gap.h"
// #include "gatt.h"
// #include "gap_le.h"


/** @addtogroup GATT_SERVER_API GATT Server API
  * @brief GATT Server API
  * @{
  */
/*============================================================================*
 *                         Macros
 *============================================================================*/
/** @defgroup GATT_SERVER_Exported_Macros GATT Server Exported Macros
  * @brief
  * @{
  */

/** @defgroup General_Service_ID General Service ID
  * @brief Service ID for general profile events.
  * @{
  */
#define SERVICE_PROFILE_GENERAL_ID  0xff
/** @} */

/** End of GATT_SERVER_Exported_Macros
  * @}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** @defgroup GATT_SERVER_Exported_Types GATT Server Exported Types
  * @brief
  * @{
  */

typedef uint8_t T_SERVER_ID;    //!< Service ID

/** @brief  GATT write data type*/
typedef enum
{
    WRITE_REQUEST,                      /**< Write request. */
    WRITE_WITHOUT_RESPONSE,             /**< Write without response. */
    WRITE_SIGNED_WITHOUT_RESPONSE,      /**< Signed write without response. */
    WRITE_LONG,                         /**< Write long request. */
} T_WRITE_TYPE;

/** @brief  GATT PDU type*/
typedef enum
{
    GATT_PDU_TYPE_ANY           = 0x00, /**<  Any PDU type. */
    GATT_PDU_TYPE_NOTIFICATION  = 0x01, /**<  Notification PDU type. */
    GATT_PDU_TYPE_INDICATION    = 0x02  /**<  Indication PDU type. */
} T_GATT_PDU_TYPE;

/** @brief Event type to inform APP*/
typedef enum
{
    SERVICE_CALLBACK_TYPE_INDIFICATION_NOTIFICATION = 1,    /**< CCCD update event. */
    SERVICE_CALLBACK_TYPE_READ_CHAR_VALUE = 2,              /**< client read event. */
    SERVICE_CALLBACK_TYPE_WRITE_CHAR_VALUE = 3,             /**< client write event. */
} T_SERVICE_CALLBACK_TYPE;

/** @brief service reg mode, only be used when: @ref GAP_INIT_STATE_STACK_READY. */
typedef enum
{
    SERVICE_REG_MODE_ADD_TO_STACK = 0,    /**< Default mode. Add service to Bluetooth Host.
    When transitioning from SERVICE_REG_MODE_ADD_TO_TABLE to SERVICE_REG_MODE_ADD_TO_STACK, services in the table that have not been registered will be registered to the Bluetooth Host.
    When in this mode, only one new service can be added to the table and registered to the Bluetooth Host at one time. */
    SERVICE_REG_MODE_ADD_TO_TABLE = 1,    /**< Add services to the table. */
} T_SERVICE_REG_MODE;

/** @defgroup GATT_SERVER_COMMON_CB_DATA Server Common Callback Data
  * @brief Data for profile to inform application.
  * @{
  */
/** @brief Event ID */
typedef enum
{
    PROFILE_EVT_SRV_REG_COMPLETE,              /**< Services register complete event
    when application calls server_add_service before calling gap_start_bt_stack. */
    PROFILE_EVT_SEND_DATA_COMPLETE,            /**< Notification or indication data send complete event. */
    PROFILE_EVT_SRV_REG_AFTER_INIT_COMPLETE,   /**< Services register complete event
    when application calls server_add_service after receiving @ref GAP_INIT_STATE_STACK_READY. */
    PROFILE_EVT_SRV_CLEAR_AFTER_INIT_COMPLETE, /**< Services clear complete event
    when application calls server_clear_service after receiving @ref GAP_INIT_STATE_STACK_READY. */
} T_SERVER_CB_TYPE;

/** @brief  The callback data of PROFILE_EVT_SRV_REG_COMPLETE. */
typedef enum
{
    GATT_SERVER_SUCCESS,  /**< Success. */
    GATT_SERVER_FAIL      /**< Fail. */
} T_SERVER_RESULT;

/** @brief  The callback data of PROFILE_EVT_SRV_REG_AFTER_INIT_COMPLETE. */
typedef struct
{
    T_SERVER_RESULT result;
    T_SERVER_ID     service_id;
    uint16_t        cause;
} T_SERVER_REG_AFTER_INIT_RESULT;

/** @brief  The callback data of PROFILE_EVT_SRV_CLEAR_AFTER_INIT_COMPLETE */
typedef struct
{
    uint16_t        cause;
    uint16_t        svc_changed_char_cccd_handle; /**< 0x0000: Invalid handle. */
} T_SERVER_CLEAR_SERVICE_AFTER_INIT_RESULT;

/** End of GATT_SERVER_COMMON_CB_DATA
  * @}
  */

/** @defgroup GATT_SERVER_CB_DATA Server Callback Data
  * @brief Data for profile to inform application.
  * @{
  */
/** @brief The callback data of PROFILE_EVT_SEND_DATA_COMPLETE. */
typedef struct
{
    uint16_t        credits;
    uint8_t         conn_id;
    T_SERVER_ID     service_id;
    uint16_t        attrib_idx;
    uint16_t        cause;
} T_SEND_DATA_RESULT;

/** @brief Service callback data. */
typedef union
{
    T_SERVER_RESULT     service_reg_result;
    T_SEND_DATA_RESULT  send_data_result;
    T_SERVER_REG_AFTER_INIT_RESULT    server_reg_after_init_result;
    T_SERVER_CLEAR_SERVICE_AFTER_INIT_RESULT  clear_service_after_init_result;
} T_SERVER_CB_DATA;

typedef struct
{
    T_SERVER_CB_TYPE   eventId;
    T_SERVER_CB_DATA   event_data;
} T_SERVER_APP_CB_DATA;
/** End of GATT_SERVER_CB_DATA
  * @}
  */

/** @defgroup P_FUN_WRITE_IND_POST_PROC Write Post Function Point Definition
  * @brief Callback function to execute some post procedure after handling write requests from clients.
  * @{
  */
typedef void (* P_FUN_WRITE_IND_POST_PROC)(uint8_t conn_id, T_SERVER_ID service_id,
                                           uint16_t attrib_index, uint16_t length,
                                           uint8_t *p_value);
/** End of P_FUN_WRITE_IND_POST_PROC
  * @}
  */

/** @defgroup P_FUN_SERVER_SPECIFIC_CB Specific Service Callback Function Point Definition
  * @{ Function pointer used in each specific service module, to send events to specific service modules.
  */
typedef T_APP_RESULT(*P_FUN_GATT_READ_ATTR_CB)(uint8_t conn_id, T_SERVER_ID service_id,
                                               uint16_t attrib_index,
                                               uint16_t offset, uint16_t *p_length, uint8_t **pp_value);
typedef T_APP_RESULT(*P_FUN_GATT_WRITE_ATTR_CB)(uint8_t conn_id, T_SERVER_ID service_id,
                                                uint16_t attrib_index, T_WRITE_TYPE write_type,
                                                uint16_t length, uint8_t *p_value, P_FUN_WRITE_IND_POST_PROC *p_write_post_proc);
typedef void (*P_FUN_GATT_CCCD_UPDATE_CB)(uint8_t conn_id, T_SERVER_ID service_id,
                                          uint16_t attrib_index, uint16_t ccc_bits);
/** End of P_FUN_SERVER_SPECIFIC_CB
  * @}
  */

/** @defgroup P_FUN_SERVER_GENERAL_CB General Server Callback Function Point Definition
  * @brief Function pointer type used to generate callbacks, to send events to applications.
  * @{
  */
typedef T_APP_RESULT(*P_FUN_SERVER_GENERAL_CB)(T_SERVER_ID service_id, void *p_para);
/** End of P_FUN_SERVER_GENERAL_CB
  * @}
  */

/** @brief GATT service callbacks. */
typedef struct
{
    P_FUN_GATT_READ_ATTR_CB read_attr_cb;     /**< Read callback function pointer.
                                                   Return value: @ref T_APP_RESULT. */
    P_FUN_GATT_WRITE_ATTR_CB write_attr_cb;   /**< Write callback function pointer.
                                                   Return value: @ref T_APP_RESULT. */
    P_FUN_GATT_CCCD_UPDATE_CB cccd_update_cb; /**< Update CCCD callback function pointer. */
} T_FUN_GATT_SERVICE_CBS;

/** End of GATT_SERVER_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** @defgroup GATT_SERVER_Exported_Functions GATT Server Exported Functions
  * @brief
  * @{
  */

/**
 * @brief Initialize parameters of GATT Server.
 *
 * @param[in] service_num Set the number of services that need to register.
 * @return void.
 *
 * <b>Example usage</b>
 * \code{.c}
    void app_le_profile_init(void)
    {
        server_init(service_num);
    }
 * \endcode
 */
void server_init(uint8_t service_num);

/**
 * @brief Register built-in services including GAP and GATT services.
 *
 * If the application does not need to register GAP and GATT services,
 * the application shall call server_builtin_service_reg(false) before server_init().
 *
 * @param[in] reg Whether to register built-in services. The default value is true.
 * @return void.
 *
 * <b>Example usage</b>
 * \code{.c}
    void app_le_profile_init(void)
    {
        server_builtin_service_reg(false);
        server_init(service_num);
        simp_srv_id = simp_ble_service_add_service(app_profile_callback);
        server_register_app_cb(app_profile_callback);
    }
 * \endcode
 */
void server_builtin_service_reg(bool reg);

/**
 * @brief Register specific service without start handle.
 *
 * Add specific service information to gatt_svc_table struct, will be registered to GATT later.
 *
 * @param[in,out] p_out_service_id     Service ID of specific service.
 * @param[in] p_database            Database pointer of specific service.
 * @param[in] length                Length of Database of specific service.
 * @param[in] srv_cbs               Service callback functions of specific service.
 * @retval true Add service success.
 * @retval false Add service failed.
 *
 * <b>Example usage</b>
 * \code{.c}
    T_SERVER_ID bas_add_service(void *p_func)
    {
        T_SERVER_ID service_id;
        if (false == server_add_service(&service_id,
                                       (uint8_t *)bas_attr_tbl,
                                       bas_attr_tbl_size,
                                       bas_cbs))
        {
            APP_PRINT_ERROR1("bas_add_service: service_id %d", service_id);
            service_id = 0xff;
        }
        pfn_bas_cb = (P_FUN_SERVER_GENERAL_CB)p_func;
        return service_id;
    }
 * \endcode
 */
bool server_add_service(T_SERVER_ID *p_out_service_id, uint8_t *p_database, uint16_t length,
                        const T_FUN_GATT_SERVICE_CBS srv_cbs);

/**
 * @brief Register specific service with start handle.
 *
 * Add specific service information to gatt_svc_table struct, will be registered to GATT later.
 *
 * @param[in,out] p_out_service_id     Service ID of specific service.
 * @param[in] p_database            Database pointer of specific service.
 * @param[in] length                Length of Database of specific service.
 * @param[in] srv_cbs               Service callback functions of specific service.
 * @param[in] start_handle          Start handle of this service.
 * @retval true Add service success.
 * @retval false Add service failed.
 *
 * <b>Example usage</b>
 * \code{.c}
    T_SERVER_ID bas_add_service(void *p_func)
    {
        T_SERVER_ID service_id;
        if (false == server_add_service_by_start_handle(&service_id,
                                       (uint8_t *)bas_attr_tbl,
                                       bas_attr_tbl_size,
                                       bas_cbs, 0x00f0))
        {
            APP_PRINT_ERROR1("bas_add_service: service_id %d", service_id);
            service_id = 0xff;
        }
        pfn_bas_cb = (P_FUN_SERVER_GENERAL_CB)p_func;
        return service_id;
    }
 * \endcode
 */
bool server_add_service_by_start_handle(uint8_t *p_out_service_id, uint8_t *p_database,
                                        uint16_t length,
                                        const T_FUN_GATT_SERVICE_CBS srv_cbs, uint16_t start_handle);
/**
 * @brief Register callback function to send events to application.
 *
 * @param[in] p_fun_cb          Callback function.
 * @return void.
 *
 * <b>Example usage</b>
 * \code{.c}
    void app_le_profile_init(void)
    {
        server_init(service_num);
        simp_srv_id = simp_ble_service_add_service(app_profile_callback);
        server_register_app_cb(app_profile_callback);
    }
 * \endcode
 */
void server_register_app_cb(P_FUN_SERVER_GENERAL_CB p_fun_cb);

/**
  * @brief  Confirm from application when receiving a read request from client.
  * @param[in]  conn_id       Connection ID indicates which link it is.
  * @param[in]  service_id    Service ID.
  * @param[in]  attrib_index  Attribute index of attribute to read confirm from application.
  * @param[in]  p_data        Point to the read value.
  * @param[in]  length        The length of the data.
  * @param[in]  cause         Cause for read confirm. @ref T_APP_RESULT.
  * @retval true: Confirm from APP success.
  * @retval false: Confirm from APP failed.
  */
bool server_attr_read_confirm(uint8_t conn_id, T_SERVER_ID service_id, uint16_t attrib_index,
                              uint8_t *p_data, uint16_t length, T_APP_RESULT cause);
/**
  * @brief  Confirm from application when receiving an Execute Write Request from the client.
  * @param[in]  conn_id     Connection ID indicates which link it is.
  * @param[in]  cause       Cause for execute write confirm. @ref T_APP_RESULT.
  * @param[in]  handle      GATT attribute handle.
  * @retval true: Confirm from APP success.
  * @retval false: Confirm from APP failed.
  */
bool server_exec_write_confirm(uint8_t conn_id, uint16_t cause, uint16_t handle);

/**
  * @brief  Confirm from application when receiving a Write Request from the client.
  * @param[in]  conn_id      Connection ID indicates which link it is.
  * @param[in]  service_id   Service ID.
  * @param[in]  attrib_index Attribute index of attribute to write confirm from application.
  * @param[in]  cause        Write request APP handle result, APP_RESULT_SUCCESS or other. @ref T_APP_RESULT.
  * @retval true: Confirm from APP success.
  * @retval false: Confirm from APP failed.
  */
bool server_attr_write_confirm(uint8_t conn_id, T_SERVER_ID service_id,
                               uint16_t attrib_index, T_APP_RESULT cause);

/**
 * @brief Send characteristic value to peer device.
 *
 * @param[in] conn_id         Connection ID indicates which link it is.
 * @param[in] service_id      Service ID.
 * @param[in] attrib_index    Attribute index of characteristic.
 * @param[in] p_data          Point to data to be sent.
 * @param[in] data_len        Length of value to be sent, range: 0~(mtu_size - 3).
                              uint16_t mtu_size is acquired by le_get_conn_param(GAP_PARAM_CONN_MTU_SIZE, &mtu_size, conn_id).
 * @param[in] type            GATT pdu type.
 * @return Data sent result.
 * @retval true Success.
 * @retval false Failed.
 *
 * <b>Example usage</b>
 * \code{.c}
    bool bas_battery_level_value_notify(uint8_t conn_id, uint8_t service_id, uint8_t battery_level)
    {
        return server_send_data(conn_id, service_id, GATT_SVC_BAS_BATTERY_LEVEL_INDEX, &battery_level,
                                sizeof(battery_level), GATT_PDU_TYPE_ANY);
    }
 * \endcode
 */
bool server_send_data(uint8_t conn_id, T_SERVER_ID service_id, uint16_t attrib_index,
                      uint8_t *p_data, uint16_t data_len, T_GATT_PDU_TYPE type);

/**
 * @brief Get the header point of the write command data buffer.
 * This function is used to get the buffer point of the write command data.
 * This function only can be called in write_attr_cb.
 *
 * @param[in]     conn_id     Connection ID indicates which link it is.
 * @param[in,out] pp_buffer   Pointer to the address of the buffer.
 * @param[in,out] p_offset    Pointer to the offset of the data.
 * @return Buffer get result.
 * @retval true Success.
 * @retval false Failed.
 *
 * <b>Example usage</b>
 * \code{.c}
    uint8_t *p_data_buf;
    uint16_t data_offset;
    T_APP_RESULT simp_ble_service_attr_write_cb(uint8_t conn_id, T_SERVER_ID service_id,
                                            uint16_t attrib_index, T_WRITE_TYPE write_type, uint16_t length, uint8_t *p_value,
                                            P_FUN_WRITE_IND_POST_PROC *p_write_ind_post_proc)
    {
        ......
        server_get_write_cmd_data_buffer(conn_id, &p_data_buf, &data_offset);
        return APP_RESULT_NOT_RELEASE;
    }
    void release(void)
    {
        if(p_data_buf != NULL)
        {
            gap_buffer_free(p_data_buf);
            p_data_buf = NULL;
        }
    }
 * \endcode
 */
bool server_get_write_cmd_data_buffer(uint8_t conn_id, uint8_t **pp_buffer, uint16_t *p_offset);

/**
 * @brief Get the start handle of the service.
 *
 * @param[in] service_id Service ID.
 * @return Start handle.
 * @retval 0 Failed.
 * @retval other Success.
 *
 * <b>Example usage</b>
 * \code{.c}
    void test(void)
    {
        uint16_t start_handle = server_get_start_handle(service_id);
    }
 * \endcode
 */
uint16_t server_get_start_handle(T_SERVER_ID service_id);

/**
 * @brief Clear service.
 *
 * @note This function can only be used when:
 *                  standby state (i.e., no link, not initiating, etc.), and @ref GAP_INIT_STATE_STACK_READY, and not add service.
 *
 * If sending request operation is success, the result of clear service will be returned by callback depends on APP: \n
 *                   Default or APP use server_cfg_use_ext_api(false):
 *                         callback registered by @ref server_register_app_cb with eventId @ref PROFILE_EVT_SRV_CLEAR_AFTER_INIT_COMPLETE. \n
 *                   APP use server_cfg_use_ext_api(true):
 *                         callback registered by @ref server_ext_register_app_cb with eventId @ref PROFILE_EVT_SRV_CLEAR_AFTER_INIT_COMPLETE.
 *
 * If clear service operation is success and APP not clear bond info: \n
 *                   APP clear CCCD except CCCD of Service Changed characteristic. \n
 *                   APP send Indication of Service Changed after reconnection.
 *
 * @return Send request operation.
 * @retval true  Send request operation success.
 * @retval false Send request operation failure.
 *
 * <b>Example usage</b>
 * \code{.c}
    void test(void)
    {
        server_clear_service();
    }

    // Default or APP use server_cfg_use_ext_api(false): callback registered by @ref server_register_app_cb
    T_APP_RESULT app_profile_callback(T_SERVER_ID service_id, void *p_data)
    {
        ......
        if (service_id == SERVICE_PROFILE_GENERAL_ID)
        {
            T_SERVER_APP_CB_DATA *p_param = (T_SERVER_APP_CB_DATA *)p_data;
            switch (p_param->eventId)
            {
            case PROFILE_EVT_SRV_CLEAR_AFTER_INIT_COMPLETE:
                APP_PRINT_INFO2("app_profile_callback: PROFILE_EVT_SRV_CLEAR_AFTER_INIT_COMPLETE, cause 0x%x, svc_changed_char_cccd_handle 0x%x",
                                p_param->event_data.clear_service_after_init_result.cause,
                                p_param->event_data.clear_service_after_init_result.svc_changed_char_cccd_handle);
                ......
                break;
        ......
    }

    // APP use server_cfg_use_ext_api(true): callback registered by @ref server_ext_register_app_cb
    T_APP_RESULT app_profile_ext_callback(T_SERVER_ID service_id, void *p_data)
    {
        ......
        if (service_id == SERVICE_PROFILE_GENERAL_ID)
        {
            T_SERVER_EXT_APP_CB_DATA *p_param = (T_SERVER_EXT_APP_CB_DATA *)p_data;
            switch (p_param->eventId)
            {
            case PROFILE_EVT_SRV_CLEAR_AFTER_INIT_COMPLETE:
                APP_PRINT_INFO2("app_profile_ext_callback: PROFILE_EVT_SRV_CLEAR_AFTER_INIT_COMPLETE, cause 0x%x, svc_changed_char_cccd_handle 0x%x",
                                p_param->event_data.clear_service_after_init_result.cause,
                                p_param->event_data.clear_service_after_init_result.svc_changed_char_cccd_handle);
                ......
                break;
            ......
    }
 * \endcode
 */
bool server_clear_service(void);

/**
 * @brief Set service reg mode.
 *
 * @note This function can only be used when:
 *                  @ref GAP_INIT_STATE_STACK_READY, and not add service.
 *
 * If mode is @ref SERVICE_REG_MODE_ADD_TO_TABLE, setting operation result will be returned.
 *
 * If mode is @ref SERVICE_REG_MODE_ADD_TO_STACK, setting operation result will be returned. \n
 *               If result is true, and p_num is not zero, the result of registering services
 *               will be returned by callback depends on APP:
 *                   callback registered by @ref server_register_app_cb with eventId @ref PROFILE_EVT_SRV_REG_AFTER_INIT_COMPLETE,
 *                   when register single or multi services complete, return the last service ID.
 *
 * @param[in]     mode  Service reg mode, @ref T_SERVICE_REG_MODE.
 * @param[in,out] p_num Pointer to the num of services in table have not been registered to Bluetooth Host.
                        Only when mode is @ref SERVICE_REG_MODE_ADD_TO_STACK and result is true, the value is valid.
 * @return Set mode result.
 * @retval true  Set mode success.
 * @retval false Set mode failure.
 *
 * <b>Example usage</b>
 * \code{.c}
    void test(void)
    {
      bool ret = server_set_service_reg_mode(SERVICE_REG_MODE_ADD_TO_TABLE, p_num);

      //add multiple service to table
      bas_srv_id = bas_add_service(app_profile_callback);
      hid_srv_id = hids_add_service(app_profile_callback);
      ......
      ret = server_set_service_reg_mode(SERVICE_REG_MODE_ADD_TO_STACK, p_num);
    }

    T_APP_RESULT app_profile_callback(T_SERVER_ID service_id, void *p_data)
    {
        ......
        if (service_id == SERVICE_PROFILE_GENERAL_ID)
        {
          T_SERVER_APP_CB_DATA *p_param = (T_SERVER_APP_CB_DATA *)p_data;

          switch (p_param->eventId)
          {
            //srv register result event.
            case PROFILE_EVT_SRV_REG_AFTER_INIT_COMPLETE:
            APP_PRINT_INFO3("app_profile_callback: PROFILE_EVT_SRV_REG_AFTER_INIT_COMPLETE: result %d, service id 0x%x, cause 0x%x",
                            p_param->event_data.server_reg_after_init_result.result,
                            //When register multi services complete, return the last service id.
                            p_param->event_data.server_reg_after_init_result.service_id,
                            p_param->event_data.server_reg_after_init_result.cause);
              ......
              break;
          ......
    }
 * \endcode
 */
bool server_set_service_reg_mode(uint8_t mode, uint8_t *p_num);

/** End of GATT_SERVER_Exported_Functions
  * @}
  */

/** End of GATT_SERVER_API
  * @}
  */


#ifdef  __cplusplus
}
#endif      /*  __cplusplus */

#endif /* PROFILE_SERVER_H */
