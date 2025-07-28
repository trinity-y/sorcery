#include "board.h"
#include "../cards/card.h"
#include "../cards/minion.h"
#include "../cards/ritual.h"
#include <memory>
#include <stdexcept>
using namespace std;

Board::Board(): boardMinions{vector<unique_ptr<Minion>>{}}, boardRitual{nullptr} {};
// invariant: ritual card stays at the end of the vector
void Board::add(unique_ptr<Card> card) {
  if (card->type == "MINION" && numMinions < 5) 
    addMinion(make_unique<Minion>(static_cast<Minion*>(card.release())));;
  else if (card->type == "RITUAL" && !hasRitual)
    addRitual(make_unique<Ritual>(static_cast<Ritual*>(card.release())));
}

void Board::addMinion(unique_ptr<Minion> minion) {
  boardMinions.push_back(move(minion));
  ++numMinions;
}

void Board::addRitual(unique_ptr<Ritual> ritual) {
  boardRitual = move(ritual);
  hasRitual = true;
}

Minion& Board::getMinion(int i) {
  return *(boardMinions[i]);
}

const Ritual& Board::getRitual() const {
  if (hasRitual) {
    return *boardRitual;
  } else {
    throw runtime_error("no ritual card to get");
  }
}

const int Board::getNumMinions() const {
  return numMinions;
}

void Board::notify(TriggerState trigger) {
  for (int i=0; i<numMinions; ++i) {
    boardMinions[i]->notify(trigger);
  }
  if (hasRitual) {
    boardRitual->notify(trigger);
  }
}

int Board::getAvailableSpace() const
{
  const int MAX_MINIONS = 5;
  return MAX_MINIONS - getMinionCount();
}
