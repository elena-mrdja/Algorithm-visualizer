#include "variable_template.hpp"

template<> std::string Variable<bool>::type() {
    return "Bool";
};

template<> std::string Variable<int>::type() {
    return "Integer";
};

template<> std::string Variable<float>::type() {
    return "Float";
};

template<> std::string Variable<double>::type() {
    return "Double";
};

template<> std::string Variable<std::string>::type() {
    return "String";
};
