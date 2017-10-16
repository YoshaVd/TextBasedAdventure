#include "Inventory.h"
#include <iostream>
#include "OutputFormatter.h"

using namespace std;

bool Inventory::IsFull() const
{
	if (m_ObjectsVec.size() < m_Capacity)
		return false;

	auto it = find_if(m_ObjectsVec.begin(), m_ObjectsVec.end(), 
		[](InteractiveObject* pObj) { return pObj == nullptr; });
	if (it != m_ObjectsVec.end())
		return false;

	cout << "Inventory is full!" << endl;
	return true;
}

bool Inventory::AddToInventory(InteractiveObject * pObj)
{
	if (m_ObjectsVec.size() < m_Capacity) {
		m_ObjectsVec.push_back(pObj);
		return true;
	}
	
	auto it = find_if(m_ObjectsVec.begin(), m_ObjectsVec.end(),
		[](InteractiveObject* pSlot) { return pSlot == nullptr; });
	if (it != m_ObjectsVec.end())
	{
		*it = pObj;
		return true;
	}

	cout << "I can't carry that many objects!" << endl;
	return false;
}

void Inventory::RemoveObject(const InteractiveObject* pObj)
{
	if (pObj != nullptr)
	{
		for (int i = 0; i < m_ObjectsVec.size(); ++i)
		{
			if (m_ObjectsVec[i] == pObj)
				m_ObjectsVec.erase(m_ObjectsVec.begin() + i);
		}
	}
	else
		cout << "Can't remove that from Inventory." << endl;
}

void Inventory::ShowContents() const
{
	OutputFormatter& of = OutputFormatter::GetInstance();
	of.NewTable();
	of.SetTableColumnNames(vector<string> {"Slot", "Name"});

	vector<string> objNamesVec;
	for (size_t i = 0; i < m_ObjectsVec.size(); i++)
		objNamesVec.push_back(m_ObjectsVec[i]->GetName());

	vector<string> invSlotsVec;
	for (size_t i = 0; i < m_Capacity; i++)
		invSlotsVec.push_back(to_string(i));

	of.SetTableValues(invSlotsVec, objNamesVec);
	of.PrintTable(true);
}

InteractiveObject* Inventory::GetObjectByName(const string& name) const
{
	auto it = find_if(m_ObjectsVec.begin(), m_ObjectsVec.end(),
		[&](InteractiveObject* pObj) { return pObj->GetName() == name; });
	if (it != m_ObjectsVec.end())
		return *it;

	return nullptr;
}
