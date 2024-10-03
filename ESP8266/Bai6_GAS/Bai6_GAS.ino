#define BLYNK_TEMPLATE_ID "TMPL6ULR9g6b7"
#define BLYNK_TEMPLATE_NAME "LEDKETNOI"
#define BLYNK_AUTH_TOKEN "VucF2htPaXxKs7Gz7oz1BS9QcF7hlldy"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

SimpleTimer timer;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "BD";        // tên wifi
char pass[] = "123456788";
int cb = A0; // khai báo chân cảm biến là A0
int coi = 5; // khai báo chân còi là GPIO2
int value; // khai báo biến lưu tạm
void setup()
{
 Serial.begin(115200);
 pinMode(cb,INPUT);
 pinMode(coi,OUTPUT);
 Blynk.begin(auth, ssid, pass);
 timer.setInterval(1000, sendUptime);
}
void sendUptime()
{
 value = analogRead(cb); // đọc giá trị cảm biến đưa vào biến lưu tạm
 Blynk.virtualWrite(V0, value); // đưa giá trị lên blynk
 Serial.println(value);
 if(value > 600) // cài đặt giá trị báo động
 {
 digitalWrite(coi,HIGH); // bật còi
 }
 if(value < 580) // giá trị tắt báo động
 {
 digitalWrite(coi,LOW); // tắt còi
 }
}
void loop()
{
 Blynk.run();
 timer.run();
}


