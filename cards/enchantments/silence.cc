#include "silence.h"
using namespace std;

Silence::Silence(unique_ptr<Minion> nextMinion): Enchantment("Silence", "Enchanted minion cannot use abilities" , 1, move(nextMinion)) {};

// do nothing, so we will not end up notifying BaseMinion and the ability will not be triggered
void Silence::notify(TriggerState trigger) {}; 
void Silence::notify(TriggerState trigger, Player& p) {};
void Silence::notify(TriggerState trigger, Player& p, string t) {};
void Silence::notify(TriggerState trigger, Player& p, int t) {};