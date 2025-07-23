#ifndef TRIGGER_H
#define TRIGGER_H
#include <string>

using namespace std;
class Trigger {
    public:
        enum TriggerState {
            START_OF_TURN,
            END_OF_TURN,
            MINION_ENTERS,
            MINION_LEAVES,
            ACTIVATED_ABILITY
        };
        TriggerState trigger;
        Trigger(TriggerState trigger);
        // should pass in some kind of enum that shows what the game state is (e.g beginning of turn, etc)
        // does notify necessarily need to be virtual? can i use observer+template, ntoify is concrete and calls the virtual trigger  effect based on triggerstate?
        virtual void notify(TriggerState newState);
        virtual void executeTrigger() = 0;
};

#endif
