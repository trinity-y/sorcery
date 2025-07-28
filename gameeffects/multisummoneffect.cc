#include "multisummoneffect.h"
#include "../player.h"
#include "../cards/cardgenerator.h"
#include "../zones/board.h"
using namespace std;
MultiSummonEffect::MultiSummonEffect(const string elementalType, int maxSummons, int minionsPerSummon)
    : elementalType{elementalType}, maxSummons{maxSummons}, minionsPerSummon{minionsPerSummon} {}

void MultiSummonEffect::useEffect(Player& p)
{
    int availableSpace = 5 - p.getNumMinions();

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
            p.addCardToBoard(move(elemental)); // add generated card to board
        }
    }
}
