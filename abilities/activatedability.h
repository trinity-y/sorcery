#ifndef ACTIVATEDABILITY_H
#define ACTIVATEDABILITY_H
#include <string>
#include <memory>

#include "../trigger.h"
#include "../gameeffects/gameeffect.h"
#include "ability.h"

using namespace std;

class ActivatedAbility : public Ability
{
public:
        ActivatedAbility(string description, unique_ptr<GameEffect> effect);
        virtual ~ActivatedAbility() {};
        // virtual void notify(TriggerState trigger, Player &activePlayer, Player &inactivePlayer){};
        // virtual void notify(TriggerState trigger, Player &p, int t){};
        // virtual void notify(TriggerState trigger, Player &p, string t){};
};
#endif