#include "enrage.h"
using namespace std;

Enrage::Enrage(int attackMultiplier, int defenseMultiplier, unique_ptr<Minion> nextMinion): Enchantment("Enrage", "", 2, move(nextMinion)), attackMultiplier{attackMultiplier}, defenseMultiplier{defenseMultiplier} {};

int Enrage::getAttack() {
    return nextMinion->getAttack() * attackMultiplier;
}

int Enrage::getDefense() {
    return nextMinion->getDefense() * defenseMultiplier;
}

string Enrage::getLeftBox() {
    return "*" + to_string(attackMultiplier);
}

string Enrage::getRightBox() {
    return "*" + to_string(defenseMultiplier);
}