#include "selfbuffeffect.h"
#include "../cards/minion.h"
#include "../player.h"

SelfBuffEffect::SelfBuffEffect(int attackChange, int defenseChange)
    : attackChange{attackChange}, defenseChange{defenseChange} {}

void SelfBuffEffect::useEffect()
{
    // Default useEffect() - this version doesn't have enough context
    // The useEffect(Player &p, int minionIndex) version should be used instead
}

void SelfBuffEffect::useEffect(Player &p)
{
    // This version doesn't know which specific minion to target
    // The useEffect(Player &p, int minionIndex) version is more useful
}

void SelfBuffEffect::useEffect(Player &p, int minionIndex)
{
    // This is the ideal version - buff the specific minion at the given index
    // Get current stats
    int currentAttack = p.getMinionAttack(minionIndex);
    int currentDefense = p.getMinionDefence(minionIndex);

    // Apply buffs
    p.setMinionAttack(minionIndex, currentAttack + attackChange);
    p.setMinionDefence(minionIndex, currentDefense + defenseChange);
}
