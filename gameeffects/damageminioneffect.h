#ifndef DAMAGEMINIONEFFECT_H
#define DAMAGEMINIONEFFECT_H
#include "gameeffect.h"

class Minion; // forward declaration

class DamageMinionEffect : public GameEffect
{
    Minion *target;
    int damage;

public:
    DamageMinionEffect(Minion *target, int damage);
    void useEffect() override;
};

#endif
