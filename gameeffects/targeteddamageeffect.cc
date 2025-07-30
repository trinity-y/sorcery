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

        // Check if the minion's defense is now 0 or less
        if (p.getMinionDefence(targetIndex) <= 0)
        {
            // Remove the minion (to graveyard)
            p.moveToGraveyard(targetIndex);
        }
    } 
}
