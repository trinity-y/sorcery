#ifndef HASTE_H
#define HASTE_H
#include "enchanter.h"
#include <string>
using namespace std;

class Haste : public Enchanter
{
    int actionBoost;

public:
    Haste(int actionBoost);
    int getDefaultActions() const override;
};

#endif