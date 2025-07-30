#include "activatedability.h"

ActivatedAbility::ActivatedAbility(string description, unique_ptr<GameEffect> effect) : Ability{description, TriggerState::ACTIVATED_ABILITY, move(effect)} {};
