#include "AquaMinder.h"

AquaMinder::AquaMinder(IdentityModule id, WeightModule weight, WeatherModule weather, User *users, int userCount)
    : identityModule(id), weightModule(weight), weatherModule(weather), users(users), userCount(userCount)
{
}

void AquaMinder::update()
{
    switch (state)
    {
    case INIT:
        initializeModules();
        changeState(IDLE);
        break;
    case IDLE:
        updateModules();
        changeState(UPDATE_USER);
        break;
    case UPDATE_USER:
    {
        String uid = getKeyFromJson(identityModule.getData(), "uid");
        if (getUser(uid) == "")
        {
            registerNewUser(uid);
        }
        changeState(UPDATE_WEIGHT);
    }
    break;
    case UPDATE_WEIGHT:
    {
        currentUser->update(getKeyFromJson(weightModule.getData(), "weight").toFloat());
        changeState(IDLE);
    }
    break;
    case DATA_IDENTITY:
        Serial.println(currentUser->getUidJson());
        changeState(IDLE);
        break;
    case DATA_WEATHER:
        Serial.println(weatherModule.getData());
        changeState(IDLE);
        break;
    case DATA_WEIGHT:
        Serial.println(currentUser->getDrankWeightJson());
        changeState(IDLE);
        break;
    default: // Should never happen
        Serial.println("ERROR: Invalid state");
        break;
    }
}

void AquaMinder::initializeModules()
{
    Serial.println("*** Starting up modules... ***");

    identityModule.begin();
    weightModule.begin();
    weatherModule.begin();

    Serial.println("*** Ready! ***");
    Serial.println();
}

void AquaMinder::updateModules()
{
    identityModule.update();
    weightModule.update();
    weatherModule.update();
}

void AquaMinder::notify(RequestType requestType)
{
    switch (requestType)
    {
    case IDENTITY:
        changeState(DATA_IDENTITY);
        break;
    case WEATHER:
        changeState(DATA_WEATHER);
        break;
    case WEIGHT:
        changeState(DATA_WEIGHT);
        break;
    default:
        break;
    }
}

String AquaMinder::getUser(const String &uid)
{
    for (int i = 0; i < userCount; i++)
    {
        if (users[i].getUid() == uid && uid.compareTo("") != 0)
        {
            currentUser = &users[i];
            Serial.print("Found user: ");
            Serial.println(currentUser->getUid());
            return currentUser->getUid();
        }
    }
    return "";
}

String AquaMinder::registerNewUser(const String &uid)
{
    if (uid.compareTo("") == 0)
    {
        return "";
    }

    for (int i = 0; i < userCount; i++)
    {
        if (users[i].getUid().compareTo("") == 0)
        {
            users[i].setUid(uid);
            currentUser = &users[i];
            Serial.print("Registered new user: ");
            Serial.println(currentUser->getUid());
            return currentUser->getUid();
        }
    }
    return "";
}

String AquaMinder::getKeyFromJson(const String &json, const String &key)
{
    // Allocate the JSON document
    StaticJsonDocument<200> doc;

    // Deserialize the JSON document
    DeserializationError error = deserializeJson(doc, json);

    // Test if parsing succeeds
    if (error)
    {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.c_str());
        return "";
    }
    else
    {
        return doc[key].as<String>();
    }
}

void AquaMinder::changeState(State newState)
{
    if (newState == state)
    {
        return;
    }
    state = newState;

    // Wait for the state to change
    __asm__("nop\n\t");
}