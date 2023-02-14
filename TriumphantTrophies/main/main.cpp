#include <iostream>
#include <string>
#include <vector>
#include "Trophy.h"
#include <vector>

using namespace std;

// Reusable strings
const string PROMPT_FOR_NAME = "Please enter the name of the Trophy";
const string PROMPT_FOR_LEVEL = "Please enter the level of your Trophy (between 1 and 10)";
const string PROMPT_FOR_COLOR = "Please enter the color of your Trophy (GOLD, SILVER, or BRONZE)";

// Menu choice handlers
void addTrophy(vector<Trophy>& trophies);
void copyTrophy(vector<Trophy>& trophies);
void deleteTrophy(vector<Trophy>& trophies);
void renameTrophy(vector<Trophy>& trophies);
void relevelTrophy(vector<Trophy>& trophies);
void recolorTrophy(vector<Trophy>& trophies);
void printTrophies(vector<Trophy>& trophies);

// Input handlers
int printMenu();
Trophy promptForTrophy();
string promptForString(const string& message);
int promptForInt(const string& message, int minimum, int maximum);
Color promptForColor(const string& message);

// Useful helper methods
string stringToUpper(string value);
int searchForTrophy(vector<Trophy> trophies, string trophyName);

// This application allows for the management of a trophy collection
int main()
{
	cout << "***********************************************" << endl
		<< "Welcome to the Trophy editor!" << endl
		<< "With this application, you can manage your trophy" << endl
		<< "collection - add, modify, or remove trophies by" << endl
		<< "using this simple menu!" << endl
		<< "***********************************************" << endl;

	vector<Trophy> trophies;

	// Loop the menu, allowing the user to select an action each time
	int input;
	do
	{
		input = printMenu();
		switch (input)
		{
		case 1:		// Add a new Trophy
			addTrophy(trophies);
			break;
		case 2:		// Copy an existing Trophy
			copyTrophy(trophies);
			break;
		case 3:		// Delete an existing Trophy
			deleteTrophy(trophies);
			break;
		case 4:		// Rename a Trophy
			 renameTrophy(trophies);
			break;
		case 5:		// Change the level of a Trophy
			relevelTrophy(trophies);
			break;
		case 6:		// Change the color of a Trophy
			recolorTrophy(trophies);
			break;
		case 7:		// Print all Trophies
			printTrophies(trophies);
			break;
		case 8:		// Exit
			cout << "You have chosen to exit the application, good-bye!" << endl;
			break;
		default:
			cout << "That is not a recognized menu selection, choose again." << endl;
			break;
		}

	} while (input != 8);

	return 0;
}

// Print the menu to the user and accept their menu choice
int printMenu()
{
	int input;
	cout << "-----------------------------------------" << endl
		<< "Please select an option :" << endl
		<< "1 - Add a new Trophy" << endl
		<< "2 - Copy a Trophy" << endl
		<< "3 - Delete a Trophy" << endl
		<< "4 - Rename a Trophy" << endl
		<< "5 - Change the level of a Trophy" << endl
		<< "6 - Change the color of a Trophy" << endl
		<< "7 - Print All the Trophies" << endl
		<< "8 - Exit the program" << endl
		<< "-----------------------------------------" << endl;
	cin >> input;
	cin.ignore();
	return input;
}

// Add a new Trophy to the collection
void addTrophy(vector<Trophy>& trophies)
{
	cout << "You have chosen to add a trophy." << endl;
	Trophy trophy = promptForTrophy();
	trophies.push_back(trophy);
}

// Delete an existing Trophy from the collection
void deleteTrophy(vector<Trophy>& trophies)
{
	cout << "You have chosen to delete an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);

	// Create a pointer to the first item in the vector
	vector<Trophy>::iterator it = trophies.begin();

	// While we haven't found a negative number
	// and not at the end of the vector
	// Search down the vector
	while (it != trophies.end())
	{
		// Move to the next item in the vector
		if (it->getName() == name)
		{
			break;
		}
		++it;
	}

	// If we're not at the end of the vector (i.e. our iterator is pointing to a valid object)
	if (it != trophies.end())
	{
		// Erase the object that the iterator is pointing to
		trophies.erase(it);
	}

}

