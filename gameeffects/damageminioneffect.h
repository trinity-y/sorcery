#ifndef DAMAGEMINIONEFFECT_H
#define DAMAGEMINIONEFFECT_H
#include "gameeffect.h"


class DamageMinionEffect : public GameEffect
{
    int damage;
public:
    DamageMinionEffect(int damage);
    void useEffect(Player &p, int targetIndex) override;
    void useEffect(Player &activePlayer, Player &inactivePlayer) override;
};

#endif

