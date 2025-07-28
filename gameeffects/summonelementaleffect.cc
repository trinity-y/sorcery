#include "summonelementaleffect.h"
#include "../player.h"
#include "../cards/cardgenerator.h"

SummonElementalEffect::SummonElementalEffect(string elementalType): elementalType{elementalType} {}

void SummonElementalEffect::useEffect(Player& player) {
    // Create the specified elemental and add it to the player's board
    CardGenerator generator;
    for (int i=0; i<(player.board.get()))
    auto elemental = generator.getCardFromString(elementalType + " Elemental");
    if (elemental)
    {
        // In a full implementation, you'd add this to the player's board
        // player->board->add(move(elemental));
    }
}
