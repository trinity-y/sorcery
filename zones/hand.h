#ifndef HAND_H
#define HAND_H
#include <vector>
#include <memory>
#include "../cards/card.h"
using namespace std;

class Hand {
  const int MAX_CARDS = 5;
  vector<unique_ptr<Card>> hand;
  public:
    Hand();
    void add(unique_ptr<Card> card);
    unique_ptr<Card> remove(int i);
    int getHandLen() const;
    Card& getCard(int i);
    const Card& getCard (int i) const;
};

#endif
