#include "player.h"
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