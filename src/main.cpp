#include <Arduino.h>
#include "RFIDLogin.h"

RFIDLogin rfidLogin(9, 10); // RST and SS pins

void setup() {
  rfidLogin.begin();
}

void loop() {
  int user_id = rfidLogin.scanCard();

  if (user_id != -1) {
    Serial.print(F("Welcome back, user "));
    Serial.println(user_id);
  }
  
  delay(100);
}