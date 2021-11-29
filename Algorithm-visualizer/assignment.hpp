#include "ast.hpp"
#include "statement.hpp"
#include "expression.hpp"
#include "AlgoParser.h"
#include "type.hpp"
#include <string>
#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

using namespace std;

namespace antlrcpptest {

class Assignment : public Statement {
public:
    Assignment(AlgoParser::StmtsContext* ctx);
    ~Assignment();
    Expression* get_value(){return value;};
    void set_value(Expression* v){value = v;};
    std::string get_name(){return name;};
    void set_name(std::string n){name = n;};
    std::string get_subtype(){return "Assignment";};
private:
    std::string name;
    Expression* value;
    Type type;
    int length;
};

}

#endif // ASSIGNMENT_HPP

