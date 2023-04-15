#ifndef WEATHER_H
#define WEATHER_H

#include <dht_nonblocking.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11
#define DHT_SENSOR_PIN 2

class Weather
{
private:
  DHT_nonblocking dht_sensor;
  float temperature;
  float humidity;
  unsigned long measurement_timestamp;

  bool measure_environment();

public:
  Weather();
  void update();
};

#endif