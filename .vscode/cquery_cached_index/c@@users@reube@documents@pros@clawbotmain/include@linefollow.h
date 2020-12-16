#ifndef _LINEFOLLOW_H_
#define _LINEFOLLOW_H_
#include "main.h"

void linefollow()
{
    int LineLeft = analogReadCalibrated(1);
    int LineCenter = analogReadCalibrated(2);
    int LineRight = analogReadCalibrated(3);
}

#endif