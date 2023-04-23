#include "Hx711Sensor.h"

Hx711Sensor::Hx711Sensor(int dataPin, int clockPin, float calibrationFactor) : loadCell(dataPin, clockPin)
{
    setCalibrationFactor(calibrationFactor);
}

void Hx711Sensor::begin()
{
    loadCell.begin();
    loadCell.start(1000, true);
    Serial.println("Hx711 sensor initialized");
}

float Hx711Sensor::readWeight()
{
    boolean newDataReady = 0;

    // check for new data/start next conversion:
    if (loadCell.update())
        newDataReady = true;

    // get smoothed value from the dataset:
    if (newDataReady)
    {
        float i = loadCell.getData();
        newDataReady = 0;
        return i;
    }
    return -1;
}

void Hx711Sensor::setCalibrationFactor(float factor)
{
    loadCell.setCalFactor(factor);
}

float Hx711Sensor::getCalibrationFactor(float knownMass)
{
    return loadCell.getNewCalibration(knownMass);
}

void Hx711Sensor::tare()
{
    loadCell.tare();
}