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
  float newWeight = hx711Sensor.readWeight();
  if (newWeight > 0)
  {
    weight = newWeight;
  }
}

String WeightModule::getData()
{
  return String(weight);
}