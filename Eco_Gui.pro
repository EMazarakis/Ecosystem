#-------------------------------------------------
#
# Project created by QtCreator 2018-10-11T13:31:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Eco_Gui
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


SOURCES += main.cpp\
        mainwindow.cpp \
    plants.cpp \
    algae.cpp \
    animals.cpp \
    bear.cpp \
    carnivores.cpp \
    deer.cpp \
    ecosystem.cpp \
    fox.cpp \
    grass.cpp \
    groundhog.cpp \
    herbivores.cpp \
    maple.cpp \
    oak.cpp \
    pine.cpp \
    rabbit.cpp \
    salmon.cpp \
    seeded.cpp \
    seedless.cpp \
    tile.cpp \
    wolf.cpp

HEADERS  += mainwindow.h \
    plants.h \
    algae.h \
    animals.h \
    bear.h \
    carnivores.h \
    deer.h \
    ecosystem.h \
    fox.h \
    grass.h \
    groundhog.h \
    herbivores.h \
    maple.h \
    oak.h \
    pine.h \
    rabbit.h \
    salmon.h \
    seeded.h \
    seedless.h \
    tile.h \
    wolf.h

FORMS    += mainwindow.ui
