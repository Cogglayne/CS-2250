#include <iostream>
using namespace std;

void showShapeSelections();

void showSizeSelections(int shapeSelection);

int selectOption();

int selectSize(int shapeSelection);

void drawSquare(int sizeSelection);

void drawRightTriangle(int sizeSelection);

void drawIsocelesTriangle(int sizeSelection);

void drawHourGlass(int sizeSelection);

void drawDiamond(int sizeSelection);

void drawShape(int sizeSelection, int shapeSelection);

/*
* Return Value:
*  int - 0 mean no errors occured
*  1 means the program failed
* Description:
*  This is the main function, execution
   starts here. Initial prompts are presented to the user
   after that the user is given the opportunity to select
   a shape to draw and a size to the shape at until the
   user either closes the program or selects 6 to quit.
*/
int main()
{
	int shapeSelection = 0; // used to allow the user to select a shape
	int sizeSelection = 0; // used to allows the user to select a size for their shape

	// outputs the initial greeting
	cout << "Welcome to the shape renderer!" << endl;
	cout << "You can draw a few different shapes at a variety of sizes!" << endl;

	// shape renderer will keep running until the user presses 6 to quit
	while (true)
	{
		// outputs the shapes a user can choose
		showShapeSelections();

		// user selects a shape
		shapeSelection = selectOption();

		// user selects a size to draw their shape
		sizeSelection = selectSize(shapeSelection);

		// draws a shape based on the size and shape chosen
		drawShape(sizeSelection, shapeSelection);
	}

	return 0;
}

/*
* Description:
*  Shows the shape options the user can select
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
* Parameter:
*  shapeSelection - what shape the user wants to draw
* Description:
*  Shows the size options the user can select
*/
void showSizeSelections(int shapeSelection)
{
	switch (shapeSelection)
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
* Return Value:
*  selection - returns the number chosen by the user
* Description:
*  Takes user input to either draw a shape or quit the application
*/
int selectOption()
{
	bool optionNotValid; // used to check if input is valid
	int selection = 0; // used to get input from the user

	// continues until a user puts in a valid input
	do
	{
		// shows the user their options
		cout << "Please select a menu option (1-6)" << endl;

		// takes input from the user and checks if it is valid
		cin >> selection;
		optionNotValid = (selection <= 0 || selection >= 7);

		// if input is not valid an error message is outputed
		if (optionNotValid)
		{
			cout << "You have not selected a valid menu option, please try again." << endl;
		}
	} while (optionNotValid);

	// exits the application if option 6 is selected
	if (selection == 6)
	{
		cout << "Thank you for using our application!  Good-bye!" << endl;
		exit(0);
	}

	return selection;
}

/*
* Parameter:
* shapeSelection - what shape the user choose to draw
* Return Value:
*  selection - returns the size the user chose
* Description:
* Takes user input to set what size the chosen shape is to be drawn at
*/
int selectSize(int shapeSelection)
{
	bool sizeNotValid; // used to check if input is valid
	int selection = 0; // used to get input from the user

	// continues until a user puts in a valid input
	do
	{
		// shows the user what sizes they can choose
		showSizeSelections(shapeSelection);

		// takes input from the user and checks if it is valid
		cin >> selection;
		sizeNotValid = (selection <= 0 || selection >= 21);

		// if input is not valid an error message is outputed
		if (sizeNotValid)
		{
			cout << "You have not selected an appropriate size, please try again." << endl;
		}
	} while (sizeNotValid);

	return selection;
}

/*
* Parameter:
*  sizeSelection - how many stars to use when drawing the shape
* Description:
*  Draws a square based on the size chosen by the user
*/
void drawSquare(int sizeSelection)
{
	// draws a square
	for (int row = 0; row < sizeSelection; row++)
	{
		for (int col = 0; col < sizeSelection; col++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

/*
* Parameter:
*  sizeSelection - how many stars to use when drawing the shape
* Description:
*  Draws a right triangle based on the size chosen by the user
*/
void drawRightTriangle(int sizeSelection)
{
	// draws a right triangle
	for (int row = 0; row < sizeSelection; row++)
	{
		for (int col = 0; col <= row; col++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

/*
* Parameter:
*  sizeSelection - how many stars to use when drawing the shape
* Description:
*  Draws a isoceles triangle based on the size chosen by the user
*/
void drawIsocelesTriangle(int sizeSelection)
{
	// draws an isoceles triangle
	int spaceCount = sizeSelection - 1;
	for (int row = 0; row < sizeSelection; row++)
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
* Parameter:
*  sizeSelection - how many stars to use when drawing the shape
* Description:
*  Draws an hour glass based on the size chosen by the user
*/
void drawHourGlass(int sizeSelection)
{
	// draws the upper part of the hour glass
	int spaceCount = sizeSelection;
	for (int row = sizeSelection - 1; row > 0; row--)
	{
		for (int space = spaceCount; space < sizeSelection; space++)
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

	// draws the lower part of the hour glass
	drawIsocelesTriangle(sizeSelection);
}

/*
* Parameter:
*  sizeSelection - how many stars to use when drawing the shape
* Description:
*  Draws a diamond based on the size chosen by the user
*/
void drawDiamond(int sizeSelection)
{
	// draws the upper part of the diamond
	drawIsocelesTriangle(sizeSelection);

	// draws the lower part of the diamond
	int spaceCount = sizeSelection - 1;
	for (int row = sizeSelection - 2; row >= 0; row--)
	{
		for (int space = spaceCount; space < sizeSelection; space++)
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
* Parameter:
*  sizeSelection - how many stars to use when drawing the shape
*  selection - what shape to draw
* Description:
*  Draws a shape based on what shape and size the user choose
*/
void drawShape(int sizeSelection, int shapeSelection)
{
	switch (shapeSelection)
	{
	case 1:
		// square
		drawSquare(sizeSelection);
		break;
	case 2:
		// right triangle
		drawRightTriangle(sizeSelection);
		break;
	case 3:
		// isoceles triangle
		drawIsocelesTriangle(sizeSelection);
		break;
	case 4:
		// hourglass
		drawHourGlass(sizeSelection);
		break;
	case 5:
		// diamond
		drawDiamond(sizeSelection);
		break;
	}
}
