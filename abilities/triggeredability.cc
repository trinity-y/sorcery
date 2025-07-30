#include "triggeredability.h"
using namespace std;

TriggeredAbility::TriggeredAbility(string description, TriggerState trigger, unique_ptr<GameEffect> effect): Ability{description, trigger, move(effect)} {};
