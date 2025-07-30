#include "disenchanteffect.h"
#include "../player.h"

void DisenchantEffect::useEffect(Player &p, int t)
{
    // Destroy top enchantment on a minion
    p.disenchantMinion(t);
}