/*
  Kết hợp chương trình Test_Motor (Makerlabvn_SimpleMotor) và switchCase2.
  Lấy ý tưởng từ chương trình B7_Full_Test_I2C_Motor_Driver (Makerlabvn_I2C_Motor_Driver)
*/

//Khai báo thư viện
#include "Makerlabvn_SimpleMotor.h"

//Định nghĩa chân
#define PIN_IN1 4 //! D4     --> A-1A
#define PIN_IN2 5 //! D5 (~) --> A-1B
#define PIN_IN3 6 //! D6 (~) --> B-1A
#define PIN_IN4 7 //! D7     --> B-1B

//Khai báo đối tượng d9110 thuộc class Makerlabvn_SimpleMotor
Makerlabvn_SimpleMotor d9110;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Start Test, input from 0 (OFF) to 8");
  Serial.println("Baud 115200, No line ending");
  d9110.setup(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if (Serial.available() > 0)
  // {
    
  // }
  
  // switch (tempInput)

  if (Serial.available() > 0) {
    int tempInput = Serial.read();

    switch (tempInput) {
      case '0':
        // digitalWrite(2, HIGH);
        Serial.println("Hai động cơ đứng yên");
        d9110.motorA_stop();
        break;
      case '1':
        // digitalWrite(3, HIGH);
        Serial.println("Điều khiển động cơ kênh A - Quay thuận 100%");
        d9110.motorA_fw(100);
        delay(5000);
        break;
      case '3':
        // digitalWrite(4, HIGH);
        Serial.println("Điều khiển động cơ kênh A - Quay ngược 100%");
        d9110.motorA_bw(100);
        break;
      case '5':
        // digitalWrite(5, HIGH);
        Serial.println("Điều khiển động cơ kênh B - Quay thuận 100%");
        d9110.motorB_fw(100);
        break;
      case '7':
        // digitalWrite(6, HIGH);
        Serial.println("Điều khiển động cơ kênh B - Quay ngược 100%");
        d9110.motorB_bw(100);
        break;
      /*
      default:
        // turn off motor
        // for (int thisPin = 2; thisPin < 7; thisPin++) {
        //   digitalWrite(thisPin, LOW);
        // }
        Serial.println("Hai động cơ đứng yên");
        d9110.motorA_stop();
      */
    }
  }

}
