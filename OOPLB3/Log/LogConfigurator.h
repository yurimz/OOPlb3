//
// Created by akimfeopentov on 31.10.22.
//

#ifndef UNTITLED2_LOGCONFIGURATOR_H
#define UNTITLED2_LOGCONFIGURATOR_H

#include "../Game/Level.h"

class LogConfigurator {
public:
    explicit LogConfigurator(Level *);
    void configure();
private:
    void configureLevels(Logger *);
    Level *level;
};


#endif //UNTITLED2_LOGCONFIGURATOR_H
