#include "../inc/ChessBoard.h"

#include <iostream>
using namespace std;

// Implement ChessBoard.h functions

ChessBoard::ChessBoard() {
    int i;
    int j;

    Block *tmpBlock;

    int pawnInc = 0;
    int backgroundColourInc = 1;

    for(i = 0; i < 5; i++) {
        tmpBlock = new Block;
        tmpBlock->backgroundColour = static_cast<Colour>((backgroundColourInc++)%2);
        tmpBlock->pawnColour = BLACK;
        tmpBlock->pawn = static_cast<Pawn>(pawnInc++);
        tmpBlock->staticData = tmpBlock->dynamicData = NULL;
        blocks[i] = tmpBlock;
        qDebug() << tmpBlock << " : " << blocks[i];
    }

    pawnInc = 2;
    for(i = 5; i < 8; i++) {
        tmpBlock = new Block;
        tmpBlock->backgroundColour = static_cast<Colour>((backgroundColourInc++)%2);
        tmpBlock->pawnColour = BLACK;
        tmpBlock->pawn = static_cast<Pawn>(pawnInc--);
        tmpBlock->staticData = tmpBlock->dynamicData = NULL;
        blocks[i] = tmpBlock;
    }

    backgroundColourInc = 0;
    for(i = 0; i < 8; i++) {
        tmpBlock = new Block;
        tmpBlock->backgroundColour = static_cast<Colour>((backgroundColourInc++)%2);
        tmpBlock->pawnColour = BLACK;
        tmpBlock->pawn = PAWN;
        tmpBlock->staticData = tmpBlock->dynamicData = NULL;
        blocks[8+i] = tmpBlock;
    }

    for(i = 2; i < 6; i++) {
        backgroundColourInc++;
        for(j = 0; j < 8; j++) {
            tmpBlock = new Block;
            tmpBlock->backgroundColour = static_cast<Colour>((backgroundColourInc++)%2);
            tmpBlock->pawnColour = NONE;
            tmpBlock->pawn = EMPTY;
            tmpBlock->staticData = tmpBlock->dynamicData = NULL;
            blocks[i*8+j] = tmpBlock;
        }
    }

    backgroundColourInc++;
    for(i = 0; i < 8; i++) {
        tmpBlock = new Block;
        tmpBlock->backgroundColour = static_cast<Colour>((backgroundColourInc++)%2);
        tmpBlock->pawnColour = WHITE;
        tmpBlock->pawn = PAWN;
        tmpBlock->staticData = tmpBlock->dynamicData = NULL;
        blocks[6*8+i] = tmpBlock;
    }

    pawnInc = 0;
    backgroundColourInc++;
    for(i = 0; i < 5; i++) {
        tmpBlock = new Block;
        tmpBlock->backgroundColour = static_cast<Colour>((backgroundColourInc++)%2);
        tmpBlock->pawnColour = WHITE;
        tmpBlock->pawn = static_cast<Pawn>(pawnInc++);
        tmpBlock->staticData = tmpBlock->dynamicData = NULL;
        blocks[7*8+i] = tmpBlock;
    }

    pawnInc = 2;
    for(i = 5; i < 8; i++) {
        tmpBlock = new Block;
        tmpBlock->backgroundColour = static_cast<Colour>((backgroundColourInc++)%2);
        tmpBlock->pawnColour = WHITE;
        tmpBlock->pawn = static_cast<Pawn>(pawnInc--);
        tmpBlock->staticData = tmpBlock->dynamicData = NULL;
        blocks[{7*8+i}] = tmpBlock;
    }
}

bool ChessBoard::moveToFirst() {
    return true;
}

bool ChessBoard::moveToPrev() {
    return true;
}

bool ChessBoard::moveToNext() {
    return true;
}

bool ChessBoard::moveTeNext(Position from, Position to) {
    return true;
}

bool ChessBoard::moveToEnd() {
    return true;
}

int ChessBoard::getMoveCount() {
    return 10;
}

/*
 * This dPtr changes from block to block when move is done.
 * TODO :
 *      Change void* to Template.
 */
bool  ChessBoard::setStaticData(Position P, void *dPtr) {
    return true;
}

bool  ChessBoard::setDynamicData(Position P, void *dPtr) {
    return true;
}

void* ChessBoard::getStaticData(Position P) {
    return NULL;
}

void* ChessBoard::getDynamicData(Position P) {
    return NULL;
}

const string ChessBoard::getPawn(Position P) {
    Block *tmpBlock;
    tmpBlock = blocks[P.row*8+P.col];

    switch(tmpBlock->pawn) {
    case ROOK:
        return "rook";
    case KNIGHT:
        return "knight";
    case BISHOP:
        return "bishop";
    case QUEEN:
        return "queen";
    case KING:
        return "king";
    case PAWN:
        return "pawn";
    default:
        return "";
    }
}

const string ChessBoard::getPawnColour(Position P) {
    Block *tmpBlock;
    tmpBlock = blocks[P.row*8+P.col];

    switch(tmpBlock->pawnColour) {
    case BLACK:
        return "black";
    case WHITE:
        return "white";
    default:
        return "";
    }
}

const string ChessBoard::getBackgroundColour(Position P) {
    Block *tmpBlock;
    tmpBlock = blocks[P.row*8+P.col];

    switch(tmpBlock->backgroundColour) {
    case BLACK:
        return "black";
    case WHITE:
        return "white";
    default:
        return "";
    }
}

