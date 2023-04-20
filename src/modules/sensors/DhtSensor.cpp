#include "DhtSensor.h"

DhtSensor::DhtSensor(int pin, int type) : dht_sensor(pin, type)
{
}

void DhtSensor::begin()
{
  dht_sensor.begin();
  Serial.println("DHT sensor initialized");
}

float DhtSensor::readHumidity()
{
  return dht_sensor.readHumidity();
}

float DhtSensor::readTemperature()
{
  return dht_sensor.readTemperature();
}