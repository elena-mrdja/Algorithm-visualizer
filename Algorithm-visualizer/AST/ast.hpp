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
    num = 0,
    smth_var= 1,
    unknown_var = 2
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
    unop = 5,
    print_stmt = 6,
    return_stmt = 7,
    unknown_stmt_type = 8
};

enum exp_type {
    binop = 1,
    binop_exp = 2,
    neg = 3,
    variable = 4,
    number = 5,
    unknown_exp_type = 6
};

enum types {
    statement = 0,
    expression = 1,
    block = 2
};

class Cache;
class BinOp;
class SingleOutput;
class Negation;
class Expression{
public:
    Expression(AlgoParser::ExpContext* ctx);
    Expression(){
        expression_type = unknown_exp_type;
        //expression_type = "Unknown exp type";
        child_binop = nullptr;
        child_sing = nullptr;
        child_neg = nullptr;
        child_binop_exp = nullptr;}
    /*~Expression(){
        delete child_binop;
        delete child_sing;
        delete child_neg;
        delete child_binop_exp;
    }*/
    string get_myself(){return "Expression";}
    exp_type get_type();
    exp_type get_exp_type(){return expression_type;};
    //virtual string get_exp_type(){cout << expression_type<<endl; return expression_type;}
    virtual string get_operation(){return nullptr;};
    virtual Expression* get_left_expression(){return nullptr;};
    virtual Expression* get_right_expression(){return nullptr;};
    virtual string get_text(){return nullptr;};
    virtual value_type get_value_type(){return unknown_value_type;};
    virtual double get_value(Cache* cache, int i){return 0;};
    int num_blocks(){return 0;};
    int get_jump_length(){return 1;};

    BinOp* get_child_binop(){return child_binop;};
    SingleOutput* get_child_sing(){return child_sing;};
    Negation* get_child_neg(){return child_neg;};
    Expression* get_child_binop_exp(){return child_binop_exp;};
private:
    BinOp* child_binop;
    SingleOutput* child_sing;
    Negation* child_neg;
    Expression* child_binop_exp;
    //string expression_type = "Unknown";
    exp_type expression_type;
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
    ValuesList(Value* h, Value* t, double v);
    //~ValuesList();
    Value* get_head();
    Value* get_tail();
    double get_value();

    void set_value(double v);
    void set_head(Value* h);
    void set_tail(Value* t);

    void add_value(Value* v);
    bool is_empty(); //fill in
    void pop(){
        Value* t = get_tail();
        tail = t->prev;
    };

    Value* head;
    Value* tail;
    double current;
};


class Declaration;

class Cache{
public:
    Cache(int number);
    //Cache();
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

class Expression;
class Block;
class Assignment;
class Declaration;
class IfElse;
class IfRest;
class WhileStmt;
class Return;
class Print;
class UnOp;

class AssignDec { //needed to unite statement children
public:
    AssignDec(AlgoParser::StmtsContext* i);
    AssignDec(){type = unknown_stmt_type; child_d = nullptr;child_a = nullptr;child_if = nullptr;child_ifrest = nullptr;child_r = nullptr;child_p = nullptr; child_while = nullptr;child_u = nullptr;};
    ////~AssignDec(){delete child_d; delete child_a; delete child_if; delete child_ifrest; delete child_r; delete child_p; delete child_while; delete child_u;};
    virtual string get_name(){return nullptr;};
    Expression* get_expression();
    stmt_type get_type(){return type;};
    virtual string get_var_type(){return nullptr;};
    int num_stmts(){return 0;};
    int get_jump_length(){return 1;};
    virtual Block* get_block(){return nullptr;};
    virtual int get_flowchart_size(){return 0;};
    virtual stmt_type get_stmt_type(){return unknown_stmt_type;};
    Declaration* get_child_dec(){return child_d;}
    Assignment* get_child_ass(){return child_a;};
    IfElse* get_child_ifelse(){return child_if;}
    IfRest* get_child_ifrest(){return child_ifrest;}
    Return* get_child_return(){return child_r;}
    Print* get_child_print(){return child_p;}
    WhileStmt* get_child_while(){return child_while;}
    UnOp* get_child_unop(){return child_u;}
    virtual Expression* get_condition();
    virtual AssignDec* get_ifrest(){return nullptr;};
private:
    Declaration* child_d;
    Assignment* child_a;
    IfElse* child_if;
    IfRest* child_ifrest;
    Return* child_r;
    Print* child_p;
    WhileStmt* child_while;
    UnOp* child_u;
    stmt_type type;
};


class SingleOutput : public Expression {
public:
    SingleOutput(AlgoParser::ExpContext* ctx);
    //~SingleOutput(){delete node;};
    exp_type get_exp_type(){
        if (val_type == num) return number;
        return variable;
    };
    string get_text(){return value;}; //returns the value as a string

