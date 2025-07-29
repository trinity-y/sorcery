#ifndef DAMAGEEFFECT_H
#define DAMAGEEFFECT_H
#include "gameeffect.h"
#include <memory>

class Minion; // forward declaration

class DamageEffect : public GameEffect
{
    unique_ptr<Minion> target;
    int damage;

public:
    DamageEffect(unique_ptr<Minion> target, int damage);
    void useEffect() override;
};

#endif