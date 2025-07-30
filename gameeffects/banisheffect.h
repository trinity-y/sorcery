#ifndef BANISHEFFECT_H
#define BANISHEFFECT_H
#include "gameeffect.h"
#include <memory>

class Minion; // forward declaration

class BanishEffect : public GameEffect
{
// Destroy target minion or ritual
public:
    BanishEffect(){};
    void useEffect(Player &p, int t) override;
    void useEffect(Player &p, string t) override;
};

#endif
