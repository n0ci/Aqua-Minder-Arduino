#ifndef Hx711Sensor_h
#define Hx711Sensor_h

#include <HX711.h>

class Hx711Sensor {
  private:
    HX711 scale;
    uint8_t dataPin;
    uint8_t clockPin;
    float calibrationFactor;
    
  public:
    Hx711Sensor(uint8_t dataPin, uint8_t clockPin);
    void begin();
    void setCalibrationFactor(float factor);
    float readMedian(uint8_t times);
    void tare();
    void writeCalibrationFactorToEEPROM(float factor);
};

#endif