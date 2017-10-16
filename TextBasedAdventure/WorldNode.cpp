#include "WorldNode.h"
#include <iostream>
#include "InteractiveObject.h"
#include "TimeManager.h"
#include "Campfire.h"
#include "OutputFormatter.h"

WorldNode::WorldNode(const string name, const string description)
	: m_Name(name), m_Description(description)
{
}

WorldNode::~WorldNode()
{
	for_each(m_ObjectsVec.begin(), m_ObjectsVec.end(), [](InteractiveObject* pObj) { delete pObj; });
	m_ObjectsVec.clear();
}

WorldNode::WorldNode(const WorldNode& other)
{
	m_Name = other.m_Name;
	m_Description = other.m_Description;
	m_ConnectionsVec = other.m_ConnectionsVec;
	m_ObjectsVec = other.m_ObjectsVec;
}

WorldNode::WorldNode(WorldNode&& other)
{
	swap(m_Name, other.m_Name);
	swap(m_Description, other.m_Description);
	swap(m_ConnectionsVec, other.m_ConnectionsVec);
	swap(m_ObjectsVec, other.m_ObjectsVec);
}

WorldNode& WorldNode::operator=(const WorldNode & other)
{
	for_each(m_ObjectsVec.begin(), m_ObjectsVec.end(), [](InteractiveObject* pObj) { delete pObj; });
	m_ObjectsVec.clear();

	m_Name = other.m_Name;
	m_Description = other.m_Description;
	m_ConnectionsVec = other.m_ConnectionsVec;
	m_ObjectsVec = other.m_ObjectsVec;
	return *this;
}

WorldNode & WorldNode::operator=(WorldNode&& other)
{
	swap(m_Name, other.m_Name);
	swap(m_Description, other.m_Description);
	swap(m_ConnectionsVec, other.m_ConnectionsVec);
	swap(m_ObjectsVec, other.m_ObjectsVec);
	return *this;
}

WorldNode* WorldNode::GoDirection(const DIRECTION dir) {
	WorldNode* node = GetNodeByDirection(dir);

	if (node != this)
		cout << node->GetDescription();

	//OutputFormatter::GetInstance().PrintSlow(desc);

	return node;
}

string WorldNode::GetDescription() const
{
	string desc;
	if (TimeManager::GetInstance().IsNightTime()) {
		desc = "It's dark...\n";
		return desc;
	}

	desc = m_Description;
	// Get base node description and add more for every present interactive object
	for (auto pObj : m_ObjectsVec)
	{
		if (pObj->GetWorldDescription() != "")
			desc += "\n" + pObj->GetWorldDescription();
	}
	desc += "\n";

	return desc;
}

Campfire* WorldNode::GetCampfire() const
{
	Campfire* pFire = dynamic_cast<Campfire*>(GetObjectByName("Fire"));
	return pFire;
}

void WorldNode::LinkToWorldNode(WorldNode* pNode, DIRECTION dir) 
{
	m_ConnectionsVec.push_back(Connection(dir, pNode));
}

void WorldNode::AddObject(InteractiveObject * pNewObj)
{
	auto it = find_if(m_ObjectsVec.begin(), m_ObjectsVec.end(), [](InteractiveObject* pObj) { return pObj == nullptr; });
	if (it != m_ObjectsVec.end())
		*it = pNewObj;
	else
		m_ObjectsVec.push_back(pNewObj);
}

void WorldNode::RemoveObject(const InteractiveObject* pObj)
{
	if (!pObj) {
		cout << "[WorldNode.cpp]RemoveObject: Trying to delete invalid object" << endl;
		return;
	}
	auto it = find(m_ObjectsVec.begin(), m_ObjectsVec.end(), pObj);
	if (it != m_ObjectsVec.end())
		m_ObjectsVec.erase(it);
}

InteractiveObject * WorldNode::GetObjectByName(const string& name) const
{
	auto it = find_if(m_ObjectsVec.begin(), m_ObjectsVec.end(), 
		[&](InteractiveObject* pObj) { return pObj->GetName() == name; });
	if(it != m_ObjectsVec.end())
		return *it;
	return nullptr;
}

/* Private methods */
/*-----------------*/
WorldNode* WorldNode::GetNodeByDirection(const DIRECTION& dir) {
	for (auto con : m_ConnectionsVec) {
		if (con.linkDirection == dir) {
			return con.pLinkedNode;
		}
	}
	cout << "There's no way to go " << DirectionToString(dir) << endl;
	return this; // return current WorldNode if no connected node was found
}