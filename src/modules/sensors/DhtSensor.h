// DhtSensor.h
#ifndef DhtSensor_h
#define DhtSensor_h

#include <DHT.h>

class DhtSensor {
  private:
    DHT dht_sensor;
    
  public:
    DhtSensor(int pin, int type);
    void begin();
    float readHumidity();
    float readTemperature();
};

#endif