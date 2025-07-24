#ifndef CARDGENERATOR_H
#define CARDGENERATOR_H
#include <memory>
#include "minion.h"
#include "ritual.h"
class CardGenerator {
    public:
        CardGenerator();
        unique_ptr<Card> getCardFromString(string cardName);

};
#endif