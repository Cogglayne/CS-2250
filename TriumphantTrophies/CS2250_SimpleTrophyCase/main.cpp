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
vector<Trophy> addTrophy(vector<Trophy> trophies);
vector<Trophy> copyTrophy(vector<Trophy> trophies);
vector<Trophy> deleteTrophy(vector<Trophy> trophies);
vector<Trophy> renameTrophy(vector<Trophy> trophies);
vector<Trophy> relevelTrophy(vector<Trophy> trophies);
vector<Trophy> recolorTrophy(vector<Trophy> trophies);
vector<Trophy> printTrophies(vector<Trophy> trophies);

// Input handlers
int printMenu();
Trophy promptForTrophy();
string promptForString(const string& message);
int promptForInt(const string& message, int minimum, int maximum);
Color /* TODO: Return a color instead of void */ promptForColor(const string& message);

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
			trophies = addTrophy(trophies);
			break;
		case 2:		// Copy an existing Trophy
			trophies = copyTrophy(trophies);
			break;
		case 3:		// Delete an existing Trophy
			trophies = deleteTrophy(trophies);
			break;
		case 4:		// Rename a Trophy
			trophies = renameTrophy(trophies);
			break;
		case 5:		// Change the level of a Trophy
			trophies = relevelTrophy(trophies);
			break;
		case 6:		// Change the color of a Trophy
			trophies = recolorTrophy(trophies);
			break;
		case 7:		// Print all Trophies
			trophies = printTrophies(trophies);
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
vector<Trophy> addTrophy(vector<Trophy> trophies)
{
	cout << "You have chosen to add a trophy." << endl;
	// TODO: Ask the user for the Trophy info (hint: there's a function for this...) and add it to the vector
	string name = promptForString(PROMPT_FOR_NAME);
	int level = promptForInt(PROMPT_FOR_LEVEL,1,10);
	Color color = promptForColor(PROMPT_FOR_COLOR);
	Trophy trophy(name,level,color);
	trophies.push_back(trophy);
	return trophies;
}

// Delete an existing Trophy from the collection
vector<Trophy> deleteTrophy(vector<Trophy> trophies)
{
	cout << "You have chosen to delete an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	int index = searchForTrophy(trophies, name);
	if (index != -1)
	{

			cout << trophies.size() << endl;
			trophies[index] = trophies.back();
			trophies.pop_back();
			cout << trophies.size() << endl;

	}
	// TODO: Find the trophy and if it exists, erase it to the vector


	return trophies;
}

// Copy an existing Trophy in the collection
vector<Trophy> copyTrophy(vector<Trophy> trophies)
{
	cout << "You have chosen to copy an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	// TODO: Find the trophy and if it exists, copy it and add the copy to the vector
	return trophies;
}

// Rename an existing Trophy (change the name)
vector<Trophy> renameTrophy(vector<Trophy> trophies)
{
	cout << "You have chosen to rename an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	string newName = promptForString("Please enter the new name of the Trophy");
	int index = searchForTrophy(trophies, name);
	if (index != -1)
	{
		trophies[index].setName(newName);
	}
	return trophies;
}

// Relevel an existing Trophy (change the level)
vector<Trophy> relevelTrophy(vector<Trophy> trophies)
{
	cout << "You have chosen to change the level of an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	int level = promptForInt(PROMPT_FOR_LEVEL,1,10);
	int index = searchForTrophy(trophies, name);
	if (index != -1)
	{
		trophies[index].setLevel(level);
	}
	return trophies;
}

// Recolor an existing Trophy (change the color)
vector<Trophy> recolorTrophy(vector<Trophy> trophies)
{
	cout << "You have chosen to change the color of an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);
	Color color = promptForColor(PROMPT_FOR_COLOR);
	int index = searchForTrophy(trophies,name);
	if (index != -1)
	{
		trophies[index].setColor(color);
	}
	return trophies;
}

// Print all of the Trophies in the collection
vector<Trophy> printTrophies(vector<Trophy> trophies)
{
	cout << "You have chosen to print all of the trophies." << endl;

	for (Trophy trophy : trophies)
	{
		trophy.print();
	}
	return trophies;
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
		cout << "That is not a valid name.  Try again." << endl; // this didnt have an endl might become an issue
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
	for (int i = 0; i < trophies.size(); i++)
	{
		if (trophies[i].getName() == trophyName)
		{
			return i;
		}
	}
	cout << "ERROR: The Trophy was not found" << endl;
	return -1;
}