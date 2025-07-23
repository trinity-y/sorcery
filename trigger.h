#ifndef TRIGGER_H
#define TRIGGER_H
#include <string>

using namespace std;
class Trigger {
    public:
        Trigger() {};
        // should pass in some kind of enum that shows what the game state is (e.g beginning of turn, etc)
        virtual void notify(string cmd) = 0;
};
#endif