#include "allminionsstatseffect.h"
#include "../player.h"
#include "../cards/minion.h"

AllMinionsStatsEffect::AllMinionsStatsEffect(unique_ptr<Player> player, int attackChange, int defenseChange)
    : player{move(player)}, attackChange{attackChange}, defenseChange{defenseChange} {}

void AllMinionsStatsEffect::useEffect()
{
    if (player && player->board)
    {
        // In full implementation, iterate through all minions on the player's board
        // and apply the stat changes to each one
        // For now, this is a placeholder that shows the structure:

        // Pseudocode for what this would do:
        // for (auto& card : player->board->getAllMinions()) {
        //     if (auto minion = dynamic_cast<Minion*>(card.get())) {
        //         minion->buffAttack(attackChange);
        //         minion->buffDefense(defenseChange);
        //     }
        // }
    }
}
