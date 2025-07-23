#ifndef CARD_H
#define CARD_H
#include <memory>
#include <string>

using namespace std;
class Player;
class Card {
  unique_ptr<Player> owner;
  public:
    Card(string type);
    string type;
    string name;
    string description;
    int cost;
    virtual string getLeftBox() = 0;
    virtual string getRightBox() = 0;
};

#endif