#ifndef DESTROYMINIONEFFECT_H
#define DESTROYMINIONEFFECT_H
#include "gameeffect.h"

class Minion; // forward declaration

class DestroyMinionEffect : public GameEffect
{
public:
    DestroyMinionEffect();
    void useEffect(Player& p, int t) override;
};

#endif
