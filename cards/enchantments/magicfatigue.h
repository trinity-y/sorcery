#ifndef MAGICFATIGUE_H
#define MAGICFATIGUE_H
#include "enchantment.h"
#include <string>
using namespace std;

class MagicFatigue : public Enchantment {
    int abilityCostIncrease;
    public:
        MagicFatigue(int abiltiyCostIncrease, unique_ptr<Minion> nextMinion);
        int getActivatedAbilityCost() override;
};

#endif