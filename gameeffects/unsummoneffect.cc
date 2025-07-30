#include "unsummoneffect.h"
#include "../cards/minion.h"
#include "../player.h"

UnsummonEffect::UnsummonEffect() {}

// In a full implementation, this would:
// 1. Remove minion from board
// 2. Add minion back to owner's hand
// 3. Reset any temporary buffs/debuffs
void UnsummonEffect::useEffect(Player &p, int t)
{
    // THIS IS SUPPPOSED TO:
    // return target minion to owner's hand
    p.returnToHand(t);
}

