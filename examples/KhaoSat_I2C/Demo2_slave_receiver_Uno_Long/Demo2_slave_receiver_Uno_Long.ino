// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

// char c = 0;

void setup() {
  Wire.begin(64);                // join I2C bus with address #8 //dia chi I2C cua Slave dang thap phan
  Wire.onReceive(receiveEvent); // register event //con tro ham
  Serial.begin(115200);           // start serial for output //UArt1
}

void loop() {
  

  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) { //dem Byte nhan ve
  while (0 < Wire.available()) { // loop through all but the last //sanSang //chua 1 byte
    char c = Wire.read(); // receive byte as a character
    // Serial.print(c,HEX);         // print the character in Hex format
    // Serial.print(c);
    // Serial.print(" ");  //leave space
    
    if (Serial.available() > 0) {
      switch (c) {
        case '40107F1FFFFFFC1':   //Động cơ A quay thuận, tốc độ 50%
          // digitalWrite(2, HIGH);
          Serial.println("Động cơ A quay thuận, tốc độ 50%");
          break;
        case '40100142':    //Động cơ A ngừng quay thuận
          // digitalWrite(3, HIGH);
          Serial.println("Động cơ A ngừng quay thuận");
          break;
        case '4010FFFFFFFF040':   //Động cơ A quay nghịch, tốc độ 100%
          // digitalWrite(4, HIGH);
          Serial.println("Động cơ A quay nghịch, tốc độ 100%");
          break;
        case '40100041':    //Động cơ A ngừng quay nghịch
          // digitalWrite(5, HIGH);
          Serial.println("Động cơ A ngừng quay nghịch");
          break;
      }
    }
  }
  // int x = Wire.read();    // receive byte as an integer
  // Serial.print("\t");
  // Serial.println(x,HEX);         // print the integer
}