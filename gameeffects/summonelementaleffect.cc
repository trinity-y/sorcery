#include "summonelementaleffect.h"
#include "../player.h"
#include "../cards/cardgenerator.h"

SummonElementalEffect::SummonElementalEffect(Player *player, string elementalType)
    : player{player}, elementalType{elementalType} {}

void SummonElementalEffect::useEffect()
{
    if (player)
    {
        // Create the specified elemental and add it to the player's board
        CardGenerator generator;
        auto elemental = generator.getCardFromString(elementalType + " Elemental");
        if (elemental)
        {
            // In a full implementation, you'd add this to the player's board
            // player->board->add(move(elemental));
        }
    }
}
