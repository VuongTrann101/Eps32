#include <Arduino.h>

#define PIR_SENSOR 27
#define LED 26
#define TIMEOUT 5000

bool motionDetected = false;
bool startTime = false;
unsigned long lastTime = 0;
unsigned long nowTime = millis();

void IRAM_ATTR detectCallback() {
  digitalWrite(LED, HIGH);
  startTime = true;
  lastTime = millis();

}
void setup() {
  Serial.begin(9600);
  pinMode(PIR_SENSOR, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  attachInterrupt(digitalPinToInterrupt(PIR_SENSOR), detectCallback, FALLING);

}

void loop() {
 nowTime = millis();
 if (digitalRead(PIR_SENSOR) == LOW && motionDetected == false) {
    Serial.println("Motion Detected!");
    motionDetected = true;
  } 
  if (startTime && (nowTime - lastTime >= TIMEOUT)) {
    digitalWrite(LED, LOW);
    startTime = false;
    motionDetected = false;
    Serial.println("Motion Stopped!");
  }
 
}
