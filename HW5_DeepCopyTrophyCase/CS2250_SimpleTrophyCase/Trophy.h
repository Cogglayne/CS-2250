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
	Trophy(const Trophy& trophy);
	~Trophy();

	string getName() const;
	int getLevel() const;
	Color getColor() const;

	void setName(string newName);
	void setLevel(int newLevel);
	void setColor(Color newColor);

	bool operator<(const Trophy& other);
	bool operator>(const Trophy& other);
	bool operator==(const Trophy& other);
	bool operator!=(const Trophy& other);
	bool operator<=(const Trophy& other);
	bool operator>=(const Trophy& other);

	Trophy& operator=(const Trophy& trophy);

	friend ostream& operator<<(ostream& sout, const Trophy& trophy);

	int compare(const Trophy& trophy);
private:
	// variables
	Color* color;
	string* name;
	int* level;
	static string colors[];
};

#endif