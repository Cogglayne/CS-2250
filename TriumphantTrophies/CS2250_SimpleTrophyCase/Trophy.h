#include <string>
using namespace std;
#ifndef TROPHY_H
#define TROPHY_H
enum Color 
{
	GOLD,
	SILVER,
	BRONZE
};		

class Trophy 
{
public:
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
	Color color;
	string name;
	int level;
};	


#endif