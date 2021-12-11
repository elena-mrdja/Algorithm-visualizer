#include "ast_classes.hpp"

types Statement::get_type(){return statement;};
types Expression::get_type(){return expression;};

subtypes Block::get_subtype(){return block;};
subtypes BinOp::get_subtype(){return binop;};
subtypes Negation::get_subtype(){return neg;};
subtypes Variable::get_subtype(){return variable;};

exp_type Negation::get_exp_type(){return boolean;}

int Block::num_statements(){
    list<Statement>::iterator i;
    int j = 0;
    for(i = statements.begin(); i != statements.end(); ++i){
           j++;
    }
    return j;
};

Negation::Negation(Expression* exp){expression = exp;};
Expression* Negation::get_expression(){return expression;};
void Negation::set_expression(Expression* exp){expression = exp;};
double Negation::get_value(){
    if (expression->get_value() != 0) return 0;
    return 1;
};
string Negation::get_text(){return "not(" + expression->get_text() + ")";};

void BinOp::set_left_exp(Expression* exp){left_exp = exp;};
void BinOp::set_right_exp(Expression* exp){right_exp = exp;};
Expression* BinOp::get_left_exp(){return left_exp;};
Expression* BinOp::get_right_exp(){return right_exp;};

Addition::Addition(Expression* l_e, Expression* r_e){
    left_exp = l_e;
    right_exp = r_e;
};
double Addition::get_value(){
    if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean) {return 0;};
    {
        cout << "One of the expressions is a boolean";
        return 0;
    };
    return left_exp->get_value() + right_exp->get_value();
};
exp_type Addition::get_exp_type(){return number;};
string Addition::get_text(){return left_exp->get_text() + " + " + right_exp->get_text();};

Subtraction::Subtraction(Expression* l_e, Expression* r_e){
    left_exp = l_e;
    right_exp = r_e;
};
double Subtraction::get_value(){
    if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
    {
        cout << "One of the expressions is a boolean";
        return 0;
    };
    return left_exp->get_value() - right_exp->get_value();
};
exp_type Subtraction::get_exp_type(){return number;};
string Subtraction::get_text(){return left_exp->get_text() + " - " + right_exp->get_text();};

Multiplication::Multiplication(Expression* l_e, Expression* r_e){
    left_exp = l_e;
    right_exp = r_e;
};
double Multiplication::get_value(){
    if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
    {
        cout << "One of the expressions is a boolean";
        return 0;
    };
    return left_exp->get_value() * right_exp->get_value();
};
exp_type Multiplication::get_exp_type(){return number;};
string Multiplication::get_text(){return left_exp->get_text() + " * " + right_exp->get_text();};

