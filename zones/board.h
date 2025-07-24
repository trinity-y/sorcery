#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include "../cards/card.h"
#include "../cards/minion.h"
#include "../cards/ritual.h"

using namespace std;

class Card;
class Board {
  vector<unique_ptr<Card>> board; // invariant: ritual card stays at the end of the vector (if it exists)
  bool hasRitual; 
  bool numMinions;
  void addRitual(unique_ptr<Card> ritual);
  void addMinion(unique_ptr<Card> minion);
  public:
    Board();
    void add(unique_ptr<Card> card);
    unique_ptr<Card> remove(int index);
};

#endif