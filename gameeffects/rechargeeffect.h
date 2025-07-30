#ifndef RECHARGEEFFECT_H
#define RECHARGEEFFECT_H
#include "gameeffect.h"
using namespace std;
class RechargeEffect : public GameEffect
{
public:
    // Your ritual gains 3 charges
    RechargeEffect(){};
    // void useEffect(Player& p) override;
    void useEffect(Player& activePlayer, Player& inactivePlayer) override;
};

#endif

