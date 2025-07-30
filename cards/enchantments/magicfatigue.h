#ifndef MAGICFATIGUE_H
#define MAGICFATIGUE_H
#include "enchanter.h"
#include <string>
using namespace std;

class MagicFatigue : public Enchanter
{
    int abilityCostIncrease;

public:
    MagicFatigue(int abiltiyCostIncrease, unique_ptr<Minion> nextMinion);
    int getActivatedAbilityCost() const override;
};

#endif