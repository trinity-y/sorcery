#include "player.h"
#include "./cards/minion.h"
#include "./cards/spell.h"
#include "trigger.h"
Player::Player(string name, vector<string> deckNames) : name{name}{
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

Player::~Player() {}; // temp    

void Player::shuffleDeck() {
    deck->shuffle();
}

void Player::addMagic(int additionalMagic) {
    magic += additionalMagic;
}; // Need to increment magic by 1 in GameState

void Player::subtractMagic(int subtractMagic) {
    magic -= subtractMagic;
}

bool Player::deckIsEmpty() {
    return deck->getLen() == 0;
}

int Player::getLife() const {
    return life;
}

void Player::drawCard() {
    hand->add(deck->pop());
}

void Player::discardCard(int i) {
    hand->remove(i);
}

void Player::notifyCards(TriggerState triggeredAbilityEnum) {
        board->notify(triggeredAbilityEnum);
}

void Player::restoreMinions() {
    for (int i=0; i<board->getNumMinions(); ++i) {
        board->getMinion(i).resetActions();
    }
}

// ASSUMES 0-INDEXED
const int Player::getMinionAttack(int i) const {
    return board->getMinion(i).getAttack();
}

// try to attack the minion i from board with attackPower
const int Player::getMinionDefence(int i) const {
    return board->getMinion(i).getDefense();
}

void Player::setMinionAttack(int i, int newAttack) {
    board->getMinion(i).setAttack(newAttack);
}

// try to attack the minion i from board with attackPower
void Player::setMinionDefence(int i, int newDefense) {
    board->getMinion(i).setDefense(newDefense);
}

void Player::reduceLife(int reduceBy) {
    life -= reduceBy;
}

void Player::playCard(int i) {
    Card& card = hand->getCard(i);
    if (card.type == "MINION" || card.type == "RITUAL") {
        board->add(hand->remove(i));
    } else if (card.type == "SPELL") {
        static_cast<Spell&>(card).notify();
        hand->remove(i);
    }
}

// get the number of minions in the board
int Player::getNumMinions() const {
    return board->getNumMinions();
}

void Player::addCardToBoard(unique_ptr<Card> card) {
    board->add(move(card));
}