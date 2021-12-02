
#include "expression.hpp"
#include "ast.hpp"
#ifndef BINOP_HPP
#define BINOP_HPP

//enum var_type {
//    unknown_var_type = 0,
//    string = 1,
//    integer = 2,
//    character = 3,
//    floating_point = 4

//};

//enum un_op {
//    unknown_un_op = 0,
//    negation = 1,
//    plusplus = 2
//    //inverse = 2 (if we add this as a unary operation for number -> -number)
//};

//enum bin_op {
//    unknown_bin_op = 0,
//    conjunction = 1,
//    disjunction = 2,
//    addition = 3,
//    subtraction = 4,
//    multiplication = 5,
//    division = 6,
//    lthan = 7,
//    mthan = 8,
//    leq = 9,
//    meq = 10,
//    eq = 11,
//    eqeq = 12
//};

//enum jump_type {
//    unknown_jump_type = 0,
//    br = 1,
//    cont = 2
//};
//enum expression_type {
//    unknown_expression_type = 0
//};




/*
//
class BoolExpression : public Expression {
    BoolExpression();
    ~BoolExpression();
    std::string get_subtype(){return "bool";};
private:

};

class IntExpression : public Expression {
    IntExpression();
    ~IntExpression();
    std::string get_subtype(){return "int";};
private:

};

class DoubleExpression : public Expression {
    DoubleExpression();
    ~DoubleExpression();
    std::string get_subtype(){return "double";};
private:

};
//







//
class BoolBinOp : public BoolExpression {
    BoolBinOp();
    ~BoolBinOp();
private:

};

class IntBinOp : public BoolExpression {
    IntBinOp();
    ~IntBinOp();
private:

};

class DoubleBinOp : public BoolExpression {
    DoubleBinOp();
    ~DoubleBinOp();
private:

};
//








class Intlthan : public BoolBinOp {
    Intlthan();
    ~Intlthan();
private:

};


class Intmthan : public BoolBinOp {
    Intmthan();
    ~Intmthan();
private:

};


class Doublelthan : public BoolBinOp {
    Doublelthan();
    ~Doublelthan();
private:

};


class Doublemthan : public BoolBinOp {
    Doublemthan();
    ~Doublemthan();
private:

};

class Intleq : public BoolBinOp {
    Intleq();
    ~Intleq();
private:

};


class Intmeq : public BoolBinOp {
    Intmeq();
    ~Intmeq();
private:

};


class Doubleleq : public BoolBinOp {
    Doubleleq();
    ~Doubleleq();
private:

};


class Doublemeq : public BoolBinOp {
    Doublemeq();
    ~Doublemeq();
private:

};


class Inteq : public BoolBinOp {
    Inteq();
    ~Inteq();
private:

};


class Doubleeq : public BoolBinOp {
    Doubleeq();
    ~Doubleeq();
private:

};


class Inteqeq : public BoolBinOp {
    Inteqeq();
    ~Inteqeq();
private:

};


class Doubleeqeq : public BoolBinOp {
    Doubleeqeq();
    ~Doubleeqeq();
private:

};


class IntDivision : public IntBinOp {
    IntDivision();
    ~IntDivision();
    int get_value(){
        if (get_subtype(left_exp) == "int" && get_subtype(right_exp) == "int"){
            return left_exp / right_exp;
        }
        return -1;
    };
private:
    Expression* left_exp;
    Expression* right_exp;
};


class DoubleDivision : public DoubleBinOp {
    DoubleDivision();
    ~DoubleDivision();
    double get_value(){
        if (get_subtype(left_exp) == "int" && get_subtype(right_exp) == "int"){
            return left_exp / right_exp;
        }
        return -1;
    };
private:
    Expression* left_exp;
    Expression* right_exp;
};


class IntMultiplication : public IntBinOp {
    IntMultiplication();
    ~IntMultiplication();
    int get_value(){
        if (get_subtype(left_exp) == "int" && get_subtype(right_exp) == "int"){
            return left_exp * right_exp;
        }
        return -1;
    };
private:
    Expression* left_exp;
    Expression* right_exp;
};


class DoubleMultiplication : public DoubleBinOp {
    DoubleMultiplication();
    ~DoubleMultiplication();
    double get_value(){
        if ((get_subtype(left_exp) == "int" && get_subtype(right_exp) == "double") ||
            (get_subtype(left_exp) == "double" && get_subtype(right_exp) == "int") ||
            (get_subtype(left_exp) == "double" && get_subtype(right_exp) == "double")){
            return left_exp * right_exp;
        }
        return -1;
    };
private:
    Expression* left_exp;
    Expression* right_exp;
};


class IntSubstraction : public IntBinOp {
    IntSubstraction();
    ~IntSubstraction();
    int get_value(){
        if (get_subtype(left_exp) == "int" && get_subtype(right_exp) == "int"){
            return left_exp - right_exp;
        }
        return -1;
    };
private:
    Expression* left_exp;
    Expression* right_exp;
};


class DoubleSubstraction : public DoubleBinOp {
    DoubleSubstraction();
    ~DoubleSubstraction();
    double get_value(){
        if ((get_subtype(left_exp) == "int" && get_subtype(right_exp) == "double") ||
            (get_subtype(left_exp) == "double" && get_subtype(right_exp) == "int") ||
            (get_subtype(left_exp) == "double" && get_subtype(right_exp) == "double")){
            return left_exp - right_exp;
        }
        return -1;
    };
private:
    Expression* left_exp;
    Expression* right_exp;
};


class IntAddition : public IntBinOp {
    IntAddition();
    ~IntAddition();
    int get_value(){
        if (get_subtype(left_exp) == "int" && get_subtype(right_exp) == "int"){
            return left_exp + right_exp;
        }
        return -1;
    };
private:
    Expression* left_exp;
    Expression* right_exp;
};


class DoubleAddition : public DoubleBinOp {
    DoubleAddition();
    ~DoubleAddition();
    double get_value(){
        if ((get_subtype(left_exp) == "int" && get_subtype(right_exp) == "double") ||
            (get_subtype(left_exp) == "double" && get_subtype(right_exp) == "int") ||
            (get_subtype(left_exp) == "double" && get_subtype(right_exp) == "double")){
            return left_exp + right_exp;
        }
        return -1;
    };
private:
    Expression* left_exp;
    Expression* right_exp;
};
*/








//
class BinOp : public Expression {
    BinOp();
    ~BinOp();
    void set_operation(bin_op op){operation = op;};
    void set_left_expression(Expression* l_e){left_exp = l_e;};
    void set_right_expression(Expression* r_e){right_exp = r_e;};
    std::string get_operation(){
        switch(operation) {
        case 0: return "unknown binary operation";
        case 1: return "conjunction";
        case 2: return "disjunction";
        case 3: return "addition";
        case 4: return "substraction";
        case 5: return "multiplication";
        case 6: return "division";
        case 7: return "lthan";
        case 8: return "mthan";
        case 9: return "leq";
        case 10: return "meq";
        case 11: return "eq";
        case 12: return "eqeq";
        }
    }
    Expression* get_left_expression(){return left_exp;};
    Expression* get_right_expression(){return right_exp;};
    std::string get_subtype(){return "BinOp";};
private:
    bin_op operation = unknown_bin_op;
    Expression* left_exp;
    Expression* right_exp;
};

#endif // BINOP_HPP
