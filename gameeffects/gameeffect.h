#ifndef GAMEEFFECT_H
#define GAMEEFFECT_H
#include <string>

using namespace std;
class GameEffect {
    public:
        GameEffect();
        virtual void useEffect() = 0;
};
#endif