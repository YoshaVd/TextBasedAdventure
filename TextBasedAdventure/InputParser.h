#pragma once
#include <string>
#include <map>
#include "Helpers.h"

class WorldNode;
class InteractiveObject;

using namespace std;

class InputParser // singleton
{
public:
	static InputParser& GetInstance() {
		static InputParser instance;
		return instance;
	}
	~InputParser() {};
	InputParser(InputParser const&) = delete;
	void operator=(InputParser const&) = delete;

	void Update(); // TODO? change parsing to only one word sentences for help, inv, here, time,...
	void LoadCommandsFromFile(const string& path);
	void LoadDirectionsFromFile(const string& path);
	void SetCurrentNode(WorldNode* const pCurrentNode) { m_pCurrentNode = pCurrentNode; }
	WorldNode* GetCurrentNode() const { return m_pCurrentNode; }

private:
	InputParser() {};

	bool ExecuteFirstValidCommand(vector<string>& wordVec);
	bool TryGo(vector<string>& wordVec, int& maxIndex);
	bool TryTake(vector<string>& wordVec, int& maxIndex);
	bool TryExamine(vector<string>& wordVec, int& maxIndex);
	bool TryUseWorld(vector<string>& wordVec, int& maxIndex);
	bool TryUseInventory(vector<string>& wordVec, int& maxIndex);

	// parsing methods
	vector<string> Split(const std::string & values, char delim);
	Command GetFirstInputCommand(vector<string>& wordsVec, bool eraseWords = true);
	vector<Command>& GetInventoryObjectCommands();
	bool HasRequiredTool(InteractiveObject* pTargetObj);
	bool HasRequiredElement(InteractiveObject * pTargetObj);
	InteractiveObject* FindObjectWithName (const vector<InteractiveObject*>& objects, const string& name);

	void PrintHelp();

	bool IsWordDirection(const string word, DIRECTION& dir);
	bool WordMatchesDirection(const string word, DIRECTION dir);

	// member variables
	WorldNode* m_pCurrentNode = nullptr;

	vector<Command> m_ValidCommandsVec;
	std::map<string, DIRECTION> m_ValidDirectionStrings;

	const int MIN_COMMAND_LENGTH = 2;
};