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

    // remove dead minions (defense <= 0) after applying damage
    removeDeadMinions(activePlayer);
    removeDeadMinions(inactivePlayer);
}

void BlizzardEffect::removeDeadMinions(Player &player)
{
    // Check minions from back to front 
    for (int i = player.getNumMinions() - 1; i >= 0; --i)
    {
        if (player.getMinionDefence(i) <= 0)
        {
            player.moveToGraveyard(i); // this should move minion to graveyard
        }
    }
}