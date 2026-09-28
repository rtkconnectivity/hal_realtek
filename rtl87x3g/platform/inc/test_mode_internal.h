#ifndef __TEST_MODE_INTERNAL_H
#define __TEST_MODE_INTERNAL_H


#include "stdint.h"
#include "stdbool.h"


typedef struct
{
    bool is_test_mode;
} MCU_TEST_MODE_CFG;


extern MCU_TEST_MODE_CFG mcu_test_mode_cfg;


bool is_mcu_test_mode(MCU_TEST_MODE_CFG *p_cfg);

void mcu_test_mode_setting(MCU_TEST_MODE_CFG *p_cfg);


#endif


