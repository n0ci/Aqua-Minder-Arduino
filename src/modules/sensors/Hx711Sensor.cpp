#include "Hx711Sensor.h"
#include <EEPROM.h>

Hx711Sensor::Hx711Sensor(uint8_t dataPin, uint8_t clockPin) : dataPin(dataPin), clockPin(clockPin), calibrationFactor(1.0) {}

void Hx711Sensor::begin() {
  scale.begin(dataPin, clockPin);
}

void Hx711Sensor::setCalibrationFactor(float factor) {
  calibrationFactor = factor;
  scale.set_scale(calibrationFactor);
}

float Hx711Sensor::readMedian(uint8_t times) {
  return scale.read_median(times) / calibrationFactor;
}

void Hx711Sensor::tare() {
  scale.tare();
}

void Hx711Sensor::writeCalibrationFactorToEEPROM(float factor) {
  calibrationFactor = factor;
  scale.set_scale(calibrationFactor);

  // Write the calibration factor to EEPROM
  int address = 0;
  byte* ptr = (byte*) &calibrationFactor;
  for (int i = 0; i < sizeof(calibrationFactor); i++) {
    EEPROM.write(address++, *ptr++);
  }
}