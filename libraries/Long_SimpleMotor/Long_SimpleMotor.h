#ifndef LONG_SIMPLE_MOTOR_H
#define LONG_SIMPLE_MOTOR_H

/*
 * Quy ước:
 * -" Kênh A" của driver điều khiển "động cơ bên TRÁI" của xe.
 * - "Kênh B" của driver điều khiển "động cơ bên PHẢI" của xe.
*/

/* ------------------------------------------------------------------------- */
/*                                  LIBRARY                                  */
/* ------------------------------------------------------------------------- */
#include <Arduino.h>
#include "kxnTask.h"
#include "Makerlabvn_I2C_Motor_Driver.h"

// Khai báo giá trị quy định loại motor driver đang sử dụng
enum{   //https://topdev.vn/blog/kieu-enum-trong-c-c-code-vi-du-enumeration-trong-c-c/
  Long_SimpleMotor_Type_L298_4Pin,   //Truoc mat chi dung voi L9110
  Long_SimpleMotor_Type_L298_6Pin, 
  Long_SimpleMotor_Type_I2C,
};

//Khai báo giá trị quy định trạng thái của motor driver
enum{
  Long_SimpleMotor_State_moveFrom0,
  Long_SimpleMotor_State_moveFromCW,
  Long_SimpleMotor_State_moveFromCCW,
  Long_SimpleMotor_State_StopThenMoveFrom0,
};

/* ------------------------------------------------------------------------- */
/*                                   CLASS                                   */
/* ------------------------------------------------------------------------- */
// https://topdev.vn/blog/co-ban-ve-class-trong-c/
// https://www.geeksforgeeks.org/cpp/c-classes-and-objects/
class Long_SimpleMotor: public kxnTask    //class này đang kế thừa (inheritance) từ class kxnTask
{
  private:  // Thuộc tính private 1
    uint8_t type;
    uint8_t i2cAddress;
    int kxnSpeedA, kxnSpeedB;
    int lastSpeedA, lastSpeedB;
    Makerlabvn_I2C_Motor_Driver *i2cMotorDriver;
  public: // Thuộc tính public 1
    /* ------------------------------- HÀM TẠO ------------------------------- */
    Long_SimpleMotor(){}
    
    Long_SimpleMotor(   // Driver có 4 chân điều khiển (L9110)
        uint8_t pinIn1, uint8_t pinIn2,
        uint8_t pinIn3, uint8_t pinIn4
    );

    Long_SimpleMotor(   // Driver có 2 chân tốc độ và 4 chân điều khiển (L298)
        uint8_t pinEnA, uint8_t pinIn1, uint8_t pinIn2,
        uint8_t pinIn3, uint8_t pinIn4, uint8_t pinEnB
    );

    Long_SimpleMotor(   // Địa chỉ I2C
      uint8_t paI2cAddress
    );

    void setup(uint8_t paAddress);    //Khởi tạo với địa chỉ I2C...
      // xxxx.setup(40) --> Địa chỉ 0x40

    void setup(   //Khởi tạo với thiết bị gồm 4 chân quy định như sau ...
      uint8_t pinIn1, uint8_t pinIn2,
      uint8_t pinIn3, uint8_t pinIn4
    );
    
    void setup(
      uint8_t pinEnA, uint8_t pinIn1, uint8_t pinIn2,
      uint8_t pinIn3, uint8_t pinIn4, uint8_t pinEnB
    );

  /* ------------------------- HÀM ĐIỀU KHIỂN MOTOR ------------------------ */

    void motorA_fw(int speed); // Điều khiển motor kênh A quay thuận
    void motorB_fw(int speed); // Điều khiển motor kênh B quay thuận

    void motorA_bw(int speed); // Điều khiển motor kênh A quay ngược
    void motorB_bw(int speed); // Điều khiển motor kênh B quay ngược

    void motorA_stop(); // Điều khiển motor kênh A dừng lại
    void motorB_stop(); // Điều khiển motor kênh B dừng lại

    /* -------------------------- HÀM ĐIỀU KHIỂN XE -------------------------- */

    void car_fw(int speedA, int speedB); // Điều khiển xe đi tới
    void car_bw(int speedA, int speedB); // Điều khiển xe đi lùi

    void car_rotateL(int speed); // Điều khiển xe xoay trái
    void car_rotateR(int speed); // Điều khiển xe xoay phải

    void car_stop(); // Điều khiển xe dừng lại

    void car_run(int speedA, int speedB);

    void loop();    //Tôi ít khi thấy gọi xxxx.loop()

  private:    // Thuộc tính private 2
    /* ----------------------- (BIẾN) CẤU HÌNH CÁC PIN ----------------------- */
    uint8_t _pinIn1;
    uint8_t _pinIn2;
    uint8_t _pinIn3;
    uint8_t _pinIn4;
    uint8_t _pinEnA;
    uint8_t _pinEnB;

    /* --------------------------- (HÀM) ĐẶT TỐC ĐỘ -------------------------- */

    /**
    * Đảm bảo giá trị tốc độ (%) nhận được trong khoảng 0% đến 100%
    * Đồng thời chuyển đổi tốc độ (%) sang thang (PWM) tương ứng
    */
    int calculate_speed(int speed);
};

#endif