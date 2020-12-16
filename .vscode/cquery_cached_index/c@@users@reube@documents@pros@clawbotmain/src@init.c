#include "main.h"

/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {
  pinMode(5, INPUT);
  pinMode(3, INPUT);
}


void initialize() {
  shoulderEncoder = encoderInit(8, 9, false);
  elbowEncoder = encoderInit(7, 6, false);
  sonarRight = ultrasonicInit(1, 2);
  sonarLeft = ultrasonicInit(11, 12);
  analogCalibrate(1);
  analogCalibrate(2);
  analogCalibrate(3);
}
