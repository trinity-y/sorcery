#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include "../cards/card.h"
#include "../cards/minion.h"
#include "../cards/ritual.h"
#include "../cards/enchantment.h"

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
  unique_ptr<Minion> removeMinion(int index); // moving to graveyard
  void destroyMinion(int index);              // completely deleting the object
  void destroyRitual();                       // completely deleting the object
  const Minion &getMinion(int i) const;
  Minion &getMinion(int i);
  const int getMinionActions(int i) const;
  void decrementMinionActions(int i);
  const Ritual &getRitual() const;
  const int getNumMinions() const;
  void notify(TriggerState trigger, Player &activePlayer, Player &inactivePlayer);
  void notify(TriggerState trigger, Player &activePlayer, int t);
  void addEnchantment(Enchantment &enchantment, int index); // apply enchantment to minion i on board
  bool hasRitualCard() const;

  // for recharge effect
  void changeRitualCharges(int amount);

  // for disenchant minion
  void disenchantMinion(int i);

  // ! debug
  // delete
  void printBoard();
};

#endif