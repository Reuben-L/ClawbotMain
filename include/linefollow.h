#ifndef _LINEFOLLOW_H_
#define _LINEFOLLOW_H_
#include "main.h"

void linefollow()
{
    printf("starting line folow");
    int LineLeft = analogReadCalibrated(1);
    int LineCenter = analogReadCalibrated(2);
    int LineRight = analogReadCalibrated(3);

    //Print values out for debugging
    printf("Line left: %d\n\n", LineLeft);
    printf("Line center left: %d\n\n", LineCenter);
    printf("Line right: %d\n\n", LineRight);

    if (LineCenter > LineLeft && LineCenter > LineRight)
    {
        chassisSet(50, 50);
    }
    else if (LineRight > LineCenter && LineRight > LineLeft)
    {
        chassisSet(-50, 50);
    }
    else if (LineLeft > LineCenter && LineLeft > LineRight)
    {
        chassisSet(-50, 50);
    }
    else
    {
        chassisSet(-50, -50);
    }
}

#endif