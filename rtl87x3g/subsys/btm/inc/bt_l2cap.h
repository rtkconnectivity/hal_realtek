/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef _BT_L2CAP_H_
#define _BT_L2CAP_H_

#include <stdint.h>
#include <stdbool.h>
#include "bt_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/**
 * \defgroup  BT_L2CAP BT L2CAP Protocol
 *
 * \brief  Provide BT L2CAP protocol interfaces.
 */

/**
 * \defgroup BT_L2CAP_MODE BT L2CAP mode.
 *
 * \brief Define BT L2CAP mode.
 *
 * \ingroup BT_L2CAP
 * @{
 */
#define BT_L2CAP_MODE_BASIC              (1 << 0x00)    /**< L2CAP channel mode: basic mode. */
#define BT_L2CAP_MODE_ERTM               (1 << 0x03)    /**< L2CAP channel mode: enhanced retransmission mode. */
/**
 * @}
 */

/**
 * \defgroup BT_L2CAP_SECURITY_SETTING BT L2CAP security setting.
 *
 * \brief Protocol security requirement settings bit mask.
 *
 * \ingroup BT_L2CAP
 * @{
 */
#define BT_L2CAP_SECURITY_BIT_OUTGOING            0x01    /**< Request for outgoing connection. */
#define BT_L2CAP_SECURITY_BIT_AUTHEN              0x02    /**< Authentication is required. */
#define BT_L2CAP_SECURITY_BIT_MITM                0x04    /**< MITM authentication is required, only possible if authentication is set. */
#define BT_L2CAP_SECURITY_BIT_AUTHORIZATION       0x08    /**< User level authorization is required. */
#define BT_L2CAP_SECURITY_BIT_ENCRYPT             0x10    /**< Encryption on link is required, only possible if authentication is set. */
/**
 * @}
 */

/**
* \brief    L2CAP confirm cause used in \ref bt_l2cap_conn_cfm API.
*
* \ingroup  BT_L2CAP
*/
typedef enum t_bt_l2cap_conn_cfm_cause
{
    BT_L2CAP_CONN_ACCEPT               = L2C_CONN_ACCEPT,                           /**< L2CAP connection accept. */
    BT_L2CAP_CONN_PENDING              = (L2C_ERR | L2C_ERR_PENDING),               /**< L2CAP connection pending. */
    BT_L2CAP_CONN_INVALID_PSM          = (L2C_ERR | L2C_ERR_INVALID_PSM),           /**< L2CAP connection reject because of PSM not support. */
    BT_L2CAP_CONN_SECURITY_BLOCK       = (L2C_ERR | L2C_ERR_SECURITY_BLOCK),        /**< L2CAP connection reject because of security block. */
    BT_L2CAP_CONN_NO_RESOURCE          = (L2C_ERR | L2C_ERR_NO_RESOURCE),           /**< L2CAP connection reject because of no resources available. */
    BT_L2CAP_CONN_INVALID_PARAM        = (L2C_ERR | L2C_ERR_INVALID_PARAM),         /**< L2CAP connection reject because of invalid parameter. */
    BT_L2CAP_CONN_INVALID_SOURCE_CID   = (L2C_ERR | L2C_ERR_INVALID_SOURCE_CID),    /**< L2CAP connection reject because of invalid source CID. */
    BT_L2CAP_CONN_SOURCE_CID_ALLOCATED = (L2C_ERR | L2C_ERR_SOURCE_CID_ALLOCATED)   /**< L2CAP connection reject because of source CID already allocated. */
} T_BT_L2CAP_CONN_CFM_CAUSE;

/**
 * \brief  BT L2CAP message type.
 *
 * \ingroup BT_L2CAP
 */
typedef enum t_bt_l2cap_msg_type
{
    BT_L2CAP_SECURITY_REGISTER_RSP   = 0x00,
    BT_L2CAP_SECURITY_UNREGISTER_RSP = 0x01,
    BT_L2CAP_MSG_CONN_IND            = 0x02,
    BT_L2CAP_MSG_CONN_RSP            = 0x03,
    BT_L2CAP_MSG_AUTHORIZATION_IND   = 0x04,
    BT_L2CAP_MSG_CONN_CMPL           = 0x05,
    BT_L2CAP_MSG_DISCONN_IND         = 0x06,
    BT_L2CAP_MSG_DISCONN_RSP         = 0x07,
    BT_L2CAP_MSG_DATA_IND            = 0x08,
    BT_L2CAP_MSG_DATA_RSP            = 0x09,
} T_BT_L2CAP_MSG_TYPE;

