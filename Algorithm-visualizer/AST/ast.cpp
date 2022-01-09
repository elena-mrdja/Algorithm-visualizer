#include <iostream>
#include "ast.hpp"
#include "antlr4-runtime.h"
#include "AlgoParser.h"
#include <string>
using namespace std;
using namespace antlr4;
using namespace antlrcpptest;
Expression::Expression(AlgoParser::ExpContext* ctx){
    expression_type = unknown_exp_type;
    if (ctx->binOp()){
        child_binop = new BinOp(ctx);
        expression_type = binop;
    }else if (ctx->negation()){
        child_neg = new Negation(ctx->negation());
        expression_type = neg;
    }else if (ctx->LP()){
        child_binop_exp = new Expression(ctx->exp(0));
        expression_type = binop_exp;
    }else{
        child_sing = new SingleOutput(ctx);
        if (ctx->variable()){
            expression_type = variable;
        }else{
            expression_type = number;
        }
    }
}

exp_type Expression::get_type(){
    if (child_binop != nullptr){
        return binop;
    }
    return unknown_exp_type;
}
SingleOutput::SingleOutput(AlgoParser::ExpContext* ctx){
    if (ctx->integerType()){
        value = ctx->integerType()->INTEGER()->getText();
        val_type = num;
    }else if (ctx->doubleType()){
        value = ctx->doubleType()->FLOAT()->getText();
        val_type = num;
    }else if (ctx -> boolType()){
        if (ctx -> boolType()->TRUE()){
            value = '1';
        }else{
            value = '0';
        }
        val_type = num;
    }else if (ctx -> variable()){
        value = ctx->variable()->STRING()->getText();
        val_type = smth_var;
    }
}

BinOp::BinOp(AlgoParser::ExpContext* ctx){
    AlgoParser::ExpContext* left_node = ctx->exp(0);
    AlgoParser::ExpContext* right_node = ctx->exp(1);
    left_exp = new Expression(left_node);
    right_exp = new Expression(right_node);

    AlgoParser::BinOpContext *i = ctx->binOp();

    if(i->PLUS()){
        operation = addition;
    }else if(i->MINUS()){
        operation = subtraction;
    }else if(i->TIMES()){
        operation = multiplication;
    }else if(i->DIV()){
        operation = division;
    }else if(i->MOD()){
        operation = modulo;
    }else if(i->XAND()){
        operation = conj;
    }else if(i->XOR()){
        operation = disj;
    }else if(i->EQQ()){
        operation = eqeq;
    }else if(i->NOTEQQ()){
        operation = noteq;
    }else if(i->LT()){
        operation = lthan;
    }else if(i->MT()){
        operation = mthan;
    }else if(i->LEQ()){
        operation = leq;
    }else if(i->MEQ()){
        operation = meq;
    }
}

AssignDec::AssignDec(AlgoParser::StmtsContext* i){
    if(i->assign()){
        AlgoParser::AssignContext* node = i->assign();
        child_a = new Assignment(node);
        type = assignment;
    }else if(i->varDec()){
        AlgoParser::VarDecContext* node = i->varDec();
        child_d = new Declaration(node);
        type = declaration;
    }else if(i->returnStmt()){
        AlgoParser::ReturnStmtContext* node = i->returnStmt();
        child_r = new Return(node);
        type = return_stmt;
    }else if(i->print()){
        AlgoParser::PrintContext* node = i->print();
        child_p = new Print(node);
        type = print_stmt;
    }else if(i->whileStmt()){
        AlgoParser::WhileStmtContext* node = i->whileStmt();
        child_while = new WhileStmt(node);
        type = while_loop;
    }else if(i->ifelse()){
        AlgoParser::IfelseContext* node = i->ifelse();
        child_if = new IfElse(node);
        type = ifelse;
    }else if(i->exp()){
        AlgoParser::ExpContext* node = i->exp();
        child_u = new UnOp(node);
        type = unop;
    }
}
UnOp::UnOp(AlgoParser::ExpContext* ctx){
    AlgoParser::ExpContext* left_node = ctx->exp(0);
    left_exp = new Expression(left_node);
    AlgoParser::UnopContext *i = ctx->unop();
    if(i->PLUSPLUS()){
        operation = 0;
    }else if(i->MINUSMINUS()){
        operation = 1;
    }else {
        operation = 2;
    }
}
Expression* AssignDec::get_expression(){
    switch (type) {
    case declaration : return child_d->get_expression();
    case assignment :  return child_a->get_expression();
    case ifelse : return nullptr;
    case ifrest : return nullptr;
    case while_loop : return nullptr;
    case unop : return nullptr;
    case print_stmt : return child_p->get_expression();
    case return_stmt : return child_r->get_expression();
    case unknown_stmt_type : return nullptr;
    }
}

