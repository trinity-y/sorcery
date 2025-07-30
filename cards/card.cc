#include "card.h"
#include <string>
Card::~Card() {};
Card::Card(string type, string name, string description, int cost) : type{type}, name{name}, description{description}, cost{cost} {};

string Card::getName() const
{
    return name;
}
string Card::getType() const
{
    return type;
}
string Card::getDescription() const
{
    return description;
}

int Card::getCost() const
{
    return cost;
}

