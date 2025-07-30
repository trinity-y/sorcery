#ifndef MINIONCHANGESTATSEFFECT_H
#define MINIONCHANGESTATSEFFECT_H
#include "gameeffect.h"
#include <memory>

class Minion; // forward declaration
class Player;

using namespace std;

class MinionChangeStatsEffect : public GameEffect
{
    int attackChange;
    int defenseChange;

public:
    MinionChangeStatsEffect(int attackChange, int defenseChange);
    void useEffect(Player &p, int t) override;
};

#endif

