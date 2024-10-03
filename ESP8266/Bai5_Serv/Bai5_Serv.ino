#define BLYNK_TEMPLATE_ID "TMPL6ULR9g6b7"
#define BLYNK_TEMPLATE_NAME "LEDKETNOI"
#define BLYNK_AUTH_TOKEN "VucF2htPaXxKs7Gz7oz1BS9QcF7hlldy"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h> // thư viện servo
Servo myservo;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "BD";        // tên wifi
char pass[] = "123456788"; // mật khẩu wifi
              // khai báo chân nút nhấn là chân GPIO2
unsigned long timeDelay = millis();
 
int servoPin = 4; // khai báo chân điều khiển servo là GPIO4
int button = 14;  
int state = 0;
// int stateServo = LOW;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  myservo.attach(servoPin);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(button, ISR, FALLING);
  // myservo.write(0);
}


BLYNK_WRITE(V0)
{
  //  Nếu phát hiện tài liệu sai sót các bạn liên hệ với mình nhé 0344970774 Trang 39 
   int value = param.asInt();
   if(value == 1) {
    myservo.write(199);
   } else {
     myservo.write(0);
   }
}
void loop()
{
  Blynk.run();
  // myservo.write(0);
  // delay(1000);
  // myservo.write(180);
  // delay(1000);
}

ICACHE_RAM_ATTR void ISR() {
  if(millis() - timeDelay > 200) {
    if(state == 0) {
      myservo.write(199);
      state = 1;
    } else {
      myservo.write(0);
      state = 0;
    }
    Blynk.virtualWrite(V0, state);
    timeDelay = millis();
  }
}
