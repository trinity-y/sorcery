#ifndef ALLMINIONSSTATSEFFECT_H
#define ALLMINIONSSTATSEFFECT_H
#include "gameeffect.h"
#include <vector>
#include <memory>

class Minion; // forward declaration
class Player; // forward declaration

class AllMinionsStatsEffect : public GameEffect
{
    unique_ptr<Player> player; // Player whose minions will be affected
    int attackChange;
    int defenseChange;

public:
    AllMinionsStatsEffect(unique_ptr<Player> player, int attackChange, int defenseChange);
    void useEffect() override;
};

#endif
