#ifndef DESTROYMINIONEFFECT_H
#define DESTROYMINIONEFFECT_H
#include "gameeffect.h"

class Minion; // forward declaration

class DestroyMinionEffect : public GameEffect
{
    Minion *target;

public:
    DestroyMinionEffect(Minion *target);
    void useEffect() override;
};

#endif
