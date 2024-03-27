#ifndef __NSC_VENEER_PARAM_H__
#define __NSC_VENEER_PARAM_H__

#include <stdint.h>
#include <stdbool.h>


/*opcode EFUSE_ACCESS*/
typedef enum
{
    EFUSE_OPERATION_READ = 0,
    EFUSE_OPERATION_WRITE = 1,
} EFUSE_OPERATION_TYPE;

typedef struct
{
    EFUSE_OPERATION_TYPE type;
    uint16_t addr;
    uint16_t byte_size;
    uint8_t *data;
} NSC_EFUSE_SECURE_ACCESS_PARAM;

/*opcode EFUSE_RAM_ACCESS*/
typedef struct
{
    EFUSE_OPERATION_TYPE type;
    uint16_t offset;
    uint16_t byte_size;
    uint8_t *data;
} NSC_EFUSE_RAM_SECURE_ACCESS_PARAM;

typedef enum
{
    SECURE_REGION_READ = 0,
    SECURE_REGION_WRITE = 1,
} SECURE_REGION_ACCESS_TYPE;

typedef struct
{
    SECURE_REGION_ACCESS_TYPE access_type;
    uint32_t addr;
    uint32_t *data;
} NSC_SECURE_REGION_ACCESS_PARAM;

#endif /* __NSC_VENEER_PARAM_H__ */
