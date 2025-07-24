#include "graveyard.h"
#include "../cards/minion.h"
#include <queue>

using namespace std;

Graveyard::Graveyard() {};

void Graveyard::add(unique_ptr<Minion> minion) {
  graveyard.push(move(minion));
}

unique_ptr<Minion> Graveyard::pop() {
  unique_ptr<Minion> front = move(graveyard.front());
  graveyard.pop();
  return front;
}
