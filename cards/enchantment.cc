#include "enchantment.h"
using namespace std;

Enchantment::Enchantment(unique_ptr<Enchanter> enchanter) : Card{"ENCHANTMENT", enchanter->name, enchanter->description, enchanter->cost}, enchanter{move(enchanter)}
{
}

string Enchantment::getLeftBox() const
{
    return enchanter->getLeftBox();
}

string Enchantment::getRightBox() const
{
    return enchanter->getRightBox();
}
