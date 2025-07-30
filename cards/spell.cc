#include "spell.h"
#include <string>
using namespace std;

Spell::Spell(string name, string description, int cost, unique_ptr<GameEffect> gameEffect) : Card{"SPELL", name, description, cost}, gameEffect{move(gameEffect)} {};

// void Spell::notify() {
//     gameEffect->useEffect();
// }

void Spell::notify(Player &activePlayer, Player &inactivePlayer)
{
    gameEffect->useEffect(activePlayer, inactivePlayer);
}

void Spell::notify(Player &p, int t) const
{
    gameEffect->useEffect(p, t);
}

void Spell::notify(Player &p, string t) const
{
    gameEffect->useEffect(p, t);
}

string Spell::getLeftBox() const
{
    return "";
}

string Spell::getRightBox() const
{
    return "";
}
