#ifndef OWNERMINIONBUFFEFFECT_H
#define OWNERMINIONBUFFEFFECT_H

#include "gameeffect.h"

class OwnerMinionBuffEffect : public GameEffect
{
    int attackBuff;
    int defenseBuff;

public:
    OwnerMinionBuffEffect(int attack, int defense);
    void useEffect(Player &p, int targetIndex) override;
};

#endif