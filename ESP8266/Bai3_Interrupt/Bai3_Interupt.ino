#define BLYNK_TEMPLATE_ID "TMPL6RouF5lnH"
#define BLYNK_TEMPLATE_NAME "Button"
#define BLYNK_AUTH_TOKEN "_fGk4BKigh5O0oXgQBH5lTnClqoLe5nk"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "BD";        // tên wifi
char pass[] = "123456788"; // mật khẩu wifi
int button = 0;              // khai báo chân nút nhấn là chân GPIO2
int led = 2;               // khai báo led là chân GPIO13
bool trangthai = HIGH;
unsigned long timeDelay = millis();
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(button, ISR, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
}

ICACHE_RAM_ATTR void ISR() {
  if(millis() - timeDelay > 200) {
    digitalWrite(led, !digitalRead(led));
    timeDelay = millis();
  }
}
