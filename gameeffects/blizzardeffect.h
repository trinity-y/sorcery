#ifndef BLIZZARDEFFECT_H
#define BLIZZARDEFFECT_H
#include "gameeffect.h"

Class Player; // Forward declaration

class BlizzardEffect : public GameEffect
{
    int damage; // Amount of damage to deal to each minion
    void removeDeadMinions(Player& player); // Helper method
public:
    BlizzardEffect(int dmg= 2);
    void useEffect(Player& activePlayer, Player& inactivePlayer) override;
};

#endif