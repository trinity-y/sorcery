#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H
#include "../minion.h"

using namespace std;
class Enchantment : public Minion {
    protected:
        unique_ptr<Minion> nextMinion; // next minion in the decorator chain
    public:
        Enchantment(string name, string description, int cost, unique_ptr<Minion> minion);
        virtual ~Enchantment() = 0;
        virtual int decrementActions() override;
        virtual int getAttack() override;
        virtual int getDefense() override;
        virtual void changeAttack(int amount) override;
        virtual void changeDefense(int amount) override;
        virtual string getLeftBox() override;
        virtual string getRightBox() override;
        virtual int getDefaultActions() override;
        virtual int getActivatedAbilityCost() override;
        virtual void notify(TriggerState trigger) override;
        virtual int getActivatedAbilityCost() override;
};

#endif
