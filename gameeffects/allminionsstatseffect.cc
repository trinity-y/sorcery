#include "allminionsstatseffect.h"
#include "../player.h"
#include "../cards/minion.h"

AllMinionsStatsEffect::AllMinionsStatsEffect(Player& player, int attackChange, int defenseChange)
    : player{move(player)}, attackChange{attackChange}, defenseChange{defenseChange} {}

void AllMinionsStatsEffect::useEffect()
{
    if (player)
    {
        Board &board = player->getBoard();
        int numMinions = board.getNumMinions();

        // Iterate through all minions on the player's board
        for (int i = 0; i < numMinions; ++i)
        {
            Minion &minion = board.getMinion(i);
            minion.buffAttack(attackChange);
            minion.buffDefense(defenseChange);
        }
    }
}
