#include "damageeffect.h"
#include "../cards/minion.h"
#include "../player.h"

DamageEffect::DamageEffect(int damage)
    : damage{damage} {}

void DamageEffect::useEffect(Player &p, int t)
{
    Board &board = p.getBoard();
    if (t >= 0 && t < board.getNumMinions())
    {
        Minion &minion = board.getMinion(t);
        minion.changeDefense(-damage);
    }
}
