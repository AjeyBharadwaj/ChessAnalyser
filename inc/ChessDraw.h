#include "Draw.h"
#include <QIcon>

class ChessDraw : public Draw {
public:
    ChessDraw(int r, int c);
    bool draw(const Position *p);
    bool drawDefaultBoard();

private:
    QIcon **icon;
};
