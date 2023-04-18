#ifndef LoginModule_h
#define LoginModule_h

#include "sensors/RfidSensor.h"

struct User
{
  byte uid[4];
};

class LoginModule
{
private:
  RfidSensor rfidSensor;
  User users[10];
  int num_users;

public:
  LoginModule(int rstPin, int ssPin);
  void begin();
  int findUser(byte *uid);
  int registerUser(byte *uid);
  int scanCard();
  void update();
};

#endif