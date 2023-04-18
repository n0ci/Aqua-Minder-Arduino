#ifndef WeatherModule_h
#define WeatherModule_h

#include "sensors/DhtSensor.h"

class WeatherModule {
  private:
    DhtSensor dhtSensor;
    float temperature;
    float humidity;
    unsigned long measurement_timestamp;
    
  public:
    WeatherModule(int pin, int type);
    void begin();
    bool measureEnvironment();
    void update();
};

#endif