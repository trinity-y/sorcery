#include "minionchangestatseffect.h"
#include "../cards/minion.h"

MinionChangeStatsEffect::MinionChangeStatsEffect(unique_ptr<Minion> target, int attackChange, int defenseChange)
    : target{move(target)}, attackChange{attackChange}, defenseChange{defenseChange} {}

void MinionChangeStatsEffect::useEffect()
{
    if (target)
    {
        target->buffAttack(attackChange);
        target->buffDefense(defenseChange);
    }
}
