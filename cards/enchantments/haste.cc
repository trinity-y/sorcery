#include "haste.h"
using namespace std;

Haste::Haste(int actionBoost, unique_ptr<Minion> nextMinion): Enchantment("Haste", "Enchanted minion gains +1 action each turn", 1, move(nextMinion)), actionBoost{actionBoost} {};

int Haste::getDefaultActions() {
    return nextMinion->getDefaultActions() + actionBoost;
}