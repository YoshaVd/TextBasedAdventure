#pragma once

#include "antlr/textworldBaseVisitor.h"
#include "antlr/textworldLexer.h"
#include "antlr/textworldParser.h"
#include "tree/TerminalNode.h"

#include <vector>
#include "WorldNode.h"
#include "InteractiveObject.h"
#include "Helpers.h"
#include "Campfire.h"

//#define DEBUG

using namespace std;

class MyVisitor : public textworldBaseVisitor
{
public:
	MyVisitor() {};
	virtual ~MyVisitor() {};

	WorldNode* GetWorldNodeByName(vector<WorldNode*> worldNodes, const string& name) {
		for (auto pNode : worldNodes)
		{
			if (pNode->GetName() == name)
				return pNode;
		}
		return nullptr;
	}

	void AddPropertyToWorldNode(textworldParser::AssignmentContext* ctx) 
	{
		textworldParser::ValueContext* vc = ctx->value();
		string propertyName = ctx->ID()->getSymbol()->getText();
		WorldNode * pNode = m_WorldNodes[m_NodeIndex];

		if (vc->STRING() != nullptr)
		{
			string value = vc->STRING()->getSymbol()->getText();
#ifdef DEBUG
			cout << "Property value: " << value << endl;
#endif // DEBUG
			value = value.substr(1, value.length() - 2); // remove quotation marks

			if (propertyName == "name")
				pNode->SetName(value);
			else if (propertyName == "description")
				pNode->SetDescription(value);
			

		}
		else if (vc->INT() != nullptr) {
			cout << "Property value: " << vc->INT()->getSymbol()->getText() << endl;
		}
	}

	void AddPropertyToObject(textworldParser::AssignmentContext* ctx, InteractiveObject* pObj) 
	{
		textworldParser::ValueContext* vc = ctx->value();
		string propertyName = ctx->ID()->getSymbol()->getText();
		if (vc->STRING() != nullptr)
		{
			string value = vc->STRING()->getSymbol()->getText();
#ifdef DEBUG
			cout << "Property value: " << value << endl;
#endif // DEBUG
			value = value.substr(1, value.length() - 2); // remove quotation marks

			if (propertyName == "name")
				pObj->SetName(value);
			else if (propertyName == "info")
				pObj->SetInfo(value);
			else if (propertyName == "infoUsed")
				pObj->SetInfoUsed(value);
			else if (propertyName == "worldDescription")
				pObj->SetWorldDescription(value);
			else if (propertyName == "worldDescriptionUsed")
				pObj->SetWorldDescriptionUsed(value);
			else if (propertyName == "useText")
				pObj->SetUseText(value);
			else if (propertyName == "takeText")
				pObj->SetTakeText(value);
			else if (propertyName == "command")
				pObj->AddObjectCommand(value);
			else if (propertyName == "tool")
				pObj->AddRequiredToolName(value);
			else if (propertyName == "element")
				pObj->AddRequiredElementName(value);
			else if (propertyName == "usability")
				pObj->SetUsablity(StringToUsability(value));
		}
		else if (vc->INT() != nullptr) {
			int value = stoi(vc->INT()->getSymbol()->getText());
#ifdef DEBUG
			cout << "Property value: " << vc->INT()->getSymbol()->getText() << endl;
#endif // DEBUG
			ConsumableStats stats = pObj->GetStats();
			if (propertyName == "warmth")
				stats.warmth = value;
			else if (propertyName == "food")
				stats.food = value;
			else if (propertyName == "drink")
				stats.drink = value;
			else if (propertyName == "inventoryCapacity")
				stats.invCapacity = value;
			else if (propertyName == "coldResist")
				stats.coldResist = value;
			else if (propertyName == "wood")
				stats.wood = value;
			else if (propertyName == "hidden") {
				if (value == 0)
					pObj->SetSubObjectsHidden(false);
				else
					pObj->SetSubObjectsHidden(true);
			}
			else if (propertyName == "pickup")
				if (value == 0)
					pObj->SetPickup(false);
				else
					pObj->SetPickup(true);
			pObj->SetUseStats(stats);
		}
	}

