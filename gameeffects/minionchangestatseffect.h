#ifndef MINIONCHANGESTATSEFFECT_H
#define MINIONCHANGESTATSEFFECT_H
#include "gameeffect.h"
#include <memory>

class Minion; // forward declaration

using namespace std;

class MinionChangeStatsEffect : public GameEffect
{
    unique_ptr<Minion> target;
    int attackChange;
    int defenseChange;

public:
    MinionChangeStatsEffect(unique_ptr<Minion> target, int attackChange, int defenseChange);
    void useEffect() override;
};

#endif
