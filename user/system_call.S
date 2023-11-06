#include "kernel/core/include/tos_system_call.h"

.global read
read:
    LDR R7, =SYS_READ
    SVC #0
    BX  LR