#include "selfbuffeffect.h"
#include "../cards/minion.h"
#include "../player.h"

SelfBuffEffect::SelfBuffEffect(int attackChange, int defenseChange)
    : attackChange{attackChange}, defenseChange{defenseChange} {}

void SelfBuffEffect::useEffect(Player &p, int minionIndex)
{
    // Apply buffs
    p.changeMinionAttack(minionIndex, attackChange);
    p.changeMinionDefence(minionIndex, defenseChange);
}
