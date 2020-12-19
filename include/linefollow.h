#ifndef _LINEFOLLOW_H_
#define _LINEFOLLOW_H_
#include "main.h"

void linefollow()
{
    int LineLeft = analogReadCalibrated(1);
    int LineCenter = analogReadCalibrated(2);
    int LineRight = analogReadCalibrated(3);
    const int speed = 30;

    //Print values out for debugging
    printf("Line sensors: (%d,%d,%d) ", LineLeft, LineCenter, LineRight);

    if (LineCenter > LineLeft && LineCenter > LineRight)
    {
        chassisSet(speed+10, speed+10);
        printf("[Forwards]\n");
    }
    else if (LineRight > LineCenter && LineRight > LineLeft)
    {
        chassisSet(speed, -speed);
        printf("[Right]\n");
    }
    else if (LineLeft > LineCenter && LineLeft > LineRight)
    {
        chassisSet(-speed, speed);
        printf("[Left]\n");
    }
    else
    {
        chassisSet(-speed, -speed);
        printf("[Backwards]\n");
    }
}

#endif