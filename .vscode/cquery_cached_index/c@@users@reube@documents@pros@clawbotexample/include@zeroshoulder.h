#ifndef _ZEROSHOULDER_H_
#define _ZEROSHOULDER_H_
void zeroShoulderSet(int lowerLimitPosition){
  print("Button pressed");
  //Turn on shoulder in negative direction while the limit switch is up
  while(digitalRead('5') == HIGH){
    shoulderSet(-60);
  }
  //stop the motor
  shouldSet(0);
  //set shoulder encoder to lowerLimitPosition
  Encoder shoulderEncoder = encoderInit(8, 9, false);
  void encoderReset (shoulderEncoder);
  //Turn on shoulder moter in positive direction
  //Stop when the encoder position equals the home position
  while(!encoderGet (shoulderEncoder) == 0){
    shoulderSet(127);
  }
}
#endif
