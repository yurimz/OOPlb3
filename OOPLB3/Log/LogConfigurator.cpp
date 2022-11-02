//
// Created by akimfeopentov on 31.10.22.
//

#include "LogConfigurator.h"
#include "LoggerPool.h"
#include <iostream>

LogConfigurator::LogConfigurator(Level * cont) : level(cont) {}

void LogConfigurator::configure() {
    char choice=' ';
    Logger* logger;
    while(choice!='0'){
        std::cout
                << "Добавить ConsolLogger, нажмите 1\n"
                   "Добавить FileLogger, нажмите 2\n"
                   "Ничего не добавлять, нажмите 0 \n ";
        std::cin >> choice;
        std::cin.ignore(1251, '\n');;
        while (choice < '0' || choice > '2') {
            std::cout << "Ошибка ввода, повторите ввод \n";
            std::cin >> choice;
            std::cin.ignore(1251, '\n');
        }
        if (choice == '1') {
            std::cout << "Логи выводятся в консоли \n";
            logger = new ConsoleLogger;
            configureLevels(logger);
            level->subscribe(logger);
            LoggerPool::getInstance().addLogger(logger);
        }
        else if(choice == '2'){
            std::cout << "Логи записываются в файл log.txt \n";
            logger=new FileLogger("log.txt");
            configureLevels(logger);
            level->subscribe(logger);
            LoggerPool::getInstance().addLogger(logger);
        }
        std::cout<<"Выйти нажмите 0, остаться и подписать что-нибудь ещё нажмите 1\n";
        std::cin >> choice;
        std::cin.ignore(1251, '\n');;
        while (choice < '0' || choice > '1') {
            std::cout << "Ошибка ввода, повторите ввод \n";
            std::cin >> choice;
            std::cin.ignore(1251, '\n');
        }
    }

}

void LogConfigurator::configureLevels(Logger * logger) {
    char cur = ' ';
    while (cur != '0') {
        if (!logger->logTypeAvailable(LogType::ObjectState))
            std::cout << "Хотите подписать ObjectState нажмите 1\n";
        if (!logger->logTypeAvailable(LogType::GameState))
            std::cout << "Хотите подписать GameState нажмите 2\n";
        if (!logger->logTypeAvailable(LogType::CriticalState))
            std::cout << "Хотите подписать CriticalState нажмите 3\n";
        std::cout<<"Оставить так и выйти из подписи уровней, нажмите 0\n";
        std::cin >> cur;std::cin.ignore(1251, '\n');
        switch (cur) {
            case '0':
                break;
            case '1':
                logger->addLogType(LogType::ObjectState);
                std::cout << "Подписаны логи уровня ObjectState\n";
                break;
            case '2':
                logger->addLogType(LogType::GameState);
                std::cout << "Подписаны логи уровня GameState\n";
                break;
            case '3':
                logger->addLogType(LogType::CriticalState);
                std::cout << "Подписаны логи уровня CriticalState\n";
                break;
            default:
                std::cout << "Ошибка ввода\n";
        }
    }

}
