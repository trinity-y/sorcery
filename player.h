#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
using namespace std;
#include "./zones/board.h"
#include "./zones/deck.h"
#include "./zones/hand.h"
#include "./zones/graveyard.h"

class Player {
    unique_ptr<Board> board;
    unique_ptr<Deck> deck;
    unique_ptr<Hand> hand;
    unique_ptr<Graveyard> graveyard;
    int magic=3;
    int life=20;
    string name;
    public:
        Player(string name, vector<string> deckNames);
        ~Player() {}; // temp    
        void shuffleDeck();
        void addMagic(); // Need to increment magic by 1 in GameState
        bool deckIsEmpty(); // Checking if the players deck is empty
        int getHandLen();
        int getLife();
        void drawCard();
        void discardCard(int i); // Discards ith card from hand
        void activateCards(int triggeredAbilityEnum);
        void restoreMinions();
        int getMinionAttack(int i);
        void setMinionAttack(int i, int newAttack);
        int getMinionDefence(int i);
        void setMinionDefence(int i, int newDefence);
        void reduceLife(int reduceBy);
};

#endif