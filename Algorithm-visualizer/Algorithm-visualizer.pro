QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GUI/codeeditor.cpp \
    GUI/highlighter.cpp \
    GUI/linenumberarea.cpp \
    GUI/textblockdata.cpp \
    GUI/test_flowchart.cpp \
    GUI/variableexplorer.cpp \
    GUI/viewer.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    GUI/codeeditor.h \
    GUI/highlighter.h \
    GUI/linenumberarea.h \
    GUI/textblockdata.h \
    GUI/test_flowchart.hpp \
    GUI/variableexplorer.h \
    GUI/viewer.h \
    mainwindow.h \

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

DISTFILES += \
    test1.txt





