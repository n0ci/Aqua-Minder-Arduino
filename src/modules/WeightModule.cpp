#include "WeightModule.h"

WeightModule::WeightModule(uint8_t dataPin, uint8_t clockPin)
    : hx711Sensor(dataPin, clockPin, 400.5)
{
  // TODO: make calibration factor configurable
}

void WeightModule::begin()
{
  hx711Sensor.begin();
}

void WeightModule::tare()
{
  hx711Sensor.tare();
}

void WeightModule::update()
{
  float currentWeight = 0;
  int iterations = 0; 

  do 
  {
    currentWeight = hx711Sensor.readWeight();
    delay(smoothTime);
    iterations++;
  }
  while (abs(currentWeight - weight) > threshold && iterations <= maxSmoothIterations);
  
  weight = currentWeight;
}

String WeightModule::getData()
{
  return String(weight);
}