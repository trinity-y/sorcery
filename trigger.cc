#include "trigger.h"

Trigger::Trigger(TriggerState trigger): trigger{trigger} {};

void Trigger::notify(TriggerState newState) {
    if (newState == trigger) {
        executeTrigger();
    }
}
