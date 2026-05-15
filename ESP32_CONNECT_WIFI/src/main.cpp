#include <Arduino.h>
#include <WiFi.h>

const char *ssid = "1T.DoubleV";
const char *password = "10012006";

void setup() {
  Serial.begin(9600);
  delay(1000);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());
  Serial.printf("RSSI: %d", WiFi.RSSI());

}
void loop() {
  // put your main code here, to run repeatedly:

} 