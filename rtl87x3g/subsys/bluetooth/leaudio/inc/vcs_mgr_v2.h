/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef _VCS_MGR_V2_H_
#define _VCS_MGR_V2_H_

#ifdef  __cplusplus
extern "C" {
#endif      /* __cplusplus */

#include "ble_audio_def.h"
#include "codec_def.h"
#include "vcs_def.h"
#include "gap.h"

/**
 * \defgroup    LEA_GAF_VCP_Server Volume Control Server
 *
 * \brief   The server role for Volume Control Profile.
 */

#define VCS_SERVER_VCS_MGR_V2_SUPPORT    1

/**
 * \defgroup    VCP_Server_Exported_Types Volume Control Server Exported Types
 *
 * \ingroup LEA_GAF_VCP_Server
 * @{
 */

typedef enum
{
    VCS_SERVER_EVENT_READ_IND = 0x01,
    VCS_SERVER_EVENT_WRITE_CP_IND = 0x02,
} T_VCS_SERVER_EVENT;


typedef struct
{
    uint16_t connection_handle;
    uint16_t cid;
    uint16_t offset;
    uint16_t char_uuid16;
    uint8_t att_error_code;

    union
    {
        uint8_t volume_flags;
        T_VOLUME_STATE volume_state;
    };
} T_VCS_SERVER_READ_CFM_PARAM;

typedef struct
{
    uint16_t connection_handle;
    uint16_t cid;
    uint8_t att_error_code;   /* @ref VCS_ERR_CODE or @ref T_APP_RESULT. */
} T_VCS_SERVER_WRITE_CP_CFM_PARAM;

typedef struct
{
    uint8_t server_id;
    uint16_t char_uuid16;
    uint16_t offset;
} T_VCS_SERVER_EVENT_PARAM_READ_IND;

typedef struct
{
    uint8_t server_id;
    T_VCS_CP_OP op;
    uint8_t change_counter;
    uint8_t volume_setting;  /* This parameter is only valid when the op is @ref VCS_CP_SET_ABSOLUTE_VOLUME. */
} T_VCS_SERVER_EVENT_PARAM_WRITE_CP_IND;

typedef struct
{
    T_VCS_SERVER_EVENT_PARAM_READ_IND read_ind;
    T_VCS_SERVER_EVENT_PARAM_WRITE_CP_IND write_cp_ind;
} T_VCS_SERVER_EVENT_PARAM;

/**
 * End of VCP_Server_Exported_Types
 * @}
 */

/**
 * \defgroup    VCP_Server_Exported_Functions Volume Control Server Exported Functions
 *
 * \ingroup LEA_GAF_VCP_Server
 * @{
 */

typedef void(*T_VCS_SERVER_APP_CALLBACK)(uint16_t connection_handle,
                                         uint16_t cid,
                                         T_VCS_SERVER_EVENT event_type,
                                         T_VCS_SERVER_EVENT_PARAM *p_event_param);

bool vcs_server_callback_register(T_VCS_SERVER_APP_CALLBACK app_callback);

bool vcs_server_read_cfm(T_VCS_SERVER_READ_CFM_PARAM *p_param);

bool vcs_server_write_cp_cfm(T_VCS_SERVER_WRITE_CP_CFM_PARAM *p_param);

bool vcs_server_volume_state_notification_send(uint16_t connection_handle, uint16_t cid,
                                               T_VOLUME_STATE volume_state);

bool vcs_server_volume_flags_notification_send(uint16_t connection_handle, uint16_t cid,
                                               uint8_t volume_flags);
/**
 * End of VCP_Server_Exported_Functions
 * @}
 */

#ifdef  __cplusplus
}
#endif      /*  __cplusplus */

#endif
