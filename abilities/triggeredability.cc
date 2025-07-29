#include "triggeredability.h"

TriggeredAbility::TriggeredAbility(string description, TriggerState trigger, unique_ptr<GameEffect> effect): Ability{description, trigger, move(effect)} {};
