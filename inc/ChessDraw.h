#ifndef CHESSDRAW_H
#define CHESSDRAW_H

#include "Draw.h"
#include "Board.h"

#include <QIcon>
#include <QPushButton>
#include <QAbstractButton>

#include <iostream>
#include <string>
#include <map>

class ChessDraw : public Draw {
public:
    ChessDraw(int r, int c, Board *_board, QAbstractButton **_square);
    bool draw(const Position *p);
    bool drawDefaultBoard();

private:
    std::map <QString, QIcon*>icon;
    QAbstractButton **square;
    Board *board;
};

#endif
