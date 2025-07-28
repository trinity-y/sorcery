#include "minion.h"
#include <string>
using namespace std;
// todo: maybe make types an enum
Minion::Minion(int attack, int defense, string name, string description, int cost, unique_ptr<ActivatedAbility> activatedAbility, unique_ptr<TriggeredAbility> triggeredAbility) : Card{"MINION", name, description, cost},
                                                                                                                                                                                   attack{attack},
                                                                                                                                                                                   defense{defense},
                                                                                                                                                                                   actions{0},
                                                                                                                                                                                   activatedAbility{move(activatedAbility)},
                                                                                                                                                                                   triggeredAbility{move(triggeredAbility)} {};

int Minion::getAttack()
{
    return attack;
}

int Minion::getDefense()
{
    return defense;
}

int Minion::setAttack(int newAttack)
{
    attack = newAttack;
}

int Minion::setDefense(int newDefense)
{
    defense = newDefense;
}

int Minion::setAttack(int newAttack)
{
    attack = newAttack;
}

int Minion::setDefense(int newDefense)
{
    defense = newDefense;
}

int Minion::decrementActions()
{
    return --actions;
}

string Minion::getLeftBox()
{
    return to_string(attack);
}

string Minion::getRightBox()
{
    return to_string(defense);
}

void Minion::resetActions()
{
    actions = 1;
}

void Minion::notify(TriggerState trigger)
{
    if (activatedAbility && actions > 0)
    {
        activatedAbility->notify(trigger);
        --actions;
    }
    if (triggeredAbility)
    {
        triggeredAbility->notify(trigger);
    }
}

void Minion::buffAttack(int amount)
{
    attack += amount;
}

void Minion::buffDefense(int amount)
{
    defense += amount;
}

void Minion::takeDamage(int damage)
{
    defense -= damage;
    // In a more complete implementation, you might want to:
    // - Check if defense goes to 0 or below (minion dies)
    // - Trigger any "when damaged" effects
    // - Handle damage prevention effects
}

TriggeredAbility *Minion::getTriggeredAbility()
{
    return triggeredAbility.get();
}

ActivatedAbility *Minion::getActivatedAbility()
{
    return activatedAbility.get();
}