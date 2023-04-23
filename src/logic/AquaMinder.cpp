#include "AquaMinder.h"

AquaMinder::AquaMinder(IdentityModule id, WeightModule weight, WeatherModule weather, User *users, int userCount) : identityModule(id), weightModule(weight), weatherModule(weather), users(users), userCount(userCount)
{
}

void AquaMinder::update()
{
    switch (state)
    {
    case INIT:
    {
        initializeModules();
        changeState(IDLE);
    }
    // Fall through to IDLE
    case IDLE:
    {
        updateModules();
        changeState(UPDATE_USER);
    }
    // Fall through to UPDATE_USER
    case UPDATE_USER:
    {
        int uid = checkIfUserChanged();
        if (uid != -1)
        {
            Serial.println("User changed");
            updateCurrentUser(uid);
        }
        // changeState(UPDATE_WEIGHT);
        break;
    }
    // Fall through to UPDATE_WEIGHT
    case UPDATE_WEIGHT:
    {
        currentUser->update(getKeyFromJson(weightModule.getData(), "weight").toFloat());
        changeState(IDLE);
        break;
    }
    case DATA_IDENTITY:
    {
        Serial.println(currentUser->getUidJson());
        changeState(IDLE);
        break;
    }
    case DATA_WEATHER:
    {
        Serial.println(weatherModule.getData());
        changeState(IDLE);
        break;
    }
    case DATA_WEIGHT:
    {
        Serial.println(currentUser->getDrankWeightJson());
        changeState(IDLE);
        break;
    }
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

int AquaMinder::checkIfUserChanged()
{
    int newUid = getKeyFromJson(identityModule.getData(), "uid").toInt();
    if (currentUser->getUid() != newUid)
    {
        return newUid;
    }
    return -1;
}

void AquaMinder::updateCurrentUser(int newUid)
{
    currentUser = NULL;
    for (int i = 0; i < userCount; i++)
    {
        if (users[i].getUid() == newUid)
        {
            // Found the user, set it as the current user
            currentUser = &users[i];
            return;
        }
    }
}

void AquaMinder::notify(int requestType)
{
    switch (requestType)
    {
    case IDENTITY:
        state = DATA_IDENTITY;
        break;
    case WEATHER:
        state = DATA_WEATHER;
        break;
    case WEIGHT:
        state = DATA_WEIGHT;
        break;
    default:
        break;
    }
}

String AquaMinder::getKeyFromJson(String json, String key)
{
    // Allocate the JSON document
    StaticJsonDocument<200> doc;

    // Deserialize the JSON document
    DeserializationError error = deserializeJson(doc, json);

    // Test if parsing succeeds
    if (error)
    {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
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
    // Serial.print("STATE: ");
    // Serial.println(state);
}