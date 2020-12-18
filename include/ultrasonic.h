#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_
#include "main.h"
#include "chassis.h"

void follow1D()
{
    int ultrasonicRight = ultrasonicGet(sonarRight);
    int ultrasonicLeft = ultrasonicGet(sonarLeft);
    int ultrasonicAverage = (ultrasonicRight + ultrasonicLeft)/2;

    //Print values out for debugging
    // printf("untrasonic distance right: %d\n\n", ultrasonicRight);
    // printf("untrasonic distance left: %d\n\n", ultrasonicLeft);
    // printf("untrasonic distance average: %d\n\n", ultrasonicAverage);

    delay(100);

    if (ultrasonicAverage > 30 && ultrasonicAverage < 100)
    {
      chassisSet(50, 50);
    }
    else if (ultrasonicAverage < 15)
    {
      chassisSet(-50, -50);
    }
    else
    {
      chassisSet(0, 0);
    }
}
void follow2D()
{
    int ultrasonicRight = ultrasonicGet(sonarRight);
    int ultrasonicLeft = ultrasonicGet(sonarLeft);

    delay(100);

    if ((ultrasonicRight < 5 || ultrasonicRight > 100) && ultrasonicLeft > 5)
    {
        chassisSet(-50, 50);
    }
    else if ((ultrasonicLeft < 5 || ultrasonicLeft > 100) && ultrasonicRight > 5)
    {
        chassisSet(50, -50);
    }
    else if (ultrasonicLeft > 5 && ultrasonicRight > 5 && ultrasonicLeft < 100 && ultrasonicRight < 100)
    {
        follow1D();
    }
}

#endif