#pragma once
#include <string>
#include <vector>
#include "Helpers.h"

class InteractiveObject;
class Campfire;

using namespace std;

class WorldNode
{
public:
	WorldNode() {}
	WorldNode(string name = "none", string description = "none");
	~WorldNode();
	WorldNode(const WorldNode& other);
	WorldNode(WorldNode&& other);
	WorldNode& operator =(const WorldNode& other);
	WorldNode& operator =(WorldNode&& other);

	WorldNode* GoDirection(const DIRECTION dir);

	void SetName(const string& name) { m_Name = name; }
	void SetDescription(const string& description) { m_Description = description; }

	string GetDescription() const;
	string GetName() const { return m_Name; };
	Campfire* GetCampfire() const;

	void LinkToWorldNode(WorldNode* pNode, DIRECTION dir = DIRECTION::NONE);
	void AddConnection(const Connection& con) { m_ConnectionsVec.push_back(con); }
	vector<Connection>& GetConnections() { return m_ConnectionsVec; }

	void AddObject(InteractiveObject* pNewObj);
	void RemoveObject(const InteractiveObject* pObj);
	InteractiveObject* GetObjectByName(const string& name) const;
	vector<InteractiveObject*> GetObjects() const { return m_ObjectsVec; }

private:
	//Private methods
	WorldNode* GetNodeByDirection(const DIRECTION& dir);

	//Member variables
	string m_Name;
	string m_Description;
	vector<Connection> m_ConnectionsVec;
	vector<InteractiveObject*> m_ObjectsVec;
};