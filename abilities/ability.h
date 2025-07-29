#ifndef ABILITY_H
#define ABILITY_H
#include <string>
#include <memory>

#include "../trigger.h"
#include "../gameeffects/gameeffect.h"
using namespace std;
class Ability : public Trigger
{
protected:
    string description;
    unique_ptr<GameEffect> gameEffect;

public:
    Ability(string description, TriggerState trigger, unique_ptr<GameEffect> effect); // need to work on GameEffect implementation -- when is created?
    // void executeTrigger() override;
    void executeTrigger(Player& activePlayer, Player& inactivePlayer) override;
    void executeTrigger(Player& p, int i) override;
    void executeTrigger(Player& p, string t) override;
    void setGameEffect(unique_ptr<GameEffect> effect);
    // whoever makes the card would know what game effect goes in it, but also since this OWNS the card it makes the most sense to make it here
    // but it also doesn't make sense to make it herer, since we will need to use gameffect elsewhere
    // do we need another 'factory' thing?
    // after talking w robyn -- create game effect in card generator
};
#endif