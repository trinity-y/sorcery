#include "haste.h"
using namespace std;

Haste::Haste(int actionBoost, unique_ptr<Minion> nextMinion) : Enchanter("Haste", "Enchanted minion gains +" + to_string(actionBoost) + " action each turn", 1, move(nextMinion)), actionBoost{actionBoost} {};

int Haste::getDefaultActions() const
{
    return nextMinion->getDefaultActions() + actionBoost;
}
