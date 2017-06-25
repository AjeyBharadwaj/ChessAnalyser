QT += widgets

TARGET    = ChessAnalyser 
TEMPLATE  = app

SOURCES   = src\ChessAnalyser.cpp \
            src\GameRepo.cpp \
            src\move.cpp \
            src\main.cpp
            
HEADERS   = include\ChessAnalyser.h \
            include\GameRepo.h \
            include\move.h

RESOURCES = src\ExtraFiles.qrc

