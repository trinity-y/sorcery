#include "trigger.h"

Trigger::Trigger(TriggerState trigger) : trigger{trigger} {};

// void Trigger::notify(TriggerState newState) {
//     if (newState == trigger) {
//         executeTrigger();
//     }
// }

void Trigger::notify(TriggerState newState, Player &p, string i)
{
    if (newState == trigger)
    {
        executeTrigger(p, i);
    }
}

void Trigger::notify(TriggerState newState, Player &activePlayer, Player &inactivePlayer)
{
    if (newState == trigger)
    {
        executeTrigger(activePlayer, inactivePlayer);
    }
}

void Trigger::notify(TriggerState newState, Player &p, int i)
{
    if (newState == trigger)
    {
        executeTrigger(p, i);
    }
}