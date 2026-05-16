/*Sử dụng switchCase2 để chọn nội dung truyền đi. 
    1 là Động cơ A quay thuận, tốc độ 50%. 
    2 là Động cơ A ngừng quay thuận. 
    3 là Động cơ A quay nghịch, tốc độ 100%. 
    4 là Động cơ A ngừng quay nghịch
*/
#include <Wire.h>
#include "Makerlabvn_SimpleMotor.h"

#define PIN_IN1 4 //! D4     --> A-1B
#define PIN_IN2 5 //! D5 (~) --> A-1A
#define PIN_IN3 6 //! D6 (~) --> B-1A
#define PIN_IN4 7 //! D7     --> B-1B

char tempInput = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin(); // join I2C bus (address optional for master)
}

// byte x = 0;

void loop() {
  /*
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  x++;
  delay(500);
  */
  if (Serial.available() > 0) {
    tempInput = Serial.read();
    Serial.write(tempInput);
  }

  if (tempInput == '1') {   //Quay thuan, 50%
    delay(15);
    Wire.beginTransmission(40); // transmit to device #40
    Wire.write("T50");        // sends five bytes
    Wire.endTransmission();    // stop transmitting
  }
  else if (tempInput == '2') {    //Ngung quay thuan
    delay(15);
    Wire.beginTransmission(40); // transmit to device #40
    Wire.write("STT");        // sends five bytes
    Wire.endTransmission();    // stop transmitting
  }
  else if (tempInput == '3') {    //Quay nghich, 100%
    delay(15);
    Wire.beginTransmission(40); // transmit to device #40
    Wire.write("N100");        // sends five bytes
    Wire.endTransmission();    // stop transmitting
  }
  else if (tempInput == '4') {    //Ngung quay ngich
    delay(15);
    Wire.beginTransmission(40); // transmit to device #40
    Wire.write("STN");        // sends five bytes
    Wire.endTransmission();    // stop transmitting
  }
  tempInput = 0;
}
