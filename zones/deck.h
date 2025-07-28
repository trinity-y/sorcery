#ifndef DECK_H
#define DECK_H
#include <vector>
#include <memory>
#include <random>
#include <string>
using namespace std;

class Card;

class Deck {
  vector<unique_ptr<Card>> deck;
  default_random_engine rng;
  public:
    Deck(vector<string> deckCardNames);
    unique_ptr<Card> pop();
    void shuffle();
    void printDeck(); // for debugging
    int getLen(); 
};

#endif