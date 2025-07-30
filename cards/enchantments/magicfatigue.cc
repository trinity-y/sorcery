#include "magicfatigue.h"
using namespace std;

MagicFatigue::MagicFatigue(int abilityCostIncrease) : Enchanter("Magic Fatigue", "Enchanted minion's activated ability costs " + to_string(abilityCostIncrease) + " more", 0), abilityCostIncrease{abilityCostIncrease} {};

int MagicFatigue::getActivatedAbilityCost() const
{
    return nextMinion->getActivatedAbilityCost() + abilityCostIncrease;
}