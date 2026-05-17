/*
  Build for Arduino Uno/ MKE-Creator
  Use 4 PWM pins
*/
//Khai báo thư viện
#include "Long_SimpleMotor.h"

// Định nghĩa chân cho L9110
#define PIN_IN1 3  //! D3  (~) --> A-1B
#define PIN_IN2 9  //! D9  (~) --> A-1A (chan +)
#define PIN_IN3 10 //! D10 (~) --> B-1A (chan +)
#define PIN_IN4 11 //! D11 (~) --> B-1B


/*Định nghĩa chân
#define PIN_IN1 3  //! D3  (~) --> A-1B
#define PIN_IN2 9  //! D9  (~) --> A-1A
#define PIN_IN3 10 //! D10 (~) --> B-1A
#define PIN_IN4 11 //! D11 (~) --> B-1B
*/

//Khai báo đối tượng d9110 thuộc class Makerlabvn_SimpleMotor
Long_SimpleMotor d9110;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Start Test, input from 0 (OFF) to 8");
  Serial.println("Baud 115200, No line ending");
  d9110.setup(PIN_IN1, PIN_IN2, PIN_IN3, PIN_IN4);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    int tempInput = Serial.read();

    switch (tempInput) {
      case '0':
        // digitalWrite(2, HIGH);
        Serial.println("Hai động cơ đứng yên");
        d9110.motorA_stop();
        d9110.motorB_stop();
        break;
      case '1':
        // digitalWrite(3, HIGH);
        Serial.println("Điều khiển động cơ kênh A - Quay thuận 100%");
        d9110.motorA_fw(100);
        d9110.motorB_stop();
        //delay(5000);
        break;
      case '2':
        // digitalWrite(3, HIGH);
        Serial.println("Điều khiển động cơ kênh A - Quay thuận 50%");
        d9110.motorA_fw(50);
        d9110.motorB_stop();
        //delay(5000);
        break;
      case '3':
        // digitalWrite(4, HIGH);
        Serial.println("Điều khiển động cơ kênh A - Quay ngược 100%");
        d9110.motorA_bw(100);
        d9110.motorB_stop();
        break;
      case '4':
        // digitalWrite(4, HIGH);
        Serial.println("Điều khiển động cơ kênh A - Quay ngược 50%");
        d9110.motorA_bw(50);
        d9110.motorB_stop();
        break;
      case '5':
        // digitalWrite(5, HIGH);
        Serial.println("Điều khiển động cơ kênh B - Quay thuận 100%");
        d9110.motorB_fw(100);
        d9110.motorA_stop();
        break;
      case '6':
        // digitalWrite(5, HIGH);
        Serial.println("Điều khiển động cơ kênh B - Quay thuận 50%");
        d9110.motorB_fw(50);
        d9110.motorA_stop();
        break;
      case '7':
        // digitalWrite(6, HIGH);
        Serial.println("Điều khiển động cơ kênh B - Quay ngược 100%");
        d9110.motorB_bw(100);
        d9110.motorA_stop();
        break;
      case '8':
        // digitalWrite(6, HIGH);
        Serial.println("Điều khiển động cơ kênh B - Quay ngược 50%");
        d9110.motorB_bw(50);
        d9110.motorA_stop();
        break;
      default:
        // d9110.motorA_stop();
        // d9110.motorB_stop();
        break;
        
    }
  }

}
