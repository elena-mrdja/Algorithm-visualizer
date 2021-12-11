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

//AST
class AST {
public :
    AST();
    ~AST();
    virtual string get_type(); // Statement or Expression
    virtual string get_subtype(); // Block, Declaration, UnOp, BinOp, ...
    void set_prev(AST* previous){prev = previous;};
    void set_next(AST* following){next = following;};
    AST* prev = nullptr;
    AST* next = nullptr;
};
class Block; //one-line declaration, to prevent errors, as Statement needs Block and Block needs statement
class Variable;
class Declaration;
class Expression;

//STATEMENT
class Statement : public AST {
public :
    Statement();
    ~Statement();
    string get_type(){return "Statement";};
    Block* block; //reference to its block (to be able to access Cache)
    Variable* get_variable();
    string get_name();
    Expression* get_condition();
    Block* else_stmt;
};

//BLOCK
class Block : public Statement {
public :
    Block();
    ~Block();
    string get_subtype(){return "Block";};
    list<Statement> statements; // list of statements in the block
    CacheList* variables;
    Block* parent_block; //nullptr if it is the program block
    int num_statements(){
        list<Statement>::iterator i;
        int j = 0;
        for(i = statements.begin(); i != statements.end(); ++i){
               j++;
        }
        return j;
    };
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
    string get_type(){return "Expression";};
    virtual double get_value() = 0;
    virtual exp_type get_exp_type() = 0;
    string get_text();
};


//UNARY OPERATION
class Negation : public Expression {
public :
    Negation();
    ~Negation();
    string get_subtype(){return "UnOp";};
    exp_type get_exp_type(){return boolean;};
    Expression* get_expression(){return expression;};
    void set_expression(Expression* exp){expression = exp;};
    double get_value(){
        if (expression->get_value() != 0) return 0;
        return 1;
    };
    string get_text(){return "not(" + expression->get_text() + ")";};
private :
    Expression* expression;
};

//BINARY OPERATIONS
class BinOp : public Expression {
public :
    BinOp();
    ~BinOp();
    string get_subtype(){return "BinOp";};
    void set_left_exp(Expression* exp){left_exp = exp;};
    void set_right_exp(Expression* exp){right_exp = exp;};
    Expression* get_left_exp(){return left_exp;};
    Expression* get_right_exp(){return right_exp;};
    Expression* left_exp;
    Expression* right_exp;
};

class Addition : public BinOp {
public :
    Addition();
    ~Addition();
    public : double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean) {return 0;};
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        return left_exp->get_value() + right_exp->get_value();
    };
    exp_type get_exp_type(){return number;};
    string get_text(){return left_exp->get_text() + " + " + right_exp->get_text();};
};

class Subtraction : public BinOp {
public :
    Subtraction();
    ~Subtraction();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        return left_exp->get_value() - right_exp->get_value();
    };
    exp_type get_exp_type(){return number;};
    string get_text(){return left_exp->get_text() + " - " + right_exp->get_text();};
};

class Multiplication : public BinOp {
public :
    Multiplication();
    ~Multiplication();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        return left_exp->get_value() * right_exp->get_value();
    };
    exp_type get_exp_type(){return number;};
    string get_text(){return left_exp->get_text() + " * " + right_exp->get_text();};
};

class Division : public BinOp {
public :
    Division();
    ~Division();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        if (right_exp->get_value() == 0)
        {
            cout << "Division by zero";
            return 0;
        };
        return left_exp->get_value() / right_exp->get_value();
    };
    exp_type get_exp_type(){return number;};
    string get_text(){return left_exp->get_text() + " / " + right_exp->get_text();};
};

