#include "rechargeeffect.h"
#include "../player.h"

void RechargeEffect::useEffect(Player &activePlayer, Player &inactivePlayer)
{
    // Your ritual gains 3 charges
    activePlayer.changeRitualCharges(3);
}
