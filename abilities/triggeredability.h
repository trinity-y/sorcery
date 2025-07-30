#ifndef TRIGGEREDABILITY_H
#define TRIGGEREDABILITY_H
#include <string>
#include <memory>

#include "../trigger.h"
#include "../gameeffects/gameeffect.h"
#include "ability.h"

using namespace std;

class TriggeredAbility : public Ability
{
public:
        TriggeredAbility(string description, TriggerState trigger, unique_ptr<GameEffect> effect);
        virtual ~TriggeredAbility() {};
        // virtual void notify(TriggerState trigger);
        // notify(trigger, p, t)
        // virtual void notify(TriggerState trigger, Player& p, string t);
        // virtual void notify(TriggerState trigger, Player& p, int t);
        // virtual void notify(TriggerState trigger, Player& activePlayer, Player& inactivePlayer);
};
#endif
