#include "player.h"
#include "./cards/minion.h"
#include "./cards/spell.h"
#include "trigger.h"
#include <iostream> // todo: remove
using namespace std;

Player::Player(string name, vector<string> deckNames) : name{name}
{
    // Initialize each players deck using deck names
    deck = make_unique<Deck>(deckNames);
    deck->shuffle();
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
    if (hand->getHandLen() < 5)
    {
        hand->add(deck->pop());
    }
    // ! debug
    // cout << "drew card. now hand =" << endl;
    // for (int i = 0; i < hand->getHandLen(); i++)
    // {
    //     cout << hand->getCard(i).name << " ";
    // }
    // cout << endl;
}

void Player::discardCard(int i)
{
    hand->remove(i);
}

// notifies all cards on board
void Player::notifyCards(TriggerState triggeredAbilityEnum, Player &activePlayer, Player &inactivePlayer)
{
    board->notify(triggeredAbilityEnum, activePlayer, inactivePlayer);
}

void Player::restoreMinions()
{
    // debug
    cerr << "got to restoreMinions" << endl;
    for (int i = 0; i < board->getNumMinions(); ++i)
    {
        Minion &minion = board->getMinion(i);
        cout << minion.getDefaultActions() << endl;
        minion.setActions(minion.getDefaultActions());
        cout << "getactions: " << minion.getActions() << endl;
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
    else
    {
        cout << "You don't have enough magic for that!" << endl;
    }
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
    else
    {
        cout << "You don't have enough magic for that!" << endl;
    }
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
    else
    {
        cout << "You don't have enough magic for that!" << endl;
    }
}

void Player::reduceLife(int reduceBy)
{
    life -= reduceBy;
}
void Player::notify(TriggerState trigger, Player &activePlayer, Player &inactivePlayer)
{
    board->notify(trigger, activePlayer, inactivePlayer);
}
void Player::notify(TriggerState trigger, Player &activePlayer, int t)
{
    board->notify(trigger, activePlayer, t);
}
void Player::playCard(int i, Player &activePlayer, Player &inactivePlayer) // temporary fix
{
    Card &card = hand->getCard(i);
    magic -= card.cost;
    if (card.type == "MINION" || card.type == "RITUAL")
    {
        // ! debug
        board->add(hand->remove(i));
        cout << "Added minion, board size now: " << board->getNumMinions() << endl;
        if (card.type == "MINION")
        {
            // ! board->notify (when minion enters play)
            // we need to notify both players boards. so ideally this logic is moved outside
            cout << "board length = " << board->getNumMinions() << endl;
            int t = board->getNumMinions() - 1;
            cout << "notifying" << endl;
            notify(MINION_ENTERS, activePlayer, t);
            inactivePlayer.notify(MINION_ENTERS, activePlayer, t);
            cout << "finished notifying" << endl;
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
    // ! debug
    cout << "DEBUG: trying to add enchantment inside player class" << endl;
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

unique_ptr<Card> Player::removeFromGraveyard()
{
    return graveyard->removeLastMinion(); // Need to implement in Graveyard class
}

int Player::getNumMinionsInGraveyard() const
{
    return graveyard->getNumMinions();
}

void Player::moveToGraveyard(int minionIndex)
{
    // Remove minion from board and add to graveyard
    auto minion = board->removeMinion(minionIndex);
    graveyard->add(std::move(minion));
}

void Player::decrementMinionActions(int i)
{
    board->decrementMinionActions(i);
}
const int Player::getMinionActions(int i) const
{
    return board->getMinionActions(i);
}
