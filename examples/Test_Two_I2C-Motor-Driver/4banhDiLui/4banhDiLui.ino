#include "Makerlabvn_I2C_Motor_Driver.h"

Makerlabvn_I2C_Motor_Driver myDriver(0); //0x64 = 2 bánh trước

// Declare the second Driver with ID 1
Makerlabvn_I2C_Motor_Driver myDriver2(1);  //0x65 = 2 bánh sau //To set the ID please use Example "B3_I2C_Driver_Set_ID"

void setup() {
  // put your setup code here, to run once:
  myDriver.begin();
  myDriver2.begin();
}

void loop() {
  bool dirValue = 1;  // Direction (1 or 0)
  unsigned char speedValueInPercent = 0;  // (0%->100%)

  //Dừng động cơ
  dirValue = 1; // Direction 1
  speedValueInPercent = 0;  
  myDriver.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  delay(2000);
  
  //Đi lùi tốc độ 100%.
  dirValue = 0; // Direction 0
  speedValueInPercent = 100; // 100% (Max Speed)  
  myDriver.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  delay(5000);

  
}