/*Jump::Jump(AlgoParser::JumpContext* ctx){
    if(ctx->CONT()){
        jumper = 0;
    }else if(ctx->BREAK()){
        jumper = 1;
    }else {
        jumper = 2;
    }
}*/

Declaration::Declaration(AlgoParser::VarDecContext* ctx) {
    value = new Expression(ctx->exp(0));
    name = ctx->variable()->STRING()->getText();
    var_type = num;
}

Assignment::Assignment(AlgoParser::AssignContext* ctx)
{
    value = new Expression(ctx->exp(0));
    name = ctx->variable()->STRING()->getText();
}

Block::Block(AlgoParser::BlockContext* ctx) {
    size = ctx->stmts().size();
    children = new AssignDec[size];
    int i = 0;
    for (;i < size; i++){
         AssignDec child(ctx->stmts()[i]);
         children[i] = child;
    };
}

WhileStmt::WhileStmt(AlgoParser::WhileStmtContext* ctx){
   condition = new Expression(ctx->exp());
   block_stmt = new Block(ctx->block());
}



Return::Return(AlgoParser::ReturnStmtContext* ctx){
    AlgoParser::ExpContext* node = ctx->exp();
    value = new Expression(node);
}

Print::Print(AlgoParser::PrintContext* ctx){
    AlgoParser::ExpContext* node = ctx->exp();
    value = new Expression(node);
}


/*AST::AST(AlgoParser::BlockContext* ctx) {
    size = 0;
    children = new AssignDec[size];
    int idx = 0;
    //cache constructor
    for (auto i: ctx->stmts()){
        AssignDec child(i); // child to cache
        children[idx] = child;
        size++;
        idx++;
    }
}*/

IfElse::IfElse(AlgoParser::IfelseContext* ctx){

    condition = new Expression(ctx->exp());
    block = new Block(ctx->block());
    if (ctx->ifrest()){
        else_stmt = new IfRest(ctx->ifrest());
    }else{
        else_stmt = nullptr;
    }

}

IfRest::IfRest(AlgoParser::IfrestContext* ctx){
    block = new Block(ctx->block());
}



ValuesList::ValuesList(Value* h, Value* t, double v){
    head = h;
    tail = t;
    current = v;
};

ValuesList::ValuesList(){
    head = new Value();
    tail = head;
    current = tail->value;
}

Value* ValuesList::get_head(){return head;};
Value* ValuesList::get_tail(){return tail;};

void ValuesList::set_head(Value* h){head = h;};
void ValuesList::set_tail(Value* t){tail = t;};
bool ValuesList::is_empty(){return head == nullptr;};
void ValuesList::set_value(double v){current = v;};
double ValuesList::get_value(){return current;};
void ValuesList::add_value(Value* v){
    if (is_empty()){
        head = v;
        tail = v;
    }
    else {
        tail->next = v;
        v->prev = tail;
        tail = v;
    }
};

Expression* AssignDec::get_condition(){
    switch (type) {
    case declaration : return nullptr;
    case assignment : return nullptr;
    case ifelse : return get_child_ifelse()->get_condition();
    case ifrest : return nullptr;
    case while_loop : get_child_ifelse()->get_condition();
    case unop : return nullptr;
    case print_stmt : return nullptr;
    case return_stmt : return nullptr;
    case unknown_stmt_type : return nullptr;
}
}

