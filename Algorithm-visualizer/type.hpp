#include "ast.hpp"
#include "declaration.hpp"
#include "AlgoParser.h"
#include <string>
#ifndef TYPE_HPP
#define TYPE_HPP

namespace antlrcpptest {

class Type : public Declaration {
public:
    Type(AlgoParser::VarDecContext* ctx);
    ~Type();
    //void set_type(Type t){type = t;};
    std::string get_type(){
        switch(t) {
        case 0: return "char";
        case 1: return "int";
        case 2: return "double";
        case 3: return "boolean";
        case 4: return "unknown type";
        }
    }
    std::string get_subtype(){return "Type";};
private:
    int t = 4;
};

};

#endif // TYPE_HPP
