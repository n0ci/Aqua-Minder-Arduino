#ifndef RFIDLogin_h
#define RFIDLogin_h

#include <SPI.h>
#include <MFRC522.h>

class RFIDLogin {
  public:
    RFIDLogin(int rstPin, int ssPin);
    void begin();
    int scanCard();
    int findUser(byte* uid);
    int registerUser(byte* uid);
    
  private:
    MFRC522 mfrc522;
    MFRC522::MIFARE_Key key;
    struct User {
      byte uid[4];
    };
    User users[10];
    int num_users;
};

#endif