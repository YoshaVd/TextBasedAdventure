
// Generated from textworld.g4 by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"




class  textworldParser : public antlr4::Parser {
public:
  enum {
    WORLD = 1, WORLDNODE = 2, OBJECT = 3, SUBOBJECT = 4, CONNECTION = 5, 
    LCB = 6, RCB = 7, EQ = 8, SC = 9, ID = 10, STRING = 11, INT = 12, WS = 13
  };

  enum {
    RuleWorld = 0, RuleWorldnode = 1, RuleObject = 2, RuleSubobject = 3, 
    RuleConnection = 4, RuleAssignment = 5, RuleValue = 6
  };

  textworldParser(antlr4::TokenStream *input);
  ~textworldParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class WorldContext;
  class WorldnodeContext;
  class ObjectContext;
  class SubobjectContext;
  class ConnectionContext;
  class AssignmentContext;
  class ValueContext; 

  class  WorldContext : public antlr4::ParserRuleContext {
  public:
    WorldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WORLD();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LCB();
    antlr4::tree::TerminalNode *RCB();
    std::vector<WorldnodeContext *> worldnode();
    WorldnodeContext* worldnode(size_t i);
    std::vector<ConnectionContext *> connection();
    ConnectionContext* connection(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WorldContext* world();

  class  WorldnodeContext : public antlr4::ParserRuleContext {
  public:
    WorldnodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WORLDNODE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LCB();
    antlr4::tree::TerminalNode *RCB();
    std::vector<AssignmentContext *> assignment();
    AssignmentContext* assignment(size_t i);
    std::vector<ObjectContext *> object();
    ObjectContext* object(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WorldnodeContext* worldnode();

  class  ObjectContext : public antlr4::ParserRuleContext {
  public:
    ObjectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBJECT();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LCB();
    antlr4::tree::TerminalNode *RCB();
    std::vector<AssignmentContext *> assignment();
    AssignmentContext* assignment(size_t i);
    std::vector<SubobjectContext *> subobject();
    SubobjectContext* subobject(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ObjectContext* object();

  class  SubobjectContext : public antlr4::ParserRuleContext {
  public:
    SubobjectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUBOBJECT();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LCB();
    antlr4::tree::TerminalNode *RCB();
    std::vector<AssignmentContext *> assignment();
    AssignmentContext* assignment(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubobjectContext* subobject();

  class  ConnectionContext : public antlr4::ParserRuleContext {
  public:
    ConnectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONNECTION();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LCB();
    antlr4::tree::TerminalNode *RCB();
    std::vector<AssignmentContext *> assignment();
    AssignmentContext* assignment(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConnectionContext* connection();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *EQ();
    ValueContext *value();
    antlr4::tree::TerminalNode *SC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  ValueContext : public antlr4::ParserRuleContext {
  public:
    ValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *INT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValueContext* value();


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


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

