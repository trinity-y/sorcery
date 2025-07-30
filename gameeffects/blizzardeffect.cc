#include "blizzardeffect.h"
#include "../player.h"

BlizzardEffect::BlizzardEffect(int damage) : damage(damage) {}

void BlizzardEffect::useEffect(Player &activePlayer, Player &inactivePlayer)
{
    // Deals damage to all minions on both players' boards

    // Damage all minions on active player's board
    int activePlayerMinions = activePlayer.getNumMinions();
    for (int i = 0; i < activePlayerMinions; ++i)
    {
        activePlayer.changeMinionDefence(i, -damage);
    }

    // Damage all minions on inactive player's board
    int inactivePlayerMinions = inactivePlayer.getNumMinions();
    for (int i = 0; i < inactivePlayerMinions; ++i)
    {
        inactivePlayer.changeMinionDefence(i, -damage);
    }

    // remove dead minions (defense )
}