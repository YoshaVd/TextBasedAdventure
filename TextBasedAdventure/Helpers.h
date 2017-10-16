#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class WorldNode; 

using namespace std;

enum CONSUMABLE_TYPE {
	FOOD,
	DRINK,
	WARMTH,
	CONTAINER,
	CLOTHING,
	CARRY,
};

enum DIRECTION {
	NONE,
	EAST,
	NORTH,
	SOUTH,
	WEST,
	// up, down?
};

enum class USABILTY {
	UNLIMITED,
	ONCE,
	DESTROY_AFTER_USE,
	NONE,
};

struct Connection {
	Connection() {}
	Connection(DIRECTION& dir, WorldNode* pNode) : linkDirection(dir), pLinkedNode(pNode) {}
	~Connection() {}

	WorldNode* pLinkedNode;
	DIRECTION linkDirection;
	bool isAccessible = true;
};

enum COMMAND_TYPE {
	HELP,
	HERE,
	TIME,
	INVENTORY,
	GO,
	TAKE,
	EXAMINE,
	INVALID,
	USE,
	DROP, // to do
	SLEEP, // to do
	HEALTH,
};

struct Command {
	Command() {};
	Command(COMMAND_TYPE t, string l = "default") : type(t), line(l) {};

	COMMAND_TYPE type = INVALID;
	string line = "default";
};

inline string ToLowerCase(const string& a)
{
	string result = a;
	for_each(result.begin(), result.end(), [](char& i) { i = tolower(i); });
	return result;
}

inline std::string DirectionToString(const DIRECTION dir)
{
	switch (dir)
	{
	case NONE:
		return "none";
	case EAST:
		return "east";
	case NORTH:
		return "north";
	case SOUTH:
		return "south";
	case WEST:
		return "west";
	default:
		break;
	}
}

inline DIRECTION StringToDirection(string direction)
{
	direction = ToLowerCase(direction);
	if (direction == "north")
		return NORTH;
	if (direction == "east")
		return EAST;
	if (direction == "south")
		return SOUTH;
	if (direction == "west")
		return WEST;
	cout << "[Helpers.h]StringToDirecion: Invalid string to DIRECTION conversion." << endl;
	return NONE;
}

inline COMMAND_TYPE StringToCommandType(const string command)
{
	if (command == "HELP")
		return HELP;
	if (command == "HERE")
		return HERE;
	if (command == "TIME")
		return TIME;
	if (command == "INVENTORY")
		return INVENTORY;
	if (command == "GO")
		return GO;
	if (command == "TAKE")
		return TAKE;
	if (command == "EXAMINE")
		return EXAMINE;
	if (command == "DROP")
		return DROP;
	if (command == "SLEEP")
		return SLEEP;	
	if (command == "USE")
		return USE;
	if (command == "HEALTH")
		return HEALTH;
	cout << "[Helpers.h]StringToCommandType: Invalid string to COMMAND_TYPE conversion." << endl;
	return INVALID;
}

inline USABILTY StringToUsability(const string& use) {
	if (use == "destroyAfterUse")
		return USABILTY::DESTROY_AFTER_USE;
	if (use == "once")
		return USABILTY::ONCE;
	if (use == "unlimited")
		return USABILTY::UNLIMITED;
	if (use == "none")
		return USABILTY::NONE;
	cout << "[Helpers.h]StringToUsability: Invalid string to USABILITY conversion." << endl;
	return USABILTY::NONE;
}

inline int GetLongestStringLength(const vector<string> strings)
{
	int longest = 0;
	for_each(strings.begin(), strings.end(), 
		[&longest](string str) {if (str.size() > longest) longest = str.size(); });
	return longest;
}
