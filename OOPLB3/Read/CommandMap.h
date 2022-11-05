//
// Created by akimfeopentov on 04.11.22.
//

#ifndef UNTITLED2_COMMANDMAP_H
#define UNTITLED2_COMMANDMAP_H
#include <map>
#include "CommandType.h"
#include "../Log/Observable.h"

class CommandMap: public Observable{
public:
    virtual bool get_map(std::map<char,CommandType> &map)=0;
};


#endif //UNTITLED2_COMMANDMAP_H
