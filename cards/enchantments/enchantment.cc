#include "enchantment.h"
using namespace std;

Enchantment::Enchantment(string name, string description, int cost, unique_ptr<Minion> minion):
    Minion{0, 0, name, description, cost} {
        type = "ENCHANTMENT"
    }

// make activated abilities/triggers go inside baseminion, but general minion still has notify.

// override notify if you want to modify an ability 

// override getAttack/getDefense if you want to modify attack/def stats

int Enchantment::getAttack() {
    return nextMinion->getAttack();
}
int Enchantment::getDefense() {
    return nextMinion->getDefense();
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