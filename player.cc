#include "player.h"
#include "./cards/minion.h"
#include "./cards/spell.h"
#include "trigger.h"
using namespace std;

Player::Player(string name, vector<string> deckNames) : name{name}
{
    // Initialize each players deck using deck names
    deck = make_unique<Deck>(deckNames);
    // Remove 5 cards from deck, add to player hand
    hand = make_unique<Hand>();
    for (int i = 0; i < 5; i++)
    {
        // Initialize player hand with cards from deck
        hand->add(deck->pop());
    }
    graveyard = make_unique<Graveyard>();
    board = make_unique<Board>();
}

void Player::shuffleDeck()
{
    deck->shuffle();
}

void Player::addMagic(int additionalMagic)
{
    magic += additionalMagic;
}; // Need to increment magic by 1 in GameState

void Player::subtractMagic(int subtractMagic)
{
    magic -= subtractMagic;
}

bool Player::deckIsEmpty()
{
    return deck->getLen() == 0;
}

int Player::getLife() const
{
    return life;
}

void Player::drawCard()
{
    hand->add(deck->pop());
}

void Player::discardCard(int i)
{
    hand->remove(i);
}

// notifies all cards on board
void Player::notifyCards(TriggerState triggeredAbilityEnum, Player& activePlayer, Player& inactivePlayer)
{
    board->notify(triggeredAbilityEnum, activePlayer, inactivePlayer);
}

void Player::restoreMinions()
{
    for (int i = 0; i < board->getNumMinions(); ++i)
    {
        Minion &minion = board->getMinion(i);
        minion.setActions(minion.getDefaultActions());
    }
}

// ASSUMES 0-INDEXED + acts on minions on the BOARD
const int Player::getMinionAttack(int i) const
{
    return board->getMinion(i).getAttack();
}

const int Player::getMinionDefence(int i) const
{
    return board->getMinion(i).getDefense();
}

void Player::changeMinionAttack(int i, int amount)
{
    board->getMinion(i).changeAttack(amount);
}

// try to attack the minion i from board with attackPower
void Player::changeMinionDefence(int i, int amount)
{
    board->getMinion(i).changeDefense(amount);
}

// notifies an individual minion on the board
// ! rly ugly code but desperate times... tons of repeated code :(
void Player::activateMinionAbility(int i, Player &activePlayer, Player &inactivePlayer)
{
    Minion &minionToActivate = board->getMinion(i);
    int activationCost = minionToActivate.getActivatedAbilityCost();
    if (activationCost <= magic)
    {
        board->getMinion(i).notify(TriggerState::ACTIVATED_ABILITY, activePlayer, inactivePlayer);
        magic -= activationCost;
    }
    // todo: error msg thats like 'you dont have enough magic'
}

void Player::activateMinionAbility(int i, Player &p, int t)
{
    Minion &minionToActivate = board->getMinion(i);
    int activationCost = minionToActivate.getActivatedAbilityCost();
    if (activationCost <= magic)
    {
        board->getMinion(i).notify(TriggerState::ACTIVATED_ABILITY, p, t);
        magic -= activationCost;
    }
    // todo: error msg thats like 'you dont have enough magic'
}

void Player::activateMinionAbility(int i, Player &p, string t)
{
    Minion &minionToActivate = board->getMinion(i);
    int activationCost = minionToActivate.getActivatedAbilityCost();
    if (activationCost <= magic)
    {
        board->getMinion(i).notify(TriggerState::ACTIVATED_ABILITY, p, t);
        magic -= activationCost;
    }
    // todo: error msg thats like 'you dont have enough magic'
}

void Player::reduceLife(int reduceBy)
{
    life -= reduceBy;
}

void Player::playCard(int i, Player &activePlayer, Player &inactivePlayer) // temporary fix
{
    Card &card = hand->getCard(i);
    if (card.type == "MINION" || card.type == "RITUAL")
    {
        board->add(hand->remove(i));
        magic -= card.cost;
        if (card.type == "MINION") {
            // ! board->notify (when minion enters play)
            // NOT GOOD CAUSE WE NEED TO ACCESS BOTH BOARDDS TO SEND NOTIFICATION
        }
    }
    else if (card.type == "SPELL")
    {
        static_cast<Spell &>(card).notify(activePlayer, inactivePlayer);
        hand->remove(i);
    }
}

// get the number of minions in the board
int Player::getNumMinions() const
{
    return board->getNumMinions();
}

void Player::addCardToBoard(unique_ptr<Card> card)
{
    board->add(move(card));
}

Card &Player::getCardFromHand(int i)
{
    return hand->getCard(i);
}

void Player::addEnchantment(Enchantment &enchantment, int minionIndex)
{
    board->addEnchantment(enchantment, minionIndex);
}

void Player::destroyMinion(int i)
{
    board->destroyMinion(i);
}
void Player::destroyRitual()
{
    board->destroyRitual();
}

void Player::returnToHand(int minionIndex)
{
    hand->add(board->removeMinion(minionIndex));
}

void Player::changeRitualCharges(int amount)
{
    board->changeRitualCharges(amount);
}

void Player::disenchantMinion(int i)
{
    // remove top level enchantment of a minion at index i
    board->disenchantMinion(i);
}