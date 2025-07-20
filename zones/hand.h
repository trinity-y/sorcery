#IFNDEF HAND_H
#DEFINE HAND_H
#include <vector>
using namespace std;

class Card;

class Hand {
  const MAX_CARDS = 5;
  vector<unique_ptr<Card>> hand;
  public:
    Hand();
    void add(unique_ptr<Card> card);
    Card remove(int i);
}


#ENDIF