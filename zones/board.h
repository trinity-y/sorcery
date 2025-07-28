#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include "../cards/card.h"
#include "../cards/minion.h"
#include "../cards/ritual.h"

using namespace std;

class Card;
class Board
{
  vector<unique_ptr<Minion>> boardMinions;
  unique_ptr<Ritual> boardRitual;
  bool hasRitual;
  int numMinions;
  void addRitual(unique_ptr<Ritual> ritual);
  void addMinion(unique_ptr<Minion> minion);

public:
  Board();
  void add(unique_ptr<Card> card);
  unique_ptr<Minion> removeMinion(int index);
  unique_ptr<Ritual> removeRitual();
  const Minion& getMinion(int i) const;
  Minion& getMinion(int i);
  const Ritual& getRitual() const;
  const int getNumMinions() const;
  void notify(TriggerState trigger);
  int getAvailableSpace() const;
};

#endif