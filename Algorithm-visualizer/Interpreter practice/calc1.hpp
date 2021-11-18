#include <stdio.h>
#include <ctype.h>
#include <stdexcept>

char* INTEGER = "INTEGER";
char* PLUS = "PLUS";
char* eof = "EOF";

class  Token{
public:
    Token(char* t, int v){type = t; value = v;};
    Token(){};
    Token(char* t){type = t;};
    char* get_type(){return type;};
    int get_value(){
        if (type != "PLUS"){
            return int(value);
        }
    };



private:
    char* type;
    int value;


};

class Interpreter{
public:
    Interpreter(char* t){text = t;};
    void error(){
        throw std::invalid_argument( "wrong format" );
        
    }
    Token get_next_token(){
        int len = 0;
        int i = 0;
        while (text[i] != '\n'){
            len ++;
            i++;
        }
        if (pos > len - 1){
            return Token(eof);
        }
        if (isdigit(text[pos])){
            return Token(INTEGER, int(text[pos]));
        }
        if (text[pos] == 43){
            return Token(PLUS, text[pos]);
        }

        error();
    }

    void eat(char* type){
        if (current_token.get_type() == type){
            current_token = (*this).get_next_token();
        }
        else{
            error();
        }
    }

    int expr(){
        current_token = (*this).get_next_token();
        Token left = current_token;
        (*this).eat(INTEGER);
        Token op = current_token;
        (*this).eat(PLUS);
        Token right = current_token;
        (*this).eat(INTEGER);
        return left.get_value() + right.get_value();
        
    }        
    



private:
    char* text;
    int pos = 0;
    Token current_token;
};