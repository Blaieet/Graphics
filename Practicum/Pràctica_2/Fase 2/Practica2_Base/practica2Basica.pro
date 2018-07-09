#-------------------------------------------------
#
# Project created by QtCreator 2012-02-07T16:04:09
#
#-------------------------------------------------

QT       += core gui opengl
QT       += widgets

TARGET = practica2Basica
TEMPLATE = app

SOURCES +=\
    Camera.cpp \
    Light.cpp \
    Material.cpp \
    MainWindow.cpp \
    Main.cpp \
    GLWidget.cpp \
    library/Common.cpp \
    objects/cara.cpp \
    objects/Object.cpp \
    scenes/Scene.cpp \
    scenes/SceneFactory.cpp \
    scenes/SceneFactoryBasica.cpp \
    TG/TG.cpp \
    animations/Animation.cpp \
    TG/Rotate.cpp \
    scenes/Factoryconcurso.cpp \
    TG/Scale1.cpp \
    TG/Translate1.cpp \
    TG/Rotatesecundaria.cpp

HEADERS  += \
    library/vec.h \
    library/mat.h \
    library/Common.h \
    Camera.h \
    Light.h \
    Material.h \
    MainWindow.h \
    objects/cara.h \
    objects/Object.h \
    scenes/Scene.h \
    scenes/SceneFactory.h \
    scenes/SceneFactoryBasica.h \
    GLWidget.h \
    TG/TG.h \
    animations/Animation.h \
    TG/Rotate.h \
    scenes/Factoryconcurso.h \
    TG/Scale1.h \
    TG/Translate1.h \
    TG/Rotatesecundaria.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    vshader1.glsl \
    fshader1.glsl

RESOURCES += resources.qrc

DISTFILES +=
