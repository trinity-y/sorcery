#include "minionchangestatseffect.h"
#include "../cards/minion.h"
#include "../player.h"

MinionChangeStatsEffect::MinionChangeStatsEffect(int attackChange, int defenseChange)
    : attackChange{attackChange}, defenseChange{defenseChange} {}

void MinionChangeStatsEffect::useEffect(Player &p, int t)
{
    Board &board = p.getBoard();
    if (t >= 0 && t < board.getNumMinions())
    {
        Minion &minion = board.getMinion(t);
        minion.buffAttack(attackChange);
        minion.changeDefense(defenseChange);
    }
}
