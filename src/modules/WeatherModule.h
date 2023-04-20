#ifndef WeatherModule_h
#define WeatherModule_h

#include "sensors/DhtSensor.h"

class WeatherModule
{
private:
  DhtSensor dhtSensor;
  float temperature;
  float humidity;

  float lastTemperature;
  float lastHumidity;

  float tempThreshold;
  float humThreshold;

  unsigned long measurement_timestamp;
  void printTemperatureIfChanged(float temperature, float tempThreshold);
  void printHumidityIfChanged(float humidity, float humThreshold);
  bool measureEnvironment();

public:
  WeatherModule(int pin, int type, float tempThreshold, float humThreshold);
  void begin();
  void update();
};

#endif