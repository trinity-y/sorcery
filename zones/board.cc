#include "board.h"
#include "../cards/card.h"
#include "../cards/minion.h"
#include "../cards/ritual.h"
#include <memory>
using namespace std;

Board::Board() {};
// invariant: ritual card stays at the end of the vector
void Board::add(unique_ptr<Card> card)
{
  if (card->type == "MINION")
    addMinion(move(card));
  else if (card->type == "RITUAL")
    addRitual(move(card));
}

void Board::addMinion(unique_ptr<Card> minion)
{ // todo: dynamic cast doesnt work so im accepting minion. might wanna fix this
  if (!hasRitual)
  {
    board.push_back(move(minion));
  }
  else
  {
    board.emplace(board.end() - 1, move(minion)); // put in second last position
  }
}

void Board::addRitual(unique_ptr<Card> ritual)
{
  if (!hasRitual)
  {
    board.push_back(move(ritual));
  }
}

int Board::getMinionCount() const
{
  int count = 0;
  for (const auto &card : board)
  {
    if (card->type == "MINION")
    {
      count++;
    }
  }
  return count;
}

int Board::getAvailableSpace() const
{
  const int MAX_MINIONS = 5;
  return MAX_MINIONS - getMinionCount();
}
