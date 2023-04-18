#ifndef WeightModule_h
#define WeightModule_h

#include "sensors/Hx711Sensor.h"

class WeightModule {
  private:
    Hx711Sensor hx711Sensor;
    float lastWeight;
    float absoluteThreshold;
    
  public:
    WeightModule(uint8_t dataPin, uint8_t clockPin, float percentThreshold);
    void begin();
    void setCalibrationFactor(float factor);
    float readWeight();
    void tare();
    void calibrate();
    void update();
    void printIfChanged(float weight);
};

#endif