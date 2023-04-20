#include "WeatherModule.h"

WeatherModule::WeatherModule(int pin, int type) : dhtSensor(pin, type)
{
}

void WeatherModule::begin()
{
  dhtSensor.begin();
}

void WeatherModule::update()
{
  humidity = dhtSensor.readHumidity();
  temperature = dhtSensor.readTemperature();
}

String WeatherModule::getData()
{
  StaticJsonDocument<200> doc;
  doc["temperature"] = temperature;
  doc["humidity"] = humidity;
  String json;
  serializeJson(doc, json);
  return json;
}