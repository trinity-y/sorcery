#include "targeteddamageeffect.h"
#include "../cards/minion.h"

TargetedDamageEffect::TargetedDamageEffect(int damage)
    : damage{damage}, target{nullptr} {}

void TargetedDamageEffect::setTarget(Minion *newTarget)
{
    target = newTarget;
}

void TargetedDamageEffect::useEffect()
{
    if (target)
    {
        target->takeDamage(damage);
    }
}
