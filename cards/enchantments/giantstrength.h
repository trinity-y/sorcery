#ifndef GIANTSTRENGTH_H
#define GIANTSTRENGTH_H
#include "enchantment.h"
#include <string>
using namespace std;

class GiantStrength : public Enchantment {
    int attackBuff;
    int defenseBuff;
    public:
        GiantStrength(int attackBuff=2, int defenseBuff=2, unique_ptr<Minion> nextMinion);
        int getAttack() override;
        int getDefense() override;
        string getLeftBox() override;
        string getRightBox() override;
};

#endif