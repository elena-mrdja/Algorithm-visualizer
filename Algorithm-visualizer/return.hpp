#include "ast.hpp"
#include "statement.hpp"
#include "expression.hpp"
#include "AlgoParser.h"
#include <string>
#ifndef RETURN_HPP
#define RETURN_HPP

namespace antlrcpptest {

class Return : public Statement {
    public:
        Return(AlgoParser::StmtsContext* ctx);
        ~Return();
        void set_exp(Expression* e){value = e;};
        Expression* get_exp(){return value;};
        std::string get_subtype(){return "Return";};
    private:
        Expression* value;
    }
};

#endif // RETURN_HPP
