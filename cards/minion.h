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
    unique_ptr<ActivatedAbility> activatedAbility;
    unique_ptr<TriggeredAbility> triggeredAbility;
    // each minion should also come with a trigger to increase action by 1
    // wait, idk if it makes sense to have the triggers inside minion, because then we have to iterate through every minion at every part of the game
    // robyn said this is ok to do ^^
public:
    Minion(int attack, int defense, string name, string description, int cost, unique_ptr<ActivatedAbility> activatedAbility, unique_ptr<TriggeredAbility> triggeredAbility);
    // i also feel liek it doesnt actually make sense to attack player through the actual minion class
    // void attackPlayer();
    // void attackMinion(unique_ptr<Minion> minion);
    // void useActivatedAbility();
    int decrementActions();
    int getAttack();
    int getDefense();
    int getAttack() const;
    int getDefense() const;
    void buffAttack(int amount);
    void buffDefense(int amount);
    void takeDamage(int damage);
    void setAttack(int newAttack);
    void setDefense(int newDefense);
    TriggeredAbility *getTriggeredAbility();
    ActivatedAbility *getActivatedAbility();
    string getLeftBox() override;
    string getRightBox() override;
    void resetActions();
    void notify(TriggerState trigger);
};

#endif