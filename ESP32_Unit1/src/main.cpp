#include <Arduino.h>

#define LED 5
#define BUTTON 4

int buttonState;

void setup() {

pinMode(LED, OUTPUT);
pinMode(BUTTON, INPUT);
 digitalWrite(LED, LOW);
}

void loop() {
buttonState = digitalRead(BUTTON);
if (buttonState == HIGH) {
  digitalWrite(LED, HIGH);
} else {
  digitalWrite(LED, LOW);
} 
}


