
// Generated from textworld.g4 by ANTLR 4.6


#include "textworldListener.h"
#include "textworldVisitor.h"

#include "textworldParser.h"


using namespace antlrcpp;
using namespace antlr4;

textworldParser::textworldParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

textworldParser::~textworldParser() {
  delete _interpreter;
}

std::string textworldParser::getGrammarFileName() const {
  return "textworld.g4";
}

const std::vector<std::string>& textworldParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& textworldParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- WorldContext ------------------------------------------------------------------

textworldParser::WorldContext::WorldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* textworldParser::WorldContext::WORLD() {
  return getToken(textworldParser::WORLD, 0);
}

tree::TerminalNode* textworldParser::WorldContext::ID() {
  return getToken(textworldParser::ID, 0);
}

tree::TerminalNode* textworldParser::WorldContext::LCB() {
  return getToken(textworldParser::LCB, 0);
}

tree::TerminalNode* textworldParser::WorldContext::RCB() {
  return getToken(textworldParser::RCB, 0);
}

std::vector<textworldParser::WorldnodeContext *> textworldParser::WorldContext::worldnode() {
  return getRuleContexts<textworldParser::WorldnodeContext>();
}

textworldParser::WorldnodeContext* textworldParser::WorldContext::worldnode(size_t i) {
  return getRuleContext<textworldParser::WorldnodeContext>(i);
}

std::vector<textworldParser::ConnectionContext *> textworldParser::WorldContext::connection() {
  return getRuleContexts<textworldParser::ConnectionContext>();
}

textworldParser::ConnectionContext* textworldParser::WorldContext::connection(size_t i) {
  return getRuleContext<textworldParser::ConnectionContext>(i);
}


size_t textworldParser::WorldContext::getRuleIndex() const {
  return textworldParser::RuleWorld;
}

void textworldParser::WorldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWorld(this);
}

void textworldParser::WorldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWorld(this);
}


antlrcpp::Any textworldParser::WorldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<textworldVisitor*>(visitor))
    return parserVisitor->visitWorld(this);
  else
    return visitor->visitChildren(this);
}

textworldParser::WorldContext* textworldParser::world() {
  WorldContext *_localctx = _tracker.createInstance<WorldContext>(_ctx, getState());
  enterRule(_localctx, 0, textworldParser::RuleWorld);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    match(textworldParser::WORLD);
    setState(15);
    match(textworldParser::ID);
    setState(16);
    match(textworldParser::LCB);
    setState(20);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == textworldParser::WORLDNODE) {
      setState(17);
      worldnode();
      setState(22);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(26);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == textworldParser::CONNECTION) {
      setState(23);
      connection();
      setState(28);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(29);
    match(textworldParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WorldnodeContext ------------------------------------------------------------------

textworldParser::WorldnodeContext::WorldnodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* textworldParser::WorldnodeContext::WORLDNODE() {
  return getToken(textworldParser::WORLDNODE, 0);
}

tree::TerminalNode* textworldParser::WorldnodeContext::ID() {
  return getToken(textworldParser::ID, 0);
}

tree::TerminalNode* textworldParser::WorldnodeContext::LCB() {
  return getToken(textworldParser::LCB, 0);
}

tree::TerminalNode* textworldParser::WorldnodeContext::RCB() {
  return getToken(textworldParser::RCB, 0);
}

std::vector<textworldParser::AssignmentContext *> textworldParser::WorldnodeContext::assignment() {
  return getRuleContexts<textworldParser::AssignmentContext>();
}

textworldParser::AssignmentContext* textworldParser::WorldnodeContext::assignment(size_t i) {
  return getRuleContext<textworldParser::AssignmentContext>(i);
}

std::vector<textworldParser::ObjectContext *> textworldParser::WorldnodeContext::object() {
  return getRuleContexts<textworldParser::ObjectContext>();
}

textworldParser::ObjectContext* textworldParser::WorldnodeContext::object(size_t i) {
  return getRuleContext<textworldParser::ObjectContext>(i);
}


size_t textworldParser::WorldnodeContext::getRuleIndex() const {
  return textworldParser::RuleWorldnode;
}

void textworldParser::WorldnodeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWorldnode(this);
}

void textworldParser::WorldnodeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWorldnode(this);
}


antlrcpp::Any textworldParser::WorldnodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<textworldVisitor*>(visitor))
    return parserVisitor->visitWorldnode(this);
  else
    return visitor->visitChildren(this);
}

