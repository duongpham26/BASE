#define BLYNK_TEMPLATE_ID "TMPL6ULR9g6b7"
#define BLYNK_TEMPLATE_NAME "LEDKETNOI"
#define BLYNK_AUTH_TOKEN "HzAWVtbZDzBT3M2zILKVWhcEoRBG_42g"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "BD";        // tên wifi
char pass[] = "123456788"; // mật khẩu wifi              // khai báo chân nút nhấn là chân GPIO2
int led = 2;  
SimpleTimer timer;             // khai báo led là chân GPIO13

void setup() {
  pinMode(led, OUTPUT);
  // int Timer1 = timer.setInterval(1000, handleTimer);
  int Timer1 = timer.setTimer(1000, handleTimer, 10);
  // int Timer1 = timer.setInterval(1000, handleTimer);
    Blynk.begin(auth, ssid, pass);
}

void loop() {
    Blynk.run();
  // put your main code here, to run repeatedly:
  timer.run();
}

void handleTimer() {
  digitalWrite(led, !digitalRead(led));
  Blynk.virtualWrite(V0, digitalRead(led));
}
