class Expression : public AST {
public : Expression();
public : Expression(expression_type t) {
        type = t;
    };
public : ~Expression();
std::string get_type(){return "Expression";};
virtual double get_value() = 0;
virtual std::string get_exp_type() = 0;
private:
    expression_type type = unknown_expression_type;
};

#endif // EXPRESSION_HPP