textworldParser::WorldnodeContext* textworldParser::worldnode() {
  WorldnodeContext *_localctx = _tracker.createInstance<WorldnodeContext>(_ctx, getState());
  enterRule(_localctx, 2, textworldParser::RuleWorldnode);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    match(textworldParser::WORLDNODE);
    setState(32);
    match(textworldParser::ID);
    setState(33);
    match(textworldParser::LCB);
    setState(37);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == textworldParser::ID) {
      setState(34);
      assignment();
      setState(39);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(43);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == textworldParser::OBJECT) {
      setState(40);
      object();
      setState(45);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(46);
    match(textworldParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectContext ------------------------------------------------------------------

textworldParser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* textworldParser::ObjectContext::OBJECT() {
  return getToken(textworldParser::OBJECT, 0);
}

tree::TerminalNode* textworldParser::ObjectContext::ID() {
  return getToken(textworldParser::ID, 0);
}

tree::TerminalNode* textworldParser::ObjectContext::LCB() {
  return getToken(textworldParser::LCB, 0);
}

tree::TerminalNode* textworldParser::ObjectContext::RCB() {
  return getToken(textworldParser::RCB, 0);
}

std::vector<textworldParser::AssignmentContext *> textworldParser::ObjectContext::assignment() {
  return getRuleContexts<textworldParser::AssignmentContext>();
}

textworldParser::AssignmentContext* textworldParser::ObjectContext::assignment(size_t i) {
  return getRuleContext<textworldParser::AssignmentContext>(i);
}

std::vector<textworldParser::SubobjectContext *> textworldParser::ObjectContext::subobject() {
  return getRuleContexts<textworldParser::SubobjectContext>();
}

textworldParser::SubobjectContext* textworldParser::ObjectContext::subobject(size_t i) {
  return getRuleContext<textworldParser::SubobjectContext>(i);
}


size_t textworldParser::ObjectContext::getRuleIndex() const {
  return textworldParser::RuleObject;
}

void textworldParser::ObjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObject(this);
}

void textworldParser::ObjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObject(this);
}


antlrcpp::Any textworldParser::ObjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<textworldVisitor*>(visitor))
    return parserVisitor->visitObject(this);
  else
    return visitor->visitChildren(this);
}

textworldParser::ObjectContext* textworldParser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 4, textworldParser::RuleObject);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(textworldParser::OBJECT);
    setState(49);
    match(textworldParser::ID);
    setState(50);
    match(textworldParser::LCB);
    setState(54);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == textworldParser::ID) {
      setState(51);
      assignment();
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == textworldParser::SUBOBJECT) {
      setState(57);
      subobject();
      setState(62);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(63);
    match(textworldParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubobjectContext ------------------------------------------------------------------

textworldParser::SubobjectContext::SubobjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* textworldParser::SubobjectContext::SUBOBJECT() {
  return getToken(textworldParser::SUBOBJECT, 0);
}

tree::TerminalNode* textworldParser::SubobjectContext::ID() {
  return getToken(textworldParser::ID, 0);
}

tree::TerminalNode* textworldParser::SubobjectContext::LCB() {
  return getToken(textworldParser::LCB, 0);
}

tree::TerminalNode* textworldParser::SubobjectContext::RCB() {
  return getToken(textworldParser::RCB, 0);
}

std::vector<textworldParser::AssignmentContext *> textworldParser::SubobjectContext::assignment() {
  return getRuleContexts<textworldParser::AssignmentContext>();
}

textworldParser::AssignmentContext* textworldParser::SubobjectContext::assignment(size_t i) {
  return getRuleContext<textworldParser::AssignmentContext>(i);
}


size_t textworldParser::SubobjectContext::getRuleIndex() const {
  return textworldParser::RuleSubobject;
}

void textworldParser::SubobjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubobject(this);
}

void textworldParser::SubobjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubobject(this);
}


antlrcpp::Any textworldParser::SubobjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<textworldVisitor*>(visitor))
    return parserVisitor->visitSubobject(this);
  else
    return visitor->visitChildren(this);
}

