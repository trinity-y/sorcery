#ifndef RITUAL_H
#define RITUAL_H
#include "card.h"
#include "../abilities/triggeredability.h"
#include <memory>
class Ritual : public Card {
    unique_ptr<TriggeredAbility> triggeredAbility;
    int charges;
    public:
        Ritual(string name, string description, int cost, unique_ptr<TriggeredAbility> triggeredAbility, int charges);
        void notify(TriggerState trigger);

};

#endif