#include "deck.h"
#include <vector>
#include <chrono>
#include <string>
#include <random>
#include <algorithm>
#include <iostream>
#include "../cards/cardgenerator.h"
using namespace std;

class Card;

Deck::Deck(vector<string> cardNames): rng{chrono::system_clock::now().time_since_epoch().count()} {
  CardGenerator cardGenerator = CardGenerator();
  for (int i=0; i<cardNames.size(); ++i){
     deck.push_back(cardGenerator.getCardFromString(cardNames[i]));
  }
};

unique_ptr<Card> Deck::pop() {
  if (deck.empty()) return nullptr;
  unique_ptr<Card> backCard = move(deck.back()); // using move so that way we don't copy the unique_ptr, which is forbidden
  deck.pop_back();
  return backCard;
}

void Deck::shuffle() {
  std::shuffle(deck.begin(), deck.end(), rng);
}

void Deck::printDeck() {
  for (size_t i=0; i<deck.size(); ++i) {
    cout << "Card Name:" << deck[i]->name << endl;
    cout << "Card Type:" << deck[i]->type << endl;
  }
}