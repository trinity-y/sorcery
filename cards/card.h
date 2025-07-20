#ifndef CARD_H
#define CARD_H
#include <memory>
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
    string getLeftBox() = 0;
    string getRightBox() = 0;
};

#endif