/**
 * \brief  Response of registering service security into Bluetooth Host. It will be received in the
 *         callback function registered by \ref bt_l2cap_service_register with message type as
 *         \ref BT_L2CAP_SECURITY_REGISTER_RSP.
 *
 * \ingroup BT_L2CAP
 */
typedef struct t_bt_l2cap_security_register_rsp
{
    uint16_t    psm;
    uint16_t    uuid;
    uint16_t    server_chann;
    uint16_t    cause;
} T_BT_L2CAP_SECURITY_REGISTER_RSP;

/**
 * \brief  Response of unregistering service security into Bluetooth Host. It will be received in
 *         the callback function registered by \ref bt_l2cap_service_register with message type as
 *         \ref BT_L2CAP_SECURITY_UNREGISTER_RSP.
 *
 * \ingroup BT_L2CAP
 */
typedef struct t_bt_l2cap_security_unregister_rsp
{
    uint16_t    psm;
    uint16_t    uuid;
    uint16_t    server_chann;
    uint16_t    cause;
} T_BT_L2CAP_SECURITY_UNREGISTER_RSP;

/**
 * \brief  Indication of L2CAP connection request from remote device. It will be received in the
 *         callback function registered by \ref bt_l2cap_service_register with message type as
 *         \ref BT_L2CAP_MSG_CONN_IND.
 *
 * \ingroup BT_L2CAP
 */
typedef struct t_bt_l2cap_conn_ind
{
    uint8_t     bd_addr[6];
    uint16_t    psm;
    uint16_t    cid;
} T_BT_L2CAP_CONN_IND;

/**
 * \brief  Response of creating L2CAP connection. It will be received in the callback
 *         function registered by \ref bt_l2cap_service_register with message type as
 *         \ref BT_L2CAP_MSG_CONN_RSP.
 *
 * \ingroup BT_L2CAP
 */
typedef struct t_bt_l2cap_conn_rsp
{
    uint8_t     bd_addr[6];
    uint16_t    psm;
    uint16_t    cid;
    uint16_t    cause;
} T_BT_L2CAP_CONN_RSP;

/**
 * \brief  Indication of request user's authorization for service connection establish. It will be
 *         received in the callback function registered by \ref bt_l2cap_service_register with
 *         message  type as \ref BT_L2CAP_AUTHORIZATION_IND.
 *
 * \ingroup BT_L2CAP
 */
typedef struct t_bt_l2cap_authorization_req_ind
{
    uint8_t     bd_addr[6];
    uint16_t    psm;
    uint16_t    uuid;
    uint16_t    server_chann;
    uint8_t     outgoing;
} T_BT_L2CAP_AUTHORIZATION_REQ_IND;

/**
 * \brief  Indication of completion of creating L2CAP connection. It will be received in the
 *         callback function registered by \ref bt_l2cap_service_register with message type
 *         as \ref BT_L2CAP_MSG_CONN_CMPL.
 *
 * \ingroup BT_L2CAP
 */
typedef struct t_bt_l2cap_conn_cmpl
{
    uint8_t     bd_addr[6];
    uint16_t    psm;
    uint16_t    cid;
    uint16_t    cause;
    uint16_t    local_mtu;
    uint16_t    remote_mtu;
} T_BT_L2CAP_CONN_CMPL;

/**
 * bt_l2cap.h
 *
 * \brief    Indication of receiving L2CAP disconnection request from remote device. It will be
 *           received in the callback function registered by \ref bt_l2cap_service_register with
 *           message type as \ref BT_L2CAP_MSG_DISCONN_IND.
 *
 * \ingroup  BT_L2CAP
 */
typedef struct
{
    uint16_t    psm;
    uint16_t    cid;
    uint16_t    cause;
} T_BT_L2CAP_DISCONN_IND;

/**
 * \brief Response of sending L2CAP disconnection request to remote device. It will be received
 *        in the callback function registered by \ref bt_l2cap_service_register with message type
 *        as \ref BT_L2CAP_MSG_DISCONN_RSP.
 *
 * \ingroup BT_L2CAP
 */
typedef struct t_bt_l2cap_disconn_rsp
{
    uint16_t    psm;
    uint16_t    cid;
    uint16_t    cause;
} T_BT_L2CAP_DISCONN_RSP;

/**
 * \brief  Indication of L2CAP data. It will be received in the callback function registered by
 *         \ref bt_l2cap_service_register with message type as \ref BT_L2CAP_MSG_DATA_IND.
 *
 * \ingroup BT_L2CAP
 */
