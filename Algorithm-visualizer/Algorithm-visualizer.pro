QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AST/ast.cpp \
    GUI/codecell.cpp \
    GUI/gui.cpp \
    GUI/varcell.cpp \
    GUI/viewer.cpp \
    Parsing/parsing.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AST/ast.hpp \
    GUI/codecell.h \
    GUI/gui.hpp \
    GUI/varcell.h \
    GUI/viewer.h \
    Parsing/parsing.hpp \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    Algorithm-visualizer_en_150.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