    string get_operation(){return "none";}; //no needed
    Expression* get_left_expression(){return nullptr;}; // no needed
    Expression* get_right_expression(){return nullptr;}; //no needed
    variable_type get_var_type(){return val_type;}; // returns a type of a single output
    value_type get_value_type(){return double_value;}                                              // possible outputs: 'double', 'integer', 'boolean', 'variable'.
    int num_blocks(){return 0;};
    double get_value(Cache* cache, int i){
        //i is the line which the SingleOutput is in
        if (val_type == num) return stod(value);
        else {
            return cache->get_last_value(value, i);
        }
    }; //returns the value as a string <- IMPORTANT
    Expression* get_result(){return nullptr;};
private:
    string value;
    variable_type val_type;
};

class BinOp : public Expression{
public:
    BinOp(AlgoParser::ExpContext* ctx);
    //~BinOp(){delete left_exp; delete right_exp;};
    exp_type get_exp_type(){return binop;};
    /*string get_text(){
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
    }; //returns an entire binOp line as a string (ex. output: '( 4.0 + x ) * 5')*/
    string get_operation(){ //returns binOp operation
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
    Expression* get_left_expression(){return left_exp;}; //return a node to left expression
    Expression* get_right_expression(){return right_exp;}; // returns a node to right expression
    bin_ops get_binop(){return operation;};
private:
    bin_ops operation;
    Expression* left_exp;
    Expression* right_exp;
    bool left_brakets = false;
    bool right_brakets = false;
};



/*class Jump : public Expression{ // change to stmt
public:
    Jump(AlgoParser::JumpContext* ctx);
    ////~UnOp();
    string get_val_type(){
        switch(jumper) {
        case 0: return "Break";
        case 1: return "Continue";
        default: return "unknown operation";
        }
    }
    string get_type(){return "Jump";};
private:
    int jumper;
};*/

class Negation : public Expression {
public:
    //not sure if this is necessary but putting
    //it down for now
    Negation(AlgoParser::NegationContext* ctx){
        AlgoParser::ExpContext* node = ctx->exp();
        value = new Expression(node);
    };
    //~Negation(){delete value;}
    exp_type get_exp_type(){return neg;};
    string get_text(){return "-"+value->get_text();}; //returns the value as a string <- IMPORTANT
    Expression* get_result(){
        return value;
    };
    string get_var_type(){return "none";};
    virtual string get_operation(){return nullptr;};
    virtual Expression* get_left_expression(){return nullptr;};
    virtual Expression* get_right_expression(){return nullptr;};
    virtual value_type get_value_type(){return double_value;};
    double get_value(Cache* cache, int i){return -value->get_value(cache, i);};
private:
    Expression* value;
};


/*class Expression {
public :
    Expression(AlgoParser::ExpContext* ctx);
    Expression(){child = nullptr;};
    ////~Expression(){delete child;};
    Expression* get_child(){return child;}; //return a child of expression (for now only binOp or SingleOutputs)
    types get_type(){return expression;};
    virtual double get_value(Cache* cache, int i){return 0;};
    virtual string get_text(){return child->get_text();};
    int get_jump_length(){return 1;};
private:
    Expression* child;
};*/

class Block;


class AssignDec;
class Declaration : public AssignDec {
public:
    Declaration(AlgoParser::VarDecContext* ctx);
    Declaration(){value = nullptr; name = "none"; var_type = unknown_var;}
    ////~Declaration(){delete value;};
    string get_var_type(){ //return type of the variable
        switch(var_type) {
        case num: return "number";
        case smth_var: return "variable";
        }
    }
    Expression* get_expression(){return value;}; // returns the object of class which corresponds to the value
    string get_name(){return name;}; // returns the name of the variable
    //string get_array_size(){return array_size;};
    stmt_type get_stmt_type(){return declaration;};
    string get_operation(){return "none";};
    int get_flowchart_size(){return 1;};
    virtual Block* get_block(){return nullptr;};
    virtual Expression* get_condition(){return nullptr;}
    virtual AssignDec* get_ifrest(){return nullptr;}
private:
    variable_type var_type = unknown_var;
    //string array_size;
    string name;
    Expression* value;
};
class Assignment : public AssignDec {
public:
    Assignment(AlgoParser::AssignContext* ctx);
    ////~Assignment(){delete value;};
    Expression* get_expression(){return value;}; // returns the object of class which corresponds to the value
    //Expression* get_index(){return index;};
    //void set_index(Expression* i){index = i;};
    string get_name(){return name;}; // returns the name of the variable
    string get_var_type(){return "none";}; //assign does not need to return variable type
    stmt_type get_stmt_type(){return assignment;};
    int get_flowchart_size(){return 1;};
    virtual Block* get_block(){return nullptr;};
    virtual Expression* get_condition(){return nullptr;}
    virtual AssignDec* get_ifrest(){return nullptr;}
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
    UnOp(){operation = 0; left_exp = nullptr;}
    ////~UnOp(){delete left_exp;};
    string get_operation(){ //returns binOp operation
        switch(operation) {
        case 0: return "++";
        case 1: return "--";
        default: return "unknown operation";
        }
    }
    string get_name(){return "none";} // change to Expression
    string get_var_type(){return "none";};
    virtual Expression* get_expression(){return nullptr;}
    Expression* get_value(){return left_exp;};
    virtual Block* get_block(){return nullptr;};
    stmt_type get_stmt_type(){return unop;};
    int get_jump_length(){return 1;};
    int get_flowchart_size(){return 1;};
    virtual Expression* get_condition(){return nullptr;}
    virtual AssignDec* get_ifrest(){return nullptr;}
private:
    int operation;
    Expression* left_exp;
};

/*class Statement {
public:
    Statement(AlgoParser::StmtsContext* ctx);
    //~Statement();
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
};*/

class Block {
public :
    Block(AlgoParser::BlockContext* ctx);
    Block();
    ////~Block(){delete children; delete child;};
    AssignDec* get_children(){return children;}
    AssignDec get_child(int i){return children[i];} //returns a child by index
    int get_size(){return size;} //needed for a for loop
    types get_type(){return block;};
    string get_operation(){return "none";};
    //walker function
    int get_block_flowchart_size(){
        size = 0;
        for (int i = 0; i < get_size(); i++){
            size += get_child(i).get_flowchart_size();
        };
        return size;
    };
private:
    AssignDec child;
    AssignDec* children;
    int size;
};
class WhileStmt : public AssignDec {
public:
    WhileStmt(AlgoParser::WhileStmtContext* ctx);
    virtual string get_name(){return "none";}
    ////~WhileStmt(){delete condition; delete block_stmt;};
    void set_condition(Expression* c){condition = c;};
    virtual Expression* get_expression(){return nullptr;}
    Expression* get_condition(){return condition;};
    Block* get_block(){return block_stmt;};
    void set_block_stmt(Block* stmt){block_stmt = stmt;};
    int get_jump_length(){return block_stmt->get_size() + 1;};
    string get_operation(){return "none";};
    virtual string get_var_type(){return "none";};
    //attributes: condition, block
    int get_flowchart_size(){return get_block()->get_block_flowchart_size() + 1;};
    virtual AssignDec* get_ifrest(){return nullptr;}
    stmt_type get_stmt_type(){return while_loop;};
private:
    Expression* condition;
    Block* block_stmt;
};

class IfRest: public AssignDec{
public:
    IfRest(AlgoParser::IfrestContext* ctx);
    ////~IfRest(){delete block;}
    Expression* get_condition(){return nullptr;}
    //BlockIf* get_block(){return block;}
    //AssignDec* get_block_child(int i){return block->get_child(i).get_child();}
    virtual Expression* get_expression(){return nullptr;}
    Expression* get_value(){return nullptr;}
    string get_name(){return nullptr;}
    string get_var_type(){return nullptr;}
    AssignDec* get_ifrest(){return nullptr;}
    string get_operation(){return "none";};
    int get_flowchart_size(){return get_block()->get_block_flowchart_size();};
    virtual Block* get_block(){return block;};
    stmt_type get_stmt_type(){return ifrest;};
private:
    Block* block;
};



class IfElse: public AssignDec{
public:
    IfElse(AlgoParser::IfelseContext* ctx);
    ////~IfElse(){delete condition; delete block; delete else_stmt;}
    Expression* get_condition(){return condition;};
    virtual Expression* get_expression(){return nullptr;}
    //AssignDec* get_block_child(int i){return block->get_child(i).get_child();};
    virtual Block* get_block(){return block;};
    stmt_type get_stmt_type(){return ifelse;};
    Expression* get_value(){return nullptr;}
    string get_name(){return nullptr;}
    string get_var_type(){return nullptr;}
    AssignDec* get_ifrest(){return else_stmt;}
    int get_jump_length(){return block->get_size() + else_stmt->get_block()->get_size() + 1;};
    int get_flowchart_size(){return get_block()->get_block_flowchart_size() + get_ifrest()->get_block()->get_block_flowchart_size() + 1;};
private:
    Expression* condition;
    Block* block;
    IfRest* else_stmt;
};

class Return : public AssignDec {
public:
    Return(AlgoParser::ReturnStmtContext* ctx);
    Return(){value = nullptr;};
    ////~Return(){delete value;};
    string get_name(){return " ";};
    Expression* get_expression(){return value;};
    string get_var_type(){return "none";};
    int get_jump_length(){return 1;};
    string get_operation(){return "none";};
    int get_flowchart_size(){return 1;};
    virtual Block* get_block(){return nullptr;};
    virtual Expression* get_condition(){return nullptr;}
    virtual AssignDec* get_ifrest(){return nullptr;}
    stmt_type get_stmt_type(){return return_stmt;};
private:
    Expression* value;
};

class Print : public AssignDec{
public:
    Print(AlgoParser::PrintContext* ctx);
    Print(){value = nullptr;};
    ////~Print(){delete value;};
    string get_name(){return " ";};
    Expression* get_expression(){return value;};
    int get_jump_length(){return 1;};
    string get_operation(){return "none";};
    int get_flowchart_size(){return 1;};
    string get_var_type(){return "none";}
    virtual Block* get_block(){return nullptr;};
    virtual Expression* get_condition(){return nullptr;}
    virtual AssignDec* get_ifrest(){return nullptr;}
    stmt_type get_stmt_type(){return print_stmt;};
private:
    Expression* value;
};

class AST {
public :
    AST(AlgoParser::BlockContext* ctx/*, pass down cache*/ );
    AST();
    ////~Block();
    AssignDec* get_children(){return children;}
    AssignDec get_child(int i){return children[i];} //returns a child by index
    int get_size(){return size;} //needed for a for loop
    types get_type(){return block;};
    int num_blocks(){
        int n = 0;
        //here we have to add walking through the list of statements and adding the blocks
        return n;
    };
    //walker function
private:
    AssignDec* child;
    AssignDec* children;
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
    ////~ValuesListInt();
    ValueInt* get_head(){return head;};
    ValueInt* get_tail(){return tail;};
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

extern flowchart l[MAX_LINES];

flowchart read_statement(AssignDec stmt, int line_num, Cache* cache);

void make_chart_list(AST* ast, Cache* cache);
