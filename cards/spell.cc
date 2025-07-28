#include "spell.h"
#include <string>
using namespace std;

Spell::Spell(string name, string description, int cost, unique_ptr<GameEffect> gameEffect): Card{"SPELL", name, description, cost}, gameEffect{move(gameEffect)} {};

void Spell::notify() {
    gameEffect->useEffect();
}
