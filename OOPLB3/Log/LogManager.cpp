//
// Created by akimfeopentov on 27.10.22.
//

#include "LogManager.h"
#include "iostream"

void LogManager::SetWriter() {
    std::cout
            << "Если вы хотите выводить логи только в консоль, нажмите 1, "
               "только в файл нажмите 2, и в консоль и в файл, нажмите 3, не хотите выводить нажмите 0 \n ";
    std::cin >> writer;
    while (writer < 0 || writer > 3) {
        std::cout << "Ошибка ввода, повторите ввод \n";
        std::cin >> writer;
    }
    reactionWriter();
}

void LogManager::reactionWriter() {
    switch (writer) {
        case 1:
            if (logConsol == nullptr)
                logConsol = new ConsoleLogger;
            logfile = nullptr;
            break;
        case 2:
            logConsol = nullptr;
            if (logfile == nullptr)
                logfile = new FileLogger("log.txt");
            break;
        case 3:
            if (logConsol == nullptr)
                logConsol = new ConsoleLogger;
            if (logfile == nullptr)
                logfile = new FileLogger("log.txt");
            break;
        case 0:
            logfile = nullptr;
            logConsol = nullptr;
    }
}
