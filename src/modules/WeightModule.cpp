#include "WeightModule.h"

WeightModule::WeightModule(uint8_t dataPin, uint8_t clockPin)
    : hx711Sensor(dataPin, clockPin, 407.22)
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
  weight = hx711Sensor.readWeight();
}

String WeightModule::getData()
{
  StaticJsonDocument<200> doc;
  doc["weight"] = weight;
  String json;
  serializeJson(doc, json);
  return json;
}