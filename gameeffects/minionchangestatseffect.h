#ifndef MINIONCHANGESTATSEFFECT_H
#define MINIONCHANGESTATSEFFECT_H
#include "gameeffect.h"

class Minion; // forward declaration

class MinionChangeStatsEffect : public GameEffect
{
    Minion *target;
    int attackChange;
    int defenseChange;

public:
    MinionChangeStatsEffect(Minion *target, int attackChange, int defenseChange);
    void useEffect() override;
};

#endif
