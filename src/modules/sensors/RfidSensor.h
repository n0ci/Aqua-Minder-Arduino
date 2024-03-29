#ifndef RfidSensor_h
#define RfidSensor_h

#include <SPI.h>
#include <MFRC522.h>

class RfidSensor
{
private:
    MFRC522 mfrc522;
    String uidString;

public:
    RfidSensor(int rstPin, int ssPin);
    void begin();
    String readUid();
};

#endif