// Generated from /home/walterjtv/Escritorio/Assignatures/Q6/CL/sessio2/Calc.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class CalcParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, IF=2, THEN=3, ELSE=4, ENDIF=5, WHILE=6, EQ=7, NEQ=8, LE=9, GE=10, 
		LESS=11, GRT=12, LPAR=13, RPAR=14, MUL=15, ADD=16, SUB=17, MOD=18, DIV=19, 
		ABS=20, MIN=21, MAX=22, COMMA=23, FACTORIAL=24, MYSTERY=25, ID=26, INT=27, 
		NEWLINE=28, WS=29;
	public static final int
		RULE_prog = 0, RULE_stat = 1, RULE_expr = 2;
	private static String[] makeRuleNames() {
		return new String[] {
			"prog", "stat", "expr"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'='", "'if'", "'then'", "'else'", "'endif'", "'while'", "'=='", 
			"'!='", "'<='", "'>='", "'<'", "'>'", "'('", "')'", "'*'", "'+'", "'-'", 
			"'%'", "'/'", "'abs'", "'min'", "'max'", "','", "'!'", "'mistery'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, "IF", "THEN", "ELSE", "ENDIF", "WHILE", "EQ", "NEQ", "LE", 
			"GE", "LESS", "GRT", "LPAR", "RPAR", "MUL", "ADD", "SUB", "MOD", "DIV", 
			"ABS", "MIN", "MAX", "COMMA", "FACTORIAL", "MYSTERY", "ID", "INT", "NEWLINE", 
			"WS"
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
	public String getGrammarFileName() { return "Calc.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public CalcParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(CalcParser.EOF, 0); }
		public List<StatContext> stat() {
			return getRuleContexts(StatContext.class);
		}
		public StatContext stat(int i) {
			return getRuleContext(StatContext.class,i);
		}
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_prog);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(7); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(6);
				stat();
				}
				}
				setState(9); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IF) | (1L << WHILE) | (1L << LPAR) | (1L << ADD) | (1L << SUB) | (1L << ABS) | (1L << MIN) | (1L << MAX) | (1L << MYSTERY) | (1L << ID) | (1L << INT) | (1L << NEWLINE))) != 0) );
			setState(11);
			match(EOF);
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

	public static class StatContext extends ParserRuleContext {
		public StatContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stat; }
	 
		public StatContext() { }
		public void copyFrom(StatContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class BlankContext extends StatContext {
		public TerminalNode NEWLINE() { return getToken(CalcParser.NEWLINE, 0); }
		public BlankContext(StatContext ctx) { copyFrom(ctx); }
	}
	public static class WhileContext extends StatContext {
		public TerminalNode WHILE() { return getToken(CalcParser.WHILE, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(CalcParser.NEWLINE, 0); }
		public StatContext stat() {
			return getRuleContext(StatContext.class,0);
		}
		public WhileContext(StatContext ctx) { copyFrom(ctx); }
	}
	public static class IfContext extends StatContext {
		public TerminalNode IF() { return getToken(CalcParser.IF, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(CalcParser.NEWLINE, 0); }
		public TerminalNode THEN() { return getToken(CalcParser.THEN, 0); }
		public StatContext stat() {
			return getRuleContext(StatContext.class,0);
		}
		public TerminalNode ENDIF() { return getToken(CalcParser.ENDIF, 0); }
		public IfContext(StatContext ctx) { copyFrom(ctx); }
	}
	public static class PrintExprContext extends StatContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(CalcParser.NEWLINE, 0); }
		public PrintExprContext(StatContext ctx) { copyFrom(ctx); }
	}
	public static class AssignContext extends StatContext {
		public TerminalNode ID() { return getToken(CalcParser.ID, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(CalcParser.NEWLINE, 0); }
		public AssignContext(StatContext ctx) { copyFrom(ctx); }
	}
	public static class IfelseContext extends StatContext {
		public TerminalNode IF() { return getToken(CalcParser.IF, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode NEWLINE() { return getToken(CalcParser.NEWLINE, 0); }
		public TerminalNode THEN() { return getToken(CalcParser.THEN, 0); }
		public List<StatContext> stat() {
			return getRuleContexts(StatContext.class);
		}
		public StatContext stat(int i) {
			return getRuleContext(StatContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(CalcParser.ELSE, 0); }
		public TerminalNode ENDIF() { return getToken(CalcParser.ENDIF, 0); }
		public IfelseContext(StatContext ctx) { copyFrom(ctx); }
	}

	public final StatContext stat() throws RecognitionException {
		StatContext _localctx = new StatContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_stat);
		try {
			setState(43);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				_localctx = new PrintExprContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(13);
				expr(0);
				setState(14);
				match(NEWLINE);
				}
				break;
			case 2:
				_localctx = new AssignContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(16);
				match(ID);
				setState(17);
				match(T__0);
				setState(18);
				expr(0);
				setState(19);
				match(NEWLINE);
				}
				break;
			case 3:
				_localctx = new IfContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(21);
				match(IF);
				setState(22);
				expr(0);
				setState(23);
				match(NEWLINE);
				setState(24);
				match(THEN);
				setState(25);
				stat();
				setState(26);
				match(ENDIF);
				}
				break;
			case 4:
				_localctx = new IfelseContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(28);
				match(IF);
				setState(29);
				expr(0);
				setState(30);
				match(NEWLINE);
				setState(31);
				match(THEN);
				setState(32);
				stat();
				setState(33);
				match(ELSE);
				setState(34);
				stat();
				setState(35);
				match(ENDIF);
				}
				break;
			case 5:
				_localctx = new WhileContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(37);
				match(WHILE);
				setState(38);
				expr(0);
				setState(39);
				match(NEWLINE);
				setState(40);
				stat();
				}
				break;
			case 6:
				_localctx = new BlankContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(42);
				match(NEWLINE);
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

	public static class ExprContext extends ParserRuleContext {
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	 
		public ExprContext() { }
		public void copyFrom(ExprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ParentesisContext extends ExprContext {
		public TerminalNode LPAR() { return getToken(CalcParser.LPAR, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RPAR() { return getToken(CalcParser.RPAR, 0); }
		public ParentesisContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class MisteryContext extends ExprContext {
		public TerminalNode MYSTERY() { return getToken(CalcParser.MYSTERY, 0); }
		public TerminalNode LPAR() { return getToken(CalcParser.LPAR, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode RPAR() { return getToken(CalcParser.RPAR, 0); }
		public List<TerminalNode> COMMA() { return getTokens(CalcParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(CalcParser.COMMA, i);
		}
		public MisteryContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class AbsContext extends ExprContext {
		public TerminalNode ABS() { return getToken(CalcParser.ABS, 0); }
		public TerminalNode LPAR() { return getToken(CalcParser.LPAR, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RPAR() { return getToken(CalcParser.RPAR, 0); }
		public AbsContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class MultContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode MUL() { return getToken(CalcParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(CalcParser.DIV, 0); }
		public TerminalNode MOD() { return getToken(CalcParser.MOD, 0); }
		public MultContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class NumContext extends ExprContext {
		public TerminalNode INT() { return getToken(CalcParser.INT, 0); }
		public NumContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class FactorialContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode FACTORIAL() { return getToken(CalcParser.FACTORIAL, 0); }
		public FactorialContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class SignContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode ADD() { return getToken(CalcParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(CalcParser.SUB, 0); }
		public SignContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class MinmaxContext extends ExprContext {
		public TerminalNode MIN() { return getToken(CalcParser.MIN, 0); }
		public TerminalNode LPAR() { return getToken(CalcParser.LPAR, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode COMMA() { return getToken(CalcParser.COMMA, 0); }
		public TerminalNode RPAR() { return getToken(CalcParser.RPAR, 0); }
		public TerminalNode MAX() { return getToken(CalcParser.MAX, 0); }
		public MinmaxContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ArithmeticContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode ADD() { return getToken(CalcParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(CalcParser.SUB, 0); }
		public ArithmeticContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class IdContext extends ExprContext {
		public TerminalNode ID() { return getToken(CalcParser.ID, 0); }
		public IdContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ComparisionContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode LESS() { return getToken(CalcParser.LESS, 0); }
		public TerminalNode LE() { return getToken(CalcParser.LE, 0); }
		public TerminalNode GE() { return getToken(CalcParser.GE, 0); }
		public TerminalNode GRT() { return getToken(CalcParser.GRT, 0); }
		public ComparisionContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class EqualityContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode EQ() { return getToken(CalcParser.EQ, 0); }
		public TerminalNode NEQ() { return getToken(CalcParser.NEQ, 0); }
		public EqualityContext(ExprContext ctx) { copyFrom(ctx); }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 4;
		enterRecursionRule(_localctx, 4, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(85);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LPAR:
				{
				_localctx = new ParentesisContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(46);
				match(LPAR);
				setState(47);
				expr(0);
				setState(48);
				match(RPAR);
				}
				break;
			case ADD:
			case SUB:
				{
				_localctx = new SignContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(50);
				_la = _input.LA(1);
				if ( !(_la==ADD || _la==SUB) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(51);
				expr(11);
				}
				break;
			case ABS:
				{
				_localctx = new AbsContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(52);
				match(ABS);
				setState(53);
				match(LPAR);
				setState(54);
				expr(0);
				setState(55);
				match(RPAR);
				}
				break;
			case MIN:
				{
				_localctx = new MinmaxContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(57);
				match(MIN);
				setState(58);
				match(LPAR);
				setState(59);
				expr(0);
				setState(60);
				match(COMMA);
				setState(61);
				expr(0);
				setState(62);
				match(RPAR);
				}
				break;
			case MAX:
				{
				_localctx = new MinmaxContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(64);
				match(MAX);
				setState(65);
				match(LPAR);
				setState(66);
				expr(0);
				setState(67);
				match(COMMA);
				setState(68);
				expr(0);
				setState(69);
				match(RPAR);
				}
				break;
			case MYSTERY:
				{
				_localctx = new MisteryContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(71);
				match(MYSTERY);
				setState(72);
				match(LPAR);
				setState(73);
				expr(0);
				setState(78);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(74);
					match(COMMA);
					setState(75);
					expr(0);
					}
					}
					setState(80);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(81);
				match(RPAR);
				}
				break;
			case INT:
				{
				_localctx = new NumContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(83);
				match(INT);
				}
				break;
			case ID:
				{
				_localctx = new IdContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(84);
				match(ID);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(103);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(101);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
					case 1:
						{
						_localctx = new MultContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(87);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(88);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << MUL) | (1L << MOD) | (1L << DIV))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(89);
						expr(11);
						}
						break;
					case 2:
						{
						_localctx = new ArithmeticContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(90);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(91);
						_la = _input.LA(1);
						if ( !(_la==ADD || _la==SUB) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(92);
						expr(10);
						}
						break;
					case 3:
						{
						_localctx = new ComparisionContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(93);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(94);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LE) | (1L << GE) | (1L << LESS) | (1L << GRT))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(95);
						expr(5);
						}
						break;
					case 4:
						{
						_localctx = new EqualityContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(96);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(97);
						_la = _input.LA(1);
						if ( !(_la==EQ || _la==NEQ) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(98);
						expr(4);
						}
						break;
					case 5:
						{
						_localctx = new FactorialContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(99);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(100);
						match(FACTORIAL);
						}
						break;
					}
					} 
				}
				setState(105);
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 2:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 10);
		case 1:
			return precpred(_ctx, 9);
		case 2:
			return precpred(_ctx, 4);
		case 3:
			return precpred(_ctx, 3);
		case 4:
			return precpred(_ctx, 13);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\37m\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\3\2\6\2\n\n\2\r\2\16\2\13\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\3\3\3\5\3.\n\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4"+
		"\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\7\4O\n\4\f\4\16\4R\13\4\3\4\3\4\3\4\3\4\5\4X\n\4\3"+
		"\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\7\4h\n\4\f\4\16"+
		"\4k\13\4\3\4\2\3\6\5\2\4\6\2\6\3\2\22\23\4\2\21\21\24\25\3\2\13\16\3\2"+
		"\t\n\2|\2\t\3\2\2\2\4-\3\2\2\2\6W\3\2\2\2\b\n\5\4\3\2\t\b\3\2\2\2\n\13"+
		"\3\2\2\2\13\t\3\2\2\2\13\f\3\2\2\2\f\r\3\2\2\2\r\16\7\2\2\3\16\3\3\2\2"+
		"\2\17\20\5\6\4\2\20\21\7\36\2\2\21.\3\2\2\2\22\23\7\34\2\2\23\24\7\3\2"+
		"\2\24\25\5\6\4\2\25\26\7\36\2\2\26.\3\2\2\2\27\30\7\4\2\2\30\31\5\6\4"+
		"\2\31\32\7\36\2\2\32\33\7\5\2\2\33\34\5\4\3\2\34\35\7\7\2\2\35.\3\2\2"+
		"\2\36\37\7\4\2\2\37 \5\6\4\2 !\7\36\2\2!\"\7\5\2\2\"#\5\4\3\2#$\7\6\2"+
		"\2$%\5\4\3\2%&\7\7\2\2&.\3\2\2\2\'(\7\b\2\2()\5\6\4\2)*\7\36\2\2*+\5\4"+
		"\3\2+.\3\2\2\2,.\7\36\2\2-\17\3\2\2\2-\22\3\2\2\2-\27\3\2\2\2-\36\3\2"+
		"\2\2-\'\3\2\2\2-,\3\2\2\2.\5\3\2\2\2/\60\b\4\1\2\60\61\7\17\2\2\61\62"+
		"\5\6\4\2\62\63\7\20\2\2\63X\3\2\2\2\64\65\t\2\2\2\65X\5\6\4\r\66\67\7"+
		"\26\2\2\678\7\17\2\289\5\6\4\29:\7\20\2\2:X\3\2\2\2;<\7\27\2\2<=\7\17"+
		"\2\2=>\5\6\4\2>?\7\31\2\2?@\5\6\4\2@A\7\20\2\2AX\3\2\2\2BC\7\30\2\2CD"+
		"\7\17\2\2DE\5\6\4\2EF\7\31\2\2FG\5\6\4\2GH\7\20\2\2HX\3\2\2\2IJ\7\33\2"+
		"\2JK\7\17\2\2KP\5\6\4\2LM\7\31\2\2MO\5\6\4\2NL\3\2\2\2OR\3\2\2\2PN\3\2"+
		"\2\2PQ\3\2\2\2QS\3\2\2\2RP\3\2\2\2ST\7\20\2\2TX\3\2\2\2UX\7\35\2\2VX\7"+
		"\34\2\2W/\3\2\2\2W\64\3\2\2\2W\66\3\2\2\2W;\3\2\2\2WB\3\2\2\2WI\3\2\2"+
		"\2WU\3\2\2\2WV\3\2\2\2Xi\3\2\2\2YZ\f\f\2\2Z[\t\3\2\2[h\5\6\4\r\\]\f\13"+
		"\2\2]^\t\2\2\2^h\5\6\4\f_`\f\6\2\2`a\t\4\2\2ah\5\6\4\7bc\f\5\2\2cd\t\5"+
		"\2\2dh\5\6\4\6ef\f\17\2\2fh\7\32\2\2gY\3\2\2\2g\\\3\2\2\2g_\3\2\2\2gb"+
		"\3\2\2\2ge\3\2\2\2hk\3\2\2\2ig\3\2\2\2ij\3\2\2\2j\7\3\2\2\2ki\3\2\2\2"+
		"\b\13-PWgi";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}