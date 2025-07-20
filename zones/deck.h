#ifndef DECK_H
#define DECK_H
#include <vector>
#include <memory>
#include <random>

using namespace std;

class Card;

class Deck {
  vector<unique_ptr<Card>> deck;
  default_random_engine rng;
  public:
    Deck(unique_ptr<Card> deck);
    Card pop();
    void shuffle();
};

#endif