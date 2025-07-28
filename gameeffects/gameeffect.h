#ifndef GAMEEFFECT_H
#define GAMEEFFECT_H
#include <string>

using namespace std;
class GameEffect {
    public:
        GameEffect();
        virtual ~GameEffect() = 0;
        virtual void useEffect(Player&p, string t) {};
        virtual void useEffect(Player&p, int t) {};
        virtual void useEffect(Player&p) {};
        virtual void useEffect() {};


};
#endif