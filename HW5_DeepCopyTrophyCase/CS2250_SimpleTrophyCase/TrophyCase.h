#ifndef TROPHYCASE_H
#define TROPHYCASE_H
#include "Trophy.h"

/// <summary>
/// A trophycase
/// </summary>
class TrophyCase
{
public:
	// constructors
	TrophyCase();
	TrophyCase(const TrophyCase& trophyCase);

	//deconstructor
	~TrophyCase();

	// getters
	int getNbrOfTrophies() const;
	int getAllocatedSize() const;

	// methods
	void addTrophy(const string& name, const int& level, const Color& color);
	bool copyTrophy(const string& name);
	bool deleteTrophy(const string& name);
	bool renameTrophy(const string& name, const string& newName);
	bool relevelTrophy(const string& name, const int& newLevel);
	bool recolorTrophy(const string& name, const Color& newColor);

	// operators
	TrophyCase& operator=(const TrophyCase& trophyCase);
	friend ostream& operator<<(ostream& sout, const TrophyCase& trophyCase);
private:
	// variables
	Trophy** trophies;
	int nbrOfTrophies;
	int capacity;

	// helper methods
	int searchTrophies(const string& name);
	void sortTrophies();
	void expandTrophies();
};

#endif