#pragma once
// antlr includes
#include "antlr4-runtime.h"
#include "antlr/textworldLexer.h"
#include "antlr/textworldParser.h"
#include "antlr/textworldBaseListener.h"
#include "antlr/textworldBaseVisitor.h"
#include "MyVisitor.h"
#include <Windows.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

// custom includes
#include "Helpers.h"
#include "WorldNode.h"
#include "InteractiveObject.h"
#include "InputParser.h"
#include "PlayerStats.h"
#include "Campfire.h"

#pragma execution_character_set("utf-8")

using namespace antlr4;

void InitializeWorld(std::vector<WorldNode*>& worldNodes, int argc, const char* argv[]);

int main(int argc, const char* argv[]) 
{
	// Get world data from file with ANTLR
	std::vector<WorldNode*> pWorldNodes = {};
	InitializeWorld(pWorldNodes, argc, argv);

	// Get commands data from file
	InputParser::GetInstance().LoadCommandsFromFile("commands.txt");
	InputParser::GetInstance().LoadDirectionsFromFile("directions.txt");

	// Set current node and start parsing the input
	InputParser::GetInstance().SetCurrentNode(pWorldNodes[0]);
	cout << pWorldNodes[0]->GetDescription();
	while (PlayerStats::GetInstance().m_IsAlive) {
		InputParser::GetInstance().Update();
	}
	cout << "You died..." << endl;

	getchar();
	return 0;
}

void InitializeWorld(std::vector<WorldNode*>& worldNodes, int argc, const char* argv[])
{
	std::ifstream stream;
	stream.open(argv[1]);
	if (stream.is_open()) {
		ANTLRInputStream input(stream);
		textworldLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
		textworldParser parser(&tokens);

		tree::ParseTree * tree = parser.world();

		MyVisitor * visitor = new MyVisitor();
		visitor->visit(tree);
		worldNodes = visitor->GetWorldNodes();
	}
}