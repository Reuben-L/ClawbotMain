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
  int lastAngleShoulder = 0;
  int lastAngleElbow = 0;

  while (!joystickGetDigital(1, 8, JOY_LEFT))
  {
    printf("wating for da button \n");
 }
  zeroElbowSet(60);
  zeroShoulderSet(90);

  while (1)
  {
    int power, turn;

    //drive base control
    power = joystickGetAnalog(1, 1); // vertical axis on left joystick
    turn = joystickGetAnalog(1, 2);  // horizontal axis on left joystick
    chassisSet(power + turn, power - turn);

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
    int ultrasonic = ultrasonicGet(sonar);
    printf("untrasonic distance: %f\n\n", ultrasonic);

    delay(100);

    if (ultrasonic > 20)
    {
      chassisSet(100, 100);
    }
    else if (ultrasonic < 15)
    {
      chassisSet(-100, -100);
    }
    else
    {
      chassisSet(0, 0);
    }
  }
}
