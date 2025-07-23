#include "triggeredability.h"

TriggeredAbility::TriggeredAbility(string description, TriggerState trigger): Ability{description, trigger} {};

void TriggeredAbility::executeTrigger() {
    gameEffect->useEffect();
}
