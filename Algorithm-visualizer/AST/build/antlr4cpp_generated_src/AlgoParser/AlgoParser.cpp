/* parser/listener/visitor header section */

// Generated from /Users/dashazorkot/Downloads/ALGOVIZ/Algorithm-visualizer/Algorithm-visualizer/AST/grammar/AlgoParser.g4 by ANTLR 4.9.3

/* parser precinclude section */


#include "AlgoParser.h"


/* parser postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif


using namespace antlrcpp;
using namespace antlrcpptest;
using namespace antlr4;

AlgoParser::AlgoParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AlgoParser::~AlgoParser() {
  delete _interpreter;
}

std::string AlgoParser::getGrammarFileName() const {
  return "AlgoParser.g4";
}

const std::vector<std::string>& AlgoParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AlgoParser::getVocabulary() const {
  return _vocabulary;
}

/* parser definitions section */

//----------------- FileContext ------------------------------------------------------------------

AlgoParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AlgoParser::MainStmtContext* AlgoParser::FileContext::mainStmt() {
  return getRuleContext<AlgoParser::MainStmtContext>(0);
}

std::vector<AlgoParser::LibraryContext *> AlgoParser::FileContext::library() {
  return getRuleContexts<AlgoParser::LibraryContext>();
}

AlgoParser::LibraryContext* AlgoParser::FileContext::library(size_t i) {
  return getRuleContext<AlgoParser::LibraryContext>(i);
}

std::vector<AlgoParser::StmtsContext *> AlgoParser::FileContext::stmts() {
  return getRuleContexts<AlgoParser::StmtsContext>();
}

AlgoParser::StmtsContext* AlgoParser::FileContext::stmts(size_t i) {
  return getRuleContext<AlgoParser::StmtsContext>(i);
}


size_t AlgoParser::FileContext::getRuleIndex() const {
  return AlgoParser::RuleFile;
}


AlgoParser::FileContext* AlgoParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, AlgoParser::RuleFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AlgoParser::INCLUDE) {
      setState(50);
      library();
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(56);
    mainStmt();
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AlgoParser::INTEGER)
      | (1ULL << AlgoParser::FLOAT)
      | (1ULL << AlgoParser::MINUS)
      | (1ULL << AlgoParser::TRUE)
      | (1ULL << AlgoParser::FALSE)
      | (1ULL << AlgoParser::LP)
      | (1ULL << AlgoParser::LCB)
      | (1ULL << AlgoParser::WHILE)
      | (1ULL << AlgoParser::IF)
      | (1ULL << AlgoParser::CONT)
      | (1ULL << AlgoParser::BREAK)
      | (1ULL << AlgoParser::PLUSPLUS)
      | (1ULL << AlgoParser::MINUSMINUS)
      | (1ULL << AlgoParser::QUOTE)
      | (1ULL << AlgoParser::RETURN)
      | (1ULL << AlgoParser::STDC)
      | (1ULL << AlgoParser::INCLUDE)
      | (1ULL << AlgoParser::INT)
      | (1ULL << AlgoParser::CHAR)
      | (1ULL << AlgoParser::STR)
      | (1ULL << AlgoParser::DOUBLE)
      | (1ULL << AlgoParser::BOOLEAN)
      | (1ULL << AlgoParser::STRING)
      | (1ULL << AlgoParser::ID))) != 0)) {
      setState(57);
      stmts();
      setState(62);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainStmtContext ------------------------------------------------------------------

AlgoParser::MainStmtContext::MainStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AlgoParser::TypeContext* AlgoParser::MainStmtContext::type() {
  return getRuleContext<AlgoParser::TypeContext>(0);
}

tree::TerminalNode* AlgoParser::MainStmtContext::MAIN() {
  return getToken(AlgoParser::MAIN, 0);
}

tree::TerminalNode* AlgoParser::MainStmtContext::LP() {
  return getToken(AlgoParser::LP, 0);
}

tree::TerminalNode* AlgoParser::MainStmtContext::RP() {
  return getToken(AlgoParser::RP, 0);
}

AlgoParser::BlockContext* AlgoParser::MainStmtContext::block() {
  return getRuleContext<AlgoParser::BlockContext>(0);
}


size_t AlgoParser::MainStmtContext::getRuleIndex() const {
  return AlgoParser::RuleMainStmt;
}


AlgoParser::MainStmtContext* AlgoParser::mainStmt() {
  MainStmtContext *_localctx = _tracker.createInstance<MainStmtContext>(_ctx, getState());
  enterRule(_localctx, 2, AlgoParser::RuleMainStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    type();
    setState(64);
    match(AlgoParser::MAIN);
    setState(65);
    match(AlgoParser::LP);
    setState(66);
    match(AlgoParser::RP);
    setState(67);
    antlrcpp::downCast<MainStmtContext *>(_localctx)->body = block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

AlgoParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::AssignContext::EQ() {
  return getToken(AlgoParser::EQ, 0);
}

tree::TerminalNode* AlgoParser::AssignContext::SEMICOLON() {
  return getToken(AlgoParser::SEMICOLON, 0);
}

AlgoParser::VariableContext* AlgoParser::AssignContext::variable() {
  return getRuleContext<AlgoParser::VariableContext>(0);
}

std::vector<AlgoParser::ExpContext *> AlgoParser::AssignContext::exp() {
  return getRuleContexts<AlgoParser::ExpContext>();
}

AlgoParser::ExpContext* AlgoParser::AssignContext::exp(size_t i) {
  return getRuleContext<AlgoParser::ExpContext>(i);
}

tree::TerminalNode* AlgoParser::AssignContext::LSB() {
  return getToken(AlgoParser::LSB, 0);
}

tree::TerminalNode* AlgoParser::AssignContext::RSB() {
  return getToken(AlgoParser::RSB, 0);
}


size_t AlgoParser::AssignContext::getRuleIndex() const {
  return AlgoParser::RuleAssign;
}


AlgoParser::AssignContext* AlgoParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 4, AlgoParser::RuleAssign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    antlrcpp::downCast<AssignContext *>(_localctx)->varName = variable();
    setState(74);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AlgoParser::LSB) {
      setState(70);
      match(AlgoParser::LSB);
      setState(71);
      antlrcpp::downCast<AssignContext *>(_localctx)->index = exp(0);
      setState(72);
      match(AlgoParser::RSB);
    }
    setState(76);
    match(AlgoParser::EQ);
    setState(77);
    antlrcpp::downCast<AssignContext *>(_localctx)->val = exp(0);
    setState(78);
    match(AlgoParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

AlgoParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AlgoParser::IntegerTypeContext* AlgoParser::ExpContext::integerType() {
  return getRuleContext<AlgoParser::IntegerTypeContext>(0);
}

AlgoParser::DoubleTypeContext* AlgoParser::ExpContext::doubleType() {
  return getRuleContext<AlgoParser::DoubleTypeContext>(0);
}

AlgoParser::BoolTypeContext* AlgoParser::ExpContext::boolType() {
  return getRuleContext<AlgoParser::BoolTypeContext>(0);
}

AlgoParser::StringContext* AlgoParser::ExpContext::string() {
  return getRuleContext<AlgoParser::StringContext>(0);
}

tree::TerminalNode* AlgoParser::ExpContext::LP() {
  return getToken(AlgoParser::LP, 0);
}

std::vector<AlgoParser::ExpContext *> AlgoParser::ExpContext::exp() {
  return getRuleContexts<AlgoParser::ExpContext>();
}

AlgoParser::ExpContext* AlgoParser::ExpContext::exp(size_t i) {
  return getRuleContext<AlgoParser::ExpContext>(i);
}

tree::TerminalNode* AlgoParser::ExpContext::RP() {
  return getToken(AlgoParser::RP, 0);
}

AlgoParser::UnopContext* AlgoParser::ExpContext::unop() {
  return getRuleContext<AlgoParser::UnopContext>(0);
}

AlgoParser::NegationContext* AlgoParser::ExpContext::negation() {
  return getRuleContext<AlgoParser::NegationContext>(0);
}

AlgoParser::IdentifierContext* AlgoParser::ExpContext::identifier() {
  return getRuleContext<AlgoParser::IdentifierContext>(0);
}

AlgoParser::ArrayTypeContext* AlgoParser::ExpContext::arrayType() {
  return getRuleContext<AlgoParser::ArrayTypeContext>(0);
}

AlgoParser::VariableContext* AlgoParser::ExpContext::variable() {
  return getRuleContext<AlgoParser::VariableContext>(0);
}

AlgoParser::BinOpContext* AlgoParser::ExpContext::binOp() {
  return getRuleContext<AlgoParser::BinOpContext>(0);
}


size_t AlgoParser::ExpContext::getRuleIndex() const {
  return AlgoParser::RuleExp;
}



AlgoParser::ExpContext* AlgoParser::exp() {
   return exp(0);
}

AlgoParser::ExpContext* AlgoParser::exp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AlgoParser::ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, parentState);
  AlgoParser::ExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, AlgoParser::RuleExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(96);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AlgoParser::INTEGER: {
        setState(81);
        integerType();
        break;
      }

      case AlgoParser::FLOAT: {
        setState(82);
        doubleType();
        break;
      }

      case AlgoParser::TRUE:
      case AlgoParser::FALSE: {
        setState(83);
        boolType();
        break;
      }

      case AlgoParser::QUOTE: {
        setState(84);
        string();
        break;
      }

      case AlgoParser::LP: {
        setState(85);
        match(AlgoParser::LP);
        setState(86);
        exp(0);
        setState(87);
        match(AlgoParser::RP);
        break;
      }

      case AlgoParser::PLUSPLUS:
      case AlgoParser::MINUSMINUS: {
        setState(89);
        unop();
        setState(90);
        exp(6);
        break;
      }

      case AlgoParser::MINUS: {
        setState(92);
        negation();
        break;
      }

      case AlgoParser::ID: {
        setState(93);
        identifier();
        break;
      }

      case AlgoParser::LCB: {
        setState(94);
        arrayType();
        break;
      }

      case AlgoParser::STRING: {
        setState(95);
        variable();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(106);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(104);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(98);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(99);
          binOp();
          setState(100);
          exp(8);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(102);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(103);
          unop();
          break;
        }

        default:
          break;
        } 
      }
      setState(108);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarDecContext ------------------------------------------------------------------

