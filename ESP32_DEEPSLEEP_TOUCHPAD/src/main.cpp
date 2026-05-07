#include <Arduino.h>


#define THRESHOLD 20
#define PIN 32
touch_pad_t touchPin;
int touchValue;
RTC_DATA_ATTR int bootCount = 0;

void print_wakeup_reason() {
  esp_sleep_wakeup_cause_t wakeup_reason;
  wakeup_reason = esp_sleep_get_wakeup_cause();
  switch (wakeup_reason) {
    case ESP_SLEEP_WAKEUP_EXT0:
      Serial.println("Wakeup caused by external signal using RTC_IO");
      break;
    case ESP_SLEEP_WAKEUP_EXT1:
      Serial.println("Wakeup caused by external signal using RTC_CNTL");
      break;
    case ESP_SLEEP_WAKEUP_TIMER:
      Serial.println("Wakeup caused by timer");
      break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD:
      Serial.println("Wakeup caused by touchpad");
      break;
    case ESP_SLEEP_WAKEUP_ULP:
      Serial.println("Wakeup caused by ULP program");
      break;
    default:
      Serial.printf("Wakeup was not caused by deep sleep: %d\n", wakeup_reason);
      break;
  }
}

void print_wakeup_touchpad() {
  touchPin = esp_sleep_get_touchpad_wakeup_status();
  
  switch(touchPin) {
    case TOUCH_PAD_NUM0:
      Serial.println("Touchpad 0 (GPIO4) caused wakeup");
      break;
    case TOUCH_PAD_NUM1:
      Serial.println("Touchpad 1 (GPIO0/1) caused wakeup");
      break;
    case TOUCH_PAD_NUM2:
      Serial.println("Touchpad 2 (GPIO2) caused wakeup");
      break;
    case TOUCH_PAD_NUM3:
      Serial.println("Touchpad 3 (GPIO15/3) caused wakeup");
      break;
    case TOUCH_PAD_NUM4:
      Serial.println("Touchpad 4 (GPIO13/4) caused wakeup");
      break;
    case TOUCH_PAD_NUM5:
      Serial.println("Touchpad 5 (GPIO12/5) caused wakeup");
      break;
    case TOUCH_PAD_NUM6:
      Serial.println("Touchpad 6 (GPIO14/6) caused wakeup");
      break;
    case TOUCH_PAD_NUM7:
      Serial.println("Touchpad 7 (GPIO27/7) caused wakeup");
      break;
    case TOUCH_PAD_NUM8:
      Serial.println("Touchpad 8 (GPIO33/8) caused wakeup");
      break;
    case TOUCH_PAD_NUM9:
      Serial.println("Touchpad 9 (GPIO32/9) caused wakeup");
      break;
    default:
      Serial.println("Unknown touchpad caused wakeup");
      break;
  }
}

void setup() {
  Serial.begin(9600);
  delay(1000);  // Take some time to open up the Serial Monitor
  print_wakeup_reason();
  print_wakeup_touchpad();
  bootCount++;
  Serial.printf("Boot number: %d\n", bootCount);
  touchSleepWakeUpEnable(PIN, THRESHOLD);
  Serial.println("Going to sleep now");
  Serial.flush(); // Ensure all serial data is sent before sleeping
  esp_deep_sleep_start();
  // Add touchpad setup here if needed
  // touchAttachInterrupt(PIN, NULL, THRESHOLD);
  // esp_sleep_enable_touchpad_wakeup();

}

void loop() {
  
  
}