#pragma once
// 'is a' relations to a inherited class
class GameUnit 
{
private:
	int x;
	int y;
	int z;

public:
	GameUnit() : x(0), y(0), z(0) {};
	virtual ~GameUnit() = 0 { };
	virtual void update() = 0;
};