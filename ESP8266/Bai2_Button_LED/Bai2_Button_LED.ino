#define BLYNK_TEMPLATE_ID "TMPL6RouF5lnH"
#define BLYNK_TEMPLATE_NAME "Button"
#define BLYNK_AUTH_TOKEN "_fGk4BKigh5O0oXgQBH5lTnClqoLe5nk"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "BD";        // tên wifi
char pass[] = "123456788"; // mật khẩu wifi
int btn = 0;              // khai báo chân nút nhấn là chân GPIO2
int led = 2;               // khai báo led là chân GPIO13
bool trangthai = HIGH;
void setup()
{
   Serial.begin(115200);
   pinMode(btn, INPUT_PULLUP); // cấu hình chân nút nhấn là INPUT_PULLUP
   pinMode(led, OUTPUT);       // cấu hình chân led là OUTPUT
   Blynk.begin(auth, ssid, pass);
}

void loop()
{
   Blynk.run();
   check_button();
}

BLYNK_WRITE(V0)
{
   int nutnhan = param.asInt();
   digitalWrite(led, nutnhan);
}

void check_button()
{
   if (digitalRead(btn) == LOW)
   {
      if (trangthai == HIGH)
      {
         if(digitalRead(led)) {
          digitalWrite(led, LOW);
         } else {
            digitalWrite(led, HIGH);
         }
         Blynk.virtualWrite(V0, digitalRead(led));
         trangthai = LOW;
      }
   }
   else
   {
      trangthai = HIGH;
   }
  //  delay(2000); // lý do dùng ngắt 
}
