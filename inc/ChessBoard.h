#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <string>

#include "../inc/Board.h"

using namespace std;

enum Colour {
    BLACK,
    WHITE
};

enum Pawn {
    EMPTY,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    PAWN
};

typedef struct Pos {
    int row;
    int col;
} Position;

typedef struct Block {
    Position Pos;
    Colour   colour;
    Pawn     pawn;
} Block;

/*
 * TODO : This has to take Algo Class elements.
 * Each move* funtionc should take additional parameter which defines the algo.
 */

class ChessBoard : public Board {
public:
    ChessBoard();
    ChessBoard(string fileName); // A Repo name.
    ~ChessBoard();

    bool moveToFirst(); // First here doesn`t means first move.
    bool moveToPrev();
    bool moveToNext();
    bool moveToEnd();

    string getCurrentMove();
    int getMoveCount();
    string getfileName();

private:
    bool initBoard();
    bool initBoard(Block **block);
    bool set(Block block, int r, int c);

    // List changes in postion. [<from,to>, <from,to>....]
    Block* parse(string move, int &changes);
};

#endif
