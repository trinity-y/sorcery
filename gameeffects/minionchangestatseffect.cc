#include "minionchangestatseffect.h"
#include "../cards/minion.h"

MinionChangeStatsEffect::MinionChangeStatsEffect(Minion *target, int attackChange, int defenseChange)
    : target{target}, attackChange{attackChange}, defenseChange{defenseChange} {}

void MinionChangeStatsEffect::useEffect()
{
    if (target)
    {
        target->buffAttack(attackChange);
        target->buffDefense(defenseChange);
    }
}
