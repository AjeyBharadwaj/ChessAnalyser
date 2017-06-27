#include "../inc/ChessDraw.h"

ChessDraw::ChessDraw(int r, int c) {
    int i;

    row = r;
    col = c;

    icon = new *QIcon[row];
    for(i = 0; i < row; i++) {
        icon[i] = new QIcon[col];
    }

}

bool ChessDraw::draw(const Position *p) {

}

bool ChessDraw::drawDefaultBoard() {

}
