#ifndef ACTIVATEDABILITY_H
#define ACTIVATEDABILITY_H
#include <string>
#include <memory>

#include "../trigger.h"
#include "../gameeffects/gameeffect.h"
#include "ability.h"

using namespace std;

class ActivatedAbility : public Ability {
        ActivatedAbility(string description);
        void executeTrigger() override;
};
#endif