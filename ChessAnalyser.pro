QT += widgets

TARGET    = ChessAnalyser 
TEMPLATE  = app

SOURCES   = src\ChessBoard.cpp \
            src\GameRepo.cpp \
            src\MainWindow.cpp \
            src\main.cpp

HEADERS   = inc\Board.h \
            inc\ChessBoard.h \
            inc\Repo.h \
            inc\GameRepo.h \
            inc\MainWindow.h

RESOURCES = src\ExtraFiles.qrc

