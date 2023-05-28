#include "IdentityModule.h"

IdentityModule::IdentityModule(int rstPin, int ssPin) : rfidSensor(rstPin, ssPin)
{
}

void IdentityModule::begin()
{
  rfidSensor.begin();
}

void IdentityModule::update()
{
  uid = rfidSensor.readUid();
  Serial.println(uid);
}

String IdentityModule::getData()
{
  return uid;
}