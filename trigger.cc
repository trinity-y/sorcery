#include "trigger.h"
#include <iostream>
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
    cerr << "got here trigger" << newState << endl;
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
