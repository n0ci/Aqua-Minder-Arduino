#include "WeatherModule.h"

WeatherModule::WeatherModule(int pin, int type, float tempThreshold, float humThreshold) : 
  dhtSensor(pin, type), temperature(0), humidity(0), measurement_timestamp(0), 
  tempThreshold(tempThreshold), humThreshold(humThreshold), lastTemperature(0), lastHumidity(0)
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
    printTemperatureIfChanged(temperature, tempThreshold);
    printHumidityIfChanged(humidity, humThreshold);
  }
}

void WeatherModule::printTemperatureIfChanged(float temperature, float tempThreshold)
{
  float absoluteChange = abs(temperature - lastTemperature);
  lastTemperature = temperature;

  if (absoluteChange > tempThreshold)
  {
    Serial.print("T = ");
    Serial.print(temperature, 1);
    Serial.println(" deg. C");
  }
}

void WeatherModule::printHumidityIfChanged(float humidity, float humThreshold)
{
  float absoluteChange = abs(humidity - lastHumidity);
  lastHumidity = humidity;

  if (absoluteChange > humThreshold)
  {
    Serial.print("H = ");
    Serial.print(humidity, 1);
    Serial.println("%");
  }
}