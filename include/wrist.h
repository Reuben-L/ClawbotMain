#ifndef _WRIST_H_
#define _WRIST_H_
#include "main.h"

void wristSet(int speed)
{ motorSet(3, -speed); }

#endif
