#ifndef ENRAGE_H
#define ENRAGE_H
#include "enchantment.h"
#include <string>
using namespace std;

class Enrage : public Enchantment {
    int attackMultiplier;
    int defenseMultiplier;
    public:
        Enrage(int attackMultiplier=2, int defenseMultiplier=2, unique_ptr<Minion> nextMinion);
        int getAttack() override;
        int getDefense() override;
        string getLeftBox() override;
        string getRightBox() override;
};

#endif