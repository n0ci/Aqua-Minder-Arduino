#ifndef User_h
#define User_h

#include <Arduino.h>
#include <ArduinoJson.h>

class User
{
private:
    int uid = 1;

    float weight = 0;
    float validWeight = 0;
    float drankWeight = 0;
    unsigned long lastWeightUpdate = 0;

    const int toleranceWeight = 10;
    const int bottleWeight = 20;

public:
    User(int uid);
    int getUid();
    float getDrankWeight();

    String getDrankWeightJson();
    String getUidJson();

    void update(float newWeight);
};

#endif