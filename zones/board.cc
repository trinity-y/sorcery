#include "board.h"

class Minion;
class Ritual;
Board::Board() {};

void Board::add(unique_ptr<Card> card) {
  if (card.type == "MINION") addMinion(dynamic_cast<unique_ptr<Minion>>card);
  else if (card.type == "RITUAL") addRitual(dynamic_cast<unique_ptr<Ritual>>card);
}

void Board::addMinion(unique_ptr<Minion> minion) {
  if (!hasRitual) {
    board.push_back(minion);
  } else {
    board.insert(board.length-2, minion); // put in second last position
  }
}

void Board::addRitual(unique_ptr<Ritual> ritual) {
  if (!hasRitual) {
    board.push_back(&ritual);
  }
}
