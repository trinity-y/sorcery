#include "enchantment.h"
using namespace std;

Enchantment::Enchantment(string name, string description, int cost, unique_ptr<Minion> minion):
    Minion{name, description, cost}, nextMinion{move(minion)} {
        type = "ENCHANTMENT";
    }

// make activated abilities/triggers go inside baseminion, but general minion still has notify.
// todo: refactor card generator
// override notify if you want to modify an ability 

// override getAttack/getDefense if you want to modify attack/def stats
Enchantment::~Enchantment() {};

int Enchantment::decrementActions() {
    return nextMinion->decrementActions();
}

int Enchantment::getAttack() {
    return nextMinion->getAttack();
}
int Enchantment::getDefense() {
    return nextMinion->getDefense();
}

void Enchantment::changeAttack(int amount) {
    nextMinion->changeAttack(amount);
}

void Enchantment::changeDefense(int amount) {
    nextMinion->changeDefense(amount);
}

string Enchantment::getLeftBox() {
    return ""; // default no box
}

string Enchantment::getRightBox() {
    return ""; // default no box
}

int Enchantment::getDefaultActions() {
    return nextMinion->getDefaultActions();
}
int Enchantment::getActivatedAbilityCost() {
    return nextMinion->getActivatedAbilityCost();
}
void Enchantment::notify(TriggerState trigger) {
    nextMinion->notify(trigger);
}

void Enchantment::notify(TriggerState trigger, Player& p) {
    nextMinion->notify(trigger, p);
}

void Enchantment::notify(TriggerState trigger, Player& p, int t) {
    nextMinion->notify(trigger, p, t);
}

void Enchantment::notify(TriggerState trigger, Player& p, string t) {
    nextMinion->notify(trigger, p, t);
}
