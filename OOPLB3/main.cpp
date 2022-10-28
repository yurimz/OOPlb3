#include "Game/Level1.h"
#include "Game/LevelTest.h"
#include <iostream>
#include "Game/Level2.h"

void Check(int &cur,int left,int right) {
    while (cur < left || cur > right) {
        std::cout << "Ошибка ввода, повторите ввод" << "\n";
        std::cin >> cur;
    }
}

int main() {
//    std::cout
//            << "Если вы хотите выводить логи только в консоль, нажмите 1, "
//               "только в файл нажмите 2, и в консоль и в файл, нажмите 3, не хотите выводить нажмите 0 \n ";
//
//    int cur;
//    std::cin >> cur;
//    Check(cur,0,3);
    int cur;
    std::cout << "Введите уровень игры от 1 до 2" << "\n";
    std::cin >> cur;
    Check(cur,1,2);
    switch (cur) {
        case 1:
            Level1 game1;
            game1.start();
            break;
        case 2:
            Level2 game2;
            game2.start();
            break;
    }
    return 0;
}