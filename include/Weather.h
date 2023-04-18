#ifndef WEATHER_H
#define WEATHER_H

#include <DHT.h>

class Weather
{
public:
  Weather(int pin, int type);
  void update();

private:
  DHT dht_sensor;
  float temperature;
  float humidity;
  unsigned long measurement_timestamp;

  bool measure_environment();
};

#endif
