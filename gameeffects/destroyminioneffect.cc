#include "destroyminioneffect.h"
#include "../cards/minion.h"
#include "../player.h"
DestroyMinionEffect::DestroyMinionEffect() {}

void DestroyMinionEffect::useEffect(Player& p, int t)
{
    if (t < p.getNumMinions() && t >= 0)
    {
        p.destroyMinion(t); // same as banish
    }
}

