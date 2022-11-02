//
// Created by akimfeopentov on 27.10.22.
//

#ifndef UNTITLED2_LOGMANAGER_H
#define UNTITLED2_LOGMANAGER_H

#include "Logger.h"
#include "log_type.h"
#include "ConsolLogger.h"
#include "FileLogger.h"
#include "Observable.h"

class LogManager {
    char writer;
    std::vector<Logger *> log;
    std::vector<Logger *> logSubscribe;
    std::vector<Logger *> logUnsubscribe;
public:
    LogManager();

    static LogManager &getLogM();

    void SetWriter();

    void reactionWriter();

    void SetLevel();

    std::vector<Logger *> getLogSubscribe();
    std::vector<Logger *> getLogUnsubscribe();

    ~LogManager();
};


#endif //UNTITLED2_LOGMANAGER_H
