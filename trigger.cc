#include "trigger.h"

Trigger::Trigger(TriggerState trigger): trigger{trigger} {};

void Trigger::notify(TriggerState newState) {
    if (newState == trigger) {
        executeTrigger();
    }
}

void Trigger::notify(TriggerState newState, Player& p, string i) {
    if (newState == trigger) {
        executeTrigger(p, i);
    }
}

void Trigger::notify(TriggerState newState, Player& p) {
    if (newState == trigger) {
        executeTrigger(p);
    }
}

void Trigger::notify(TriggerState newState, Player& p, int i) {
    if (newState == trigger) {
        executeTrigger(p, i);
    }
}