#include "card.h"
#include <string>
Card::~Card() {};
Card::Card(string type, string name, string description, int cost): type{type}, name{name}, description{description}, cost{cost} {};
