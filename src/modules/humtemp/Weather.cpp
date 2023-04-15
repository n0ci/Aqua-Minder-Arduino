#include "weather.h"

Weather::Weather() : dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE), temperature(0), humidity(0), measurement_timestamp(0) {}

bool Weather::measure_environment()
{
  if (millis() - measurement_timestamp > 3000ul)
  {
    if (dht_sensor.measure(&temperature, &humidity))
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