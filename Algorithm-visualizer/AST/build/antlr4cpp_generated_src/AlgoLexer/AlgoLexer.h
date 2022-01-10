/* lexer header section */

// Generated from /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST/grammar/AlgoLexer.g4 by ANTLR 4.9.3

#pragma once

/* lexer precinclude section */

#include "antlr4-runtime.h"


/* lexer postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif


namespace antlrcpptest {

/* lexer context section */

class  AlgoLexer : public antlr4::Lexer {
public:
  enum {
    DUMMY = 1, WS = 2, INTEGER = 3, Digit = 4, FLOAT = 5, VAR = 6, MAIN = 7, 
    PLUS = 8, MINUS = 9, TIMES = 10, DIV = 11, MOD = 12, EQ = 13, LT = 14, 
    MT = 15, LEQ = 16, MEQ = 17, TRUE = 18, FALSE = 19, LP = 20, RP = 21, 
    LCB = 22, RCB = 23, LSB = 24, RSB = 25, SEMICOLON = 26, XOR = 27, XAND = 28, 
    EQQ = 29, NOTEQQ = 30, WHILE = 31, IF = 32, ELSE = 33, CONT = 34, BREAK = 35, 
    PLUSPLUS = 36, MINUSMINUS = 37, QUOTE = 38, RETURN = 39, DOT = 40, COMMA = 41, 
    LL = 42, STDC = 43, STDE = 44, INCLUDE = 45, INT = 46, CHAR = 47, STR = 48, 
    DOUBLE = 49, BOOLEAN = 50, STRING = 51, ID = 52
  };

  explicit AlgoLexer(antlr4::CharStream *input);
  ~AlgoLexer();

  /* public lexer declarations section */
  bool canTestFoo() { return true;}
  bool isItFoo() { return true; }
  bool isItBar() { return true; }

  void myFooLexerAction() { /* do something*/ };
  void myBarLexerAction() { /* do something*/ };

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;

  /* private lexer declarations/members section */

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace antlrcpptest
