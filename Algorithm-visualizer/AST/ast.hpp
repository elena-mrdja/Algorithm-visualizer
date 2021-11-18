#ifndef AST_H
#define AST_H

#include <QAbstractItemModel>
#include <string>
using namespace std;

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

<<<<<<< Updated upstream
=======
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

enum jump_type {
    jump = 0,
    continue = 1
};




//AST CLASS

class AST {
    AST();
    ~AST();
    string get_type() = 0; // Statement or Expression   (this is an abstract method which will be defined in subclasses Statement and Expression and inherited by every other subclass below)
    string get_subtype() = 0; // Block, Declaration, UnOp, BinOp, ...   (this is an abstract method which will be defined in subclasses Block, Declaration, ...)


//this whole rest of the class will probably be deleted
/*    void set_left_child(AST* lc){left_child = lc;};
    AST* get_left_child(){return left_child;};
    void set_right_child(AST* rc){right_child = rc;};
    AST* get_right_child(){return right_child;};
    void set_parent(AST* par){parent = par;};
    AST* get_parent(){return parent;};
private:
    AST* left_child;
    AST* right_child;
    AST* parent; */
};

/*
class NodeBinOp(AST) {
    NodeBinOp();
    ~NodeBinOp();
    void set_bin_op(bin_op op){operation = op};
    bin_op get_bin_op(){return operation;};
private:
    bin_op operation;
};
class NodeUnOp(AST) {
    NodeUnOp();
    ~NodeUnOp();
    void set_un_op(un_op op){operation = op;};
    un_op get_un_op(){return operation;};
private:
    un_op operation;
};
class NodeVar(AST) {
    NodeVar();
    ~NodeVar();
    void set_var_type(var_type vt){type = vt;};
    var_type get_var_type(return type;);
    void set_var_name(char vn){var_name = vn;};
    char get_var_name(){return var_name;};
private:
    var_type type;
    char var_name;
};

class NodeIf(AST) {
    NodeIf();
    ~NodeIf();
    void set_condition(AST a){condition = a;};
    AST get_condition(){return condition;};
private:
    AST condition;
}; */

class Statement : public AST {
    Statement();
    ~Statement();
    string get_type(){return "Statement";}
};

class Expression : public AST {
    Expression();
    ~Expression();
    string get_type(){return "Expression";}
};

class Block : public Statement {
    Block();
    ~Block();
    string get_subtype(){return "Block";} //moreover, get_type() is naturally inherited from class Statement and will return "Statetemnt" for Block objects.
    //list of statements
};


class Declaration : public Statement {
public:
    Declaration();
    ~Declaration();
    void set_var_type(var_type t){type = t;};
    var_type get_var_type(){
        if type == 0:
            return "string";
        elif type == 1:
            return "integer";
        elif type == 2:
            return "character";
        elif type == 3:
            return "floating_point";
    };
    char get_value(){return value;};
    void set_value(char v){value = v;};
    string get_subtype(){return "Declaration";}
private:
    var_type type;
    char value;
    //int x = 7, bool y = False
    //attributes:
    //name + value of the variable or Variable + sth
};

class Assignment : public Statement {
    public:
    Assignment();
    ~Assignment();
    Expression get_value(){return value;};
    void set_value(Expression v){value= v;}
    string get_name(){return name;};
    void set_name(string n){name= n;}
    string get_subtype(){return "Assignment";}
    //x = 5; x = y
private:
    string name;
    Expression value;
};

class Return : public Statement {
    Return();
    ~Return();
    void set_exp(Expression e){exp = e;};
    Expression get_exp(){return exp;};
    string get_subtype(){return "Return";}
private:
    Expression exp;
};

class Print : public Statement {
    Print();
    ~Print();
    void set_exp(Expression e){exp = e;};
    Expression get_exp(){return exp;};
    string get_subtype(){return "Print";}
    //attribute: expression to be printed
private:
    Expression exp;
};

class Jump : public Statement {
public:
    Jump();
    Jump(char value);
    ~Jump();
    void set_value(char v){value = v;};
    jump_type get_value(){
        if value == 0:
            return "jump";
        elif value == 1:
            return "continue";
    };
    string get_subtype(){return "Jump";}
private:
    jump_type value; // values are CONT or BREAK
};

class Decision : public Statement {
    Decision();
    ~Decision();
    void set_condition(Expression c){condition = c;};
    Expression get_condition(){return condition;};
private:
    Expression condition;
};

class IfElse : public Decision {
    IfElse();
    ~IfElse();
    void set_else_stmt(IfRest stmt){else_stmt = stmt;};
    IfRest get_else_stmt(){return else_stmt;};
    string get_subtype(){return "IfElse";}
    //attributes: condition(expression), IfRest
private:
    IfRest else_stmt;
};

class IfRest : public Statement {
public:
   IfRest();
   ~IfRest();
   Block get_block_stmt(){return block_stmt;};
   void set_block_stmt(Block stmt){block_stmt = stmt;};
   string get_subtype(){return "IfRest";}
   //atrributes: a block, or another IfElse
private:
    Block block_stmt;
};

class While : public Decision {
public:
    While();
    ~While();
    Block get_block_stmt(){return block_stmt;};
    void set_block_stmt(Block stmt){block_stmt = stmt;};
    string get_subtype(){return "While";}
    //attributes: condition, block
private:
    Block block_stmt;
};

class Variable : public Expression {
    Variable();
    ~Variable();
    void set_name(char n){name = n;};
    void set_type(var_type t){type = t;};
    string get_name(){return name;};
    var_type get_type(){
        if type == 0:
            return "string";
        elif type == 1:
            return "integer";
        elif type == 2:
            return "character";
        elif type == 3:
            return "floating_point";
    };
    string get_subtype(){return "Variable";}
private:
    string name;
    var_type type;
};

class UnOp : public Expression {
    UnOp();
    ~UnOp();
    void set_operation(un_op op){operation = op;};
    void set_expression(Expression e){expression = e;};
    un_op get_operation(){
        if operation == 0:
            return "negation";
        elif operation == 1:
            return "plusplus";
    };
    Expression get_expression(){return expression;};
    string get_subtype(){return "UnOp";}
private:
    un_op operation;
    Expression expression;
};

class BinOp : public Expression {
    BinOp();
    ~BinOp();
    void set_operation(bin_op op){operation = op;};
    void set_left_expression(Expression l_e){left_exp = l_e;};
    void set_right_expression(Expression r_e){right_exp = r_e;};
    bin_op get_operation(){
        if operation == 0:
            return "conjunction";
        elif operation == 1:
            return "disjunction";
        elif operation == 2:
            return "addition";
        elif operation == 3:
            return "substraction";
        elif operation == 4:
            return "multiplication";
        elif operation == 5:
            return "division";
        elif operation == 6:
            return "lthan";
        elif operation == 7:
            return "mthan";
        elif operation == 8:
            return "leq";
        elif operation == 9:
            return "meq";
        elif operation == 10:
            return "eq";
        elif operation == 11:
            return "eqeq";
    };
    Expression get_left_expression(){return left_exp;};
    Expression get_right_expression(){return right_exp;};
    string get_subtype(){return "BinOp";}
private:
    bin_op operation;
    Expression left_exp;
    Expression right_exp;
};

class Boolean : public Expression {
    //not sure if this is necessary but putting
    //it down for now
    Boolean();
    ~Boolean();
    void set_value(bool v){value = v;};
    bool is_true(){return value;};
    string get_subtype(){return "Boolean";}
private:
    bool value;
};

>>>>>>> Stashed changes
#endif // AST_H
