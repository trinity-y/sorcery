#include "magicfatigue.h"
using namespace std;

MagicFatigue::MagicFatigue(int abilityCostIncrease, unique_ptr<Minion> nextMinion): Enchantment("Magic Fatigue", "Enchanted minion's activated ability costs " + to_string(abilityCostIncrease) + " more" , 0, move(nextMinion)), abilityCostIncrease{abilityCostIncrease} {};

int MagicFatigue::getActivatedAbilityCost() {
    return nextMinion->getActivatedAbilityCost() + abilityCostIncrease;
}