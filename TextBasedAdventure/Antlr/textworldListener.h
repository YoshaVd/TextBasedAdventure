
// Generated from textworld.g4 by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"
#include "textworldParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by textworldParser.
 */
class  textworldListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterWorld(textworldParser::WorldContext *ctx) = 0;
  virtual void exitWorld(textworldParser::WorldContext *ctx) = 0;

  virtual void enterWorldnode(textworldParser::WorldnodeContext *ctx) = 0;
  virtual void exitWorldnode(textworldParser::WorldnodeContext *ctx) = 0;

  virtual void enterObject(textworldParser::ObjectContext *ctx) = 0;
  virtual void exitObject(textworldParser::ObjectContext *ctx) = 0;

  virtual void enterSubobject(textworldParser::SubobjectContext *ctx) = 0;
  virtual void exitSubobject(textworldParser::SubobjectContext *ctx) = 0;

  virtual void enterConnection(textworldParser::ConnectionContext *ctx) = 0;
  virtual void exitConnection(textworldParser::ConnectionContext *ctx) = 0;

  virtual void enterAssignment(textworldParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(textworldParser::AssignmentContext *ctx) = 0;

  virtual void enterValue(textworldParser::ValueContext *ctx) = 0;
  virtual void exitValue(textworldParser::ValueContext *ctx) = 0;


};

