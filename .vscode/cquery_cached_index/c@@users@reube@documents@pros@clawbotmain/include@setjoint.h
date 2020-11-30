#include "main.h"
#include "shoulder.h"
#ifndef _SETJOINT_H_
#define _SETJOINT_H_

int encoderError = 2;
bool shoulderReleased = true;

void setShoulderPos(int degrees)
{
  shoulderReleased = false;
  while (!shoulderReleased)
  {
    if (encoderGet(shoulderEncoder) > encoderError + degrees)
    {
      while (encoderGet(shoulderEncoder) > encoderError + degrees)
      {
        shoulderSet(-60);
      }
    }
    else if (encoderGet(shoulderEncoder) < degrees - encoderError)
    {
      while (encoderGet(shoulderEncoder) < degrees - encoderError)
      {
        shoulderSet(60);
      }
    }
    else
    {
      shoulderSet(0);
    }
  }
}
#endif