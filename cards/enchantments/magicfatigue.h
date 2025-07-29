#ifndef HASTE_H
#define HASTE_H
#include "enchantment.h"
#include <string>
using namespace std;

class Haste : public Enchantment {
    int actionBoost;
    public:
        Haste(int actionBoost, unique_ptr<Minion> nextMinion);
        int getDefaultActions() override;
};

#endif