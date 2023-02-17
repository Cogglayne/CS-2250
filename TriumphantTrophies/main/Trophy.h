#include <string>
using namespace std;

#ifndef TROPHY_H
#define TROPHY_H

/*
* An enum of colors
*/
enum Color
{
	DEFAULT,
	BRONZE,
	SILVER,
	GOLD,
};

/*
* A trophy
*/
class Trophy
{
public:
	// method prototypes
	Trophy();
	Trophy(string newName, int newLevel, Color newColor);
	string getName() const;
	int getLevel() const;
	Color getColor() const;
	void setName(string newName);
	void setLevel(int newLevel);
	void setColor(Color newColor);
	void print();
private:
	// variables
	Color color;
	string name;
	int level;
	static string colors[];
};

#endif