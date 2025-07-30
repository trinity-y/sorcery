#include "raisedeadeffect.h"
#include "../player.h"

RaiseDeadEffect::RaiseDeadEffect() {}

void RaiseDeadEffect::useEffect(Player &activePlayer, Player &inactivePlayer)
{
    // Check if there are any minions in the graveyard
    if (activePlayer.getNumMinionsInGraveyard() > 0)
    {
        //
    }
}