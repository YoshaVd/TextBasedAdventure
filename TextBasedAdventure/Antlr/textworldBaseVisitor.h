
// Generated from textworld.g4 by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"
#include "textworldVisitor.h"


/**
 * This class provides an empty implementation of textworldVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  textworldBaseVisitor : public textworldVisitor {
public:

  virtual antlrcpp::Any visitWorld(textworldParser::WorldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWorldnode(textworldParser::WorldnodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObject(textworldParser::ObjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubobject(textworldParser::SubobjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConnection(textworldParser::ConnectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(textworldParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue(textworldParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }


};

