#ifndef AST_CLASSES_HPP
#define AST_CLASSES_HPP
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <array>
using namespace std;
const int MAX_LINES = 100;

//CACHE
class CacheList;
class CacheNode;

enum types {
    expression = 0,
    statement = 1
};

enum subtypes {
    block = 0,
    neg = 1,
    ifelse = 2,
    ifrest = 3,
    while_loop = 4,
    binop = 5,
    variable = 6,
    declaration = 7,
    assignment = 8,
    return_stmt = 9
};

//AST
class AST {
public :
    AST();
    ~AST();
    virtual types get_type(); // Statement or Expression
    virtual subtypes get_subtype(); // Block, Declaration, UnOp, BinOp, ...
};
class Block; //one-line declaration, to prevent errors, as Statement needs Block and Block needs statement
class Variable;
class Declaration;
class Expression;
class IfRest;

//STATEMENT
class Statement : public AST {
public :
    Statement();
    ~Statement();
    virtual types get_type();
    virtual Variable* get_variable();
    virtual string get_name();
    virtual Expression* get_condition();
    Block* block_stmt;
    IfRest* else_stmt;
    virtual Expression* get_assign_exp();
    virtual double get_assign_value();
};

//BLOCK
class Block : public Statement {
public :
    Block();
    ~Block();
    subtypes get_subtype();
    list<Statement*>* get_statements();
    CacheList* variables;
    Block* parent_block; //nullptr if it is the program block
    int num_statements();
protected:
    list<Statement*>* statements; // list of statements in the block
};

//EXPRESSION
enum exp_type {
    boolean = 0,
    number = 1 //always a double

};

class Expression : public AST {
public :
    Expression();
    ~Expression();
    types get_type();
    virtual double get_value();
    virtual exp_type get_exp_type();
    virtual string get_text();
};


//UNARY OPERATION
class Negation : public Expression {
public :
    Negation();
    Negation(Expression* exp);
    ~Negation();
    subtypes get_subtype();
    exp_type get_exp_type();
    Expression* get_expression();
    void set_expression(Expression* exp);
    double get_value();
    string get_text();
private :
    Expression* expression;
};

//BINARY OPERATIONS
class BinOp : public Expression {
public :
    BinOp();
    ~BinOp();
    subtypes get_subtype();
    void set_left_exp(Expression* exp);
    void set_right_exp(Expression* exp);
    Expression* get_left_exp();
    Expression* get_right_exp();
    Expression* left_exp;
    Expression* right_exp;
};

class Addition : public BinOp {
public :
    Addition();
    Addition(Expression* l_e, Expression* r_e);
    ~Addition();
    public : double get_value();
    exp_type get_exp_type();
    string get_text();
};

class Subtraction : public BinOp {
public :
    Subtraction();
    Subtraction(Expression* l_e, Expression* r_e);
    ~Subtraction();
    double get_value();
    exp_type get_exp_type();
    string get_text();
};

class Multiplication : public BinOp {
public :
    Multiplication();
    Multiplication(Expression* l_e, Expression* r_e);
    ~Multiplication();
    double get_value();
    exp_type get_exp_type();
    string get_text();
};

class Division : public BinOp {
public :
    Division();
    Division(Expression* l_e, Expression* r_e);
    ~Division();
    double get_value();
    exp_type get_exp_type();
    string get_text();
};

class Mthan : public BinOp {
public :
    Mthan();
    Mthan(Expression* l_e, Expression* r_e);
    ~Mthan();
    double get_value();
    exp_type get_exp_type();
    string get_text();
};

class Lthan : public BinOp {
public :
    Lthan();
    Lthan(Expression* l_e, Expression* r_e);
    ~Lthan();
    double get_value();
    exp_type get_exp_type();
    string get_text();
};

class Leq : public BinOp {
public :
    Leq();
    Leq(Expression* l_e, Expression* r_e);
    ~Leq();
    double get_value();
    exp_type get_exp_type();
    string get_text();
};

class Meq : public BinOp {
public :
    Meq();
    Meq(Expression* l_e, Expression* r_e);
    ~Meq();
    double get_value();
    exp_type get_exp_type();
    string get_text();
};

class Eqeq : public BinOp {
public :
    Eqeq();
    Eqeq(Expression* l_e, Expression* r_e);
    ~Eqeq();
    double get_value();
    exp_type get_exp_type();
    string get_text();
};

class AndOp : public BinOp {
public :
    AndOp();
    AndOp(Expression* l_e, Expression* r_e);
    ~AndOp();
    double get_value();
    exp_type get_exp_type();
    string get_text();
};

class OrOp : public BinOp {
public :
    OrOp();
    OrOp(Expression* l_e, Expression* r_e);
    ~OrOp();
    double get_value();
    exp_type get_exp_type();
    string get_text();
};

