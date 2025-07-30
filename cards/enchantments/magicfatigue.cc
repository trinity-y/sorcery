#include "magicfatigue.h"
using namespace std;

MagicFatigue::MagicFatigue(int abilityCostIncrease, unique_ptr<Minion> nextMinion) : Enchanter("Magic Fatigue", "Enchanted minion's activated ability costs " + to_string(abilityCostIncrease) + " more", 0, move(nextMinion)), abilityCostIncrease{abilityCostIncrease} {};

int MagicFatigue::getActivatedAbilityCost() const
{
    return nextMinion->getActivatedAbilityCost() + abilityCostIncrease;
}