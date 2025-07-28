#include "ability.h"

Ability::Ability(string description, TriggerState trigger) : Trigger{trigger}, description{description} {};

void Ability::setGameEffect(unique_ptr<GameEffect> effect)
{
    gameEffect = move(effect);
}

void Ability::executeTrigger() {
    gameEffect->useEffect();
}