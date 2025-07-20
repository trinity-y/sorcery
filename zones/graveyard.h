#ifndef GRAVEYARD_H
#define GRAVEYARD_H
#include <queue>
#include <memory>
using namespace std;

class Minion;

class Graveyard {
  queue<unique_ptr<Minion>> graveyard;
  public:
    Graveyard();
    void add(Minion& minion);
    Minion pop();
}

#endif