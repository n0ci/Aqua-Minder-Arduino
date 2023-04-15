#include "RFIDLogin.h"

RFIDLogin::RFIDLogin(int rstPin, int ssPin) : mfrc522(ssPin, rstPin), num_users(0) {}

void RFIDLogin::begin() {
  Serial.begin(9600);
  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println(F("Welcome, please register or login using your card."));
  
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}

int RFIDLogin::scanCard() {
  byte uid[4] = {0};

  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return -1;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return -1;
  }

  // Get the UID of the card
  memcpy(uid, mfrc522.uid.uidByte, 4);

  // Halt PICC and re-select it
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  // Find or register the user
  int user_id = findUser(uid);
  if (user_id == -1) {
    user_id = registerUser(uid);
  }
  
  return user_id;
}

int RFIDLogin::findUser(byte* uid) {
  for (int i = 0; i < num_users; i++) {
    if (memcmp(users[i].uid, uid, 4) == 0) {
      return i;
    }
  }
  Serial.println(F("User not found."));
  return -1;
}

int RFIDLogin::registerUser(byte* uid) {
  if (num_users >= 10) {
    Serial.println(F("Cannot register more users."));
    return -1;
  }
  
  // Save user data
  memcpy(users[num_users].uid, uid, 4);
  int user_id = num_users;
  num_users++;
  
  Serial.print(F("New user registered with ID "));
  
  return user_id;
}