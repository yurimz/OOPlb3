//
// Created by akimfeopentov on 15.09.22.
//


#ifndef UNTITLED2_CELL_H
#define UNTITLED2_CELL_H

enum TileType {
    STONE, GRASS, TRAP, HP_INC, HP_DEC, TELEPORT, CRASH, FINISH
};

class Cell;

#include "Field.h"
#include "../Events/Event.h"


class Cell {
    TileType characteristic;
    Event *m_event;
public:
    Cell(TileType characteristic = GRASS);

    char get_characteristic() {
        return characteristic;
    }

    void setCharacteristic(TileType characteristic);

    void triggerEvent(Field &field);

    void setEvent(Event *event);
};


#endif //UNTITLED2_CELL_H
