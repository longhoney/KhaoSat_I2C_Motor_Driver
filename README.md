# Arduino_Project_Template

`git clone https://github.com/longhoney/4WD_I2C-Motor-Driver_Mecanum.git`

- git status
- git add . // git add examples/<File_Name>
- git status
- git commit -m"editted readme"  
- git push

`Nhắc lại vài thứ trước khi bắt đầu`
- Mục tiêu khi làm chiếc xe này là gì? Phải trả lời được thì mới không bị lạc hướng
- Trước khi làm gì, phải suy nghĩ việc mình làm ảnh hưởng đến hệ thống như nào (không phải cứ hư thì đền ...)

`Quy tắc kết nối`
- Dây cấp nguồn phải to, không được dùng jumper wires --> Phải thay toàn bộ dây, vì sức mạnh của mắt xích yếu nhất cũng là sức mạch của toàn bộ dây chuyền

`Quy tắc cài đặt phần mềm`
- Cài đặt phần mềm vào chung ổ đĩa cài HĐH (thường là ổ C:)
- Dữ liệu khi dùng phần mềm lưu ở ổ đĩa riêng (ví dụ là ổ D:)

`Cập nhật`
- Sau khi thay dây nguồn cấp cho driver (jumper wire --> Xh2.54 4P): Xe chạy theo chường trình, nhưng động cơ không dừng hẳn
- Vì dây cấp nguồn chính cho 2 driver vẫn là jumper wire (tôi giữ vậy để dễ tháo ra mỗi khi nạp code), xe thiếu nguồn nên hoạt động không đúng như chương trình
- Tôi thay toàn bộ sang xh2.54 4p, xe chạy tốt, cặp bánh sau quay nhanh hơn hẳn cặp bánh truóc, bánh trái trước quay nhanh hơn hẳn bánh phải trước

`Cập nhật tiến độ`
- https://docs.google.com/document/d/1SmDWLpdE43OGyefFhWPm1k47KTTY6QEGslYMM_aYo_g/edit?usp=sharing

`Chương trình tham khảo`
- https://github.com/MinhKhanh614/Mecanum-Car/tree/main 
