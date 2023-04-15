#ifndef WEATHER_H
#define WEATHER_H

#include <DHT.h>

#define DHT_SENSOR_TYPE DHT11
#define DHT_SENSOR_PIN 2

class Weather
{
private:
  DHT dht_sensor;
  float temperature;
  float humidity;
  unsigned long measurement_timestamp;

  bool measure_environment();

public:
  Weather();
  void update();
};

#endif
