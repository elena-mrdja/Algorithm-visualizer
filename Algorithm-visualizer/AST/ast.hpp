#ifndef AST_H
#define AST_H

#include <string>
#include <iostream>
#include <QAbstractItemModel>

/*
class AST : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit AST(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};
*/

enum var_type {
    unknown_var_type = 0,
    string = 1,
    integer = 2,
    character = 3,
    floating_point = 4

};

enum un_op {
    unknown_un_op = 0,
    negation = 1,
    plusplus = 2
    //inverse = 2 (if we add this as a unary operation for number -> -number)
};

enum bin_op {
    unknown_bin_op = 0,
    conjunction = 1,
    disjunction = 2,
    addition = 3,
    subtraction = 4,
    multiplication = 5,
    division = 6,
    lthan = 7,
    mthan = 8,
    leq = 9,
    meq = 10,
    eq = 11,
    eqeq = 12
};

enum jump_type {
    unknown_jump_type = 0,
    br = 1,
    cont = 2
};

//AST CLASS

class AST {
protected : AST();
protected : ~AST();
private:
    std::map<char, char> variables;
};

class Statement : AST {
protected : Statement();
protected : ~Statement();
};

enum expression_type {
    unknown_expression_type = 0
};

class Expression : AST {
protected : Expression();
protected : Expression(expression_type t) {
        type = t;
    };
    ~Expression();
private:
    expression_type type = unknown_expression_type;
};

class Block : Statement {
protected : Block();
protected : ~Block();
    //list of statements
};


class Declaration : Statement {
public:
    Declaration();
    ~Declaration();
    void set_var_type(var_type t){type = t;};
    std::string get_var_type(){
        switch(type) {
        case 0: return "unknown variable type";
        case 1: return "string";
        case 2: return "integer";
        case 3: return "char";
        case 4: return "floating_point";
        }
    }
    char get_value(){return value;};
    void set_value(char v){value = v;};


private:
    var_type type = unknown_var_type;
    char value;
    //int x = 7, bool y = False
    //attributes:
    //name + value of the variable or Variable + sth
};

class Assignment : Statement {
    public:
    Assignment();
    ~Assignment();
    Expression* get_value(){return value;};
    void set_value(Expression* v){value= v;}
    std::string get_name(){return name;};
    void set_name(std::string n){name= n;}
    //x = 5; x = y
private:
    std::string name;
    Expression* value;
};

class Return : Statement {
    Return();
    ~Return();
    void set_exp(Expression* e){exp = e;};
    Expression* get_exp(){return exp;};
private:
    Expression* exp;
};

class Print : Statement {
    Print();
    ~Print();
    void set_exp(Expression* e){exp = e;};
    Expression* get_exp(){return exp;};
    //attribute: expression to be printed
private:
    Expression* exp;
};

class Jump : Statement {
    Jump();
    Jump(char value);
    ~Jump();
    void set_value(jump_type v){value = v;};
    std::string get_value(){
        switch(value) {
        case 0: return "unknown jump type";
        case 1: return "break";
        case 2: return "continue";
        }
  };
private:
    jump_type value = unknown_jump_type;
};

class IfRest : Statement {
public:
   IfRest();
   ~IfRest();
   Block* get_block_stmt(){return block_stmt;};
   void set_block_stmt(Block* stmt){block_stmt = stmt;};
   //atrributes: a block, or another IfElse
private:
    Block* block_stmt;
};

class IfElse : Statement {
    IfElse();
    ~IfElse();
    //attributes: condition(expression), IfRest
    void set_condition(Expression* c){condition = c;};
    Expression* get_condition(){return condition;};
    void set_else_stmt(IfRest* stmt){else_stmt = stmt;};
    IfRest* get_else_stmt(){return else_stmt;};
private:
    Expression* condition;
    IfRest* else_stmt;
};

class While : Statement {
public:
    While();
    ~While();
    void set_condition(Expression* c){condition = c;};
    Expression* get_condition(){return condition;};
    Block* get_block_stmt(){return block_stmt;};
    void set_block_stmt(Block* stmt){block_stmt = stmt;};

    //attributes: condition, block
private:
    Expression* condition;
    Block* block_stmt;
};

class Variable : Expression {
    Variable();
    ~Variable();
    void set_name(char n){name = n;};
    void set_type(var_type t){type = t;};
    std::string get_name(){return name;};
    var_type get_type(){return type;};

private:
    std::string name;
    var_type type = unknown_var_type;
};

class UnOp : Expression {
    UnOp();
    ~UnOp();
    void set_operation(un_op op){operation = op;};
    void set_expression(Expression* e){expression = e;};
    un_op get_operation(){return operation;};
    Expression* get_expression(){return expression;};
private:
    un_op operation = unknown_un_op;
    Expression* expression;
};

class BinOp : Expression {
    BinOp();
    ~BinOp();
    void set_operation(bin_op op){operation = op;};
    void set_left_expression(Expression* l_e){left_exp = l_e;};
    void set_right_expression(Expression* r_e){right_exp = r_e;};
    std::string get_operation(){
        switch(operation) {
        case 0: return "unknown binary operation";
        case 1: return "conjunction";
        case 2: return "disjunction";
        case 3: return "addition";
        case 4: return "substraction";
        case 5: return "multiplication";
        case 6: return "division";
        case 7: return "lthan";
        case 8: return "mthan";
        case 9: return "leq";
        case 10: return "meq";
        case 11: return "eq";
        case 12: return "eqeq";
        }
    }
    Expression* get_left_expression(){return left_exp;};
    Expression* get_right_expression(){return right_exp;};
private:
    bin_op operation = unknown_bin_op;
    Expression* left_exp;
    Expression* right_exp;
};

class Boolean : Expression {
    //not sure if this is necessary but putting
    //it down for now
    Boolean();
    ~Boolean();
    void set_value(bool v){value = v;};
    bool is_true(){return value;};
private:
    bool value;
};

#endif
