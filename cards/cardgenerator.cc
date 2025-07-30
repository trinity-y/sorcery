#include "cardgenerator.h"
#include "baseminion.h"
#include "../abilities/activatedability.h"
#include "../abilities/triggeredability.h"
#include "../gameeffects/minionchangestatseffect.h"
#include "../gameeffects/damageminioneffect.h"
#include "../gameeffects/allminionsstatseffect.h"
#include "../gameeffects/targeteddamageeffect.h"
#include "../gameeffects/multisummoneffect.h"
#include "../gameeffects/banisheffect.h"
#include "../gameeffects/unsummoneffect.h"
#include "../gameeffects/rechargeeffect.h"
#include "../gameeffects/disenchanteffect.h"
#include "../gameeffects/raisedeadeffect.h"
#include "../gameeffects/blizzardeffect.h"
#include "../gameeffects/selfbuffeffect.h"
#include "../gameeffects/gainmagiceffect.h"
#include "../gameeffects/destroyminioneffect.h"
#include "../gameeffects/ownerminionbuffeffect.h"
#include "./enchantments/giantstrength.h"
#include "./enchantments/enrage.h"
#include "./enchantments/haste.h"
#include "./enchantments/magicfatigue.h"
#include "./enchantments/silence.h"

#include "../trigger.h"
#include "spell.h"
#include "enchantment.h"

#include <iostream> // ! debug
using namespace std;

