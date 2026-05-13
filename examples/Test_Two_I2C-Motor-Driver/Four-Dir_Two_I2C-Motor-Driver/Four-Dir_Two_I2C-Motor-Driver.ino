#include "Makerlabvn_I2C_Motor_Driver.h"

/**
 * Quy ước:
 * -" Kênh A" của driver điều khiển "động cơ bên TRÁI" của xe.
 * - "Kênh B" của driver điều khiển "động cơ bên PHẢI" của xe.
 */

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
  unsigned char speedValueInPercent = 100;  // (0%->100%)
  unsigned char speedSlow = 75;  // (0%->100%)
  unsigned char speedNo = 0;  // (0%->100%)
  
  //Xe dừng lại
  myDriver.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedNo);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedNo);    // Run motor B max Speed
  delay(2000);
  
  //Xe đi thẳng
  dirValue = 1; // Direction 1  
  myDriver.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  delay(5000);

  //Xe dừng lại
  myDriver.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedNo);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedNo);    // Run motor B max Speed
  delay(2000);

  //Xe đi lùi
  dirValue = 0; // Direction 0
  myDriver.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  delay(5000);
  
  //Xe dừng lại
  myDriver.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedNo);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedNo);    // Run motor B max Speed
  delay(2000);
  
  //Xe tiến sang phải
  dirValue = 1; // Direction 1 
  myDriver.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedSlow);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedSlow);    // Run motor B max Speed
  delay(5000);

  //Xe dừng lại
  myDriver.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedNo);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedNo);    // Run motor B max Speed
  delay(2000);
  
  //Xe tiến sang trái
  myDriver.writeMA(dirValue, speedSlow);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedSlow);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  delay(5000);

  //Xe dừng lại
  dirValue = 1; // Direction 1
  speedValueInPercent = 0; // 100% (Max Speed)  
  myDriver.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  delay(2000);

  //Xe lùi sang phải
  dirValue = 0; // Direction 0  
  myDriver.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedSlow);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedSlow);    // Run motor B max Speed
  delay(5000);

  //Xe dừng lại
  myDriver.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedNo);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedNo);    // Run motor B max Speed
  delay(2000);

  //Xe lùi sang trái
  dirValue = 0; // Direction 0 
  myDriver.writeMA(dirValue, speedSlow);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedSlow);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  delay(5000);

  //Xe dừng lại
  myDriver.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedNo);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedNo);    // Run motor B max Speed
  delay(2000);
  
  /*
  //Xe quay vòng phải
  dirValue = 1; // Direction 1 
  myDriver.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedNo);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedValueInPercent);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedNo);    // Run motor B max Speed
  delay(5000);

  //Xe dừng lại
  myDriver.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedNo);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedNo);    // Run motor B max Speed
  delay(2000);

  //Xe quay vòng trái
  dirValue = 1; // Direction 1
  speedValueInPercent = 100; // 100% (Max Speed)  
  myDriver.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  //2 bánh sau
  myDriver2.writeMA(dirValue, speedNo);    // Run motor A max Speed
  myDriver2.writeMB(dirValue, speedValueInPercent);    // Run motor B max Speed
  delay(5000);

  */
}