textworldParser::SubobjectContext* textworldParser::subobject() {
  SubobjectContext *_localctx = _tracker.createInstance<SubobjectContext>(_ctx, getState());
  enterRule(_localctx, 6, textworldParser::RuleSubobject);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    match(textworldParser::SUBOBJECT);
    setState(66);
    match(textworldParser::ID);
    setState(67);
    match(textworldParser::LCB);
    setState(71);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == textworldParser::ID) {
      setState(68);
      assignment();
      setState(73);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(74);
    match(textworldParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConnectionContext ------------------------------------------------------------------

textworldParser::ConnectionContext::ConnectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* textworldParser::ConnectionContext::CONNECTION() {
  return getToken(textworldParser::CONNECTION, 0);
}

tree::TerminalNode* textworldParser::ConnectionContext::ID() {
  return getToken(textworldParser::ID, 0);
}

tree::TerminalNode* textworldParser::ConnectionContext::LCB() {
  return getToken(textworldParser::LCB, 0);
}

tree::TerminalNode* textworldParser::ConnectionContext::RCB() {
  return getToken(textworldParser::RCB, 0);
}

std::vector<textworldParser::AssignmentContext *> textworldParser::ConnectionContext::assignment() {
  return getRuleContexts<textworldParser::AssignmentContext>();
}

textworldParser::AssignmentContext* textworldParser::ConnectionContext::assignment(size_t i) {
  return getRuleContext<textworldParser::AssignmentContext>(i);
}


size_t textworldParser::ConnectionContext::getRuleIndex() const {
  return textworldParser::RuleConnection;
}

void textworldParser::ConnectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConnection(this);
}

void textworldParser::ConnectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConnection(this);
}


antlrcpp::Any textworldParser::ConnectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<textworldVisitor*>(visitor))
    return parserVisitor->visitConnection(this);
  else
    return visitor->visitChildren(this);
}

