#include "User.h"

User::User()
{
}

void User::setUid(String uid)
{
    this->uid = uid;
}

String User::getUid()
{
    return uid;
}

float User::getDrankWeight()
{
    return drankWeight;
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

void User::update(float newWeight)
{
    // If lastWeightUpdate is 0, this is the first weight update in a while
    if (lastWeightUpdate == 0)
    {
        lastWeightUpdate = millis();
    }

    // Withdraw first few weight updates
    if ((millis() - lastWeightUpdate) < 3000)
    {
        return;
    }
    else
    {
        lastWeightUpdate = 0;
    }

    // If the weight is less than bottleWeight, not a valid weight
    if (newWeight < bottleWeight)
    {
        return;
    }

    // If the weight is within the tolerance, the user hasn't drank anything
    int diff = this->validWeight - newWeight;
    if (abs(diff) < toleranceWeight)
    {
        return;
    }
    // If the diff is higher than the valid weight, the user has drank something
    else if (diff > 0)
    {
        drankWeight += diff;
        weight = newWeight;
    }
    // If the diff is lower than the valid weight, the user has filled the bottle
    else if (diff < 0)
    {
        weight = newWeight;
    }
}