#include "cardgenerator.h"
#include "minion.h"
CardGenerator::CardGenerator() {}
unique_ptr<Card> CardGenerator::getCardFromString(string cardName) {
    // minions
    // Minion(int attack, int defense, string name, string description, int cost, activatedAbility, triggeredAbility)
    if (cardName == "Air Elemental") {
        return make_unique<Minion>(1, 1, "Air Elemental", "", 0, nullptr, nullptr);
    } else if (cardName == "Earth Elemental") {
        return make_unique<Minion>(4, 4, "Earth Elemental", "", 3, nullptr, nullptr);
    }
    //  else if (cardName == "Bone Golem") {

    // } else if (cardName == "Fire Elemental") {

    // } else if (cardName == "Potion Seller") {

    // } else if (cardName == "Potion Seller") {

    // } else if (cardName == "Novice Pyromancer") {

    // } else if (cardName == "Apprentice Summoner") {

    // } else if (cardName == "Master Summoner") {

    // }
    return nullptr;
}