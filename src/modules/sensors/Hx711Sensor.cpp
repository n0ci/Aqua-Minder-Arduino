#include "Hx711Sensor.h"

Hx711Sensor::Hx711Sensor(int dataPin, int clockPin, float calibrationFactor) : loadCell(dataPin, clockPin)
{
    setCalibrationFactor(calibrationFactor);
}

void Hx711Sensor::begin()
{
    loadCell.begin();
    loadCell.start(1000, true);
    Serial.println("DHT sensor initialized");
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
}

void Hx711Sensor::setCalibrationFactor(float factor)
{
    loadCell.setCalFactor(factor);
}