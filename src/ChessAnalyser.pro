QT += widgets

TARGET = ChessAnalyser 
TEMPLATE = app

SOURCES   = ChessAnalyser.cpp \
            GameRepo.cpp \
	    move.cpp \
            main.cpp
HEADERS   = ChessAnalyser.h \
            GameRepo.h \
	    move.h

RESOURCES += \
    ExtraFiles.qrc

