//
// Created by akimfeopentov on 23.10.22.
//

#include "Observable.h"

void Observable::subscribe(Observer *observer) {
    for (int i = 0; i < list.size(); i++) {
        if (observer == list[i])
            return;
    }
    list.push_back(observer);
}

void Observable::unsubscribe(Observer *observer) {
    for (int i = 0; i < list.size(); i++) {
        if (observer == list[i]) {
            list.erase(list.begin() + i);
            return;
        }
    }
}

void Observable::notify(const Message &message) {
    for (Observer *obr: list) {
        obr->update(message);
    }
}