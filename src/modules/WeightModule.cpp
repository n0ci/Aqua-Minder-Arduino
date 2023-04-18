#include "WeightModule.h"

WeightModule::WeightModule(uint8_t dataPin, uint8_t clockPin, float absoluteThreshold) 
  : hx711Sensor(dataPin, clockPin, 407.22), lastWeight(0), absoluteThreshold(absoluteThreshold){}

void WeightModule::begin() {
  hx711Sensor.begin();
}

float WeightModule::readWeight() {
  return hx711Sensor.readWeight();
}

void WeightModule::tare() {
  hx711Sensor.tare();
}

void WeightModule::update() {
  float weight = readWeight();
  printIfChanged(weight);
}

void WeightModule::printIfChanged(float weight) {
  float absoluteChange = abs(weight - lastWeight);
  lastWeight = weight;
  if (absoluteChange > absoluteThreshold) {
    Serial.print(F("Weight: "));
    Serial.print(weight, 2);
    Serial.println(F(" g"));
  }
}