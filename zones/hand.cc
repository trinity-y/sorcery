#include "hand.h"

Hand::Hand() {};

void Hand::add(unique_ptr<Card> card) {
  hand.push_back(move(card));
}
