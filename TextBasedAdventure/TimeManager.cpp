#include "TimeManager.h"
#include <iostream>

using namespace std;

void TimeManager::GetTime() const
{
	cout << endl << m_Time << endl;
	if (m_Time < MORNING_END)
		cout << "The sun is barely up, the birds are chirping." << endl 
		<< "Time to go out and gather some supplies..." << endl;
	else if (m_Time < EVENING_BEGIN)
		cout << "The sun is up high, hard to tell the exact time." << endl;
	else if (m_Time < EVENING_END)
		cout << "Dusk is falling rapidly..." << endl
		<< "Better head back to camp before nightfall." << endl;
	else
		cout << "It's pitch black, dawn doesn't seem anywhere near and it's freezing." << endl;
}

void TimeManager::IncrementTime(const COMMAND_TYPE& type)
{
	// Increment time based on what action is performed
	switch (type)
	{
	case HELP:
	case HERE:
	case TIME:
	case INVENTORY:
	case DROP:
		break;
	case GO:
		m_Time += TRAVEL_TIME;
		break;
	case EXAMINE:
		m_Time += EXAMINE_TIME;
		break;
	case TAKE:
		m_Time += TAKE_TIME;
		break;
	case USE:
		m_Time += USE_TIME;
		break;
	default:
		cout << "No valid command type to affect time";
		break;
	}
	m_Time = m_Time % 100;

	if (m_Time < DAY_NIGHT_CYCLE / 2)
		m_IsNightTime = false;
	else
		m_IsNightTime = true;
}
