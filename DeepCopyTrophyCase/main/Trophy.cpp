#include "Trophy.h"
#include <string>
#include <iostream>
using namespace std;

// all colors have the same options for colors
string Trophy::colors[4] = { "DEFAULT","BRONZE","SILVER","GOLD" };

/*
* Default trophy constructor
*/
Trophy::Trophy()
{
	name = new string("");
	level = new int(0);
	color = new Color(Color::DEFAULT);
}

/*
* Trophy constructor with parameters for the trophy's name,
* level, and color.
*/
Trophy::Trophy(string newName, int newLevel, Color newColor)
{
	name = new string(newName);
	level = new int(newLevel);
	color = new Color(newColor);
}

/*
* Copy Constructor
*/
Trophy::Trophy(const Trophy& trophy)
{
	name = new string(trophy.getName());
	level = new int(trophy.getLevel());
	color = new Color(trophy.getColor());
}

/*
* Deconstructor
*/
Trophy::~Trophy()
{
	delete name;
	delete level;
	delete color;
}

/*
* Gets the name of the trophy
*/
string Trophy::getName() const
{
	return *name;
}

/*
* Gets the level of the trophy
*/
int Trophy::getLevel() const
{
	return *level;
}

/*
* Gets the color of the trophy
*/
Color Trophy::getColor() const
{
	return *color;
}

/*
* Sets the name of the trophy
*/
void Trophy::setName(string newName)
{
	*name = newName;
}

/*
* Sets the level of the trophy
*/
void Trophy::setLevel(int newLevel)
{
	*level = newLevel;
}

/*
* Sets the color of the trophy
*/
void Trophy::setColor(Color newColor)
{
	*color = newColor;
}

/*
* Outputs the name, level, and color of a trophy
*/
void Trophy::print()
{
	cout << "[ " << getName() << " : " << getLevel() << " : " << colors[getColor()] << " ]" << endl;
}

/*
* Assignment operator
*/
Trophy& Trophy::operator=(const Trophy& trophy)
{
	if (&trophy != this)
	{
		*name = *trophy.name;
		*level = *trophy.level;
		*color = *trophy.color;
	}
	return *this;
}