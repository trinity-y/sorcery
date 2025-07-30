#ifndef UNSUMMONEFFECT_H
#define UNSUMMONEFFECT_H
#include "gameeffect.h"

class Minion; // forward declaration

class UnsummonEffect : public GameEffect
{
    Minion *target;
public:
    UnsummonEffect();
    void useEffect(Player& p, int t) override;
};

#endif
