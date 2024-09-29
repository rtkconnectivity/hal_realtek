/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _OS_POOL_H_
#define _OS_POOL_H_

#include <stdint.h>
#include <stdbool.h>
#include <mem_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup OS_POOL Pool Management
 *
 * \brief   Manage task-safe and fixed-size blocks of dynamic memory.
 * \details Memory pools are fixed-size blocks of memory that are task-safe. They operate much
 *          faster than the dynamically allocated heap and do not suffer from fragmentation.
 *          Being task-safe, they can be accessed from tasks and ISRs alike.\n
 *          Shared memory is one of the basic models to exchange information between tasks.
 *          Using memory pools for exchanging data, you can share more complex objects between
 *          taks if compared to the Message Queue. Memory pool management functions are used to
 *          define and manage such fixed-sized memory pools.\n
 *
 * \image html OS-pool-overview.jpg "Memory Pool Overview" width=601px height=481px
 *
 */


/**
 * os_pool.h
 *
 * \brief The invalid pool handle. Valid pool handles should be less than OS_POOL_INVALID_HANDLE.
 *
 * \ingroup Pool
 */
#define OS_POOL_INVALID_HANDLE  0xFF

extern bool (*os_pool_create_intern)(uint8_t *p_handle, RAM_TYPE ram_type, uint16_t buf_size,
                                     uint16_t buf_count, const char *p_func, uint32_t file_line);

extern bool (*os_pool_extend_intern)(uint8_t handle, uint16_t buf_size, uint16_t buf_count,
                                     const char *p_func, uint32_t file_line);

extern bool (*os_pool_delete_intern)(uint8_t handle, const char *p_func, uint32_t file_line);

extern void *(*os_buffer_get_intern)(uint8_t handle, uint16_t buf_size,
                                     const char *p_func, uint32_t file_line);

extern bool (*os_buffer_put_intern)(void *p_buf, const char *p_func, uint32_t file_line);

/*============================================================================*
 *                              Functions
*============================================================================*/
/** @defgroup OS_POOL_Exported_Functions OS Pool Exported Functions
  * \ingroup  OS_POOL
  * @{
  */

/**
 * os_pool.h
 *
 * \brief   Creates and initialize a memory pool.
 *
 * \param  p_handle   Used to pass back a handle by which the memory pool
 *                         can be referenced.
 *
 * \param   ram_type            RAM type for the memory pool buffer.
 * \arg \c  RAM_TYPE_DATA_ON        Data RAM type.
 * \arg \c  RAM_TYPE_BUFFER_ON      BUFFER RAM type.
 * \arg \c  RAM_TYPE_EXT_DATA_SRAM  EXT_DATA_SRAM type.
 *
 * \param   buf_size   The pool buffer size in bytes.
 *
 * \param   buf_count  The number of pool buffers allocated.
 *
 * \return           The status of the memory pool creation.
 * \retval true      Pool was created successfully.
 * \retval false     Pool was failed to create.
 *
 * <b>Example usage</b>
 * \code{.c}
 * #define BUF_SIZE 0x40
 * #define BUF_NUM  16
 *
 * int test(void)
 * {
 *     uint8_t handle;
 *
 *     // Create a memory pool capable of containing 16 buffers.
 *     if (os_pool_create(&handle, RAM_TYPE_DATA_ON, BUF_SIZE, BUF_NUM) == true)
 *     {
 *         // Memory pool created successfully.
 *     }
 *     else
 *     {
 *         // Memory pool failed to create.
 *         return -1;
 *     }
 *
 *     return 0;
 * }
 * \endcode
 *
 */
#define os_pool_create(p_handle, ram_type, buf_size, buf_count) \
    os_pool_create_intern(p_handle, ram_type, buf_size, buf_count, __func__, __LINE__)

/**
 * os_pool.h
 *
 * \brief   Extend a set of buffers to the created memory pool. The extended pool
 *          buffers have the same RAM type with the created buffers.
 *
 * \param   handle     The handle of the created memory pool.
 *
 * \param   buf_size   The pool buffer size in bytes.
 *
 * \param   buf_count  The number of pool buffers allocated.
 *
 * \return           The status of the memory pool extension.
 * \retval true      Pool was extended successfully.
 * \retval false     Pool was failed to extend.
 *
 * <b>Example usage</b>
 * \code{.c}
 * #define BUF_SIZE1 0x40
 * #define BUF_NUM1  16
 * #define BUF_SIZE2 0x20
 * #define BUF_NUM2  8
 *
 * int test(void)
 * {
 *     uint8_t handle;
 *
 *     // Create a memory pool capable of containing 16 buffers.
 *     if (os_pool_create(&handle, RAM_TYPE_DATA_ON, BUF_SIZE1, BUF_NUM1) == true)
 *     {
 *         // Memory pool created successfully.
 *     }
 *     else
 *     {
 *         // Memory pool failed to create.
 *         return -1;
 *     }
 *
 *     // Extend the memory pool to have extra 8 buffers each in 0x20 bytes.
 *     os_pool_extend(handle, BUF_SIZE2, BUF_NUM2);
 *
 *     return 0;
 * }
 * \endcode
 *
 */
#define os_pool_extend(handle, buf_size, buf_count) \
    os_pool_extend_intern(handle, buf_size, buf_count, __func__, __LINE__)

