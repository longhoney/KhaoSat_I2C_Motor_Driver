#include <Wire.h>
#include "Long_SimpleMotor.h"

// Định nghĩa chân cho L9110
#define PIN_IN1 3  //! D3  (~) --> A-1B
#define PIN_IN2 9  //! D9  (~) --> A-1A (chan +)
#define PIN_IN3 10 //! D10 (~) --> B-1A (chan +)
#define PIN_IN4 11 //! D11 (~) --> B-1B



// Định nghĩa chân cho MKE-Creator // KHONOG THAY DOI TOC DO DUOC
// Định nghĩa chân cho L298
// #define PIN_ENA 6 //! D6 (~)
// #define PIN_IN1 9 //! D9 (~)
// #define PIN_IN2 8 //! D8 --> (chan +), gan cong nap code
// #define PIN_IN3 4 //! D4 --> (chan +), gan cong nap code
// #define PIN_IN4 7 //! D7 
// #define PIN_ENB 5 //! D5 (~)

//Khai bao bien gop byte
String dataHex = "";

//Khai bao doi tuong
Long_SimpleMotor d9110;

void setup() {
  Wire.begin(64);                // join I2C bus with address #8 //dia chi I2C cua Slave dang thap phan
  Wire.onReceive(receiveEvent); // register event //con tro ham
  Serial.begin(115200);           // start serial for output //UArt1
  d9110.setup(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4);
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) { //dem Byte nhan ve
  while (Wire.available()) { // loop through all but the last //sanSang //chua 1 byte
    byte c = Wire.read(); // receive byte as a character
    // Serial.print(c,HEX);         // print the character in Hex format
    // Serial.print(c);
    // Serial.print(" ");  //leave space
   
    // In HEX và ghép chuỗi
    dataHex += String(c, HEX);
  }
  // Chuyển thành chữ HOA cho dễ so sánh
  dataHex.toUpperCase();
  
  Serial.print("Nhan duoc: ");
  Serial.println(dataHex);

    // So sánh lệnh
  if (dataHex == "40107F1C1") {
    dataHex = ""; //Xoa noi dung cu
    Serial.println("Động cơ A quay thuận, tốc độ 50%");
    d9110.motorA_fw(50);
  }
  else if (dataHex == "40100142") {
    dataHex = ""; //Xoa noi dung cu
    Serial.println("Động cơ A ngừng quay thuận");
    d9110.motorA_stop(); //tam thoi dung chung
  }
  else if (dataHex == "4010FF040") {
    dataHex = ""; //Xoa noi dung cu
    Serial.println("Động cơ A quay nghịch, tốc độ 100%");
    d9110.motorA_bw(100);
    // Serial.println("Động cơ A quay nghịch, tốc độ 50%");
    // d9110.motorA_bw(50);
  }
  else if (dataHex == "40100041") {
    dataHex = ""; //Xoa noi dung cu
    Serial.println("Động cơ A ngừng quay nghịch");
    d9110.motorA_stop(); //tam thoi dung chung
  }
  else {
    dataHex = ""; //Xoa noi dung cu
    Serial.println("Lenh khong hop le");
  }
  
  // int x = Wire.read();    // receive byte as an integer
  // Serial.print("\t");
  // Serial.println(x,HEX);         // print the integer
}