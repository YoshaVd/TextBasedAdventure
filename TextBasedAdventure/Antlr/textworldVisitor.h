
// Generated from textworld.g4 by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"
#include "textworldParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by textworldParser.
 */
class  textworldVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by textworldParser.
   */
    virtual antlrcpp::Any visitWorld(textworldParser::WorldContext *context) = 0;

    virtual antlrcpp::Any visitWorldnode(textworldParser::WorldnodeContext *context) = 0;

    virtual antlrcpp::Any visitObject(textworldParser::ObjectContext *context) = 0;

    virtual antlrcpp::Any visitSubobject(textworldParser::SubobjectContext *context) = 0;

    virtual antlrcpp::Any visitConnection(textworldParser::ConnectionContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(textworldParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitValue(textworldParser::ValueContext *context) = 0;


};

