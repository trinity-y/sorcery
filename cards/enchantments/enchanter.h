#ifndef ENCHANTER_H
#define ENCHANTER_H
#include "../minion.h"
#include <memory>
using namespace std;
class Enchanter : public Minion
{
protected:
public:
    unique_ptr<Minion> nextMinion; // next minion in the decorator chain
    Enchanter(string name, string description, int cost);
    virtual ~Enchanter() = 0;
    virtual int decrementActions() override;
    virtual int getAttack() const override;
    virtual int getDefense() const override;
    virtual const int getActions() const override;
    virtual void changeAttack(int amount) override;
    virtual void changeDefense(int amount) override;
    virtual string getLeftBox() const override;
    virtual string getRightBox() const override;
    virtual int getDefaultActions() const override;
    virtual void setActions(int newActions) override;
    virtual int getActivatedAbilityCost() const override;
    // virtual void notify(TriggerState trigger) override;
    virtual void notify(TriggerState trigger, Player &activePlayer, Player &inactivePlayer) override;
    virtual void notify(TriggerState trigger, Player &p, int t) override;
    virtual void notify(TriggerState trigger, Player &p, string t) override;
    void setNextMinion(unique_ptr<Minion> newNextMinion);
    virtual int getCost() const override;

    // for disenchant effect
    virtual unique_ptr<Minion> disenchantMinion();
    virtual string getMinionName() const override;
    virtual string getMinionDescription() const override;
};

#endif

