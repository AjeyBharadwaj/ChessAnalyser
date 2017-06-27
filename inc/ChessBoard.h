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
    Colour   backgroundColour;
    Colour   pawnColour;
    Pawn     pawn;
    void     *dynamicData;
    void     *staticData;
} Block;

/*
 * TODO : This has to take Algo Class elements.
 * Each move* funtionc should take additional parameter which defines the algo.
 */

//template<typename T>
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

    bool moveToFirst();
    bool moveToPrev();
    bool moveToNext();
    bool moveTeNext(Position from, Position to); // Override for actual game.
    bool moveToEnd();
    int  getMoveCount();

    bool  setStaticData(Position P, void *dPtr);
    bool  setDynamicData(Position P, void *dPtr);
    void* getStaticData(Position P);
    void* getDynamicData(Position P);

    const string getPawn(Position P);
    const string getPawnColour(Position P);
    const string getBackgroundColour(Position P);

    // List changes in postion. [<from,to>, <from,to>....]
    Block* parse(string move, int &changes);
    std::map<Position, Block*> blocks;

    Repo *R;
};

#endif
