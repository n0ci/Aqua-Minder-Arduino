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
  String newUid = rfidSensor.readUid();
  if (newUid != "noID")
  {
    uid = newUid;
  }
}

String IdentityModule::getData()
{
  return uid;
}