#include "User.h"

User::User(int uid, float tareWeight, float calibrationFactor)
    : uid(uid), tareWeight(tareWeight), calibrationFactor(calibrationFactor)
{
}

String User::getUidJson()
{
    StaticJsonDocument<200> doc;
    doc["uid"] = uid;
    String json;
    serializeJson(doc, json);
    return json;
}

String User::getDrankWeightJson()
{
    StaticJsonDocument<200> doc;
    doc["drankWeight"] = drankWeight;
    String json;
    serializeJson(doc, json);
    return json;
}

int User::getUid()
{
    return uid;
}

float User::getDrankWeight()
{
    return drankWeight;
}

void User::setTareWeight(float tareWeight)
{
    this->tareWeight = tareWeight;
}

void User::setLastWeight(float lastWeight)
{
    this->lastWeight = lastWeight;
}

void User::setDrankWeight(float drankWeight)
{
    this->drankWeight = drankWeight;
}

void User::setCalibrationFactor(float calibrationFactor)
{
    this->calibrationFactor = calibrationFactor;
}