textworldParser::ConnectionContext* textworldParser::connection() {
  ConnectionContext *_localctx = _tracker.createInstance<ConnectionContext>(_ctx, getState());
  enterRule(_localctx, 8, textworldParser::RuleConnection);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    match(textworldParser::CONNECTION);
    setState(77);
    match(textworldParser::ID);
    setState(78);
    match(textworldParser::LCB);
    setState(82);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == textworldParser::ID) {
      setState(79);
      assignment();
      setState(84);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(85);
    match(textworldParser::RCB);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

textworldParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* textworldParser::AssignmentContext::ID() {
  return getToken(textworldParser::ID, 0);
}

tree::TerminalNode* textworldParser::AssignmentContext::EQ() {
  return getToken(textworldParser::EQ, 0);
}

textworldParser::ValueContext* textworldParser::AssignmentContext::value() {
  return getRuleContext<textworldParser::ValueContext>(0);
}

tree::TerminalNode* textworldParser::AssignmentContext::SC() {
  return getToken(textworldParser::SC, 0);
}


size_t textworldParser::AssignmentContext::getRuleIndex() const {
  return textworldParser::RuleAssignment;
}

void textworldParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void textworldParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


antlrcpp::Any textworldParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<textworldVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

textworldParser::AssignmentContext* textworldParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 10, textworldParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(textworldParser::ID);
    setState(88);
    match(textworldParser::EQ);
    setState(89);
    value();
    setState(90);
    match(textworldParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

textworldParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* textworldParser::ValueContext::STRING() {
  return getToken(textworldParser::STRING, 0);
}

tree::TerminalNode* textworldParser::ValueContext::INT() {
  return getToken(textworldParser::INT, 0);
}


size_t textworldParser::ValueContext::getRuleIndex() const {
  return textworldParser::RuleValue;
}

void textworldParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void textworldParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<textworldListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}


antlrcpp::Any textworldParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<textworldVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

textworldParser::ValueContext* textworldParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 12, textworldParser::RuleValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    _la = _input->LA(1);
    if (!(_la == textworldParser::STRING

    || _la == textworldParser::INT)) {
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

// Static vars and initialization.
std::vector<dfa::DFA> textworldParser::_decisionToDFA;
atn::PredictionContextCache textworldParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN textworldParser::_atn;
std::vector<uint16_t> textworldParser::_serializedATN;

std::vector<std::string> textworldParser::_ruleNames = {
  "world", "worldnode", "object", "subobject", "connection", "assignment", 
  "value"
};

std::vector<std::string> textworldParser::_literalNames = {
  "", "'world'", "'worldnode'", "'object'", "'subobject'", "'connection'", 
  "'{'", "'}'", "'='", "';'"
};

std::vector<std::string> textworldParser::_symbolicNames = {
  "", "WORLD", "WORLDNODE", "OBJECT", "SUBOBJECT", "CONNECTION", "LCB", 
  "RCB", "EQ", "SC", "ID", "STRING", "INT", "WS"
};

dfa::Vocabulary textworldParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> textworldParser::_tokenNames;

textworldParser::Initializer::Initializer() {
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

  _serializedATN = {
    0x3, 0x430, 0xd6d1, 0x8206, 0xad2d, 0x4417, 0xaef1, 0x8d80, 0xaadd, 
    0x3, 0xf, 0x61, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x15, 
    0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x18, 0xb, 0x2, 0x3, 0x2, 0x7, 0x2, 0x1b, 
    0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x1e, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x26, 0xa, 0x3, 0xc, 0x3, 
    0xe, 0x3, 0x29, 0xb, 0x3, 0x3, 0x3, 0x7, 0x3, 0x2c, 0xa, 0x3, 0xc, 0x3, 
    0xe, 0x3, 0x2f, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x7, 0x4, 0x37, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x3a, 0xb, 
    0x4, 0x3, 0x4, 0x7, 0x4, 0x3d, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x40, 0xb, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 
    0x5, 0x48, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x4b, 0xb, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x53, 0xa, 0x6, 
    0xc, 0x6, 0xe, 0x6, 0x56, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x2, 
    0x2, 0x9, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x2, 0x3, 0x3, 0x2, 0xd, 
    0xe, 0x61, 0x2, 0x10, 0x3, 0x2, 0x2, 0x2, 0x4, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x32, 0x3, 0x2, 0x2, 0x2, 0x8, 0x43, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0xc, 0x59, 0x3, 0x2, 0x2, 0x2, 0xe, 0x5e, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0x7, 0x3, 0x2, 0x2, 0x11, 0x12, 0x7, 
    0xc, 0x2, 0x2, 0x12, 0x16, 0x7, 0x8, 0x2, 0x2, 0x13, 0x15, 0x5, 0x4, 
    0x3, 0x2, 0x14, 0x13, 0x3, 0x2, 0x2, 0x2, 0x15, 0x18, 0x3, 0x2, 0x2, 
    0x2, 0x16, 0x14, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x17, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x18, 0x16, 0x3, 0x2, 0x2, 0x2, 0x19, 
    0x1b, 0x5, 0xa, 0x6, 0x2, 0x1a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1e, 
    0x3, 0x2, 0x2, 0x2, 0x1c, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0x1d, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1c, 0x3, 0x2, 
    0x2, 0x2, 0x1f, 0x20, 0x7, 0x9, 0x2, 0x2, 0x20, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x21, 0x22, 0x7, 0x4, 0x2, 0x2, 0x22, 0x23, 0x7, 0xc, 0x2, 0x2, 
    0x23, 0x27, 0x7, 0x8, 0x2, 0x2, 0x24, 0x26, 0x5, 0xc, 0x7, 0x2, 0x25, 
    0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x29, 0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x5, 0x6, 
    0x4, 0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 
    0x2e, 0x30, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x30, 
    0x31, 0x7, 0x9, 0x2, 0x2, 0x31, 0x5, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 
    0x7, 0x5, 0x2, 0x2, 0x33, 0x34, 0x7, 0xc, 0x2, 0x2, 0x34, 0x38, 0x7, 
    0x8, 0x2, 0x2, 0x35, 0x37, 0x5, 0xc, 0x7, 0x2, 0x36, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x37, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0x39, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3e, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3d, 0x5, 0x8, 0x5, 0x2, 0x3c, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x40, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 
    0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0x9, 
    0x2, 0x2, 0x42, 0x7, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x7, 0x6, 0x2, 
    0x2, 0x44, 0x45, 0x7, 0xc, 0x2, 0x2, 0x45, 0x49, 0x7, 0x8, 0x2, 0x2, 
    0x46, 0x48, 0x5, 0xc, 0x7, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x9, 0x2, 0x2, 0x4d, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x4f, 0x7, 0x7, 0x2, 0x2, 0x4f, 0x50, 0x7, 0xc, 0x2, 
    0x2, 0x50, 0x54, 0x7, 0x8, 0x2, 0x2, 0x51, 0x53, 0x5, 0xc, 0x7, 0x2, 
    0x52, 0x51, 0x3, 0x2, 0x2, 0x2, 0x53, 0x56, 0x3, 0x2, 0x2, 0x2, 0x54, 
    0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x57, 
    0x3, 0x2, 0x2, 0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x7, 
    0x9, 0x2, 0x2, 0x58, 0xb, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0xc, 
    0x2, 0x2, 0x5a, 0x5b, 0x7, 0xa, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0xe, 0x8, 
    0x2, 0x5c, 0x5d, 0x7, 0xb, 0x2, 0x2, 0x5d, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x5f, 0x9, 0x2, 0x2, 0x2, 0x5f, 0xf, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x16, 0x1c, 0x27, 0x2d, 0x38, 0x3e, 0x49, 0x54, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

textworldParser::Initializer textworldParser::_init;
