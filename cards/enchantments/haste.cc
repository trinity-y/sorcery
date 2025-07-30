#include "haste.h"
using namespace std;

Haste::Haste(int actionBoost) : Enchanter("Haste", "Enchanted minion gains +" + to_string(actionBoost) + " action each turn", 1), actionBoost{actionBoost} {};

int Haste::getDefaultActions() const
{
    return nextMinion->getDefaultActions() + actionBoost;
}
