#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Helpers.h"

using namespace std;

struct ConsumableStats {
	ConsumableStats() {}
	ConsumableStats(int w, int f, int d, int wood, int iC, int cR)
		:warmth(w), food(f), drink(d), wood(wood), invCapacity(iC), coldResist(cR)
	{}
	~ConsumableStats() {}

	int warmth = 0;
	int food = 0;
	int drink = 0;
	int wood = 0;
	int invCapacity = 0;
	int coldResist = 0;
};

class InteractiveObject
{
public:
	InteractiveObject();
	~InteractiveObject();
	InteractiveObject(const InteractiveObject& other);
	InteractiveObject(InteractiveObject&& other);
	virtual InteractiveObject& operator =(const InteractiveObject& other);
	virtual InteractiveObject& operator =(InteractiveObject&& other);

	// GETTERS
	virtual string GetName() const { return m_Name; }
	virtual string GetInfo() const;
	virtual string GetInfoUsed() const { return m_InfoUsed; }
	virtual string GetWorldDescription() const { return m_IsUsed ? m_WorldDescriptionUsed : m_WorldDescription; }
	virtual string GetWorldDescriptionUsed() const { return m_WorldDescriptionUsed; }
	virtual string GetTakeText() const;
	virtual string GetUseText() const { return m_UseText; };

	virtual vector<Command>& GetObjectCommands() { return m_ObjectCommandVec; }
	virtual vector<string>& GetRequiredToolNames() { return m_RequiredToolNameVec; }
	virtual vector<string>& GetRequiredElementNames() { return m_RequiredElementNameVec; }
	virtual vector<InteractiveObject*> GetSubObjects() const { return m_SubObjectVec; }
	virtual USABILTY GetUsability() const { return m_Usability; }
	virtual bool AreSubObjectsHidden() const { return m_AreSubObjectsHidden; }
	virtual bool IsPickup() const { return  m_IsPickup; }
	virtual bool IsUsed() const { return m_IsUsed; }
	virtual ConsumableStats GetStats() const { return m_UseStats; }

	// SETTERS
	virtual void SetName(const string& name) { m_Name = name; }
	virtual void SetInfo(const string& info) { m_Info = info; }
	virtual void SetInfoUsed(const string& info) { m_InfoUsed = info; }
	virtual void SetWorldDescription(const string& worldDesc) { m_WorldDescription = worldDesc; }
	virtual void SetWorldDescriptionUsed(const string& worldDesc) { m_WorldDescriptionUsed = worldDesc; }
	virtual void SetUseText(const string& useText) { m_UseText = useText; }
	virtual void SetTakeText(const string& line) { m_TakeText = line; }
	virtual void SetPickup(bool isPickup) { m_IsPickup = isPickup; }

	virtual void AddRequiredToolName(const string& toolName) { m_RequiredToolNameVec.push_back(toolName); }
	virtual void SetRequiredToolNames(const vector<string>& toolNames) { m_RequiredToolNameVec = toolNames; }
	virtual void AddRequiredElementName(const string& elementName) { m_RequiredElementNameVec.push_back(elementName); }
	virtual void SetRequiredElementNames(const vector<string>& elementNames) { m_RequiredElementNameVec = elementNames; }
	virtual void SetUseStats(const ConsumableStats& useStats) { m_UseStats = useStats; }
	virtual void SetUsablity(const USABILTY& usability) { m_Usability = usability; }

	virtual void AddObjectCommand(const string& objectCommand) { m_ObjectCommandVec.push_back(Command(USE, objectCommand)); }
	virtual void AddObjectCommands(const vector<string>& objectCommands);

	virtual void AddSubObject(InteractiveObject* const pSubObj) { m_SubObjectVec.push_back(pSubObj); }
	virtual void SetSubObjects(const vector<InteractiveObject*>& subObjects) { m_SubObjectVec = subObjects; }
	virtual void SetSubObjectsHidden(const bool hidden) { m_AreSubObjectsHidden = hidden; }

	virtual bool Use(WorldNode* pCurrentWorldNode);
private:
	virtual void UpdateStats();
	virtual void RemoveSubObject(const InteractiveObject* pObj);
	virtual void DeepCopy(const InteractiveObject& other);

protected:
	string m_Name;
	string m_Info; // individual object description
	string m_InfoUsed; // individual object description after one time use
	string m_WorldDescription; // description of object in WorldNode
	string m_WorldDescriptionUsed; // description of object in WorldNode after one time use
	string m_UseText; // output when item gets used
	string m_TakeText; // line when object is picked up

	vector<Command> m_ObjectCommandVec;
	vector<string> m_RequiredToolNameVec;
	vector<string> m_RequiredElementNameVec;
	ConsumableStats m_UseStats;
	USABILTY m_Usability;
	bool m_IsUsed = false;

	bool m_IsPickup ;

	bool m_AreSubObjectsHidden;
	vector<InteractiveObject*> m_SubObjectVec; // objects in this object (IE: berries in a bush)
};