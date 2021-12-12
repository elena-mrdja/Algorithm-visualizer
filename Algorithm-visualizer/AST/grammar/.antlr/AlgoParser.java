// Generated from /Users/katushaborisova/Desktop/test_antlr4 copy/grammar/AlgoParser.g4 by ANTLR 4.8
/* parser/listener/visitor header section */
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class AlgoParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		DUMMY=1, WS=2, INTEGER=3, Digit=4, FLOAT=5, VAR=6, MAIN=7, PLUS=8, MINUS=9, 
		TIMES=10, DIV=11, MOD=12, EQ=13, LT=14, MT=15, LEQ=16, MEQ=17, TRUE=18, 
		FALSE=19, LP=20, RP=21, LCB=22, RCB=23, LSB=24, RSB=25, SEMICOLON=26, 
		XOR=27, XAND=28, EQQ=29, NOTEQQ=30, WHILE=31, IF=32, ELSE=33, CONT=34, 
		BREAK=35, PLUSPLUS=36, MINUSMINUS=37, QUOTE=38, RETURN=39, DOT=40, COMMA=41, 
		LL=42, STDC=43, STDE=44, INCLUDE=45, INT=46, CHAR=47, STR=48, DOUBLE=49, 
		BOOLEAN=50, STRING=51, ID=52;
	public static final int
		RULE_file = 0, RULE_mainStmt = 1, RULE_assign = 2, RULE_exp = 3, RULE_varDec = 4, 
		RULE_whileStmt = 5, RULE_returnStmt = 6, RULE_negation = 7, RULE_block = 8, 
		RULE_stmts = 9, RULE_ifelse = 10, RULE_ifrest = 11, RULE_boolType = 12, 
		RULE_doubleType = 13, RULE_integerType = 14, RULE_arrayType = 15, RULE_string = 16, 
		RULE_type = 17, RULE_binOp = 18, RULE_unop = 19, RULE_identifier = 20, 
		RULE_variable = 21, RULE_print = 22, RULE_jump = 23, RULE_library = 24;
	private static String[] makeRuleNames() {
		return new String[] {
			"file", "mainStmt", "assign", "exp", "varDec", "whileStmt", "returnStmt", 
			"negation", "block", "stmts", "ifelse", "ifrest", "boolType", "doubleType", 
			"integerType", "arrayType", "string", "type", "binOp", "unop", "identifier", 
			"variable", "print", "jump", "library"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, null, "'var '", "'main'", "'+'", "'-'", 
			"'*'", "'/'", "'%'", "'='", "'<'", "'>'", "'<='", "'>='", "'true'", "'false'", 
			"'('", "')'", "'{'", "'}'", "'['", "']'", "';'", "'||'", "'&&'", "'=='", 
			"'!='", "'while'", "'if'", "'else'", "'continue'", "'break'", "'++'", 
			"'--'", "'\"'", "'return'", "'.'", "','", "'<<'", "'std::cout'", "'std::endl'", 
			"'#include'", "'int'", "'char'", "'str'", "'double'", "'bool'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "DUMMY", "WS", "INTEGER", "Digit", "FLOAT", "VAR", "MAIN", "PLUS", 
			"MINUS", "TIMES", "DIV", "MOD", "EQ", "LT", "MT", "LEQ", "MEQ", "TRUE", 
			"FALSE", "LP", "RP", "LCB", "RCB", "LSB", "RSB", "SEMICOLON", "XOR", 
			"XAND", "EQQ", "NOTEQQ", "WHILE", "IF", "ELSE", "CONT", "BREAK", "PLUSPLUS", 
			"MINUSMINUS", "QUOTE", "RETURN", "DOT", "COMMA", "LL", "STDC", "STDE", 
			"INCLUDE", "INT", "CHAR", "STR", "DOUBLE", "BOOLEAN", "STRING", "ID"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "AlgoParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }


	/* public parser declarations/members section */
	bool myAction() { return true; }
	bool doesItBlend() { return true; }
	void cleanUp() {}
	void doInit() {}
	void doAfter() {}

	public AlgoParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class FileContext extends ParserRuleContext {
		public MainStmtContext mainStmt() {
			return getRuleContext(MainStmtContext.class,0);
		}
		public List<LibraryContext> library() {
			return getRuleContexts(LibraryContext.class);
		}
		public LibraryContext library(int i) {
			return getRuleContext(LibraryContext.class,i);
		}
		public List<StmtsContext> stmts() {
			return getRuleContexts(StmtsContext.class);
		}
		public StmtsContext stmts(int i) {
			return getRuleContext(StmtsContext.class,i);
		}
		public FileContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_file; }
	}

	public final FileContext file() throws RecognitionException {
		FileContext _localctx = new FileContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_file);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(53);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==INCLUDE) {
				{
				{
				setState(50);
				library();
				}
				}
				setState(55);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(56);
			mainStmt();
			setState(60);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INTEGER) | (1L << FLOAT) | (1L << MINUS) | (1L << TRUE) | (1L << FALSE) | (1L << LP) | (1L << LCB) | (1L << WHILE) | (1L << IF) | (1L << CONT) | (1L << BREAK) | (1L << PLUSPLUS) | (1L << MINUSMINUS) | (1L << QUOTE) | (1L << RETURN) | (1L << STDC) | (1L << INCLUDE) | (1L << INT) | (1L << CHAR) | (1L << STR) | (1L << DOUBLE) | (1L << BOOLEAN) | (1L << STRING) | (1L << ID))) != 0)) {
				{
				{
				setState(57);
				stmts();
				}
				}
				setState(62);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class MainStmtContext extends ParserRuleContext {
		public BlockContext body;
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode MAIN() { return getToken(AlgoParser.MAIN, 0); }
		public TerminalNode LP() { return getToken(AlgoParser.LP, 0); }
		public TerminalNode RP() { return getToken(AlgoParser.RP, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public MainStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_mainStmt; }
	}

	public final MainStmtContext mainStmt() throws RecognitionException {
		MainStmtContext _localctx = new MainStmtContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_mainStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(63);
			type();
			setState(64);
			match(MAIN);
			setState(65);
			match(LP);
			setState(66);
			match(RP);
			setState(67);
			((MainStmtContext)_localctx).body = block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignContext extends ParserRuleContext {
		public VariableContext varName;
		public ExpContext index;
		public ExpContext val;
		public TerminalNode EQ() { return getToken(AlgoParser.EQ, 0); }
		public TerminalNode SEMICOLON() { return getToken(AlgoParser.SEMICOLON, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode LSB() { return getToken(AlgoParser.LSB, 0); }
		public TerminalNode RSB() { return getToken(AlgoParser.RSB, 0); }
		public AssignContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assign; }
	}

	public final AssignContext assign() throws RecognitionException {
		AssignContext _localctx = new AssignContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_assign);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(69);
			((AssignContext)_localctx).varName = variable();
			setState(74);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LSB) {
				{
				setState(70);
				match(LSB);
				setState(71);
				((AssignContext)_localctx).index = exp(0);
				setState(72);
				match(RSB);
				}
			}

			setState(76);
			match(EQ);
			setState(77);
			((AssignContext)_localctx).val = exp(0);
			setState(78);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpContext extends ParserRuleContext {
		public IntegerTypeContext integerType() {
			return getRuleContext(IntegerTypeContext.class,0);
		}
		public DoubleTypeContext doubleType() {
			return getRuleContext(DoubleTypeContext.class,0);
		}
		public BoolTypeContext boolType() {
			return getRuleContext(BoolTypeContext.class,0);
		}
		public StringContext string() {
			return getRuleContext(StringContext.class,0);
		}
		public TerminalNode LP() { return getToken(AlgoParser.LP, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public TerminalNode RP() { return getToken(AlgoParser.RP, 0); }
		public UnopContext unop() {
			return getRuleContext(UnopContext.class,0);
		}
		public NegationContext negation() {
			return getRuleContext(NegationContext.class,0);
		}
		public IdentifierContext identifier() {
			return getRuleContext(IdentifierContext.class,0);
		}
		public ArrayTypeContext arrayType() {
			return getRuleContext(ArrayTypeContext.class,0);
		}
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public BinOpContext binOp() {
			return getRuleContext(BinOpContext.class,0);
		}
		public ExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exp; }
	}

	public final ExpContext exp() throws RecognitionException {
		return exp(0);
	}

	private ExpContext exp(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpContext _localctx = new ExpContext(_ctx, _parentState);
		ExpContext _prevctx = _localctx;
		int _startState = 6;
		enterRecursionRule(_localctx, 6, RULE_exp, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(96);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case INTEGER:
				{
				setState(81);
				integerType();
				}
				break;
			case FLOAT:
				{
				setState(82);
				doubleType();
				}
				break;
			case TRUE:
			case FALSE:
				{
				setState(83);
				boolType();
				}
				break;
			case QUOTE:
				{
				setState(84);
				string();
				}
				break;
			case LP:
				{
				setState(85);
				match(LP);
				setState(86);
				exp(0);
				setState(87);
				match(RP);
				}
				break;
			case PLUSPLUS:
			case MINUSMINUS:
				{
				setState(89);
				unop();
				setState(90);
				exp(6);
				}
				break;
			case MINUS:
				{
				setState(92);
				negation();
				}
				break;
			case ID:
				{
				setState(93);
				identifier();
				}
				break;
			case LCB:
				{
				setState(94);
				arrayType();
				}
				break;
			case STRING:
				{
				setState(95);
				variable();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(106);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(104);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
					case 1:
						{
						_localctx = new ExpContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_exp);
						setState(98);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(99);
						binOp();
						setState(100);
						exp(8);
						}
						break;
					case 2:
						{
						_localctx = new ExpContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_exp);
						setState(102);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(103);
						unop();
						}
						break;
					}
					} 
				}
				setState(108);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class VarDecContext extends ParserRuleContext {
		public VariableContext varName;
		public ExpContext arrSize;
		public ExpContext val;
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(AlgoParser.SEMICOLON, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode LSB() { return getToken(AlgoParser.LSB, 0); }
		public TerminalNode RSB() { return getToken(AlgoParser.RSB, 0); }
		public TerminalNode EQ() { return getToken(AlgoParser.EQ, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public VarDecContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varDec; }
	}

	public final VarDecContext varDec() throws RecognitionException {
		VarDecContext _localctx = new VarDecContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_varDec);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(109);
			type();
			setState(110);
			((VarDecContext)_localctx).varName = variable();
			setState(115);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==LSB) {
				{
				setState(111);
				match(LSB);
				setState(112);
				((VarDecContext)_localctx).arrSize = exp(0);
				setState(113);
				match(RSB);
				}
			}

			setState(119);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==EQ) {
				{
				setState(117);
				match(EQ);
				setState(118);
				((VarDecContext)_localctx).val = exp(0);
				}
			}

			setState(121);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhileStmtContext extends ParserRuleContext {
		public ExpContext cond;
		public BlockContext body;
		public TerminalNode WHILE() { return getToken(AlgoParser.WHILE, 0); }
		public TerminalNode LP() { return getToken(AlgoParser.LP, 0); }
		public TerminalNode RP() { return getToken(AlgoParser.RP, 0); }
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public WhileStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileStmt; }
	}

	public final WhileStmtContext whileStmt() throws RecognitionException {
		WhileStmtContext _localctx = new WhileStmtContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_whileStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(123);
			match(WHILE);
			setState(124);
			match(LP);
			setState(125);
			((WhileStmtContext)_localctx).cond = exp(0);
			setState(126);
			match(RP);
			setState(127);
			((WhileStmtContext)_localctx).body = block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ReturnStmtContext extends ParserRuleContext {
		public ExpContext val;
		public TerminalNode RETURN() { return getToken(AlgoParser.RETURN, 0); }
		public TerminalNode SEMICOLON() { return getToken(AlgoParser.SEMICOLON, 0); }
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public ReturnStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_returnStmt; }
	}

	public final ReturnStmtContext returnStmt() throws RecognitionException {
		ReturnStmtContext _localctx = new ReturnStmtContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_returnStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(129);
			match(RETURN);
			setState(130);
			((ReturnStmtContext)_localctx).val = exp(0);
			setState(131);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NegationContext extends ParserRuleContext {
		public TerminalNode MINUS() { return getToken(AlgoParser.MINUS, 0); }
		public IntegerTypeContext integerType() {
			return getRuleContext(IntegerTypeContext.class,0);
		}
		public DoubleTypeContext doubleType() {
			return getRuleContext(DoubleTypeContext.class,0);
		}
		public NegationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_negation; }
	}

	public final NegationContext negation() throws RecognitionException {
		NegationContext _localctx = new NegationContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_negation);
		try {
			setState(137);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(133);
				match(MINUS);
				setState(134);
				integerType();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(135);
				match(MINUS);
				setState(136);
				doubleType();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockContext extends ParserRuleContext {
		public TerminalNode LCB() { return getToken(AlgoParser.LCB, 0); }
		public TerminalNode RCB() { return getToken(AlgoParser.RCB, 0); }
		public List<StmtsContext> stmts() {
			return getRuleContexts(StmtsContext.class);
		}
		public StmtsContext stmts(int i) {
			return getRuleContext(StmtsContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(139);
			match(LCB);
			setState(143);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INTEGER) | (1L << FLOAT) | (1L << MINUS) | (1L << TRUE) | (1L << FALSE) | (1L << LP) | (1L << LCB) | (1L << WHILE) | (1L << IF) | (1L << CONT) | (1L << BREAK) | (1L << PLUSPLUS) | (1L << MINUSMINUS) | (1L << QUOTE) | (1L << RETURN) | (1L << STDC) | (1L << INCLUDE) | (1L << INT) | (1L << CHAR) | (1L << STR) | (1L << DOUBLE) | (1L << BOOLEAN) | (1L << STRING) | (1L << ID))) != 0)) {
				{
				{
				setState(140);
				stmts();
				}
				}
				setState(145);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(146);
			match(RCB);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StmtsContext extends ParserRuleContext {
		public WhileStmtContext whileStmt() {
			return getRuleContext(WhileStmtContext.class,0);
		}
		public IfelseContext ifelse() {
			return getRuleContext(IfelseContext.class,0);
		}
		public ReturnStmtContext returnStmt() {
			return getRuleContext(ReturnStmtContext.class,0);
		}
		public PrintContext print() {
			return getRuleContext(PrintContext.class,0);
		}
		public LibraryContext library() {
			return getRuleContext(LibraryContext.class,0);
		}
		public VarDecContext varDec() {
			return getRuleContext(VarDecContext.class,0);
		}
		public AssignContext assign() {
			return getRuleContext(AssignContext.class,0);
		}
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(AlgoParser.SEMICOLON, 0); }
		public JumpContext jump() {
			return getRuleContext(JumpContext.class,0);
		}
		public StmtsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmts; }
	}

	public final StmtsContext stmts() throws RecognitionException {
		StmtsContext _localctx = new StmtsContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_stmts);
		try {
			setState(159);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(148);
				whileStmt();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(149);
				ifelse();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(150);
				returnStmt();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(151);
				print();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(152);
				library();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(153);
				varDec();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(154);
				assign();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(155);
				exp(0);
				setState(156);
				match(SEMICOLON);
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(158);
				jump();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IfelseContext extends ParserRuleContext {
		public ExpContext cond;
		public BlockContext thn;
		public TerminalNode IF() { return getToken(AlgoParser.IF, 0); }
		public TerminalNode LP() { return getToken(AlgoParser.LP, 0); }
		public TerminalNode RP() { return getToken(AlgoParser.RP, 0); }
		public IfrestContext ifrest() {
			return getRuleContext(IfrestContext.class,0);
		}
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public IfelseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifelse; }
	}

	public final IfelseContext ifelse() throws RecognitionException {
		IfelseContext _localctx = new IfelseContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_ifelse);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(161);
			match(IF);
			setState(162);
			match(LP);
			setState(163);
			((IfelseContext)_localctx).cond = exp(0);
			setState(164);
			match(RP);
			setState(165);
			((IfelseContext)_localctx).thn = block();
			setState(166);
			ifrest();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IfrestContext extends ParserRuleContext {
		public BlockContext thn;
		public TerminalNode ELSE() { return getToken(AlgoParser.ELSE, 0); }
		public IfelseContext ifelse() {
			return getRuleContext(IfelseContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public IfrestContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifrest; }
	}

	public final IfrestContext ifrest() throws RecognitionException {
		IfrestContext _localctx = new IfrestContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_ifrest);
		try {
			setState(172);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(168);
				match(ELSE);
				setState(169);
				ifelse();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(170);
				match(ELSE);
				setState(171);
				((IfrestContext)_localctx).thn = block();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BoolTypeContext extends ParserRuleContext {
		public TerminalNode TRUE() { return getToken(AlgoParser.TRUE, 0); }
		public TerminalNode FALSE() { return getToken(AlgoParser.FALSE, 0); }
		public BoolTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_boolType; }
	}

	public final BoolTypeContext boolType() throws RecognitionException {
		BoolTypeContext _localctx = new BoolTypeContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_boolType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(174);
			_la = _input.LA(1);
			if ( !(_la==TRUE || _la==FALSE) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DoubleTypeContext extends ParserRuleContext {
		public TerminalNode FLOAT() { return getToken(AlgoParser.FLOAT, 0); }
		public DoubleTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_doubleType; }
	}

	public final DoubleTypeContext doubleType() throws RecognitionException {
		DoubleTypeContext _localctx = new DoubleTypeContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_doubleType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(176);
			match(FLOAT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IntegerTypeContext extends ParserRuleContext {
		public TerminalNode INTEGER() { return getToken(AlgoParser.INTEGER, 0); }
		public IntegerTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_integerType; }
	}

	public final IntegerTypeContext integerType() throws RecognitionException {
		IntegerTypeContext _localctx = new IntegerTypeContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_integerType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(178);
			match(INTEGER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArrayTypeContext extends ParserRuleContext {
		public TerminalNode LCB() { return getToken(AlgoParser.LCB, 0); }
		public TerminalNode RCB() { return getToken(AlgoParser.RCB, 0); }
		public List<ExpContext> exp() {
			return getRuleContexts(ExpContext.class);
		}
		public ExpContext exp(int i) {
			return getRuleContext(ExpContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(AlgoParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(AlgoParser.COMMA, i);
		}
		public ArrayTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arrayType; }
	}

	public final ArrayTypeContext arrayType() throws RecognitionException {
		ArrayTypeContext _localctx = new ArrayTypeContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_arrayType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(180);
			match(LCB);
			setState(188);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INTEGER) | (1L << FLOAT) | (1L << MINUS) | (1L << TRUE) | (1L << FALSE) | (1L << LP) | (1L << LCB) | (1L << PLUSPLUS) | (1L << MINUSMINUS) | (1L << QUOTE) | (1L << STRING) | (1L << ID))) != 0)) {
				{
				setState(181);
				exp(0);
				setState(184); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(182);
					match(COMMA);
					setState(183);
					exp(0);
					}
					}
					setState(186); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( _la==COMMA );
				}
			}

			setState(190);
			match(RCB);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StringContext extends ParserRuleContext {
		public List<TerminalNode> QUOTE() { return getTokens(AlgoParser.QUOTE); }
		public TerminalNode QUOTE(int i) {
			return getToken(AlgoParser.QUOTE, i);
		}
		public TerminalNode STRING() { return getToken(AlgoParser.STRING, 0); }
		public StringContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_string; }
	}

	public final StringContext string() throws RecognitionException {
		StringContext _localctx = new StringContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_string);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(192);
			match(QUOTE);
			setState(193);
			match(STRING);
			setState(194);
			match(QUOTE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeContext extends ParserRuleContext {
		public TerminalNode INT() { return getToken(AlgoParser.INT, 0); }
		public TerminalNode STR() { return getToken(AlgoParser.STR, 0); }
		public TerminalNode CHAR() { return getToken(AlgoParser.CHAR, 0); }
		public TerminalNode DOUBLE() { return getToken(AlgoParser.DOUBLE, 0); }
		public TerminalNode BOOLEAN() { return getToken(AlgoParser.BOOLEAN, 0); }
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_type);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(196);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << INT) | (1L << CHAR) | (1L << STR) | (1L << DOUBLE) | (1L << BOOLEAN))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BinOpContext extends ParserRuleContext {
		public TerminalNode PLUS() { return getToken(AlgoParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(AlgoParser.MINUS, 0); }
		public TerminalNode TIMES() { return getToken(AlgoParser.TIMES, 0); }
		public TerminalNode DIV() { return getToken(AlgoParser.DIV, 0); }
		public TerminalNode MOD() { return getToken(AlgoParser.MOD, 0); }
		public TerminalNode XOR() { return getToken(AlgoParser.XOR, 0); }
		public TerminalNode XAND() { return getToken(AlgoParser.XAND, 0); }
		public TerminalNode EQQ() { return getToken(AlgoParser.EQQ, 0); }
		public TerminalNode NOTEQQ() { return getToken(AlgoParser.NOTEQQ, 0); }
		public TerminalNode LT() { return getToken(AlgoParser.LT, 0); }
		public TerminalNode MT() { return getToken(AlgoParser.MT, 0); }
		public TerminalNode LEQ() { return getToken(AlgoParser.LEQ, 0); }
		public TerminalNode MEQ() { return getToken(AlgoParser.MEQ, 0); }
		public BinOpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_binOp; }
	}

	public final BinOpContext binOp() throws RecognitionException {
		BinOpContext _localctx = new BinOpContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_binOp);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(198);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << PLUS) | (1L << MINUS) | (1L << TIMES) | (1L << DIV) | (1L << MOD) | (1L << LT) | (1L << MT) | (1L << LEQ) | (1L << MEQ) | (1L << XOR) | (1L << XAND) | (1L << EQQ) | (1L << NOTEQQ))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnopContext extends ParserRuleContext {
		public TerminalNode PLUSPLUS() { return getToken(AlgoParser.PLUSPLUS, 0); }
		public TerminalNode MINUSMINUS() { return getToken(AlgoParser.MINUSMINUS, 0); }
		public UnopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unop; }
	}

	public final UnopContext unop() throws RecognitionException {
		UnopContext _localctx = new UnopContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_unop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(200);
			_la = _input.LA(1);
			if ( !(_la==PLUSPLUS || _la==MINUSMINUS) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IdentifierContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(AlgoParser.ID, 0); }
		public IdentifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_identifier; }
	}

	public final IdentifierContext identifier() throws RecognitionException {
		IdentifierContext _localctx = new IdentifierContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_identifier);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(202);
			match(ID);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VariableContext extends ParserRuleContext {
		public TerminalNode STRING() { return getToken(AlgoParser.STRING, 0); }
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_variable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(204);
			match(STRING);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PrintContext extends ParserRuleContext {
		public TerminalNode STDC() { return getToken(AlgoParser.STDC, 0); }
		public List<TerminalNode> LL() { return getTokens(AlgoParser.LL); }
		public TerminalNode LL(int i) {
			return getToken(AlgoParser.LL, i);
		}
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public TerminalNode STDE() { return getToken(AlgoParser.STDE, 0); }
		public TerminalNode SEMICOLON() { return getToken(AlgoParser.SEMICOLON, 0); }
		public PrintContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_print; }
	}

	public final PrintContext print() throws RecognitionException {
		PrintContext _localctx = new PrintContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_print);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(206);
			match(STDC);
			setState(207);
			match(LL);
			setState(208);
			exp(0);
			setState(209);
			match(LL);
			setState(210);
			match(STDE);
			setState(211);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class JumpContext extends ParserRuleContext {
		public TerminalNode CONT() { return getToken(AlgoParser.CONT, 0); }
		public TerminalNode BREAK() { return getToken(AlgoParser.BREAK, 0); }
		public JumpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_jump; }
	}

	public final JumpContext jump() throws RecognitionException {
		JumpContext _localctx = new JumpContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_jump);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(213);
			_la = _input.LA(1);
			if ( !(_la==CONT || _la==BREAK) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LibraryContext extends ParserRuleContext {
		public TerminalNode INCLUDE() { return getToken(AlgoParser.INCLUDE, 0); }
		public List<TerminalNode> QUOTE() { return getTokens(AlgoParser.QUOTE); }
		public TerminalNode QUOTE(int i) {
			return getToken(AlgoParser.QUOTE, i);
		}
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public LibraryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_library; }
	}

	public final LibraryContext library() throws RecognitionException {
		LibraryContext _localctx = new LibraryContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_library);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(215);
			match(INCLUDE);
			setState(216);
			match(QUOTE);
			setState(217);
			variable();
			setState(218);
			match(QUOTE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 3:
			return exp_sempred((ExpContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean exp_sempred(ExpContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 7);
		case 1:
			return precpred(_ctx, 5);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\66\u00df\4\2\t\2"+
		"\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\3\2\7\2\66\n\2\f\2\16\29\13\2\3\2\3\2\7\2=\n\2\f\2\16\2@\13"+
		"\2\3\3\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\5\4M\n\4\3\4\3\4\3\4\3"+
		"\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\5\5"+
		"c\n\5\3\5\3\5\3\5\3\5\3\5\3\5\7\5k\n\5\f\5\16\5n\13\5\3\6\3\6\3\6\3\6"+
		"\3\6\3\6\5\6v\n\6\3\6\3\6\5\6z\n\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3\b"+
		"\3\b\3\b\3\b\3\t\3\t\3\t\3\t\5\t\u008c\n\t\3\n\3\n\7\n\u0090\n\n\f\n\16"+
		"\n\u0093\13\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\13"+
		"\3\13\5\13\u00a2\n\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\r\3\r\3\r\3\r\5\r"+
		"\u00af\n\r\3\16\3\16\3\17\3\17\3\20\3\20\3\21\3\21\3\21\3\21\6\21\u00bb"+
		"\n\21\r\21\16\21\u00bc\5\21\u00bf\n\21\3\21\3\21\3\22\3\22\3\22\3\22\3"+
		"\23\3\23\3\24\3\24\3\25\3\25\3\26\3\26\3\27\3\27\3\30\3\30\3\30\3\30\3"+
		"\30\3\30\3\30\3\31\3\31\3\32\3\32\3\32\3\32\3\32\3\32\2\3\b\33\2\4\6\b"+
		"\n\f\16\20\22\24\26\30\32\34\36 \"$&(*,.\60\62\2\7\3\2\24\25\3\2\60\64"+
		"\5\2\n\16\20\23\35 \3\2&\'\3\2$%\2\u00e2\2\67\3\2\2\2\4A\3\2\2\2\6G\3"+
		"\2\2\2\bb\3\2\2\2\no\3\2\2\2\f}\3\2\2\2\16\u0083\3\2\2\2\20\u008b\3\2"+
		"\2\2\22\u008d\3\2\2\2\24\u00a1\3\2\2\2\26\u00a3\3\2\2\2\30\u00ae\3\2\2"+
		"\2\32\u00b0\3\2\2\2\34\u00b2\3\2\2\2\36\u00b4\3\2\2\2 \u00b6\3\2\2\2\""+
		"\u00c2\3\2\2\2$\u00c6\3\2\2\2&\u00c8\3\2\2\2(\u00ca\3\2\2\2*\u00cc\3\2"+
		"\2\2,\u00ce\3\2\2\2.\u00d0\3\2\2\2\60\u00d7\3\2\2\2\62\u00d9\3\2\2\2\64"+
		"\66\5\62\32\2\65\64\3\2\2\2\669\3\2\2\2\67\65\3\2\2\2\678\3\2\2\28:\3"+
		"\2\2\29\67\3\2\2\2:>\5\4\3\2;=\5\24\13\2<;\3\2\2\2=@\3\2\2\2><\3\2\2\2"+
		">?\3\2\2\2?\3\3\2\2\2@>\3\2\2\2AB\5$\23\2BC\7\t\2\2CD\7\26\2\2DE\7\27"+
		"\2\2EF\5\22\n\2F\5\3\2\2\2GL\5,\27\2HI\7\32\2\2IJ\5\b\5\2JK\7\33\2\2K"+
		"M\3\2\2\2LH\3\2\2\2LM\3\2\2\2MN\3\2\2\2NO\7\17\2\2OP\5\b\5\2PQ\7\34\2"+
		"\2Q\7\3\2\2\2RS\b\5\1\2Sc\5\36\20\2Tc\5\34\17\2Uc\5\32\16\2Vc\5\"\22\2"+
		"WX\7\26\2\2XY\5\b\5\2YZ\7\27\2\2Zc\3\2\2\2[\\\5(\25\2\\]\5\b\5\b]c\3\2"+
		"\2\2^c\5\20\t\2_c\5*\26\2`c\5 \21\2ac\5,\27\2bR\3\2\2\2bT\3\2\2\2bU\3"+
		"\2\2\2bV\3\2\2\2bW\3\2\2\2b[\3\2\2\2b^\3\2\2\2b_\3\2\2\2b`\3\2\2\2ba\3"+
		"\2\2\2cl\3\2\2\2de\f\t\2\2ef\5&\24\2fg\5\b\5\ngk\3\2\2\2hi\f\7\2\2ik\5"+
		"(\25\2jd\3\2\2\2jh\3\2\2\2kn\3\2\2\2lj\3\2\2\2lm\3\2\2\2m\t\3\2\2\2nl"+
		"\3\2\2\2op\5$\23\2pu\5,\27\2qr\7\32\2\2rs\5\b\5\2st\7\33\2\2tv\3\2\2\2"+
		"uq\3\2\2\2uv\3\2\2\2vy\3\2\2\2wx\7\17\2\2xz\5\b\5\2yw\3\2\2\2yz\3\2\2"+
		"\2z{\3\2\2\2{|\7\34\2\2|\13\3\2\2\2}~\7!\2\2~\177\7\26\2\2\177\u0080\5"+
		"\b\5\2\u0080\u0081\7\27\2\2\u0081\u0082\5\22\n\2\u0082\r\3\2\2\2\u0083"+
		"\u0084\7)\2\2\u0084\u0085\5\b\5\2\u0085\u0086\7\34\2\2\u0086\17\3\2\2"+
		"\2\u0087\u0088\7\13\2\2\u0088\u008c\5\36\20\2\u0089\u008a\7\13\2\2\u008a"+
		"\u008c\5\34\17\2\u008b\u0087\3\2\2\2\u008b\u0089\3\2\2\2\u008c\21\3\2"+
		"\2\2\u008d\u0091\7\30\2\2\u008e\u0090\5\24\13\2\u008f\u008e\3\2\2\2\u0090"+
		"\u0093\3\2\2\2\u0091\u008f\3\2\2\2\u0091\u0092\3\2\2\2\u0092\u0094\3\2"+
		"\2\2\u0093\u0091\3\2\2\2\u0094\u0095\7\31\2\2\u0095\23\3\2\2\2\u0096\u00a2"+
		"\5\f\7\2\u0097\u00a2\5\26\f\2\u0098\u00a2\5\16\b\2\u0099\u00a2\5.\30\2"+
		"\u009a\u00a2\5\62\32\2\u009b\u00a2\5\n\6\2\u009c\u00a2\5\6\4\2\u009d\u009e"+
		"\5\b\5\2\u009e\u009f\7\34\2\2\u009f\u00a2\3\2\2\2\u00a0\u00a2\5\60\31"+
		"\2\u00a1\u0096\3\2\2\2\u00a1\u0097\3\2\2\2\u00a1\u0098\3\2\2\2\u00a1\u0099"+
		"\3\2\2\2\u00a1\u009a\3\2\2\2\u00a1\u009b\3\2\2\2\u00a1\u009c\3\2\2\2\u00a1"+
		"\u009d\3\2\2\2\u00a1\u00a0\3\2\2\2\u00a2\25\3\2\2\2\u00a3\u00a4\7\"\2"+
		"\2\u00a4\u00a5\7\26\2\2\u00a5\u00a6\5\b\5\2\u00a6\u00a7\7\27\2\2\u00a7"+
		"\u00a8\5\22\n\2\u00a8\u00a9\5\30\r\2\u00a9\27\3\2\2\2\u00aa\u00ab\7#\2"+
		"\2\u00ab\u00af\5\26\f\2\u00ac\u00ad\7#\2\2\u00ad\u00af\5\22\n\2\u00ae"+
		"\u00aa\3\2\2\2\u00ae\u00ac\3\2\2\2\u00af\31\3\2\2\2\u00b0\u00b1\t\2\2"+
		"\2\u00b1\33\3\2\2\2\u00b2\u00b3\7\7\2\2\u00b3\35\3\2\2\2\u00b4\u00b5\7"+
		"\5\2\2\u00b5\37\3\2\2\2\u00b6\u00be\7\30\2\2\u00b7\u00ba\5\b\5\2\u00b8"+
		"\u00b9\7+\2\2\u00b9\u00bb\5\b\5\2\u00ba\u00b8\3\2\2\2\u00bb\u00bc\3\2"+
		"\2\2\u00bc\u00ba\3\2\2\2\u00bc\u00bd\3\2\2\2\u00bd\u00bf\3\2\2\2\u00be"+
		"\u00b7\3\2\2\2\u00be\u00bf\3\2\2\2\u00bf\u00c0\3\2\2\2\u00c0\u00c1\7\31"+
		"\2\2\u00c1!\3\2\2\2\u00c2\u00c3\7(\2\2\u00c3\u00c4\7\65\2\2\u00c4\u00c5"+
		"\7(\2\2\u00c5#\3\2\2\2\u00c6\u00c7\t\3\2\2\u00c7%\3\2\2\2\u00c8\u00c9"+
		"\t\4\2\2\u00c9\'\3\2\2\2\u00ca\u00cb\t\5\2\2\u00cb)\3\2\2\2\u00cc\u00cd"+
		"\7\66\2\2\u00cd+\3\2\2\2\u00ce\u00cf\7\65\2\2\u00cf-\3\2\2\2\u00d0\u00d1"+
		"\7-\2\2\u00d1\u00d2\7,\2\2\u00d2\u00d3\5\b\5\2\u00d3\u00d4\7,\2\2\u00d4"+
		"\u00d5\7.\2\2\u00d5\u00d6\7\34\2\2\u00d6/\3\2\2\2\u00d7\u00d8\t\6\2\2"+
		"\u00d8\61\3\2\2\2\u00d9\u00da\7/\2\2\u00da\u00db\7(\2\2\u00db\u00dc\5"+
		",\27\2\u00dc\u00dd\7(\2\2\u00dd\63\3\2\2\2\20\67>Lbjluy\u008b\u0091\u00a1"+
		"\u00ae\u00bc\u00be";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}