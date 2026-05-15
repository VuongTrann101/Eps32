#include <Arduino.h>
#include "WiFi.h"

// put function declarations here:

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.printf("setup done\n");
  delay(2000);


}

void loop() {
  int n = WiFi.scanNetworks();
  Serial.printf("scan done\n");
  if (n == 0) {
    Serial.printf("%d networks found\n", n);
  }
  for (int i = 0; i < n; ++i) {
    Serial.printf("Wifi %d: %s (%d) %s\n", i+1, WiFi.SSID(i).c_str(), WiFi.RSSI(i), WiFi.encryptionType(i) == WIFI_AUTH_OPEN ? "OPEN" : "ENCRYPTED");
  }
  delay(20000);
}
