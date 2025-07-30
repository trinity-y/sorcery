#include "enrage.h"
using namespace std;

Enrage::Enrage(int attackMultiplier, int defenseMultiplier) : Enchanter("Enrage", "", 2), attackMultiplier{attackMultiplier}, defenseMultiplier{defenseMultiplier} {};

int Enrage::getAttack() const
{
    return nextMinion->getAttack() * attackMultiplier;
}

int Enrage::getDefense() const
{
    return nextMinion->getDefense() * defenseMultiplier;
}

string Enrage::getLeftBox() const
{
    return "*" + to_string(attackMultiplier);
}

string Enrage::getRightBox() const
{
    return "*" + to_string(defenseMultiplier);
}