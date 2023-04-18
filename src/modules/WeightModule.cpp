#include "WeightModule.h"

WeightModule::WeightModule(uint8_t dataPin, uint8_t clockPin, float percentThreshold) 
  : hx711Sensor(dataPin, clockPin), lastWeight(0), percentThreshold(percentThreshold){}

void WeightModule::begin() {
  hx711Sensor.begin();
}

void WeightModule::setCalibrationFactor(float factor) {
  hx711Sensor.setCalibrationFactor(factor);
}

float WeightModule::readWeight() {
  return hx711Sensor.readMedian(7);
}

void WeightModule::tare() {
  hx711Sensor.tare();
}

void WeightModule::calibrate() {
  Serial.println(F("Place a known weight on the scale and press enter..."));
  while (!Serial.available()) {
    // wait for user input
  }
  float knownWeight = Serial.parseFloat();
  hx711Sensor.tare();
  float measuredWeight = hx711Sensor.readMedian(7);
  float calibrationFactor = knownWeight / measuredWeight;
  hx711Sensor.setCalibrationFactor(calibrationFactor);
  Serial.print(F("Calibration factor set to "));
  Serial.println(calibrationFactor);
}

void WeightModule::update() {
  float weight = readWeight();
  printIfChanged(weight);
}

void WeightModule::printIfChanged(float weight) {
  float percentChange = abs((weight - lastWeight) / lastWeight) * 100.0;
  if (percentChange >= percentThreshold) {
    Serial.print(F("Weight: "));
    Serial.print(weight, 2);
    Serial.println(F(" kg"));
    lastWeight = weight;
  }
}