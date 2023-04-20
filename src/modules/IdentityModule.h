#ifndef IdentityModule_h
#define IdentityModule_h

#include "sensors/RfidSensor.h"
#include "Module.h"

class IdentityModule : public Module
{
private:
  RfidSensor rfidSensor;
  int uid;
  int scanCard();

public:
  IdentityModule(int rstPin, int ssPin);
  void update();
  void begin();
  String getData();
};

#endif