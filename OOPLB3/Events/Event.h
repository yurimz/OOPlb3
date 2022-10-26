//
// Created by akimfeopentov on 20.09.22.
//


#ifndef UNTITLED2_EVENT_H
#define UNTITLED2_EVENT_H
class Event;
#include "../Map/Field.h"

class Event {
public:
    virtual void eventCell(Field &field) = 0;
};


#endif //UNTITLED2_EVENT_H
