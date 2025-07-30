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

    virtual ~Minion() = 0;
    virtual int decrementActions() = 0;
    virtual int getAttack() const = 0;
    virtual int getDefense() const = 0;
    virtual void changeAttack(int amount) = 0;
    virtual void changeDefense(int amount) = 0;
    virtual const int getActions() const = 0;
    // TriggeredAbility& getTriggeredAbility();
    // ActivatedAbility& getActivatedAbility();
    virtual string getLeftBox() const = 0;
    virtual string getRightBox() const = 0;
    virtual int getDefaultActions() const = 0;
    virtual void setActions(int newActions) = 0;
    // virtual void notify(TriggerState trigger) = 0;
    virtual int getActivatedAbilityCost() const = 0;
    virtual void notify(TriggerState trigger, Player &activePlayer, Player &inactivePlayer) = 0;
    virtual void notify(TriggerState trigger, Player &p, int i) = 0;
    virtual void notify(TriggerState trigger, Player &p, string t) = 0;

    virtual string getMinionName() const = 0;
    virtual int getCost() const = 0;
    virtual string getMinionDescription() const = 0;
};

#endif

