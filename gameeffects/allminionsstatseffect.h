#ifndef ALLMINIONSSTATSEFFECT_H
#define ALLMINIONSSTATSEFFECT_H
#include "gameeffect.h"
#include <vector>
#include <memory>

class Minion; // forward declaration
class Player; // forward declaration

class AllMinionsStatsEffect : public GameEffect
{
    int attackChange;
    int defenseChange;

public:
    AllMinionsStatsEffect(int attackChange, int defenseChange);
    void useEffect(Player& activePlayer, Player& inactivePlayer) override;
};

#endif
