#define BLYNK_TEMPLATE_ID "TMPL6ULR9g6b7"
#define BLYNK_TEMPLATE_NAME "LEDKETNOI"
#define BLYNK_AUTH_TOKEN "VucF2htPaXxKs7Gz7oz1BS9QcF7hlldy"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "BD";        // tên wifi
char pass[] = "123456788";

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
Servo myservo;
BlynkTimer timer;
unsigned long timeDelay = millis();
unsigned long timeDelay1 = millis();
unsigned long timeDelay2 = millis();


int timerID1;
int gas_value;
int mucCanhbao=600;
int buzzer=5; //D1
int ledMode = 12; //D6 led hiển thị chế độ hoạt động
int servopin=4; // D2 Kết nối servo
int button1=0; //D3 Bật tắt chế độ cảnh báo
int button2=14; // D5 Điều khiển cửa

int BTN_Den = 13; // d7
int DenLED = 15; // d8
boolean denState = 0;

boolean button1State=HIGH;
boolean button2State=HIGH;
boolean runMode=1;//Bật/tắt chế độ cảnh báo
boolean canhbaoState=0;
boolean cuaState=0;

#define KHIGAS V0
#define RUNMODE V2
#define TRANGTHAICB V4
#define SERVO V1
#define DEN V3

void setup() {
  Serial.begin(115200);
  delay(100);
  Blynk.begin(auth, ssid, pass);
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);

  pinMode(BTN_Den,INPUT_PULLUP);
  pinMode(DenLED, OUTPUT);
  digitalWrite(DenLED ,denState);

  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer,LOW); //Tắt buzzer
  pinMode(ledMode,OUTPUT);
  digitalWrite(ledMode,HIGH);

  myservo.attach(servopin);
  myservo.write(0);

  attachInterrupt(button2, ISR, FALLING);
  attachInterrupt(BTN_Den, ISR1, FALLING);
  attachInterrupt(button1, ISR2, FALLING);
  timerID1 = timer.setInterval(1000L,handleTimerID1);
}

void loop() {
  Blynk.run();
  timer.run();
  

  // if(digitalRead(button2)==LOW){
  //   if(button2State==HIGH){
  //     button2State=LOW;
  //     controlDoor();
  //     Blynk.virtualWrite(SERVO, cuaState);
  //     delay(200);
  //   }
  // }else{
  //   button2State=HIGH;
  // }

}

void handleTimerID1(){
  gas_value = analogRead(A0);
  Serial.println(gas_value);
  Blynk.virtualWrite(KHIGAS, gas_value);
  if(runMode==1){
    if(gas_value>mucCanhbao){
      if(canhbaoState==0){
        canhbaoState=1;
        Blynk.logEvent("canhbao", String("Cảnh báo! Khí gas=" + String(gas_value)+" vượt quá mức cho phép!"));
        digitalWrite(buzzer, HIGH);
        Blynk.virtualWrite(TRANGTHAICB, HIGH);
        Serial.println("Đã bật cảnh báo!");
      }
      myservo.write(199);
      cuaState=1;
      Blynk.virtualWrite(SERVO,cuaState);
    } else if (gas_value < mucCanhbao) {
      canhbaoState = 0;
      digitalWrite(buzzer,LOW);
      Blynk.virtualWrite(TRANGTHAICB,LOW);
      Serial.println("Đã tắt cảnh báo!");
    }
  }else{
    digitalWrite(buzzer,LOW);
    Blynk.virtualWrite(TRANGTHAICB,LOW);
    Serial.println("Đã tắt cảnh báo!");
    canhbaoState=0;
  }
}

// BLYNK_CONNECTED() {
//   Blynk.syncVirtual(RUNMODE,SERVO);
// }

// BLYNK_WRITE(MUCCANHBAO) {
//   mucCanhbao = param.asInt();
//   Serial.println("Mức cảnh báo: " + String(mucCanhbao));
// }

BLYNK_WRITE(RUNMODE) {
  runMode = param.asInt();
  digitalWrite(ledMode,runMode);
}

BLYNK_WRITE(SERVO){
  cuaState = !param.asInt();
  controlDoor();
}

BLYNK_WRITE(DEN){
  denState = param.asInt();
  digitalWrite(DenLED, denState);
}

void controlDoor(){
  if(cuaState==1){
    Serial.println("hehe");
    // for (int pos = 0; pos <= 180; pos += 5){
    //   myservo.write(pos);
    //   delay(0);
    // }
     myservo.write(0);
     cuaState=0;
  }else{
    Serial.println("hehe 1");
    // for (int pos = 180; pos >= 0; pos -= 5) {
    //   myservo.write(pos);
    //   delay(0);
    // }
    myservo.write(199);
    cuaState=1;
  }
}

ICACHE_RAM_ATTR void ISR() {
  if(millis() - timeDelay > 200) {
    if(cuaState == 0) {
      myservo.write(199);
      cuaState = 1;
    } else {
      myservo.write(0);
      cuaState = 0;
    }
    Blynk.virtualWrite(SERVO, cuaState);
    timeDelay = millis();
  }
}

ICACHE_RAM_ATTR void ISR1() {
  if(millis() - timeDelay1 > 200) {
    if(denState == 0) {
      digitalWrite(DenLED ,HIGH);
      denState = 1;
    } else {
       digitalWrite(DenLED ,LOW);
      denState = 0;
    }
    Blynk.virtualWrite(DEN, denState);
    Serial.println("btn_den");
    timeDelay1 = millis();
  }
}

ICACHE_RAM_ATTR void ISR2() {
  if(millis() - timeDelay2 > 200) {
    if(runMode==1){
      runMode=0;
      digitalWrite(ledMode, runMode);
    } else {
      runMode=1;
      digitalWrite(ledMode, runMode);
    }
    Blynk.virtualWrite(RUNMODE,runMode);
    Serial.println("btb canh bao");
    timeDelay2 = millis();
  }
}

