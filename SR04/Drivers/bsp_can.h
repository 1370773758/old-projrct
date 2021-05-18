#ifndef __BSP_CAN_H
#define __BSP_CAN_H

#include "user_common.h"

#define PASS_ID 0x1314

void can_cfg(void);

extern CanTxMsg  CANTX;
extern CanRxMsg  CANRX;

#endif  
