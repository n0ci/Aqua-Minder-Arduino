#ifndef WeightModule_h
#define WeightModule_h

#include "sensors/Hx711Sensor.h"
#include <ArduinoJson.h>

class WeightModule
{
private:
  Hx711Sensor hx711Sensor;
  float weight = -1;

  float readWeight();
  void calibrate();
  void tare();

public:
  WeightModule(uint8_t dataPin, uint8_t clockPin);
  void begin();
  void update();
  String getData();
};

#endif