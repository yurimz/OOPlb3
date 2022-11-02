//
// Created by akimfeopentov on 18.09.22.
//

#include "Controller.h"
#include "Log/message.h"
#include "Log/ConsolLogger.h"
#include "Log/LogConfigurator.h"
#include "Log/LoggerPool.h"


Controller::Controller(CommandReader &cur, Field &field) {
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
        case 'l':
            notify(Message(LogType::GameState, "Game end"));
            break;
        default:
            notify(Message(LogType::CriticalState, "Wrong command"));
    }
    newPosition.first =
            (newPosition.first % field.get_amountCellsY() + field.get_amountCellsY()) % field.get_amountCellsY();
    newPosition.second =
            (newPosition.second % field.get_amountCellsX() + field.get_amountCellsX()) % field.get_amountCellsX();
    if (field.get_map()[newPosition.first][newPosition.second].get_characteristic() != STONE &&
        (field.getPlayerPosY() != newPosition.first || field.getPlayerPosX() != newPosition.second)) {
        field.setPlayerPosY(newPosition.first);
        field.setPlayerPosX(newPosition.second);
        field.triggerCellEvent();
        notify(Message(LogType::ObjectState,
                       "Player changed position " + std::to_string(field.getPlayerPosY()) + " " +
                       std::to_string(field.getPlayerPosX())));
    } else {
        if(field.get_map()[newPosition.first][newPosition.second].get_characteristic() == STONE)
            notify(Message(LogType::CriticalState, "player tries to pass through stone!"));
    }
}

Controller::~Controller() {
}