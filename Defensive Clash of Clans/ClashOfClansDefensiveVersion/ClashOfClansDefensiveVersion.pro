QT       += core gui
QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    cannon.cpp \
    castle.cpp \
    enemytroops.cpp \
    fence.cpp \
    game.cpp \
    gameover.cpp \
    level.cpp \
    main.cpp \
    next_level.cpp \
    powerups.cpp \
    start.cpp \
    timer.cpp

HEADERS += \
    bullet.h \
    cannon.h \
    castle.h \
    enemytroops.h \
    fence.h \
    game.h \
    gameover.h \
    level.h \
    next_level.h \
    powerups.h \
    start.h \
    timer.h

FORMS += \
    gameover.ui \
    next_level.ui \
    start.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    gamesources.qrc \
    sources.qrc

DISTFILES += \
    E:/ENG Mohamed/CS2/project/Cs2 sources/caslte/castle.jpeg \
    E:/ENG Mohamed/CS2/project/Cs2 sources/caslte/castle.jpeg \
    castle.jpeg
