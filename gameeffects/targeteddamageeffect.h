#ifndef TARGETEDDAMAGEEFFECT_H
#define TARGETEDDAMAGEEFFECT_H
#include "gameeffect.h"
class Minion; // forward declaration
class Player;
class TargetedDamageEffect : public GameEffect
{
    int damage;

public:
    TargetedDamageEffect(int damage);
    void useEffect(Player& p, int targetIndex) override;
};

#endif
