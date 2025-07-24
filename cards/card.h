#ifndef CARD_H
#define CARD_H
#include <memory>
#include <string>
// #include "../player.h"
using namespace std;
class Card {
  // unique_ptr<Player> owner;
  // might be shared?
  public:
    Card(string type, string name, string description, int cost);
    ~Card();
    string type;
    string name;
    string description;
    int cost;
    virtual string getLeftBox() = 0;
    virtual string getRightBox() = 0;
};

#endif