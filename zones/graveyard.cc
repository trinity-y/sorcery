#include "graveyard.h"

#include <queue>

using namespace std;

Graveyard::Graveyard() {};

void Graveyard::add(unique_ptr<Minion> minion) {
  graveyard.push_back(minion);
}

Minion Graveyard::pop() {
  return graveyard.pop_front();
}
