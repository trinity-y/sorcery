#include "activatedability.h"

ActivatedAbility::ActivatedAbility(string description): Ability{description, TriggerState::ACTIVATED_ABILITY} {};

void ActivatedAbility::executeTrigger() {
    gameEffect->useEffect();
}
