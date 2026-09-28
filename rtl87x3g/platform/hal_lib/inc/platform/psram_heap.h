/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _DSP_SYS_RAM_HEAP_CONFIG_H_
#define _DSP_SYS_RAM_HEAP_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                               Header Files
*============================================================================*/

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


/**
 * @brief Initialize the PSRAM heap for dynamic memory allocation.
 *
 * This function sets up a memory region as the PSRAM heap, which is used for dynamic memory
 * allocation within the DSP system. It must be called before any allocation or freeing
 * operations from the heap.
 *
 * @param addr Pointer to the starting address of the memory region to be used as the heap.
 * @param size Size (in bytes) of the memory region to use for the heap.
 */
void psram_heap_init(uint8_t *addr, uint32_t size);

/**
 * @brief Allocate a memory block from the PSRAM heap.
 *
 * Allocates a block of memory of the specified size from the previously initialized PSRAM heap.
 * Returns a pointer to the allocated block, or NULL if allocation fails (e.g., due to insufficient heap memory).
 *
 * @param xWantedSize Size (in bytes) of the memory block to allocate.
 * @return Pointer to the allocated memory block, or NULL if allocation fails.
 */
void *psram_heap_malloc(size_t xWantedSize);

/**
 * @brief Free a previously allocated memory block back to the PSRAM heap.
 *
 * Deallocates a memory block previously allocated with psram_heap_malloc(), making it available for
 * future allocations. The pointer must not have been already freed.
 *
 * @param pv Pointer to the memory block to free.
 */
void psram_heap_free(void *pv);

/**
 * @brief Get the current available free heap size in the PSRAM heap.
 *
 * Returns the total amount of free memory, in bytes, remaining in the PSRAM heap.
 *
 * @return The number of free bytes currently available in the heap.
 */
uint32_t psram_get_free_heap_size(void);

/**
 * @brief Get the minimum ever free heap size recorded since initialization.
 *
 * Returns the minimum amount of free heap memory (in bytes) that has ever been available since
 * the heap was initialized. Useful for tracking peak memory usage.
 *
 * @return The minimum number of free bytes ever available in the heap.
 */
uint32_t psram_get_ever_free_heap_size(void);


#ifdef __cplusplus
}
#endif

#endif

