#ifndef MINION_H
#define MINION_H
#include "card.h"
#include "memory"
#include "../abilities/activatedability.h"
#include "../abilities/triggeredability.h"
class Minion : public Card
{
    int attack;
    int defense;
    int actions;
    int activatedAbilityCost;
    unique_ptr<ActivatedAbility> activatedAbility;
    unique_ptr<TriggeredAbility> triggeredAbility;
public:
    Minion(int attack, int defense, string name, string description, int cost, unique_ptr<ActivatedAbility> activatedAbility, unique_ptr<TriggeredAbility> triggeredAbility);
    virtual ~Minion() = 0;
    int decrementActions();
    virtual int getAttack();
    virtual int getDefense();
    void changeAttack(int amount);
    void changeDefense(int amount);
    TriggeredAbility& getTriggeredAbility();
    ActivatedAbility& getActivatedAbility();
    string getLeftBox() override;
    string getRightBox() override;
    virtual int getDefaultActions();
    void setActions(int newActions);
    virtual void notify(TriggerState trigger);
    virtual int getActivatedAbilityCost();
};

#endif