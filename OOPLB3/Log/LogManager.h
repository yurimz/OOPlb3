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
    int writer;
    int level;
    Logger *logConsol;
    Logger *logfile;
public:
    void SetWriter();
    void SetLevel();
    void reactionWriter();

};


#endif //UNTITLED2_LOGMANAGER_H
