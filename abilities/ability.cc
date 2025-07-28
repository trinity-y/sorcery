#include "ability.h"

Ability::Ability(string description, TriggerState trigger): Trigger{trigger}, description{description} {};

void Ability::executeTrigger() {
    gameEffect->useEffect();
}