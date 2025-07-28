#include "ritual.h"
#include <string>
using namespace std;

Ritual::Ritual(string name, string description, int cost, unique_ptr<TriggeredAbility> triggeredAbility): Card{"RITUAL", name, description, cost}, triggeredAbility{move(triggeredAbility)} {};

void Ritual::notify(TriggerState trigger) {
    triggeredAbility->notify(trigger);
}
