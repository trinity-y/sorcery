#ifndef DAMAGEEFFECT_H
#define DAMAGEEFFECT_H
#include "gameeffect.h"
#include <memory>
#include <string>

class Minion; // forward declaration

class DamageEffect : public GameEffect
{
    int damage;
public:
    DamageEffect(int damage);
    void useEffect(Player &p, int t) override;
};

#endif
