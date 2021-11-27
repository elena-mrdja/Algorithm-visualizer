QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AST/assignment.cpp \
    AST/ast.cpp \
    AST/binop.cpp \
    AST/block.cpp \
    AST/boolean.cpp \
    AST/decision.cpp \
    AST/declaration.cpp \
    AST/expression.cpp \
    AST/expression_template.cpp \
    AST/ifelse.cpp \
    AST/ifrest.cpp \
    AST/jump.cpp \
    AST/print.cpp \
    AST/return.cpp \
    AST/statement.cpp \
    AST/unop.cpp \
    AST/variable.cpp \
    AST/variable_template.cpp \
    AST/while.cpp \
    GUI/codecell.cpp \
    GUI/gui.cpp \
    GUI/varcell.cpp \
    GUI/viewer.cpp \
    Parsing/parsing.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AST/assignment.hpp \
    AST/ast.hpp \
    AST/binop.hpp \
    AST/binop_template.hpp \
    AST/block.hpp \
    AST/boolean.hpp \
    AST/decision.hpp \
    AST/declaration.hpp \
    AST/declaration_template.hpp \
    AST/expression.hpp \
    AST/expression_template.hpp \
    AST/ifelse.hpp \
    AST/ifrest.hpp \
    AST/jump.hpp \
    AST/print.hpp \
    AST/return.hpp \
    AST/statement.hpp \
    AST/unop.hpp \
    AST/variable.hpp \
    AST/variable_template.hpp \
    AST/while.hpp \
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
