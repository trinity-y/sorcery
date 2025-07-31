#include "baseminion.h"
#include <string>
#include <iostream>
using namespace std;
BaseMinion::BaseMinion(int attack, int defense, string name, string description, int cost, unique_ptr<ActivatedAbility> activatedAbility, unique_ptr<TriggeredAbility> triggeredAbility) : Minion{name, description, cost},
                                                                                                                                                                                           attack{attack},
                                                                                                                                                                                           defense{defense},
                                                                                                                                                                                           actions{0},
                                                                                                                                                                                           activatedAbilityCost{activatedAbility != nullptr ? activatedAbility->getCost() : 0},
                                                                                                                                                                                           activatedAbility{move(activatedAbility)},
                                                                                                                                                                                           triggeredAbility{move(triggeredAbility)} {};

int BaseMinion::decrementActions()
{
    return --actions;
}

int BaseMinion::getAttack() const
{
    return attack;
}

int BaseMinion::getDefense() const
{
    return defense;
}

// In a more complete implementation, you might want to:
// - Check if defense goes to 0 or below (BaseMinion dies)
// - Trigger any "when damaged" effects
// - Handle damage prevention effects
void BaseMinion::changeDefense(int amount)
{
    defense += amount;
}

void BaseMinion::changeAttack(int amount)
{
    attack += amount;
}

string BaseMinion::getLeftBox() const
{
    return to_string(attack);
}

string BaseMinion::getRightBox() const
{
    return to_string(defense);
}

int BaseMinion::getDefaultActions() const
{
    return 1;
}

void BaseMinion::setActions(int newActions)
{
    // cout << "set actions " << newActions << endl;
    actions = newActions;
}

// ! a lot of repeated code here :(
// idk if the below function is required for anyhting, since now we shouldnt have empty gamestates-
// void BaseMinion::notify(TriggerState trigger)
// {
//     if (activatedAbility && actions > 0)
//     {
//         activatedAbility->notify(trigger);
//         --actions;
//     }
//     if (triggeredAbility)
//     {
//         triggeredAbility->notify(trigger);
//     }
// }

void BaseMinion::notify(TriggerState trigger, Player &p, int t)
{
    // ! debug
    // cout << "notifying " << name << "of event " << trigger << " for minion index " << t << endl;

    if (activatedAbility && actions > 0)
    {
        activatedAbility->notify(trigger, p, t);
        --actions;
    }
    if (triggeredAbility)
    {
        triggeredAbility->notify(trigger, p, t);
    }
}
// int targetMinionIndex = board->getNumMinions() - 1;
//             notify(MINION_ENTERS, activePlayer, targetMinionIndex);
//             inactivePlayer.notify(MINION_ENTERS, inactivePlayer, targetMinionIndex);
// i feel like this one shouldnt be needed cause minios dont have ritual targets
// we  can keep it anyways tohugh ig
void BaseMinion::notify(TriggerState trigger, Player &p, string t)
{
    // ! debug
    // cout << "notifying " << name << "of event " << trigger << " for minion index " << t << endl;
    if (activatedAbility && actions > 0)
    {
        activatedAbility->notify(trigger, p, t);
        --actions;
    }
    if (triggeredAbility)
    {
        triggeredAbility->notify(trigger, p, t);
    }
}

void BaseMinion::notify(TriggerState trigger, Player &activePlayer, Player &inactivePlayer)
{
    if (trigger == TriggerState::ACTIVATED_ABILITY && activatedAbility && actions > 0)
    {
        activatedAbility->notify(trigger, activePlayer, inactivePlayer);
        --actions;
    }
    if (triggeredAbility)
    {
        triggeredAbility->notify(trigger, activePlayer, inactivePlayer);
    }
}

int BaseMinion::getActivatedAbilityCost() const // in actions -- this func is technically not needed
{
    return activatedAbilityCost;
}

const int BaseMinion::getActions() const
{
    return actions;
}

string BaseMinion::getMinionName() const
{
    return name;
}

int BaseMinion::getCost() const
{
    return cost;
}

string BaseMinion::getMinionDescription() const
{
    // if (triggeredAbility != nullptr)
    // {
    return description;
    // }
    return ""; // return empty string if no description
}