AlgoParser::VarDecContext::VarDecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AlgoParser::TypeContext* AlgoParser::VarDecContext::type() {
  return getRuleContext<AlgoParser::TypeContext>(0);
}

tree::TerminalNode* AlgoParser::VarDecContext::SEMICOLON() {
  return getToken(AlgoParser::SEMICOLON, 0);
}

AlgoParser::VariableContext* AlgoParser::VarDecContext::variable() {
  return getRuleContext<AlgoParser::VariableContext>(0);
}

tree::TerminalNode* AlgoParser::VarDecContext::LSB() {
  return getToken(AlgoParser::LSB, 0);
}

tree::TerminalNode* AlgoParser::VarDecContext::RSB() {
  return getToken(AlgoParser::RSB, 0);
}

tree::TerminalNode* AlgoParser::VarDecContext::EQ() {
  return getToken(AlgoParser::EQ, 0);
}

std::vector<AlgoParser::ExpContext *> AlgoParser::VarDecContext::exp() {
  return getRuleContexts<AlgoParser::ExpContext>();
}

AlgoParser::ExpContext* AlgoParser::VarDecContext::exp(size_t i) {
  return getRuleContext<AlgoParser::ExpContext>(i);
}


size_t AlgoParser::VarDecContext::getRuleIndex() const {
  return AlgoParser::RuleVarDec;
}


