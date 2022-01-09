// Generated from /Users/katushaborisova/Desktop/CSE201/Project/Algorithm-visualizer/AST/grammar/AlgoLexer.g4 by ANTLR 4.8
/* lexer header section */
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class AlgoLexer extends Lexer {
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
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"WS", "INTEGER", "Digit", "FLOAT", "VAR", "MAIN", "PLUS", "MINUS", "TIMES", 
			"DIV", "MOD", "EQ", "LT", "MT", "LEQ", "MEQ", "TRUE", "FALSE", "LP", 
			"RP", "LCB", "RCB", "LSB", "RSB", "SEMICOLON", "XOR", "XAND", "EQQ", 
			"NOTEQQ", "WHILE", "IF", "ELSE", "CONT", "BREAK", "PLUSPLUS", "MINUSMINUS", 
			"QUOTE", "RETURN", "DOT", "COMMA", "LL", "STDC", "STDE", "INCLUDE", "INT", 
			"CHAR", "STR", "DOUBLE", "BOOLEAN", "STRING", "SYMB", "ID", "LETTER"
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

	/* public lexer declarations section */
	bool canTestFoo() { return true;}
	bool isItFoo() { return true; }
	bool isItBar() { return true; }

	void myFooLexerAction() { /* do something*/ };
	void myBarLexerAction() { /* do something*/ };


	public AlgoLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "AlgoLexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\66\u0147\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t"+
		"+\4,\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64"+
		"\t\64\4\65\t\65\4\66\t\66\3\2\6\2o\n\2\r\2\16\2p\3\2\3\2\3\3\6\3v\n\3"+
		"\r\3\16\3w\3\4\3\4\3\5\6\5}\n\5\r\5\16\5~\3\5\3\5\6\5\u0083\n\5\r\5\16"+
		"\5\u0084\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3"+
		"\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3\17\3\20\3\20\3\20\3\21\3"+
		"\21\3\21\3\22\3\22\3\22\3\22\3\22\3\23\3\23\3\23\3\23\3\23\3\23\3\24\3"+
		"\24\3\25\3\25\3\26\3\26\3\27\3\27\3\30\3\30\3\31\3\31\3\32\3\32\3\33\3"+
		"\33\3\33\3\34\3\34\3\34\3\35\3\35\3\35\3\36\3\36\3\36\3\37\3\37\3\37\3"+
		"\37\3\37\3\37\3 \3 \3 \3!\3!\3!\3!\3!\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\""+
		"\3\"\3#\3#\3#\3#\3#\3#\3$\3$\3$\3%\3%\3%\3&\3&\3\'\3\'\3\'\3\'\3\'\3\'"+
		"\3\'\3(\3(\3)\3)\3*\3*\3*\3+\3+\3+\3+\3+\3+\3+\3+\3+\3+\3,\3,\3,\3,\3"+
		",\3,\3,\3,\3,\3,\3-\3-\3-\3-\3-\3-\3-\3-\3-\3.\3.\3.\3.\3/\3/\3/\3/\3"+
		"/\3\60\3\60\3\60\3\60\3\61\3\61\3\61\3\61\3\61\3\61\3\61\3\62\3\62\3\62"+
		"\3\62\3\62\3\63\3\63\3\63\7\63\u0138\n\63\f\63\16\63\u013b\13\63\3\64"+
		"\3\64\3\65\3\65\3\65\6\65\u0142\n\65\r\65\16\65\u0143\3\66\3\66\2\2\67"+
		"\3\4\5\5\7\6\t\7\13\b\r\t\17\n\21\13\23\f\25\r\27\16\31\17\33\20\35\21"+
		"\37\22!\23#\24%\25\'\26)\27+\30-\31/\32\61\33\63\34\65\35\67\369\37; "+
		"=!?\"A#C$E%G&I\'K(M)O*Q+S,U-W.Y/[\60]\61_\62a\63c\64e\65g\2i\66k\2\3\2"+
		"\5\5\2\13\f\17\17\"\"\3\2\62;\5\2C\\c|\u0082\1\2\u014c\2\3\3\2\2\2\2\5"+
		"\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2"+
		"\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33"+
		"\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2"+
		"\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2"+
		"\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2"+
		"\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K"+
		"\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2\2Q\3\2\2\2\2S\3\2\2\2\2U\3\2\2\2\2W\3\2"+
		"\2\2\2Y\3\2\2\2\2[\3\2\2\2\2]\3\2\2\2\2_\3\2\2\2\2a\3\2\2\2\2c\3\2\2\2"+
		"\2e\3\2\2\2\2i\3\2\2\2\3n\3\2\2\2\5u\3\2\2\2\7y\3\2\2\2\t|\3\2\2\2\13"+
		"\u0086\3\2\2\2\r\u008b\3\2\2\2\17\u0090\3\2\2\2\21\u0092\3\2\2\2\23\u0094"+
		"\3\2\2\2\25\u0096\3\2\2\2\27\u0098\3\2\2\2\31\u009a\3\2\2\2\33\u009c\3"+
		"\2\2\2\35\u009e\3\2\2\2\37\u00a0\3\2\2\2!\u00a3\3\2\2\2#\u00a6\3\2\2\2"+
		"%\u00ab\3\2\2\2\'\u00b1\3\2\2\2)\u00b3\3\2\2\2+\u00b5\3\2\2\2-\u00b7\3"+
		"\2\2\2/\u00b9\3\2\2\2\61\u00bb\3\2\2\2\63\u00bd\3\2\2\2\65\u00bf\3\2\2"+
		"\2\67\u00c2\3\2\2\29\u00c5\3\2\2\2;\u00c8\3\2\2\2=\u00cb\3\2\2\2?\u00d1"+
		"\3\2\2\2A\u00d4\3\2\2\2C\u00d9\3\2\2\2E\u00e2\3\2\2\2G\u00e8\3\2\2\2I"+
		"\u00eb\3\2\2\2K\u00ee\3\2\2\2M\u00f0\3\2\2\2O\u00f7\3\2\2\2Q\u00f9\3\2"+
		"\2\2S\u00fb\3\2\2\2U\u00fe\3\2\2\2W\u0108\3\2\2\2Y\u0112\3\2\2\2[\u011b"+
		"\3\2\2\2]\u011f\3\2\2\2_\u0124\3\2\2\2a\u0128\3\2\2\2c\u012f\3\2\2\2e"+
		"\u0134\3\2\2\2g\u013c\3\2\2\2i\u013e\3\2\2\2k\u0145\3\2\2\2mo\t\2\2\2"+
		"nm\3\2\2\2op\3\2\2\2pn\3\2\2\2pq\3\2\2\2qr\3\2\2\2rs\b\2\2\2s\4\3\2\2"+
		"\2tv\5\7\4\2ut\3\2\2\2vw\3\2\2\2wu\3\2\2\2wx\3\2\2\2x\6\3\2\2\2yz\t\3"+
		"\2\2z\b\3\2\2\2{}\5\7\4\2|{\3\2\2\2}~\3\2\2\2~|\3\2\2\2~\177\3\2\2\2\177"+
		"\u0080\3\2\2\2\u0080\u0082\7\60\2\2\u0081\u0083\5\7\4\2\u0082\u0081\3"+
		"\2\2\2\u0083\u0084\3\2\2\2\u0084\u0082\3\2\2\2\u0084\u0085\3\2\2\2\u0085"+
		"\n\3\2\2\2\u0086\u0087\7x\2\2\u0087\u0088\7c\2\2\u0088\u0089\7t\2\2\u0089"+
		"\u008a\7\"\2\2\u008a\f\3\2\2\2\u008b\u008c\7o\2\2\u008c\u008d\7c\2\2\u008d"+
		"\u008e\7k\2\2\u008e\u008f\7p\2\2\u008f\16\3\2\2\2\u0090\u0091\7-\2\2\u0091"+
		"\20\3\2\2\2\u0092\u0093\7/\2\2\u0093\22\3\2\2\2\u0094\u0095\7,\2\2\u0095"+
		"\24\3\2\2\2\u0096\u0097\7\61\2\2\u0097\26\3\2\2\2\u0098\u0099\7\'\2\2"+
		"\u0099\30\3\2\2\2\u009a\u009b\7?\2\2\u009b\32\3\2\2\2\u009c\u009d\7>\2"+
		"\2\u009d\34\3\2\2\2\u009e\u009f\7@\2\2\u009f\36\3\2\2\2\u00a0\u00a1\7"+
		">\2\2\u00a1\u00a2\7?\2\2\u00a2 \3\2\2\2\u00a3\u00a4\7@\2\2\u00a4\u00a5"+
		"\7?\2\2\u00a5\"\3\2\2\2\u00a6\u00a7\7v\2\2\u00a7\u00a8\7t\2\2\u00a8\u00a9"+
		"\7w\2\2\u00a9\u00aa\7g\2\2\u00aa$\3\2\2\2\u00ab\u00ac\7h\2\2\u00ac\u00ad"+
		"\7c\2\2\u00ad\u00ae\7n\2\2\u00ae\u00af\7u\2\2\u00af\u00b0\7g\2\2\u00b0"+
		"&\3\2\2\2\u00b1\u00b2\7*\2\2\u00b2(\3\2\2\2\u00b3\u00b4\7+\2\2\u00b4*"+
		"\3\2\2\2\u00b5\u00b6\7}\2\2\u00b6,\3\2\2\2\u00b7\u00b8\7\177\2\2\u00b8"+
		".\3\2\2\2\u00b9\u00ba\7]\2\2\u00ba\60\3\2\2\2\u00bb\u00bc\7_\2\2\u00bc"+
		"\62\3\2\2\2\u00bd\u00be\7=\2\2\u00be\64\3\2\2\2\u00bf\u00c0\7~\2\2\u00c0"+
		"\u00c1\7~\2\2\u00c1\66\3\2\2\2\u00c2\u00c3\7(\2\2\u00c3\u00c4\7(\2\2\u00c4"+
		"8\3\2\2\2\u00c5\u00c6\7?\2\2\u00c6\u00c7\7?\2\2\u00c7:\3\2\2\2\u00c8\u00c9"+
		"\7#\2\2\u00c9\u00ca\7?\2\2\u00ca<\3\2\2\2\u00cb\u00cc\7y\2\2\u00cc\u00cd"+
		"\7j\2\2\u00cd\u00ce\7k\2\2\u00ce\u00cf\7n\2\2\u00cf\u00d0\7g\2\2\u00d0"+
		">\3\2\2\2\u00d1\u00d2\7k\2\2\u00d2\u00d3\7h\2\2\u00d3@\3\2\2\2\u00d4\u00d5"+
		"\7g\2\2\u00d5\u00d6\7n\2\2\u00d6\u00d7\7u\2\2\u00d7\u00d8\7g\2\2\u00d8"+
		"B\3\2\2\2\u00d9\u00da\7e\2\2\u00da\u00db\7q\2\2\u00db\u00dc\7p\2\2\u00dc"+
		"\u00dd\7v\2\2\u00dd\u00de\7k\2\2\u00de\u00df\7p\2\2\u00df\u00e0\7w\2\2"+
		"\u00e0\u00e1\7g\2\2\u00e1D\3\2\2\2\u00e2\u00e3\7d\2\2\u00e3\u00e4\7t\2"+
		"\2\u00e4\u00e5\7g\2\2\u00e5\u00e6\7c\2\2\u00e6\u00e7\7m\2\2\u00e7F\3\2"+
		"\2\2\u00e8\u00e9\7-\2\2\u00e9\u00ea\7-\2\2\u00eaH\3\2\2\2\u00eb\u00ec"+
		"\7/\2\2\u00ec\u00ed\7/\2\2\u00edJ\3\2\2\2\u00ee\u00ef\7$\2\2\u00efL\3"+
		"\2\2\2\u00f0\u00f1\7t\2\2\u00f1\u00f2\7g\2\2\u00f2\u00f3\7v\2\2\u00f3"+
		"\u00f4\7w\2\2\u00f4\u00f5\7t\2\2\u00f5\u00f6\7p\2\2\u00f6N\3\2\2\2\u00f7"+
		"\u00f8\7\60\2\2\u00f8P\3\2\2\2\u00f9\u00fa\7.\2\2\u00faR\3\2\2\2\u00fb"+
		"\u00fc\7>\2\2\u00fc\u00fd\7>\2\2\u00fdT\3\2\2\2\u00fe\u00ff\7u\2\2\u00ff"+
		"\u0100\7v\2\2\u0100\u0101\7f\2\2\u0101\u0102\7<\2\2\u0102\u0103\7<\2\2"+
		"\u0103\u0104\7e\2\2\u0104\u0105\7q\2\2\u0105\u0106\7w\2\2\u0106\u0107"+
		"\7v\2\2\u0107V\3\2\2\2\u0108\u0109\7u\2\2\u0109\u010a\7v\2\2\u010a\u010b"+
		"\7f\2\2\u010b\u010c\7<\2\2\u010c\u010d\7<\2\2\u010d\u010e\7g\2\2\u010e"+
		"\u010f\7p\2\2\u010f\u0110\7f\2\2\u0110\u0111\7n\2\2\u0111X\3\2\2\2\u0112"+
		"\u0113\7%\2\2\u0113\u0114\7k\2\2\u0114\u0115\7p\2\2\u0115\u0116\7e\2\2"+
		"\u0116\u0117\7n\2\2\u0117\u0118\7w\2\2\u0118\u0119\7f\2\2\u0119\u011a"+
		"\7g\2\2\u011aZ\3\2\2\2\u011b\u011c\7k\2\2\u011c\u011d\7p\2\2\u011d\u011e"+
		"\7v\2\2\u011e\\\3\2\2\2\u011f\u0120\7e\2\2\u0120\u0121\7j\2\2\u0121\u0122"+
		"\7c\2\2\u0122\u0123\7t\2\2\u0123^\3\2\2\2\u0124\u0125\7u\2\2\u0125\u0126"+
		"\7v\2\2\u0126\u0127\7t\2\2\u0127`\3\2\2\2\u0128\u0129\7f\2\2\u0129\u012a"+
		"\7q\2\2\u012a\u012b\7w\2\2\u012b\u012c\7d\2\2\u012c\u012d\7n\2\2\u012d"+
		"\u012e\7g\2\2\u012eb\3\2\2\2\u012f\u0130\7d\2\2\u0130\u0131\7q\2\2\u0131"+
		"\u0132\7q\2\2\u0132\u0133\7n\2\2\u0133d\3\2\2\2\u0134\u0139\5g\64\2\u0135"+
		"\u0138\5g\64\2\u0136\u0138\4\62;\2\u0137\u0135\3\2\2\2\u0137\u0136\3\2"+
		"\2\2\u0138\u013b\3\2\2\2\u0139\u0137\3\2\2\2\u0139\u013a\3\2\2\2\u013a"+
		"f\3\2\2\2\u013b\u0139\3\2\2\2\u013c\u013d\t\4\2\2\u013dh\3\2\2\2\u013e"+
		"\u0141\5k\66\2\u013f\u0142\5k\66\2\u0140\u0142\4\62;\2\u0141\u013f\3\2"+
		"\2\2\u0141\u0140\3\2\2\2\u0142\u0143\3\2\2\2\u0143\u0141\3\2\2\2\u0143"+
		"\u0144\3\2\2\2\u0144j\3\2\2\2\u0145\u0146\t\4\2\2\u0146l\3\2\2\2\13\2"+
		"pw~\u0084\u0137\u0139\u0141\u0143\3\2\3\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}