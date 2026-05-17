// Thêm bộ thư viện
// Add the library.
#include "Makerlabvn_I2C_Motor_Driver.h"

// Khai báo module.
// Declare module.
Makerlabvn_I2C_Motor_Driver myDriver(0);

unsigned long timeDelay = 2000; //2000ms 

void setup()
{
  // Khởi động kết nối Serial UART ở tốc độ 115200 để truyền dữ liệu lên máy tính.
  // Start the Serial UART connection at 115200 to transfer data to the computer.
  Serial.begin(115200);

  // Khởi tạo module
  // init module
  myDriver.begin();
}

void loop()
{                        //(pwm: 0-100)
  // run(45, 135, 1, 5); // vom do dc 2.5vdc tai pwm =5 (vm 5vdc) 
  // run(90, 90, 1, 0);
  run(135, 45, 0, 50); //vom do duoc 4vdc tai pwm = 50
  // run(0, 0, 0, 0);
}

/**
 * void run (angel_RC1, angel_RC1, Dir_DC, SpeedDC)
 *    angle (0->180)
 *    dir (0_>1)    
 *    Speed (0->100)
 */
void run(uint8_t s1_Value, uint8_t s2_Value, uint8_t dir_Value, uint8_t speed_Value){
  // Gán giá trị module
  // Set data module
  myDriver.writeS1(s1_Value);
  myDriver.writeS2(s2_Value);
  myDriver.writeMA(dir_Value, speed_Value);
  myDriver.writeMB(dir_Value, speed_Value);

  // Hiển thị giá trị của module lên máy tính.
  // Show the module value on Arduno Serial Monitor
  Serial.print(String() + F("RC1: ") + s1_Value);
  Serial.print(String() + F("\t RC2: ") + s2_Value);
  Serial.print(String() + F("\t DC_DIR: ") + dir_Value);
  Serial.println(String() + F("\t DC_SPEED: ") + speed_Value);

  // Chờ timeDelay ms
  // Wait timeDelay ms
  delay(timeDelay);
}