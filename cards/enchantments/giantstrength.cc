#include "giantstrength.h"
using namespace std;

GiantStrength::GiantStrength(int attackBuff, int defenseBuff, unique_ptr<Minion> nextMinion): Enchantment("Giant Strength", "", 1, move(nextMinion)), attackBuff{attackBuff}, defenseBuff{defenseBuff} {};

int GiantStrength::getAttack() {
    return nextMinion->getAttack() + attackBuff;
}

int GiantStrength::getDefense() {
    return nextMinion->getDefense() + defenseBuff;
}

string GiantStrength::getLeftBox() {
    return "+" + to_string(attackBuff);
}

string GiantStrength::getRightBox() {
    return "+" + to_string(defenseBuff);
}