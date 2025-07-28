#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
using namespace std;
#include "./zones/board.h"
#include "./zones/deck.h"
#include "./zones/hand.h"
#include "./zones/graveyard.h"

class Player {
    public:
        unique_ptr<Board> board;
        unique_ptr<Deck> deck;
        unique_ptr<Hand> hand;
        unique_ptr<Graveyard> graveyard;

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
        void setMinionAttack(int i, int newAttack);
        const int getMinionDefence(int i) const;
        void setMinionDefence(int i, int newDefence);
        void reduceLife(int reduceBy);
        void playCard(int i);
        int getNumMinions() const;
};

#endif