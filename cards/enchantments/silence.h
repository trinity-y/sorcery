#ifndef SILENCE_H
#define SILENCE_H
#include "enchantment.h"
#include <string>
using namespace std;

class Silence : public Enchantment {
    public:
        Silence(unique_ptr<Minion> nextMinion);
        void notify(TriggerState trigger) override;
        void notify(TriggerState trigger, Player& p) override;
        void notify(TriggerState trigger, Player& p, string t) override;
        void notify(TriggerState trigger, Player& p, int t) override;
};

#endif