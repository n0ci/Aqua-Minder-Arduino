#include <Arduino.h>
#include "modules/IdentityModule.h"
#include "modules/WeatherModule.h"
#include "modules/WeightModule.h"
#include "logic/AquaMinder.h"

// Set up the logic
//AquaMinder aquaMinder(IdentityModule(9, 10), WeightModule(3, 2), WeatherModule(4, DHT11));

IdentityModule idMo(9, 10);

void setup()
{
  // Initialize serial communication
  Serial.begin(115200);
  //aquaMinder.initializeModules();

  idMo.begin();
}

void loop()
{
  idMo.update();

  delay(100);


  // Send the data to the unity application on available request
  /* if (Serial.available() > 0)
  {
    int input = Serial.readStringUntil('\n').toInt();
    aquaMinder.notify(input);
  } */
}