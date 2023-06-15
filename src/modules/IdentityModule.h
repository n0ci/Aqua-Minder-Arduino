#ifndef IdentityModule_h
#define IdentityModule_h

#include <ArduinoJson.h>
#include "sensors/RfidSensor.h"

class IdentityModule
{
private:
  RfidSensor rfidSensor;
  String uid = "noID";
  int scanCard();

public:
  IdentityModule(int rstPin, int ssPin);
  void update();
  void begin();
  String getData();
};

#endif