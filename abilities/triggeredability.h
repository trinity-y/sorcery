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
        TriggeredAbility(string description, TriggerState trigger);
        void executeTrigger() override;
};
#endif