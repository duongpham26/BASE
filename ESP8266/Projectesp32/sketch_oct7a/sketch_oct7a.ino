// #define BLYNK_TEMPLATE_ID "TMPL6TkD0L0AA"
// #define BLYNK_TEMPLATE_NAME "Smart Kitchen"
// #define BLYNK_AUTH_TOKEN "EmYf-sHtjVa3PRbN508ISXb2kHTLN0iZ"

#define BLYNK_TEMPLATE_ID "TMPL6ULR9g6b7"
#define BLYNK_TEMPLATE_NAME "LEDKETNOI"
#define BLYNK_AUTH_TOKEN "VucF2htPaXxKs7Gz7oz1BS9QcF7hlldy"

#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Servo.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
BlynkTimer timer;
Servo myservo;

#define CONNECTION_TIMEOUT 10

#define DO_PIN 36     // The ESP8266 pin connected to the analog output of the flame sensor
#define GAS_PIN 39

#define btn_den 33 // button bat, tat den
#define btn_che_do 12 // button bat tat che do canh bao
#define btn_cua 19 // button dong, mo cua

#define servo 32
#define led_mode 27
#define buzzer 25
#define light 26
#define active 22

unsigned long timeDelay = millis();
unsigned long timeDelay1 = millis();
unsigned long timeDelay2 = millis();

int mucCanhbaoGas = 1800;
int mucCanhbaoFire = 2000;

boolean denState = 0;
boolean runMode=1;//Bật/tắt chế độ cảnh báo
boolean canhbaoState=0;
boolean cuaState=0;

volatile bool updateRunmodeState = false; // Biến cờ báo hiệu
volatile int stateToWriteRunmode = 0;    

volatile bool updateCuaState = false; // Biến cờ báo hiệu
volatile int stateToWriteCua = 0;

volatile bool updateDenState = false; // Biến cờ báo hiệu
volatile int stateToWriteDen = 0;

const char* ssid = "BD";
const char* password = "123456788";

#define KHIGAS V0
#define SERVO V1
#define RUNMODE V2
#define DEN V3
#define TRANGTHAICB V4

