#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>

using namespace std;

class Card;
class Board {
  vector<unique_ptr<Card>> board;
  bool hasRitual; // invariant: ritual card stays at the end of the vector
  bool numMinions;
  void addRitual(unique_ptr<Ritual> ritual);
  void addMinion(unique_ptr<Minion> minion);
  public:
    Board();
    void add(unique_ptr<Card> card);
    Card remove(int index);
};

#endif