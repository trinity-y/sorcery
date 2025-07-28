#ifndef SUMMONELEMENTALEFFECT_H
#define SUMMONELEMENTALEFFECT_H
#include "gameeffect.h"

class Player; // forward declaration

class SummonElementalEffect : public GameEffect
{
    string elementalType; // "Air", "Earth", "Fire", etc.

public:
    SummonElementalEffect(string elementalType);
    void useEffect(Player&p) override;
};

#endif
