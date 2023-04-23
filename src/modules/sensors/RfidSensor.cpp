#include "RfidSensor.h"

RfidSensor::RfidSensor(int rstPin, int ssPin) : mfrc522(ssPin, rstPin) {}

void RfidSensor::begin()
{
    SPI.begin();
    mfrc522.PCD_Init();
    Serial.println("RFID sensor initialized");
}

String RfidSensor::readUid()
{
    byte uid[4] = {0};

    if (!mfrc522.PICC_IsNewCardPresent())
    {
        return "";
    }

    if (!mfrc522.PICC_ReadCardSerial())
    {
        return "";
    }

    memcpy(uid, mfrc522.uid.uidByte, 4);

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();

    String uidString = "";
    for (int i = 0; i < 4; i++)
    {
        uidString += String(uid[i], HEX);
    }

    return uidString;
}