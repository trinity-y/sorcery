#include "hand.h"
#include <iostream>
using namespace std;
Hand::Hand() {};

void Hand::add(unique_ptr<Card> card)
{
  hand.push_back(move(card));
}
int Hand::getHandLen() const
{
  return hand.size();
}

unique_ptr<Card> Hand::remove(int i)
{
  unique_ptr<Card> card = move(hand[i]); // move ownershup into this unique_ptr
  hand.erase(hand.begin() + i);
  return card;
}

Card &Hand::getCard(int i)
{
  if (i < getHandLen())
  {
    return *hand[i];
  }
  // For now, return the first card if index is out of bounds -> later can throw an exception?
  cerr << "Tried to get a card that's not in your hand." << endl;
  return *hand[0];
}

const Card &Hand::getCard(int i) const
{
  if (i < getHandLen())
  {
    return *hand[i];
  }
  cerr << "Tried to get a card that's not in your hand." << endl;
  // For now, return the first card if index is out of bounds
  return *hand[0];
}
