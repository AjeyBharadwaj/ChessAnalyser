QT += widgets

TARGET    = ChessAnalyser 
TEMPLATE  = app

SOURCES   = ChessBoard.cpp \
            PGNRepo.cpp \
            MainWindow.cpp \
            ChessDraw.cpp \
            main.cpp

HEADERS   = ..\inc\Board.h \
            ..\inc\ChessBoard.h \
            ..\inc\Repo.h \
            ..\inc\PGNRepo.h \
            ..\inc\MainWindow.h \
            ..\inc\Draw.h \
            ..\inc\ChessDraw.h

RESOURCES = ..\src\ExtraFiles.qrc
