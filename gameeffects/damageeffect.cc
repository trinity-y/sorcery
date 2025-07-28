#include "damageeffect.h"
#include "../cards/minion.h"

DamageEffect::DamageEffect(Minion *target, int damage)
    : target{target}, damage{damage} {}

void DamageEffect::useEffect()
{
    if (target)
    {
        target->takeDamage(damage);
    }
}
