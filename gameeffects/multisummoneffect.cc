#include "multisummoneffect.h"
#include "../player.h"
#include "../cards/cardgenerator.h"
#include "../zones/board.h"

MultiSummonEffect::MultiSummonEffect(Player *player, const std::string &elementalType, int maxSummons, int minionsPerSummon)
    : player{player}, elementalType{elementalType}, maxSummons{maxSummons}, minionsPerSummon{minionsPerSummon} {}

void MultiSummonEffect::useEffect()
{
    if (!player || !player->board)
    {
        return;
    }

    int availableSpace = getAvailableBoardSpace();
    if (availableSpace <= 0)
    {
        // No space on board, ability fails
        return;
    }

    // Calculate how many elementals we can actually summon
    int summonsToMake = std::min(maxSummons, availableSpace / minionsPerSummon);

    if (summonsToMake <= 0)
    {
        return;
    }

    // Create and add the elementals to the board
    CardGenerator generator;
    for (int i = 0; i < summonsToMake; ++i)
    {
        auto elemental = generator.getCardFromString(elementalType + " Elemental");
        if (elemental)
        {
            // In a full implementation, add this to the player's board
            // player->board->add(std::move(elemental));
        }
    }
}

int MultiSummonEffect::getAvailableBoardSpace() const
{
    if (!player || !player->board)
    {
        return 0;
    }

    return player->board->getAvailableSpace();
}
