QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
<<<<<<< HEAD
    GUI/codecell.cpp \
    GUI/gui.cpp \
    GUI/varcell.cpp \
=======
    GUI/codeeditor.cpp \
    GUI/variableexplorer.cpp \
>>>>>>> 7119ede870b0d7ac65fe1960c3b3019727858467
    GUI/viewer.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
<<<<<<< HEAD
    GUI/codecell.h \
    GUI/gui.hpp \
    GUI/varcell.h \
    GUI/viewer.h \
    mainwindow.h
=======
    GUI/codeeditor.h \
    GUI/variableexplorer.h \
    GUI/viewer.h \
    mainwindow.h \
>>>>>>> 7119ede870b0d7ac65fe1960c3b3019727858467

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
