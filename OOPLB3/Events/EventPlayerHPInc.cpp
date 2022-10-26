//
// Created by akimfeopentov on 12.10.22.
//

#include "EventPlayerHPInc.h"
#include <iostream>

void EventPlayerHPInc::eventCell(Field &field) {
    int hp = field.getPlayer()->getHp();
    if (hp <= 90) {
        hp += 10;
    } else
        hp = 100;
    field.getPlayer()->setHp(hp);
    field.getPlayer()->setHp(hp);
    field.get_map()[field.getPlayerPosY()][field.getPlayerPosX()].setEvent(nullptr);
    field.get_map()[field.getPlayerPosY()][field.getPlayerPosX()] = GRASS;
}
