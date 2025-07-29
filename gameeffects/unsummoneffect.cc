#include "unsummoneffect.h"
#include "../cards/minion.h"

UnsummonEffect::UnsummonEffect(Minion *target)
    : target{target} {}

void UnsummonEffect::useEffect(Player& p1, Player& p2)
{
    if (target)
    {
        // Return the minion to its owner's hand
        // In a full implementation, this would:
        // 1. Remove minion from board
        // 2. Add minion back to owner's hand
        // 3. Reset any temporary buffs/debuffs

        // THIS IS SUPPPOSED TO:
        // return target minion to owner's hand
    }
}
