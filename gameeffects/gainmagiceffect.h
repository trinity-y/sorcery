#ifndef GAINMAGICEFFECT_H
#define GAINMAGICEFFECT_H
#include "gameeffect.h"

class Player; // forward declaration

class GainMagicEffect : public GameEffect
{
    int magicAmount;

public:
    GainMagicEffect(int magicAmount);
    void useEffect(Player& activePlayer, Player& inactivePlayer) override;
};

#endif
