#include <QtWidgets/QApplication>
#include "../inc/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow M;
    return a.exec();
}
