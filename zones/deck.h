#IFNDEF DECK_H
#DEFINE DECK_H
#include <vector>

using namespace std;

class Card;

class Deck {
  vector<unique_ptr<Card>> deck;
  default_random_engine rng;
  public:
    Deck(unique_ptr<Card> deck);
    Card pop();
    void shuffle();
}

#ENDIF