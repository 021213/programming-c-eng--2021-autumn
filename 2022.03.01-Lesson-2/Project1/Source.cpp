#include<iostream>
#include "CMonster.h"
#include "CPlayer.h"
#include "IGameUnit.h"

int main()
{
	const int monsterLen = 5;
	CMonster monster[monsterLen];
	for (int i = 0; i < monsterLen; ++i)
	{
		monster[i].setLevel(rand() % 10 + 10);
	}

	const int playerLen = 5;
	CPlayer player[playerLen];
	for (int i = 0; i < playerLen; ++i)
	{
		player[i].setHp(rand() % 10 + 10);
	}

	const int unitLen = monsterLen + playerLen;
	IGameUnit* gameUnit[unitLen];
	for (int i = 0; i < monsterLen; ++i)
	{
		gameUnit[i] = &monster[i];
	}
	for (int i = 0; i < playerLen; ++i)
	{
		gameUnit[monsterLen + i] = &player[i];
	}

	for (int i = 0; i < unitLen; ++i)
	{
		std::cout << gameUnit[i]->number() << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < unitLen; ++i)
	{
		for (int j = i + 1; j < unitLen; ++j)
		{
			if (gameUnit[i]->number() > gameUnit[j]->number())
			{
				IGameUnit* temp = gameUnit[i];
				gameUnit[i] = gameUnit[j];
				gameUnit[j] = temp;
			}
		}
	}

	for (int i = 0; i < unitLen; ++i)
	{
		std::cout << gameUnit[i]->number() << " ";
	}
	std::cout << std::endl;

	return 0;
}