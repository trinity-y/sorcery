#ifndef UNSUMMONEFFECT_H
#define UNSUMMONEFFECT_H
#include "gameeffect.h"

class Minion; // forward declaration

class UnsummonEffect : public GameEffect
{
    Minion *target;

public:
    UnsummonEffect(Minion *target);
    void useEffect(Player& p1, Player& p2) override;
};

#endif
