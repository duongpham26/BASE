



#define BLYNK_TEMPLATE_ID "TMPL6Dr8y-r5R"
#define BLYNK_TEMPLATE_NAME "Bientro"
#define BLYNK_AUTH_TOKEN "YwHT4ZiwddqmA6jM8DTfYfhcQ-iUIr4w"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "BD"; // tên wifi
char pass[] = "123456788"; // mật khẩu wifi
int analogPin = A0; // khai báo chân analog là chân A0
 
int value; // khai báo biến lưu tạm
void setup()
{
  Serial.begin(115200);
  pinMode(analogPin, INPUT); // cấu hình chân tín hiệu là INPUT
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  value = analogRead(analogPin); // Đọc giá trị biến trở bằng hàm analogRea
  Blynk.virtualWrite(V0, value); // đưa giá trị đọc được lên Blynk thông qua chân ảo V0 - chân này là chân đã chọn lúc tạo project
}
