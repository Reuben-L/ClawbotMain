#ifndef _ELBOW_H_
#define _ELBOW_H_

#include "main.h"


void elbowSet(int speed)
{
    motorSet(4, speed);
}
void zeroElbowSet(int lowerLimitPosition)
{
    printf("elbow homing started \n");
    //Turn on elbow in negative direction while the limit switch is up
    while (digitalRead(3))
    {
        elbowSet(-60);
    }
    //stop the motor
    elbowSet(0);
    //set shoulder encoder to lowerLimitPosition
    encoderReset(elbowEncoder);
    //Turn on shoulder moter in positive direction
    //Stop when the encoder position equals the home position
    while (encoderGet(elbowEncoder) < lowerLimitPosition)
    {
        elbowSet(127);
    }
    elbowSet(0);
    encoderReset(elbowEncoder);
    printf("elbow homing complete \n");
}

void setElbowPos(int TARGET)
{
    int Kp = 1;
    int MAX_OUT = 127;
    int error;
    int output;

    error = TARGET - encoderGet(elbowEncoder);
    output = Kp * error;
    if (abs(error) < MAX_OUT)
    {
        elbowSet(output);
    }
    else
    {
        elbowSet(output / abs(output) * MAX_OUT);
    }
}
#endif
