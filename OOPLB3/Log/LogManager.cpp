//
// Created by akimfeopentov on 27.10.22.
//

#include "LogManager.h"
#include "iostream"

LogManager::LogManager() {
    log.push_back(new ConsoleLogger);
    log.push_back(new FileLogger("log.txt"));
}

LogManager &LogManager::getLogM() {
    static LogManager manager;
    return manager;
}

void LogManager::SetWriter() {
    std::cout
            << "Если вы хотите выводить логи только в консоль, нажмите 1, "
               "только в файл нажмите 2, и в консоль и в файл, нажмите 3, не хотите выводить нажмите 0 \n ";
    std::cin >> writer;
    std::cin.ignore(1251, '\n');;
    while (writer < '0' || writer > '3') {
        std::cout << "Ошибка ввода, повторите ввод \n";
        std::cin >> writer;
        std::cin.ignore(1251, '\n');
    }
    reactionWriter();
    if (writer != '0')
        SetLevel();
}


void LogManager::SetLevel() {
    char cur = ' ';
    while (cur != '0') {
        if (log[0]->logTypeAvailable(LogType::ObjectState))
            std::cout << "ObjectState подписан, хотите отписать нажмите 1\n";
        else
            std::cout << "Хотите подписать ObjectState нажмите 1\n";
        if (log[0]->logTypeAvailable(LogType::GameState))
            std::cout << "GameState подписан, хотите отписать нажмите 2\n";
        else
            std::cout << "Хотите подписать GameState нажмите 2\n";
        if (log[0]->logTypeAvailable(LogType::CriticalState))
            std::cout << "CriticalState подписан, хотите отписать нажмите 3\n";
        else
            std::cout << "Хотите подписать CriticalState нажмите 3\n";
        std::cout<<"Оставить так и выйти, нажмите 0\n";
        std::cin >> cur;std::cin.ignore(1251, '\n');
        switch (cur) {
            case '0':
                break;
            case '1':
                if (log[0]->logTypeAvailable(LogType::ObjectState))
                    std::cout << "Отписаны логи уровня ObjectState\n";
                else
                    std::cout << "Подписаны логи уровня ObjectState\n";
                for (int i = 0; i < log.size(); i++)
                    if (log[i]->logTypeAvailable(LogType::ObjectState))
                        log[i]->deleteLogType(LogType::ObjectState);
                    else
                        log[i]->addLogType(LogType::ObjectState);
                break;
            case '2':
                if (log[0]->logTypeAvailable(LogType::GameState))
                    std::cout << "Отписаны логи уровня GameState\n";
                else
                    std::cout << "Подписаны логи уровня GameState\n";
                for (int i = 0; i < log.size(); i++)
                    if (log[i]->logTypeAvailable(LogType::GameState))
                        log[i]->deleteLogType(LogType::GameState);
                    else
                        log[i]->addLogType(LogType::GameState);
                break;
            case '3':
                if (log[0]->logTypeAvailable(LogType::CriticalState))
                    std::cout << "Отписаны логи уровня CriticalState\n";
                else
                    std::cout << "Подписаны логи уровня CriticalState\n";
                for (int i = 0; i < log.size(); i++)
                    if (log[i]->logTypeAvailable(LogType::CriticalState))
                        log[i]->deleteLogType(LogType::CriticalState);
                    else
                        log[i]->addLogType(LogType::CriticalState);
                break;
            default:
                std::cout << "Ошибка ввода\n";
        }
    }
}

void LogManager::reactionWriter() {
    for(int i=0;i<logSubscribe.size();i++)
        delete logSubscribe[i];
    for(int i=0;i<logUnsubscribe.size();i++)
        delete logUnsubscribe[i];
    logSubscribe.clear();
    std::vector<Logger*>(logSubscribe).swap( logSubscribe );
    logUnsubscribe.clear();
    std::vector<Logger*>(logUnsubscribe).swap(logUnsubscribe);
    switch (writer) {
        case '0':
            logUnsubscribe.push_back(log[0]);
            logUnsubscribe.push_back(log[1]);
            break;
        case '1':
            logUnsubscribe.push_back(log[1]);
            logSubscribe.push_back(log[0]);
            break;
        case '2':
            logUnsubscribe.push_back(log[0]);
            logSubscribe.push_back(log[1]);
            break;
        case '3':
            logSubscribe.push_back(log[0]);
            logSubscribe.push_back(log[1]);
            break;
    }
}


std::vector<Logger *> LogManager::getLogSubscribe() {
    return logSubscribe;
}
std::vector<Logger *> LogManager::getLogUnsubscribe() {
    return logUnsubscribe;
}
LogManager::~LogManager() {
    for(int i=0;i<log.size();i++)
        delete log[i];
    for(int i=0;i<logSubscribe.size();i++)
        delete logSubscribe[i];
    for(int i=0;i<logUnsubscribe.size();i++)
        delete logUnsubscribe[i];
}