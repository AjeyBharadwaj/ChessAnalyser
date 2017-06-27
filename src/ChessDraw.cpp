#include <QDebug>

#include "../inc/ChessDraw.h"

using namespace std;

ChessDraw::ChessDraw(int r, int c, Board *_board, QAbstractButton **_square) {
    int i, j, k;
    QString file;
    QString colours[2] = {"white", "black"};
    QString pawns[10] = {"rook", "knight", "bishop", "queen",
                            "king", "bishop", "knight", "rook", "pawn", "pawn"};

    row = r;
    col = c;
    square = _square;
    board  = _board;

    // PawnColour : Pawn : Background
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 10; j++) {
            for(k = 0; k < 2; k++) {
                file = QString(colours[i] + "_" +
                               pawns[j] + "_" +
                               colours[k]);

                icon[file] = new QIcon(":/Images/" + file + ".jpg");
                qDebug() << file << icon[file];
            }
        }
        file = QString(colours[i]);

        icon[file] = new QIcon(":/Images/empty_" + file + ".jpg");
    }
}

bool ChessDraw::draw(const Position *p) {

}

bool ChessDraw::drawDefaultBoard() {
    int r, c;
    QString pawn, pawnColour, backgroundColour;
    QString path;

    for(r = 0; r < row; r++) {
        for(c= 0; c < col; c++) {
            pawn = QString::fromStdString(board->getPawn(Position{r, c}));
            pawnColour = QString::fromStdString(board->getPawnColour(Position{r, c}));
            backgroundColour = QString::fromStdString(board->getBackgroundColour(Position{r, c}));
            if (pawn == "") {
                square[r][c].setIcon(*icon[backgroundColour]);
            } else {
                square[r][c].setIcon(*icon[pawnColour + "_" + pawn + "_" + backgroundColour]);
            }
            square[r][c].setFixedSize(50, 50);
            square[r][c].setIconSize(QSize(50, 50));
        }
    }

}
