#include "Trophy.h"
#include <string>
#include <iostream>
#include <iomanip>
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

bool Trophy::operator<(const Trophy& other)
{
	int comparison = this->compare(other);
	if (comparison == -1)
	{
		return true;
	}
	return false;
}
bool Trophy::operator>(const Trophy& other)
{
	int comparison = this->compare(other);
	if (comparison == 1)
	{
		return true;
	}
	return false;
}
bool Trophy::operator==(const Trophy& other)
{
	int comparison = this->compare(other);
	if (comparison == 0)
	{
		return true;
	}
	return false;
}
bool Trophy::operator!=(const Trophy& other)
{
	int comparison = this->compare(other);
	if (comparison == -1 || comparison == 1)
	{
		return true;
	}
	return false;
}
bool Trophy::operator<=(const Trophy& other)
{
	int comparison = this->compare(other);
	if (comparison == -1 || comparison == 0)
	{
		return true;
	}
	return false;
}
bool Trophy::operator>=(const Trophy& other)
{
	int comparison = this->compare(other);
	if (comparison == 1 || comparison == 0)
	{
		return true;
	}
	return false;
}

/*
* Outputs the name, level, and color of a trophy
*/
ostream& operator<<(ostream& sout, const Trophy& trophy)
{
	sout << "[ " << std::setw(30) << std::left << *trophy.name << " : "
		<< *trophy.level << " : " << trophy.colors[*trophy.color] << " ]";

	return sout;
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

int Trophy::compare(const Trophy& trophy)
{
	if (*level != *trophy.level)
	{
		if (*level < *trophy.level)
		{
			return -1;
		}
		else if (*level == *trophy.level)
		{
			return 0;
		}
		else if (*level > *trophy.level)
		{
			return 1;
		}
	}
	else if (*color != *trophy.color)
	{
		if (*color < *trophy.color)
		{
			return -1;
		}
		else if (*color == *trophy.color)
		{
			return 0;
		}
		else if (*color > *trophy.color)
		{
			return 1;
		}
	}
	else
	{
		if (*name < *trophy.name)
		{
			return -1;
		}
		else if (*name == *trophy.name)
		{
			return 0;
		}
		else if (*name > *trophy.name)
		{
			return 1;
		}

	}
}