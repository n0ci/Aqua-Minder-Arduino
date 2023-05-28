#include "AquaMinder.h"

AquaMinder::AquaMinder(IdentityModule id, WeightModule weight, WeatherModule weather)
    : identityModule(id), weightModule(weight), weatherModule(weather)
{
}

void AquaMinder::initializeModules()
{
    Serial.println("*** Starting up modules... ***");

    identityModule.begin();
    weightModule.begin();
    weatherModule.begin();

    Serial.println("*** Ready! ***");
}

void AquaMinder::update()
{
    identityModule.update();
    weatherModule.update();
    weightModule.update();
}

void AquaMinder::notify(RequestType requestType)
{
    switch (requestType)
    {
    case IDENTITY:
        identityModule.update();
        Serial.println(identityModule.getData());
        break;
    case WEATHER:
        weatherModule.update();
        Serial.println(weatherModule.getData());
        break;
    case WEIGHT:
        Serial.println(weightModule.getData());
        break;
    default:
        break;
    }
}