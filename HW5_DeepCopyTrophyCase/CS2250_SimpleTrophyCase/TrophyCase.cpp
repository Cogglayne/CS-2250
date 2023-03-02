#include "TrophyCase.h"
#include <iostream>
#include <algorithm>
using namespace std;

/// <summary>
/// Default Constructor
/// </summary>
TrophyCase::TrophyCase()
{
	capacity = 10;
	nbrOfTrophies = 0;
	trophies = new Trophy * [capacity];
}

/// <summary>
/// Copy Constructor
/// </summary>
/// <param name="trophyCase">Trophy case that is being copied</param>
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

/// <summary>
/// Deconstructor
/// </summary>
TrophyCase::~TrophyCase()
{
	for (int index = 0; index < nbrOfTrophies; index++)
	{
		delete trophies[index];
		trophies[index] = nullptr;
	}
	delete[] trophies;
}

/// <summary>
/// Getter for number of trophies
/// </summary>
/// <returns>The number of trophies in the trophy case</returns>
int TrophyCase::getNbrOfTrophies() const
{
	return nbrOfTrophies;
}

/// <summary>
/// Getter for the capacity of a trophy case
/// </summary>
/// <returns>The capacity of a trophy case</returns>
int TrophyCase::getAllocatedSize() const
{
	return capacity;
}

/// <summary>
/// Adds a trophy to a trophy case
/// expands the case if its capacity has been reached
/// </summary>
/// <param name="name">Name of the trophy</param>
/// <param name="level">Level of the trophy</param>
/// <param name="color">Color of the trophy</param>
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

/// <summary>
/// Copies an existing trophy
/// </summary>
/// <param name="name">The name of the trophy the user wants to copy</param>
/// <returns>True if the trophy name was found, false otherwise</returns>
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

/// <summary>
/// Deletes a trophy
/// </summary>
/// <param name="name">The name of the trophy the user wants to delete</param>
/// <returns>True if the trophy name was found, false otherwise</returns>
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

/// <summary>
/// Renames a trophy
/// </summary>
/// <param name="name">The name of the trophy the user wants to rename</param>
/// <param name="newName">The new name for the trophy</param>
/// <returns>True if the trophy name was found, false otherwise</returns>
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

/// <summary>
/// Relevels a trophy
/// </summary>
/// <param name="name">The name of the trophy the user wants to relevel</param>
/// <param name="newLevel">The new level for the trophy</param>
/// <returns>True if the trophy name was found, false otherwise</returns>
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

/// <summary>
/// Recolors a trophy
/// </summary>
/// <param name="name">The name of the trophy the user wants to recolor</param>
/// <param name="newColor">The new color for the trophy</param>
/// <returns>True if the trophy name was found, false otherwise</returns>
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

/// <summary>
/// Assignment Operator
/// </summary>
/// <param name="trophyCase">The trophy case this trophy is to be assigned to</param>
/// <returns>This trophy case</returns>
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
			trophies[index] = new Trophy(*trophyCase.trophies[index]); 
		}
		sortTrophies();
	}
	return *this;
}

/// <summary>
/// << operator overload
/// </summary>
/// <param name="sout">An output stream</param>
/// <param name="trophyCase">The trophycase to be outputted</param>
/// <returns>Custom output stream</returns>
ostream& operator<<(ostream& sout, const TrophyCase& trophyCase)
{
	for (int index = 0; index < trophyCase.nbrOfTrophies; index++)
	{
		sout << *trophyCase.trophies[index] << endl;
	}
	return sout;
}

/// <summary>
/// Finds a specified trophpy
/// </summary>
/// <param name="name">The name of the trophy to be found</param>
/// <returns>The trophies index if it was found, -1 otherwise</returns>
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

/// <summary>
/// Sorts the trophies
/// </summary>
void TrophyCase::sortTrophies()
{
	sort(trophies, trophies + nbrOfTrophies, [](Trophy* a, Trophy* b)
		{
			return *a < *b;
		});
}

/// <summary>
/// Expands the trophy case
/// </summary>
void TrophyCase::expandTrophies()
{
	int expansionAmount = capacity * .1;
	capacity += expansionAmount;
	Trophy** newTrophies = new Trophy * [capacity];
	for (int index = 0; index < nbrOfTrophies; index++)
	{
		newTrophies[index] = trophies[index];
	}
	delete[] trophies;
	trophies = newTrophies;
}

