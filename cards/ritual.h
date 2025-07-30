#ifndef RITUAL_H
#define RITUAL_H
#include "card.h"
#include "../abilities/triggeredability.h"
#include <memory>
class Ritual : public Card
{
    unique_ptr<TriggeredAbility> triggeredAbility;
    int charges;
    int activationCost;

public:
    Ritual(string name, string description, int cost, unique_ptr<TriggeredAbility> triggeredAbility, int charges);
    void changeCharges(int amount);
    void notify(TriggerState trigger, Player &activePlayer, Player &inactivePlayer);

    // getters for Ritual properties (used in TextDisplay)
    int getCharges() const;
    int getActivationCost() const;

    string getLeftBox() const override;
    string getRightBox() const override;
};

#endif
