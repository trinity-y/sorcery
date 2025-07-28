#include "graveyard.h"
#include "../cards/minion.h"
#include <queue>

using namespace std;

Graveyard::Graveyard(): numMinions{0}, graveyard{queue<unique_ptr<Minion>>{}} {};

void Graveyard::add(unique_ptr<Minion> minion) {
  graveyard.push(move(minion));
  ++numMinions;
}

unique_ptr<Minion> Graveyard::pop() {
  unique_ptr<Minion> front = move(graveyard.front());
  graveyard.pop();
  return front;
}

const int Graveyard::getNumMinions() const {
  return numMinions;
}

// i dont tihnnk we need to notify graveyard
// void Graveyard::notify(TriggerState trigger) {
//   for (int i=0; i< numMinions; ++i) {
//     graveyard[i]->notify(trigger);
//   }
// }