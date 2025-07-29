#include "ability.h"

Ability::Ability(string description, TriggerState trigger, unique_ptr<GameEffect> effect) : Trigger{trigger}, description{description}, gameEffect{move(effect)} {};

void Ability::executeTrigger()
{
    gameEffect->useEffect();
}