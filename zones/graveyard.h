#ifndef GRAVEYARD_H
#define GRAVEYARD_H
#include <queue>
#include <memory>
#include "../cards/minion.h"
using namespace std;

class Graveyard {
  queue<unique_ptr<Minion>> graveyard;
  int numMinions;
  public:
    Graveyard();
    void add(unique_ptr<Minion> minion);
    unique_ptr<Minion> pop();
    const int getNumMinions() const;
    void notify(TriggerState trigger);
};

#endif