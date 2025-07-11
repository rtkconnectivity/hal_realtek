

#define ACTIVE 1
#define NOT_ACTIVE 0
#define CONFIG_OSIF_TIMER_MAX_COUNT 20
#define TASK_SEM_ARRAY_NUMBER 5
#define CONFIG_ZEPHYR_PRI_MAX 6

typedef enum
{
    SCHEDULER_SUSPENDED = 0,
    SCHEDULER_NOT_STARTED = 1,
    SCHEDULER_RUNNING = 2
} SCHEDULER_STATE;

typedef enum
{
    TimerOnce               = 0,          /* /< One-shot timer. */
    TimerPeriodic           = 1           /* /< Repeating timer. */
} TimerType;

struct osif_timer
{
    struct k_timer ztimer;
    TimerType type;
    uint32_t interval_ms;
    uint32_t timer_id;
    uint32_t status;
    const char *name;
};

typedef struct
{
    void *task_handle;
    void *sem_handle;
} task_sem_item;

typedef void (*PendedFunctionOS_t)(void *para1, uint32_t para2);
typedef struct pend_call
{
    struct k_work work;
    PendedFunctionOS_t Pend_func;
    void *para1;
    uint32_t para2;
} Pend_Call;
