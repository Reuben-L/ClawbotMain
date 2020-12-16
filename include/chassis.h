#ifndef _CHASSIS_H_
#define _CHASSIS_H_
#include "main.h"

// Sets the speeds of the left and right wheels of the chassis

void chassisSet(int left, int right) {
  motorSet(6, left);
  motorSet(7, -right);
}

#endif // _CHASSIS_H_
