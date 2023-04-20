#ifndef WeatherModule_h
#define WeatherModule_h

#include "sensors/DhtSensor.h"
#include "Module.h"

class WeatherModule : public Module
{
private:
  DhtSensor dhtSensor;
  float temperature = -1;
  float humidity = -1;

public:
  WeatherModule(int pin, int type);
  void begin();
  void update();
  String getData();
};

#endif