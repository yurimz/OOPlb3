//
// Created by akimfeopentov on 15.10.22.
//

#include "EventPlayerTeleport.h"
EventPlayerTeleport::EventPlayerTeleport(int y, int x) {
    this->PosTeleportX=x;
    this->PosTeleportY=y;
    for (int i = 0; i < LogManager::getLogM().getLogSubscribe().size(); i++)
        subscribe(LogManager::getLogM().getLogSubscribe()[i]);
    for (int i = 0; i < LogManager::getLogM().getLogUnsubscribe().size(); i++)
        unsubscribe(LogManager::getLogM().getLogUnsubscribe()[i]);
}

void EventPlayerTeleport::eventCell(Field &field) {
    field.setPlayerPosX(PosTeleportX);
    field.setPlayerPosY(PosTeleportY);
    notify(Message(LogType::ObjectState,"actuation EventPlayerTeleport"));
}
EventPlayerTeleport::~EventPlayerTeleport() {}