#ifndef MINION_H
#define MINION_H
#include "card.h"
#include "memory"
#include "../abilities/activatedability.h"
#include "../abilities/triggeredability.h"
class Minion : public Card
{
    // int activatedAbilityCost;
    // unique_ptr<ActivatedAbility> activatedAbility;
    // unique_ptr<TriggeredAbility> triggeredAbility;
public:
    // Minion(int attack, int defense, string name, string description, int cost, unique_ptr<ActivatedAbility> activatedAbility, unique_ptr<TriggeredAbility> triggeredAbility);
    Minion(string name, string description, int cost);

    virtual int decrementActions() = 0;
    virtual int getAttack() = 0;
    virtual int getDefense() = 0;
    virtual void changeAttack(int amount) = 0;
    virtual void changeDefense(int amount) = 0;
    // TriggeredAbility& getTriggeredAbility();
    // ActivatedAbility& getActivatedAbility();
    virtual string getLeftBox() = 0;
    virtual string getRightBox() = 0;
    virtual int getDefaultActions() = 0;
    virtual void setActions(int newActions) = 0;
    virtual void notify(TriggerState trigger) = 0;
    // virtual void notify(TriggerState trigger, Player& p) = 0;
    virtual void notify(TriggerState trigger, Player& p, int i) = 0;
    virtual void notify(TriggerState trigger, Player& p, string t) = 0;
    virtual int getActivatedAbilityCost() = 0;
};

#endif