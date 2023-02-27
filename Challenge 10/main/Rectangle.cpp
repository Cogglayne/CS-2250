#include "Rectangle.h"
#include <string>
#include <iostream>

/// <summary>
/// Constructor
/// </summary>
/// <param name="newName">Name of the rectangle</param>
/// <param name="newHeight">Height of the rectangle</param>
/// <param name="newWidth">Width of the rectangle</param>
Rectangle::Rectangle(string newName, int newHeight, int newWidth) : Shape(newName)
{
	cout << "Rectangle Constructor" << endl;

	height = newHeight;
	width = newWidth;
}

/// <summary>
/// Draws the rectangle
/// </summary>
void Rectangle::draw()
{
	// calls shape draw
	Shape::draw();

	cout << "Rectangle Draw" << endl;

	// draws a rectangle
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
