#include "gainmagiceffect.h"
#include "../player.h"

GainMagicEffect::GainMagicEffect(Player *player, int magicAmount)
    : player{player}, magicAmount{magicAmount} {}

void GainMagicEffect::useEffect()
{
    if (player)
    {
        // In a full implementation, you'd add magic/mana to the player
        // player->gainMagic(magicAmount);
        // For now, this is a placeholder
    }
}
