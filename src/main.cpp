#include <Arduino.h>
#include "modules/LoginModule.h"
#include "modules/WeatherModule.h"
#include "modules/WeightModule.h"

// Set up the login module with reset and slave select pins
LoginModule loginModule(9, 10);

// Set up the weather module with the DHT11 sensor on pin 4
WeatherModule weatherModule(4, DHT11, 0.2, 0.1);

// Set up the weight module with the HX711 sensor on pins 3 and 2
WeightModule weightModule(3, 2, 1.0);

void setup()
{
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("*** Starting up... ***");

  // Initialize the login module and weather module
  loginModule.begin();
  weatherModule.begin();
  weightModule.begin();

  Serial.println("*** Ready! ***");
  Serial.println();
}

void loop()
{
  // Scan for a user's card and get the user's ID
  loginModule.update();

  // Measure the environment and print the results
  weatherModule.update();

  // Measure the weight and print the results
  weightModule.update();
}