#include <Arduino.h>

#define TIME_TO_SLEEP 5 * 1000000 // Time ESP32 will go to sleep (in microseconds)
RTC_DATA_ATTR int bootCount = 0;  

void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;
  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch(wakeup_reason)
  {
    case ESP_SLEEP_WAKEUP_EXT0 : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case ESP_SLEEP_WAKEUP_EXT1 : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case ESP_SLEEP_WAKEUP_TIMER : Serial.println("Wakeup caused by timer"); break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD : Serial.println("Wakeup caused by touchpad"); break;
    case ESP_SLEEP_WAKEUP_ULP : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.printf("Wakeup was not caused by deep sleep: %d\n",wakeup_reason); break;
  }
}
void setup() {
  Serial.begin(9600);
  delay(1000); // Take some time to open up the Serial Monitor
  print_wakeup_reason();
  bootCount++;
  Serial.printf("Boot number: %d\n", bootCount);
  Serial.println("Going to sleep now");
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP); delay(1000);
  Serial.flush();
  esp_deep_sleep_start();

}

void loop() {
  
}

