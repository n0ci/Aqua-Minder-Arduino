#include "LoginModule.h"

LoginModule::LoginModule(int rstPin, int ssPin) : rfidSensor(rstPin, ssPin), num_users(0) {}

void LoginModule::begin()
{
  rfidSensor.begin();
}

int LoginModule::scanCard()
{
  byte *uid = rfidSensor.readUid();
  if (uid == NULL)
  {
    return -1;
  }

  int user_id = findUser(uid);
  if (user_id == -1)
  {
    user_id = registerUser(uid);
    Serial.print("New user registered with ID ");
    Serial.println(user_id);
  }
  else
  {
    Serial.print("Existing user detected with ID ");
    Serial.println(user_id);
  }

  return user_id;
}

int LoginModule::findUser(byte *uid)
{
  for (int i = 0; i < num_users; i++)
  {
    if (memcmp(users[i].uid, uid, 4) == 0)
    {
      return i;
    }
  }
  return -1;
}

int LoginModule::registerUser(byte *uid)
{
  if (num_users >= 10)
  {
    return -1;
  }

  memcpy(users[num_users].uid, uid, 4);
  int user_id = num_users;
  num_users++;

  return user_id;
}

void LoginModule::update()
{
  int user_id = scanCard();
  if (user_id != -1)
  {
    Serial.print(F("Welcome, user "));
    Serial.println(user_id);
  }
}