class Mthan : public BinOp {
public :
    Mthan();
    ~Mthan();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        if (left_exp->get_value() > right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
    string get_text(){return left_exp->get_text() + " > " + right_exp->get_text();};
};

class Lthan : public BinOp {
public :
    Lthan();
    ~Lthan();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        if (left_exp->get_value() < right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
    string get_text(){return left_exp->get_text() + " < " + right_exp->get_text();};
};

class Leq : public BinOp {
public :
    Leq();
    ~Leq();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        if (left_exp->get_value() <= right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
    string get_text(){return left_exp->get_text() + " <= " + right_exp->get_text();};
};

class Meq : public BinOp {
public :
    Meq();
    ~Meq();
    double get_value(){
        if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
        {
            cout << "One of the expressions is a boolean";
            return 0;
        };
        if (left_exp->get_value() >= right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
    string get_text(){return left_exp->get_text() + " >= " + right_exp->get_text();};
};

class Eqeq : public BinOp {
public :
    Eqeq();
    ~Eqeq();
    double get_value(){
        if (left_exp->get_value() == right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
    string get_text(){return left_exp->get_text() + " == " + right_exp->get_text();};
};

class AndOp : public BinOp {
public :
    AndOp();
    ~AndOp();
    double get_value(){
        if (left_exp->get_value() && right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
    string get_text(){return left_exp->get_text() + " and " + right_exp->get_text();};
};

class OrOp : public BinOp {
public :
    OrOp();
    ~OrOp();
    double get_value(){
        if (left_exp->get_value() || right_exp->get_value()) return 1;
        return 0;
    };
    exp_type get_exp_type(){return boolean;};
    string get_text(){return left_exp->get_text() + " or " + right_exp->get_text();};
};

class Variable : public Expression {
public :
    Variable();
    ~Variable();
    void set_name(std::string n){name = n;};
    void set_value(bool val){
        if (val) value = 1;
        else value = 0;
        type = boolean;
    };
    void set_value(double val){
        value = val;
        type = number;
    };
    std::string get_name(){return name;};
    double get_value(){return value;};
    exp_type get_exp_type(){return type;};
    string get_subtype(){return "Variable";};
    string get_text(){return name;};
protected:
    std::string name;
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
    std::string get_subtype(){return "Declaration";};
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
    string get_subtype(){return "Assignment";};
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
    string get_subtype(){return "Return";};
private:
    Expression* exp;
};

//DECISIONS
class Decision : public Statement {
public :
    Decision();
    ~Decision();
    void set_condition(Expression* c){condition = c;};
    Expression* get_condition(){return condition;};
    double get_value(){
        if (condition->get_value()) return 1;
        return 0;
    };
    bool is_true(){
        if (get_value() == 1) return true;
        return false;
    };
protected:
    Expression* condition;
};

class IfRest : public Statement {
public:
   IfRest();
   ~IfRest();
   Block* get_block_stmt(){return block_stmt;};
   void set_block_stmt(Block* stmt){block_stmt = stmt;};
   string get_subtype(){return "IfRest";};
    Block* block_stmt;
};

class IfElse : public Decision {
public:
    IfElse();
    ~IfElse();
    //attributes: condition(expression), IfRest
    void set_condition(Expression* c){condition = c;};
    Expression* get_condition(){return condition;};
    void set_else_stmt(IfRest* stmt){else_stmt = stmt;};
    IfRest* get_else_stmt(){return else_stmt;};
    std::string get_subtype(){return "IfElse";};
protected:
    Block* block;
    IfRest* else_stmt;
};

class While : public Decision {
public:
    While();
    ~While();
    void set_condition(Expression* c){condition = c;};
    Expression* get_condition(){return condition;};
    Block* get_block_stmt(){return block_stmt;};
    void set_block_stmt(Block* stmt){block_stmt = stmt;};
    std::string get_subtype(){return "While";};
protected:
    Expression* condition;
    Block* block_stmt;
};
//Cache
/* Cache will be stored as a dictionary which contains a linked list. We chose this format as we do not have to decide how big the arrays need to be */
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
        prev =p;
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

void read_statement(Statement* stmt){
    //returns a flowchart corresponding to the given statement
    string stmt_type = stmt->get_subtype();
    flowchart chart;
    if (stmt_type == "Declaration"){
        chart.shape = rectangle;
        chart.text = "Declare " + stmt->get_variable()->get_name();

    }
    if(stmt_type == "Assignment"){
        chart.shape = rectangle;
        chart.text = "Assign " + stmt->get_name();
    };
    if(stmt_type == "IfElse"){
        chart.shape = diamond;
        chart.text = stmt->get_condition()->get_text();
        chart.first_block = stmt->block->num_statements();
        chart.second_block = stmt->else_stmt->num_statements();
    };
    if(stmt_type == "While"){
        chart.shape = diamond;
        chart.text = stmt->get_condition()->get_text();
        chart.first_block = stmt->block->num_statements();
    };
};



























#endif // AST_CLASSES_HPP
