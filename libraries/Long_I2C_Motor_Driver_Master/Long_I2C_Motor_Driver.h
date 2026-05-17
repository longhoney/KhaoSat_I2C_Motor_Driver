#ifndef Long_I2C_Motor_Driver_H_
#define Long_I2C_Motor_Driver_H_

#include "Arduino.h"
#include <Wire.h>

#define MAKERLABVN_I2C_DRIVER_MAX_NUMBER_DRIVER_SUPPORT (5)
#define MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MIN (64)  //Decimal
#define MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MAX (MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MIN + MAKERLABVN_I2C_DRIVER_MAX_NUMBER_DRIVER_SUPPORT - 1)

// Định nghĩa cho RC Servo
#define MAKERLABVN_I2C_DRIVER_PULSE_TIME_MAX (2350)
#define MAKERLABVN_I2C_DRIVER_PULSE_TIME_MIN (460)

// Định nghĩa số lượng DC motor và RC servo
#define MAX_I2C_MOTOR_DC_SIZE (2)
#define MAKERLABVN_I2C_DRIVER_INDEX_MA (0)
#define MAKERLABVN_I2C_DRIVER_INDEX_MB (1)
#define MAX_I2C_MOTOR_RC_SIZE (2)
#define MAKERLABVN_I2C_DRIVER_INDEX_S1 (0)
#define MAKERLABVN_I2C_DRIVER_INDEX_S2 (1)

//Định nghĩa thông số delay trước khi gửi dữ liệu đi
#define DELAY_I2C_SEND (15) //us

#define I2C_MOTOR_DRIVER_PULSE_DISABLE (3000)

typedef union myValue {   // union dùng để gộp byte pulse, dir và pwm??
  uint16_t pulse;
  struct
  {
    uint8_t dir;
    uint8_t pwm;
  };
};

typedef enum {    // enum 1: lưu định danh của RC Servo, DC motor, địa chỉ, chế độ
  RC_ID = 0,
  DC_ID,
  SADDR_ID,   //Slave address ID
  END_MODE_ID
} typeModeId;   // Tại sao nằm riêng ở ngoài??? enum 1 sẽ lưu vào biến này??

typedef enum {    // enum 2: lưu giá trị quy định trạng thái kết nối I2C
  I2C_MOTOR_DRIVER_CODE_FAIL = 0,
  I2C_MOTOR_DRIVER_CODE_SUCCESS,
  I2C_MOTOR_DRIVER_CODE_NOT_CONNECT,
  I2C_MOTOR_DRIVER_CODE_MANY_CONNECT,
  I2C_MOTOR_DRIVER_CODE_INVALID_ADDRESS,
  END_I2C_MOTOR_DRIVER_CODE
} I2C_Driver_Error_Code;

typedef struct {    // struct 1: quy định cấu trúc của frame gửi đi của RC servo
  uint8_t addressId;
  uint8_t modeId;
  uint8_t index;
  myValue value;    //gán giá trị value vào myValue
  uint8_t checkSum;
} str_serial_data_rcMotor;

typedef struct {    // Struct 2: quy định cấu trúc của frame gửi đi của DC motor
  uint8_t addressId;
  uint8_t modeId;
  uint8_t index;
  uint8_t pwm; // pwm
  uint8_t dir; // dir
  uint8_t checkSum;
} str_serial_data_dcMotor;

class Long_I2C_Motor_Driver {   //class chính của thư viện
  public:
    //gán địa chỉ I2C mặc định là giá trị địa chỉ nhỏ nhất
    Long_I2C_Motor_Driver(uint8_t _address_ = MAKERLABVN_I2C_DRIVER_SLAVE_ADDRESS_MIN);
    void begin();
    I2C_Driver_Error_Code setAddress(uint8_t _address_);
    I2C_Driver_Error_Code scanI2CAddress();
    I2C_Driver_Error_Code ReadI2cOverSerial();
    // Thông số điều khiển RC Servo và DC motor gán vào biến nội bộ _ABC_
    // Các hàm điều khiển chính
    void S1(uint16_t _pulse_us_);
    void S2(uint16_t _pulse_us_);
    void MA(bool _dir_, uint8_t _PWMspeed_);          // _PWMspeed_: (0->255) ; _dir_: (0, 1)
    void MB(bool _dir_, uint8_t _PWMspeed_);
    void writeMA(bool _dir_, uint8_t _PercentSpeed_); // _PercentSpeed_: (0->100) ; _dir_: (0, 1)
    void writeMB(bool _dir_, uint8_t _PercentSpeed_);
    void SetS1(uint16_t _pulseMin_0_Degree, uint16_t _pulseMax_180_Degree);
    void SetS2(uint16_t _pulseMin_0_Degree, uint16_t _pulseMax_180_Degree);
    void writeS1(uint16_t _degree_);
    void writeS2(uint16_t _degree_);
    void freeS1();
    void freeS2();

  private:
    byte addressDriver;
    byte lastAddressDriver;

  struct Str_RC_info {
    uint16_t pulseMin; uint16_t pulseMax;
  };

  Str_RC_info infoS1, infoS2;    //quy định cấu trúc nội dung lệnh điều khiển RC Servo

  str_serial_data_dcMotor motorDC[MAX_I2C_MOTOR_DC_SIZE];
  str_serial_data_rcMotor motorRC[MAX_I2C_MOTOR_RC_SIZE];

  void motorRC_Write(uint8_t _index_, uint16_t _pulse_);    // index = Servo S1 hoặc S2 ...
  void motorDC_Write(uint8_t _index_, uint8_t _dir_, uint8_t _speed_);
  void checkSumCalculate(str_serial_data_dcMotor *_myMotor_);   // CRC của DC motor
  void checkSumCalculate(str_serial_data_rcMotor *_myMotor_);

  // Hàm gửi byte dữ liệu qua I2C
  void sendI2cMotorDC_Data(str_serial_data_dcMotor *_myMotor_);
  void sendI2cMotorRC_Data(str_serial_data_rcMotor *_myMotor2_);
  void sendI2cAddress_Data(uint8_t _address_, str_serial_data_dcMotor *_myMotor_);

  void motorI2C_init() {
    motorDC[0].addressId = addressDriver;
    motorDC[1].addressId = addressDriver;
    motorRC[0].addressId = addressDriver;
    motorRC[1].addressId = addressDriver;
    // motorRC[2].addressId = 8;

    motorDC[0].modeId = DC_ID;
    motorDC[1].modeId = DC_ID;
    motorRC[0].modeId = RC_ID;
    motorRC[1].modeId = RC_ID;
    // motorRC[2].modeId = RC_ID;

    motorDC[0].index = 0;
    motorDC[1].index = 1;
    motorRC[0].index = 1;
    motorRC[1].index = 2;
    // motorRC[2].index = 2;

    infoS1.pulseMax = infoS2.pulseMax = MAKERLABVN_I2C_DRIVER_PULSE_TIME_MAX;
    infoS1.pulseMin = infoS2.pulseMin = MAKERLABVN_I2C_DRIVER_PULSE_TIME_MIN;
  }
};
#endif