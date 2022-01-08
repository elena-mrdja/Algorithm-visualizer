#include "AlgoParser.h"
#include <string>
#include "iostream"
#include "iomanip"
#include "sstream"
#include <map>
#include <array>
using namespace std;
using namespace antlr4;
using namespace antlrcpptest;
// IMPORTANT DO NOT DELETE ANY FUNCTION!!! EVEN IF THEY ARE MARKED AS NO NEEDED

const int MAX_LINES = 100;

enum bin_ops {
    addition = 0,
    subtraction = 1,
    multiplication = 2,
    division = 3,
    modulo = 4,
    conj = 5,
    disj = 6,
    eqeq = 7,
    noteq = 8,
    lthan = 9,
    mthan = 10,
    leq = 11,
    meq = 12,
    unknown_binop = 13
};

enum un_ops {
    minusminus = 0,
    plusplus = 1,
    unknown_unop = 2
};

enum variable_type {
    var_int = 0,
    var_double = 1,
    var_bool = 2,
    var_char = 3,
    num = 4,
    unknown_var = 5
};

enum value_type {
    boolean = 0,
    double_value = 1,
    unknown_value_type = 2
};

enum stmt_type {
    declaration = 0,
    assignment = 1,
    ifelse = 2,
    ifrest = 3,
    while_loop = 4,
    unop = 5
};

enum exp_type {
    unop = 0,
    binop = 1,
    binop_exp = 2,
    neg = 3,
    variable = 4,
    number = 5,
    unknown_exp_type = 5
};

enum types {
    statement = 0,
    expression = 1,
    block = 2
};

class Cache;

struct BinOpExp{
    virtual exp_type get_exp_type(){return binop_exp;};
    virtual std::string get_operation();
    virtual BinOpExp* get_left_expression();
    virtual BinOpExp* get_right_expression();
    virtual std::string get_text();
    virtual value_type get_value_type();
    virtual double get_value(Cache* cache, int i);
    int num_blocks(){return 0;};
    int get_jump_length(){return 1;};
};

//the following three classes are for variable tracking
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
    void pop(){
        Value* t = get_tail();
        tail = t->prev;
    };
private:
    Value* head;
    Value* tail;
};

class Declaration;

class Cache{
public:
    Cache(int number);
    ~Cache();
    void new_var(Declaration* dec, int num);
    ValuesList* get_var(string var);
    void add_new_value(string var, Value* value, int line);
    double get_last_value(string name, int i){
        return variables[i][i][name]->get_tail()->value;
    };
    map<string, ValuesList*>* get_map(){return *variables;};

private:
    int num_lines;
    map<string, ValuesList*>* variables[MAX_LINES]; //MAX_LINES defined on the top of the file
};



class SingleOutput : public BinOpExp {
public:
    SingleOutput(AlgoParser::ExpContext* ctx);
    ~SingleOutput();
    exp_type get_exp_type(){
        if (val_type == num) return number;
        return variable;
    };
    string get_text(){return value;}; //returns the value as a string

    string get_operation(){return "none";}; //no needed
    BinOpExp* get_left_expression(){return nullptr;}; // no needed
    BinOpExp* get_right_expression(){return nullptr;}; //no needed
    variable_type get_var_type(){return val_type;}; // returns a type of a single output
                                                   // possible outputs: 'double', 'integer', 'boolean', 'variable'.
    int num_blocks(){return 0;};
    double get_value(Cache* cache, int i){
        //i is the line which the SingleOutput is in
        if (val_type == num) return stod(value);
        else {
            return cache->get_last_value(value, i);
        }
    }; //returns the value as a string <- IMPORTANT
    BinOpExp* get_result(){return nullptr;};
private:
    string value;
    variable_type val_type;
};

