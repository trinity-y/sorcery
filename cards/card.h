#ifndef CARD_H
#define CARD_H
#include <memory>
#include <string>
// #include "../player.h"
using namespace std;
class Card
{
public:
  Card(string type, string name, string description, int cost);
  virtual ~Card();
  string type;
  string name;
  string description;
  int cost;

  virtual string getLeftBox() const = 0;
  virtual string getRightBox() const = 0;
  virtual string getName() const;
  virtual string getType() const;
  virtual string getDescription() const;
  virtual int getCost() const;
};

#endif