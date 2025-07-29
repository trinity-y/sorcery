#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
using namespace std;
#include "./zones/board.h"
#include "./zones/deck.h"
#include "./zones/hand.h"
#include "./zones/graveyard.h"

class Player
{
    unique_ptr<Board> board;
    unique_ptr<Deck> deck;
    unique_ptr<Hand> hand;
    unique_ptr<Graveyard> graveyard;
    int magic = 3;
    int life = 20;
    string name;

public:
    Player(string name, vector<string> deckNames);
    ~Player() {}; // temp
    void shuffleDeck();
    void addMagic(int additionalMagic); // Need to increment magic by 1 in GameState
    void subtractMagic(int subtractMagic);
    bool deckIsEmpty(); // Checking if the players deck is empty
    int getHandLen();
    int getLife() const;
    void drawCard();
    void discardCard(int i); // Discards ith card from hand
    void notifyCards(TriggerState triggeredAbilityEnum);
    void restoreMinions();
    const int getMinionAttack(int i) const;
    const int getMinionDefence(int i) const;
    void changeMinionAttack(int i, int amount);
    void changeMinionDefence(int i, int amount);
    void reduceLife(int reduceBy);
    void playCard(int i);
    int getNumMinions() const;
    void addCardToBoard(unique_ptr<Card> card);

    // View interface methods
    Hand &getHand() { return *hand; }
    Board &getBoard() { return *board; }
    Graveyard &getGraveyard() { return *graveyard; }
    string getName() const { return name; }
    int getMagic() const { return magic; }

    // Additional in progress methods from GameState
    Card &getCardFromHand(int i);
    void addEnchantment(Card &c, int r);
};

#endif