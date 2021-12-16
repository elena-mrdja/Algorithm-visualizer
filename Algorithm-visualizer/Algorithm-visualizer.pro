QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AST/assignment.cpp \
    AST/ast.cpp \
    AST/ast_builder.cpp\
    AST/ast_classes.cpp \
    AST/ast_classes.cpp\
    AST/binop.cpp \
    AST/block.cpp \
    AST/boolean.cpp \
    AST/class.cpp \
    AST/decision.cpp \
    AST/declaration.cpp \
    AST/expression.cpp \
    AST/first_graphics_test.cpp \
    AST/ifelse.cpp \
    AST/ifrest.cpp \
    AST/jump.cpp \
    AST/print.cpp \
    AST/shapes.cpp \
    AST/statement.cpp \
    AST/tracking.cpp \
    AST/unop.cpp \
    AST/variable.cpp \
    AST/while.cpp \
    GUI/codecell.cpp \
    GUI/gui.cpp \
    GUI/varcell.cpp \
    GUI/viewer.cpp \
    Parsing/parsing.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    AST/assignment.hpp \
    AST/ast.hpp \
    AST/ast_builder.hpp\
    AST/ast_classes.hpp\
    AST/binop.hpp \
    AST/block.hpp \
    AST/boolean.hpp \
    AST/class.hpp \
    AST/decision.hpp \
    AST/declaration.hpp \
    AST/expression.hpp \
    AST/ifelse.hpp \
    AST/ifrest.hpp \
    AST/jump.hpp \
    AST/print.hpp \
    AST/shapes.hpp \
    AST/statement.hpp \
    AST/tracking.hpp \
    AST/unop.hpp \
    AST/variable.hpp \
    AST/while.hpp \
    GUI/codecell.hpp \
    GUI/gui.hpp \
    GUI/varcell.hpp \
    GUI/viewer.hpp \
    Parsing/parsing.hpp \
    main.hpp \
    mainwindow.hpp \


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
