#ifndef Hx711Sensor_h
#define Hx711Sensor_h

#include <HX711_ADC.h>
#include <EEPROM.h>

class Hx711Sensor {
  private:
    HX711_ADC loadCell;
    
  public:
    Hx711Sensor(uint8_t dataPin, uint8_t clockPin, float calibrationFactor);
    void begin();
    void setCalibrationFactor(float factor);
    float readWeight();
    void tare();
};

#endif