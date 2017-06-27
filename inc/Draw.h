#ifndef DRAW_H
#define DRAW_H

#include "Board.h"

class Draw {
public:
    virtual bool draw(const Position *p) = 0;
    virtual bool drawDefaultBoard() = 0;

    int row;
    int col;
};

#endif
