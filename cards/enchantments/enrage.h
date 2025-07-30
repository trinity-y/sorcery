#ifndef ENRAGE_H
#define ENRAGE_H
#include "enchanter.h"
#include <string>
using namespace std;

class Enrage : public Enchanter
{
    int attackMultiplier;
    int defenseMultiplier;

public:
    Enrage(unique_ptr<Minion> nextMinion, int attackMultiplier = 2, int defenseMultiplier = 2);
    int getAttack() const override;
    int getDefense() const override;
    string getLeftBox() const override;
    string getRightBox() const override;
};

#endif