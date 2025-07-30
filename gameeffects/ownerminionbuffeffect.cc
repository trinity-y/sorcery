#include "ownerminionbuffeffect.h"
#include "../player.h"
#include "../zones/board.h"
#include "../cards/minion.h"

OwnerMinionBuffEffect::OwnerMinionBuffEffect(int attack, int defense)
    : attackBuff(attack), defenseBuff(defense) {}

    void OwnerMinionBuffEffect::useEffect(Player &p, int targetIndex) {

        // check if the minion that just entered belongs to the active player
        if (targetIndex < p.getNumMinions() && targetIndex >= 0){
            // buff the minions attack and defense
            p.changeMinionAttack(targetIndex, attackBuff);
            p.changeMinionDefence(targetIndex, defenseBuff);
        }

        
    }