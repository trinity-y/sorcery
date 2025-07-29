#ifndef BASEMINION_H
#define BASEMINION_H
#include "minion.h"
#include "memory"
#include "../abilities/activatedability.h"
#include "../abilities/triggeredability.h"
class BaseMinion : public Minion
{
    int attack;
    int defense;
    int actions;
    int activatedAbilityCost;
    unique_ptr<ActivatedAbility> activatedAbility;
    unique_ptr<TriggeredAbility> triggeredAbility;
    // each minion should also come with a trigger to increase action by 1
    // wait, idk if it makes sense to have the triggers inside minion, because then we have to iterate through every minion at every part of the game
    // robyn said this is ok to do ^^
public:
    BaseMinion(int attack, int defense, string name, string description, int cost, unique_ptr<ActivatedAbility> activatedAbility, unique_ptr<TriggeredAbility> triggeredAbility);
    int decrementActions() override;
    int getAttack() override;
    int getDefense() override;
    void changeAttack(int amount) override;
    void changeDefense(int amount) override;
    // TriggeredAbility& getTriggeredAbility();
    // ActivatedAbility& getActivatedAbility();
    string getLeftBox() override;
    string getRightBox() override;
    void setActions(int newActions) override;
    void notify(TriggerState trigger) override;
    int getActivatedAbilityCost() override;
    int getDefaultActions() override;
};

#endif
