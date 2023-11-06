/*----------------------------------------------------------------------------
 * Tencent is pleased to support the open source community by making TencentOS
 * available.
 *
 * Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
 * If you have downloaded a copy of the TencentOS binary from Tencent, please
 * note that the TencentOS binary is licensed under the BSD 3-Clause License.
 *
 * If you have downloaded a copy of the TencentOS source code from Tencent,
 * please note that TencentOS source code is licensed under the BSD 3-Clause
 * License, except for the third-party components listed below which are
 * subject to different license terms. Your integration of TencentOS into your
 * own projects may require compliance with the BSD 3-Clause License, as well
 * as the other licenses applicable to the third-party components included
 * within TencentOS.
 *---------------------------------------------------------------------------*/

#include "tos_k.h"

extern uint64_t sys_read(void);

static uint64_t (*syscalls[])(void) = {
    [SYS_READ] sys_read
};

int length = 1;

__KNL__ void system_call_process(void)
{
    int id = get_system_call_id();

    if (id > 0 && id < length && syscalls[id])
    {
        syscalls[id](); // 用保存在k_task_st的R0寄存器来接住这个返回值
    }
}

__KNL__ int get_system_call_id(void)
{
    
}