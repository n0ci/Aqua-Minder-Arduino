#ifndef AquaMinder_h
#define AquaMinder_h

#include "entities/User.h"
#include "modules/WeightModule.h"
#include "modules/IdentityModule.h"
#include "modules/WeatherModule.h"
#include "modules/WeightModule.h"
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

    User *currentUser = NULL;
    void initializeModules();
    void updateModules();
    String getUser(String uid);
    String registerNewUser(String uid);

    void
    updateCurrentUserWeight();

    void changeState(State newState);

    String getKeyFromJson(String json, String key);

public:
    AquaMinder(IdentityModule identityModule, WeightModule weightModule, WeatherModule weatherModule, User *users, int userCount);
    void update();
    void notify(int requestType);
};

#endif