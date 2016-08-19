#-------------------------------------------------
#
# Project created by QtCreator 2016-01-26T22:41:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RayCastingFinal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    color.cpp \
    material.cpp \
    light.cpp \
    object.cpp \
    triangle.cpp \
    intersection.cpp \
    ray.cpp \
    camera.cpp \
    scene.cpp \
    mathutils.cpp \
    point.cpp \
    mytree.cpp \
    solidcube.cpp \
    myterrain.cpp \
    myfence.cpp \
    myhay.cpp \
    mylamp.cpp \
    mysilo.cpp \
    mysun.cpp \
    mymill.cpp \
    mybarn.cpp \
    mycloud.cpp \
    myfarmer.cpp \
    mycow.cpp \
    mydog.cpp

HEADERS  += mainwindow.h \
    color.h \
    material.h \
    light.h \
    object.h \
    triangle.h \
    intersection.h \
    ray.h \
    camera.h \
    scene.h \
    mathutils.h \
    point.h \
    Models/BlenderCube.h \
    Models/BlenderBarn.h \
    Models/BlenderCloud.h \
    Models/BlenderCow.h \
    Models/BlenderDog.h \
    Models/BlenderFarmer.h \
    Models/BlenderFence.h \
    Models/BlenderHay.h \
    Models/BlenderLamp.h \
    Models/BlenderMill.h \
    Models/BlenderSilo.h \
    Models/BlenderTerrain.h \
    Models/BlenderTree.h \
    Sombra/balcao.h \
    Sombra/base.h \
    Sombra/escritorio.h \
    Sombra/floor.h \
    Sombra/mesinha.h \
    Sombra/newwall.h \
    Sombra/roof.h \
    Sombra/sofa.h \
    Sombra/tv.h \
    Sombra/walls.h \
    mytree.h \
    solidcube.h \
    myterrain.h \
    myfence.h \
    myhay.h \
    mylamp.h \
    mysilo.h \
    mysun.h \
    mymill.h \
    mybarn.h \
    mycloud.h \
    myfarmer.h \
    mycow.h \
    mydog.h

FORMS    += mainwindow.ui

LIBS += -llapack -lblas -larmadillo
