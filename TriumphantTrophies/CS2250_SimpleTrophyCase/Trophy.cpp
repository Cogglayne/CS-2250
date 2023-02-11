#include "Trophy.h"
#include <string>
#include <iostream>
using namespace std;


Trophy::Trophy()
{
	name = "";
	level = 0;
	color = Color::EMPTYCOLOR;
}

Trophy::Trophy(string newName, int newLevel, Color newColor)
{
	name = newName;
	level = newLevel;
	color = newColor;
}

string Trophy::getName() const
{
	return name;
}

int Trophy::getLevel() const
{
	return level;
}

Color Trophy::getColor() const
{
	return color;
}

void Trophy::setName(string newName)
{
	name = newName;
}

void Trophy::setLevel(int newLevel)
{
	level = newLevel;
}

void Trophy::setColor(Color newColor)
{
	color = newColor;
}

void Trophy::print()
{
	switch (getColor())
	{

	case 0:
		cout << "[ " << getName() << " : " << getLevel() << " : " << "GOLD" << " ]" << endl;
		break;
	case 1:
		cout << "[ " << getName() << " : " << getLevel() << " : " << "SILVER" << " ]" << endl;
		break;
	case 2:
		cout << "[ " << getName() << " : " << getLevel() << " : " << "BRONZE" << " ]" << endl;
		break;
	}

}