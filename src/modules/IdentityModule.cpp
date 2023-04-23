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
}

String IdentityModule::getData()
{
  StaticJsonDocument<200> doc;
  doc["uid"] = uid;
  String json;
  serializeJson(doc, json);
  return json;
}