// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
/*
* Shows the shape options the user can select
*/
void showShapeSelections()
{
	cout << "********************************************************************************" << endl;
	cout << "* 1 - Square" << endl;
	cout << "* 2 - Right Triangle" << endl;
	cout << "* 3 - Isosceles Triangle" << endl;
	cout << "* 4 - Hourglass" << endl;
	cout << "* 5 - Diamond" << endl;
	cout << "* 6 - Quit(exit the application)" << endl;
	cout << "********************************************************************************" << endl;
}
/*
* Shows the size options the user can select
*/
void showSizeSelections(int selection, int choice) {
	switch (choice)
	{
	case 1:
		// square
		cout << "You have selected a square!  What size should it be (1-20)?" << endl;
		break;
	case 2:
		// right triangle
		cout << "You have selected a right triangle!  What size should it be (1-20)?" << endl;
		break;
	case 3:
		// isoceles triangle
		cout << "You have selected an isosceles triangle!  What size should it be (1-20)?" << endl;
		break;
	case 4:
		// hourglass
		cout << "You have selected an hourglass!  What size should it be (1-20)?" << endl;
		break;
	case 5:
		// diamond
		cout << "You have selected a diamond!  What size should it be (1-20)?" << endl;
		break;
	}
}
/*
* Takes user input to either draw a shape or quit the application, error checks for any selection no presented to the user
*/
int choiceSelection(int selection)
{
	do
	{
		cout << "Please select a menu option (1-6)" << endl;
		cin >> selection;
		// checks if user input is a valid selection, accepts the input if its valid, otherwise an error message is outputed,
		// and the user is prompted again to enter a valid selection
	} while ((selection <= 0 || selection >= 7) && cout << "You have not selected a valid menu option, please try again." << endl);
	// exits the game if option 6 is selected
	if (selection == 6) {
		exit(0);
	}
	return selection;
}
/*
* Takes user input to set what size the chosen shape is to be drawn at, error checks for any selection no presented to the user
*/
int sizeSelection(int selection, int choice)
{
	do
	{
		showSizeSelections(selection, choice);
		cin >> selection;
		// checks if user input is a valid selection, accepts the input if its valid, otherwise an error message is outputed,
		// and the user is prompted again to enter a valid selection
	} while ((selection <= 0 || selection >= 21) && cout << "You have not selected an appropriate size, please try again." << endl);
	return selection;
}
/*
* Draws a square based on the size chosen by the user
*/
void drawSquare(int size) {
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
/*
*  Draws a right triangle based on the size chosen by the user
*/
void drawRightTriangle(int size) {
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col <= row; col++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
/*
*  Draws a isoceles triangle based on the size chosen by the user
*/
void drawIsocelesTriangle(int size) 
{
	int spaceCount = size - 1;
	for (int row = 0; row < size; row++)
	{
		for (int space = spaceCount; space > 0; space--) 
		{
			cout << " ";
		}
		for (int col = 0; col <= (row * 2); col++)
		{
			cout << "*";
		}
		spaceCount--;
		cout << endl;
	}
}
/*
*  Draws an hour glass based on the size chosen by the user
*/
void drawHourGlass(int size) {
	int spaceCount = size;
	for (int row = size - 1; row >= 0; row--)
	{
		for (int space = spaceCount; space < size; space++)
		{
			cout << " ";
		}
		for (int col = (row * 2); col >= 0; col--)
		{
			cout << "*";
		}
		spaceCount--;
		cout << endl;
	}

	spaceCount = size - 2;
	for (int row = 1; row < size; row++)
	{
		for (int space = spaceCount; space > 0; space--)
		{
			cout << " ";
		}
		for (int col = 0; col <= (row * 2); col++)
		{
			cout << "*";
		}
		spaceCount--;
		cout << endl;
	}
}
/*
*  Draws a diamond based on the size chosen by the user
*/
void drawDiamond(int size) 
{
	int spaceCount = size - 1;
	for (int row = 0; row < size - 1 ; row++)
	{
		for (int space = spaceCount; space > 0; space--)
		{
			cout << " ";
		}
		for (int col = 0; col <= (row * 2); col++)
		{
			cout << "*";
		}
		spaceCount--;
		cout << endl;
	}

	spaceCount = size;
	for (int row = size - 1; row >= 0; row--)
	{
		for (int space = spaceCount; space < size; space++)
		{
			cout << " ";
		}
		for (int col = (row * 2); col >= 0; col--)
		{
			cout << "*";
		}
		spaceCount--;
		cout << endl;
	}
}
/*
* Draws a shape based on what shape and size the user choose
*/
void drawShape(int size, int selection) 
{
	switch (selection) 
	{
	case 1:
		// draw square
		drawSquare(size);
		break;
	case 2:
		// draw right triangle
		drawRightTriangle(size);
		break;
	case 3:
		// draw isoceles triangle
		drawIsocelesTriangle(size);
		break;
	case 4:
		// draw hourglass
		drawHourGlass(size);
		break;
	case 5:
		// draw diamond
		drawDiamond(size);
		break;
	}
}
/*
* This is the main function, execution
 starts here. Initial prompts are presented to the user
 after that the user is given the opportunity to select
 a shape to draw and a size to the shape at until the
 user either closes the program or selects 6 to quit.
*/
int main()
{
	cout << "Welcome to the shape renderer!" << endl;
	cout << "You can draw a few different shapes at a variety of sizes!" << endl;

	int size = 0;
	int choice = 0;

	while (true) {
		showShapeSelections();
		choice = choiceSelection(choice);
		size = sizeSelection(size, choice);
		drawShape(size, choice);
	}
}