CardGenerator::CardGenerator() {}
unique_ptr<Card> CardGenerator::getCardFromString(string cardName)
{
    // minions
    // Minion(int attack, int defense, string name, string description, int cost, activatedAbility, triggeredAbility)
    if (cardName == "Air Elemental")
    {
        return make_unique<BaseMinion>(1, 1, "Air Elemental", "", 0, nullptr, nullptr);
    }
    else if (cardName == "Earth Elemental")
    {
        return make_unique<BaseMinion>(4, 4, "Earth Elemental", "", 3, nullptr, nullptr);
    }
    else if (cardName == "Bone Golem")
    {
        // Create a self-buff effect that doesn't store any pointers
        auto selfBuffEffect = make_unique<SelfBuffEffect>(1, 1); // +1/+1 buff

        // Create a triggered ability that triggers when minions leave play
        auto triggeredAbility = make_unique<TriggeredAbility>(
            "Gain +1/+1 whenever a minion leaves play.",
            TriggerState::MINION_LEAVES,
            move(selfBuffEffect));

        // Create the minion
        auto boneGolem = make_unique<BaseMinion>(1, 3, "Bone Golem", "Gain +1/+1 whenever a minion leaves play.", 2, nullptr, move(triggeredAbility));

        return move(boneGolem);
    }
    else if (cardName == "Fire Elemental")
    {
        auto damageEffect = make_unique<DamageMinionEffect>(1); // target will be set when trigger fires

        // Create a triggered ability that triggers when a minion enters play
        auto triggeredAbility = make_unique<TriggeredAbility>(
            "Whenever an opponent's minion enters play, deal 1 damage to it.",
            TriggerState::MINION_ENTERS,
            move(damageEffect));

        // Create the minion first
        auto fireElemental = make_unique<BaseMinion>(2, 2, "Fire Elemental", "Whenever an opponent's minion enters play, deal 1 damage to it.", 2, nullptr, move(triggeredAbility));

        return move(fireElemental);
    }
    else if (cardName == "Potion Seller")
    {
        // Create the effect that buffs all minions with +0/+1
        auto allMinionsEffect = make_unique<AllMinionsStatsEffect>(0, 1); // +0/+1 to all minions

        // Create a triggered ability that triggers at the end of turn
        auto triggeredAbility = make_unique<TriggeredAbility>(
            "At the end of your turn, all your minions gain +0/+1.",
            TriggerState::END_OF_TURN,
            move(allMinionsEffect));

        // Create the minion first
        auto potionSeller = make_unique<BaseMinion>(1, 3, "Potion Seller", "At the end of your turn, all your minions gain +0/+1.", 2, nullptr, move(triggeredAbility));

        return move(potionSeller);
    }
    else if (cardName == "Novice Pyromancer")
    {
        // Create the targeted damage effect
        // For activated abilities, the target is chosen when the ability is used
        auto targetedDamageEffect = make_unique<TargetedDamageEffect>(1); // 1 damage

        // Create an activated ability (player-initiated)
        auto activatedAbility = make_unique<ActivatedAbility>(
            "Deal 1 damage to target minion.",
            move(targetedDamageEffect)); // Magic cost of 1

        // Create the minion first (0 attack, 1 defense, card cost 1)
        auto novicePyromancer = make_unique<BaseMinion>(0, 1, "Novice Pyromancer", "Deal 1 damage to target minion.", 1, move(activatedAbility), nullptr);

        return move(novicePyromancer);
    }
    else if (cardName == "Apprentice Summoner")
    {
        // Create the summon effect - can summon 1 elemental if there's board space
        auto summonEffect = make_unique<MultiSummonEffect>("Air", 1); // max 1 summon

        // Create an activated ability that summons a 1/1 Air Elemental
        auto activatedAbility = make_unique<ActivatedAbility>(
            "Summon a 1/1 Air Elemental.",
            move(summonEffect)); // Magic cost of 1

        // Create the minion first (1 attack, 1 defense, card cost 1)
        auto apprenticeSummoner = make_unique<BaseMinion>(1, 1, "Apprentice Summoner", "Summon a 1/1 Air Elemental.", 1, move(activatedAbility), nullptr);

        return move(apprenticeSummoner);
    }
    else if (cardName == "Master Summoner")
    {
        // Create the multi-summon effect - can summon up to 3 elementals based on available board space
        auto summonEffect = make_unique<MultiSummonEffect>("Air", 3); // max 3 summons

        // Create an activated ability that summons up to three 1/1 Air Elementals
        auto activatedAbility = make_unique<ActivatedAbility>(
            "Summon up to three 1/1 air elementals.",
            move(summonEffect)); // Magic cost of 2

        // Create the minion first (2 attack, 3 defense, card cost 3)
        auto masterSummoner = make_unique<BaseMinion>(2, 3, "Master Summoner", "Summon up to three 1/1 air elementals.", 3, move(activatedAbility), nullptr);

        return move(masterSummoner);
    }
    // Spells
    else if (cardName == "Banish")
    {
        return make_unique<Spell>("Banish", "Destroy target minion or ritual.", 2, make_unique<BanishEffect>());
    }
    else if (cardName == "Unsummon")
    {
        return make_unique<Spell>("Unsummon", "Return target minion to its owner's hand.", 1, make_unique<UnsummonEffect>());
    }
    else if (cardName == "Recharge")
    {
        return make_unique<Spell>("Recharge", "Your ritual gains 3 charges.", 1, make_unique<RechargeEffect>());
    }
    else if (cardName == "Disenchant")
    {
        return make_unique<Spell>("Disenchant", "Destroy the top enchantment on target minion.", 1, make_unique<DisenchantEffect>());
    }
    else if (cardName == "Raise Dead")
    {
        return make_unique<Spell>("Raise Dead", "Resurrect the top minion in your graveyard with 1 defense.", 2, make_unique<RaiseDeadEffect>());
    }
    else if (cardName == "Blizzard")
    {
        return make_unique<Spell>("Blizzard", "Deal 2 damage to all minions.", 3, make_unique<BlizzardEffect>());
    }

    // Enchantments
    else if (cardName == "Giant Strength")
    {
        // StrengthEnchanter should add +2 ATK, +2 DEF
        return make_unique<Enchantment>(make_unique<GiantStrength>(2, 2));
    }
    else if (cardName == "Magic Fatigue")
    {
        // FatigueEnchanter increases activated ability cost by 2
        return make_unique<Enchantment>(make_unique<MagicFatigue>(2));
    }
    else if (cardName == "Silence")
    {
        // SilenceEnchanter disables all abilities
        return make_unique<Enchantment>(make_unique<Silence>());
    }
    else if (cardName == "Enrage")
    {
        // multiples *2 ATK, *2 DEF
        return make_unique<Enchantment>(make_unique<Enrage>(2, 2));
    }
    else if (cardName == "Haste")
    {
        // + 1 action per turn
        return make_unique<Enchantment>(make_unique<Haste>(1));
    }

    // Rituals
    else if (cardName == "Dark Ritual")
    {
        auto gainMana = make_unique<GainMagicEffect>(1);
        auto trigger = make_unique<TriggeredAbility>("Gain 1 mana at the start of your turn.", TriggerState::START_OF_TURN, move(gainMana));
        return make_unique<Ritual>("Dark Ritual", "Gain 1 mana at the start of your turn.", 0, move(trigger), 5);
    }
    else if (cardName == "Aura of Power")
    {
        auto statBuff = make_unique<OwnerMinionBuffEffect>(1, 1);
        auto trigger = make_unique<TriggeredAbility>("Whenever a minion enters play under your control, it gains +1/+1.", TriggerState::MINION_ENTERS, move(statBuff));
        return make_unique<Ritual>("Aura of Power", "Your minions get +1/+1 when they enter play.", 1, move(trigger), 4);
    }
    else if (cardName == "Standstill")
    {
        auto destroyEffect = make_unique<DestroyMinionEffect>();
        auto trigger = make_unique<TriggeredAbility>("Whenever a minion enters play, destroy it.", TriggerState::MINION_ENTERS, move(destroyEffect));
        return make_unique<Ritual>("Standstill", "Destroy any minion that enters play.", 3, move(trigger), 4);
    }

    return nullptr;
}
