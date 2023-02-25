#ifndef TROPHYCASE_H
#define TROPHYCASE_H
#include "Trophy.h"

class TrophyCase
{
public:
	TrophyCase();
	TrophyCase(const TrophyCase& trophyCase);
	~TrophyCase();

	int getNbrOfTrophies() const;
	int getAllocatedSize() const;

	void addTrophy(string name, int level, Color color);
	bool copyTrophy(string name);
	bool deleteTrophy(string name);
	bool renameTrophy(string name, string newName);
	bool relevelTrophy(string name, int newLevel);
	bool recolorTrophy(string name, Color newColor);

	TrophyCase& operator=(const TrophyCase& trophyCase);
	friend ostream& operator<<(ostream& sout, const TrophyCase& trophyCase);
private:
	Trophy** trophies;
	int nbrOfTrophies;
	int capacity;
	int searchTrophies(string name);
	void sortTrophies();
};
#endif