//
// Created by akimfeopentov on 15.09.22.
//

#include "Cell.h"

Cell::Cell(TileType characteristic) : characteristic(characteristic), m_event(nullptr) { }

void Cell::setCharacteristic(TileType characteristic) {
    Cell::characteristic = characteristic;
}

void Cell::triggerEvent(Field &field) {
    if (m_event != nullptr) {
        m_event->eventCell(field);
    }
}

void Cell::setEvent(Event *event) {
    m_event = event;
}
