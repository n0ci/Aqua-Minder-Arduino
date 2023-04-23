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
  int uid = (int)rfidSensor.readUid();
  if (uid != -1)
  {
    Serial.println("******");
    Serial.println(uid);
  }
}

String IdentityModule::getData()
{
  StaticJsonDocument<200> doc;
  doc["uid"] = uid;
  String json;
  serializeJson(doc, json);
  return json;
}