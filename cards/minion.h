#ifndef MINION_H
#define MINION_H
#include "card.h"
#include "memory"
#include "activatedability.h"
#include "triggeredability.h"
class Minion : public Card {
    int attack;
    int defense;
    int actions;
    unique_ptr<ActivatedAbility> activatedAbility;
    unique_ptr<TriggeredAbility> triggeredAbility;
    public:
        Minion();
};

#endif