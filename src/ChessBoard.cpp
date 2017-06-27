#include "../inc/ChessBoard.h"

#include <iostream>
using namespace std;

// Implement ChessBoard.h functions

ChessBoard::ChessBoard() {
    ;
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
    return "rook";
}

const string ChessBoard::getPawnColour(Position P) {
    return "black";
}

const string ChessBoard::getBackgroundColour(Position P) {
    return "black";
}

