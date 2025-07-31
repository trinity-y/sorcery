#include "damageminioneffect.h"
#include "../cards/minion.h"
#include "../player.h"
#include <iostream>
DamageMinionEffect::DamageMinionEffect(int damage)
    : damage{damage} {}

void DamageMinionEffect::useEffect(Player &p, int t)
{
    // cout << "got to damageminioneffect called Player t" << endl;
    // need to check that it's the opponent
    if (t < p.getNumMinions() && t >= 0)
    {
        p.changeMinionDefence(t, -damage);
    }
}

void DamageMinionEffect::useEffect(Player &activePlayer, Player &inactivePlayer)
{
    int i = activePlayer.getNumMinions() - 1;
    activePlayer.changeMinionDefence(i, -damage);
}
