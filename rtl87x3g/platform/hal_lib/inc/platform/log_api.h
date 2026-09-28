/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __LOG_API_H_
#define __LOG_API_H_
#include "stdbool.h"
#include "stdint.h"
#include <stdarg.h>
/** @defgroup  HAL_LOG_API    Log Control
    * @brief Log control.
    * @{
    */
/** @defgroup HAL_LOG_CONTROL_EXPORTED_TYPE Log Control Exported Types
   * @brief
   * @{
   */
typedef void (*LOG_VENDOR_INIT_CB)(void);
typedef void (*LOG_VENDOR_DEINIT_CB)(void);
typedef void (*LOG_VENDOR_DIRECT_SEND_FUNC)(uint8_t *, uint32_t);
typedef void (*LOG_VENDOR_TX_DONE_CB)(void);
typedef void (*LOG_VENDOR_ASYNC_SEND_FUNC)(uint8_t *, uint16_t, LOG_VENDOR_TX_DONE_CB);


typedef struct
{
    LOG_VENDOR_INIT_CB vendor_log_init_func;
    LOG_VENDOR_DEINIT_CB vendor_log_deinit_func;
    LOG_VENDOR_DIRECT_SEND_FUNC direct_send_func;
    LOG_VENDOR_ASYNC_SEND_FUNC async_send_func;
} T_LOG_VENDOR_CB_FUNC;


/** End of HAL_LOG_CONTROL_EXPORTED_TYPE
    * @}
    */
/** @defgroup HAL_LOG_CONTROL_EXPORTED_FUNCTIONS Log Control Exported Functions
    * @brief
    * @{
    */
