#include "Makerlabvn_I2C_Motor_Driver.h"

/* Quy ước
  Kênh A điều khiển motor bên trái của xe (chiều từ đuôi xe ra đầu xe)
  Kênh B điều khiển motor bên phải của xe (chiều từ đuôi xe ra đầu xe)
*/

Makerlabvn_I2C_Motor_Driver myDriver(0); //myDriver(0) = 0x64, myDriver(1) = 0x65
void setup() {
  // put your setup code here, to run once:
  myDriver.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  bool dirValue = 1;  // Direction (1 or 0)
  unsigned char speedValueInPercent = 0;  // (0%->100%)
  myDriver.writeMA(dirValue, speedValueInPercent);    // Stop motor A
  myDriver.writeMB(dirValue, speedValueInPercent);    // Stop motor B
  delay(2000);

  dirValue = 1; // Direction 1
  speedValueInPercent = 100; // 100% (Max Speed)  
  myDriver.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  delay(5000);

  /*
  dirValue = 1; // Direction 1
  speedValueInPercent = 50; // 50%
  myDriver.writeMA(dirValue, speedValueInPercent);    // Run motor A half Speed
  myDriver.writeMB(dirValue, speedValueInPercent);    // Run motor B half Speed
  delay(2000);

  dirValue = 1; // Direction 1
  speedValueInPercent = 0; // 0% => Stop
  myDriver.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  delay(2000);

  dirValue = 0; // Direction 0
  speedValueInPercent = 50; // 50%
  myDriver.writeMA(dirValue, speedValueInPercent);    // Run motor A half Speed
  myDriver.writeMB(dirValue, speedValueInPercent);    // Run motor B half Speed
  delay(2000);

  dirValue = 0; // Direction 0
  speedValueInPercent = 100; // 100% (Max Speed)  
  myDriver.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  delay(2000);
  */
}
