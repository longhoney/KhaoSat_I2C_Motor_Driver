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

byte x = 0;

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
    switch (tempInput) {
      case '1': //Quay thuan, 50%
        // digitalWrite(2, HIGH);
        Wire.beginTransmission(40); // transmit to device #40
        Wire.write("Quay thuan, 50%");        // sends five bytes
        Wire.endTransmission();    // stop transmitting
        break;
      case '2':
        // digitalWrite(3, HIGH);
        break;
      case '3':
        // digitalWrite(4, HIGH);
        break;
      case '4':
        // digitalWrite(5, HIGH);
        break;
      case 'e':
        // digitalWrite(6, HIGH);
        break;
      /*
      default:
        // turn all the LEDs off:
        for (int thisPin = 2; thisPin < 7; thisPin++) {
          // digitalWrite(thisPin, LOW);
        }*/
    } 
  }
}
