#include "Long_I2C_Motor_Driver.h"

Long_I2C_Motor_Driver::Long_I2C_Motor_Driver(uint8_t _address_) {
  if(_address_ <= Long_I2C_DRIVER_MAX_NUMBER_DRIVER_SUPPORT){
    addressDriver = _address_ + Long_I2C_DRIVER_SLAVE_ADDRESS_MIN;
  }else if((_address_ >= Long_I2C_DRIVER_SLAVE_ADDRESS_MIN) && (_address_ <= Long_I2C_DRIVER_SLAVE_ADDRESS_MAX)){
    addressDriver = _address_;
  }else
   addressDriver = Long_I2C_DRIVER_SLAVE_ADDRESS_MIN;
}

void Long_I2C_Motor_Driver::begin()   // Hàm khởi tạo
{
  Wire.begin(); // join i2c bus (address optional for master)
  motorI2C_init();
  ReadI2cOverSerial();
  this->MB(0,0);
  this->MA(0,0);
  this->freeS2();
  this->freeS1();
}

// Hàm tính CRC cho frame của DC motor
void Long_I2C_Motor_Driver::checkSumCalculate(str_serial_data_dcMotor *_myMotor_)
{
  uint16_t tempSum = _myMotor_->addressId +   //trỏ thông tin từ _myMotor_
                     _myMotor_->modeId +
                     _myMotor_->index +
                     _myMotor_->pwm +
                     _myMotor_->dir;
  _myMotor_->checkSum = (uint8_t)tempSum;   //gán kiểu dữ liệu ít bộ nhớ hơn cho kết quả cuối?
}

// Hàm tính CRC cho frame của RC servo
void Long_I2C_Motor_Driver::checkSumCalculate(str_serial_data_rcMotor *_myMotor_)
{
  uint16_t tempSum = _myMotor_->addressId +
                     _myMotor_->modeId +
                     _myMotor_->index +
                     _myMotor_->value.pwm +
                     _myMotor_->value.dir;
  _myMotor_->checkSum = (uint8_t)tempSum;
}

