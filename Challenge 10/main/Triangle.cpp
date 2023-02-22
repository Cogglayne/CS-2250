#include "Triangle.h"
#include "Shape.h"
#include <iostream>

Triangle::Triangle(string newName, int newHeight) : Shape(newName)
{
	cout << "Triangle Constructor" << endl;
	height = newHeight;
}

void Triangle::draw()
{
	Shape::draw();
	cout << "Triangle Draw" << endl;
	// draws a right triangle
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col <= row; col++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

