#-------------------------------------------------
#
# Project created by QtCreator 2019-06-29T22:24:17
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = infiniteEvolution
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    bullet.cpp \
    gamewidget.cpp \
    map.cpp \
    monster.cpp \
    obj.cpp \
    player.cpp \
    prop.cpp \
    mypushbutton.cpp \
    darkload.cpp \
    dragon.cpp \
    knight.cpp \
    pupa.cpp \
    remotemonster.cpp \
    closemonster.cpp \
    skill.cpp \
    inputusername.cpp \
    rankmainwindow.cpp

HEADERS += \
        widget.h \
    bullet.h \
    gamewidget.h \
    map.h \
    monster.h \
    obj.h \
    player.h \
    prop.h \
    mypushbutton.h \
    darkload.h \
    dragon.h \
    knight.h \
    pupa.h \
    remotemonster.h \
    closemonster.h \
    skill.h \
    inputusername.h \
    rankmainwindow.h

FORMS += \
        widget.ui \
    gamewidget.ui \
    inputusername.ui \
    rankmainwindow.ui

RESOURCES += \
    res.qrc \
    res.qrc \
    closemonste_1r.qrc \
    closemonster_2.qrc \
    closemonster_3.qrc \
    remotemonster_1.qrc \
    remotemonster_2.qrc \
    remotemonster_3.qrc \
    remotemonster_4.qrc \
    closemonster_4.qrc \
    closemonster_2.qrc \
    res.qrc \
    closemonster_2.qrc \
    closemonster_3.qrc \
    remotemonster_3.qrc \
    remotemonster_3.qrc \
    remotemonster_3.qrc \
    closemonster_2.qrc
