
// Generated from textworld.g4 by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"
#include "textworldListener.h"


/**
 * This class provides an empty implementation of textworldListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  textworldBaseListener : public textworldListener {
public:

  virtual void enterWorld(textworldParser::WorldContext * /*ctx*/) override { }
  virtual void exitWorld(textworldParser::WorldContext * /*ctx*/) override { }

  virtual void enterWorldnode(textworldParser::WorldnodeContext * /*ctx*/) override { }
  virtual void exitWorldnode(textworldParser::WorldnodeContext * /*ctx*/) override { }

  virtual void enterObject(textworldParser::ObjectContext * /*ctx*/) override { }
  virtual void exitObject(textworldParser::ObjectContext * /*ctx*/) override { }

  virtual void enterSubobject(textworldParser::SubobjectContext * /*ctx*/) override { }
  virtual void exitSubobject(textworldParser::SubobjectContext * /*ctx*/) override { }

  virtual void enterConnection(textworldParser::ConnectionContext * /*ctx*/) override { }
  virtual void exitConnection(textworldParser::ConnectionContext * /*ctx*/) override { }

  virtual void enterAssignment(textworldParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(textworldParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterValue(textworldParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(textworldParser::ValueContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

