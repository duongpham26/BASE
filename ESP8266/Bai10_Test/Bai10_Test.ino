
// #include <ESP8266WiFi.h>
// #include <BlynkSimpleEsp8266.h>
// char auth[] = BLYNK_AUTH_TOKEN;
// char ssid[] = "BD";        // tên wifi
// char pass[] = "123456788"; // mật khẩu wifi             // khai báo chân nút nhấn là chân GPIO2
int led = 0;               // khai báo led là chân GPIO13
void setup()
{
  pinMode(led, OUTPUT);       // cấu hình chân led là OUTPUT
  digitalWrite(led, HIGH);
}

void loop()
{
  digitalWrite(led, LOW);
  delay(1000);
  digitalWrite(led, HIGH);
  delay(1000);
}




