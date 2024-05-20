/**
*****************************************************************************************
*     Copyright(c) 2020, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file     ppt_sync.h
  * @brief    Head file for sync protocol.
  * @details  data structs and external functions declaration.
  * @author   bill
  * @date     2022-03-15
  * @version  v0.1
  * *************************************************************************************
  */

/* Add Includes here */
#include <stdbool.h>
#include <stdint.h>

#ifdef  __cplusplus
extern "C" {
#endif      /* __cplusplus */

/** @addtogroup PPT_SYNC_Driver
  * @{
  */

/** @defgroup PPT_SYNC_Driver_Exported_Macros Exported Macros
  * @brief
  * @{
  */
#define SYNC_OPCODE_APP_START_VALUE             0x10

#define SYNC_MSG_RETRANS_NUM_INFINITE           0xff
#define SYNC_SYNC_FAST_PERIOD_DISABLE           0xffffffff

/** @} End of PPT_SYNC_Driver_Exported_Macros */

/** @defgroup PPT_SYNC_Driver_Exported_Types Exported Types
  * @brief
  * @{
  */

/** error code */
typedef enum
{
    SYNC_ERR_CODE_SUCCESS,
    SYNC_ERR_CODE_UNKNOWN,
    SYNC_ERR_CODE_INVALID_LENGTH,
    SYNC_ERR_CODE_INVALID_PARAM,
    SYNC_ERR_CODE_INVALID_STATE,
    SYNC_ERR_CODE_NULL_POINTER,
    SYNC_ERR_CODE_FULL_QUEUE,
    SYNC_ERR_CODE_EMPTY_QUEUE,
    SYNC_ERR_CODE_NO_MEM,
    SYNC_ERR_CODE_NOT_FOUND
} sync_err_code_t;

#pragma pack(1)

/** access address */
typedef struct
{
    uint32_t addr;
} sync_acc_t;

/** bond information */
typedef struct
{
    sync_acc_t acc;
} sync_bond_info_t;

#pragma pack()

/** role definition */
typedef enum
{
    SYNC_ROLE_UNKNOWN,
    SYNC_ROLE_MASTER,
    SYNC_ROLE_SLAVE
} sync_role_t;

/** connect state */
typedef enum
{
    SYNC_STATE_IDLE,
    SYNC_STATE_SYNC_SLOW,
    SYNC_STATE_SYNC,
    SYNC_STATE_SYNC_FAST
} sync_state_t;

/** pair state */
typedef enum
{
    SYNC_PAIR_STATE_IDLE,
    SYNC_PAIR_STATE_PAIRING,
    SYNC_PAIR_STATE_PAIRED,
} sync_pair_state_t;

/** events triggered by the sync protocol */
typedef enum
{
    SYNC_EVENT_PAIRED,
    SYNC_EVENT_PAIR_TIMEOUT,
    SYNC_EVENT_CONNECTED,
    SYNC_EVENT_CONNECT_TIMEOUT,
    SYNC_EVENT_CONNECT_LOST,
#ifdef SYNC_DEBUG
    SYNC_EVENT_SYNC_LOST,
    SYNC_EVENT_SYNC_RECONNECTED
#endif
} sync_event_t;

/** Message types with difference performances */
typedef enum
{
    /** The message will be sent only once regardless of the ack. */
    SYNC_MSG_TYPE_ONESHOT,
    /**
     *  The message will be sent finite times even it is not acked.
     *  The retransmission will be stopped right after it is acked.
     *  Refer to @ref sync_msg_set_finite_retrans, it sets the finite retransmission times.
     */
    SYNC_MSG_TYPE_FINITE_RETRANS,
    /**
     *  The message will be sent infinite times until it is acked.
     *  The retransmission will be stopped right after it is acked.
     */
    SYNC_MSG_TYPE_INFINITE_RETRANS,
    /**
     *  Depending whether there are other messages pended, the message will be sent variable times if it is not acked.
     *  The retransmission will be stopped right after it is acked.
     *  Refer to @ref sync_msg_set_dynamic_retrans, it sets the lower and upper limitation of the retransmission times.
     *  If not acked, the message will be sent at least the lower limitation times and at most the upper limitation times.
     */
    SYNC_MSG_TYPE_DYNAMIC_RETRANS,
    SYNC_MSG_TYPE_NUM,
    SYNC_MSG_TYPE_ALL = SYNC_MSG_TYPE_NUM
} sync_msg_type_t;

/** Message transmit result */
typedef enum
{
    /** The transmitted message is received by the peer device. */
    SYNC_SEND_RESULT_ACKED,
    /** The transmitted message isn't received by the peer device. */
    SYNC_SEND_RESULT_NACKED,
    /** Don't known whether the transmitted message is received. */
    SYNC_SEND_RESULT_UNKNOWN,
    /** The transmitted message is flushed by myself. */
    SYNC_SEND_RESULT_FLUSHED
} sync_send_result_t;

/** Message transmit general information */
typedef struct
{
    sync_send_result_t res;
    /** retransmit counter */
    uint8_t retrans_count;
} sync_send_info_t;

/** Message receive general information */
typedef struct
{
    int8_t rssi;
} sync_receive_info_t;

/** Time related parameters used by the sync protocol */
typedef enum
{
    /** Synchronization Interval, unit is us */
    SYNC_TIME_PARAM_CONNECT_INTERVAL,
    /**
      * Retransmit Interval, unit is us
      * If it is equal to Synchronization Interval, there will be no chance to retransmit during the sync interval.
      * Retransmit Interval shall be a divisor of Synchronization Interval.
      * For example 1K report rate, Synchronization Interval = 1000us and  Retransmit Interval = 250us,
      * then there will be 3 times chance to retransmit in the sync interval.
      */
    SYNC_TIME_PARAM_CONNECT_INTERVAL_HIGH,
    /** Synchronization lost state life cycle, unit is us */
    SYNC_TIME_PARAM_SYNC_LOST_PERIOD,
    /** Synchronization fast state life cycle, unit is us, use value @ref SYNC_SYNC_FAST_PERIOD_DISABLE can remove synchronization fast state */
    SYNC_TIME_PARAM_SYNC_FAST_PERIOD,
    /** heartbeat timeout times used to control heartbeat exit sensitivity */
    SYNC_TIME_PARAM_HB_TO_TIMES,
    /** channel assess times used by the slave to evaluate the channel quality */
    SYNC_TIME_PARAM_CHANNEL_ASSESS_TIMES,
    /** slave hopping speed at sync low state, unit is us */
    SYNC_TIME_PARAM_SLAVE_HOPPING_SPEED
} sync_time_param_t;

/** feature value definition */
typedef enum
{
    SYNC_FEATURE_USE_DEFAULT,
    SYNC_FEATURE_ENABLE,
    SYNC_FEATURE_DISABLE
} sync_feature_t;

/**
  * @brief sync stack event notify callback
  * @param[in] event: event type
  * @return none
  */
typedef void (*sync_event_cb_t)(sync_event_t event);

/**
  * @brief sync stack message send result callback
  * @param[in] type: msg type
  * @param[in] data: the original data
  * @param[in] len: the original length
  * @param[in] result: the send result
  * @return none
  */
typedef void (*sync_msg_send_cb_t)(sync_msg_type_t type, uint8_t *data, uint16_t len,
                                   sync_send_info_t *info);

/**
  * @brief sync stack message receive callback
  * @param[in] data: the data
  * @param[in] len: the length
  * @param[in] info: the receive information pointer
  * @return none
  */
typedef void (*sync_msg_receive_cb_t)(uint8_t *data, uint16_t len, sync_receive_info_t *info);

/** heartbeat callback parameters */
typedef struct
{
    bool enter;
    uint32_t interval; //!< unit of us
} sync_hb_cb_param_t;

/**
  * @brief heartbeat callback function pointer type
  * @param[in] param: heartbeat callback parameters pointer
  * @return none
  */
typedef void (*sync_hb_cb_t)(sync_hb_cb_param_t *param);

/**
  * @brief sync stack uses this callback to request real time environment
  *
  * When the stack requires real time environment at special scenarios, the app shall try their best to provide.
  * For example, avoid using critical section, avoid entering DLPS, and increase cpu clock etc.
  * @param[in] required: true means request real time environment
  * @return none
  */
typedef void (*sync_rte_req_cb_t)(bool required);

/** @} End of PPT_SYNC_Driver_Exported_Types */

/** @defgroup PPT_SYNC_Driver_Exported_Functions Exported Functions
  * @brief
  * @{
  */

/**
  * @brief initialize the protocol
  *
  * The protocol will initiate some default settings.
  * After initialization, the app can set some parameters before @ref sync_enable to the value they like.
  * @param[in] role: the protocol role
  * @return none
  */
void sync_init(sync_role_t role);

/**
  * @brief set the crc parameters
  *
  * The protocol will initiate CRC default settings.
  * After initialization, the app can use this api to overwrite the default settings.
  * @param[in] crc_len: crc bit length
  * @param[in] crc_poly: crc poly
  * @param[in] crc_init: crc init
  * @return none
  * <b>Example usage</b>
  * \code{.c}
    // set crc8
    sync_crc_set(8, 0x07, 0xff);
    // set crc16
    sync_crc_set(16, 0x8005, 0xffff);
    // set crc24
    sync_crc_set(24, 0x00065b, 0x555555);
    // set crc32
    sync_crc_set(32, 0x04c11db7, 0xffffffff);
  * \endcode
  */
void sync_crc_set(uint8_t crc_len, uint32_t crc_poly, uint32_t crc_init);

/**
  * @brief set timing related parameters
  * @param[in] type: the parameter type
  * @param[in] time: the time value, the unit is usually us depend on the type
  * @return set result
  */
bool sync_time_set(sync_time_param_t type, uint32_t time);

/**
  * @brief get timing related parameters
  * @param[in] type: the parameter type
  * @param[out] time: the time value, the unit is usually us depend on the type
  * @return get result
  */
bool sync_time_get(sync_time_param_t type, uint32_t *time);

/**
  * @brief set rf channels
  * @param[in] chan_num: the number of rf channels
  * @param[in] group_num: the number of groups
  * @param[in] freq: the frequency array
  * @return set result
  */
bool sync_channel_set(uint8_t chan_num, uint8_t group_num, uint16_t freq[]);

/**
  * @brief set rf tx power
  *
  * If dynamic is true, the tx power will be changed automatically at the range according to the link quality.
  * If dynamic is false, the tx_power_dbm_max will be used all the time.
  * @param[in] dynamic: whether to change automatically at run time
  * @param[in] tx_power_dbm_max: maximum tx power
  * @param[in] tx_power_dbm_min: minimum tx power
  * @return set result
  */
bool sync_tx_power_set(bool dynamic, int8_t tx_power_dbm_max, int8_t tx_power_dbm_min);

/**
  * @brief turn on/off sync log
  * @param[in] level: the log level
  * @param[in] on: true: on, false: off
  * @return set result
  */
bool sync_log_set(uint8_t level, bool on);

/**
  * @brief set rssi threshold when pairing
  *
  * Only the requesting device with rssi value equal or bigger than the threshold will be accepted.
  * @param[in] rssi: the rssi level
  * @return set result
  */
bool sync_pair_rssi_set(int8_t rssi);

/**
  * @brief set time of inter-frame space (tifs)
  *
  * The tifs used at different process or sync interval may be different.
  * There are 2 levels used:
  * Level 0 is used for sync slow process and sync interval >= 500us.
  * Level 1 is used for sync interval < 500us.
  * @param[in] level: level index
  * @param[in] tifs: time of inter-frame space
  * @return set result
  */
bool sync_tifs_set(uint8_t level, uint8_t tifs);

/**
  * @brief check whether the access address is valid
  *
  * The access address is used by the hardware to match the right packet with the same access address.
  * The hardware has some limitations on the value of the access address.
  * Usually it is randomly generated and checked until it is valid.
  * @param[in] acc: the access address value
  * @return 0: valid, other: invalid
  */
int sync_acc_check(sync_acc_t acc);

/**
  * @brief set the access address of the broadcast channel used by the pairing process
  *
  * Invoke this api will overwrite the default value.
  * The user should check whether the new value is valid by call @ref sync_acc_check.
  * @param[in] acc_br: the access address value
  * @return none
  */
void sync_acc_set_br(sync_acc_t acc_br);

/**
  * @brief enable the protocol
  *
  * It shall be called after @ref sync_init to enable the protocol.
  * @return none
  */
void sync_enable(void);

/**
  * @brief register event callback function
  *
  * The event @ref sync_event_t include the pairing and connection result.
  * @param[in] cb: event callback
  * @return none
  */
void sync_event_cb_reg(sync_event_cb_t cb);

/**
  * @brief get bond information from flash
  *
  * After pairing, the bond information wil be stored to the flash automatically.
  * The bond information is used for connection.
  * @return operation result
  * @retval SYNC_ERR_CODE_SUCCESS: bond information get successfully
  * @retval SYNC_ERR_CODE_NOT_FOUND: bond information doesn't exist
  */
sync_err_code_t sync_nvm_get_bond_info(sync_bond_info_t *bond_info);

/**
  * @brief set bond information to flash
  *
  * The app may want to add bond information manually by this api.
  * @return operation result
  * @retval SYNC_ERR_CODE_SUCCESS: bond information set successfully
  * @retval SYNC_ERR_CODE_UNKNOWN: bond information storage fail
  */
sync_err_code_t sync_nvm_set_bond_info(sync_bond_info_t *bond_info);

/**
  * @brief clear bond information in flash
  *
  * The app can clear the bond information to restore unpaired state.
  * @return operation result
  * @retval SYNC_ERR_CODE_SUCCESS: bond information set successfully
  * @retval SYNC_ERR_CODE_UNKNOWN: bond information clear fail
  */
sync_err_code_t sync_nvm_clear_bond_info(void);

/**
  * @brief start pairing
  *
  * After pairing, two new devices is connected and bonded.
  * The pairing result is notified at the event callback registered by @ref sync_event_cb_reg.
  * @return operation result
  */
sync_err_code_t sync_pair(void);

/**
  * @brief start connect
  *
  * If two bonded devices are disconnected, call this api to connect each other.
  * The connection result is notified at the event callback registered by @ref sync_event_cb_reg.
  * @param[in] bond_info: bond information used to create a connection
  * @return operation result
  */
sync_err_code_t sync_connect(sync_bond_info_t *bond_info);

/**
  * @brief stop the connection or the pairing procedure
  *
  * If the device is connecting, pairing or connected, call this api to stop.
  * @return none
  */
void sync_stop(void);

/**
  * @brief deinitiate the protocol to release all resources
  *
  * If the device is running, the api @ref sync_stop shall be called before this.
  * @return none
  */
void sync_deinit(void);

/**
  * @brief initialize the sync protocol dlps setting
  * @return none
  */
void sync_dlps_init(void);

/**
  * @brief set message queue size of each type
  *
  * Different message types have different queue size.
  * @param[in] msg_quota: queue size
  * @return none
  */
void sync_msg_set_quota(uint8_t msg_quota[SYNC_MSG_TYPE_NUM]);

/**
  * @brief set message queue size of the specific type
  *
  * Different message types have different queue size.
  * @param[in] type: the message type
  * @param[in] quota: the message type
  * @return set result
  */
bool sync_msg_set_quota_by_type(sync_msg_type_t type, uint8_t quota);

/**
  * @brief set message retranmsit times for @ref SYNC_MSG_TYPE_FINITE_RETRANS type msg
  * @param[in] msg_retrans_num: retranmsit times
  * @return none
  */
void sync_msg_set_finite_retrans(uint8_t msg_retrans_num);

/**
  * @brief set message retranmsit times for @ref SYNC_MSG_TYPE_DYNAMIC_RETRANS type msg
  * @param[in] msg_retrans_num_lower: retranmsit times lower limit
  * @param[in] msg_retrans_num_upper: retranmsit times upper limit
  * @return none
  */
void sync_msg_set_dynamic_retrans(uint8_t msg_retrans_num_lower, uint8_t msg_retrans_num_upper);

/**
  * @brief register message receive callback function
  * @param[in] cb: callback function
  * @return none
  */
void sync_msg_reg_receive_cb(sync_msg_receive_cb_t cb);

/**
  * @brief send message
  *
  * The first byte of data buffer shall contain the opcode starting from SYNC_OPCODE_APP_START_VALUE.
  * @param[in] type: msg type, different types have different retransmit behavior
  * @param[in] data: the data buffer
  * @param[in] len: the data length
  * @param[in] send_cb: the send complete callback
  * @return send result
  * @retval SYNC_ERR_CODE_SUCCESS: the msg is successfully pushed into the queue to send
  */
sync_err_code_t sync_msg_send(sync_msg_type_t type, uint8_t *data, uint16_t len,
                              sync_msg_send_cb_t send_cb);

/**
  * @brief get the free number of the message buffer with the specific type
  * @param[in] type: the msg type
  * @return the free messages number
  */
uint8_t sync_msg_get_available_number(sync_msg_type_t type);

/**
  * @brief flush the msg sending queue
  *
  * Each message type can be flushed independently.
  * @param[in] type: the msg type
  * @return the flushed messages number
  */
uint8_t sync_msg_flush(sync_msg_type_t type);

/**
  * @brief reset the message tx queue
  *
  * It is safe to be called when the device is disconnected and at the app task context.
  * @return none
  */
void sync_msg_reset(void);

/**
  * @brief enter critical section
  * @return interrupt mask
  */
uint32_t sync_enter_critical(void);

/**
  * @brief exit critical section
  * @param[in] flag: interrupt mask
  * @return none
  */
void sync_exit_critical(uint32_t flag);

/**
  * @brief register heartbeat callback
  * @param[in] cb: function pointer
  * @return none
  */
void sync_hb_reg_cb(sync_hb_cb_t cb);

/**
  * @brief register heartbeat callback
  * @param[in] cb: function pointer
  * @return none
  */
void sync_rte_req_reg_cb(sync_rte_req_cb_t cb);

/** @} End of PPT_SYNC_Driver_Exported_Functions */

/** @} End of PPT_SYNC_Driver */
