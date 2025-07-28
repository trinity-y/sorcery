#ifndef TARGETEDDAMAGEEFFECT_H
#define TARGETEDDAMAGEEFFECT_H
#include "gameeffect.h"

class Minion; // forward declaration

class TargetedDamageEffect : public GameEffect
{
    int damage;
    Minion *target; // will be set when ability is activated

public:
    TargetedDamageEffect(int damage);
    void setTarget(Minion *newTarget);
    void useEffect() override;
};

#endif
