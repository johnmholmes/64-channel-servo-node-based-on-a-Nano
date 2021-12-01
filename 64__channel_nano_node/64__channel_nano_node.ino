
/*
 * This node is for demonstration purpose on upto 64 servos with a single Nano and 4 16 channel servo boards
 * It uses the address of 5 and it can be used with a usb cable connected to the pc or using the RS485 bus wire method
 * The code is a colabaration with others from MERG and each module will need there I2C address setting to the ones shown below for them to work
 * please see the MIT licence before using
 * some additional libraries will need to be downloaaded and added to the arduino ide
 */
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <CMRI.h>
#include <Auto485.h>
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40); //setup the board address
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);
Adafruit_PWMServoDriver pwm3 = Adafruit_PWMServoDriver(0x42);
Adafruit_PWMServoDriver pwm4 = Adafruit_PWMServoDriver(0x43);
Auto485 bus(2); // Arduino pin 2 -> MAX485 DE and RE pins
CMRI cmri(5, 24, 48, bus); //CMRI node & Nano number address 5

int Tbit[48];          //Max bits allowed from CMRI
int currentPos1[16];   // current positions for 16 servos per board
int currentPos2[16];
int currentPos3[16];
int currentPos4[16];

void setup() {
  Serial.begin(115200);
  bus.begin(115200);     //Starts the RS485 bus
  pwm1.begin();
  pwm1.setPWMFreq(60); // This is the maximum PWM frequency
  pwm2.begin();
  pwm2.setPWMFreq(60);
  pwm3.begin();
  pwm3.setPWMFreq(60);
  pwm4.begin();
  pwm4.setPWMFreq(60);

  for (int i = 0; i < 16; i++) // set and remember initial positions using array
  {
    pwm1.setPWM(i, 0, 380);  // set initial position
    currentPos1[i] = 380;    // and remember it as current
  }
  for (int i = 0; i < 16; i++)
  {
    pwm2.setPWM(i, 0, 221);  // set initial position
    currentPos2[i] = 221;    // and remember it as current
  }

  for (int i = 0; i < 16; i++)
  {
    pwm3.setPWM(i, 0, 221);  // set initial position
    currentPos3[i] = 221;    // and remember it as current
  }

  for (int i = 0; i < 16; i++)
  {
    pwm4.setPWM(i, 0, 221);  // set initial position
    currentPos4[i] = 221;    // and remember it as current
  }
}
void loop() {
  cmri.process();
  for (int i=0; i<48; i++){
  Tbit[i] = cmri.get_bit(i);
}
  int angle;
  int i;

  if (Tbit[0] == 1) {      //Bit1 CT5001 received from CMRI when turnout/switch thrown.
    slowMove1(9, 1, 145);  //CT5001 offset by 1 from Tbit[0].
  }                        // Moves servo 9 at speed rate 1 to position 145.
  if (Tbit[0] == 0) {      //Bit0 CT5001 received from CMRI.
    slowMove1(9, 1, 400);  //Moves servo 9 speed rate 1 to position 400.
  }
  if (Tbit[1] == 1) {
    slowMove1(10, 1, 145);//CT5002
  }
  if (Tbit[1] == 0) {
    slowMove1(10, 1, 400);//CT5002
  }
  if (Tbit[2] == 1) {
    slowMove1(11, 1, 145);//CT5003
  }
  if (Tbit[2] == 0) {
    slowMove1(11, 1, 400);//CT5003
  }
  if (Tbit[3] == 1) {
    slowMove1(12, 1, 145);//CT5004
  }
  if (Tbit[3] == 0) {
    slowMove1(12, 1, 400);//CT5004
  }
   if (Tbit[4] == 1) {
    slowMove1(13, 1, 145);//CT5005
  }
  if (Tbit[4] == 0) {
    slowMove1(13, 1, 400);//CT5005
  }
  if (Tbit[5] == 1) {
    slowMove1(14, 1, 145);//CT5006
  }
  if (Tbit[5] == 0) {
    slowMove1(14, 1, 400);//CT5006
  }
  if (Tbit[6] == 1) {
    slowMove1(15, 1, 145);//CT5007
  }
  if (Tbit[6] == 0) {
    slowMove1(15, 1, 400);//CT5007
  }
//  if (Tbit[7] == 1) {
//    slowMove4(0, 1, 145);//CT5008
//  }
//  if (Tbit[7] == 0) {
//    slowMove4(0, 1, 400);//CT5008
//  }
//  if (Tbit[8] == 1) {
//    slowMove4(1, 1, 145);//CT5009
//  }
//  if (Tbit[8] == 0) {
//    slowMove4(1, 1, 400);//CT5009
//  }
//  if (Tbit[9] == 1) {
//    slowMove4(2, 1, 145);//CT5010
//  }
//  if (Tbit[9] == 0) {
//    slowMove4(2, 1, 400);//CT5010
//  }
//  if (Tbit[10] == 1) {
//    slowMove1(9, 1, 145);//CT5011
//  }
//  if (Tbit[10] == 0) {
//    slowMove1(9, 1, 400);//CT5011
//  }
//  if (Tbit[11] == 1) {
//    slowMove1(10, 1, 145);//CT5012
//  }
//  if (Tbit[11] == 0) {
//    slowMove1(10, 1, 400);//CT5012
//  }
  if (Tbit[12] == 1) {
    slowMove2(0, 1, 145);//CT5013
  }
  if (Tbit[12] == 0) {
    slowMove2(0, 1, 400);//CT5013
  }
  if (Tbit[13] == 1) {
    slowMove2(1, 1, 145);//CT5014
  }
  if (Tbit[13] == 0) {
    slowMove2(1, 1, 400);//CT5014
  }
   if (Tbit[14] == 1) {
    slowMove2(2, 1, 145);//CT5015
  }
  if (Tbit[14] == 0) {
    slowMove2(2, 1, 400);//CT5015
  }
  if (Tbit[15] == 1) {
    slowMove2(3, 1, 145);//CT5016
  }
  if (Tbit[15] == 0) {
    slowMove2(3, 1, 400);//CT5016
  }
  if (Tbit[16] == 1) {
    slowMove2(4, 1, 145);//CT5017
  }
  if (Tbit[16] == 0) {
    slowMove2(4, 1, 400);//CT5017
  }
//  if (Tbit[17] == 1) {
//    slowMove4(0, 1, 145);//CT5018
//  }
//  if (Tbit[17] == 0) {
//    slowMove4(0, 1, 400);//CT5018
//  }
//  if (Tbit[18] == 1) {
//    slowMove4(1, 1, 145);//CT5019
//  }
//  if (Tbit[18] == 0) {
//    slowMove4(1, 1, 400);//CT5019
//  }
//  if (Tbit[19] == 1) {
//    slowMove4(2, 1, 145);//CT5020
//  }
//  if (Tbit[19] == 0) {
//    slowMove4(2, 1, 400);//CT5020
//  }
//  if (Tbit[20] == 1) {
//    slowMove1(9, 1, 145);//CT5021 
//  }
//  if (Tbit[20] == 0) {
//    slowMove1(9, 1, 400);//CT5021
//  }
//  if (Tbit[21] == 1) {
//    slowMove1(10, 1, 145);//CT5022
//  }
//  if (Tbit[21] == 0) {
//    slowMove1(10, 1, 400);//CT5022
//  }
//  if (Tbit[22] == 1) {
//    slowMove4(1, 1, 145);//CT5023
//  }
//  if (Tbit[22] == 0) {
//    slowMove4(1, 1, 400);//CT5023
//  }
//  if (Tbit[23] == 1) {
//    slowMove4(2, 1, 145);//CT5024
//  }
//  if (Tbit[23] == 0) {
//    slowMove4(2, 1, 400);//CT5024
//  }
   if (Tbit[24] == 1) {
    slowMove3(13, 1, 145);//CT5025
  }
  if (Tbit[24] == 0) {
    slowMove3(13, 1, 400);//CT5025
  }
  if (Tbit[25] == 1) {
    slowMove3(14, 1, 145);//CT5026
  }
  if (Tbit[25] == 0) {
    slowMove3(14, 1, 400);//CT5026
  }
  if (Tbit[26] == 1) {
    slowMove3(15, 1, 145);//CT5027
  }
  if (Tbit[26] == 0) {
    slowMove3(15, 1, 400);//CT5027
  }
  if (Tbit[27] == 1) {
    slowMove3(0, 1, 145);//CT5028
  }
  if (Tbit[27] == 0) {
    slowMove3(0, 1, 400);//CT5028
  }
//  if (Tbit[28] == 1) {
//    slowMove4(1, 1, 145);//CT5029
//  }
//  if (Tbit[28] == 0) {
//    slowMove4(1, 1, 400);//CT5029
//  }
//  if (Tbit[29] == 1) {
//    slowMove4(2, 1, 145);//CT5030
//  }
//  if (Tbit[29] == 0) {
//    slowMove4(2, 1, 400);//CT5030
//  }
//  if (Tbit[30] == 1) {
//    slowMove1(9, 1, 145);//CT5031
//  }
//  if (Tbit[30] == 0) {
//    slowMove1(9, 1, 400);//CT5031
//  }
//  if (Tbit[31] == 1) {
//    slowMove1(10, 1, 145);//CT5032
//  }
//  if (Tbit[31] == 0) {
//    slowMove1(10, 1, 400);//CT5032
//  }
//  if (Tbit[32] == 1) {
//    slowMove4(1, 1, 145);//CT5033
//  }
//  if (Tbit[32] == 0) {
//    slowMove4(1, 1, 400);//CT5033
//  }
//  if (Tbit[33] == 1) {
//    slowMove4(2, 1, 145);//CT5034
//  }
//  if (Tbit[33] == 0) {
//    slowMove4(2, 1, 400);//CT5034
//  }
//   if (Tbit[34] == 1) {
//    slowMove4(0, 1, 145);//CT5035
//  }
//  if (Tbit[34] == 0) {
//    slowMove4(0, 1, 400);//CT5035
//  }
//  if (Tbit[35] == 1) {
//    slowMove4(1, 1, 145);//CT5036
//  }
//  if (Tbit[35] == 0) {
//    slowMove4(1, 1, 400);//CT5036
//  }
  if (Tbit[36] == 1) {
    slowMove4(0, 1, 145);//CT5037
  }
  if (Tbit[36] == 0) {
    slowMove4(0, 1, 400);//CT5037
  }
  if (Tbit[37] == 1) {
    slowMove4(1, 1, 145);//CT5038
  }
  if (Tbit[37] == 0) {
    slowMove4(1, 1, 400);//CT5038
  }
  if (Tbit[38] == 1) {
    slowMove4(2, 1, 145);//CT5039
  }
  if (Tbit[38] == 0) {
    slowMove4(2, 1, 400);//CT5039
  }
  if (Tbit[39] == 1) {
    slowMove4(3, 1, 145);//CT5040
  }
  if (Tbit[39] == 0) {
    slowMove4(3, 1, 400);//CT5040
  }
  if (Tbit[40] == 1) {
    slowMove4(15, 1, 145);//CT5041
  }
  if (Tbit[40] == 0) {
    slowMove4(15, 1, 400);//CT5041
  }
//  if (Tbit[41] == 1) {
//    slowMove1(10, 1, 145);//CT5042
//  }
//  if (Tbit[41] == 0) {
//    slowMove1(10, 1, 400);//CT5042
//  }
//  if (Tbit[42] == 1) {
//    slowMove4(1, 1, 145);//CT5043
//  }
//  if (Tbit[42] == 0) {
//    slowMove4(1, 1, 400);//CT5043
//  }
//  if (Tbit[43] == 1) {
//    slowMove4(2, 1, 145);//CT5044
//  }
//  if (Tbit[43] == 0) {
//    slowMove4(2, 1, 400);//CT5044
//  }
//   if (Tbit[44] == 1) {
//    slowMove4(0, 1, 145);//CT5045
//  }
//  if (Tbit[44] == 0) {
//    slowMove4(0, 1, 400);//CT5045
//  }
//  if (Tbit[45] == 1) {
//    slowMove4(1, 1, 145);//CT5046
//  }
//  if (Tbit[45] == 0) {
//    slowMove4(1, 1, 400);//CT5046
//  }
//  if (Tbit[46] == 1) {
//    slowMove4(2, 1, 145);//CT5047
//  }
//  if (Tbit[46] == 0) {
//    slowMove4(2, 1, 400);//CT5047
//  }
//  if (Tbit[47] == 1) {
//    slowMove4(0, 1, 145);//CT5048
//  }
//  if (Tbit[47] == 0) {
//    slowMove4(0, 1, 400);//CT5048
//  }
  }

