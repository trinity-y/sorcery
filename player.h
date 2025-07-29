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
    // Accessing + modifying player
    Player(string name, vector<string> deckNames);
    ~Player() {}; // temp
    void addMagic(int additionalMagic); // Need to increment magic by 1 in GameState
    void subtractMagic(int subtractMagic);
    int getLife() const;
    void drawCard();
    void playCard(int i); // play card i in hand (0-indexed)

    // Accessing + modifying individual minions on the board
    const int getMinionAttack(int i) const;
    const int getMinionDefence(int i) const;
    void changeMinionAttack(int i, int amount);
    void changeMinionDefence(int i, int amount);
    void reduceLife(int reduceBy);
    void activateMinionAbility(int i, bool passPlayer);
    void activateMinionAbility(int i, Player& p, int t);
    void activateMinionAbility(int i, Player& p, string t);

    // Accessing + modifying player's zones
    int getNumMinions() const; // number of minions in player's board
    void addCardToBoard(unique_ptr<Card> card);
    void shuffleDeck();
    int getHandLen();
    void discardCard(int i); // Discards ith card from hand
    bool deckIsEmpty(); // Checking if the players deck is empty
    void restoreMinions(); // restore minions to their default number of actions
    void notifyCards(TriggerState triggeredAbilityEnum); // notify all cards in board

    // View interface methods
    const Hand &getHand() const { return *hand; }
    const Board &getBoard() const { return *board; }
    const Graveyard &getGraveyard() const { return *graveyard; }
    const string getName() const { return name; }
    const int getMagic() const { return magic; }

    // Additional in progress methods from GameState
    Card &getCardFromHand(int i);
    void addEnchantment(Card &c, int r);
    void addEnchantmentFromHand(int handIndex, int minionIndex); // can only be played on minions
};

#endif