	virtual antlrcpp::Any visitWorld(textworldParser::WorldContext * ctx) override
	{
		return visitChildren(ctx);
	}


	virtual antlrcpp::Any visitWorldnode(textworldParser::WorldnodeContext * ctx) override 
	{
		m_NodeIndex++;
		m_ObjectIndex = -1; // reset object index for each node
#ifdef DEBUG
		cout << endl << "Found Worldnode: " << ctx->WORLDNODE()->getSymbol()->getText() << endl;
		cout << "Worldnode name: " << ctx->ID()->getSymbol()->getText() << endl;
#endif // DEBUG
		// Add worldnode with name
		m_WorldNodes.push_back(new WorldNode(ctx->ID()->getSymbol()->getText()));
		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitObject(textworldParser::ObjectContext * ctx) override 
	{
		m_ObjectIndex++;
		m_SubObjectIndex = -1; // reset subobject index for each object
#ifdef DEBUG
		cout << endl << "Found Object: " << ctx->OBJECT()->getSymbol()->getText() << endl;
		cout << "Object name: " << ctx->ID()->getSymbol()->getText() << endl;
#endif // DEBUG

		// add object to current node
		if(ctx->ID()->getSymbol()->getText() == "fire")
			m_WorldNodes[m_NodeIndex]->AddObject(new Campfire());
		else
			m_WorldNodes[m_NodeIndex]->AddObject(new InteractiveObject());
		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitSubobject(textworldParser::SubobjectContext * ctx) override
	{
		m_SubObjectIndex++;
#ifdef DEBUG
		cout << endl << "Found SubObject: " << ctx->SUBOBJECT()->getSymbol()->getText() << endl;
		cout << "SubObject name: " << ctx->ID()->getSymbol()->getText() << endl;
#endif // DEBUG

		// add subobject to current object
		m_WorldNodes[m_NodeIndex]->GetObjects()[m_ObjectIndex]->AddSubObject(new InteractiveObject());
		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitConnection(textworldParser::ConnectionContext * ctx) override
	{
		m_IsParsingConnections = true;
#ifdef DEBUG
		cout << endl << "Found Connection: " << ctx->CONNECTION()->getSymbol()->getText() << endl;
		cout << "Connection target: " << ctx->ID()->getSymbol()->getText() << endl;
#endif // DEBUG

		return visitChildren(ctx);
	}

	virtual antlrcpp::Any visitAssignment(textworldParser::AssignmentContext * ctx) override 
	{
		string propertyName = ctx->ID()->getSymbol()->getText();
#ifdef DEBUG
		cout << "Property name: " << propertyName << endl;
#endif // DEBUG
		textworldParser::ValueContext* vc = ctx->value();
		
		if (m_IsParsingConnections) 
		{
			if (vc->STRING() != nullptr)
			{
				string value = vc->STRING()->getSymbol()->getText();
				value = value.substr(1, value.length() - 2); // remove quotation marks

				if (propertyName == "target")
					m_CurrentConnection.pLinkedNode = GetWorldNodeByName(m_WorldNodes, value);
				else if (propertyName == "direction") {
					DIRECTION dir = StringToDirection(value);
					m_CurrentConnection.linkDirection = dir;
				}
				else if (propertyName == "start")
					GetWorldNodeByName(m_WorldNodes, value)->AddConnection(m_CurrentConnection);
			}
		}

		if (m_ObjectIndex == -1)
			AddPropertyToWorldNode(ctx);
		else if (m_SubObjectIndex == -1)
			AddPropertyToObject(ctx, m_WorldNodes[m_NodeIndex]->GetObjects()[m_ObjectIndex]);
		else
			AddPropertyToObject(ctx, m_WorldNodes[m_NodeIndex]->GetObjects()[m_ObjectIndex]->GetSubObjects()[m_SubObjectIndex]);

		return visitChildren(ctx);
	}

	vector<WorldNode*> GetWorldNodes() { return m_WorldNodes; }

private:
	vector<WorldNode*> m_WorldNodes;
	int m_NodeIndex = -1;
	int m_ObjectIndex = -1;
	int m_SubObjectIndex = -1;
	bool m_IsParsingConnections = false;
	Connection m_CurrentConnection;
};