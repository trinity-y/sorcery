#include "giantstrength.h"
using namespace std;

GiantStrength::GiantStrength(unique_ptr<Minion> nextMinion, int attackBuff, int defenseBuff) : Enchanter("Giant Strength", "", 1, move(nextMinion)), attackBuff{attackBuff}, defenseBuff{defenseBuff} {};

int GiantStrength::getAttack() const
{
    return nextMinion->getAttack() + attackBuff;
}

int GiantStrength::getDefense() const
{
    return nextMinion->getDefense() + defenseBuff;
}

string GiantStrength::getLeftBox() const
{
    return "+" + to_string(attackBuff);
}

string GiantStrength::getRightBox() const
{
    return "+" + to_string(defenseBuff);
}