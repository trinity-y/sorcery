#ifndef SPELL_H
#define SPELL_H
#include "card.h"
#include "../gameeffects/gameeffect.h"
#include <memory>

class Spell : public Card
{
public:
    unique_ptr<GameEffect> gameEffect;
    Spell(string name, string description, int cost, unique_ptr<GameEffect> gameEffect);
    // void notify();
    // void notify(Player &p);
    void notify(Player &activePlayer, Player &inactivePlayer);
    void notify(Player &p, int t);
    void notify(Player &p, string t);
};

#endif