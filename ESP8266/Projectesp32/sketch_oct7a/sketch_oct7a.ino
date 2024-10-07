#include <Arduino.h>

#define DO_PIN 32     // The ESP8266 pin connected to the analog output of the flame sensor
#define BUZZER_PIN 22     // The pin connected to the buzzer
long timeSeconds = 5;
long now = millis();
long lastTrigger = 0;
boolean startTimer = false;


void setup() {
  pinMode(DO_PIN, INPUT);      // Initialize the ESP8266's pin as an input for the sensor
  pinMode(BUZZER_PIN, OUTPUT); // Initialize the buzzer pin as an output
  digitalWrite(BUZZER_PIN, LOW);
  Serial.begin(9600);

}

int flame_state;
void loop() {
  flame_state = analogRead(DO_PIN);
  if(flame_state < 1000) {
    detectsFire();
  }
  now = millis();
  if(startTimer && (now - lastTrigger > (timeSeconds*1000)) ) {
    Serial.println("stop");
    digitalWrite(BUZZER_PIN, LOW);
    startTimer = false;
  }
  delay(200);
}

void detectsFire() {
  Serial.println("detect fire");
  digitalWrite(BUZZER_PIN, HIGH);
  startTimer = true;
  lastTrigger = millis();
}

// void handleTimerID1() {
//   flame_state = analogRead(DO_PIN);  // Read the analog value from the sensor
//   Serial.println(flame_state);           // Print the value for debugging

//   // If flame_state is less than the threshold (350), fire is detected
//   if (flame_state > 1000) {
//     digitalWrite(BUZZER_PIN, LOW);   // Turn off the buzzer
//     Serial.println("No flame detected => All clear");
//   } else {
//     digitalWrite(BUZZER_PIN, HIGH);  // Turn on the buzzer
//     Serial.println("Flame present => Fire detected");
//   }
//   delay(1000);
// }