void setup() {
    Serial.begin(115200);
    Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
    delay(1000);
    //setup pin
    pinMode(DO_PIN, INPUT);
    pinMode(GAS_PIN, INPUT);

    pinMode(btn_den, INPUT_PULLUP);
    pinMode(btn_che_do, INPUT_PULLUP);
    pinMode(btn_cua, INPUT_PULLUP);

    pinMode(servo, OUTPUT);
    pinMode(led_mode, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(light, OUTPUT);
    pinMode(active, OUTPUT);

    digitalWrite(light ,denState);
    digitalWrite(buzzer,canhbaoState); //Tắt buzzer
    digitalWrite(led_mode,runMode);
    digitalWrite(active,LOW);

    Blynk.virtualWrite(SERVO, cuaState);
    Blynk.virtualWrite(DEN, denState);
    Blynk.virtualWrite(RUNMODE, runMode);
    Blynk.virtualWrite(TRANGTHAICB, canhbaoState);
  
    myservo.attach(servo);
    myservo.write(0);

    attachInterrupt(btn_den, ISR_DEN, FALLING);
    attachInterrupt(btn_che_do, ISR_CHE_DO, FALLING);
    attachInterrupt(btn_cua, ISR_CUA, FALLING);

    while(1) {
      int gas_test = analogRead(GAS_PIN);
      int fire_test = analogRead(DO_PIN);
      Serial.println("Connect...");
      digitalWrite(active,LOW);

      if(gas_test < mucCanhbaoGas && fire_test > mucCanhbaoFire) {
        Serial.println("Starting...");
        delay(5000);
        if(gas_test < mucCanhbaoGas && fire_test > mucCanhbaoFire) {
          Serial.println("Started");
          digitalWrite(active,HIGH);
          break;
        }
      }
      delay(1000);
    }

    timer.setInterval(1000L, handleADC);
}

void handleADC() {
  int gas_value, fire_value; 
  gas_value = analogRead(GAS_PIN);
  fire_value = analogRead(DO_PIN);

  Blynk.virtualWrite(KHIGAS, gas_value);


  Serial.println(gas_value);
  Serial.println(fire_value);
  Serial.print("runmode ");
  Serial.println(runMode);
  Serial.print("cua ");
  Serial.println(cuaState);
  Serial.print("den ");
  Serial.println(denState);

  if(runMode==1){
    if((gas_value>mucCanhbaoGas) || fire_value < mucCanhbaoFire) {
      if(canhbaoState==0){
        canhbaoState=1;
        digitalWrite(buzzer, HIGH);
        Blynk.virtualWrite(TRANGTHAICB, HIGH);
        // Serial.println("Đã bật cảnh báo!");
      }
      myservo.write(90);
      cuaState=1;
      Blynk.virtualWrite(SERVO,cuaState);
    } else if (gas_value < mucCanhbaoGas && fire_value > mucCanhbaoFire) {
      canhbaoState = 0;
      digitalWrite(buzzer,LOW);
      Blynk.virtualWrite(TRANGTHAICB,LOW);
      // Serial.println("Đã tắt cảnh báo!");
    }
  }else{
    digitalWrite(buzzer,LOW);
    Blynk.virtualWrite(TRANGTHAICB,LOW);
    // Serial.println("Đã tắt cảnh báo!");
    canhbaoState=0;
  }
}
 

void loop(){
  Blynk.run();
  timer.run();

  if (updateRunmodeState) { 
    Blynk.virtualWrite(RUNMODE, stateToWriteRunmode); // Cập nhật Blynk ở đây
    updateRunmodeState = false; // Reset cờ
  }

  if (updateDenState) { 
    Blynk.virtualWrite(DEN, stateToWriteDen);
    updateDenState = false; // Reset cờ
  }

  if (updateCuaState) { 
    Blynk.virtualWrite(SERVO, stateToWriteCua);
    updateCuaState= false; // Reset cờ
  }

}

BLYNK_WRITE(RUNMODE) {
  runMode = param.asInt();
  // Serial.print("runM ");
  // Serial.println(runMode);
  digitalWrite(led_mode,runMode);
}

BLYNK_WRITE(SERVO){
  cuaState = param.asInt();
  if(cuaState==1){
     myservo.write(90);
  }else{
    myservo.write(0);
  }
}

BLYNK_WRITE(DEN){
  denState = param.asInt();
  digitalWrite(light, denState);
}


IRAM_ATTR void ISR_CUA() {
  if(millis() - timeDelay > 200) {
    if(cuaState == 0) {
      myservo.write(90);
      cuaState = 1;
    } else {
      myservo.write(0);
      cuaState = 0;
    }
    stateToWriteCua = cuaState; 
    updateCuaState = true;
    timeDelay = millis();
  }
}

IRAM_ATTR void ISR_DEN() {
  if(millis() - timeDelay1 > 200) {
    if(denState == 0) {
      digitalWrite(light ,HIGH);
      // Serial.println("bat den");
      denState = 1;
    } else {
       digitalWrite(light ,LOW);
      // Serial.println("tat den");

      denState = 0;
    }
    stateToWriteDen = denState; 
    updateDenState = true;
    // Serial.println("btn_den");
    timeDelay1 = millis();
  }
}

IRAM_ATTR void ISR_CHE_DO() {
  if(millis() - timeDelay2 > 200) {
    if(runMode==1){
      runMode=0;
      // Serial.println("tat che do");
      digitalWrite(led_mode, runMode);
    } else {
      runMode=1;
      // Serial.println("bat che do");
      digitalWrite(led_mode, runMode);
    }
    // Serial.println("btb canh bao");
    stateToWriteRunmode = runMode; 
    updateRunmodeState = true;
    timeDelay2 = millis();
  }
}


