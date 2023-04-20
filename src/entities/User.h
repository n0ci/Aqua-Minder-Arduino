#ifndef User_h
#define User_h

#include <Arduino.h>
#include <ArduinoJson.h>

class User
{
private:
    int uid;
    float tareWeight = 0;
    float lastWeight = 0;
    float drankWeight = 0;
    float calibrationFactor = 0;

public:
    User(int uid, float tareWeight, float calibrationFactor);
    int getUid();
    String getUidJson();
    float getDrankWeight();
    String getDrankWeightJson();

    void setTareWeight(float tareWeight);
    void setLastWeight(float lastWeight);
    void setDrankWeight(float drankWeight);
    void setCalibrationFactor(float calibrationFactor);
};

#endif