// Checks to see if a move is needed using currentPos[]
// if so it uses for loop to move to position given in 'to' argument
// speed of the move is controlled by delayTime smaller delay = faster move

void slowMove1(int servoNum, int delayTime, int to)
{
  if (currentPos1[servoNum] == to) return;  // Nothing to do if it's already there

  else if (to > currentPos1[servoNum])
  {
    for (int i = currentPos1[servoNum]; i < to; i++)
    {
      pwm1.setPWM(servoNum, 0, i);
      delay(delayTime);
    }
  }
  else if (currentPos1[servoNum] > to)
  {
    for (int i = currentPos1[servoNum]; i > to; i--)
    {
      pwm1.setPWM(servoNum, 0, i);
      delay(delayTime);
    }
  }
  currentPos1[servoNum] = to;    // save the current servo position
}
void slowMove2(int servoNum, int delayTime, int to)
{
  if (currentPos2[servoNum] == to) return;  // Nothing to do if it's already there

  else if (to > currentPos2[servoNum])
  {
    for (int i = currentPos2[servoNum]; i < to; i++)
    {
      pwm2.setPWM(servoNum, 0, i);
      delay(delayTime);
    }
  }
  else if (currentPos2[servoNum] > to)
  {
    for (int i = currentPos2[servoNum]; i > to; i--)
    {
      pwm2.setPWM(servoNum, 0, i);
      delay(delayTime);
    }
  }
  currentPos2[servoNum] = to;    // save the current servo position
}
void slowMove3(int servoNum, int delayTime, int to)
{
  if (currentPos3[servoNum] == to) return;  // Nothing to do if it's already there

  else if (to > currentPos3[servoNum])
  {
    for (int i = currentPos3[servoNum]; i < to; i++)
    {
      pwm3.setPWM(servoNum, 0, i);
      delay(delayTime);
    }
  }
  else if (currentPos3[servoNum] > to)
  {
    for (int i = currentPos3[servoNum]; i > to; i--)
    {
      pwm3.setPWM(servoNum, 0, i);
      delay(delayTime);
    }
  }
  currentPos3[servoNum] = to;    // save the current servo position
}
void slowMove4(int servoNum, int delayTime, int to)
{
  if (currentPos4[servoNum] == to) return;  // Nothing to do if it's already there

  else if (to > currentPos4[servoNum])
  {
    for (int i = currentPos4[servoNum]; i < to; i++)
    {
      pwm4.setPWM(servoNum, 0, i);
      delay(delayTime);
    }
  }
  else if (currentPos4[servoNum] > to)
  {
    for (int i = currentPos4[servoNum]; i > to; i--)
    {
      pwm4.setPWM(servoNum, 0, i);
      delay(delayTime);
    }
  }
  currentPos4[servoNum] = to;    // save the current servo position
}
