#include "hand.h"

Hand::Hand() {};

Hand::add(unique_ptr<Card> card) {
  hand.push_back(card)
}
