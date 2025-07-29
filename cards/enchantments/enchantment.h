#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H
#include "../minion.h"

using namespace std;
class Enchantment : public Minion {
    protected:
        unique_ptr<Minion> nextMinion; // next minion in the decorator chain
    public:
        // unfortunately, some fields in minion dont apply to enchantment (i.e attack. ) we just have to live with that otherwise we would have to have too many layers of inheritance
        Enchantment(string name, string description, int cost, unique_ptr<Minion> minion);
        virtual int getAttack() override;
        virtual int getDefense() override;
        virtual int getDefaultActions() override;
        virtual int getActivatedAbilityCost() override;
        virtual void notify(TriggerState trigger) override;
};

#endif