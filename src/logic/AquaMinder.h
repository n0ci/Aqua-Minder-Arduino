#ifndef AquaMinder_h
#define AquaMinder_h

#include "entities/User.h"
#include "modules/Module.h"

class AquaMinder
{
private:
    enum State
    {
        INIT,
        IDLE,
        LOGIN,
        LOGOUT,
        DRINKING,
        DRANK,
        DATA_IDENTITY,
        DATA_WEATHER,
        DATA_WEIGHT,
        ERROR
    };

    enum RequestType
    {
        IDENTITY,
        WEATHER,
        WEIGHT
    };

    State state = INIT;

    Module *modules;
    int moduleCount;
    User *users;
    int userCount;

    User *currentUser = NULL;

    void updateModules();
    void initializeModules();
    void login();
    void logout();
    void drink();
    void drank();
    void dataIdentity();
    void dataWeather();
    void dataWeight();
    void error();

public:
    AquaMinder(Module *modules, int moduleCount, User *users, int userCount);
    void update();
    void notify(int requestType);
};

#endif