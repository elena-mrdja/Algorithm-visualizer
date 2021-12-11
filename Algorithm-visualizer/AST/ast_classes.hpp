#ifndef AST_CLASSES_HPP
#define AST_CLASSES_HPP
#include <string>
#include <iostream>
#include <list>
#include <map>
using namespace std;

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
    types get_type();
    Variable* get_variable();
    string get_name();
    Expression* get_condition();
    Block* block_stmt;
    IfRest* else_stmt;
};

//BLOCK
class Block : public Statement {
public :
    Block();
    ~Block();
    subtypes get_subtype();
    list<Statement> statements; // list of statements in the block
    CacheList* variables;
    Block* parent_block; //nullptr if it is the program block
    int num_statements();
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
    virtual double get_value() = 0;
    virtual exp_type get_exp_type() = 0;
    string get_text();
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
    void set_variable(Variable var){variable = var;};
    double get_value(){return variable.get_value();};
    void set_value(double v){variable.set_value(v);};
    void set_value(bool v){variable.set_value(v);};
    Variable get_variable(){return variable;};
    subtypes get_subtype(){return declaration;};
  //void add_variable_to_list(){Block variables; variables.insert({variable, value});};
protected:
    Variable variable;
};

class Assignment : public Statement {
public:
    Assignment();
    ~Assignment();
    string get_name(){return var_name;};
    void set_name(string n){var_name = n;};
    subtypes get_subtype(){return assignment;};
protected:
    //the Assigment is of form Variable = Expression
    //the value of the expression is supposed to be added straight to the Cache and not kept in this object
    //When we do the walker/variable tracking maybe we will need to add another argument
    //in this object that keeps Variable/Expression.
    string var_name; //at this point we know that the variable is in Cache
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
class VarNode; //one line declaration
class CacheNode{
public:
    CacheNode(); // Empty constructor
    CacheNode(double v, CacheNode* p){ //Constructor when you now the value and the previous node
        value = v;
        prev = p;

    };
    CacheNode( CacheNode* p){ //Constructor to create an empty linked node
        prev = p;

    };
    CacheNode* get_prev(){
        return prev;
    };
    CacheNode* get_next(){
        return next;
    };
    void set_prev(CacheNode* p){
        prev = p;
    };
    void set_next(CacheNode* n){
        next = n;
    };
    double get_value(){
        return value;
    };
    void set_value(double v){
        value = v;
    };
    ~CacheNode();
private:
    //Previous node
    CacheNode* prev;
    //Next node
    CacheNode* next;
    //Value stored at this node
    double value;
    VarNode* variables;
    string name;

};

class CacheList{
public:
    CacheList();
    // You initialize a CacheList for a new variable, size of number of lines, where each node represents a the value of x at a certain line
    CacheList(int lines){
        // Declare the head
        CacheNode new_head = CacheNode();
        head = &new_head;
        CacheNode* current = head;
        for (int i = 0; i<lines - 1; i++){
           // Create an empty node linked to the previous one
           CacheNode new_node = CacheNode(current);
           // Link the previous to the new node
           current->set_next(&new_node);
           current = &new_node;
        }
    };
    CacheNode* get_head(){
        return head;
    };
    CacheNode* get_tail(){
        return tail;
    };
    void set_head(CacheNode* h){
        head = h;
    };
    void set_tail(CacheNode* t){
        tail = t;
    };
    CacheNode* get(int i){
        // return the node at postion i
        CacheNode* current = head;
        for (int j = 0; j<i; j++){
            current = current->get_next();
    }
        return current;
    }
    void add_value(double v, int i){
        // set the value at position i
        CacheNode* current = (*this).get(i);
        current->set_value(v);
    };
    ~CacheList();
private:
    CacheNode* head;
    CacheNode* tail;
};

class VarNode{
public:
    VarNode();
    VarNode(string n, double v){
        name = n;
        value = v;
    };
    ~VarNode();
    void set_name(string n){name = n;};
    void set_value(double v){value = v;};
    string get_name(){return name;};
    double get_value(){return value;};
private:
    string name;
    double value;
    VarNode* next;
    CacheNode* line;
};


class Cache; //TBC

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

flowchart* read_statement(Statement* stmt, int i, list<CacheList*> variables){
    //returns a flowchart corresponding to the given statement
    //this function is supposed to be used within the walker i will keep the line of the statement being read
    //(so, if stmt is in the 20th line, i = 20)
    subtypes stmt_type = stmt->get_subtype();
    flowchart* chart;
    if (stmt_type == declaration){
        chart->shape = rectangle;
        chart->text = "Declare " + stmt->get_variable()->get_name();
        VarNode var = VarNode(stmt->get_variable()->get_name(), stmt->get_variable()->get_value());
        return chart;
    }
    if(stmt_type == assignment){
        chart->shape = rectangle;
        chart->text = "Assign " + stmt->get_name();
        return chart;
    };
    if(stmt_type == ifelse){
        chart->shape = diamond;
        chart->text = stmt->get_condition()->get_text();
        chart->first_block = stmt->block_stmt->num_statements();
        chart->second_block = stmt->else_stmt->num_stmt;
        return chart;
    };
    if(stmt_type == while_loop){
        chart->shape = diamond;
        chart->text = stmt->get_condition()->get_text();
        chart->first_block = stmt->block_stmt->num_statements();
        return chart;
    };
    return chart;
};

void draw_flowchart(Block* block){
    int n = block->num_statements();
    //initialize CacheList of length n
    for (int i = 0; i < n; i++){
        //flowchart* chart = read_statement(block->statements[i], i);
    };
};





























#endif // AST_CLASSES_HPP
