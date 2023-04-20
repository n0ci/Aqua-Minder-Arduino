#ifndef Hx711Sensor_h
#define Hx711Sensor_h

#include <HX711_ADC.h>

class Hx711Sensor
{
private:
  HX711_ADC loadCell;

public:
  Hx711Sensor(int dataPin, int clockPin, float calibrationFactor);
  void begin();
  void setCalibrationFactor(float factor);
  float readWeight();
  void tare();
};

#endif