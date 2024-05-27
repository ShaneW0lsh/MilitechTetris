QT += core gui widgets network openglwidgets sql
CONFIG += c++17 cmdline
LIBS += -lopengl32
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AuthDialog.cpp \
    MainWindow.cpp \
    RendererFacilities.cpp \
    consoleclient.cpp \
    core/Board.cpp \
    core/Tetromino.cpp \
    core/TetrominoFactory.cpp \
    core/Tetromino_I.cpp \
    core/Tetromino_J.cpp \
    core/Tetromino_L.cpp \
    core/Tetromino_O.cpp \
    core/Tetromino_S.cpp \
    core/Tetromino_T.cpp \
    core/Tetromino_Z.cpp \
    main.cpp \
    GameRenderer.cpp
    consoleclient.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    AuthDialog.h \
    GameRenderer.hpp \
    MainWindow.h \
    RendererFacilities.hpp \
    consoleclient.h \
    core/Board.hpp \
    core/Tetromino.hpp \
    core/TetrominoFactory.hpp \
    core/Tetromino_I.hpp \
    core/Tetromino_J.hpp \
    core/Tetromino_L.hpp \
    core/Tetromino_O.hpp \
    core/Tetromino_S.hpp \
    core/Tetromino_T.hpp \
    core/Tetromino_Z.hpp \
    consoleclient.h
