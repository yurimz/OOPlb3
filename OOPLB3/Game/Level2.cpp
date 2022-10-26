//
// Created by akimfeopentov on 17.10.22.
//

#include "Level2.h"

void Level2::start() {
    const int amountCellX = 17;
    const int amountCellY = 12;
    Field field = Field(amountCellX, amountCellY);
    field.get_map()[0][1]=STONE;
    field.get_map()[1][1]=STONE;
    field.get_map()[1][0]=STONE;
    field.get_map()[0][amountCellX-2]=STONE;
    field.get_map()[0][amountCellX-1]=HP_DEC;
    field.get_map()[0][amountCellX-1].setEvent(new EventPlayerHPDec);
    field.get_map()[1][amountCellX-2]=STONE;
    field.get_map()[2][amountCellX-2]=STONE;
    field.get_map()[2][amountCellX-1]=STONE;
    field.get_map()[amountCellY-2][0]=STONE;
    field.get_map()[amountCellY-2][1]=STONE;
    field.get_map()[amountCellY-1][1]=STONE;
    field.get_map()[amountCellY-1][amountCellX-2]=STONE;
    field.get_map()[amountCellY-2][amountCellX-2]=STONE;
    field.get_map()[amountCellY-2][amountCellX-1]=STONE;
    field.get_map()[amountCellY-1][amountCellX-1]=CRASH;
    field.get_map()[amountCellY-1][amountCellX-1].setEvent(new EventMapPassage(0,1));
    field.get_map()[7][7]=FINISH;
    field.get_map()[7][7].setEvent(new EventStateWin);
    gameCurrent(field);
}


void Level2::gameCurrent(Field &field) {
    CommandReader curRead;
    Controller Control = Controller(curRead, field);
    FieldView painting = FieldView(field);
    painting.Field_write(field);
    while (curRead.getCommand() != 'l') {
        curRead.read();
        Control.action(curRead, field);
        std::system("clear");
        painting.Field_write(field);
        if (field.getState() == LOSS) {
            std::cout << "YOU LOSS!\n";
            break;
        }
        if (field.getState() == WIN) {
            std::cout << "YOU WON!\n";
            break;
        }
    }
}