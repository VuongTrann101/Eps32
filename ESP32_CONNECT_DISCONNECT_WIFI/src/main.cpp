#include <Arduino.h>
#include "WiFi.h"

const char* ssid = "1T.DoubleV";
const char* password = "10012006";

unsigned long previousMillis = 0;
#define interval 10000 // 10 seconds

void initWiFi() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

}
 void setup() {
  initWiFi();
 Serial.println("WiFi.SSID: " + WiFi.SSID());
 }

void loop() {
  unsigned long currentMillis = millis();

  
   if (WiFi.status() != WL_CONNECTED && (currentMillis - previousMillis >= interval)) {
    previousMillis = currentMillis;
    Serial.println("Reconnecting to WiFi...");
    WiFi.disconnect();
    WiFi.reconnect();
    delay(2000); // Wait for connection to establish
    Serial.println("WiFi.SSID: " + WiFi.SSID());
  } else if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi is connected. SSID: " + WiFi.SSID());
    delay(5000); // Check connection status every 5 seconds
  }

} 