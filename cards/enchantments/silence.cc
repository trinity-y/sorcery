#include "silence.h"
using namespace std;

Silence::Silence() : Enchanter("Silence", "Enchanted minion cannot use abilities", 1) {};

// do nothing, so we will not end up notifying BaseMinion and the ability will not be triggered
void Silence::notify(TriggerState trigger, Player &activePlayer, Player &inactivePlayer) {};
void Silence::notify(TriggerState trigger, Player &p, string t) {};
void Silence::notify(TriggerState trigger, Player &p, int t) {};
// void Silence::notify(TriggerState trigger) {};