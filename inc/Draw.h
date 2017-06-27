#include "Board.h"

class Draw {
public:
    bool draw(const Position *p) = 0;
    bool drawDefaultBoard() = 0;

private:
    int row;
    int col;
};

