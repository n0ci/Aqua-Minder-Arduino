#include "AquaMinder.h"

AquaMinder::AquaMinder(Module *modules, int moduleCount, User *users, int userCount)
{
    this->modules = modules;
    this->moduleCount = moduleCount;
    this->users = users;
    this->userCount = userCount;
}

void AquaMinder::update()
{
    switch (state)
    {
    case INIT:
        initializeModules();
        state = IDLE;
        // Fall through
    case IDLE:
        updateModules();
        break;
    case LOGIN:
        break;
    case LOGOUT:
        break;
    case DRINKING:
        break;
    case DRANK:
        break;
    case DATA_IDENTITY:
        break;
    case DATA_WEATHER:
        break;
    case DATA_WEIGHT:
        break;
    case ERROR:
        break;
    default: // Should never happen
        break;
    }
}

void AquaMinder::initializeModules()
{
    Serial.println("*** Starting up modules... ***");

    for (int i = 0; i < moduleCount; i++)
    {
        modules[i].begin();
    }

    Serial.println("*** Ready! ***");
    Serial.println();
}

void AquaMinder::updateModules()
{
    for (int i = 0; i < moduleCount; i++)
    {
        modules[i].update();
    }
}

void AquaMinder::login()
{
}

void AquaMinder::logout()
{
}

void AquaMinder::drink()
{
}

void AquaMinder::drank()
{
}

void AquaMinder::dataIdentity()
{
    Serial.println(currentUser->getUidJson());
}

void AquaMinder::dataWeather()
{
    Serial.println(modules[1].getData());
}

void AquaMinder::dataWeight()
{
    Serial.println(currentUser->getDrankWeightJson());
}

void AquaMinder::error()
{
}
