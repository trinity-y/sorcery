#ifndef GAMEEFFECT_H
#define GAMEEFFECT_H
#include <string>
// #include "../player.h"

using namespace std;

class Player; // Forward declaration

class GameEffect
{
public:
    GameEffect();
    virtual ~GameEffect() = 0;
    virtual void useEffect(Player &activePlayer, Player &inactivePlayer) {};
    virtual void useEffect(Player &p, string t) {};
    virtual void useEffect(Player &p, int t) {};
    // virtual void useEffect(Player &p) {};
    // virtual void useEffect(Player &p) {};
    // virtual void useEffect() {};
};
#endif