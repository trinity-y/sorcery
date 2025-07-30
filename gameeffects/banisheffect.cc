#include "banisheffect.h"
#include "../player.h"
// Destroy target minion or ritual
void BanishEffect::useEffect(Player &p, int t){
    p.destroyMinion(t);
}
void BanishEffect::useEffect(Player &p, string t){
    p.destroyRitual();
}
