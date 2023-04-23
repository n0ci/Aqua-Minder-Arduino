#include <Arduino.h>
#include "modules/IdentityModule.h"
#include "modules/WeatherModule.h"
#include "modules/WeightModule.h"
#include "logic/AquaMinder.h"

#define USER_COUNT 5

// Set up the users
User users[USER_COUNT] = {User(1), User(2), User(3), User(4), User(5)};

// Set up the logic
AquaMinder aquaMinder(IdentityModule(9, 10), WeightModule(3, 2), WeatherModule(4, DHT11), users, USER_COUNT);

void setup()
{
  // Initialize serial communication
  Serial.begin(9600);
}

void loop()
{
  // Update the logic and thus modules
  aquaMinder.update();
  // Send the data to the unity application on request
  aquaMinder.notify(Serial.read());
}