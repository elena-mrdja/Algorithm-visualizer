#ifndef AST_H
#define AST_H

#include <QAbstractItemModel>

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

//AST CLASS

class AST {
    AST();
    ~AST();
    void set_left_child(AST* lc){left_child = lc;};
    AST* get_left_child(){return left_child;};
    void set_right_child(AST* rc){right_child = rc;};
    AST* get_right_child(){return right_child;};
    void set_parent(AST* par){parent = par;};
    AST* get_parent(){return parent;};
private:
    AST* left_child;
    AST* right_child;
    AST* parent;
};

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
};

//THESE WILL BE POTENTIALLY USEFUL FOR CLASSIFYING THINGS WHILE READING THE AST

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

class Declaration : Statement {
public:
    Declaration();
    ~Declaration();
    void set_var_type(var_type t){type = t;};
    var_type get_var_type(){return type};
    char get_value(){return value;};
    void set_value(char v){value = v;};


private:
    var_type type;
    char value;
    //int x = 7, bool y = False
    //attributes:
    //name + value of the variable or Variable + sth
};

class Assignment : Statement {
    public:
    Assignment();
    ~Assignment();
    char get_value(){return value;};
    void set_value(char v){value= v;}
    char get_name(){return name;};
    void set_name(char n){name= n;}

    //x = 5; x = y
private:
    char name; 
    char value;
};

class Return : Statement {
    Return();
    ~Return();
    void set_exp(Expression e){exp = e;};
    Expression get_exp(){return exp;};
    //attribute: expression being returned
private:
    Expression exp;
};

class Print : Statement {
    Print();
    ~Print();
    void set_exp(Expression e){exp = e;};
    Expression get_exp(){return exp;};
    //attribute: expression to be printed
private:
    Expression exp;
};

class Jump : Statement {
public:
  Jump();
  Jump(char value);
  ~Jump();
  void set_value(char v){value = v;};
  char get_value(){return value;};

private:
    char value; // values are CONT or BREAK
};

class IfElse : Statement {
    IfElse();
    ~IfElse();
    //attributes: condition(expression), IfRest
    void set_condition(Expression c){condition = c;};
    Expression get_condition(){return condition;};
    void set_else_stmt(IfRest stmt){else_stmt = stmt;};
    IfRest get_else_stmt(){return else_stmt;};
private:
    Expression condition;
    IfRest else_stmt;
};

class IfRest : Statement {
public:
   IfRest();
   ~IfRest();
   Block get_block_stmt(){return block_stmt;};
   void set_block_stmt(Block stmt){block_stmt = stmt;};
   //atrributes: a block, or another IfElse
private:
    Block block_stmt;
};

class While : Statement {
public:
    While();
    ~While();
    void set_condition(Expression c){condition = c;};
    Expression get_condition(){return condition;};
    Block get_block_stmt(){return block_stmt;};
    void set_block_stmt(Block stmt){block_stmt = stmt;};

    //attributes: condition, block
private:
    Expression condition;
    Block block_stmt;
};

class Variable : Expression {
    Variable();
    ~Variable();
    void set_name(char n){name = n;};
    void set_type(var_type t){type = t;};
    char get_name(){return name;};
    var_type get_type(){return type;};

private:
    char name;
    var_type type;
};

class UnOp : Expression {
    UnOp();
    ~UnOp();
    void set_operation(un_op op){operation = op;};
    void set_expression(Expression e){expression = e;};
    un_op get_operation(){return operation;};
    Expression get_expression(){return expression;};
private:
    un_op operation;
    Expression expression;
};

class BinOp : Expression {
    BinOp();
    ~BinOp();
    void set_operation(bin_op op){operation = op;};
    void set_left_expression(Expression l_e){left_exp = l_e;};
    void set_right_expression(Expression r_e){right_exp = r_e;};
    bin_op get_operation(){return operation;};
    Expression get_left_expression(){return left_exp;};
    Expression get_right_expression(){return right_exp;};
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
    void set_value(bool v){value = v;};
    bool get_value(){return value;};
private:
    bool value;
};

#endif // AST_H
