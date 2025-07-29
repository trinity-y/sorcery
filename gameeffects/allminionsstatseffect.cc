#include "allminionsstatseffect.h"
#include "../player.h"
#include "../cards/minion.h"

AllMinionsStatsEffect::AllMinionsStatsEffect(int attackChange, int defenseChange)
    : attackChange{attackChange}, defenseChange{defenseChange} {}

void AllMinionsStatsEffect::useEffect(Player &activePlayer, Player& inactivePlayer)
{
    int numMinions = activePlayer.getNumMinions();

    // Iterate through all minions on the player's board
    for (int i = 0; i < numMinions; ++i)
    {
        activePlayer.changeMinionAttack(i, attackChange);
        activePlayer.changeMinionDefence(i, defenseChange);
    }
}