AlgoParser::VarDecContext* AlgoParser::varDec() {
  VarDecContext *_localctx = _tracker.createInstance<VarDecContext>(_ctx, getState());
  enterRule(_localctx, 8, AlgoParser::RuleVarDec);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    type();
    setState(110);
    antlrcpp::downCast<VarDecContext *>(_localctx)->varName = variable();
    setState(115);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AlgoParser::LSB) {
      setState(111);
      match(AlgoParser::LSB);
      setState(112);
      antlrcpp::downCast<VarDecContext *>(_localctx)->arrSize = exp(0);
      setState(113);
      match(AlgoParser::RSB);
    }
    setState(119);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AlgoParser::EQ) {
      setState(117);
      match(AlgoParser::EQ);
      setState(118);
      antlrcpp::downCast<VarDecContext *>(_localctx)->val = exp(0);
    }
    setState(121);
    match(AlgoParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

AlgoParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::WhileStmtContext::WHILE() {
  return getToken(AlgoParser::WHILE, 0);
}

tree::TerminalNode* AlgoParser::WhileStmtContext::LP() {
  return getToken(AlgoParser::LP, 0);
}

tree::TerminalNode* AlgoParser::WhileStmtContext::RP() {
  return getToken(AlgoParser::RP, 0);
}

AlgoParser::ExpContext* AlgoParser::WhileStmtContext::exp() {
  return getRuleContext<AlgoParser::ExpContext>(0);
}

AlgoParser::BlockContext* AlgoParser::WhileStmtContext::block() {
  return getRuleContext<AlgoParser::BlockContext>(0);
}


size_t AlgoParser::WhileStmtContext::getRuleIndex() const {
  return AlgoParser::RuleWhileStmt;
}


AlgoParser::WhileStmtContext* AlgoParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 10, AlgoParser::RuleWhileStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(AlgoParser::WHILE);
    setState(124);
    match(AlgoParser::LP);
    setState(125);
    antlrcpp::downCast<WhileStmtContext *>(_localctx)->cond = exp(0);
    setState(126);
    match(AlgoParser::RP);
    setState(127);
    antlrcpp::downCast<WhileStmtContext *>(_localctx)->body = block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

AlgoParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::ReturnStmtContext::RETURN() {
  return getToken(AlgoParser::RETURN, 0);
}

tree::TerminalNode* AlgoParser::ReturnStmtContext::SEMICOLON() {
  return getToken(AlgoParser::SEMICOLON, 0);
}

AlgoParser::ExpContext* AlgoParser::ReturnStmtContext::exp() {
  return getRuleContext<AlgoParser::ExpContext>(0);
}


size_t AlgoParser::ReturnStmtContext::getRuleIndex() const {
  return AlgoParser::RuleReturnStmt;
}


AlgoParser::ReturnStmtContext* AlgoParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 12, AlgoParser::RuleReturnStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    match(AlgoParser::RETURN);
    setState(130);
    antlrcpp::downCast<ReturnStmtContext *>(_localctx)->val = exp(0);
    setState(131);
    match(AlgoParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NegationContext ------------------------------------------------------------------

AlgoParser::NegationContext::NegationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::NegationContext::MINUS() {
  return getToken(AlgoParser::MINUS, 0);
}

AlgoParser::ExpContext* AlgoParser::NegationContext::exp() {
  return getRuleContext<AlgoParser::ExpContext>(0);
}


size_t AlgoParser::NegationContext::getRuleIndex() const {
  return AlgoParser::RuleNegation;
}


AlgoParser::NegationContext* AlgoParser::negation() {
  NegationContext *_localctx = _tracker.createInstance<NegationContext>(_ctx, getState());
  enterRule(_localctx, 14, AlgoParser::RuleNegation);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(AlgoParser::MINUS);
    setState(134);
    exp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

AlgoParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::BlockContext::LCB() {
  return getToken(AlgoParser::LCB, 0);
}

tree::TerminalNode* AlgoParser::BlockContext::RCB() {
  return getToken(AlgoParser::RCB, 0);
}

std::vector<AlgoParser::StmtsContext *> AlgoParser::BlockContext::stmts() {
  return getRuleContexts<AlgoParser::StmtsContext>();
}

AlgoParser::StmtsContext* AlgoParser::BlockContext::stmts(size_t i) {
  return getRuleContext<AlgoParser::StmtsContext>(i);
}


size_t AlgoParser::BlockContext::getRuleIndex() const {
  return AlgoParser::RuleBlock;
}


AlgoParser::BlockContext* AlgoParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 16, AlgoParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(AlgoParser::LCB);
    setState(140);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AlgoParser::INTEGER)
      | (1ULL << AlgoParser::FLOAT)
      | (1ULL << AlgoParser::MINUS)
      | (1ULL << AlgoParser::TRUE)
      | (1ULL << AlgoParser::FALSE)
      | (1ULL << AlgoParser::LP)
      | (1ULL << AlgoParser::LCB)
      | (1ULL << AlgoParser::WHILE)
      | (1ULL << AlgoParser::IF)
      | (1ULL << AlgoParser::CONT)
      | (1ULL << AlgoParser::BREAK)
      | (1ULL << AlgoParser::PLUSPLUS)
      | (1ULL << AlgoParser::MINUSMINUS)
      | (1ULL << AlgoParser::QUOTE)
      | (1ULL << AlgoParser::RETURN)
      | (1ULL << AlgoParser::STDC)
      | (1ULL << AlgoParser::INCLUDE)
      | (1ULL << AlgoParser::INT)
      | (1ULL << AlgoParser::CHAR)
      | (1ULL << AlgoParser::STR)
      | (1ULL << AlgoParser::DOUBLE)
      | (1ULL << AlgoParser::BOOLEAN)
      | (1ULL << AlgoParser::STRING)
      | (1ULL << AlgoParser::ID))) != 0)) {
      setState(137);
      stmts();
      setState(142);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(143);
    match(AlgoParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtsContext ------------------------------------------------------------------

AlgoParser::StmtsContext::StmtsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AlgoParser::WhileStmtContext* AlgoParser::StmtsContext::whileStmt() {
  return getRuleContext<AlgoParser::WhileStmtContext>(0);
}

AlgoParser::IfelseContext* AlgoParser::StmtsContext::ifelse() {
  return getRuleContext<AlgoParser::IfelseContext>(0);
}

AlgoParser::ReturnStmtContext* AlgoParser::StmtsContext::returnStmt() {
  return getRuleContext<AlgoParser::ReturnStmtContext>(0);
}

AlgoParser::PrintContext* AlgoParser::StmtsContext::print() {
  return getRuleContext<AlgoParser::PrintContext>(0);
}

AlgoParser::LibraryContext* AlgoParser::StmtsContext::library() {
  return getRuleContext<AlgoParser::LibraryContext>(0);
}

AlgoParser::VarDecContext* AlgoParser::StmtsContext::varDec() {
  return getRuleContext<AlgoParser::VarDecContext>(0);
}

AlgoParser::AssignContext* AlgoParser::StmtsContext::assign() {
  return getRuleContext<AlgoParser::AssignContext>(0);
}

AlgoParser::ExpContext* AlgoParser::StmtsContext::exp() {
  return getRuleContext<AlgoParser::ExpContext>(0);
}

tree::TerminalNode* AlgoParser::StmtsContext::SEMICOLON() {
  return getToken(AlgoParser::SEMICOLON, 0);
}

AlgoParser::JumpContext* AlgoParser::StmtsContext::jump() {
  return getRuleContext<AlgoParser::JumpContext>(0);
}


size_t AlgoParser::StmtsContext::getRuleIndex() const {
  return AlgoParser::RuleStmts;
}


AlgoParser::StmtsContext* AlgoParser::stmts() {
  StmtsContext *_localctx = _tracker.createInstance<StmtsContext>(_ctx, getState());
  enterRule(_localctx, 18, AlgoParser::RuleStmts);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(145);
      whileStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(146);
      ifelse();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(147);
      returnStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(148);
      print();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(149);
      library();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(150);
      varDec();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(151);
      assign();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(152);
      exp(0);
      setState(153);
      match(AlgoParser::SEMICOLON);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(155);
      jump();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfelseContext ------------------------------------------------------------------

AlgoParser::IfelseContext::IfelseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::IfelseContext::IF() {
  return getToken(AlgoParser::IF, 0);
}

tree::TerminalNode* AlgoParser::IfelseContext::LP() {
  return getToken(AlgoParser::LP, 0);
}

tree::TerminalNode* AlgoParser::IfelseContext::RP() {
  return getToken(AlgoParser::RP, 0);
}

AlgoParser::IfrestContext* AlgoParser::IfelseContext::ifrest() {
  return getRuleContext<AlgoParser::IfrestContext>(0);
}

AlgoParser::ExpContext* AlgoParser::IfelseContext::exp() {
  return getRuleContext<AlgoParser::ExpContext>(0);
}

AlgoParser::BlockContext* AlgoParser::IfelseContext::block() {
  return getRuleContext<AlgoParser::BlockContext>(0);
}


size_t AlgoParser::IfelseContext::getRuleIndex() const {
  return AlgoParser::RuleIfelse;
}


AlgoParser::IfelseContext* AlgoParser::ifelse() {
  IfelseContext *_localctx = _tracker.createInstance<IfelseContext>(_ctx, getState());
  enterRule(_localctx, 20, AlgoParser::RuleIfelse);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    match(AlgoParser::IF);
    setState(159);
    match(AlgoParser::LP);
    setState(160);
    antlrcpp::downCast<IfelseContext *>(_localctx)->cond = exp(0);
    setState(161);
    match(AlgoParser::RP);
    setState(162);
    antlrcpp::downCast<IfelseContext *>(_localctx)->thn = block();
    setState(163);
    ifrest();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfrestContext ------------------------------------------------------------------

AlgoParser::IfrestContext::IfrestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::IfrestContext::ELSE() {
  return getToken(AlgoParser::ELSE, 0);
}

AlgoParser::IfelseContext* AlgoParser::IfrestContext::ifelse() {
  return getRuleContext<AlgoParser::IfelseContext>(0);
}

AlgoParser::BlockContext* AlgoParser::IfrestContext::block() {
  return getRuleContext<AlgoParser::BlockContext>(0);
}


size_t AlgoParser::IfrestContext::getRuleIndex() const {
  return AlgoParser::RuleIfrest;
}


AlgoParser::IfrestContext* AlgoParser::ifrest() {
  IfrestContext *_localctx = _tracker.createInstance<IfrestContext>(_ctx, getState());
  enterRule(_localctx, 22, AlgoParser::RuleIfrest);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(169);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(165);
      match(AlgoParser::ELSE);
      setState(166);
      ifelse();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(167);
      match(AlgoParser::ELSE);
      setState(168);
      antlrcpp::downCast<IfrestContext *>(_localctx)->thn = block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolTypeContext ------------------------------------------------------------------

AlgoParser::BoolTypeContext::BoolTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::BoolTypeContext::TRUE() {
  return getToken(AlgoParser::TRUE, 0);
}

tree::TerminalNode* AlgoParser::BoolTypeContext::FALSE() {
  return getToken(AlgoParser::FALSE, 0);
}


size_t AlgoParser::BoolTypeContext::getRuleIndex() const {
  return AlgoParser::RuleBoolType;
}


AlgoParser::BoolTypeContext* AlgoParser::boolType() {
  BoolTypeContext *_localctx = _tracker.createInstance<BoolTypeContext>(_ctx, getState());
  enterRule(_localctx, 24, AlgoParser::RuleBoolType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    _la = _input->LA(1);
    if (!(_la == AlgoParser::TRUE

    || _la == AlgoParser::FALSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DoubleTypeContext ------------------------------------------------------------------

AlgoParser::DoubleTypeContext::DoubleTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::DoubleTypeContext::FLOAT() {
  return getToken(AlgoParser::FLOAT, 0);
}


size_t AlgoParser::DoubleTypeContext::getRuleIndex() const {
  return AlgoParser::RuleDoubleType;
}


AlgoParser::DoubleTypeContext* AlgoParser::doubleType() {
  DoubleTypeContext *_localctx = _tracker.createInstance<DoubleTypeContext>(_ctx, getState());
  enterRule(_localctx, 26, AlgoParser::RuleDoubleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    match(AlgoParser::FLOAT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerTypeContext ------------------------------------------------------------------

AlgoParser::IntegerTypeContext::IntegerTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::IntegerTypeContext::INTEGER() {
  return getToken(AlgoParser::INTEGER, 0);
}


size_t AlgoParser::IntegerTypeContext::getRuleIndex() const {
  return AlgoParser::RuleIntegerType;
}


AlgoParser::IntegerTypeContext* AlgoParser::integerType() {
  IntegerTypeContext *_localctx = _tracker.createInstance<IntegerTypeContext>(_ctx, getState());
  enterRule(_localctx, 28, AlgoParser::RuleIntegerType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(AlgoParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

AlgoParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::ArrayTypeContext::LCB() {
  return getToken(AlgoParser::LCB, 0);
}

tree::TerminalNode* AlgoParser::ArrayTypeContext::RCB() {
  return getToken(AlgoParser::RCB, 0);
}

std::vector<AlgoParser::ExpContext *> AlgoParser::ArrayTypeContext::exp() {
  return getRuleContexts<AlgoParser::ExpContext>();
}

AlgoParser::ExpContext* AlgoParser::ArrayTypeContext::exp(size_t i) {
  return getRuleContext<AlgoParser::ExpContext>(i);
}

std::vector<tree::TerminalNode *> AlgoParser::ArrayTypeContext::COMMA() {
  return getTokens(AlgoParser::COMMA);
}

tree::TerminalNode* AlgoParser::ArrayTypeContext::COMMA(size_t i) {
  return getToken(AlgoParser::COMMA, i);
}


size_t AlgoParser::ArrayTypeContext::getRuleIndex() const {
  return AlgoParser::RuleArrayType;
}


AlgoParser::ArrayTypeContext* AlgoParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 30, AlgoParser::RuleArrayType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(AlgoParser::LCB);
    setState(185);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AlgoParser::INTEGER)
      | (1ULL << AlgoParser::FLOAT)
      | (1ULL << AlgoParser::MINUS)
      | (1ULL << AlgoParser::TRUE)
      | (1ULL << AlgoParser::FALSE)
      | (1ULL << AlgoParser::LP)
      | (1ULL << AlgoParser::LCB)
      | (1ULL << AlgoParser::PLUSPLUS)
      | (1ULL << AlgoParser::MINUSMINUS)
      | (1ULL << AlgoParser::QUOTE)
      | (1ULL << AlgoParser::STRING)
      | (1ULL << AlgoParser::ID))) != 0)) {
      setState(178);
      exp(0);
      setState(181); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(179);
        match(AlgoParser::COMMA);
        setState(180);
        exp(0);
        setState(183); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == AlgoParser::COMMA);
    }
    setState(187);
    match(AlgoParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

AlgoParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AlgoParser::StringContext::QUOTE() {
  return getTokens(AlgoParser::QUOTE);
}

tree::TerminalNode* AlgoParser::StringContext::QUOTE(size_t i) {
  return getToken(AlgoParser::QUOTE, i);
}

tree::TerminalNode* AlgoParser::StringContext::STRING() {
  return getToken(AlgoParser::STRING, 0);
}


size_t AlgoParser::StringContext::getRuleIndex() const {
  return AlgoParser::RuleString;
}


AlgoParser::StringContext* AlgoParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 32, AlgoParser::RuleString);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    match(AlgoParser::QUOTE);
    setState(190);
    match(AlgoParser::STRING);
    setState(191);
    match(AlgoParser::QUOTE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AlgoParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::TypeContext::INT() {
  return getToken(AlgoParser::INT, 0);
}

tree::TerminalNode* AlgoParser::TypeContext::STR() {
  return getToken(AlgoParser::STR, 0);
}

tree::TerminalNode* AlgoParser::TypeContext::CHAR() {
  return getToken(AlgoParser::CHAR, 0);
}

tree::TerminalNode* AlgoParser::TypeContext::DOUBLE() {
  return getToken(AlgoParser::DOUBLE, 0);
}

tree::TerminalNode* AlgoParser::TypeContext::BOOLEAN() {
  return getToken(AlgoParser::BOOLEAN, 0);
}


size_t AlgoParser::TypeContext::getRuleIndex() const {
  return AlgoParser::RuleType;
}


AlgoParser::TypeContext* AlgoParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 34, AlgoParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AlgoParser::INT)
      | (1ULL << AlgoParser::CHAR)
      | (1ULL << AlgoParser::STR)
      | (1ULL << AlgoParser::DOUBLE)
      | (1ULL << AlgoParser::BOOLEAN))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinOpContext ------------------------------------------------------------------

AlgoParser::BinOpContext::BinOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::BinOpContext::PLUS() {
  return getToken(AlgoParser::PLUS, 0);
}

tree::TerminalNode* AlgoParser::BinOpContext::MINUS() {
  return getToken(AlgoParser::MINUS, 0);
}

tree::TerminalNode* AlgoParser::BinOpContext::TIMES() {
  return getToken(AlgoParser::TIMES, 0);
}

tree::TerminalNode* AlgoParser::BinOpContext::DIV() {
  return getToken(AlgoParser::DIV, 0);
}

tree::TerminalNode* AlgoParser::BinOpContext::MOD() {
  return getToken(AlgoParser::MOD, 0);
}

tree::TerminalNode* AlgoParser::BinOpContext::XOR() {
  return getToken(AlgoParser::XOR, 0);
}

tree::TerminalNode* AlgoParser::BinOpContext::XAND() {
  return getToken(AlgoParser::XAND, 0);
}

tree::TerminalNode* AlgoParser::BinOpContext::EQQ() {
  return getToken(AlgoParser::EQQ, 0);
}

tree::TerminalNode* AlgoParser::BinOpContext::NOTEQQ() {
  return getToken(AlgoParser::NOTEQQ, 0);
}

tree::TerminalNode* AlgoParser::BinOpContext::LT() {
  return getToken(AlgoParser::LT, 0);
}

tree::TerminalNode* AlgoParser::BinOpContext::MT() {
  return getToken(AlgoParser::MT, 0);
}

tree::TerminalNode* AlgoParser::BinOpContext::LEQ() {
  return getToken(AlgoParser::LEQ, 0);
}

tree::TerminalNode* AlgoParser::BinOpContext::MEQ() {
  return getToken(AlgoParser::MEQ, 0);
}


size_t AlgoParser::BinOpContext::getRuleIndex() const {
  return AlgoParser::RuleBinOp;
}


AlgoParser::BinOpContext* AlgoParser::binOp() {
  BinOpContext *_localctx = _tracker.createInstance<BinOpContext>(_ctx, getState());
  enterRule(_localctx, 36, AlgoParser::RuleBinOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AlgoParser::PLUS)
      | (1ULL << AlgoParser::MINUS)
      | (1ULL << AlgoParser::TIMES)
      | (1ULL << AlgoParser::DIV)
      | (1ULL << AlgoParser::MOD)
      | (1ULL << AlgoParser::LT)
      | (1ULL << AlgoParser::MT)
      | (1ULL << AlgoParser::LEQ)
      | (1ULL << AlgoParser::MEQ)
      | (1ULL << AlgoParser::XOR)
      | (1ULL << AlgoParser::XAND)
      | (1ULL << AlgoParser::EQQ)
      | (1ULL << AlgoParser::NOTEQQ))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnopContext ------------------------------------------------------------------

AlgoParser::UnopContext::UnopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::UnopContext::PLUSPLUS() {
  return getToken(AlgoParser::PLUSPLUS, 0);
}

tree::TerminalNode* AlgoParser::UnopContext::MINUSMINUS() {
  return getToken(AlgoParser::MINUSMINUS, 0);
}


size_t AlgoParser::UnopContext::getRuleIndex() const {
  return AlgoParser::RuleUnop;
}


AlgoParser::UnopContext* AlgoParser::unop() {
  UnopContext *_localctx = _tracker.createInstance<UnopContext>(_ctx, getState());
  enterRule(_localctx, 38, AlgoParser::RuleUnop);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(197);
    _la = _input->LA(1);
    if (!(_la == AlgoParser::PLUSPLUS

    || _la == AlgoParser::MINUSMINUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

AlgoParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::IdentifierContext::ID() {
  return getToken(AlgoParser::ID, 0);
}


size_t AlgoParser::IdentifierContext::getRuleIndex() const {
  return AlgoParser::RuleIdentifier;
}


AlgoParser::IdentifierContext* AlgoParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 40, AlgoParser::RuleIdentifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(AlgoParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

AlgoParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::VariableContext::STRING() {
  return getToken(AlgoParser::STRING, 0);
}


size_t AlgoParser::VariableContext::getRuleIndex() const {
  return AlgoParser::RuleVariable;
}


AlgoParser::VariableContext* AlgoParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 42, AlgoParser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    match(AlgoParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintContext ------------------------------------------------------------------

AlgoParser::PrintContext::PrintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::PrintContext::STDC() {
  return getToken(AlgoParser::STDC, 0);
}

std::vector<tree::TerminalNode *> AlgoParser::PrintContext::LL() {
  return getTokens(AlgoParser::LL);
}

tree::TerminalNode* AlgoParser::PrintContext::LL(size_t i) {
  return getToken(AlgoParser::LL, i);
}

AlgoParser::ExpContext* AlgoParser::PrintContext::exp() {
  return getRuleContext<AlgoParser::ExpContext>(0);
}

tree::TerminalNode* AlgoParser::PrintContext::STDE() {
  return getToken(AlgoParser::STDE, 0);
}

tree::TerminalNode* AlgoParser::PrintContext::SEMICOLON() {
  return getToken(AlgoParser::SEMICOLON, 0);
}


size_t AlgoParser::PrintContext::getRuleIndex() const {
  return AlgoParser::RulePrint;
}


AlgoParser::PrintContext* AlgoParser::print() {
  PrintContext *_localctx = _tracker.createInstance<PrintContext>(_ctx, getState());
  enterRule(_localctx, 44, AlgoParser::RulePrint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    match(AlgoParser::STDC);
    setState(204);
    match(AlgoParser::LL);
    setState(205);
    exp(0);
    setState(206);
    match(AlgoParser::LL);
    setState(207);
    match(AlgoParser::STDE);
    setState(208);
    match(AlgoParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JumpContext ------------------------------------------------------------------

AlgoParser::JumpContext::JumpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::JumpContext::CONT() {
  return getToken(AlgoParser::CONT, 0);
}

tree::TerminalNode* AlgoParser::JumpContext::BREAK() {
  return getToken(AlgoParser::BREAK, 0);
}


size_t AlgoParser::JumpContext::getRuleIndex() const {
  return AlgoParser::RuleJump;
}


AlgoParser::JumpContext* AlgoParser::jump() {
  JumpContext *_localctx = _tracker.createInstance<JumpContext>(_ctx, getState());
  enterRule(_localctx, 46, AlgoParser::RuleJump);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    _la = _input->LA(1);
    if (!(_la == AlgoParser::CONT

    || _la == AlgoParser::BREAK)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LibraryContext ------------------------------------------------------------------

AlgoParser::LibraryContext::LibraryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AlgoParser::LibraryContext::INCLUDE() {
  return getToken(AlgoParser::INCLUDE, 0);
}

std::vector<tree::TerminalNode *> AlgoParser::LibraryContext::QUOTE() {
  return getTokens(AlgoParser::QUOTE);
}

tree::TerminalNode* AlgoParser::LibraryContext::QUOTE(size_t i) {
  return getToken(AlgoParser::QUOTE, i);
}

AlgoParser::VariableContext* AlgoParser::LibraryContext::variable() {
  return getRuleContext<AlgoParser::VariableContext>(0);
}


size_t AlgoParser::LibraryContext::getRuleIndex() const {
  return AlgoParser::RuleLibrary;
}


AlgoParser::LibraryContext* AlgoParser::library() {
  LibraryContext *_localctx = _tracker.createInstance<LibraryContext>(_ctx, getState());
  enterRule(_localctx, 48, AlgoParser::RuleLibrary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(AlgoParser::INCLUDE);
    setState(213);
    match(AlgoParser::QUOTE);
    setState(214);
    variable();
    setState(215);
    match(AlgoParser::QUOTE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AlgoParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return expSempred(antlrcpp::downCast<ExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AlgoParser::expSempred(ExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> AlgoParser::_decisionToDFA;
atn::PredictionContextCache AlgoParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AlgoParser::_atn;
std::vector<uint16_t> AlgoParser::_serializedATN;

std::vector<std::string> AlgoParser::_ruleNames = {
  "file", "mainStmt", "assign", "exp", "varDec", "whileStmt", "returnStmt", 
  "negation", "block", "stmts", "ifelse", "ifrest", "boolType", "doubleType", 
  "integerType", "arrayType", "string", "type", "binOp", "unop", "identifier", 
  "variable", "print", "jump", "library"
};

std::vector<std::string> AlgoParser::_literalNames = {
  "", "", "", "", "", "", "'var '", "'main'", "'+'", "'-'", "'*'", "'/'", 
  "'%'", "'='", "'<'", "'>'", "'<='", "'>='", "'true'", "'false'", "'('", 
  "')'", "'{'", "'}'", "'['", "']'", "';'", "'||'", "'&&'", "'=='", "'!='", 
  "'while'", "'if'", "'else'", "'continue'", "'break'", "'++'", "'--'", 
  "'\"'", "'return'", "'.'", "','", "'<<'", "'std::cout'", "'std::endl'", 
  "'#include'", "'int'", "'char'", "'str'", "'double'", "'bool'"
};

std::vector<std::string> AlgoParser::_symbolicNames = {
  "", "DUMMY", "WS", "INTEGER", "Digit", "FLOAT", "VAR", "MAIN", "PLUS", 
  "MINUS", "TIMES", "DIV", "MOD", "EQ", "LT", "MT", "LEQ", "MEQ", "TRUE", 
  "FALSE", "LP", "RP", "LCB", "RCB", "LSB", "RSB", "SEMICOLON", "XOR", "XAND", 
  "EQQ", "NOTEQQ", "WHILE", "IF", "ELSE", "CONT", "BREAK", "PLUSPLUS", "MINUSMINUS", 
  "QUOTE", "RETURN", "DOT", "COMMA", "LL", "STDC", "STDE", "INCLUDE", "INT", 
  "CHAR", "STR", "DOUBLE", "BOOLEAN", "STRING", "ID"
};

dfa::Vocabulary AlgoParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AlgoParser::_tokenNames;

AlgoParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x36, 0xdc, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x3, 0x2, 0x7, 0x2, 0x36, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
       0x39, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x3d, 0xa, 0x2, 0xc, 
       0x2, 0xe, 0x2, 0x40, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x5, 0x4, 0x4d, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x63, 0xa, 0x5, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 
       0x5, 0x6b, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x6e, 0xb, 0x5, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x76, 
       0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x7a, 0xa, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
       0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x8d, 0xa, 0xa, 0xc, 0xa, 
       0xe, 0xa, 0x90, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x9f, 0xa, 0xb, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xac, 0xa, 0xd, 0x3, 0xe, 
       0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 
       0x11, 0x3, 0x11, 0x3, 0x11, 0x6, 0x11, 0xb8, 0xa, 0x11, 0xd, 0x11, 
       0xe, 0x11, 0xb9, 0x5, 0x11, 0xbc, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 
       0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 
       0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 
       0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
       0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x2, 0x3, 
       0x8, 0x1b, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
       0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
       0x2e, 0x30, 0x32, 0x2, 0x7, 0x3, 0x2, 0x14, 0x15, 0x3, 0x2, 0x30, 
       0x34, 0x5, 0x2, 0xa, 0xe, 0x10, 0x13, 0x1d, 0x20, 0x3, 0x2, 0x26, 
       0x27, 0x3, 0x2, 0x24, 0x25, 0x2, 0xde, 0x2, 0x37, 0x3, 0x2, 0x2, 
       0x2, 0x4, 0x41, 0x3, 0x2, 0x2, 0x2, 0x6, 0x47, 0x3, 0x2, 0x2, 0x2, 
       0x8, 0x62, 0x3, 0x2, 0x2, 0x2, 0xa, 0x6f, 0x3, 0x2, 0x2, 0x2, 0xc, 
       0x7d, 0x3, 0x2, 0x2, 0x2, 0xe, 0x83, 0x3, 0x2, 0x2, 0x2, 0x10, 0x87, 
       0x3, 0x2, 0x2, 0x2, 0x12, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x14, 0x9e, 0x3, 
       0x2, 0x2, 0x2, 0x16, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x18, 0xab, 0x3, 0x2, 
       0x2, 0x2, 0x1a, 0xad, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xaf, 0x3, 0x2, 0x2, 
       0x2, 0x1e, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x20, 0xb3, 0x3, 0x2, 0x2, 0x2, 
       0x22, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x24, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x26, 
       0xc5, 0x3, 0x2, 0x2, 0x2, 0x28, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xc9, 
       0x3, 0x2, 0x2, 0x2, 0x2c, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xcd, 0x3, 
       0x2, 0x2, 0x2, 0x30, 0xd4, 0x3, 0x2, 0x2, 0x2, 0x32, 0xd6, 0x3, 0x2, 
       0x2, 0x2, 0x34, 0x36, 0x5, 0x32, 0x1a, 0x2, 0x35, 0x34, 0x3, 0x2, 
       0x2, 0x2, 0x36, 0x39, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 
       0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3a, 0x3, 0x2, 0x2, 0x2, 
       0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3e, 0x5, 0x4, 0x3, 0x2, 0x3b, 
       0x3d, 0x5, 0x14, 0xb, 0x2, 0x3c, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 
       0x40, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 
       0x3, 0x2, 0x2, 0x2, 0x3f, 0x3, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 
       0x2, 0x2, 0x2, 0x41, 0x42, 0x5, 0x24, 0x13, 0x2, 0x42, 0x43, 0x7, 
       0x9, 0x2, 0x2, 0x43, 0x44, 0x7, 0x16, 0x2, 0x2, 0x44, 0x45, 0x7, 
       0x17, 0x2, 0x2, 0x45, 0x46, 0x5, 0x12, 0xa, 0x2, 0x46, 0x5, 0x3, 
       0x2, 0x2, 0x2, 0x47, 0x4c, 0x5, 0x2c, 0x17, 0x2, 0x48, 0x49, 0x7, 
       0x1a, 0x2, 0x2, 0x49, 0x4a, 0x5, 0x8, 0x5, 0x2, 0x4a, 0x4b, 0x7, 
       0x1b, 0x2, 0x2, 0x4b, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x48, 0x3, 
       0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x3, 0x2, 
       0x2, 0x2, 0x4e, 0x4f, 0x7, 0xf, 0x2, 0x2, 0x4f, 0x50, 0x5, 0x8, 0x5, 
       0x2, 0x50, 0x51, 0x7, 0x1c, 0x2, 0x2, 0x51, 0x7, 0x3, 0x2, 0x2, 0x2, 
       0x52, 0x53, 0x8, 0x5, 0x1, 0x2, 0x53, 0x63, 0x5, 0x1e, 0x10, 0x2, 
       0x54, 0x63, 0x5, 0x1c, 0xf, 0x2, 0x55, 0x63, 0x5, 0x1a, 0xe, 0x2, 
       0x56, 0x63, 0x5, 0x22, 0x12, 0x2, 0x57, 0x58, 0x7, 0x16, 0x2, 0x2, 
       0x58, 0x59, 0x5, 0x8, 0x5, 0x2, 0x59, 0x5a, 0x7, 0x17, 0x2, 0x2, 
       0x5a, 0x63, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0x28, 0x15, 0x2, 
       0x5c, 0x5d, 0x5, 0x8, 0x5, 0x8, 0x5d, 0x63, 0x3, 0x2, 0x2, 0x2, 0x5e, 
       0x63, 0x5, 0x10, 0x9, 0x2, 0x5f, 0x63, 0x5, 0x2a, 0x16, 0x2, 0x60, 
       0x63, 0x5, 0x20, 0x11, 0x2, 0x61, 0x63, 0x5, 0x2c, 0x17, 0x2, 0x62, 
       0x52, 0x3, 0x2, 0x2, 0x2, 0x62, 0x54, 0x3, 0x2, 0x2, 0x2, 0x62, 0x55, 
       0x3, 0x2, 0x2, 0x2, 0x62, 0x56, 0x3, 0x2, 0x2, 0x2, 0x62, 0x57, 0x3, 
       0x2, 0x2, 0x2, 0x62, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x62, 0x5e, 0x3, 0x2, 
       0x2, 0x2, 0x62, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 
       0x2, 0x62, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x6c, 0x3, 0x2, 0x2, 0x2, 
       0x64, 0x65, 0xc, 0x9, 0x2, 0x2, 0x65, 0x66, 0x5, 0x26, 0x14, 0x2, 
       0x66, 0x67, 0x5, 0x8, 0x5, 0xa, 0x67, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x68, 
       0x69, 0xc, 0x7, 0x2, 0x2, 0x69, 0x6b, 0x5, 0x28, 0x15, 0x2, 0x6a, 
       0x64, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6e, 
       0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 
       0x2, 0x2, 0x2, 0x6d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 
       0x2, 0x2, 0x6f, 0x70, 0x5, 0x24, 0x13, 0x2, 0x70, 0x75, 0x5, 0x2c, 
       0x17, 0x2, 0x71, 0x72, 0x7, 0x1a, 0x2, 0x2, 0x72, 0x73, 0x5, 0x8, 
       0x5, 0x2, 0x73, 0x74, 0x7, 0x1b, 0x2, 0x2, 0x74, 0x76, 0x3, 0x2, 
       0x2, 0x2, 0x75, 0x71, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 
       0x2, 0x76, 0x79, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0xf, 0x2, 0x2, 
       0x78, 0x7a, 0x5, 0x8, 0x5, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 
       0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 
       0x7, 0x1c, 0x2, 0x2, 0x7c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x7, 
       0x21, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x16, 0x2, 0x2, 0x7f, 0x80, 0x5, 
       0x8, 0x5, 0x2, 0x80, 0x81, 0x7, 0x17, 0x2, 0x2, 0x81, 0x82, 0x5, 
       0x12, 0xa, 0x2, 0x82, 0xd, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x7, 0x29, 
       0x2, 0x2, 0x84, 0x85, 0x5, 0x8, 0x5, 0x2, 0x85, 0x86, 0x7, 0x1c, 
       0x2, 0x2, 0x86, 0xf, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x7, 0xb, 0x2, 
       0x2, 0x88, 0x89, 0x5, 0x8, 0x5, 0x2, 0x89, 0x11, 0x3, 0x2, 0x2, 0x2, 
       0x8a, 0x8e, 0x7, 0x18, 0x2, 0x2, 0x8b, 0x8d, 0x5, 0x14, 0xb, 0x2, 
       0x8c, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 
       0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x91, 
       0x3, 0x2, 0x2, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x7, 
       0x19, 0x2, 0x2, 0x92, 0x13, 0x3, 0x2, 0x2, 0x2, 0x93, 0x9f, 0x5, 
       0xc, 0x7, 0x2, 0x94, 0x9f, 0x5, 0x16, 0xc, 0x2, 0x95, 0x9f, 0x5, 
       0xe, 0x8, 0x2, 0x96, 0x9f, 0x5, 0x2e, 0x18, 0x2, 0x97, 0x9f, 0x5, 
       0x32, 0x1a, 0x2, 0x98, 0x9f, 0x5, 0xa, 0x6, 0x2, 0x99, 0x9f, 0x5, 
       0x6, 0x4, 0x2, 0x9a, 0x9b, 0x5, 0x8, 0x5, 0x2, 0x9b, 0x9c, 0x7, 0x1c, 
       0x2, 0x2, 0x9c, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9f, 0x5, 0x30, 
       0x19, 0x2, 0x9e, 0x93, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x94, 0x3, 0x2, 
       0x2, 0x2, 0x9e, 0x95, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x96, 0x3, 0x2, 0x2, 
       0x2, 0x9e, 0x97, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x98, 0x3, 0x2, 0x2, 0x2, 
       0x9e, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9e, 
       0x9d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 
       0x7, 0x22, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x16, 0x2, 0x2, 0xa2, 0xa3, 
       0x5, 0x8, 0x5, 0x2, 0xa3, 0xa4, 0x7, 0x17, 0x2, 0x2, 0xa4, 0xa5, 
       0x5, 0x12, 0xa, 0x2, 0xa5, 0xa6, 0x5, 0x18, 0xd, 0x2, 0xa6, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x23, 0x2, 0x2, 0xa8, 0xac, 
       0x5, 0x16, 0xc, 0x2, 0xa9, 0xaa, 0x7, 0x23, 0x2, 0x2, 0xaa, 0xac, 
       0x5, 0x12, 0xa, 0x2, 0xab, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa9, 
       0x3, 0x2, 0x2, 0x2, 0xac, 0x19, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x9, 
       0x2, 0x2, 0x2, 0xae, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x7, 
       0x2, 0x2, 0xb0, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x5, 0x2, 
       0x2, 0xb2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xbb, 0x7, 0x18, 0x2, 
       0x2, 0xb4, 0xb7, 0x5, 0x8, 0x5, 0x2, 0xb5, 0xb6, 0x7, 0x2b, 0x2, 
       0x2, 0xb6, 0xb8, 0x5, 0x8, 0x5, 0x2, 0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 
       0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 
       0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xb4, 
       0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 
       0x2, 0x2, 0x2, 0xbd, 0xbe, 0x7, 0x19, 0x2, 0x2, 0xbe, 0x21, 0x3, 
       0x2, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x28, 0x2, 0x2, 0xc0, 0xc1, 0x7, 
       0x35, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x28, 0x2, 0x2, 0xc2, 0x23, 0x3, 
       0x2, 0x2, 0x2, 0xc3, 0xc4, 0x9, 0x3, 0x2, 0x2, 0xc4, 0x25, 0x3, 0x2, 
       0x2, 0x2, 0xc5, 0xc6, 0x9, 0x4, 0x2, 0x2, 0xc6, 0x27, 0x3, 0x2, 0x2, 
       0x2, 0xc7, 0xc8, 0x9, 0x5, 0x2, 0x2, 0xc8, 0x29, 0x3, 0x2, 0x2, 0x2, 
       0xc9, 0xca, 0x7, 0x36, 0x2, 0x2, 0xca, 0x2b, 0x3, 0x2, 0x2, 0x2, 
       0xcb, 0xcc, 0x7, 0x35, 0x2, 0x2, 0xcc, 0x2d, 0x3, 0x2, 0x2, 0x2, 
       0xcd, 0xce, 0x7, 0x2d, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x2c, 0x2, 0x2, 
       0xcf, 0xd0, 0x5, 0x8, 0x5, 0x2, 0xd0, 0xd1, 0x7, 0x2c, 0x2, 0x2, 
       0xd1, 0xd2, 0x7, 0x2e, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x1c, 0x2, 0x2, 
       0xd3, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x9, 0x6, 0x2, 0x2, 0xd5, 
       0x31, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x2f, 0x2, 0x2, 0xd7, 
       0xd8, 0x7, 0x28, 0x2, 0x2, 0xd8, 0xd9, 0x5, 0x2c, 0x17, 0x2, 0xd9, 
       0xda, 0x7, 0x28, 0x2, 0x2, 0xda, 0x33, 0x3, 0x2, 0x2, 0x2, 0xf, 0x37, 
       0x3e, 0x4c, 0x62, 0x6a, 0x6c, 0x75, 0x79, 0x8e, 0x9e, 0xab, 0xb9, 
       0xbb, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AlgoParser::Initializer AlgoParser::_init;
