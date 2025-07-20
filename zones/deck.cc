#include "deck.h"
#include <vector>
#include <chrono>

using namespace std;

class Card;

Deck::Deck(vector<unique_ptr<Card>> deck): deck{deck}, rng{chrono::system_clock::now().time_since_epoch().count()} {};

Card Deck::pop() {
  return deck.pop_back();
}

void Deck::shuffle() {
  shuffle(deck.begin(), deck.end(), rng);
}
