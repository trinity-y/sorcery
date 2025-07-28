#include "damageeffect.h"
#include "../cards/minion.h"

DamageEffect::DamageEffect(unique_ptr<Minion> target, int damage)
    : target{move(target)}, damage{damage} {}

void DamageEffect::useEffect()
{
    if (target)
    {
        target->takeDamage(damage);
    }
}
