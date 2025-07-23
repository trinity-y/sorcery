#ifndef TRIGGEREDABILITY_H
#define TRIGGEREDABILITY_H
#include <string>
#include <memory>

#include "../trigger.h"
#include "../gameeffect.h"
#include "ability.h"

using namespace std;

class TriggeredAbility : public Ability {
        TriggeredAbility(string description, TriggerState trigger);
        void executeTrigger() override;
};
#endif