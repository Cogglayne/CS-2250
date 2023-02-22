#include "Rectangle.h"
#include <string>
#include <iostream>

Rectangle::Rectangle(string newName, int newHeight, int newWidth) : Shape(newName)
{
	cout << "Rectangle Constructor" << endl;
	height = newHeight;
	width = newWidth;
}

void Rectangle::draw()
{
	Shape::draw();
	cout << "Rectangle Draw" << endl;
	// draws a square
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
