#include "InteractiveObject.h"
#include <iostream>
#include "TimeManager.h"
#include "InputParser.h"
#include "WorldNode.h"
#include "PlayerStats.h"
#include "Inventory.h"
#include "Campfire.h"

InteractiveObject::InteractiveObject() :
	m_Name("name"),
	m_Info("info"),
	m_InfoUsed("info after use"),
	m_WorldDescription("world description"),
	m_WorldDescriptionUsed("world description after use"),
	m_UseText("object gets used"),
	m_TakeText("object gets picked up"),
	m_Usability(USABILTY::NONE),
	m_AreSubObjectsHidden(false),
	m_IsPickup(false)
{
}

InteractiveObject::~InteractiveObject()
{
	for_each(m_SubObjectVec.begin(), m_SubObjectVec.end(), [](InteractiveObject* pObj) { delete pObj; });
	m_SubObjectVec.clear();
}

InteractiveObject::InteractiveObject(const InteractiveObject & other)
{
	DeepCopy(other);
}

InteractiveObject::InteractiveObject(InteractiveObject&& other)
{
	swap(m_Name, other.m_Name);
	swap(m_WorldDescription, other.m_WorldDescription);
	swap(m_WorldDescriptionUsed, other.m_WorldDescriptionUsed);
	swap(m_Info, other.m_Info);
	swap(m_InfoUsed, other.m_InfoUsed);
	swap(m_TakeText, other.m_TakeText);
	swap(m_UseText, other.m_UseText);

	swap(m_Usability, other.m_Usability);
	swap(m_AreSubObjectsHidden, other.m_AreSubObjectsHidden);
	swap(m_IsPickup, other.m_IsPickup);

	swap(m_UseStats, other.m_UseStats);
	swap(m_ObjectCommandVec, other.m_ObjectCommandVec);
	swap(m_SubObjectVec, other.m_SubObjectVec);
	swap(m_RequiredElementNameVec, other.m_RequiredElementNameVec);
	swap(m_RequiredToolNameVec, other.m_RequiredToolNameVec);
}

InteractiveObject & InteractiveObject::operator=(const InteractiveObject & other)
{
	DeepCopy(other);
	return *this;
}

InteractiveObject & InteractiveObject::operator=(InteractiveObject && other)
{
	if (this != &other) {
		swap(m_Name, other.m_Name);
		swap(m_WorldDescription, other.m_WorldDescription);
		swap(m_WorldDescriptionUsed, other.m_WorldDescriptionUsed);
		swap(m_Info, other.m_Info);
		swap(m_InfoUsed, other.m_InfoUsed);
		swap(m_TakeText, other.m_TakeText);
		swap(m_UseText, other.m_UseText);

		swap(m_Usability, other.m_Usability);
		swap(m_AreSubObjectsHidden, other.m_AreSubObjectsHidden);
		swap(m_IsPickup, other.m_IsPickup);

		swap(m_UseStats, other.m_UseStats);
		swap(m_ObjectCommandVec, other.m_ObjectCommandVec);
		swap(m_SubObjectVec, other.m_SubObjectVec);
		swap(m_RequiredElementNameVec, other.m_RequiredElementNameVec);
		swap(m_RequiredToolNameVec, other.m_RequiredToolNameVec);
	}
	return *this;
}

string InteractiveObject::GetInfo() const
{
	string result = "";
	if (m_IsUsed) {
		cout << m_InfoUsed << endl;
		result += m_InfoUsed;
	}
	else {
		cout << m_Info << endl;
		result += m_Info;
	}

	if (!m_AreSubObjectsHidden)
	{
		for (auto pSubObj : m_SubObjectVec)
		{
			cout << pSubObj->GetWorldDescription() << endl;
			result += pSubObj->GetWorldDescription();
		}
	}
	cout << endl;
	return result;
}

string InteractiveObject::GetTakeText() const
{
	if (m_IsPickup)
		cout << m_TakeText << endl;
	return m_TakeText;
}

bool InteractiveObject::Use(WorldNode* pCurrentWorldNode)
{
	switch (m_Usability)
	{
	case USABILTY::UNLIMITED:
		cout << m_UseText;
		break;
	case USABILTY::ONCE:
	case USABILTY::DESTROY_AFTER_USE:
		if (m_IsUsed)
			return false;
		cout << m_UseText;
		m_IsUsed = true;
		break;
	case USABILTY::NONE:
		cout << "Can't use that!";
		break;
	default:
		break;
	}
	cout << endl;

	// update stats of consumption
	UpdateStats();

	// drop loot if it contains any
	for (size_t i = 0; i < m_SubObjectVec.size(); i++)
	{
		if (Inventory::GetInstance().AddToInventory(m_SubObjectVec[i])) {
			m_SubObjectVec[i]->GetTakeText();
			RemoveSubObject(m_SubObjectVec[i]);
		}
		else {
			// add subobjects to world node if inventory is full
			pCurrentWorldNode->AddObject(m_SubObjectVec[i]);
			RemoveSubObject(m_SubObjectVec[i]);
		}
	}

	// if the item contains wood try to use it as fuel
	if (m_UseStats.wood > 0 && pCurrentWorldNode->GetCampfire())
			pCurrentWorldNode->GetCampfire()->AddFuel(m_UseStats.wood);
	
	return true;
}

void InteractiveObject::UpdateStats()
{
	PlayerStats& ps = PlayerStats::GetInstance();
	ps.m_Warmth += m_UseStats.warmth;
	ps.m_Food += m_UseStats.food;
	ps.m_Drink += m_UseStats.drink;
	ps.m_ColdResist += m_UseStats.coldResist;
	Inventory::GetInstance().IncrementCapacity(m_UseStats.invCapacity);
}

void InteractiveObject::RemoveSubObject(const InteractiveObject* pObj)
{
	if (!pObj) {
		cout << "[InteractiveObject.cpp]RemoveObject: Trying to delete invalid object" << endl;
		return;
	}
	auto it = find(m_SubObjectVec.begin(), m_SubObjectVec.end(), pObj);
	if (it != m_SubObjectVec.end())
		m_SubObjectVec.erase(it);
}

void InteractiveObject::DeepCopy(const InteractiveObject& other)
{
	m_Name = other.m_Name;
	m_WorldDescription = other.m_WorldDescription;
	m_WorldDescriptionUsed = other.m_WorldDescriptionUsed;
	m_Info = other.m_Info;
	m_InfoUsed = other.m_InfoUsed;
	m_TakeText = other.m_TakeText;
	m_UseText = other.m_UseText;

	m_Usability = other.m_Usability;
	m_AreSubObjectsHidden = other.m_AreSubObjectsHidden;
	m_IsPickup = other.m_IsPickup;

	m_UseStats = other.m_UseStats;
	m_ObjectCommandVec = other.m_ObjectCommandVec;
	m_SubObjectVec = other.m_SubObjectVec;
	m_RequiredElementNameVec = other.m_RequiredElementNameVec;
	m_RequiredToolNameVec = other.m_RequiredToolNameVec;
}

void InteractiveObject::AddObjectCommands(const vector<string>& objectCommands)
{
	for_each(objectCommands.begin(), objectCommands.end(), 
		[&](string line) {m_ObjectCommandVec.push_back(Command(USE, line)); });
}
