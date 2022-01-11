/* parser/listener/visitor header section */

// Generated from /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST/grammar/AlgoParser.g4 by ANTLR 4.9.3

#pragma once

/* parser precinclude section */

#include "antlr4-runtime.h"


/* parser postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif


namespace antlrcpptest {

/* parser context section */

class  AlgoParser : public antlr4::Parser {
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

  enum {
    RuleFile = 0, RuleMainStmt = 1, RuleAssign = 2, RuleExp = 3, RuleVarDec = 4, 
    RuleWhileStmt = 5, RuleReturnStmt = 6, RuleNegation = 7, RuleBlock = 8, 
    RuleStmts = 9, RuleIfelse = 10, RuleIfrest = 11, RuleBoolType = 12, 
    RuleDoubleType = 13, RuleIntegerType = 14, RuleArrayType = 15, RuleString = 16, 
    RuleType = 17, RuleBinOp = 18, RuleUnop = 19, RuleIdentifier = 20, RuleVariable = 21, 
    RulePrint = 22, RuleJump = 23, RuleLibrary = 24
  };

  explicit AlgoParser(antlr4::TokenStream *input);
  ~AlgoParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  /* public parser declarations/members section */
  bool myAction() { return true; }
  bool doesItBlend() { return true; }
  void cleanUp() {}
  void doInit() {}
  void doAfter() {}


