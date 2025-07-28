#ifndef DAMAGEEFFECT_H
#define DAMAGEEFFECT_H
#include "gameeffect.h"

class Minion; // forward declaration

class DamageEffect : public GameEffect
{
    Minion *target;
    int damage;

public:
    DamageEffect(Minion *target, int damage);
    void useEffect() override;
};

#endif
