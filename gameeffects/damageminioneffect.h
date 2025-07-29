#ifndef DAMAGEMINIONEFFECT_H
#define DAMAGEMINIONEFFECT_H
#include "gameeffect.h"

class Minion; // forward declaration

class DamageMinionEffect : public GameEffect
{
    int damage;
public:
    DamageMinionEffect(int damage);
    void useEffect(Player &p, int t) override;
};

#endif
