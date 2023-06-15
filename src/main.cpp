#include <Arduino.h>
#include "modules/IdentityModule.h"
#include "modules/WeatherModule.h"
#include "modules/WeightModule.h"
#include "logic/AquaMinder.h"

// Set up the logic
AquaMinder aquaMinder(IdentityModule(9, 10), WeightModule(3, 2), WeatherModule(4, DHT11));

void setup()
{
  // Initialize serial communication
  Serial.begin(115200);
  aquaMinder.initializeModules();
}

void loop()
{
  aquaMinder.update();
  aquaMinder.sendAllData();
}