#include <Arduino.h>
#include "RFIDLogin.h"
#include "Weather.h"

RFIDLogin rfidLogin(9, 10);
Weather weather;

void setup()
{
  Serial.begin(9600);
  rfidLogin.begin();
}

void loop()
{
  weather.update();

  int user_id = rfidLogin.scanCard();

  if (user_id != -1)
  {
    Serial.print(F("Welcome back, user "));
    Serial.println(user_id);
  }
}