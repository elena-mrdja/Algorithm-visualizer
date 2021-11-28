#ifndef VARIABLE_TEMPLATE_H
#define VARIABLE_TEMPLATE_H

#include "expression_template.hpp"

template<typename T> class Variable : Expression<T> {
    Variable();
    ~Variable();
    void set_name(char n){name = n;};
    std::string get_name(){return name;};
    std::string get_subtype(){return "Variable";};
    T get_value(){return value;};
    std::string type();
private:
    std::string name;
    T value;
};

#endif // VARIABLE_TEMPLATE_H
