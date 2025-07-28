#include "destroyminioneffect.h"
#include "../cards/minion.h"

DestroyMinionEffect::DestroyMinionEffect(Minion *target)
    : target{target} {}

void DestroyMinionEffect::useEffect()
{
    if (target)
    {
        // Set defense to 0 or negative to "destroy" the minion
        // In a full implementation, this would trigger removal from board
        target->buffDefense(-target->getDefense() - 1);
    }
}
