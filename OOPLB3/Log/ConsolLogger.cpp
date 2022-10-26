//
// Created by akimfeopentov on 23.10.22.
//
#include <iostream>
#include "ConsolLogger.h"

void ConsoleLogger::update(const Message &message) {
    lo
    if (logTypeAvailable(message.type()))
        std::cout << message << '\n';
}