#include "Trophy.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// all colors have the same options for colors
string Trophy::colors[3] = { "BRONZE","SILVER","GOLD" };

/// <summary>
/// Default trophy constructor
/// </summary>
Trophy::Trophy()
{
	name = new string("");
	level = new int(0);
	color = new Color(Color::BRONZE);
}

/// <summary>
/// * Trophy constructor with parameters for the trophy's name, *level, and color.
/// </summary>
/// <param name="newName">Name of trophy being created</param>
/// <param name="newLevel">Level of trophy being created</param>
/// <param name="newColor">Color of trophy being created</param>
Trophy::Trophy(const string& newName, const int& newLevel, const Color& newColor)
{
	name = new string(newName);
	level = new int(newLevel);
	color = new Color(newColor);
}

/// <summary>
///  Copy Constructor
/// </summary>
/// <param name="trophy">Trophy being copied</param>
Trophy::Trophy(const Trophy& trophy)
{
	name = new string(trophy.getName());
	level = new int(trophy.getLevel());
	color = new Color(trophy.getColor());
}

/// <summary>
///  Deconstructor
/// </summary>
Trophy::~Trophy()
{
	delete name;
	delete level;
	delete color;
}

/// <summary>
/// Getter for the trophy's name
/// </summary>
/// <returns>The trophy's name</returns>
string Trophy::getName() const
{
	return *name;
}

/// <summary>
/// Getter for the trophy's level
/// </summary>
/// <returns>The trophy's level</returns>
int Trophy::getLevel() const
{
	return *level;
}

/// <summary>
/// Getter for the trophy's color
/// </summary>
/// <returns>The trophy's color</returns>
Color Trophy::getColor() const
{
	return *color;
}

/// <summary>
/// Setter for the trophy's name
/// </summary>
/// <param name="newName">What to set the trophy's name to</param>
void Trophy::setName(const string& newName)
{
	*name = newName;
}

/// <summary>
/// Setter for the trophy's level
/// </summary>
/// <param name="newName">What to set the trophy's level to</param>
void Trophy::setLevel(const int& newLevel)
{
	*level = newLevel;
}

/// <summary>
/// Setter for the trophy's color
/// </summary>
/// <param name="newName">What to set the trophy's color to</param>
void Trophy::setColor(const Color& newColor)
{
	*color = newColor;
}

/// <summary>
/// < operator overload
/// </summary>
/// <param name="other">Trophy to compare against</param>
/// <returns>true if less than, otherwise false</returns>
bool Trophy::operator<(const Trophy& other) const
{
	return compare(other) < 0;
}

/// <summary>
/// > operator overload
/// </summary>
/// <param name="other">Trophy to compare against</param>
/// <returns>true if greater than, otherwise false</returns>
bool Trophy::operator>(const Trophy& other) const
{
	return compare(other) > 0;
}

/// <summary>
/// == operator overload
/// </summary>
/// <param name="other">Trophy to compare against</param>
/// <returns>true if equal, otherwise false</returns>
bool Trophy::operator==(const Trophy& other) const
{
	return compare(other) == 0;
}

/// <summary>
/// != operator overload
/// </summary>
/// <param name="other">Trophy to compare against</param>
/// <returns>true if other is not equal, otherwise false</returns>
bool Trophy::operator!=(const Trophy& other) const
{
	return compare(other) != 0;
}

/// <summary>
/// <= operator overload
/// </summary>
/// <param name="other">Trophy to compare against</param>
/// <returns>true if less than or equal to, otherwise false</returns>
bool Trophy::operator<=(const Trophy& other) const
{
	return compare(other) <= 0;
}

/// <summary>
/// >= operator overload
/// </summary>
/// <param name="other">Trophy to compare against</param>
/// <returns>true if greater than or equal to, otherwise false</returns>
bool Trophy::operator>=(const Trophy& other) const
{
	return compare(other) >= 0;
}

/// <summary>
/// << operator overload
/// </summary>
/// <param name="sout">An output stream</param>
/// <param name="trophy">The trophy to be outputted</param>
/// <returns>Custom output stream</returns>
ostream& operator<<(ostream& sout, const Trophy& trophy)
{
	// formats the output for a trophy
	sout << "[ " << left << setw(30) << *trophy.name
		<< " : "
		<< setw(2) << right << *trophy.level
		<< " : "
		<< setw(6) << left << trophy.colors[*trophy.color] << " ]";

	return sout;
}

/// <summary>
/// Assignment operator
/// </summary>
/// <param name="trophy">Trophy to assign to</param>
/// <returns>This trophy</returns>
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
/// <summary>
/// Compares two trophies
/// </summary>
/// <param name="other">Trophy to compare against</param>
/// <returns>1 if other is greater than, 0 if other is equal, -1 if other is less than</returns>
int Trophy::compare(const Trophy& other) const
{
	// compares level, then color, then name, if they are all the same 0 is returned
	if (*level != *other.level)
	{
		return (*level < *other.level) ? -1 : 1;
	}
	else if (*color != *other.color)
	{
		return (*color < *other.color) ? -1 : 1;
	}
	else if (*name != *other.name)
	{
		return (*name < *other.name) ? -1 : 1;
	}
	else
	{
		return 0;
	}
}
