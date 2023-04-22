#pragma once
#include <Arduino.h>
#include "modules/IdentityModule.h"
#include "modules/WeatherModule.h"
#include "modules/WeightModule.h"
#include "logic/AquaMinder.h"

#define MODULE_COUNT 3
#define USER_COUNT 10

// Set up the modules
Module modules[MODULE_COUNT] = {IdentityModule(9, 10), WeatherModule(4, DHT11), WeightModule(3, 2)};

// Set up the users
User users[USER_COUNT];

// Set up the logic
AquaMinder aquaMinder(modules, MODULE_COUNT, users, USER_COUNT);

void setup()
{
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the logic and thus modules
  aquaMinder.update();
}

void loop()
{
  // Send the data to the unity application on request
  aquaMinder.notify(Serial.read());

  // Update the logic and thus modules
  aquaMinder.update();
}