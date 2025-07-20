#IFNDEF BOARD_H
#DEFINE BOARD_H

using namespace std;

class Card;

#include <vector>
class Board {
  vector<unique_ptr<Card>> board;
  bool hasRitual; // invariant: ritual card stays at the end of the vector
  bool numMinions;
  void addRitual(Ritual& ritual);
  void addMinion(Minion& minion);
  public:
    Board();
    void add(unique_ptr<Card> card);
    Card remove(int index);
}

#ENDIF