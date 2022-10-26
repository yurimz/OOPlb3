//
// Created by akimfeopentov on 18.09.22.
//
#include "Map/Field.h"
#include "Map/FieldView.h"
#include "Player/Player.h"
#include "Read/CommandReader.h"
#include "Log/Observable.h"

#ifndef UNTITLED2_CONTROLER_H
#define UNTITLED2_CONTROLER_H

#include "Log/FileLogger.h"



class Controller : public Observable {
public:
    Controller(CommandReader &cur,Field &field);
    void action(CommandReader &cur,Field &field);
    ~Controller();
private:
    Logger *f;
};


#endif //UNTITLED2_CONTROLER_H