Division::Division(Expression* l_e, Expression* r_e){
    left_exp = l_e;
    right_exp = r_e;
};
double Division::get_value(){
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
exp_type Division::get_exp_type(){return number;};
string Division::get_text(){return left_exp->get_text() + " / " + right_exp->get_text();};

Mthan::Mthan(Expression* l_e, Expression* r_e){
    left_exp = l_e;
    right_exp = r_e;
};
double Mthan::get_value(){
    if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
    {
        cout << "One of the expressions is a boolean";
        return 0;
    };
    if (left_exp->get_value() > right_exp->get_value()) return 1;
    return 0;
};
exp_type Mthan::get_exp_type(){return boolean;};
string Mthan::get_text(){return left_exp->get_text() + " > " + right_exp->get_text();};

Lthan::Lthan(Expression* l_e, Expression* r_e){
    left_exp = l_e;
    right_exp = r_e;
};
double Lthan::get_value(){
    if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
    {
        cout << "One of the expressions is a boolean";
        return 0;
    };
    if (left_exp->get_value() < right_exp->get_value()) return 1;
    return 0;
};
exp_type Lthan::get_exp_type(){return boolean;};
string Lthan::get_text(){return left_exp->get_text() + " < " + right_exp->get_text();};

Leq::Leq(Expression* l_e, Expression* r_e){
    left_exp = l_e;
    right_exp = r_e;
};
double Leq::get_value(){
    if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
    {
        cout << "One of the expressions is a boolean";
        return 0;
    };
    if (left_exp->get_value() <= right_exp->get_value()) return 1;
    return 0;
};
exp_type Leq::get_exp_type(){return boolean;};
string Leq::get_text(){return left_exp->get_text() + " <= " + right_exp->get_text();};

Meq::Meq(Expression* l_e, Expression* r_e){
    left_exp = l_e;
    right_exp = r_e;
};
double Meq::get_value(){
    if (left_exp->get_exp_type() == boolean or right_exp->get_exp_type() == boolean)
    {
        cout << "One of the expressions is a boolean";
        return 0;
    };
    if (left_exp->get_value() >= right_exp->get_value()) return 1;
    return 0;
};
exp_type Meq::get_exp_type(){return boolean;};
string Meq::get_text(){return left_exp->get_text() + " >= " + right_exp->get_text();};

Eqeq::Eqeq(Expression* l_e, Expression* r_e){
    left_exp = l_e;
    right_exp = r_e;
};
double Eqeq::get_value(){
    if (left_exp->get_value() == right_exp->get_value()) return 1;
    return 0;
};
exp_type Eqeq::get_exp_type(){return boolean;};
string Eqeq::get_text(){return left_exp->get_text() + " == " + right_exp->get_text();};

AndOp::AndOp(Expression* l_e, Expression* r_e){
    left_exp = l_e;
    right_exp = r_e;
};
double AndOp::get_value(){
    if (left_exp->get_value() && right_exp->get_value()) return 1;
    return 0;
};
exp_type AndOp::get_exp_type(){return boolean;};
string AndOp::get_text(){return left_exp->get_text() + " and " + right_exp->get_text();};

OrOp::OrOp(Expression* l_e, Expression* r_e){
    left_exp = l_e;
    right_exp = r_e;
};
double OrOp::get_value(){
    if (left_exp->get_value() || right_exp->get_value()) return 1;
    return 0;
};
exp_type OrOp::get_exp_type(){return boolean;};
string OrOp::get_text(){return left_exp->get_text() + " or " + right_exp->get_text();};

Variable::Variable(string n, double v){
    name = n;
    value = v;
};
Variable::Variable(string n, bool v){
    name = n;
    if (v) value = 1;
    else value = 0;
};
void Variable::set_name(std::string n){name = n;};
void Variable::set_value(bool val){
    if (val) value = 1;
    else value = 0;
    type = boolean;
};
void Variable::set_value(double val){
    value = val;
    type = number;
};
string Variable::get_name(){return name;};
double Variable::get_value(){return value;};
exp_type Variable::get_exp_type(){return type;};
string Variable::get_text(){return name;};

Decision::Decision(Expression* c){
    condition = c;
};
void Decision::set_condition(Expression* c){condition = c;};
Expression* Decision::get_condition(){return condition;};
double Decision::get_value(){
    if (condition->get_value()) return 1;
    return 0;
};
bool Decision::is_true(){
    if (get_value() == 1) return true;
    return false;
};

IfRest::IfRest(Block* b){
    block_stmt = b;
    num_stmt = b->num_statements();

};
Block* IfRest::get_block_stmt(){return block_stmt;};
void IfRest::set_num_stmt(int n){num_stmt = n;};
void IfRest::set_block_stmt(Block* stmt){block_stmt = stmt;};
subtypes IfRest::get_subtype(){return ifrest;};

IfElse::IfElse(Block* b, IfRest* s){
    block_stmt = b;
    else_stmt = s;
};
void IfElse::set_condition(Expression* c){condition = c;};
Expression* IfElse::get_condition(){return condition;};
void IfElse::set_else_stmt(IfRest* stmt){else_stmt = stmt;};
IfRest* IfElse::get_else_stmt(){return else_stmt;};
subtypes IfElse::get_subtype(){return ifelse;};

While::While(Expression* c, Block* b){
    condition = c;
    block_stmt = b;
};
void While::set_condition(Expression* c){condition = c;};
Expression* While::get_condition(){return condition;};
Block* While::get_block_stmt(){return block_stmt;};
void While::set_block_stmt(Block* stmt){block_stmt = stmt;};
subtypes While::get_subtype(){return while_loop;};

ValuesList::ValuesList(Value* h, Value* t){
    head = h;
    tail = t;
};
Value* ValuesList::get_head(){return head;};
Value* ValuesList::get_tail(){return tail;};
void ValuesList::set_head(Value* h){head = h;};
void ValuesList::set_tail(Value* t){tail = t;};
void ValuesList::add_value(Value* v){
    tail->next = v;
    v->prev = tail;
    tail = v;
};

flowchart read_statement(Statement* stmt, int i, list<map<Variable*, Value>*>* variables){
    //returns a flowchart corresponding to the given statement
    //this function is supposed to be used within the walker i will keep the line of the statement being read
    //(so, if stmt is in the 20th line, i = 20)
    subtypes stmt_type = stmt->get_subtype();
    flowchart chart;
    if (stmt_type == declaration){
        chart.shape = rectangle;
        chart.text = "Declare " + stmt->get_variable()->get_name();
        Value var;
        var.value = stmt->get_variable()->get_value();
        //variables[i][stmt->get_variable()].add_value(var);
        return chart;
    }
    if(stmt_type == assignment){
        chart.shape = rectangle;
        chart.text = "Assign " + stmt->get_name();
        return chart;
    };
    if(stmt_type == ifelse){
        chart.shape = diamond;
        chart.text = stmt->get_condition()->get_text();
        chart.first_block = stmt->block_stmt->num_statements();
        chart.second_block = stmt->else_stmt->num_stmt;
        return chart;
    };
    if(stmt_type == while_loop){
        chart.shape = diamond;
        chart.text = stmt->get_condition()->get_text();
        chart.first_block = stmt->block_stmt->num_statements();
        return chart;
    };
    return chart;
};

void draw_flowchart(Block* block){
    int n = block->num_statements();
    list<map<Variable*, Value>*>* variables = new list<map<Variable*, Value>*>[n];
    //this list has to be initialized to have pointers to maps for each line
    for (int i = 0; i < n; i++){
        //flowchart* chart = read_statement(block->statements[i], i);
    };
};
