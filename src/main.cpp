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
  
  // Send the data to the unity application on available request
  if (Serial.available() > 0)
  {
    int input = Serial.readStringUntil('\n').toInt();
    aquaMinder.notify(input);
  }
}