// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void showSelections()
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
int choiceSelection(int selection)
{
	do
	{
		cout << "Please select a menu option (1-6)" << endl;
		cin >> selection;
	} while ((selection <= 0 || selection >= 7) && cout << "You have not selected a valid menu option, please try again." << endl);
	// exit
	if (selection == 6) {
		exit(0);
	}
	return selection;
}
int sizeSelection(int selection, int choice)
{
	do
	{
		switch (choice) {
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
		cin >> selection;
	} while ((selection <= 0 || selection >= 21) && cout << "You have not selected an appropriate size, please try again." << endl);
	return selection;
}
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
void drawDiamond() 
{

}
void drawShape(int size, int selection) 
{
	switch (selection) {
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
		break;
	}
}
int main()
{
	cout << "Welcome to the shape renderer!" << endl;
	cout << "You can draw a few different shapes at a variety of sizes!" << endl;
	int size = 0;
	int choice = 0;
	while (true) {
		showSelections();
		choice = choiceSelection(choice);
		size = sizeSelection(size, choice);
		drawShape(size, choice);
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