// Copy an existing Trophy in the collection
void copyTrophy(vector<Trophy>& trophies)
{
	Trophy trophy;
	cout << "You have chosen to copy an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	int index = searchForTrophy(trophies, name);
	if (index != -1)
	{
		trophy.setName(trophies[index].getName());
		trophy.setLevel(trophies[index].getLevel());
		trophy.setColor(trophies[index].getColor());
		trophies.push_back(trophy);
	}
}

// Rename an existing Trophy (change the name)
void renameTrophy(vector<Trophy>& trophies)
{
	cout << "You have chosen to rename an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	string newName = promptForString("Please enter the new name of the Trophy");
	int index = searchForTrophy(trophies, name);
	if (index != -1)
	{
		trophies[index].setName(newName);
	}
}

// Relevel an existing Trophy (change the level)
void relevelTrophy(vector<Trophy>& trophies)
{
	cout << "You have chosen to change the level of an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	int level = promptForInt(PROMPT_FOR_LEVEL,1,10);
	int index = searchForTrophy(trophies, name);
	if (index != -1)
	{
		trophies[index].setLevel(level);
	}
}

// Recolor an existing Trophy (change the color)
void recolorTrophy(vector<Trophy>& trophies)
{
	cout << "You have chosen to change the color of an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	Color color = promptForColor(PROMPT_FOR_COLOR);
	int index = searchForTrophy(trophies,name);
	if (index != -1)
	{
		trophies[index].setColor(color);
	}
}

// Print all of the Trophies in the collection
void printTrophies(vector<Trophy>& trophies)
{
	cout << "You have chosen to print all of the trophies." << endl;

	for (int index = 0; index < trophies.size(); index++)
	{
		trophies[index].print();
	}
}

// Ask the user for a Trophy, validate their responses
// Return the Trophy
Trophy promptForTrophy()
{
	string name = promptForString(PROMPT_FOR_NAME);
	int level = promptForInt(PROMPT_FOR_LEVEL, 1, 10);
	Color color = promptForColor(PROMPT_FOR_COLOR);
	Trophy trophy(name, level, color);
	return trophy;
}

// Ask the user for a string, validate their response
// Return the string
string promptForString(const string& message)
{
	string value = "";
	cout << message << endl;
	getline(cin, value);
	while (value.empty())
	{
		cout << "That is not a valid name.  Try again.";
		getline(cin, value);
	}
	return value;
}

// Ask the user for an int, validate their response by
// checking that it is between minimum and maximum values
// Return the int
int promptForInt(const string& message, int minimum, int maximum)
{
	int value = 0;
	cout << message << endl;
	cin >> value;
	while (value < minimum || value > maximum)
	{
		cout << "That value is outside the acceptable range.  Try again." << endl;
		cin >> value;
	}
	cin.ignore();
	return value;
}

// Convert a string to all uppercase (so that we can compare the
// user's entered color to the official color)
string stringToUpper(string value)
{
	for (int i = 0; i < value.length(); i++)
	{
		value[i] = toupper(value[i]);
	}
	return value;
}

// Ask the user for a color, validate the response
// Return the color
Color promptForColor(const string& message)
{
	Color color = Color::EMPTYCOLOR;
	string value;
	cout << message << endl;

	while (color == EMPTYCOLOR)
	{
		cin >> value;
		value = stringToUpper(value);
		if (value == "GOLD")
		{
			color = Color::GOLD;
		}
		else if (value == "SILVER")
		{
			color = Color::SILVER;
		}
		else if (value == "BRONZE")
		{
			color = Color::BRONZE;
		}else
		{
			cout << "That is not an acceptable color.  Try again." << endl;
		}
	}
	cin.ignore();
	return color;
}

// Search for a trophy in the collection by name
int searchForTrophy(vector<Trophy> trophies, string trophyName)
{
	for (int index = 0; index < trophies.size(); index++)
	{
		if (trophies[index].getName() == trophyName)
		{
			return index;
		}
	}
	cout << "ERROR: The Trophy was not found" << endl;
	return -1;
}