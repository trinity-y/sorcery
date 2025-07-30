#ifndef DISENCHANTEFFECT_H
#define DISENCHANTEFFECT_H
#include "gameeffect.h"
#include "../player.h"
using namespace std;
class DisenchantEffect : public GameEffect
{
public:
    // Destroy top enchantment on a minion
    DisenchantEffect(){};
    void useEffect(Player& p, int t) override;
};

#endif

