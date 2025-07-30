#include "board.h"
#include "../cards/card.h"
#include "../cards/minion.h"
#include "../cards/ritual.h"
#include "../cards/enchantment.h"
#include "../cards/baseminion.h"
#include <memory>
#include <stdexcept>
using namespace std;

Board::Board() : boardMinions{vector<unique_ptr<Minion>>{}}, boardRitual{nullptr} {};
// invariant: ritual card stays at the end of the vector
void Board::add(unique_ptr<Card> card)
{
  if (card->type == "MINION" && numMinions < 5)
    addMinion(unique_ptr<BaseMinion>(static_cast<BaseMinion *>(card.release())));
  else if (card->type == "RITUAL")
    addRitual(unique_ptr<Ritual>(static_cast<Ritual *>(card.release())));
}

void Board::addMinion(unique_ptr<Minion> minion)
{
  boardMinions.push_back(move(minion));
  ++numMinions;
}

void Board::addRitual(unique_ptr<Ritual> ritual)
{
  boardRitual = move(ritual);
  hasRitual = true;
}

Minion &Board::getMinion(int i)
{
  if (i >= 0 && i < numMinions)
  {
    return *(boardMinions[i]);
  }
}

const Ritual &Board::getRitual() const
{
  if (hasRitual)
  {
    return *boardRitual;
  }
  else
  {
    throw runtime_error("no ritual card to get");
  }
}

const int Board::getNumMinions() const
{
  return numMinions;
}

void Board::notify(TriggerState trigger, Player &activePlayer, Player &inactivePlayer)
{
  for (int i = 0; i < numMinions; ++i)
  {
    boardMinions[i]->notify(trigger, activePlayer, inactivePlayer);
  }
  if (hasRitual)
  {
    boardRitual->notify(trigger, activePlayer, inactivePlayer);
  }
}

unique_ptr<Minion> Board::removeMinion(int index)
{
  // moving to graveyard (player handles this, we just return it)
  unique_ptr<Minion> removedMinion = nullptr;
  if (index >= 0 && index < numMinions && numMinions != 0)
  {
    numMinions--;
    removedMinion = move(boardMinions[index]);
    boardMinions.erase(boardMinions.begin() + index); // remove from vector
  }
  return removedMinion;
}
void Board::destroyMinion(int index)
{
  // completely deleting the object
  if (index >= 0 && index < numMinions && numMinions != 0)
  { // for sanity
    numMinions--;
    // Remove from vector
    boardMinions.erase(boardMinions.begin() + index);
  }
}
void Board::destroyRitual()
{
  if (hasRitual)
  {
    boardRitual.release();
    hasRitual = false;
  }
}

void Board::changeRitualCharges(int amount)
{
  boardRitual->changeCharges(amount);
}

void Board::addEnchantment(Enchantment &enchantment, int index)
{
  if (index >= 0 && index < numMinions)
  {
    enchantment.enchanter->setNextMinion(move(boardMinions[index]));
    boardMinions[index] = move(enchantment.enchanter);
    // enchantment should be discarded from hand by game state
  }
}

void Board::disenchantMinion(int i)
{
  // removing the top level enchantment
  // get the minion at requested index, downcast it to enchanter
  if (boardMinions[i]->type == "ENCHANTMENT")
  {
    // cast as an enchanter, disenchant the minion
    Enchanter &ench = dynamic_cast<Enchanter &>(*boardMinions[i]);
    boardMinions[i] = ench.disenchantMinion();
  }
}

bool Board::hasRitualCard() const
{
  return hasRitual;
}