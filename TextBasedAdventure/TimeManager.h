#pragma once
#include "Helpers.h"

// Manages the day-night cycle based on input actions
class TimeManager // singleton
{
public:
	static TimeManager& GetInstance() {
		static TimeManager instance;
		return instance;
	}
	~TimeManager() {};
	TimeManager(TimeManager const&) = delete;
	void operator=(TimeManager const&) = delete;

	void GetTime() const;
	bool IsNightTime() const { return m_IsNightTime; }
	void IncrementTime(const COMMAND_TYPE& type);
	void NewDay() { m_Time = 0; }

private:
	TimeManager() {};
	
	// cycle
	bool m_IsNightTime = false;
	int m_Time = 0;
	const int DAY_NIGHT_CYCLE = 100;
	const int MORNING_END = 10;
	const int EVENING_BEGIN = 40;
	const int EVENING_END = 50;

	// action durations
	const int TRAVEL_TIME = 10;
	const int EXAMINE_TIME = 5;
	const int TAKE_TIME = 5;
	const int USE_TIME = 5;
};

