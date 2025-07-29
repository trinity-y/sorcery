#include "cardgenerator.h"
#include "minion.h"
#include "../abilities/activatedability.h"
#include "../abilities/triggeredability.h"
#include "../gameeffects/minionchangestatseffect.h"
#include "../gameeffects/damageminioneffect.h"
#include "../gameeffects/allminionsstatseffect.h"
#include "../gameeffects/targeteddamageeffect.h"
#include "../gameeffects/multisummoneffect.h"
#include "../gameeffects/selfbuffeffect.h"
#include "../trigger.h"
CardGenerator::CardGenerator() {}
unique_ptr<Card> CardGenerator::getCardFromString(string cardName)
{
    // minions
    // Minion(int attack, int defense, string name, string description, int cost, activatedAbility, triggeredAbility)
    if (cardName == "Air Elemental")
    {
        return make_unique<Minion>(1, 1, "Air Elemental", "", 0, nullptr, nullptr);
    }
    else if (cardName == "Earth Elemental")
    {
        return make_unique<Minion>(4, 4, "Earth Elemental", "", 3, nullptr, nullptr);
    }
    else if (cardName == "Bone Golem")
    {
        // Create a triggered ability that triggers when minions leave play
        auto triggeredAbility = make_unique<TriggeredAbility>(
            "Gain +1/+1 whenever a minion leaves play.",
            Trigger::TriggerState::MINION_LEAVES);

        // Create the minion first
        auto boneGolem = make_unique<Minion>(1, 3, "Bone Golem", "Gain +1/+1 whenever a minion leaves play.", 2, nullptr, move(triggeredAbility));

        // Create a self-buff effect that doesn't store any pointers
        auto selfBuffEffect = make_unique<SelfBuffEffect>(1, 1); // +1/+1 buff

        // Set the game effect for the triggered ability
        boneGolem->getTriggeredAbility().setGameEffect(move(selfBuffEffect));

        return move(boneGolem);
    }
    else if (cardName == "Fire Elemental")
    {
        // Create a triggered ability that triggers when a minion enters play
        auto triggeredAbility = make_unique<TriggeredAbility>(
            "Whenever an opponent's minion enters play, deal 1 damage to it.",
            Trigger::TriggerState::MINION_ENTERS);

        // Create the minion first
        auto fireElemental = make_unique<Minion>(2, 2, "Fire Elemental", "Whenever an opponent's minion enters play, deal 1 damage to it.", 2, nullptr, move(triggeredAbility));

        // Note: The damage effect setup is more complex since we need to know which opponent's minion entered
        // placeholder for now
        auto damageEffect = make_unique<DamageMinionEffect>(nullptr, 1); // target will be set when trigger fires

        // Set the game effect for the triggered ability
        fireElemental->getTriggeredAbility().setGameEffect(move(damageEffect));
        return move(fireElemental);
    }
    else if (cardName == "Potion Seller")
    {
        // Create a triggered ability that triggers at the end of turn
        auto triggeredAbility = make_unique<TriggeredAbility>(
            "At the end of your turn, all your minions gain +0/+1.",
            Trigger::TriggerState::END_OF_TURN);

        // Create the minion first
        auto potionSeller = make_unique<Minion>(1, 3, "Potion Seller", "At the end of your turn, all your minions gain +0/+1.", 2, nullptr, move(triggeredAbility));

        // Create the effect that buffs all minions with +0/+1
        // need to pass the owner player - use nullptr as a placeholder
        auto allMinionsEffect = make_unique<AllMinionsStatsEffect>(nullptr, 0, 1); // +0/+1 to all minions

        // Set the game effect for the triggered ability
        potionSeller->getTriggeredAbility().setGameEffect(move(allMinionsEffect));

        return move(potionSeller);
    }
    else if (cardName == "Novice Pyromancer")
    {
        // Create an activated ability (player-initiated)
        // Note: Magic cost of 1 for the ability is not yet implemented in the current system
        auto activatedAbility = make_unique<ActivatedAbility>(
            "Deal 1 damage to target minion.");

        // Create the minion first (0 attack, 1 defense, card cost 1)
        auto novicePyromancer = make_unique<Minion>(0, 1, "Novice Pyromancer", "Deal 1 damage to target minion.", 1, move(activatedAbility), nullptr);

        // Create the targeted damage effect
        // For activated abilities, the target is chosen when the ability is used
        auto targetedDamageEffect = make_unique<TargetedDamageEffect>(1); // 1 damage

        // Set the game effect for the activated ability
        novicePyromancer->getActivatedAbility().setGameEffect(move(targetedDamageEffect));

        return move(novicePyromancer);
    }
    else if (cardName == "Apprentice Summoner")
    {
        // Create an activated ability that summons a 1/1 Air Elemental
        // Note: Magic cost of 1 for the ability is not yet implemented in the current system
        auto activatedAbility = make_unique<ActivatedAbility>(
            "Summon a 1/1 Air Elemental.");

        // Create the minion first (1 attack, 1 defense, card cost 1)
        auto apprenticeSummoner = make_unique<Minion>(1, 1, "Apprentice Summoner", "Summon a 1/1 Air Elemental.", 1, move(activatedAbility), nullptr);

        // Create the summon effect - can summon 1 elemental if there's board space
        auto summonEffect = make_unique<MultiSummonEffect>("Air", 1); // max 1 summon

        // Set the game effect for the activated ability
        apprenticeSummoner->getActivatedAbility().setGameEffect(move(summonEffect));

        return move(apprenticeSummoner);
    }
    else if (cardName == "Master Summoner")
    {
        // Create an activated ability that summons up to three 1/1 Air Elementals
        // Note: Magic cost of 2 for the ability is not yet implemented in the current system
        auto activatedAbility = make_unique<ActivatedAbility>(
            "Summon up to three 1/1 air elementals.");

        // Create the minion first (2 attack, 3 defense, card cost 3)
        auto masterSummoner = make_unique<Minion>(2, 3, "Master Summoner", "Summon up to three 1/1 air elementals.", 3, move(activatedAbility), nullptr);

        // Create the multi-summon effect - can summon up to 3 elementals based on available board space
        auto summonEffect = make_unique<MultiSummonEffect>("Air", 3); // max 3 summons

        // Set the game effect for the activated ability
        masterSummoner->getActivatedAbility().setGameEffect(move(summonEffect));

        return move(masterSummoner);
    }
    return nullptr;
}