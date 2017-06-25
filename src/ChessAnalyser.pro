QT += widgets

TARGET    = ChessAnalyser 
TEMPLATE  = app

SOURCES   = ChessBoard.cpp \
            GameRepo.cpp \
            MainWindow.cpp \
            main.cpp

HEADERS   = ..\inc\Board.h \
            ..\inc\ChessBoard.h \
            ..\inc\Repo.h \
            ..\inc\GameRepo.h \
            ..\inc\MainWindow.h

RESOURCES = ..\src\ExtraFiles.qrc
