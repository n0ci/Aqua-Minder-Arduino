#pragma once
#include <Arduino.h>
#include "modules/Module.h"
#include "modules/IdentityModule.h"
#include "modules/WeatherModule.h"
#include "modules/WeightModule.h"
#include "logic/AquaMinder.h"

#define MODULE_COUNT 3

enum RequestType
{
  IDENTITY,
  WEATHER,
  WEIGHT
};

// Set up the modules
Module modules[MODULE_COUNT] = {IdentityModule(9, 10), WeatherModule(4, DHT11), WeightModule(3, 2)};

// Set up the logic
AquaMinder aquaMinder;

void setup()
{
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("*** Starting up... ***");

  // Initialize the login module and weather module
  for (int i = 0; i < MODULE_COUNT; i++)
  {
    modules[i].begin();
  }

  Serial.println("*** Ready! ***");
  Serial.println();
}

void loop()
{
  // Update the modules data
  for (int i = 0; i < MODULE_COUNT; i++)
  {
    modules[i].update();
  }

  // Send the data to the unity application on request
  int unity = Serial.read();
  if (unity == RequestType::IDENTITY)
  {
    Serial.println(aquaMinder.getCurrentUser()->getDrankWeightJson());
  }
  else if (unity == RequestType::WEATHER)
  {
    Serial.println(modules[1].getData());
  }
  else if (unity == RequestType::WEIGHT)
  {
    Serial.println(aquaMinder.getCurrentUser()->getDrankWeightJson());
  }
}