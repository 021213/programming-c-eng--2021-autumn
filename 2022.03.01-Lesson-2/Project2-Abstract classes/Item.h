#pragma once
#include"GameUnit.h"

class Item : public GameUnit
{
private:
	int lifetime;

public:
	Item(int lifetime = 0) : lifetime(lifetime) { }
	~Item() override
	{

	}
	virtual void update() override
	{
		++lifetime;
	}
};