/**
 * os_pool.h
 *
 * \brief   Delete a memory pool.
 *
 * \param  handle   The handle of the memory pool to be deleted.
 *
 * \return           The status of the memory pool deletion.
 * \retval true      Pool was deleted successfully.
 * \retval false     Pool was failed to delete.
 *
 * <b>Example usage</b>
 * \code{.c}
 * #define BUF_SIZE 0x40
 * #define BUF_NUM  16
 *
 * int test(void)
 * {
 *     uint8_t handle;
 *
 *     // Create a memory pool capable of containing 16 buffers.
 *     if (os_pool_create(&handle, RAM_TYPE_DATA_ON, BUF_SIZE, BUF_NUM) == true)
 *     {
 *         // Memory pool created successfully.
 *     }
 *     else
 *     {
 *         // Memory pool failed to create.
 *         return -1;
 *     }
 *
 *     // Delete the memory pool.
 *     os_pool_delete(handle);
 *
 *     return 0;
 * }
 * \endcode
 *
 */
#define os_pool_delete(handle)  os_pool_delete_intern(handle, __func__, __LINE__)

/**
 * os_pool.h
 *
 * \brief   Allocate a pool buffer from the specified memory pool. The allocated pool
 *          buffer size may be larger than the required size.
 *
 * \param  handle     The handle of the created memory pool.
 *
 * \param  buf_size   The pool buffer size in bytes.
 *
 * \return           The address of the allocated pool buffer. If the address is NULL,
 *                   the buffer allocation failed.
 *
 * <b>Example usage</b>
 * \code{.c}
 * #define BUF_SIZE1 0x40
 * #define BUF_NUM1  16
 * #define BUF_SIZE2 0x20
 * #define BUF_NUM2  8
 *
 * int test(void)
 * {
 *     uint8_t handle;
 *     void *p_buf;
 *
 *     // Create a memory pool capable of containing 16 buffers.
 *     if (os_pool_create(&handle, RAM_TYPE_DATA_ON, BUF_SIZE1, BUF_NUM1) == true)
 *     {
 *         // Memory pool created successfully.
 *     }
 *     else
 *     {
 *         // Memory pool failed to create.
 *         return -1;
 *     }
 *
 *     // Extend the memory pool to have extra 8 buffers each in 0x20 bytes.
 *     os_pool_extend(handle, BUF_SIZE2, BUF_NUM2);
 *
 *     // Allocate a pool buffer in 0x30 bytes. While, the memory pool will
 *     // give a buffer in 0x40 bytes.
 *     p_buf = os_buffer_get(handle, 0x30);
 *
 *     return 0;
 * }
 * \endcode
 *
 */
#define os_buffer_get(handle, buf_size) \
    os_buffer_get_intern(handle, buf_size, __func__, __LINE__)

/**
 * os_pool.h
 *
 * \brief   Free and return the pool buffer to the specified memory pool.
 *
 * \param   p_buf   The address of the pool buffer allocated by os_buffer_get()
 *                      API function.
 *
 * \return           The status of the pool buffer freeing.
 * \retval true      Pool was freed successfully.
 * \retval false     Pool was failed to free.
 *
 * <b>Example usage</b>
 * \code{.c}
 * #define BUF_SIZE1 0x40
 * #define BUF_NUM1  16
 * #define BUF_SIZE2 0x20
 * #define BUF_NUM2  8
 *
 * int test(void)
 * {
 *     uint8_t handle;
 *     void *p_buf;
 *
 *     // Create a memory pool capable of containing 16 buffers.
 *     if (os_pool_create(&handle, RAM_TYPE_DATA_ON, BUF_SIZE1, BUF_NUM1) == true)
 *     {
 *         // Memory pool created successfully.
 *     }
 *     else
 *     {
 *         // Memory pool failed to create.
 *         return -1;
 *     }
 *
 *     // Extend the memory pool to have extra 8 buffers each in 0x20 bytes.
 *     os_pool_extend(handle, BUF_SIZE2, BUF_NUM2);
 *
 *     // Allocate a pool buffer in 0x30 bytes. While, the memory pool will
 *     // give a buffer in 0x40 bytes.
 *     p_buf = os_buffer_get(handle, 0x30);
 *
 *     // Free the pool buffer by the address.
 *     os_buffer_put(p_buf);
 *
 *     return 0;
 * }
 * \endcode
 *
 */
#define os_buffer_put(p_buf)    \
    os_buffer_put_intern(p_buf, __func__, __LINE__)

/**
 * os_pool.h
 *
 * \brief   Dump the pool buffers of the specified memory pool.
 *
 * \param   handle  The handle of the memory pool buffer to be dumped. If the
 *                      memory pool handle is invalid, all created memory pools
 *                      will be dumped.
 *
 * \return     None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * #define BUF_SIZE1 0x40
 * #define BUF_NUM1  16
 * #define BUF_SIZE2 0x20
 * #define BUF_NUM2  8
 *
 * int test(void)
 * {
 *     uint8_t handle;
 *     void *p_buf;
 *
 *     // Create a memory pool capable of containing 16 buffers.
 *     if (os_pool_create(&handle, RAM_TYPE_DATA_ON, BUF_SIZE1, BUF_NUM1) == true)
 *     {
 *         // Memory pool created successfully.
 *     }
 *     else
 *     {
 *         // Memory pool failed to create.
 *         return -1;
 *     }
 *
 *     // Extend the memory pool to have extra 8 buffers each in 0x20 bytes.
 *     os_pool_extend(handle, BUF_SIZE2, BUF_NUM2);
 *
 *     // Allocate a pool buffer in 0x30 bytes. While, the memory pool will
 *     // give a buffer in 0x40 bytes.
 *     p_buf = os_buffer_get(handle, 0x30);
 *
 *     // Dump the memory pool.
 *     os_pool_dump(handle);
 *
 *     return 0;
 * }
 * \endcode
 *
 */
extern void (*os_pool_dump)(uint8_t handle);

/** End of group OS_POOL_Exported_Functions
  * @}
  */

/** End of OS_POOL
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif  /* _OS_POOL_H_ */
