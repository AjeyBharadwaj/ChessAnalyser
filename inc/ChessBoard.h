#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <string>
#include <map>

#include "../inc/Board.h"
#include "../inc/Repo.h"

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

typedef struct Block {
    Position Pos;
    Colour   colour;
    Pawn     pawn;
    void     *dynamicData;
    void     *staticData;
} Block;

/*
 * TODO : This has to take Algo Class elements.
 * Each move* funtionc should take additional parameter which defines the algo.
 */

template<typename T>
class ChessBoard : public Board {
public:
    ChessBoard();
    ChessBoard(string repoName); // A Repo name.
    ~ChessBoard();

    string getfileName();

private:
    bool initBoard();
    bool initBoard(Block **block);
    bool set(Block block, int r, int c);

    // List changes in postion. [<from,to>, <from,to>....]
    Block* parse(string move, int &changes);
    std::map<Position, Block*> blocks;

    Repo R;
};

#endif
