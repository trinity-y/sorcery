#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H
#include "./enchantments/enchanter.h"
#include <memory>
using namespace std;
class Enchantment : public Card
{
public:
    Enchantment(unique_ptr<Enchanter> enchanter);
    unique_ptr<Enchanter> enchanter;
    virtual string getLeftBox() const override;
    virtual string getRightBox() const override;
};

#endif

