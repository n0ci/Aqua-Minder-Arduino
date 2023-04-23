#ifndef AquaMinder_h
#define AquaMinder_h

#include "entities/User.h"
#include "modules/WeightModule.h"
#include "modules/IdentityModule.h"
#include "modules/WeatherModule.h"
#include <ArduinoJson.h>

class AquaMinder
{
private:
    enum State
    {
        INIT,
        IDLE,
        UPDATE_USER,
        UPDATE_WEIGHT,
        DATA_IDENTITY,
        DATA_WEATHER,
        DATA_WEIGHT
    };

    enum RequestType
    {
        IDENTITY,
        WEATHER,
        WEIGHT
    };

    State state = INIT;

    IdentityModule identityModule;
    WeightModule weightModule;
    WeatherModule weatherModule;

    User *users;
    int userCount;

    User *currentUser = nullptr;

    void initializeModules();
    void updateModules();
    String getUser(const String &uid);
    String registerNewUser(const String &uid);
    void updateCurrentUserWeight();
    void changeState(State newState);
    String getKeyFromJson(const String &json, const String &key);

public:
    AquaMinder(IdentityModule id, WeightModule weight, WeatherModule weather, User *users, int userCount);
    void update();
    void notify(RequestType requestType);
};

#endif