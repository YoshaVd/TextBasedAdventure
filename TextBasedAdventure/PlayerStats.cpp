#include "PlayerStats.h"
#include <iostream>
#include "OutputFormatter.h"

using namespace std;

void PlayerStats::GetHealthInfo() const
{
	OutputFormatter& of = OutputFormatter::GetInstance();
	of.NewTable();
	of.SetTableColumnNames(vector<string> {"HEALTH", ""});

	vector<string> statNames = { "Warmth", "Food", "Drink" };
	vector<string> statCounts = { to_string(m_Warmth), to_string(m_Food), to_string(m_Drink) };

	of.SetTableValues(statNames, statCounts);
	of.PrintTable(true);
}

void PlayerStats::UpdateStatsOverTime(const COMMAND_TYPE& type)
{
	// Change stats based on what action is performed
	float warmthMultiplier = m_ColdResist * m_HungerMultiplier * m_ThirstMultiplier;
	switch (type)
	{
	case HELP:
	case HERE:
	case TIME:
	case INVENTORY:
	case DROP:
		break;
	case GO:
		m_Warmth -= 3 / warmthMultiplier;
		m_Food -= 5;
		m_Drink -= 10;
		break;
	case EXAMINE:
		m_Warmth -= 3 / warmthMultiplier;
		m_Food -= 1;
		m_Drink -= 1;
		break;
	case TAKE:
		m_Warmth -= 3 / warmthMultiplier;
		m_Food -= 2;
		m_Drink -= 2;
		break;
	case USE:
		m_Warmth -= 5 / warmthMultiplier;
		m_Food -= 5;
		m_Drink -= 10;
		break;
	default:
		cout << "No valid command type to affect time";
		break;
	}

	// Lose warmth faster when hungry/thirsty
	m_HungerMultiplier = (m_Food < 0) ? HUNGRY : NOT_HUNGRY;
	m_ThirstMultiplier = (m_Food < 0) ? THIRSTY : NOT_THIRSTY;

	// If warmth drops below 0 the player dies
	if (m_Warmth < 50 && m_PreviousWarmth >= 50)
		cout << "You're starting to get cold, make sure to get back to camp on time." << endl;
	if (m_Warmth < 25 && m_PreviousWarmth >= 25)
		cout << "If you don't find a source of heat soon you won't last much longer." << endl;
	if (m_Warmth < 10 && m_PreviousWarmth >= 10)
		cout << "Death is nigh." << endl;
	if (m_Warmth < 0) {
		m_IsAlive = false;
	}

	m_PreviousWarmth = m_Warmth;
}

void PlayerStats::Rest(const Campfire * fire)
{
	TimeManager::GetInstance().NewDay();
	PlayerStats& ps = PlayerStats::GetInstance();

	int fireWarmth = fire->GetWarmth();
	if (fireWarmth >= 50) {
		ps.m_Warmth += fireWarmth;
		ps.m_Food += 10;
		ps.m_Drink += 10;
		cout << "You spend a cosy night by the fire and regain some of your strenghts." << endl;
	}
	else if (fireWarmth >= 25) {
		ps.m_Warmth += fireWarmth;
		ps.m_Food -= 5;
		ps.m_Drink -= 5;
		cout << "You spend the night by the warmth of the fire." << endl;
	}
	else if (fireWarmth >= 0) {
		ps.m_Warmth += fireWarmth;
		ps.m_Food -= 10;
		ps.m_Drink -= 10;
		cout << "You spend a cold night savouring the sparse warmth of a small fire." << endl;
	}
	else {
		ps.m_Warmth += fireWarmth;
		ps.m_Food -= 20;
		ps.m_Drink -= 20;
		cout << "You spend an icy, sleepless night next to a smoldering bed of coals." << endl;
	}
}
