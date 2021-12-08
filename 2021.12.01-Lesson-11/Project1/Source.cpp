#include<iostream>
#include<ctime>

using namespace std;

class Banana
{
public:
	int count;
	Banana(int count = 0) : count(count) {}
};

class Fighter
{
private:
	int hp;
	int maxhp;
	int damage;

protected:
	int luck;

public:
	Fighter(int hp = 100, int damage = 5, int luck = 30) :
		hp(hp),
		maxhp(hp),
		damage(damage),
		luck(luck)
	{};

	void getDamage(int damage)
	{
		int rnd = rand() % 100;
		if (luck > rnd)
		{
			hp -= damage / 2;
		}
		else
		{
			hp -= damage;
		}
		if (hp < 0)
		{
			hp = 0;
		}
	}

	int dealDamage()
	{
		int rnd = rand() % 100;
		if (luck > rnd)
		{
			return damage * 3 / 2;
		}
		else
		{
			return damage;
		}
	}

	bool isDead()
	{
		return hp <= 0;
	}

	friend ostream& operator<<(ostream& stream, Fighter& fighter)
	{
		stream << "[" << fighter.hp << "/" << fighter.maxhp << "]";
		stream << " DMG:" << fighter.damage;
		stream << " LCK:" << fighter.luck;
		return stream;
	}

protected:
	int getHp()
	{
		return hp;
	}

	void setHp(int hp)
	{
		this->hp = hp;
	}
};

class Healer : public Fighter, public Banana
{
private:
	int reshp;
	using Banana::count;

public:
	Healer(int hp = 100, int damage = 5, int luck = 30) :
		Fighter(hp, damage, luck),
		Banana(7),
		reshp(hp / 20)
	{};

	void getDamage(int damage)
	{
		Fighter::getDamage(damage);
		if (getHp() > 0)
		{
			setHp(getHp() + reshp);
		}
	}
};

class FighterHealerNoInheritance
{
private:
	Fighter fighter;
	int reshp;

public:
	FighterHealerNoInheritance(int hp = 100, int damage = 5, int luck = 30) :
		fighter(hp, damage, luck),
		reshp(hp / 20)
	{};

	void getDamage(int damage)
	{
		return fighter.getDamage(damage);
	}

	int dealDamage()
	{
		return fighter.dealDamage();
	}

	bool isDead()
	{
		return fighter.isDead();
	}

	friend ostream& operator<<(ostream& stream, FighterHealerNoInheritance& fighter)
	{
		stream << fighter;
		return stream;
	}
};

int main(int argc, char* argv[])
{
	srand(time(0));
	
	Fighter bob(120, 7, 5);
	Healer john(90, 3, 40);

	//cout << john.count; //due to private: using Banana::count;

	while (!bob.isDead() && !john.isDead())
	{
		if (rand() % 2 == 0)
		{
			cout << "BOB deals damage to JOHN:" << john << " -> ";
			john.getDamage(bob.dealDamage());
			cout << john << endl;
			if (!john.isDead())
			{
				cout << "JOHN deals damage to BOB:" << bob << " -> ";
				bob.getDamage(john.dealDamage());
				cout << bob << endl;
			}
		}
		else
		{
			cout << "JOHN deals damage to BOB:" << bob << " -> ";
			bob.getDamage(john.dealDamage());
			cout << bob << endl;

			if (!bob.isDead())
			{
				cout << "BOB deals damage to JOHN:" << john << " -> ";
				john.getDamage(bob.dealDamage());
				cout << john << endl;
			}
		}
	}

	if (bob.isDead())
	{
		cout << "JOHN WINS" << endl;
	}
	else
	{
		cout << "BOB WINS" << endl;
	}

	return EXIT_SUCCESS;
}