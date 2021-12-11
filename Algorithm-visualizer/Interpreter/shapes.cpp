#include "shapes.hpp"


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





