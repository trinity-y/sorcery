#include "enchanter.h"
using namespace std;

Enchanter::Enchanter(string name, string description, int cost) : Minion{name, description, cost}
{
    type = "ENCHANTMENT";
}

// make activated abilities/triggers go inside baseminion, but general minion still has notify.
// todo: refactor card generator
// override notify if you want to modify an ability

// override getAttack/getDefense if you want to modify attack/def stats
Enchanter::~Enchanter() {};

int Enchanter::decrementActions()
{
    return nextMinion->decrementActions();
}

int Enchanter::getAttack() const
{
    return nextMinion->getAttack();
}
int Enchanter::getDefense() const
{
    return nextMinion->getDefense();
}
const int Enchanter::getActions() const
{
    return nextMinion->getActions();
}
void Enchanter::changeAttack(int amount)
{
    nextMinion->changeAttack(amount);
}

void Enchanter::changeDefense(int amount)
{
    nextMinion->changeDefense(amount);
}

string Enchanter::getLeftBox() const
{
    return ""; // default no box
}

string Enchanter::getRightBox() const
{
    return ""; // default no box
}

int Enchanter::getDefaultActions() const
{
    return nextMinion->getDefaultActions();
}
int Enchanter::getActivatedAbilityCost() const
{
    return nextMinion->getActivatedAbilityCost();
}

// void Enchanter::notify(TriggerState trigger)
// {
//     nextMinion->notify(trigger);
// }

void Enchanter::notify(TriggerState trigger, Player &activePlayer, Player &inactivePlayer)
{
    nextMinion->notify(trigger, activePlayer, inactivePlayer);
}

void Enchanter::notify(TriggerState trigger, Player &p, int t)
{
    nextMinion->notify(trigger, p, t);
}

void Enchanter::notify(TriggerState trigger, Player &p, string t)
{
    nextMinion->notify(trigger, p, t);
}

unique_ptr<Minion> Enchanter::disenchantMinion()
{
    // this current object would be deleted after, so it is safe to transfer ownership
    return move(nextMinion);
}

void Enchanter::setNextMinion(unique_ptr<Minion> newNextMinion)
{
    nextMinion = move(newNextMinion);
}

void Enchanter::setActions(int newActions)
{
    nextMinion->setActions(newActions);
}

string Enchanter::getMinionName() const
{
    return nextMinion->getMinionName();
}


