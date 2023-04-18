#include "WeatherModule.h"

WeatherModule::WeatherModule(int pin, int type) : dhtSensor(pin, type), temperature(0), humidity(0), measurement_timestamp(0)
{
}

void WeatherModule::begin()
{
  dhtSensor.begin();
}

bool WeatherModule::measureEnvironment()
{
  if (millis() - measurement_timestamp > 3000ul)
  {
    humidity = dhtSensor.readHumidity();
    temperature = dhtSensor.readTemperature();
    if (!isnan(humidity) && !isnan(temperature))
    {
      measurement_timestamp = millis();
      return true;
    }
  }
  return false;
}

void WeatherModule::update()
{
  if (measureEnvironment())
  {
    Serial.print("T = ");
    Serial.print(temperature, 1);
    Serial.print(" deg. C, H = ");
    Serial.print(humidity, 1);
    Serial.println("%");
  }
}