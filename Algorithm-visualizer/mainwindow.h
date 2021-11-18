#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtGui>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow ui;

};

class Program {
    Program();
    ~Program();
    //list of statements or the
    //program block - not sure yet
};

class Block {
    Block();
    ~Block();
    //list of statements
};

class Statement {
    Statement();
    ~Statement();
};

class Expression {
  Expression();
  ~Expression();
};

enum var_type {
    string = 0,
    integer = 1,
    character = 2,
    floating_point = 3

};

enum un_op {
    negation = 0,
    plusplus = 1
    //inverse = 2 (if we add this as a unary operation for number -> -number)
};

enum bin_op {
    conjunction = 0,
    disjunction = 1,
    addition = 2,
    subtraction = 3,
    multiplication = 4,
    division = 5,
    lthan = 6,
    mthan = 7,
    leq = 8,
    meq = 9,
    eq = 10,
    eqeq = 11
};

class Declaration : Statement {
    Declaration();
    ~Declaration();
    //int x = 7, bool y = False
    //attributes:
    //name + value of the variable or Variable + sth
};

class Assignment : Statement {
    Assignment();
    ~Assignment();
    //x = 5; x = y
};

class Return : Statement {
    Return();
    ~Return();
    //attribute: expression being returned
};

class Print : Statement {
    Print();
    ~Print();
    //attirbute: expression to be printed
};

class Jump : Statement {
  Jump();
  Jump(char value);
  ~Jump();
  void set_value();
  private:
    char value; // values are CONT or BREAK
};

class IfElse : Statement {
    IfElse();
    ~IfElse();
    //attributes: condition(expression), IfRest
};

class IfRest : Statement {
   IfRest();
   ~IfRest();
   //atrributes: a block, or another IfElse
};

class While : Statement {
    While();
    ~While();
    //attributes: condition, block
};

class Variable : Expression {
    Variable();
    ~Variable();
private:
    char name;
    var_type type;
};

class UnOp : Expression {
    UnOp();
    ~UnOp();
private:
    un_op operation;
    Expression expression;
};

class BinOp : Expression {
    BinOp();
    ~BinOp();
private:
    bin_op operation;
    Expression left_exp;
    Expression right_exp;
};

class Boolean : Expression {
    //not sure if this is necessary but putting
    //it down for now
    Boolean();
    ~Boolean();
private:
    bool value;
};

#endif // MAINWINDOW_H
