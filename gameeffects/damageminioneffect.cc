#include "damageminioneffect.h"
#include "../cards/minion.h"

DamageMinionEffect::DamageMinionEffect(Minion *target, int damage)
    : target{target}, damage{damage} {}

void DamageMinionEffect::useEffect()
{
    if (target)
    {
        target->takeDamage(damage);
    }
}