class BinOp : public BinOpExp{
public:
    BinOp(AlgoParser::ExpContext* ctx);
    ~BinOp();
    exp_type get_exp_type(){return binop;};
    string get_text(){
        if (left_exp->get_exp_type() == number or left_exp->get_exp_type() == variable) {
            if (right_exp->get_exp_type() == number or right_exp->get_exp_type() == variable)
            {
                return left_exp->get_text() + " " + get_operation() + " " + right_exp->get_text();
            }
            else {
                return left_exp->get_text() + " " + get_operation() + " (" + right_exp->get_text() + ")";
            }
        }
        else {
            if (right_exp->get_exp_type() == number or right_exp->get_exp_type() == variable) {
                return "(" + left_exp->get_text() + ") " + get_operation() + " " + right_exp->get_text();
            }
        }
        return "(" + left_exp->get_text() + ") " + get_operation() + " (" + right_exp->get_text() + ")";
    }; //returns an entire binOp line as a string (ex. output: '( 4.0 + x ) * 5')
    std::string get_operation(){ //returns binOp operation
        switch(operation) {
        case addition: return "+";
        case subtraction: return "-";
        case multiplication: return "*";
        case division: return "/";
        case modulo: return "%";
        case conj: return "&&";
        case disj: return "||";
        case eqeq: return "==";
        case noteq: return "!=";
        case lthan: return "<";
        case mthan: return ">";
        case leq: return "<=";
        case meq: return ">=";
        default: return "unknown binary operation";
        }
    };
    value_type get_value_type(){
        switch(operation) {
        case addition: return double_value;
        case subtraction: return double_value;
        case multiplication: return double_value;
        case division: return double_value;
        case modulo: return double_value;
        case conj: return boolean;
        case disj: return boolean;
        case eqeq: return boolean;
        case noteq: return boolean;
        case lthan: return boolean;
        case mthan: return boolean;
        case leq: return boolean;
        case meq: return boolean;
        default: return unknown_value_type;
        }
    };
    double get_value(Cache* cache, int i){
            switch(operation) {
            case addition: {
                if (left_exp->get_value_type() == boolean or right_exp->get_value_type() == boolean) {return 0;};
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                return left_exp->get_value(cache, i) + right_exp->get_value(cache, i);
            };
            case subtraction: {
                if (left_exp->get_value_type() == boolean or right_exp->get_value_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                return left_exp->get_value(cache, i) - right_exp->get_value(cache, i);
            };
            case multiplication: {
                if (left_exp->get_value_type() == boolean or right_exp->get_value_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                return left_exp->get_value(cache, i) * right_exp->get_value(cache, i);
            };
            case division: {
                if (left_exp->get_value_type() == boolean or right_exp->get_value_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                if (right_exp->get_value(cache, i) == 0)
                {
                    cout << "Division by zero";
                    return 0;
                };
                return left_exp->get_value(cache, i) / right_exp->get_value(cache, i);
            };
            case modulo: {
                if (left_exp->get_value_type() == boolean or right_exp->get_value_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                if (right_exp->get_value(cache, i) == 0)
                {
                    cout << "Division by zero";
                    return 0;
                };
                return (int)left_exp->get_value(cache, i) % (int)right_exp->get_value(cache, i);
            };
            case conj: {
                if (left_exp->get_value(cache, i) && right_exp->get_value(cache, i)) return 1;
                return 0;
            };
            case disj: {
                if (left_exp->get_value(cache, i) || right_exp->get_value(cache, i)) return 1;
                return 0;
            };
            case eqeq: {
                if (left_exp->get_value(cache, i) == right_exp->get_value(cache, i)) return 1;
                return 0;
            };
            case noteq: {
                if (left_exp->get_value(cache, i) != right_exp->get_value(cache, i)) return 1;
                return 0;
            };
            case lthan: {
                if (left_exp->get_value_type() == boolean or right_exp->get_value_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                if (left_exp->get_value(cache, i) < right_exp->get_value(cache, i)) return 1;
                return 0;
            };
            case mthan: {
                if (left_exp->get_value_type() == boolean or right_exp->get_value_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                if (left_exp->get_value(cache, i) > right_exp->get_value(cache, i)) return 1;
                return 0;
            };
            case leq: {
                if (left_exp->get_value_type() == boolean or right_exp->get_value_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                if (left_exp->get_value(cache, i) <= right_exp->get_value(cache, i)) return 1;
                return 0;
            };
            case meq: {
                if (left_exp->get_value_type() == boolean or right_exp->get_value_type() == boolean)
                {
                    cout << "One of the expressions is a boolean";
                    return 0;
                };
                if (left_exp->get_value(cache, i) >= right_exp->get_value(cache, i)) return 1;
                return 0;
            };
            default: return 0;
        }
    };
    BinOpExp* get_left_expression(){return left_exp;}; //return a node to left expression
    BinOpExp* get_right_expression(){return right_exp;}; // returns a node to right expression
    bin_ops get_binop(){return operation;};
private:
    bin_ops operation;
    BinOpExp* left_exp;
    BinOpExp* right_exp;
    bool left_brakets = false;
    bool right_brakets = false;
};



class Jump : public BinOpExp{
public:
    Jump(AlgoParser::JumpContext* ctx);
    //~UnOp();
    std::string get_val_type(){
        switch(jumper) {
        case 0: return "Break";
        case 1: return "Continue";
        default: return "unknown operation";
        }
    }
    std::string get_type(){return "Jump";};
private:
    int jumper;
};

class Negation : public BinOpExp {
public:
    //not sure if this is necessary but putting
    //it down for now
    Negation(AlgoParser::NegationContext* ctx){
        cout << "create negation" << endl;
        AlgoParser::ExpContext* node = ctx->exp();
        if (node->binOp()){
            value = new BinOp(node);
        }else if(node->LP()){
            value = new BinOp(node);
        }else if((node->integerType()) || (node->doubleType()) || (node->boolType())){
            value = new SingleOutput(node);
        }else if(node->variable()){
            value = new SingleOutput(node);
        }else{
            std::cout << "something else" <<std::endl;
        }
    };
    ~Negation();
    exp_type get_exp_type(){return neg;};
    std::string get_text(){return "-"+value->get_text();}; //returns the value as a string <- IMPORTANT
    BinOpExp* get_result(){
        //cout << "try" << endl;
        return value;
    };
    std::string get_var_type(){return "none";};
private:
    BinOpExp* value;
};


class Expression {
public :
    Expression(AlgoParser::ExpContext* ctx);
    Expression();
    //~Expression();
    BinOpExp* get_child(){return child;}; //return a child of expression (for now only binOp or SingleOutputs)
    types get_type(){return expression;};
    virtual double get_value(Cache* cache, int i);
    virtual string get_text(){return child->get_text();};
    int get_jump_length(){return 1;};
private:
    BinOpExp* child;
};

class Block;

struct AssignDec { //needed to unite statement children
    virtual std::string get_name() = 0;
    virtual Expression* get_expression();
    virtual std::string get_type() = 0;
    virtual std::string get_var_type() = 0;
    int num_stmts(){return 0;};
    int get_jump_length(){return 1;};
    virtual Block* get_block();
    virtual int get_flowchart_size();
};
class Declaration : public AssignDec {
public:
    Declaration(AlgoParser::VarDecContext* ctx);
    //~Declaration();
    std::string get_var_type(){ //return type of the variable
        switch(var_type) {
        case var_int: return "int";
        case var_double: return "double";
        case var_char: return "char";
        case var_bool: return "boolean";
        case unknown_var: return "unknown variable type";
        }
    }
    Expression* get_expression(){return value;}; // returns the object of class which corresponds to the value
    string get_name(){return name;}; // returns the name of the variable
    //std::string get_array_size(){return array_size;};
    stmt_type get_stmt_type(){return declaration;};
    std::string get_operation(){return "none";};
    int get_flowchart_size(){return 1;};
private:
    variable_type var_type = unknown_var;
    //std::string array_size;
    string name;
    Expression* value;
};
class Assignment : public AssignDec {
public:
    Assignment(AlgoParser::AssignContext* ctx);
    ~Assignment();
    Expression* get_expression(){return value;}; // returns the object of class which corresponds to the value
    //Expression* get_index(){return index;};
    //void set_index(Expression* i){index = i;};
    string get_name(){return name;}; // returns the name of the variable
    string get_var_type(){return "none";}; //assign does not need to return variable type
    stmt_type get_stmt_type(){return assignment;};
    int get_flowchart_size(){return 1;};
private:
    string name;
    Expression* value;
    //Expression* index;
};
// double x = 2.0;
// x = x + 2

class UnOp : public AssignDec{
public:
    UnOp(AlgoParser::ExpContext* ctx);
    //~UnOp();
    std::string get_operation(){ //returns binOp operation
        switch(operation) {
        case 0: return "++";
        case 1: return "--";
        default: return "unknown operation";
        }
    }
    std::string get_name(){return left_exp;}
    std::string get_val_type(){return "none";};
    Expression* get_value(){return nullptr;};
    virtual Block* get_block(){return nullptr;};
    std::string get_type(){return "UnOp";};
    stmt_type get_stmt_type(){return unop;};
    int get_jump_length(){return 1;};
    int get_flowchart_size(){return 1;};
private:
    int operation;
    std::string left_exp;
};

class Statement {
public:
    Statement(AlgoParser::StmtsContext* ctx);
    ~Statement();
    Statement(){child = nullptr;};
    AssignDec* get_child(){return child;}; //return a child of statement,
                                            //i.e directs to the actual statement (ex. assign, declaration, return, etc.)
    virtual int num_stmts(){return child->num_stmts();};
    virtual stmt_type get_stmt_type();
    virtual string get_name();
    types get_type(){return statement;};
    virtual Expression* get_expression(){return nullptr;};
    virtual Expression* get_condition(){return nullptr;};
    virtual Block* get_block(){return nullptr;};
    virtual int get_jump_length();
    virtual int get_flowchart_size(){return 1;};
    virtual AssignDec* get_ifrest();
private :
    AssignDec* child;
};

class Block {
public :
    Block(AlgoParser::BlockContext* ctx/*, pass down cache*/ );
    Block();
    ~Block();
    Statement* get_children(){return children;}
    Statement get_child(int i){return children[i];} //returns a child by index
    int get_size(){return size;} //needed for a for loop
    types get_type(){return block;};
    std::string get_operation(){return "none";};
    //walker function
    int get_flowchart_size(){
        size = 0;
        for (int i = 0; i < get_size(); i++){
            size += get_child(i).get_flowchart_size();
        };
        return size;
    };
private:
    Statement* child;
    Statement* children;
    int size;
};
class WhileStmt : public AssignDec {
public:
    WhileStmt(AlgoParser::WhileStmtContext* ctx);
    //~WhileStmt();
    void set_condition(Expression* c){condition = c;};
    Expression* get_condition(){return condition;};
    Block* get_block(){return block_stmt;};
    void set_block_stmt(Block* stmt){block_stmt = stmt;};
    std::string get_type(){return "While";};
    int get_jump_length(){return block_stmt->get_size() + 1;};
    std::string get_operation(){return "none";};
    //attributes: condition, block
    int get_flowchart_size(){return get_block()->get_flowchart_size() + 1;};
private:
    Expression* condition;
    Block* block_stmt;
};

class IfRest: public AssignDec{
public:
    IfRest(AlgoParser::IfrestContext* ctx);
    Expression* get_condition(){return nullptr;}
    //BlockIf* get_block(){return block;}
    AssignDec* get_block_child(int i){return block->get_child(i).get_child();}
    std::string get_type(){return "IfRest";}
    Expression* get_value(){return nullptr;}
    std::string get_name(){return nullptr;}
    std::string get_var_type(){return nullptr;}
    AssignDec* get_ifrest(){return nullptr;}
    std::string get_operation(){return "none";};
    int get_flowchart_size(){return get_block()->get_flowchart_size();};
private:
    Block* block;
};



class IfElse: public AssignDec{
public:
    IfElse(AlgoParser::IfelseContext* ctx);
    Expression* get_condition(){return condition;};
    AssignDec* get_block_child(int i){return block->get_child(i).get_child();};
    stmt_type get_stmt_type(){return ifelse;};
    Expression* get_value(){return nullptr;}
    std::string get_name(){return nullptr;}
    std::string get_var_type(){return nullptr;}
    AssignDec* get_ifrest(){return else_stmt;}
    int get_jump_length(){return block->get_size() + else_stmt->get_block()->get_size() + 1;};
    int get_flowchart_size(){return get_block()->get_flowchart_size() + get_ifrest()->get_block()->get_flowchart_size() + 1;};
private:
    Expression* condition;
    Block* block;
    AssignDec* else_stmt;
};

class Return : public AssignDec {
public:
    Return(AlgoParser::ReturnStmtContext* ctx);
    Return();
    //~Return();
    std::string get_type(){return "Return";};
    std::string get_name(){return " ";};
    Expression* get_expression(){return value;};
    std::string get_var_type(){return "none";};
    int get_jump_length(){return 1;};
    std::string get_operation(){return "none";};
    int get_flowchart_size(){return 1;};
private:
    Expression* value;
};

class Print : public AssignDec{
public:
    Print(AlgoParser::PrintContext* ctx);
    Print();
    //~Print();
    std::string get_type(){return "Print";};
    std::string get_name(){return " ";};
    Expression* get_expression(){return value;};
    int get_jump_length(){return 1;};
    std::string get_operation(){return "none";};
    int get_flowchart_size(){return 1;};
private:
    Expression* value;
};

class AST {
public :
    AST(AlgoParser::BlockContext* ctx/*, pass down cache*/ );
    AST();
    //~Block();
    Statement* get_children(){return children;}
    Statement get_child(int i){return children[i];} //returns a child by index
    int get_size(){return size;} //needed for a for loop
    types get_type(){return block;};
    int num_blocks(){
        int n = 0;
        //here we have to add walking through the list of statements and adding the blocks
        return n;
    };
    //walker function
private:
    Statement* child;
    Statement* children;
    int size;
};

//below is stuff for the AST walker


struct ValueInt{
    int value;
    ValueInt* prev;
    ValueInt* next;
};

class ValuesListInt {
public:
    ValuesListInt();
    ValuesListInt(ValueInt* h, ValueInt* t);
    ~ValuesListInt();
    ValueInt* get_head(){return head;};
    ValueInt* get_tail(){};
    void set_head(ValueInt* h);
    void set_tail(ValueInt* t);
    void add_value(ValueInt* v);
    bool is_empty(); //fill in
    void pop(){
        ValueInt* t = get_tail();
        tail = t->prev;
    };
private:
    ValueInt* head;
    ValueInt* tail;
};

enum chart_shape {
    rectangle = 0,
    diamond = 1,
    circle = 2
};

enum chart_type {
    process = 0,
    if_else = 1,
    while_chart = 2
};

enum colors {
    red = 0,
    green = 1
};

struct flowchart {
    chart_shape shape;
    chart_type type;
    string text;
    int first_block; // num of stmts in the first block (if in if and the only block in while)
    int second_block; // num of stmts in else
    colors color;
};
