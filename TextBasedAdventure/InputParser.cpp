#include "InputParser.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <fstream>
#include <cstdarg>

#include "WorldNode.h"
#include "InteractiveObject.h"
#include "TimeManager.h"
#include "Inventory.h"
#include "OutputFormatter.h"
#include "PlayerStats.h"

using namespace std;

void InputParser::Update()
{
	// get vector of words from input
	cout << endl;
	string input;
	getline(cin, input);
	vector<string> wordVec;
	wordVec = Split(input, ' ');
	cout << endl;
	if (wordVec[0] == "quit")
		PlayerStats::GetInstance().m_IsAlive = false;

	// look for the first command with a valid target and execute it 
	Command firstCommand = GetFirstInputCommand(wordVec, false);
	bool isCommandExecuted = false;
	switch (firstCommand.type)
	{
	case INVALID:
		cout << "No valid command was found[1]" << endl;
		return;
	case HELP:
		PrintHelp();
		return;
	case HERE:
		cout << m_pCurrentNode->GetDescription();
		return;
	case TIME:
		TimeManager::GetInstance().GetTime();
		return;
	case INVENTORY:
		Inventory::GetInstance().ShowContents();
		return;
	case HEALTH:
		PlayerStats::GetInstance().GetHealthInfo();
		return;
	case SLEEP:
	{
		// can only sleep with a campfire nearby
		Campfire* pFire = m_pCurrentNode->GetCampfire();
		if (pFire)
			PlayerStats::GetInstance().Rest(pFire);
		else
			cout << "It's too cold and wet to sleep here." << endl;
		return;
	}
	case GO:
	case TAKE:
	case EXAMINE:
	case USE:
		// recursive use of ExecuteFirstValidCommand() until the first valid command is found and executet
		isCommandExecuted = ExecuteFirstValidCommand(wordVec);
		break;
	default:
		cout << "No matching case was found in the command switch structure" << endl;
		break;
	}

	// update time and stats based on the executed command
	if (isCommandExecuted) {
		TimeManager::GetInstance().IncrementTime(firstCommand.type);
		PlayerStats::GetInstance().UpdateStatsOverTime(firstCommand.type);
	}
}

bool InputParser::ExecuteFirstValidCommand(vector<string>& wordVec)
{
	Command firstCommand = GetFirstInputCommand(wordVec);
	int maxIndex = wordVec.size();
	bool isCommandExecuted = false;
	switch (firstCommand.type)
	{
	case INVALID:
		//cout << "No valid command was found[2]" << endl;
		isCommandExecuted = false;
		break;
	case HELP:
	case HERE:
	case TIME:
	case INVENTORY:
	case HEALTH:
	case SLEEP:
		isCommandExecuted = ExecuteFirstValidCommand(wordVec);
		break;
	case GO:
		isCommandExecuted = TryGo(wordVec, maxIndex);
		break;
	case TAKE:
		isCommandExecuted = TryTake(wordVec, maxIndex);
		break;
	case EXAMINE:
		isCommandExecuted = TryExamine(wordVec, maxIndex);
		break;
	case USE:
		isCommandExecuted = TryUseInventory(wordVec, maxIndex);
		if (!isCommandExecuted)
			isCommandExecuted = TryUseWorld(wordVec, maxIndex);
		break;
	default:
		break;
	}

	return isCommandExecuted;
}

bool InputParser::TryGo(vector<string>& wordVec, int& maxIndex)
{
	// compare input with direction words
	// SUCCESS: attempt to go in direction if one is found
	DIRECTION dir = NONE;
	for (size_t i = 0; i < maxIndex; i++)
	{
		if (IsWordDirection(wordVec[i], dir))
		{
			// avoid looking for targets words after the target of the first valid command
			maxIndex = i + 1; 
			// if there's no room for another valid command in between the current command and it's target
			// OR if there is room but there's no valid command there execute the current command
			if (i < MIN_COMMAND_LENGTH || !ExecuteFirstValidCommand(wordVec)) {
				WorldNode* pPreviousNode = m_pCurrentNode;
				m_pCurrentNode = m_pCurrentNode->GoDirection(dir);
				if (m_pCurrentNode == pPreviousNode)
					return false;
				else
					return true;
			}
		}
	}
	cout << "Can't go there!" << endl;
	return false;
}

bool InputParser::TryTake(vector<string>& wordVec, int & maxIndex)
{
	// compare input with names of objects in the current WorldNode
	// SUCCESS: attempt to take it, add to inventory and remove from node
	for (size_t i = 0; i < maxIndex; i++)
	{
		InteractiveObject* pObj = FindObjectWithName(m_pCurrentNode->GetObjects(), wordVec[i]);
		if (!pObj) continue;

		maxIndex = i + 1;
		if (i < MIN_COMMAND_LENGTH || !ExecuteFirstValidCommand(wordVec))
		{
			if (!Inventory::GetInstance().IsFull() && pObj->IsPickup()) {
				pObj->GetTakeText();
				Inventory::GetInstance().AddToInventory(pObj);
				m_pCurrentNode->RemoveObject(pObj);
				return true;
			}
		}
	}
	cout << "Can't take that!" << endl;
	return false;
}

