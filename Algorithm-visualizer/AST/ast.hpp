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
private:
    AST* left_child;
    AST* right_child;
    AST* parent;
};

class NodeBinOp(AST) {
    NodeBinOp();
    ~NodeBinOp();
private:
    bin_op operation;
};

class NodeUnOp(AST) {
    NodeUnOp();
    ~NodeUnOp();
private:
    un_op operation;
};

class NodeVar(AST) {
    NodeVar();
    ~NodeVar();
private:
    var_type type;
    char var_name;
};
    
class NodeIf(AST) {
    NodeIf();
    ~NodeIf();
private:
    AST condition;
};
    
class NodeIf(AST) {
    NodeIf();
    ~NodeIf();
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
private:
    Expression exp;
};

class Print : Statement {
    Print();
    ~Print();
    //attirbute: expression to be printed
private:
    Expression exp;
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
private:
    Expression condition;
    IfRest else_stmt;
};

class IfRest : Statement {
   IfRest();
   ~IfRest();
   //atrributes: a block, or another IfElse
private:
    Block block_stmt;
};

class While : Statement {
    While();
    ~While();
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
    Expression get_right_expression(){return left_exp;};
    Expression get_left_expression(){return right_exp;};
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
