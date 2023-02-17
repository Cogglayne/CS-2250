#include "Trophy.h"
#include <string>
#include <iostream>
using namespace std;

// all colors have the same options for colors
string Trophy::colors[4] = { "DEFAULT","BRONZE","SILVER","GOLD" };

/*
* Default constructor for a trophy
*/
Trophy::Trophy()
{
	name = "";
	level = 0;
	color = Color::DEFAULT;
}

/*
* Trophy constructor with parameters for the trophy's name,
* level, and color.
*/
Trophy::Trophy(string newName, int newLevel, Color newColor)
{
	name = newName;
	level = newLevel;
	color = newColor;
}

/*
* Gets the name of the trophy
*/
string Trophy::getName() const
{
	return name;
}

/*
* Gets the level of the trophy
*/
int Trophy::getLevel() const
{
	return level;
}

/*
* Gets the color of the trophy
*/
Color Trophy::getColor() const
{
	return color;
}

/*
* Sets the name of the trophy
*/
void Trophy::setName(string newName)
{
	name = newName;
}

/*
* Sets the level of the trophy
*/
void Trophy::setLevel(int newLevel)
{
	level = newLevel;
}

/*
* Sets the color of the trophy
*/
void Trophy::setColor(Color newColor)
{
	color = newColor;
}

/*
* Outputs the name, level, and color of a trophy
*/
void Trophy::print()
{
	cout << "[ " << getName() << " : " << getLevel() << " : " << colors[getColor()] << " ]" << endl;
}