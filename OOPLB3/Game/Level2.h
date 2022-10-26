//
// Created by akimfeopentov on 17.10.22.
//

#ifndef UNTITLED2_LEVEL2_H
#define UNTITLED2_LEVEL2_H
#include "iostream"
#include "../Map/FieldView.h"
#include "../Map/Field.h"
#include "../Read/CommandReader.h"
#include "../Controller.h"
#include "../Events/EventMapTrap.h"
#include "../Events/EventPlayerTeleport.h"
#include "../Events/EventMapPassage.h"
#include "../Events/EventStateWin.h"
#include "../Events/EventPlayerHPDec.h"
#include "../Events/EventPlayerHPInc.h"

class Level2 {
public:
    void start();
    void gameCurrent(Field &field);
};


#endif //UNTITLED2_LEVEL2_H
