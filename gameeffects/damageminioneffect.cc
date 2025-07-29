#include "damageminioneffect.h"
#include "../cards/minion.h"
#include "../player.h"
DamageMinionEffect::DamageMinionEffect(int damage)
    : damage{damage} {}

void DamageMinionEffect::useEffect(Player &p, int t)
{
    if (t < p.getNumMinions() && t >= 0)
    {
        p.changeMinionDefence(t, -damage);
    }
}
