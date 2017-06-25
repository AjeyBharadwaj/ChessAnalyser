#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
public:
    Board() {row = col = 0; dataPtr = NULL;};
    ~Board() {delete dataPtr;};
    int getRowCount() {return row;};
    int getColCount() {return col;};

protected:
    //virtual bool  setData(int r, int c, void *data) = 0;
    //virtual void* getData(int r, int c) = 0;

private:
    int row;
    int col;
    void **dataPtr;
};

#endif
