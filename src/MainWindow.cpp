#include <iostream>

#include "../inc/MainWindow.h"
#include "../inc/ChessDraw.h"

using namespace std;

MainWindow::MainWindow() {
    initLayout();
    initBoard();
    initDraw();
    drawDefaultBoard();
}

MainWindow::~MainWindow() {
    //qDebug() << "Destructor called" << endl;
}

void MainWindow::initDraw() {
    draw = new ChessDraw(8, 8, board, (QAbstractButton **)square);
}

void MainWindow::initLayout() {
    window = new QWidget();

    mainLayout = new QHBoxLayout();
    playLayout = new QVBoxLayout();
    matchLayout = new QHBoxLayout();
    infoLayout = new QVBoxLayout();

    fileLayout = new QHBoxLayout();
    fileName = new QLabel();
    fileButton = new QPushButton("Repo");
    fileButton->setFixedSize(30, 30);
    connect(fileButton, SIGNAL (released()), this, SLOT(loadFile()));
    fileLayout->addWidget(fileName);
    fileLayout->addWidget(fileButton);

    boardLayout = new QGridLayout();
    boardLayout->setHorizontalSpacing(0);
    boardLayout->setVerticalSpacing(0);

    moveButtonSetup();

    playLayout->addLayout(fileLayout);
    playLayout->addLayout(boardLayout);
    playLayout->addLayout(moveButtonLayout);

    matchList = new QListView();
    matchListModel = NULL;
    moveList  = new QListView();
    moveListModel = NULL;
    matchLayout->addWidget(matchList);
    matchLayout->addWidget(moveList);

    connect(matchList, SIGNAL(clicked(QModelIndex)), this, SLOT(loadMoves(QModelIndex)));
    connect(moveList, SIGNAL(clicked(QModelIndex)), this, SLOT(makeMove(QModelIndex)));

    infoBoxSetup();

    mainLayout->addLayout(playLayout);
    mainLayout->addLayout(matchLayout);
    mainLayout->addLayout(infoLayout);

    window->setLayout(mainLayout);

    window->layout()->setSizeConstraint(QLayout::SetFixedSize);

    window->show();

    // FIXME
    //loadFile("/home/ajbharad/ChessAnalyser/Chess_Test.pgn")
    //loadFile("c:\\Users\\ajbharad\\Desktop\\ChessAnalyser\\Chess_Test.pgn");
}

void MainWindow::moveButtonSetup() {

    firstMoveButton = new QPushButton("|<");
    prevMoveButton  = new QPushButton("<");
    playButton      = new QPushButton("|>");
    nextMoveButton  = new QPushButton(">");
    lastMoveButton  = new QPushButton(">|");

    moveButtonLayout = new QHBoxLayout();

    moveButtonLayout->addWidget(firstMoveButton);
    moveButtonLayout->addWidget(prevMoveButton);
    moveButtonLayout->addWidget(playButton);
    moveButtonLayout->addWidget(nextMoveButton);
    moveButtonLayout->addWidget(lastMoveButton);

    connect(firstMoveButton, SIGNAL (released()), this, SLOT(moveToFirst()));
    connect(prevMoveButton,  SIGNAL (released()), this, SLOT(moveToPrev()));
    connect(playButton,      SIGNAL (released()), this, SLOT(play()));
    connect(nextMoveButton, SIGNAL (released()), this, SLOT(moveToNext()));
    connect(lastMoveButton, SIGNAL (released()), this, SLOT(moveToLast()));

}

void MainWindow::infoBoxSetup() {

    matchesCountLabel = new QLabel("Matches : ");
    resultLabel = new QLabel("Result : ");
    winnerLabel = new QLabel("Winner : ");
    algo1Label = new QLabel("Algo 1 : ");
    algo2Label = new QLabel("Algo 2 : ");

    infoLayout->addWidget(matchesCountLabel);
    infoLayout->addWidget(resultLabel);
    infoLayout->addWidget(winnerLabel);
    infoLayout->addWidget(algo1Label);
    infoLayout->addWidget(algo2Label);
}

void MainWindow::initBoard() {
    int i, j;

    board = new ChessBoard();
    square = new QPushButton*[8];
    for(i = 0; i < 8; i++) {
        square[i] = new QPushButton[8];
        for(j = 0; j < 8; j++) {
            square[i][j].setFixedSize(50, 50);
            square[i][j].setIconSize(QSize(50, 50));
            boardLayout->addWidget(&square[i][j], i, j);
        }
    }
}

void MainWindow::drawDefaultBoard() {
    draw->drawDefaultBoard();
}

void MainWindow::moveToFirst() {

}

void MainWindow::moveToPrev() {

}

void MainWindow::play() {
    playButton->setText("||");
    connect(playButton, SIGNAL (released()), this, SLOT(pause()));
}

void MainWindow::pause() {
    playButton->setText("|>");
    connect(playButton, SIGNAL (released()), this, SLOT(play()));
}

void MainWindow::moveToNext() {
}

void MainWindow::moveToLast() {

}

void MainWindow::loadFile() {

}

void MainWindow::loadMoves(const QModelIndex &index) {

}

void MainWindow::makeMove(const QModelIndex &index) {

}
