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
	void addTrophy(string name, int level, Color color);
	bool copyTrophy(string name);
	bool deleteTrophy(string name);
	bool renameTrophy(string name, string newName);
	bool relevelTrophy(string name, int newLevel);
	bool recolorTrophy(string name, Color newColor);

	// operators
	TrophyCase& operator=(const TrophyCase& trophyCase);
	friend ostream& operator<<(ostream& sout, const TrophyCase& trophyCase);
private:
	// variables
	Trophy** trophies;
	int nbrOfTrophies;
	int capacity;

	// helper methods
	int searchTrophies(string name);
	void sortTrophies();
	void expandTrophies();
};

#endif