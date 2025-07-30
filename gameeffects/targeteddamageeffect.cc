#include "targeteddamageeffect.h"
#include "../cards/minion.h"
#include "../player.h"

TargetedDamageEffect::TargetedDamageEffect(int damage)
    : damage{damage} {}
void TargetedDamageEffect::useEffect(Player &p, int targetIndex)
{
    if (targetIndex < p.getNumMinions() && targetIndex >= 0)
    {
        const int targetDefence = p.getMinionDefence(targetIndex);
        p.changeMinionDefence(targetIndex, -damage);

        
    } // TODO: Handle minion death if defense <= 0
}
