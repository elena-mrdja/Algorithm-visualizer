#include <iostream>
#include "ast.hpp"
#include "antlr4-runtime.h"
#include "AlgoParser.h"
#include <string>
using namespace std;
using namespace antlr4;
using namespace antlrcpptest;
BinOpExp::BinOpExp(AlgoParser::ExpContext* ctx){
    cout << "sleeeeeeeeep" << std::endl;
    if (ctx->binOp()){
        cout << "binop" << std::endl;
        BinOp child_binop(ctx);
        expression_type = child_binop.get_exp_type();
    }else if (ctx->negation()){
        expression_type = neg;
        Negation child_neg(ctx->negation());
        expression_type = child_neg.get_exp_type();
    }else{
        SingleOutput child_sing(ctx);
        expression_type = child_sing.get_exp_type();
    }
    cout << expression_type << std::endl;
}
SingleOutput::SingleOutput(AlgoParser::ExpContext* ctx){
    //cout << "katia4\n"<< std::endl;
    if (ctx->integerType()){
        value = ctx->integerType()->INTEGER()->getText();
        val_type = num;
    }else if (ctx->doubleType()){
        //cout << "katia5\n"<< std::endl;
        value = ctx->doubleType()->FLOAT()->getText();
        //cout << value << std::endl;
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
        val_type = smth_var; // y = (x * 1) + 1
    }
}

BinOp::BinOp(AlgoParser::ExpContext* ctx){
    AlgoParser::ExpContext* left_node = ctx->exp(0);
    AlgoParser::ExpContext* right_node = ctx->exp(1);
    //BinOpExp* left_exp(left_node);
    //BinOpExp* right_exp(right_node);
    if (left_node->binOp()){
        left_exp = new BinOp(left_node);
    }else if(left_node->LP()){
        left_exp = new BinOp(left_node->exp(0));
        left_brakets = true;
    }else if((left_node->integerType()) || (left_node->doubleType()) || (left_node->boolType())){
        left_exp = new SingleOutput(left_node);
    }else if(left_node->variable()){
        left_exp = new SingleOutput(left_node);
    }else if (left_node->negation()){
        left_exp = new Negation(left_node->negation());
    }else{
        std::cout << "something else" <<std::endl;
    }

    if (right_node->binOp()){
        right_exp = new BinOp(right_node);
    }else if(right_node->LP()){
        right_exp = new BinOp(right_node->exp(0));
        right_brakets = true;
    }else if((right_node->integerType()) || (right_node->doubleType()) || (right_node->boolType())){
        right_exp = new SingleOutput(right_node);
    }else if(right_node->variable()){
        right_exp = new SingleOutput(right_node);
    }else if (right_node->negation()){
        right_exp = new Negation(right_node->negation());
    }else{
            std::cout << "something else" <<std::endl;
     }

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
    //cout << "katia1\n"<< std::endl;
    Declaration* child_d = nullptr;
    Assignment* child_a = nullptr;
    IfElse* child_if = nullptr;
    IfRest* child_ifrest = nullptr;
    Return* child_r = nullptr;
    Print* child_p = nullptr;
    WhileStmt* child_while = nullptr;
    UnOp* child_u = nullptr;
    type = unknown_stmt_type;
    //cout << "katia Type...\n" << std::endl;
    //cout << type << std::endl;
    //cout << "katia Type\n"<< std::endl;
    //cout << i->print()<< std::endl;
    if(i->assign()){
        AlgoParser::AssignContext* node = i->assign();
        //Assignment child_a(node);
        //child = new Assignment(node);
        type = assignment;
    }else if(i->varDec()){
        //cout << "katia VarDec\n"<< std::endl;
        AlgoParser::VarDecContext* node = i->varDec();
        //child = new Declaration(node);
        Declaration child_d(node);
        type = declaration;
        //cout << i->varDec()<< std::endl;
    }else if(i->returnStmt()){
        AlgoParser::ReturnStmtContext* node = i->returnStmt();
        //child = new Return(node);
        Return child_r(node);
        type = return_stmt;
    }else if(i->print()){
        AlgoParser::PrintContext* node = i->print();
        //child = new Print(node);
        Print child_p(node);
        type = print_stmt;
    }else if(i->whileStmt()){
        AlgoParser::WhileStmtContext* node = i->whileStmt();
        //child = new WhileStmt(node);
        WhileStmt child_while(node);
        type = while_loop;
    }else if(i->ifelse()){
        AlgoParser::IfelseContext* node = i->ifelse();
        //child = new IfElse(node);
        IfElse child_if(node);
        type = ifelse;
    }else if(i->exp()){
        AlgoParser::ExpContext* node = i->exp();
        //child = new UnOp(node);
        UnOp child_u(node);
        type = unop;
    }else{
        cout << "katia Strange\n";
    }
}
UnOp::UnOp(AlgoParser::ExpContext* ctx){
    AlgoParser::ExpContext* left_node = ctx->exp(0);
    Expression left_exp(left_node);
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
    case assignment : return child_a->get_expression();
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

Expression::Expression(AlgoParser::ExpContext* ctx){
    //cout << "katia3\n"<< std::endl;
    if (ctx->binOp()){
        child = new BinOpExp(ctx);
    }else if (ctx->exp(0)){
        child = Expression(ctx->exp(0)).get_child();
    }else if (ctx->negation()){
        child = new BinOpExp(ctx);
    }else{
        child = new BinOpExp(ctx);
    }
}
Declaration::Declaration(AlgoParser::VarDecContext* ctx) {
    //cout << "katia2\n"<< std::endl;
    value = new Expression(ctx->exp(0));
    name = ctx->variable()->STRING()->getText();
    var_type = num;
    /*if (ctx->type()->INT()){
        var_type = num;
    }else if (ctx->type()->DOUBLE()){
        var_type = num;
    }else if (ctx->type()->CHAR()){
        var_type = num;
    }else if (ctx->type()->BOOLEAN()){
        var_type = num;
    }else{
        var_type = num;
    }*/

}

Assignment::Assignment(AlgoParser::AssignContext* ctx)
{
    value = new Expression(ctx->exp(0));
    name = ctx->variable()->STRING()->getText();
}

/*Statement::Statement(AlgoParser::StmtsContext* ctx){
    //AlgoParser::BinOpContext *i = ctx->binOp();
    if(ctx->assign()){
        AlgoParser::AssignContext* node = ctx->assign();
        child = new Assignment(node);
    }else if(ctx->varDec()){
        AlgoParser::VarDecContext* node = ctx->varDec();
        child = new Declaration(node);
    }else if(ctx->returnStmt()){
        AlgoParser::ReturnStmtContext* node = ctx->returnStmt();
        child = new Return(node);
    }else if(ctx->print()){
        AlgoParser::PrintContext* node = ctx->print();
        child = new Print(node);
    }
}*/

Block::Block(AlgoParser::BlockContext* ctx) {
    size = ctx->stmts().size();
    children = new AssignDec[size];
    //cache constructor
    cout << ctx->stmts()[1] << std::endl;
    int i = 0;
    for (;i < size; i++){
         //cout << "katia\n"<< std::endl;
         AssignDec child(ctx->stmts()[i]);
         //cout << child.get_type() << std::endl;
         //cout << "end"<< std::endl;
         children[i] = child;
         //cout << "end children"<< std::endl;
         //cout << size << std::endl;
         //cout << i << std::endl;
         //cout << ctx->stmts().size() << std::endl;

    };
    cout << child << std::endl;
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


AST::AST(AlgoParser::BlockContext* ctx) {
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
}

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
