#ifndef MULTISUMMONEFFECT_H
#define MULTISUMMONEFFECT_H
#include "gameeffect.h"
#include <string>

class Player; // forward declaration
using namespace std;
class MultiSummonEffect : public GameEffect
{
    const string elementalType;
    int maxSummons;
    int minionsPerSummon; // typically 1, but could be different

public:
    MultiSummonEffect(const string elementalType, int maxSummons, int minionsPerSummon = 1);
    void useEffect(Player& p) override;
};

#endif
