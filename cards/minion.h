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
    // unique_ptr<TriggeredAbility> triggeredAbility;
    // each minion should also come with a trigger to increase action by 1
    // wait, idk if it makes sense to have the triggers inside minion, because then we have to iterate through every minion at every part of the game
    public:
        Minion(int attack, int defense);
        // i also feel liek it doesnt actually make sense to attack player through the actual minion class
        // void attackPlayer(); 
        // void attackMinion(unique_ptr<Minion> minion);
        // void useActivatedAbility();
        int decrementActions();
        int getAttack();
        int getDefense();
};

#endif