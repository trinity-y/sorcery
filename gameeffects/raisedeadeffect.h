#ifndef RAISEDEADEFFECT_H
#define RAISEDEADEFFECT_H
#include "gameeffect.h"

class RaiseDeadEffect : public GameEffect
{
public:
    // resurrects the top minion in your graveyard and set it's defense to 1
    // cannot be played if there are no minions in the graveyard
    RaiseDeadEffect();
    void useEffect(Player &activePlayer, Player &inactivePlayer) override;
};
#endif
