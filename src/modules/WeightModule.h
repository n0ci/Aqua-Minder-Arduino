#ifndef WeightModule_h
#define WeightModule_h

#include "sensors/Hx711Sensor.h"

class WeightModule
{
private:
  Hx711Sensor hx711Sensor;
  float lastWeight;
  float weightThreshold;

  void setCalibrationFactor(float factor);
  float readWeight();
  void tare();
  void calibrate();
  void printIfChanged(float weight);

public:
  WeightModule(uint8_t dataPin, uint8_t clockPin, float weightThreshold);
  void begin();
  void update();
};

#endif