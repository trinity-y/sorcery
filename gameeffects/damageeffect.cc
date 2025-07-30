#include "damageeffect.h"
#include "../cards/minion.h"
#include "../player.h"
#include <iostream>
DamageEffect::DamageEffect(int damage)
    : damage{damage} {}

void DamageEffect::useEffect(Player &p, int targetIndex)
{
    cout << "damaging minion";
    p.changeMinionDefence(targetIndex, -damage);
    // whenever an oppent's minions enters play, deal 1 damage ot it
    // TODO: This needs to be moved into player
    // const Board &board = p.getBoard();
    // if (t >= 0 && t < board.getNumMinions())
    // {
    //     const Minion &minion = board.getMinion(t);
    //     minion.changeDefense(-damage);
    // }
}

