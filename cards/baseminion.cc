#include "baseminion.h"
#include <string>
using namespace std;
BaseMinion::BaseMinion(int attack, int defense, string name, string description, int cost, unique_ptr<ActivatedAbility> activatedAbility, unique_ptr<TriggeredAbility> triggeredAbility) : Minion{name, description, cost},
    attack{attack},
    defense{defense},
    actions{0},
    activatedAbility{move(activatedAbility)},
    triggeredAbility{move(triggeredAbility)} {};

int BaseMinion::getAttack()
{
    return attack;
}

int BaseMinion::getDefense()
{
    return defense;
}

int BaseMinion::decrementActions()
{
    return --actions;
}

string BaseMinion::getLeftBox()
{
    return to_string(attack);
}

string BaseMinion::getRightBox()
{
    return to_string(defense);
}

int BaseMinion::getDefaultActions()
{
    return 1;
}

void BaseMinion::setActions(int newActions) {
    actions = newActions;
}

void BaseMinion::notify(TriggerState trigger)
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

int BaseMinion::getActivatedAbilityCost() {
    return activatedAbilityCost;
}