typedef struct t_bt_l2cap_data_ind
{
    uint32_t    bt_clock;
    uint16_t    cid;
    uint16_t    psm;
    uint16_t    len;
    uint8_t    *buf;
} T_BT_L2CAP_DATA_IND;

/**
 * \brief  Indication L2CAP data has been sent out. It will be received in the callback
 *         function registered by \ref bt_l2cap_service_register with message type as
 *         \ref BT_L2CAP_MSG_DATA_RSP.
 *
 * \ingroup BT_L2CAP
 */
typedef struct t_bt_l2cap_data_rsp
{
    uint16_t    cid;
    uint16_t    psm;
    uint8_t     dlci;
} T_BT_L2CAP_DATA_RSP;

/**
 * \brief  L2CAP message callback definition.
 *
 * \param[in]  msg_type   L2CAP message type.
 * \param[in]  msg        Message buffer address.
 *
 * \ingroup BT_L2CAP
 */
typedef void (*T_BT_L2CAP_SERVICE_CBACK)(T_BT_L2CAP_MSG_TYPE  msg_type,
                                         void                *msg);

/**
 * \brief  Register service to L2CAP.
 *
 * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
 *
 * \param[in] psm             Protocol service multiplexer that the callback function is related.
 * \param[in] cback           Callback function used to handle L2CAP message.
 *
 * \return    The result of registration.
 * \retval true    Registration has been completed successfully.
 * \retval false   Registration was failed to complete.
 *
 * \ingroup BT_L2CAP
 */
bool bt_l2cap_service_register(uint16_t                 psm,
                               T_BT_L2CAP_SERVICE_CBACK cback);

/**
 * \brief  Unregister service from L2CAP.
 *
 * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
 *
 * \param[in] psm      Protocol service multiplexer.
 *
 * \return    The result of unregistration.
 * \retval true    Unregistration has been completed successfully.
 * \retval false   Unregistration was failed to complete.
 *
 * \ingroup BT_L2CAP
 */
bool bt_l2cap_service_unregister(uint16_t psm);

/**
 * \brief   Send a request to register a protocol security entry over L2CAP. The security will be
 *          used when establishing a L2CAP channel. If the request was successfully sent, a message
 *          whose type is \ref BT_L2CAP_SECURITY_REGISTER_RSP will be received in the callback
 *          function registered by \ref bt_l2cap_service_register.
 *
 * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
 *
 * \param[in] psm              Protocol service multiplexer that the callback function is related.
 * \param[in] server_chann     Local server channel number for RFCOMM, for other protocols set to 0.
 * \param[in] uuid             Service UUID.
 * \param[in] requirement      Security requirement of the entry. Valid values are combinations of \ref BT_L2CAP_SECURITY_SETTING.
 *
 * \return    The result of registration.
 * \retval true    Registration has been completed successfully.
 * \retval false   Registration was failed to complete.
 *
 * \ingroup BT_L2CAP
 */
bool bt_l2cap_security_register(uint16_t psm,
                                uint16_t server_chann,
                                uint16_t uuid,
                                uint16_t requirement);

/**
 * \brief    Send a request to unregister a protocol security entry over L2CAP. If the request was
 *           successfully sent, a message whose type is \ref BT_L2CAP_SECURITY_UNREGISTER_RSP will
 *           be received in the callback function registered by \ref bt_l2cap_service_register.
 *
 * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
 *
 * \param[in] psm              Protocol service multiplexer that the callback function is related.
 * \param[in] server_chann     Local server channel number for RFCOMM, for other protocols set to 0.
 * \param[in] uuid             Service UUID.
 * \param[in] requirement      Security requirement of the entry, defined in \ref BT_L2CAP_SECURITY_SETTING.
 *
 * \return    The result of unregistration.
 * \retval true    Unregistration has been completed successfully.
 * \retval false   Unregistration was failed to complete.
 *
 * \ingroup BT_L2CAP
 */
bool bt_l2cap_security_unregister(uint16_t psm,
                                  uint16_t server_chann,
                                  uint16_t uuid,
                                  uint16_t requirement);

