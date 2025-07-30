#include "damageminioneffect.h"
#include "../cards/minion.h"
#include "../player.h"
#include <iostream>
DamageMinionEffect::DamageMinionEffect(int damage)
    : damage{damage} {}

void DamageMinionEffect::useEffect(Player &p, int t)
{
    cout << "got to damageminioneffect called Player t" << endl;
    if (t < p.getNumMinions() && t >= 0)
    {
        p.changeMinionDefence(t, -damage);
    }
}

void DamageMinionEffect::useEffect(Player &activePlayer, Player &inactivePlayer)
{
    for (int i = 0; i < inactivePlayer.getNumMinions(); i++)
    {
        cout << "minion defense before " << inactivePlayer.getMinionDefence(i) << endl;
        inactivePlayer.changeMinionDefence(i, -damage);
        cout << "minion defense after " << inactivePlayer.getMinionDefence(i) << endl;

    }
}

