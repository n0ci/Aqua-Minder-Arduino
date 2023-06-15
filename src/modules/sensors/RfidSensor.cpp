#include "RfidSensor.h"

RfidSensor::RfidSensor(int rstPin, int ssPin) : mfrc522(ssPin, rstPin) {}

void RfidSensor::begin()
{
    SPI.begin();
    mfrc522.PCD_Init();
    uidString = "";

    Serial.println("RFID sensor initialized");
}

/**
 * If the card is new => read the id
 *
 * If the card stays on the sensor it is in state HALT, therfore we cant read the card again.
 * PICC_WakeupA reactivates the card and sets it to state IDLE and can be read again.
 *
 * If no chip is present there is nothing to wakeup => uid=null
 */
String RfidSensor::readUid()
{
    if (mfrc522.PICC_IsNewCardPresent())
    {
        if (mfrc522.PICC_ReadCardSerial())
        {
            byte uid[4] = {0};

            memcpy(uid, mfrc522.uid.uidByte, 4);

            uidString = "";

            for (int i = 0; i < 4; i++)
            {
                uidString += String(uid[i], HEX);
            }
        }

        mfrc522.PICC_HaltA();
        mfrc522.PCD_StopCrypto1();
    }
    else
    {
        byte bufferATQA[2];
        byte bufferSize = sizeof(bufferATQA);

        if (!mfrc522.PICC_WakeupA(bufferATQA, &bufferSize) == MFRC522::STATUS_OK)
            uidString = "noID";
    }

    return uidString;
}