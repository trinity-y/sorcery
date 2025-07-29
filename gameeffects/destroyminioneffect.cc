#include "destroyminioneffect.h"
#include "../cards/minion.h"
#include "../player.h"
DestroyMinionEffect::DestroyMinionEffect() {}

void DestroyMinionEffect::useEffect(Player& p, int t)
{
    if (t < p.getNumMinions() && t >= 0)
    {
        // Set defense to 0 or negative to "destroy" the minion
        // In a full implementation, this would trigger removal from board
        p.changeMinionDefence(t, p.getMinionDefence(t));
    }
}
