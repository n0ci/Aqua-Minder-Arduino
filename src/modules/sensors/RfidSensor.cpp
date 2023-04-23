#include "RfidSensor.h"

RfidSensor::RfidSensor(int rstPin, int ssPin) : mfrc522(ssPin, rstPin) {}

void RfidSensor::begin()
{
    SPI.begin();
    mfrc522.PCD_Init();
    Serial.println("RFID sensor initialized");
}

int RfidSensor::readUid()
{
    int uid = -1;

    if (!mfrc522.PICC_IsNewCardPresent())
    {
        return -1;
    }

    if (!mfrc522.PICC_ReadCardSerial())
    {
        return -1;
    }

    uid = (int)mfrc522.uid.uidByte;

    Serial.println("uid: " + String(uid));

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();

    return uid;
}