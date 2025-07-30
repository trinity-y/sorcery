#ifndef GIANTSTRENGTH_H
#define GIANTSTRENGTH_H
#include "enchanter.h"
#include <string>
using namespace std;

class GiantStrength : public Enchanter
{
    int attackBuff;
    int defenseBuff;

public:
    GiantStrength(unique_ptr<Minion> nextMinion, int attackBuff = 2, int defenseBuff = 2);
    int getAttack() const override;
    int getDefense() const override;
    string getLeftBox() const override;
    string getRightBox() const override;
};

#endif