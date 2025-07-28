#ifndef SPELL_H
#define SPELL_H
#include "card.h"
#include "../gameeffects/gameeffect.h"
#include <memory>

class Spell : public Card {
    unique_ptr<GameEffect> gameEffect;
    public:
        Spell(string name, string description, int cost, unique_ptr<GameEffect> gameEffect);
        void notify();
};

#endif