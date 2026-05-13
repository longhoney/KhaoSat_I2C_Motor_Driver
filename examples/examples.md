
`A. KhaoSat`
- Trước khi nạp chương trình điều khiển sản phẩm nào, cần phải đảm bảo nó hoạt động tốt trước
- Trước khi làm gì, phải suy nghĩ việc mình làm ảnh hưởng đến hệ thống như nào

`1. Khao sat MKE-M15`
- Nạp chương trình mẫu từ thư viện MAKERLABVN theo đường dẫn: D:\Git\GitHub\longhoney\4WD_I2C-Motor-Driver_Mecanum\libraries\MAKERLABVN\examples\Module\MKE_M15_Bluetooth_LCD_Serial\MKE_M15_Bluetooth_LCD_Serial_VietDuinoUno - Kết quả: chương trình chạy đúng với mục tiêu thiết kế
- Nạp chương trình từ thư viện gốc Dabble

`2. Khao sat 4 dong co vang`
- Tôi test độc lập 4 động cơ (cấp nguồn thông qua mạch MKE-M12) --> Kết quả: phải trên ok, trái trên ok, phải sau ok, trái sau ok.
- Cách khảo sát động cơ đúng: khảo sát với driver để bảo vệ toàn bộ hệ thống
- Bỏ qua bước này và nhảy xuống các bước tiếp theo

`3. Khao sat driver tren - 2 banh truoc`
- Vừa test driver vừa test động cơ
- Anh Ngọc: "Tầm quan trọng của DIOD đối với các tải cảm: relay, Dc motor, Solenoid Valve, Solenoid Lock, ... Bất kỳ mạch nào có liên quan tải cảm, phải kiếm xem con DIOD nào bị hở chân không nhé!
Nguồn: https://www.youtube.com/watch?v=LXGtE3X2k7Y"

- Nạp chương trình mẫu từ thư viện "Makerlabvn_I2C_Motor_Driver", địa chỉ i2c: myDriver(0)

`4. Khao sat driver duoi - 2 banh sau`
- Nạp chương trình mẫu từ thư viện "Makerlabvn_I2C_Motor_Driver", địa chỉ i2c: myDriver(1)