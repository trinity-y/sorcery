#include "gainmagiceffect.h"
#include "../player.h"

GainMagicEffect::GainMagicEffect(int magicAmount)
    : magicAmount{magicAmount} {};

void GainMagicEffect::useEffect(Player& activePlayer, Player& inactivePlayer)
{
    activePlayer.addMagic(magicAmount);
}

