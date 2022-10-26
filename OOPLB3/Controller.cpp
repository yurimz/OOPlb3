//
// Created by akimfeopentov on 18.09.22.
//

#include "Controller.h"
#include "Log/message.h"
#include "Log/ConsolLogger.h"
#include "Log/FileLogger.h"


Controller::Controller(CommandReader &cur, Field &field) {
    Logger *log = new ConsoleLogger;
    f = new FileLogger("log.txt");
    log->addLogType(LogType::CriticalState);
    f->addLogType(LogType::ObjectState);
    subscribe(log);
    subscribe(f);
    action(cur, field);
}

void Controller::action(CommandReader &cur, Field &field) {
    char order = cur.getCommand();
    std::pair<int, int> newPosition;
    newPosition.first = field.getPlayerPosY();
    newPosition.second = field.getPlayerPosX();
    switch (order) {
        case 'w':
            newPosition.first--;
            break;
        case 's':
            newPosition.first++;
            break;
        case 'a':
            newPosition.second--;
            break;
        case 'd':
            newPosition.second++;
            break;
    }
    newPosition.first =
            (newPosition.first % field.get_amountCellsY() + field.get_amountCellsY()) % field.get_amountCellsY();
    newPosition.second =
            (newPosition.second % field.get_amountCellsX() + field.get_amountCellsX()) % field.get_amountCellsX();
    if (field.get_map()[newPosition.first][newPosition.second].get_characteristic() != STONE) {
        field.setPlayerPosY(newPosition.first);
        field.setPlayerPosX(newPosition.second);
        field.triggerCellEvent();
        notify(Message(LogType::ObjectState, "Player changed position"));
    } else{
        notify(Message(LogType::CriticalState, "player tries to pass through stone!"));
        //notify(PlayerMessages::triesToPassSolidCell(field));
    }
}

Controller::~Controller() {
    delete f;
}