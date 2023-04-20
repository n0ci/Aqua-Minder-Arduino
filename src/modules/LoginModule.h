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

  int findUser(byte *uid);
  int registerUser(byte *uid);
  int scanCard();

public:
  LoginModule(int rstPin, int ssPin);
  void update();
  void begin();
};

#endif