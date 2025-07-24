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
        Player() {}; // temp
        ~Player() {}; // temp
};

#endif