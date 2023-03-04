#include <string>
using namespace std;

#ifndef TROPHY_H
#define TROPHY_H

/// <summary>
/// An enum of colors
/// </summary>
enum Color
{
	BRONZE,
	SILVER,
	GOLD,
};

/// <summary>
/// A trophy
/// </summary>
class Trophy
{
public:
	// constructors
	Trophy();
	Trophy(const string& newName, const int& newLevel, const Color& newColor);
	Trophy(const Trophy& trophy);

	// deconstructor
	~Trophy();

	// getters
	string getName() const;
	int getLevel() const;
	Color getColor() const;

	// setters
	void setName(const string& newName);
	void setLevel(const int& newLevel);
	void setColor(const Color& newColor);

	// opertors
	bool operator<(const Trophy& other) const;
	bool operator>(const Trophy& other) const;
	bool operator==(const Trophy& other) const;
	bool operator!=(const Trophy& other) const;
	bool operator<=(const Trophy& other) const;
	bool operator>=(const Trophy& other) const;
	Trophy& operator=(const Trophy& trophy);
	friend ostream& operator<<(ostream& sout, const Trophy& trophy);
private:
	// variables
	Color* color;
	string* name;
	int* level;
	static string colors[];

	// helper methods
	int compare(const Trophy& trophy) const;
};

#endif