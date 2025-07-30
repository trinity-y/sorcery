#include "ability.h"
#include <string>

Ability::Ability(string description, TriggerState trigger, unique_ptr<GameEffect> effect) : Trigger{trigger}, description{description}, gameEffect{move(effect)} {};

// void Ability::executeTrigger()
// {
//     gameEffect->useEffect();
// }

void Ability::executeTrigger(Player &activePlayer, Player &inactivePlayer)
{
    gameEffect->useEffect(activePlayer, inactivePlayer);
}

void Ability::executeTrigger(Player &p, int i)
{
    gameEffect->useEffect(p, i);
}

void Ability::executeTrigger(Player &p, string t)
{
    gameEffect->useEffect(p, t);
}