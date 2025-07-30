#ifndef SILENCE_H
#define SILENCE_H
#include "enchanter.h"
#include <string>
using namespace std;

class Silence : public Enchanter
{
public:
    Silence(unique_ptr<Minion> nextMinion);
    // void notify(TriggerState trigger) override;
    void notify(TriggerState trigger, Player &activePlayer, Player &inactivePlayer) override;
    void notify(TriggerState trigger, Player &p, string t) override;
    void notify(TriggerState trigger, Player &p, int t) override;
};

#endif