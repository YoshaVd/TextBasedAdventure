#include "Campfire.h"

Campfire::Campfire() : InteractiveObject()
{
	m_Name = "Fire";
}

Campfire::Campfire(const Campfire & other)
{
	InteractiveObject::InteractiveObject(other);
	m_Warmth = other.GetWarmth();
}

Campfire::Campfire(Campfire && other)
{
	InteractiveObject::InteractiveObject(other);
	//swap(m_Warmth, other.GetWarmth());
}

Campfire & Campfire::operator=(const Campfire & other)
{
	InteractiveObject::operator=(other);
	m_Warmth = other.GetWarmth();
	return *this;
}

Campfire & Campfire::operator=(Campfire && other)
{
	InteractiveObject::operator=(other);
	//swap(m_Warmth, other.GetWarmth());
	return *this;
}

string Campfire::GetInfo() const
{
	string fireInfo;
	if (m_Warmth >= 100)
		fireInfo = "[" + to_string(m_Warmth) + "] It's almost impossible to stand the heat inside, this fire won't go out for some time.";
	else if (m_Warmth >= 75)
		fireInfo = "[" + to_string(m_Warmth) + "] The fire is large, it won't go out for a while.";
	else if (m_Warmth >= 50)
		fireInfo = "[" + to_string(m_Warmth) + "] The fire is doing well, but won't last indefinitely.";
	else if (m_Warmth >= 25)
		fireInfo = "[" + to_string(m_Warmth) + "] The fire is quite small, better get some more wood to keep it going.";
	else if (m_Warmth < 25)
		fireInfo = "[" + to_string(m_Warmth) + "] The fire has gone out, but some wood should get it going again.";

	cout << fireInfo << endl;
	return fireInfo;
}

string Campfire::GetWorldDescription() const
{
	string fireDescription;
	if (m_Warmth >= 100)
		fireDescription = "A huge fire is blazing inside.";
	else if (m_Warmth >= 75)
		fireDescription = "A sizeable fire is crackling inside.";
	else if (m_Warmth >= 50)
		fireDescription = "There's a fire burning inside.";
	else if (m_Warmth >= 25)
		fireDescription = "A small fire is flickering inside.";
	else if (m_Warmth < 25)
		fireDescription = "A bed of coals is smoldering inside.";

	return fireDescription;
}
