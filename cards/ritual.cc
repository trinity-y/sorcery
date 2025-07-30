#include "ritual.h"
#include <string>
using namespace std;

Ritual::Ritual(string name, string description, int cost, unique_ptr<TriggeredAbility> triggeredAbility, int charges) : Card{"RITUAL", name, description, cost}, triggeredAbility{move(triggeredAbility)}, charges{charges} {};

void Ritual::notify(TriggerState trigger, Player& activePlayer, Player& inactivePlayer) //  note: changed from no players
{
    if (cost >= charges)
    {
        charges -= cost;
        triggeredAbility->notify(trigger, activePlayer, inactivePlayer);
    }
}

void Ritual::changeCharges(int amount)
{
    charges += amount;
}

int Ritual::getCharges() const
{
    return charges;
}

int Ritual::getActivationCost() const
{
    return cost; // Assuming cost is the activation cost
}

string Ritual::getRightBox() const
{
    // todo: top inner left box
    return to_string(charges);
}
string Ritual::getLeftBox() const
{
    // empty
    return "";
}
