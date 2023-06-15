#ifndef AquaMinder_h
#define AquaMinder_h

#include "modules/WeightModule.h"
#include "modules/IdentityModule.h"
#include "modules/WeatherModule.h"
#include <ArduinoJson.h>

class AquaMinder
{
private:
    enum RequestType
    {
        IDENTITY,
        WEATHER,
        WEIGHT
    };

    IdentityModule identityModule;
    WeightModule weightModule;
    WeatherModule weatherModule;

public:
    AquaMinder(IdentityModule id, WeightModule weight, WeatherModule weather);

    void initializeModules();
    void update();
    void notify(RequestType requestType);
    void spam();
    void sendAllData();
};

#endif