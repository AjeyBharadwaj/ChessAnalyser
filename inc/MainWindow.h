#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QDebug>
#include <QListview>
#include <QGroupBox>
#include <QFileDialog>
#include <QtWidgets/QMainWindow>
#include <QStringListModel>
#include <QStringList>
#include <QListView>

#include "../inc/Board.h"
#include "../inc/ChessBoard.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();

private slots:
    void moveToFirst();
    void moveToPrev();
    void play();
    void pause();
    void moveToNext();
    void moveToLast();
    void loadFile();
    void loadMoves(const QModelIndex &index);
    void makeMove(const QModelIndex &index);

private:

    void initLayout();
    void initBoard();
    void drawDefaultBoard();

    void moveButtonSetup();
    void infoBoxSetup();

    QWidget *window;
    QHBoxLayout *mainLayout;

    QVBoxLayout *playLayout;
    QHBoxLayout *matchLayout;
    QVBoxLayout *infoLayout;

    // playLayout :
    QHBoxLayout *fileLayout;
    QLabel *fileName;
    QPushButton *fileButton;
    QGridLayout *boardLayout;
    QPushButton **square;
    QHBoxLayout *moveButtonLayout;
    QPushButton *firstMoveButton, *prevMoveButton,
                *playButton, *nextMoveButton, *lastMoveButton;

    // matchLayout
    QListView *matchList;
    QStringListModel *matchListModel;
    int matchIndex;
    QListView *moveList;
    QStringListModel *moveListModel;
    int moveIndex;

    // infoLayout
    QLabel *matchesCountLabel, *resultLabel, *winnerLabel,
            *algo1Label, *algo2Label;

    ChessBoard *board;

};

#endif
