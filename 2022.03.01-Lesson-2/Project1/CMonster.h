#pragma once
#include "IGameUnit.h"
class CMonster : public IGameUnit
{
private:
	int level;

public:
	CMonster(int level = 5) : level(level) { }
	void setLevel(int level)
	{
		this->level = level;
	}
	virtual int number()
	{
		return level;
	}
	virtual void step()
	{
	}
};