class Variable : public Expression {
public :
    Variable();
    Variable(string n, double v);
    Variable(string n, bool v);
    ~Variable();
    void set_name(std::string n);
    void set_value(bool val);
    void set_value(double val);
    std::string get_name();
    double get_value();
    exp_type get_exp_type();
    subtypes get_subtype();
    string get_text();
protected:
    string name;
    double value = 0;
    exp_type type;
};

/*
//STATEMENT
class Statement : public AST {
protected : Statement();
protected : ~Statement();
std::string get_type(){return "Statement";};
};
*/
/*
class Block : public AST{
public :
    Block();
   ~Block();
    string get_type(){return "Block";};
protected:
    list<Statement> statements; // list of statements in the block
    std::map<char, char> variables; //this is the Cache and will be changed
    Block* parent_block; //nullptr if it is the program block
};
*/

class Declaration : public Statement {
public:
    Declaration();
    ~Declaration();
    void set_variable(Variable* var){variable = var;};
    double get_value(){return variable->get_value();};
    void set_value(double v){variable->set_value(v);};
    void set_value(bool v){variable->set_value(v);};
    Variable* get_variable(){return variable;};
    subtypes get_subtype(){return declaration;};
  //void add_variable_to_list(){Block variables; variables.insert({variable, value});};
protected:
    Variable* variable;
};

class Assignment : public Statement {
public:
    Assignment();
    ~Assignment();
    Variable* get_variable(){return variable;};
    Expression* get_assign_exp(){return exp;};
    double get_assign_value(){return exp->get_value();};
    void set_variable(Variable* v){variable = v;};
    void set_assign_expression(Expression* e){exp = e;};
    subtypes get_subtype(){return assignment;};
protected:
    //the Assigment is of form Variable = Expression
    //the value of the expression is supposed to be added straight to the Cache and not kept in this object
    //When we do the walker/variable tracking maybe we will need to add another argument
    //in this object that keeps Variable/Expression.
    Variable* variable;
    Expression* exp; //expression is the value the variable is assigned
};

class Return : public Statement {
    Return();
    ~Return();
    void set_exp(Expression* e){exp = e;};
    Expression* get_exp(){return exp;};
    subtypes get_subtype(){return return_stmt;};
private:
    Expression* exp;
};

//DECISIONS
class Decision : public Statement {
public :
    Decision();
    Decision(Expression* c);
    ~Decision();
    void set_condition(Expression* c);
    Expression* get_condition();
    double get_value();
    bool is_true();
protected:
    Expression* condition;
};

class IfRest : public Statement {
public:
    IfRest();
    IfRest(Block* b);
    ~IfRest();
    Block* get_block_stmt();
    void set_num_stmt(int n);
    void set_block_stmt(Block* stmt);
    subtypes get_subtype();
    int num_stmt;
};

class IfElse : public Decision {
public:
    IfElse();
    IfElse(Block* block, IfRest* else_stmt);
    ~IfElse();
    void set_condition(Expression* c);
    Expression* get_condition();
    void set_else_stmt(IfRest* stmt);
    IfRest* get_else_stmt();
    subtypes get_subtype();
};

class While : public Decision {
public:
    While();
    While(Expression* c, Block* b);
    ~While();
    void set_condition(Expression* c);
    Expression* get_condition();
    Block* get_block_stmt();
    void set_block_stmt(Block* stmt);
    subtypes get_subtype();
};
//Cache
/* Cache will be stored as a dictionary which contains a linked list. We chose this format as we do not have to decide how big the arrays need to be */

struct Value{
    double value;
    Value* prev;
    Value* next;
};

class ValuesList {
public:
    ValuesList();
    ValuesList(Value* h, Value* t);
    ~ValuesList();
    Value* get_head();
    Value* get_tail();
    void set_head(Value* h);
    void set_tail(Value* t);
    void add_value(Value* v);
    bool is_empty(); //fill in
    double get_last_value();
private:
    Value* head;
    Value* tail;
};

class Cache{
public:
    Cache(int number);
    ~Cache();
    void new_var(std::string var, int num, double value);
    ValuesList* get_var(std::string var);
    void add_new_value(std::string var, Value* value, int line);
    double get_previous_value(std::string var, int line);


private:
    int num_lines;
    std::map<std::string, ValuesList*> *variables[MAX_LINES];
};

enum chart_shape {
    rectangle = 0,
    diamond = 1,
    circle = 2
};

struct flowchart {
    chart_shape shape;
    string text;
    int first_block; // num of stmts in the first block (if in if and the only block in while)
    int second_block; // num of stmts in else
};


#endif // AST_CLASSES_HPP