//variable tracking
/*Cache::Cache(int number){
    num_lines = number;
}

void fill_while_block(Block* block, Expression* condition, Cache* cache, int while_condition_line);
void fill_declaration(AssignDec dec, Cache* cache, int current_line);
void fill_assignment(AssignDec assign, Cache* cache, int current_line);
void fill_ifelse(AssignDec ifelse, Cache* cache, int if_condition_line);
void fill_unop(AssignDec ifelse, Cache* cache, int if_condition_line);

void fill_statement(AssignDec stmt, Cache* cache, int current_line){
    switch (stmt.get_stmt_type()){
    case declaration : fill_declaration(stmt, cache, current_line);
    case assignment : fill_assignment(stmt, cache, current_line);
    case ifelse : fill_ifelse(stmt, cache, current_line);
    case ifrest : cout << "error: ifelse";
    case while_loop : fill_while_block(stmt.get_block(), stmt.get_condition(), cache, current_line);
    case unop : fill_unop(stmt, cache, current_line);
    };
};

void fill_while_block(Block* block, Expression* condition, Cache* cache, int while_condition_line){
    //Block : the block of the while statement
    //while_condition_line : the number of the line while(condition)
    int n = block->get_size();
    while (condition->get_value(cache, while_condition_line)) {
        for (int i = 1; i <= n; i++) {
            fill_statement(block->get_child(while_condition_line + i), cache, while_condition_line + i);
        };
    };
};

void fill_declaration(AssignDec dec, Cache* cache, int declaration_line){
    Value* value = new Value;
    value->value = dec.get_expression()->get_value(cache, declaration_line);
    cache->get_map()[declaration_line][dec.get_name()]->add_value(value);
};

void fill_assignment(AssignDec assign, Cache* cache, int assignment_line){
    Value* value = new Value;
    value->value = assign.get_expression()->get_value(cache, assignment_line);
    cache->get_map()[assignment_line][assign.get_name()]->add_value(value);
};

void fill_ifelse(AssignDec ifelse, Cache* cache, int if_condition_line){
    Expression* condition = ifelse.get_condition();
    if (condition->get_value(cache, if_condition_line)){
        int n = ifelse.get_block()->get_size();
        for (int i = 1; i <= n; i++){
            fill_statement(ifelse.get_block()->get_child(i - 1), cache, if_condition_line + i);
        };
    }
    else {
        if (ifelse.get_ifrest() != nullptr) {
            int n = ifelse.get_block()->get_size();
            int m = ifelse.get_ifrest()->get_block()->get_size();
            for (int i = 1; i <= m; i++) {
                fill_statement(ifelse.get_ifrest()->get_block()->get_child(i - 1), cache, if_condition_line + n + i);
            }
        }
    }
};

void fill_unop(AssignDec unop, Cache* cache, int current_line){
    Value* value = new Value;
    value->value = unop.get_expression()->get_value(cache, current_line);
    cache->get_map()[current_line][unop.get_name()]->add_value(value);
}



void fill_cache(Block* ast, Cache* cache){
    int current_line = 0;
    int n = ast->get_size();
    while (current_line < n){
        //with our constraints, the first line has to be a declaration
        int next_line = current_line + ast->get_child(current_line).get_jump_length();
        fill_statement(ast->get_child(current_line), cache, current_line);
        //next_line : in case of stmts with no blocks, the line increases by only 1
        cache->get_map()[next_line] = cache->get_map()[current_line];
        current_line = next_line;
    };
};


flowchart read_statement(AssignDec stmt, int line_num, Cache* cache){
    //returns a flowchart corresponding to the given statement
    //this function is supposed to be used within the walker i will keep the line of the statement being read
    //(so, if stmt is in the 20th line, i = 20)
    stmt_type st_type = stmt.get_stmt_type();
    flowchart chart;
    if (st_type == declaration){
        chart.shape = rectangle;
        chart.text = "Declare " + stmt.get_child()->get_name();
        chart.color = red;
        return chart;
    }
    if(st_type == assignment){
        chart.shape = rectangle;
        chart.text = "Assign " + stmt.get_name();
        /*Value* value = new Value;
        value->value = stmt.get_child()->get_expression()->get_value(cache, line_num);
        cache->get_map()[line_num][stmt.get_child()->get_name()]->add_value(value);
        chart.color = red;
        return chart;
    };
    if(st_type == ifelse){
        chart.shape = diamond;
        chart.text = stmt.get_condition()->get_text();
        chart.first_block = stmt.get_block()->get_block_flowchart_size();
        if (stmt.get_ifrest()->get_block() == nullptr) {
            chart.second_block = 0;
        }
        else chart.second_block = 1;
        if (stmt.get_condition()->get_value(cache, line_num)) chart.color = green;
        else chart.color = red;
        return chart;
    };
    if (st_type == ifrest) {
        chart.shape = diamond;
        chart.text = "Else";
        chart.color = red;
        chart.first_block = stmt.get_block()->get_block_flowchart_size();
    };
    if(st_type == while_loop){
        chart.shape = diamond;
        chart.text = stmt.get_condition()->get_text();
        chart.first_block = stmt.get_block()->get_block_flowchart_size();
        if (stmt.get_condition()->get_value(cache, line_num)) chart.color = green;
        else chart.color = red;
        return chart;

    };
    if(st_type == unop){
        chart.shape = rectangle;
        chart.text = "Assign" + stmt.get_name();
        chart.color = red;
        return chart;
    }
    return chart;
};

flowchart l[MAX_LINES] = {};

void draw_flowchart(AST* ast, Cache* cache){
    int n = ast->get_size();
    for (int i = 0; i < n; i++){
        flowchart chart = read_statement(ast->get_child(i), i, cache);
        l[i] = chart;

    };
};*/
