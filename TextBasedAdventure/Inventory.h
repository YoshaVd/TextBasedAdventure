#pragma once
#include "InteractiveObject.h"
#include <vector>

class InteractiveObject;
using namespace std;

class Inventory // singleton
{
public:
	static Inventory& GetInstance() {
		static Inventory instance;
		return instance;
	}
	~Inventory() {};
	Inventory(Inventory const&) = delete;
	void operator=(Inventory const&) = delete;

	vector<InteractiveObject*> GetObjects() const { return m_ObjectsVec; }
	bool IsFull() const;

	bool AddToInventory(InteractiveObject* pObj);
	void RemoveObject(const InteractiveObject* pObj);
	void ShowContents() const;
	void IncrementCapacity(int amount) { m_Capacity += amount; }

private:
	Inventory() {};
	InteractiveObject* GetObjectByName(const string& name) const;

	// Member variables
	const int DEFAULT_CAPACITY = 4;
	int m_Capacity = DEFAULT_CAPACITY;
	// TO DO: initialize inventory to preset size, display empty slots
	vector<InteractiveObject*>  m_ObjectsVec;
};