bool InputParser::TryExamine(vector<string>& wordVec, int & maxIndex)
{
	// compare input with names of objects in the current WorldNode
	// SUCCESS: get object information
	for (size_t i = 0; i < maxIndex; i++)
	{
		InteractiveObject* pObj = FindObjectWithName(m_pCurrentNode->GetObjects(), wordVec[i]);
		if (!pObj)
			pObj = FindObjectWithName(Inventory::GetInstance().GetObjects(), wordVec[i]);
		if (!pObj) continue;

		maxIndex = i + 1;
		if (i < MIN_COMMAND_LENGTH || !ExecuteFirstValidCommand(wordVec)) {
			pObj->GetInfo();
			return true;
		}
	}
	cout << "There's no such thing to examine!" << endl;
	return false;
}

bool InputParser::TryUseInventory(vector<string>& wordVec, int & maxIndex)
{
	// compare input with names of objects in inventory
	// SUCCESS: attempt to use it, destroy depending on USABILITY
	for (size_t i = 0; i < maxIndex; i++)
	{
		InteractiveObject* pInvObj = FindObjectWithName(Inventory::GetInstance().GetObjects(), wordVec[i]);
		if (!pInvObj) continue;

		// if it's a tool look for another object to use it on
		if (pInvObj->GetObjectCommands().size() > 0)
			return TryUseWorld(wordVec, maxIndex);

		maxIndex = i + 1;
		if (i < MIN_COMMAND_LENGTH || !ExecuteFirstValidCommand(wordVec))
		{
			if (pInvObj->IsUsed()) {
				cout << "Can't use that.\n";
				pInvObj->GetInfo();
			}
			else if (HasRequiredTool(pInvObj) && HasRequiredElement(pInvObj)) {
				pInvObj->Use(m_pCurrentNode);
				if (pInvObj->GetUsability() == USABILTY::DESTROY_AFTER_USE)
					Inventory::GetInstance().RemoveObject(pInvObj);
			}

			return true;
		}
	}
	return false;
}

bool InputParser::TryUseWorld(vector<string>& wordVec, int & maxIndex)
{
	// compare input with names of objects in the current WorldNode
	// SUCCESS: attempt to use it, destroy depending on USABILITY
	for (size_t i = 0; i < maxIndex; i++)
	{
		InteractiveObject* pObj = FindObjectWithName(m_pCurrentNode->GetObjects(), wordVec[i]);
		if (!pObj) continue;

		maxIndex = i + 1;
		if (i < MIN_COMMAND_LENGTH || !ExecuteFirstValidCommand(wordVec))
		{
			if (pObj->IsUsed()) {
				cout << "Can't use that.\n";
				pObj->GetInfo();
			}
			else if (HasRequiredTool(pObj)) {
				pObj->Use(m_pCurrentNode);
				if (pObj->GetUsability() == USABILTY::DESTROY_AFTER_USE)
					m_pCurrentNode->RemoveObject(pObj);
			}
			return true;
		}
	}
	cout << "Can't use that!" << endl;
	return false;
}

vector<string> InputParser::Split(const string& input, char delim = '\n')
{
	// splits the input string by the given delimeter 
	// and returns a vector of strings in lower case for case insensitive comparison
	vector<string> result;
	stringstream inputStream(input);

	while (inputStream.good())
	{
		string substr;
		getline(inputStream, substr, delim);
		if (substr.length() > 0) {
			std::transform(substr.begin(), substr.end(), substr.begin(), ::tolower);
			result.push_back(substr);
		}
	}

	return result;
}

Command InputParser::GetFirstInputCommand(vector<string>& wordsVec, bool eraseWords)
{
	vector<Command> validCommands = m_ValidCommandsVec;
	// add object specific commands to general valid commands
	vector<Command> objectCommands = GetInventoryObjectCommands();
	validCommands.insert(validCommands.end(), objectCommands.begin(), objectCommands.end());

	// check input for the first valid command and return it
	for (int input = 0; input < wordsVec.size(); ++input)
	{
		for (int valids = 0; valids < validCommands.size(); ++valids)
		{
			string validCommand = validCommands[valids].line;
			// if the valid command contains 2 words, check the next 2 words from the input
			if (validCommand.find(" ") != string::npos && input < wordsVec.size() - 1)
			{
				string twoWordsLine = wordsVec[input] + ' ' + wordsVec[input + 1];
				// when a valid command is found erase all the words up until that part and return the command
				if (twoWordsLine == validCommand)
				{
					if (eraseWords)
						wordsVec.erase(wordsVec.begin(), wordsVec.begin() + input + 2);
					return validCommands[valids];
				}
			}
			// else compare the command line with the single input word
			else
			{
				// when a valid command is found erase all the words up until that part and return the command
				if (wordsVec[input] == validCommand)
				{
					if (eraseWords)
						wordsVec.erase(wordsVec.begin(), wordsVec.begin() + input + 1);
					return validCommands[valids];
				}
			}
		}
	}
	return Command();
}

