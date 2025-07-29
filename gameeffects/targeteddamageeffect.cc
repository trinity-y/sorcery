#include "targeteddamageeffect.h"
#include "../cards/minion.h"
#include "../player.h"

TargetedDamageEffect::TargetedDamageEffect(int damage)
    : damage{damage} {}
void TargetedDamageEffect::useEffect(Player& p, int t)
{
    if (t < p.getNumMinions() && t >= 0)
    {
        int targetDefence = p.getMinionDefence(t);
        p.setMinionDefence(t, t - damage);
    }
}
