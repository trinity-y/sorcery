#ifndef GAINMAGICEFFECT_H
#define GAINMAGICEFFECT_H
#include "gameeffect.h"

class Player; // forward declaration

class GainMagicEffect : public GameEffect
{
    Player *player;
    int magicAmount;

public:
    GainMagicEffect(Player *player, int magicAmount);
    void useEffect() override;
};

#endif
