//
// Created by akimfeopentov on 04.11.22.
//
#include <algorithm>
#include "CommandFile.h"

CommandFile::CommandFile() {
    file.open("Command.txt");
    strType.push_back("down");
    strType.push_back("up");
    strType.push_back("left");
    strType.push_back("right");
    strType.push_back("esc");
}

bool CommandFile::get_map(std::map<char, CommandType> &map) {
    while (!file.eof()) {
        std::string str;
        std::getline(file, str);
        std::transform(str.begin(), str.end(), str.begin(), tolower);
        delete_space(str);
        prov_string(str);
    }
    if (mapLocal.size() == 5) {
        map = mapLocal;
        return true;
    } else {
        map['s'] = CommandType::DOWN;
        map['w'] = CommandType::UP;
        map['a'] = CommandType::LEFT;
        map['d'] = CommandType::RIGHT;
        map['l'] = CommandType::ESC;
        return false;
    }

}

void CommandFile::delete_space(std::string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            str.erase(i, 1);
            i--;
        }
    }
}

void CommandFile::prov_string(std::string str) {
    std:
    std::string s = "";
    int i = 0;
    for (i; i < str.size(); i++) {
        if (str[i] == ':')
            break;
        s = s + str[i];
    }
    if (i != str.size() - 1) {
        i++;
        for (int j = 0; j < strType.size(); j++) {
            if (strType[j] == s && str.size() == strType[j].size() + 2) {
                if (mapLocal.find(str[i]) == mapLocal.end()) {
                    switch (j) {
                        case 0:
                            mapLocal.insert_or_assign(str[i], CommandType::DOWN);
                            break;
                        case 1:
                            mapLocal.insert_or_assign(str[i], CommandType::UP);
                            break;
                        case 2:
                            mapLocal.insert_or_assign(str[i], CommandType::LEFT);
                            break;
                        case 3:
                            mapLocal.insert_or_assign(str[i], CommandType::RIGHT);
                            break;
                        case 4:
                            mapLocal.insert_or_assign(str[i], CommandType::ESC);
                            break;
                    }
                }

            }
        }
    }
}