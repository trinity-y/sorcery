#ifndef SUMMONELEMENTALEFFECT_H
#define SUMMONELEMENTALEFFECT_H
#include "gameeffect.h"

class Player; // forward declaration

class SummonElementalEffect : public GameEffect
{
    Player *player;
    string elementalType; // "Air", "Earth", "Fire", etc.

public:
    SummonElementalEffect(Player *player, string elementalType);
    void useEffect() override;
};

#endif
