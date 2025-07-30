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

unique_ptr<Card> Graveyard::removeLastMinion() {
  if (numMinions == 0) {
    return nullptr; // or throw an exception
  }
  
  unique_ptr<Minion> lastMinion = move(graveyard.back());
  graveyard.pop();
  --numMinions;
  
  return lastMinion;
}

// i dont tihnnk we need to notify graveyard
// void Graveyard::notify(TriggerState trigger) {
//   for (int i=0; i< numMinions; ++i) {
//     graveyard[i]->notify(trigger);
//   }
// }
