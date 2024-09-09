#ifndef OS_CFG_H
#define OS_CFG_H

/**
 * @struct T_OS_CFG
 * @brief FreeRTOS EFuse settings.
 *
 * Refer to EFUSE[0x].
 */
#include <stdint.h>
#include <stdbool.h>

typedef struct t_efuse_os_cfg
{
    uint8_t getStackHighWaterMark : 1;         /* 0 for release version, 1 for debug version */
    uint8_t checkForStackOverflow : 1;         /* 0 for release version, 1 for debug version */
    uint8_t printAllLogBeforeEnterLowpower : 1;    /* 0 for release version, 1 for debug version */
    uint8_t dumpMemoryWhenHardFaultOrWDG : 1;  /* 0 for release version, 1 for debug version */
    uint8_t dumpMemoryUsage : 1;               /* 0 for release version, 1 for debug version */
    uint8_t enableASSERT: 1;                   /* 0 for release version, 1 for debug version */
    uint8_t printDLPSCheckLog: 1;              /* default = 0 */
    uint8_t rsvd0: 1;

    uint8_t wdgConfigDivfactor;                /* refer to WDG_Config(), default = 15 */
    uint8_t wdgConfigCntLimit  : 4;            /* refer to WDG_Config(), default = 15 */
    uint8_t wdgEnableInRom : 1;     /* 1 for release version, 0 for debug version. default = 0 */
    uint8_t wdgResetInRom :  1;     /* 1 for release version, 0 for debug version. default = 0 */
    uint8_t wdgMode : 2;            /* 0: interrupt CPU,     1: reset all but aon
                                       2: reset core domain, 3: reset all */

    uint8_t  timerMaxNumber;                   /* default = 0x20 */
    uint8_t  timerQueueLength;                 /* default = 0x20 */
    uint8_t  UseAliOS  : 1;
    uint8_t  combine_lowerstack_and_timer_task  : 1; /* combine tasks to save stack ram */
    uint8_t  reserved  : 6;
    uint16_t  dyn_malloc_task_stack_size;

    uint32_t appDataAddr;
    uint32_t appDataSize;
    uint32_t heapDataONSize;
    uint32_t heapBufferONSize;

    uint16_t idle_task_stack_size;             /* measured in bytes, default 256 * 4 bytes */
    uint16_t timer_task_stack_size;            /* measured in bytes, default 256 * 4 bytes */
    uint16_t lower_task_stack_size;            /* measured in bytes, default 768 * 4 bytes */
} __attribute__((packed)) T_OS_CFG;


extern T_OS_CFG os_cfg;
typedef bool (*BOOL_APP_PATCH_FUNC)();
extern uint16_t (*get_lower_task_stack_size)(void);

#endif // OS_CFG_H
