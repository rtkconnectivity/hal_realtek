/**************************************************************************//**
 * @file     frame_802154.h
 * @brief    Inter-Processor communication definition for IEEE802.15.4 MAC/PHY
 *           control cross platorm.
 *
 * @version  V1.00
 * @date     2023-05-31
 *
 * @note
 *
 ******************************************************************************
 *
 * Copyright(c) 2007 - 2023 Realtek Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

#ifndef _FRAME_802154_H_
#define _FRAME_802154_H_

/**
  \brief  Defines MAC Frame Type
*/
enum mac_frame_type_e
{
    FRAME_TYPE_BEACON           = 0,
    FRAME_TYPE_DATA             = 1,
    FRAME_TYPE_ACK              = 2,
    FRAME_TYPE_COMMAND          = 3,
    FRAME_TYPE_RESERVED         = 4,
    FRAME_TYPE_MULTIPURPOSE     = 6,
    FRAME_TYPE_FRAGMENT         = 6,
    FRAME_TYPE_EXTENDED         = 7,
};

/**
  \brief  Defines Destination Addressing Mode and Source Addressing Mode fields Type
*/
enum mac_addr_mode_e
{
    ADDR_MODE_NONE              = 0,
    ADDR_MODE_RESERVED          = 1,
    ADDR_MODE_SHORT             = 2,
    ADDR_MODE_LONG              = 3,
};

/**
  \brief  Defines Frame Version field
*/
enum mac_frame_version_e
{
    FRAME_VER_2003              = 0,
    FRAME_VER_2006              = 1,
    FRAME_VER_2015              = 2,
    FRAME_VER_RESERVED          = 3,
};

/**
  \brief  Defines Security levels
*/
enum mac_security_level_e
{
    SEC_LEVEL_NONE              = 0,
    SEC_LEVEL_MIC32             = 1,
    SEC_LEVEL_MIC64             = 2,
    SEC_LEVEL_MIC128            = 3,
    SEC_LEVEL_ENC               = 4,
    SEC_LEVEL_ENC_MIC32         = 5,
    SEC_LEVEL_ENC_MIC64         = 6,
    SEC_LEVEL_ENC_MIC128        = 7,
};

/**
  \brief  Defines Key Identifier Mode
*/
enum mac_key_id_mode_e
{
    KEY_ID_MODE_IMPLICIT        = 0,
    KEY_ID_MODE_1B              = 1,
    KEY_ID_MODE_5B              = 2,
    KEY_ID_MODE_9B              = 3,
};

#define SEC_KEY_LEN             (16)
#define SEC_NONCE_LEN           (13)

typedef union
{
    uint8_t bytes[2]; /*!< frame control data in byte */

    struct
    {
        uint16_t frm_type : 3; /*!< [0..2] Transmit frame type */
        uint16_t sec_en : 1; /*!< [3..3] security enabled */
        uint16_t frm_pending : 1; /*!< [4..4] frame pending */
        uint16_t ack_req : 1;  /*!< [5..5] ACK request */
        uint16_t panid_comp : 1; /*!< [6..6] PANID compression */
        uint16_t reserved1 : 1; /*!< [7..7] reserved */
        uint16_t sn_suppr : 1; /*!< [8..8] sequence number suppression */
        uint16_t ie_present : 1; /*!< [9..9] IE present */
        uint16_t dest_addr_mode : 2; /*!< [11..10] destination address mode */
        uint16_t frm_ver : 2; /*!< [13..12] frame version */
        uint16_t src_addr_mode : 2; /*!< [15..14] source address mode */
    } bits;  /*!< bit fields for frame control */
} frame_control_t, *pframe_control_t;

#endif /* _FRAME_802154_H_ */