/**
 * \brief  Send a request to create a L2CAP connection.
 *
 * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
 *
 * \param[in] bd_addr          Remote BT address.
 * \param[in] psm              PSM of the L2CAP channel that will be established.
 * \param[in] uuid             UUID of profile that is established over the L2CAP channel.
 * \param[in] mtu_size         The maximum frame_size supported by local device.
 * \param[in] mode             Channel mode to use, defined in \ref BT_L2CAP_MODE.
 * \param[in] flush_timeout    Flush timeout of flushable data on this channel, 0xFFFF for not flush.
 *
 * \return    The status of sending connection request.
 * \retval true    Request has been sent successfully.
 * \retval false   Request was fail to send.
 *
 * \ingroup BT_L2CAP
 */
bool bt_l2cap_conn_req(uint8_t  bd_addr[6],
                       uint16_t psm,
                       uint16_t uuid,
                       uint16_t mtu_size,
                       uint8_t  mode,
                       uint16_t flush_timeout);

/**
 * \brief  Send a confirmation to accept or reject the received L2CAP connection request.
 *
 * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
 *
 * \param[in] cid              Local channel identifier.
 * \param[in] cause            Confirmation cause for the connection request from remote device, defined in \ref T_BT_L2CAP_CONN_CFM_CAUSE.
 * \param[in] mtu_size         Preferred MTU size value of the L2CAP channel.
 * \param[in] mode             Channel mode to use, defined in \ref BT_L2CAP_MODE.
 * \param[in] flush_timeout    Flush timeout of flushable data on this channel, 0xFFFF for not flush.
 *
 * \return    The result of sending confirmation.
 * \retval true    The confirmation has been sent successfully.
 * \retval false   The confirmation was fail to send.
 *
 * \ingroup BT_L2CAP
 */
bool bt_l2cap_conn_cfm(uint16_t cid,
                       uint16_t cause,
                       uint16_t mtu_size,
                       uint8_t  mode,
                       uint16_t flush_timeout);

/**
* \brief  Send a confirmation for authorization request indication.
*
* \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
*
* \param[in] bd_addr          Remote BT address.
* \param[in] result           Result of authorization.
*
* \return     The result of sending confirmation.
* \retval true    The confirmation has been sent successfully.
* \retval false   The confirmation was fail to send.
*
* \ingroup BT_L2CAP
*/
bool bt_l2cap_authorization_cfm(uint8_t *bd_addr,
                                bool     result);

/**
 * \brief   Get buffer from Bluetooth stack to put in L2CAP data which will be sent to remote device.
 *
 * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
 *
 * \param[in] psm        PSM of the l2cap channel.
 * \param[in] cid        L2CAP channel identifier.
 * \param[in] dlci       DLCI value for the RFCOMM channel.
 * \param[in] size       Buffer size.
 * \param[in] ack        Whether need a ACK message generated by local Host when sending out L2CAP data.
 *
 * \return    The result of sending confirmation.
 * \retval true    The confirmation has been sent successfully.
 * \retval false   The confirmation was fail to send.
 *
 * \ingroup BT_L2CAP
 */
uint8_t *bt_l2cap_buf_get(uint16_t psm,
                          uint16_t cid,
                          uint16_t dlci,
                          uint16_t size,
                          bool     ack);

/**
 * \brief  Send a request to send data to remote device.
 *
 * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
 *
 * \param[in] cid         Local channel identifier of the L2CAP channel.
 * \param[in] buf         The start address of the data buffer.
 * \param[in] len         The length of the data to be sent.
 * \param[in] flush       Whether the L2CAP data can be flushed or not.
 *
 * \return    The status of sending data.
 * \retval true    Data has been sent successfully.
 * \retval false   Data was fail to send.
 *
 * \ingroup BT_L2CAP
 */
bool bt_l2cap_data_send(uint16_t  cid,
                        uint8_t  *buf,
                        uint16_t  len,
                        bool      flush);

/**
 * \brief  Send a request to disconnect a L2CAP channel.
 *
 * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
 *
 * \param[in] cid            Local channel identifier of the L2CAP channel.
 *
 * \return    The result of sending request.
 * \retval true    The request has been sent successfully.
 * \retval false   The request was fail to send.
 *
 * \ingroup BT_L2CAP
 */
bool bt_l2cap_disconn_req(uint16_t cid);

/**
 * \brief  Send a confirmation for a L2CAP disconnection request from remote device.
 *
 * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
 *
 * \param[in] cid            Local channel identifier of the L2CAP channel.
 *
 * \return    The result of sending confirmation.
 * \retval true    The confirmation has been sent successfully.
 * \retval false   The confirmation was fail to send.
 *
 * \ingroup BT_L2CAP
 */
bool bt_l2cap_disconn_cfm(uint16_t cid);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _BT_L2CAP_H_ */
