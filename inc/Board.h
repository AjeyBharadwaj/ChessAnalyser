#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <QDebug>

using namespace std;

typedef struct Position {
    int row;
    int col;
    bool operator <( const struct Position &rhs ) const {
        return (row == rhs.row && col == rhs.col);
    }
} Position;

enum GameType {
    ANALYSIS,
    GAME
};


class Board {
public:
    Board() {row = col = currMoveCount = 0;};
    Board(GameType G) {row = col = currMoveCount = 0; gameType = G;};

    ~Board() {};
    int getRowCount() {return row;};
    int getColCount() {return col;};

    GameType getGameType() { return gameType; };

    virtual bool moveToFirst() = 0; // First here doesn`t means first move.
    virtual bool moveToPrev() = 0;
    virtual bool moveToNext() = 0;
    virtual bool moveTeNext(Position from, Position to) = 0; // Override for actual game.
    virtual bool moveToEnd() = 0;
    virtual int  getMoveCount() = 0;

    /*
     * This dPtr changes from block to block when move is done.
     * TODO :
     *      Change void* to Template.
     */
    virtual bool  setStaticData(Position P, void *dPtr) = 0;
    virtual bool  setDynamicData(Position P, void *dPtr) = 0;
    virtual void* getStaticData(Position P) = 0;
    virtual void* getDynamicData(Position P) = 0;

    virtual const string getPawn(Position P) = 0;
    virtual const string getPawnColour(Position P) = 0;
    virtual const string getBackgroundColour(Position P) = 0;

private:
    int row;
    int col;
    int count;
    GameType gameType;
    int currMoveCount;
};

#endif
