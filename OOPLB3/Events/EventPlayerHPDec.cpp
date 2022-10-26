//
// Created by akimfeopentov on 14.10.22.
//

#include "EventPlayerHPDec.h"


void EventPlayerHPDec::eventCell(Field &field) {
    int hp = field.getPlayer()->getHp();
    if (hp >= 10) {
        hp -= 10;
    }
    else{
        hp = 0;
    }

    field.getPlayer()->setHp(hp);
    if(hp==0){
        field.get_map()[field.getPlayerPosY()][field.getPlayerPosX()].setEvent(new EventStateLoss);
        field.triggerCellEvent();
    }
    field.get_map()[field.getPlayerPosY()][field.getPlayerPosX()].setEvent(nullptr);
    field.get_map()[field.getPlayerPosY()][field.getPlayerPosX()]=GRASS;
}