vector<Command>& InputParser::GetInventoryObjectCommands()
{
	vector<Command> inventoryObjectsCommands = vector<Command>{};
	vector<InteractiveObject*> invObjects = Inventory::GetInstance().GetObjects();
	for (auto pObj : invObjects)
	{
		vector<Command> objCommands = pObj->GetObjectCommands();
		inventoryObjectsCommands.insert(inventoryObjectsCommands.end(), objCommands.begin(), objCommands.end());
	}
	return inventoryObjectsCommands;
}

bool InputParser::HasRequiredTool(InteractiveObject* pTargetObj)
{
	if (pTargetObj->GetRequiredToolNames().size() == 0)
		return true;

	vector<string> toolNames = pTargetObj->GetRequiredToolNames();
	InteractiveObject* pObj; 
	for (auto tool : toolNames)
	{
		if (FindObjectWithName(Inventory::GetInstance().GetObjects(), tool))
			return true;
	}
	
	cout << "You lack the proper equipment to do that!" << endl;
	return false;
}

bool InputParser::HasRequiredElement(InteractiveObject* pTargetObj)
{
	if (pTargetObj->GetRequiredElementNames().size() == 0)
		return true;

	vector<string> elementNames = pTargetObj->GetRequiredElementNames();
	for (auto name : elementNames)
	{
		if (FindObjectWithName(m_pCurrentNode->GetObjects(), name))
			return true;
	}

	cout << "You lack the means to do that!" << endl;
	return false;
}

InteractiveObject* InputParser::FindObjectWithName(const vector<InteractiveObject*>& objects, const string & name)
{
	// checks for an object with the same name (in lower case)
	auto it = find_if(objects.begin(), objects.end(),
		[&](InteractiveObject* pObj) {
		return ToLowerCase(pObj->GetName()) == name; 
	});

	if (it == objects.end())
		return nullptr;
	else
		return *it;
}

bool InputParser::IsWordDirection(const string word, DIRECTION& dir) {
	if (WordMatchesDirection(word, EAST)) {
		dir = EAST;
		return true;
	}
	if (WordMatchesDirection(word, NORTH)) {
		dir = NORTH;
		return true;
	}
	if (WordMatchesDirection(word, SOUTH)) {
		dir = SOUTH;
		return true;
	} 
	if (WordMatchesDirection(word, WEST)) {
		dir = WEST;
		return true;
	}
	dir = NONE;
	return false;
}

bool InputParser::WordMatchesDirection(const string word, DIRECTION dir)
{
	for (auto dirPair : m_ValidDirectionStrings)
	{
		if (dirPair.first == word && dirPair.second == dir)
			return true;
	}
	return false;
}

void InputParser::PrintHelp()
{
	vector<string> helpStrings;
	vector<string> hereStrings;
	vector<string> timeStrings;
	vector<string> goStrings;
	vector<string> takeStrings;
	vector<string> examineStrings;

	for (size_t i = 0; i < m_ValidCommandsVec.size(); i++)
	{
		switch (m_ValidCommandsVec[i].type)
		{
		case HELP:
			helpStrings.push_back(m_ValidCommandsVec[i].line);
			break;
		case HERE:
			hereStrings.push_back(m_ValidCommandsVec[i].line);
			break;
		case TIME:
			timeStrings.push_back(m_ValidCommandsVec[i].line);
			break;
		case GO:
			goStrings.push_back(m_ValidCommandsVec[i].line);
			break;
		case TAKE:
			takeStrings.push_back(m_ValidCommandsVec[i].line);
			break;
		case EXAMINE:
			examineStrings.push_back(m_ValidCommandsVec[i].line);
			break;
		default:
			break;
		}
	}
	OutputFormatter& of = OutputFormatter::GetInstance();
	of.NewTable();
	of.SetTableColumnNames(vector<string> {"HELP", "HERE", "TIME", "GO", "TAKE", "EXAMINE"});
	of.SetTableValues(helpStrings, hereStrings, timeStrings, goStrings, takeStrings, examineStrings);
	of.PrintTable();
}

void InputParser::LoadCommandsFromFile(const string& path)
{
	fstream file;
	file.open(path, fstream::in);
	COMMAND_TYPE type = HELP;

	while (!file.eof()) 
	{
		string line;
		getline(file, line);

		if (line.length() <= 0)
			continue;

		if (line[0] == '[')
		{
			int index = line.find(']');
			line = line.substr(1, index - 1);
			type = StringToCommandType(line);
			continue;
		}

		Command command = Command(type, line);
		m_ValidCommandsVec.push_back(command);
	}
}

void InputParser::LoadDirectionsFromFile(const string& path)
{
	fstream file;
	file.open(path, fstream::in);
	DIRECTION dir = NONE;

	while (!file.eof())
	{
		string line;
		getline(file, line);

		if (line.length() <= 0)
			continue;

		if (line[0] == '[')
		{
			int index = line.find(']');
			line = line.substr(1, index - 1);
			dir = StringToDirection(line);
			continue;
		}

		m_ValidDirectionStrings[line] = dir;
	}
}