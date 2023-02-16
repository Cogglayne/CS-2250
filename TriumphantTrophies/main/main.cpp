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

	// has the user create a trophy
	Trophy trophy = promptForTrophy();

	// adds the trophy to the back of the vector
	trophies.push_back(trophy);
}

// Delete an existing Trophy from the collection
void deleteTrophy(vector<Trophy>& trophies)
{
	cout << "You have chosen to delete an existing trophy." << endl;

	// gets the name of the trophy the user wants to delte
	string name = promptForString(PROMPT_FOR_NAME);

	// Create a pointer to the first item in the vector
	vector<Trophy>::iterator trophiesIterator = trophies.begin();

	// Search down the vector
	while (trophiesIterator != trophies.end())
	{
		// breaks if the current trophy has a name that matches
		// the trophy the user wants to delete
		if (trophiesIterator->getName() == name)
		{
			break;
		}

		// Move to the next item in the vector
		trophiesIterator++;
	}

	// If we're not at the end of the vector (i.e. our iterator is pointing to a valid object)
	if (trophiesIterator != trophies.end())
	{
		// Erase the object that the iterator is pointing to
		trophies.erase(trophiesIterator);
	}

}

// Copy an existing Trophy in the collection
void copyTrophy(vector<Trophy>& trophies)
{
	Trophy trophy; // initializes a trophy 

	cout << "You have chosen to copy an existing trophy." << endl;

	// gets the name of the trophy the user wants to copy
	string name = promptForString(PROMPT_FOR_NAME);

	// searches for the trophy and if it exists copies the trophy
	// the copied trophy is then added to the back of the vector
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

	// gets the name of the trophy the user wants to rename
	string name = promptForString(PROMPT_FOR_NAME);

	// gets the name that the user wants to change the trophy's name to
	string newName = promptForString("Please enter the new name of the Trophy");

	// searches for the trophy and if it exists renames the trophy
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

	// gets the name of the trophy the user wants to relevel
	string name = promptForString(PROMPT_FOR_NAME);

	// gets the level that the user wants to change the trophy's level to
	int level = promptForInt(PROMPT_FOR_LEVEL, 1, 10);

	// searches for the trophy and if it exists relevels the trophy
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

	// gets the name of the trophy the user wants to recolor
	string name = promptForString(PROMPT_FOR_NAME);

	// gets the color that the user wants to change the trophy's color to
	Color color = promptForColor(PROMPT_FOR_COLOR);

	// searches for the trophy and if it exists recolors the trophy
	int index = searchForTrophy(trophies, name);
	if (index != -1)
	{
		trophies[index].setColor(color);
	}
}

// Print all of the Trophies in the collection
void printTrophies(vector<Trophy>& trophies)
{
	cout << "You have chosen to print all of the trophies." << endl;

	// loops through the vector and calls the print method on every trophy
	for (int index = 0; index < trophies.size(); index++)
	{
		trophies[index].print();
	}
}

// Ask the user for a Trophy, validate their responses
// Return the Trophy
Trophy promptForTrophy()
{
	// gets the name, level, and color of a trophy
	string name = promptForString(PROMPT_FOR_NAME);
	int level = promptForInt(PROMPT_FOR_LEVEL, 1, 10);
	Color color = promptForColor(PROMPT_FOR_COLOR);

	// creates a trophy using input gathered above
	Trophy trophy(name, level, color);

	return trophy;
}

// Ask the user for a string, validate their response
// Return the string
string promptForString(const string& message)
{
	string value = ""; // used to get a string from the user

	// outputs what the user should enter
	cout << message << endl;

	// reads in a string from the user
	getline(cin, value);

	// while the string is empty an error message is outputed and
	// the user is prompted for another string
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
	int value = 0; // used to get an int from the user

	// outputs the valid range for the int
	cout << message << endl;

	// reads in an int from the user
	cin >> value;

	// while the value entered is above the maximum or below the maximum
	// an error message is outputed and the user is asked to input another number
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
	// loops through the length of a string and uppercases each letter in the string
	for (int index = 0; index < value.length(); index++)
	{
		value[index] = toupper(value[index]);
	}

	return value;
}

// Ask the user for a color, validate the response
// Return the color
Color promptForColor(const string& message)
{
	Color color = Color::Default; // used to get a color from the user
	string value = ""; // used to get a color from the user

	// outputs the acceptable colors the user can input
	cout << message << endl;

	// while the color is the default color the loop will continue
	while (color == Default)
	{
		// gets a string from the user and then uppercases it
		cin >> value;
		value = stringToUpper(value);

		if (value == "GOLD")
		{
			// sets the color to gold
			color = Color::GOLD;
		}
		else if (value == "SILVER")
		{
			// sets the color to silver
			color = Color::SILVER;
		}
		else if (value == "BRONZE")
		{
			// sets the color to bronze
			color = Color::BRONZE;
		}
		else
		{
			// outputs an error and asks the user to input another color
			cout << "That is not an acceptable color.  Try again." << endl;
		}
	}

	cin.ignore();

	return color;
}

// Search for a trophy in the collection by name
int searchForTrophy(vector<Trophy> trophies, string trophyName)
{
	// loops through a vector to find a trophy
	for (int index = 0; index < trophies.size(); index++)
	{
		// returns the first trophy that matches the name that is being searched for
		if (trophies[index].getName() == trophyName)
		{
			return index;
		}
	}

	// an error message is outputed and -1 is returned if the 
	// trophy was not found
	cout << "ERROR: The Trophy was not found" << endl;
	return -1;
}