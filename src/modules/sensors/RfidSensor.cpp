#include "RfidSensor.h"

RfidSensor::RfidSensor(int rstPin, int ssPin) : mfrc522(ssPin, rstPin) {}

void RfidSensor::begin()
{
    SPI.begin();
    mfrc522.PCD_Init();
    Serial.println("RFID sensor initialized");
}

byte *RfidSensor::readUid()
{
    static byte uid[4] = {0};

    if (!mfrc522.PICC_IsNewCardPresent())
    {
        return NULL;
    }

    if (!mfrc522.PICC_ReadCardSerial())
    {
        return NULL;
    }

    memcpy(uid, mfrc522.uid.uidByte, 4);

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();

    return uid;
}