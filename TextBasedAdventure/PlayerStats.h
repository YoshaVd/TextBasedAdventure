#pragma once
#include "Helpers.h"
#include "Campfire.h"
#include "TimeManager.h"

class Campfire;

struct PlayerStats // singleton
{
public:
	static PlayerStats& GetInstance() {
		static PlayerStats instance;
		return instance;
	}
	~PlayerStats() {};
	PlayerStats(PlayerStats const&) = delete;
	void operator=(PlayerStats const&) = delete;

	void GetHealthInfo() const;
	void UpdateStatsOverTime(const COMMAND_TYPE& type);
	void Rest(const Campfire* fire);

	// Members
	bool m_IsAlive = true;
	int m_Warmth = 100;
	int m_Food = 100;
	int m_Drink = 100;
	float m_ColdResist = 1; // increases with warm clothing, decreases when wet/at night

private:
	PlayerStats() {};

	int m_PreviousWarmth = m_Warmth;

	float m_HungerMultiplier = 1.0f;
	float m_ThirstMultiplier = 1.0f;
	const float THIRSTY = 0.5f;
	const float NOT_THIRSTY = 1.0f;
	const float HUNGRY = 0.5f;
	const float NOT_HUNGRY = 1.0f;
};

