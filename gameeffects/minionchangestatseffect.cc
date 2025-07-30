#include "minionchangestatseffect.h"
#include "../cards/minion.h"
#include "../player.h"

MinionChangeStatsEffect::MinionChangeStatsEffect(int attackChange, int defenseChange)
    : attackChange{attackChange}, defenseChange{defenseChange} {}

void MinionChangeStatsEffect::useEffect(Player &p, int t)
{
    // idk why theres still an error referencing board when its nowhere to be seen, idk if it's just the IDE
    p.changeMinionAttack(t, attackChange);
    p.changeMinionDefence(t, defenseChange);
}

