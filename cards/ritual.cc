#include "ritual.h"
#include <string>
using namespace std;

Ritual::Ritual(string name, string description, int cost, unique_ptr<TriggeredAbility> triggeredAbility, int charges): Card{"RITUAL", name, description, cost}, triggeredAbility{move(triggeredAbility)}, charges{charges} {};

void Ritual::notify(TriggerState trigger) {
    if (cost >= charges){
        charges -= cost;
        triggeredAbility->notify(trigger);
    }
}
