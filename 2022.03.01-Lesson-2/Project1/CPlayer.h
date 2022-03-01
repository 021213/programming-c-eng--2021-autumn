#pragma once
#include"IGameUnit.h"
class CPlayer : public IGameUnit
{
private:
	int hp;

public:
	CPlayer(int hp = 5) : hp(hp) { }
	void setHp(int hp)
	{
		this->hp = hp;
	}
	virtual int number()
	{
		return hp;
	}
	virtual void step()
	{
	}
};