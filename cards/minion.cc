#include "minion.h"
// will need to be updated when card constructor is more thought out
Minion::Minion(int attack, int defense): Card{"Minion"}, attack{attack}, defense{defense}, actions{0} {};

int Minion::getAttack() {
    return attack;
}

int Minion::getDefense() {
    return defense;
}

int Minion::decrementActions() {
    return --actions;
}
