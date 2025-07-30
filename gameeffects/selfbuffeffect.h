#ifndef SELFBUFFEFFECT_H
#define SELFBUFFEFFECT_H
#include "gameeffect.h"

class Player; // forward declaration

class SelfBuffEffect : public GameEffect
{
    int attackChange;
    int defenseChange;

public:
    SelfBuffEffect(int attackChange, int defenseChange);
    void useEffect(Player &p, int minionIndex) override; // Gets specific minion by index
};

#endif

