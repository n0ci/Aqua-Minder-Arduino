#include "weather.h"

Weather::Weather(int pin, int type) : dht_sensor(pin, type), temperature(0), humidity(0), measurement_timestamp(0)
{
  dht_sensor.begin();
}

bool Weather::measure_environment()
{
  if (millis() - measurement_timestamp > 3000ul)
  {
    humidity = dht_sensor.readHumidity();
    temperature = dht_sensor.readTemperature();
    if (!isnan(humidity) && !isnan(temperature))
    {
      measurement_timestamp = millis();
      return true;
    }
  }
  return false;
}

void Weather::update()
{
  if (measure_environment())
  {
    Serial.print("T = ");
    Serial.print(temperature, 1);
    Serial.print(" deg. C, H = ");
    Serial.print(humidity, 1);
    Serial.println("%");
  }
}