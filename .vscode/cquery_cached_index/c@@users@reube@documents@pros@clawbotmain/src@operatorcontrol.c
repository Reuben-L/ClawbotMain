#include "main.h"
#include "chassis.h" // redundant, but ensures that the corresponding header file (chassis.h) is included
#include "claw.h"
#include "shoulder.h"
#include "elbow.h"
#include "zeroShoulder.h"
#include "setJoint.h"

void operatorControl()
{
  int loopCount = 0; //just a loop counter
  while (1)
  {
    int power, turn;
    if (joystickGetDigital(1, 8, JOY_LEFT))
    {
      zeroShoulderSet(90);
    }

    //drive base control
    power = joystickGetAnalog(1, 1); // vertical axis on left joystick
    turn = joystickGetAnalog(1, 2);  // horizontal axis on left joystick
    chassisSet(power + turn, power - turn);

    // controll claw with CH4 of joystick
    clawSet(joystickGetAnalog(1, 4));

    // control shoulder motor with button 6U and 6D
    if (joystickGetDigital(1, 6, JOY_UP))
    {
      shoulderSetPos(127); // pressing up, so lift should go up
    }
    else if (joystickGetDigital(1, 6, JOY_DOWN))
    {
      shoulderSetPos(-127); // pressing down, so lift should go down
    }
    else
    {
      // no buttons are pressed, run the cloesd loop control

    }

    // control elbow motor with button 5U and 5D
    if (joystickGetDigital(1, 5, JOY_UP))
    {
      elbowSet(127); // pressing up, so lift should go up
    }
    else if (joystickGetDigital(1, 5, JOY_DOWN))
    {
      elbowSet(-127); // pressing down, so lift should go down
    }
    else
    {
      elbowSet(0); // no buttons are pressed, stop the lift
    }
    loopCount = loopCount + 1;
    //Debuging:
    printf("shoulder encoder at %f\n", encoderGet(shoulderEncoder));
    if ((digitalRead(5) == HIGH))
    {
      printf("limit switch pressed \n");
    }
  }
}
