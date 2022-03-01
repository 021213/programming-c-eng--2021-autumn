#pragma once
// 'behaves like a' relations to a inherited class
class IGameUnit //Names of interfaces start with capitalized I
{
private:
	//All interfaces have empty private part
public:
	/*
	There are only public methods in interfaces
	int C++ any virtual function in interface needs a return value
	in Java and C# you should use the reserved word interface instead
	of class for interfaces
	*/
	virtual int number() { return 0; }
	virtual void step() { }
};