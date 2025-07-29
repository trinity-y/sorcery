#include "silence.h"
using namespace std;

Silence::Silence(unique_ptr<Minion> nextMinion): Enchantment("Silence", "Enchanted minion cannot use abilities" , 1, move(nextMinion)) {};

void Silence::notify(TriggerState trigger) {}; // do nothing, so we will not end up notifying BaseMinion and the ability will not be triggered