#ifdef __cplusplus
extern "C" {
#endif
/**
    * @brief  Get the log enable status.
    * @return The log enable status.
    * @retval true   Log enable.
    * @retval false  Log disable.
    */
bool log_enable_get(void);
/**
    * @brief  Set the log enable status.
    * @warning This API is supported in the RTL87x3E/RTL87x3EP/RTL87x3G.
    *          It is NOT supported in the RTL87x3D.
    * @param enable  Log enable status, false: log disable, true: log enable.
    */
void log_enable_set(bool enable);

/**
    * @brief  Set the trace string log enable status.
    * \xrefitem Added_API_2_12_0_0 "Added Since 2.12.0.0" "Added API"
    * @param enable  Whether to output trace string, false: don't output, true: output.
    */
void log_enable_trace_string(bool enable);

/**
    * @brief  Get the trace string log enable status.
    * \xrefitem Added_API_2_11_1_0 "Added Since 2.11.1.0" "Added API"
    * @return  The status whether to output trace string, false: don't output, true: output.
    */
bool log_enable_trace_string_get(void);

/**
    * @brief  Enable LEVEL_CRITICAL log.
    * @note   LEVEL_CRITICAL log is disabled by default. If LEVEL_CRITICAL log is enabled, it will be output ad LEVEL_INFO.
    * \xrefitem Added_API_2_14_0_0 "Added Since 2.14.0.0" "Added API"
    * @warning This API is supported in the RTL87x3E and RTL87x3D.
    *          It is NOT supported in the RTL87x3EP/RTL87x3G.
    * @param enable  Whether to output LEVEL_CRITICAL log, false: don't output, true: output.
    */
void log_enable_critical_level(bool enable);

/**
    * @brief  Get the LEVEL_CRITICAL log enable status.
    * \xrefitem Added_API_2_14_0_0 "Added Since 2.14.0.0" "Added API"
    * @warning This API is supported in the RTL87x3E and RTL87x3D.
    *          It is NOT supported in the RTL87x3EP/RTL87x3G.
    * @return The output status for LEVEL_CRITICAL log, true: output, false: don't output.
    */
bool log_enable_critical_level_get(void);

/**
    * @brief  Get trace_mask value.
    *\xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
    * @param[out] p_trace_mask_buf  Pointer to the buffer to get the trace_mask value.
    * @param[in] buf_size  Specified the size of p_trace_mask_buf. User can get the size of trace_mask by log_trace_mask_size_get API.
    * @return The operation status for getting trace_mask value.
    * @retval  true  Get the trace_mask value by p_trace_mask_buf successfully.
    * @retval  false Get trace_mask value  fail for parameter checking invalid.
    */
bool log_trace_mask_get(void *p_trace_mask_buf, uint32_t buf_size);

/**
    * @brief  Get trace_mask size, uint: bytes.
    *\xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
    * @return The trace_mask size, uint: bytes.
    */
uint32_t log_trace_mask_size_get(void);

/**
    * @brief  Enable vendor log.
    *\xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Experimental Added API"
    * @warning This API is supported in the RTL87x3E, RTL87x3D and RTL87x3G.
    *          It is NOT supported in the RTL87x3EP.
    * @param   log_vendor_cb_func_set Pointer to the vendor log callback function set, includes Vendor directly send data function,
    *                                 vendor async send data function, init function and deinit funciton.
    *
    * <b>Example usage</b>
    * @code
    * // Example: Redirect log to custom output device using vendor log interface
    *
    * #include "log_api.h"
    *
    * // Global variable to save tx_done_cb for async transmission
    * static LOG_VENDOR_TX_DONE_CB vendor_tx_done_cb = NULL;
    *
    * // Device write completion callback (called by device driver interrupt)
    * void custom_device_write_complete_handler(void)
    * {
    *     // This function is called by device driver when async write completes
    *     // Invoke the LOG_VENDOR_TX_DONE_CB to notify the log system
    *     // that transmission is complete
    *     if (vendor_tx_done_cb != NULL)
    *     {
    *         vendor_tx_done_cb();
    *     }
    * }
    *
    * // Custom device initialization
    * void custom_device_init(void)
    * {
    *     // Initialize device hardware (e.g., DMA, peripheral, GPIO)
    *     // ...
    *
    *     // Register write completion callback to device driver
    *     // This callback will be invoked when async write operation completes
    *     device_register_tx_done_callback(custom_device_write_complete_handler);
    * }
    *
    * // Vendor log initialization callback
    * void vendor_log_init(void)
    * {
    *     // Initialize custom output device
    *     custom_device_init();
    * }
    *
    * // Vendor log deinitialization callback
    * void vendor_log_deinit(void)
    * {
    *     // Deinitialize custom output device
    *     custom_device_deinit();
    * }
    *
    * // Direct send function for synchronous log output
    * void vendor_log_direct_send(uint8_t *data, uint32_t len)
    * {
    *     // Write data directly to output device (blocking mode)
    *     // Operate on the buffer pointer directly, no additional buffering needed
    *     custom_device_write(data, len);
    * }
    *
    * // Async send function for asynchronous log output
    * void vendor_log_async_send(uint8_t *data, uint16_t len, LOG_VENDOR_TX_DONE_CB tx_done_cb)
    * {
    *     // Save tx_done_cb to global variable for later use in completion handler
    *     vendor_tx_done_cb = tx_done_cb;
    *
    *     // Asynchronous write to output device
    *     // Operate on the buffer pointer directly, no additional buffering needed
    *     // The log system already has ping-pong buffer for caching
    *     // The tx_done_cb will be called in custom_device_write_complete_handler
    *     // when the write operation completes
    *     custom_device_write_async(data, len);
    * }
    *
    * // Initialize and enable vendor log
    * void app_vendor_log_init(void)
    * {
    *     T_LOG_VENDOR_CB_FUNC vendor_log_func = {0};
    *
    *     // Register callback functions
    *     vendor_log_func.vendor_log_init_func = vendor_log_init;
    *     vendor_log_func.vendor_log_deinit_func = vendor_log_deinit;
    *     vendor_log_func.direct_send_func = vendor_log_direct_send;
    *     vendor_log_func.async_send_func = vendor_log_async_send;
    *
    *     // Enable vendor log with registered callbacks
    *     log_enable_vendor(&vendor_log_func);
    * }
    * @endcode
    * @}
    */
void log_enable_vendor(T_LOG_VENDOR_CB_FUNC *p_log_vendor_cb_func_set);

/**
    * @brief   Output formated log data for third-party variable parmameter log interface adaptation.
    *\xrefitem Experimental_Added_API_2_14_1_0 "Experimental Added Since 2.14.1.0" "Experimental Added API"
    * @param   fmt  Specify the log format string.
    * @param   arg  Specify the variable parameter list.
    *
    * <b>Example usage</b>
    * \code{.c}
       int wrapper_log_printf(const char *fmt, ...)
       {
           va_list  ap;
           va_start(ap, fmt);
           log_printf_common(fmt, ap);
           va_end(ap);
           return 0;
       }
    * \endcode
    */
void log_printf_common(const char *fmt, va_list  arg);
#ifdef __cplusplus
}
#endif
/** @} */ /* End of group HAL_LOG_CONTROL_EXPORTED_FUNCTIONS */
/** @} */ /* End of group HAL_LOG_API */
#endif

