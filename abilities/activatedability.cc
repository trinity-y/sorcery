#include "activatedability.h"

ActivatedAbility::ActivatedAbility(string description, unique_ptr<GameEffect> effect, int cost) : Ability{description, TriggerState::ACTIVATED_ABILITY, move(effect)}, cost{cost} {};

int ActivatedAbility::getCost() const {
    return cost;
}

