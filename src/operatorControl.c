#include "main.h"
#include "chassis.h" // redundant, but ensures that the corresponding header file (chassis.h) is included
#include "claw.h"
#include "shoulder.h"
#include "elbow.h"
#include "zeroShoulder.h"
#include "setJoint.h"
#include "ultrasonic.h"
#include "linefollow.h"

void operatorControl()
{
  int loopCount = 0; //just a loop counter
  int lastAngleShoulder = 0;
  int lastAngleElbow = 0;
  int controlMode = 0; //0 is manuel control, 1 is ultrasonic control, 2 is line follow control

  while (!joystickGetDigital(1, 8, JOY_LEFT))
  {
    printf("wating for da button \n");
  }
  zeroElbowSet(60);
  zeroShoulderSet(90);

  while (1)
  {
    if (joystickGetDigital(1, 8, JOY_UP))
    {
      controlMode = 0;
    }
    else if (joystickGetDigital(1, 8, JOY_RIGHT))
    {
      controlMode = 1;
    }
    else if (joystickGetDigital(1, 8, JOY_DOWN))
    {
      controlMode = 2;
    }
    
    int power, turn;

    if (controlMode == 0)
    {
      //drive base control
      power = joystickGetAnalog(1, 2); // vertical axis on left joystick
      turn = joystickGetAnalog(1, 1);  // horizontal axis on left joystick
      chassisSet(power + turn, power - turn);
    }
    else if (controlMode = 1) 
    {
      follow1D();
    }
    else if (controlMode = 2) 
    {
      linefollow();
    }

    // controll claw with CH4 of joystick
    clawSet(joystickGetAnalog(1, 4));

    // control shoulder motor with button 6U and 6D
    if (joystickGetDigital(1, 6, JOY_UP))
    {
      shoulderSet(127);
      lastAngleShoulder = encoderGet(shoulderEncoder);
      //pressing up, so lift should go up
    }
    else if (joystickGetDigital(1, 6, JOY_DOWN))
    {
      shoulderSet(-127);
      lastAngleShoulder = encoderGet(shoulderEncoder);
      //pressing down, so lift should go down
    }
    else
    {
      setShoulderPos(lastAngleShoulder);
      // no buttons are pressed, run the cloesd loop control
    }

    // control elbow motor with button 5U and 5D
    if (joystickGetDigital(1, 5, JOY_UP))
    {
      elbowSet(127); // pressing up, so lift should go up
      lastAngleElbow = encoderGet(elbowEncoder);
    }
    else if (joystickGetDigital(1, 5, JOY_DOWN))
    {
      elbowSet(-127); // pressing down, so lift should go down
      lastAngleElbow = encoderGet(elbowEncoder);
    }
    else
    {
      setElbowPos(lastAngleElbow);
      // no buttons are pressed, run the cloesd loop control
    }
    loopCount = loopCount + 1;
    //Debuging:
    // printf("shoulder encoder at %f\n", encoderGet(shoulderEncoder));
    // printf("\n");
    // printf("elbow encoder at %f\n", encoderGet(elbowEncoder));
  }
}