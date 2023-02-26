#include "TrophyCase.h"
#include <iostream>
#include <algorithm>
using namespace std;

TrophyCase::TrophyCase()
{
	capacity = 10;
	nbrOfTrophies = 0;
	trophies = new Trophy * [capacity];
}
TrophyCase::TrophyCase(const TrophyCase& trophyCase)
{
	capacity = trophyCase.capacity;
	nbrOfTrophies = trophyCase.nbrOfTrophies;
	trophies = new Trophy * [capacity];
	for (int index = 0; index < nbrOfTrophies; index++)
	{
		trophies[index] = new Trophy(*trophyCase.trophies[index]);
	}
}
TrophyCase::~TrophyCase()
{
	for (int index = 0; index < nbrOfTrophies; index++)
	{
		delete trophies[index];
		trophies[index] = nullptr;
	}
	delete[] trophies;
}

int TrophyCase::getNbrOfTrophies() const
{
	return nbrOfTrophies;
}
int TrophyCase::getAllocatedSize() const
{
	return capacity;
}

void TrophyCase::addTrophy(string name, int level, Color color)
{
	if (nbrOfTrophies >= capacity)
	{
		expandTrophies();
	}

	Trophy* trophy = new Trophy(name, level, color);
	trophies[nbrOfTrophies] = trophy;
	nbrOfTrophies++;
	sortTrophies();
}
bool TrophyCase::copyTrophy(string name)
{
	// searches for the trophy and if it exists copies it
	int index = searchTrophies(name);
	if (index != -1)
	{
		addTrophy(trophies[index]->getName(), trophies[index]->getLevel(), trophies[index]->getColor());
		return true;
	}
	return false;
}
bool TrophyCase::deleteTrophy(string name)
{
	// searches for the trophy and if it exists deletes it
	int index = searchTrophies(name);
	if (index != -1)
	{
		delete trophies[index];
		trophies[index] = nullptr;
		nbrOfTrophies--;
		while (index < nbrOfTrophies)
		{
			trophies[index] = trophies[index + 1];
			index++;
		}
		sortTrophies();
		return true;
	}
	return false;
}
bool TrophyCase::renameTrophy(string name, string newName)
{
	// searches for the trophy and if it exists renames the trophy
	int index = searchTrophies(name);
	if (index != -1)
	{
		trophies[index]->setName(newName);
		sortTrophies();
		return true;
	}
	return false;
}
bool TrophyCase::relevelTrophy(string name, int newLevel)
{
	// searches for the trophy and if it exists relevels the trophy
	int index = searchTrophies(name);
	if (index != -1)
	{
		trophies[index]->setLevel(newLevel);
		sortTrophies();
		return true;
	}
	return false;
}
bool TrophyCase::recolorTrophy(string name, Color newColor)
{
	// searches for the trophy and if it exists recolors the trophy
	int index = searchTrophies(name);
	if (index != -1)
	{
		trophies[index]->setColor(newColor);
		sortTrophies();
		return true;
	}
	return false;
}

TrophyCase& TrophyCase::operator=(const TrophyCase& trophyCase)
{
	if (&trophyCase != this)
	{
		for (int index = 0; index < nbrOfTrophies; index++)
		{
			delete trophies[index];
			trophies[index] = nullptr;
		}
		delete[] trophies;

		capacity = trophyCase.capacity;
		trophies = new Trophy * [capacity];
		nbrOfTrophies = trophyCase.nbrOfTrophies;

		for (int index = 0; index < nbrOfTrophies; index++)
		{
			trophies[index] = (trophyCase.trophies[index]);
		}
		sortTrophies();
	}
	return *this;
}
ostream& operator<<(ostream& sout, const TrophyCase& trophyCase)
{
	for (int index = 0; index < trophyCase.nbrOfTrophies; index++)
	{
		sout << *trophyCase.trophies[index] << endl;

	}
	return sout;
}

int TrophyCase::searchTrophies(string name)
{
	// loops through a vector to find a trophy
	for (int index = 0; index < nbrOfTrophies; index++)
	{
		// returns the first trophy that matches the name that is being searched for
		if (trophies[index]->getName() == name)
		{
			return index;
		}
	}

	// -1 is returned if the trophy was not found
	return -1;
}

void TrophyCase::sortTrophies()
{
	sort(trophies, trophies + nbrOfTrophies, [](Trophy* a, Trophy* b)
		{
			return *a < *b;
		});
}

void TrophyCase::expandTrophies()
{
	capacity++;
	Trophy** newTrophies = new Trophy * [capacity];
	for (int index = 0; index < nbrOfTrophies; index++)
	{
		newTrophies[index] = trophies[index];
	}
	delete[] trophies;
	trophies = newTrophies;
}

