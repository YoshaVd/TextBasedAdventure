#pragma once
#include "InteractiveObject.h"

class Campfire : public InteractiveObject
{
public:
	Campfire();
	~Campfire() {}
	Campfire(const Campfire& other);
	Campfire(Campfire&& other);
	Campfire& operator =(const Campfire& other);
	Campfire& operator =(Campfire&& other);

	virtual string GetInfo() const;
	virtual string GetWorldDescription() const;
	int GetWarmth() const { return m_Warmth; }

	void AddFuel(const int amount) { m_Warmth += amount; }

private:
	int m_Warmth = 0;
};

