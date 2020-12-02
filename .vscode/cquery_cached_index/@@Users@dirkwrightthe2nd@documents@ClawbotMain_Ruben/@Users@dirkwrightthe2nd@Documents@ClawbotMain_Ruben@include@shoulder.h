#ifndef _SHOULDER_H_
#define _SHOULDER_H_

#include "main.h"


void shoulderSet(int speed)
{
  motorSet(5, -speed);
}

void zeroShoulderSet(int lowerLimitPosition)
{
  printf("shoulder homing started \n");
  //Turn on shoulder in negative direction while the limit switch is up
  while (digitalRead(5))
  {
    shoulderSet(-60);
  }
  //stop the motor
  shoulderSet(0);
  //set shoulder encoder to lowerLimitPosition
  encoderReset(shoulderEncoder);
  //Turn on shoulder moter in positive direction
  //Stop when the encoder position equals the home position
  while (encoderGet(shoulderEncoder) < lowerLimitPosition)
  {
    shoulderSet(127);
  }
  shoulderSet(0);
  encoderReset(shoulderEncoder);
  printf("shoulder homing complete \n");
}

void setShoulderPos(int TARGET)
{
  int Kp = 1;
  int MAX_OUT = 127;
  int error;
  int output;

  error = TARGET - encoderGet(shoulderEncoder);
  output = Kp * error;
  if (abs(error) < MAX_OUT)
  {
    shoulderSet(output);
  }
  else
  {
    shoulderSet(output / abs(output) * MAX_OUT);
  }
}

#endif
