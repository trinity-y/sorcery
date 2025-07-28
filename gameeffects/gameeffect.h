#ifndef GAMEEFFECT_H
#define GAMEEFFECT_H
#include <string>

using namespace std;

class Player; // forward declaration

class GameEffect
{
public:
    GameEffect();
    virtual ~GameEffect() = 0;
    // Include optional error implementation here:
    virtual void useEffect(Player &p, string t) {}
    virtual void useEffect(Player &p, int t) {}
    virtual void useEffect(Player &p) {}
    virtual void useEffect() {}
};
#endif