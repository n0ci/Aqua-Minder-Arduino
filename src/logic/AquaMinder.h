#ifndef AquaMinder_h
#define AquaMinder_h

#define USER_COUNT 10
#include "entities/User.h"

class AquaMinder
{
    enum State
    {
        IDLE,
        LOGIN,
        LOGOUT,
        DRINKING,
        DRANK
    };

private:
    User users[USER_COUNT];
    User *currentUser = NULL;
    State state = IDLE;

public:
    AquaMinder();
    User *getCurrentUser();
    State changeState(State newState);
};

#endif