  class FileContext;
  class MainStmtContext;
  class AssignContext;
  class ExpContext;
  class VarDecContext;
  class WhileStmtContext;
  class ReturnStmtContext;
  class NegationContext;
  class BlockContext;
  class StmtsContext;
  class IfelseContext;
  class IfrestContext;
  class BoolTypeContext;
  class DoubleTypeContext;
  class IntegerTypeContext;
  class ArrayTypeContext;
  class StringContext;
  class TypeContext;
  class BinOpContext;
  class UnopContext;
  class IdentifierContext;
  class VariableContext;
  class PrintContext;
  class JumpContext;
  class LibraryContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MainStmtContext *mainStmt();
    std::vector<LibraryContext *> library();
    LibraryContext* library(size_t i);
    std::vector<StmtsContext *> stmts();
    StmtsContext* stmts(size_t i);

   
  };

  FileContext* file();

  class  MainStmtContext : public antlr4::ParserRuleContext {
  public:
    AlgoParser::BlockContext *body = nullptr;
    MainStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *MAIN();
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *RP();
    BlockContext *block();

   
  };

  MainStmtContext* mainStmt();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    AlgoParser::VariableContext *varName = nullptr;
    AlgoParser::ExpContext *index = nullptr;
    AlgoParser::ExpContext *val = nullptr;
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *SEMICOLON();
    VariableContext *variable();
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    antlr4::tree::TerminalNode *LSB();
    antlr4::tree::TerminalNode *RSB();

   
  };

  AssignContext* assign();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntegerTypeContext *integerType();
    DoubleTypeContext *doubleType();
    BoolTypeContext *boolType();
    StringContext *string();
    antlr4::tree::TerminalNode *LP();
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    antlr4::tree::TerminalNode *RP();
    UnopContext *unop();
    NegationContext *negation();
    IdentifierContext *identifier();
    ArrayTypeContext *arrayType();
    VariableContext *variable();
    BinOpContext *binOp();

   
  };

  ExpContext* exp();
  ExpContext* exp(int precedence);
  class  VarDecContext : public antlr4::ParserRuleContext {
  public:
    AlgoParser::VariableContext *varName = nullptr;
    AlgoParser::ExpContext *arrSize = nullptr;
    AlgoParser::ExpContext *val = nullptr;
    VarDecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *SEMICOLON();
    VariableContext *variable();
    antlr4::tree::TerminalNode *LSB();
    antlr4::tree::TerminalNode *RSB();
    antlr4::tree::TerminalNode *EQ();
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

   
  };

  VarDecContext* varDec();

  class  WhileStmtContext : public antlr4::ParserRuleContext {
  public:
    AlgoParser::ExpContext *cond = nullptr;
    AlgoParser::BlockContext *body = nullptr;
    WhileStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *RP();
    ExpContext *exp();
    BlockContext *block();

   
  };

  WhileStmtContext* whileStmt();

  class  ReturnStmtContext : public antlr4::ParserRuleContext {
  public:
    AlgoParser::ExpContext *val = nullptr;
    ReturnStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpContext *exp();

   
  };

  ReturnStmtContext* returnStmt();

  class  NegationContext : public antlr4::ParserRuleContext {
  public:
    NegationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS();
    ExpContext *exp();

   
  };

  NegationContext* negation();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCB();
    antlr4::tree::TerminalNode *RCB();
    std::vector<StmtsContext *> stmts();
    StmtsContext* stmts(size_t i);

   
  };

  BlockContext* block();

  class  StmtsContext : public antlr4::ParserRuleContext {
  public:
    StmtsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    WhileStmtContext *whileStmt();
    IfelseContext *ifelse();
    ReturnStmtContext *returnStmt();
    PrintContext *print();
    LibraryContext *library();
    VarDecContext *varDec();
    AssignContext *assign();
    ExpContext *exp();
    antlr4::tree::TerminalNode *SEMICOLON();
    JumpContext *jump();

   
  };

  StmtsContext* stmts();

  class  IfelseContext : public antlr4::ParserRuleContext {
  public:
    AlgoParser::ExpContext *cond = nullptr;
    AlgoParser::BlockContext *thn = nullptr;
    IfelseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *RP();
    IfrestContext *ifrest();
    ExpContext *exp();
    BlockContext *block();

   
  };

  IfelseContext* ifelse();

  class  IfrestContext : public antlr4::ParserRuleContext {
  public:
    AlgoParser::BlockContext *thn = nullptr;
    IfrestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSE();
    IfelseContext *ifelse();
    BlockContext *block();

   
  };

  IfrestContext* ifrest();

  class  BoolTypeContext : public antlr4::ParserRuleContext {
  public:
    BoolTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();

   
  };

  BoolTypeContext* boolType();

  class  DoubleTypeContext : public antlr4::ParserRuleContext {
  public:
    DoubleTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLOAT();

   
  };

  DoubleTypeContext* doubleType();

  class  IntegerTypeContext : public antlr4::ParserRuleContext {
  public:
    IntegerTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();

   
  };

  IntegerTypeContext* integerType();

  class  ArrayTypeContext : public antlr4::ParserRuleContext {
  public:
    ArrayTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCB();
    antlr4::tree::TerminalNode *RCB();
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  ArrayTypeContext* arrayType();

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> QUOTE();
    antlr4::tree::TerminalNode* QUOTE(size_t i);
    antlr4::tree::TerminalNode *STRING();

   
  };

  StringContext* string();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *STR();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *DOUBLE();
    antlr4::tree::TerminalNode *BOOLEAN();

   
  };

  TypeContext* type();

  class  BinOpContext : public antlr4::ParserRuleContext {
  public:
    BinOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *XOR();
    antlr4::tree::TerminalNode *XAND();
    antlr4::tree::TerminalNode *EQQ();
    antlr4::tree::TerminalNode *NOTEQQ();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *MT();
    antlr4::tree::TerminalNode *LEQ();
    antlr4::tree::TerminalNode *MEQ();

   
  };

  BinOpContext* binOp();

  class  UnopContext : public antlr4::ParserRuleContext {
  public:
    UnopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PLUSPLUS();
    antlr4::tree::TerminalNode *MINUSMINUS();

   
  };

  UnopContext* unop();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

   
  };

  IdentifierContext* identifier();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();

   
  };

  VariableContext* variable();

  class  PrintContext : public antlr4::ParserRuleContext {
  public:
    PrintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STDC();
    std::vector<antlr4::tree::TerminalNode *> LL();
    antlr4::tree::TerminalNode* LL(size_t i);
    ExpContext *exp();
    antlr4::tree::TerminalNode *STDE();
    antlr4::tree::TerminalNode *SEMICOLON();

   
  };

  PrintContext* print();

  class  JumpContext : public antlr4::ParserRuleContext {
  public:
    JumpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONT();
    antlr4::tree::TerminalNode *BREAK();

   
  };

  JumpContext* jump();

  class  LibraryContext : public antlr4::ParserRuleContext {
  public:
    LibraryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INCLUDE();
    std::vector<antlr4::tree::TerminalNode *> QUOTE();
    antlr4::tree::TerminalNode* QUOTE(size_t i);
    VariableContext *variable();

   
  };

  LibraryContext* library();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expSempred(ExpContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;

  /* private parser declarations section */

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace antlrcpptest
