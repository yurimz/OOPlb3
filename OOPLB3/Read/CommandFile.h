//
// Created by akimfeopentov on 04.11.22.
//

#ifndef UNTITLED2_COMMANDFILE_H
#define UNTITLED2_COMMANDFILE_H
#include "CommandMap.h"
#include <vector>
#include <fstream>

class CommandFile: public CommandMap{
    std::ifstream file;
    std::vector<std::string> strType;
    std::map<char,CommandType> mapLocal;
public:
    CommandFile();
    bool get_map(std::map<char,CommandType> &map);
    void prov_string(std::string str);
    void delete_space(std::string &str);
};


#endif //UNTITLED2_COMMANDFILE_H
