//
// Created by akimfeopentov on 23.10.22.
//

#ifndef UNTITLED2_LOGGER_H
#define UNTITLED2_LOGGER_H
#include "Observer.h"
#include <vector>

class Logger : public Observer {
    std::vector<LogType> m_types;
protected:
    bool logTypeAvailable(const LogType &type) const;
public:
    void addLogType(const LogType &type);
    void deleteLogType(const LogType &type);
    virtual ~Logger() = default;
};


#endif //UNTITLED2_LOGGER_H
