#include "Triangle.h"
#include "Shape.h"
#include <iostream>

/// <summary>
/// Constructor
/// </summary>
/// <param name="newName">Name of the triangle</param>
/// <param name="newHeight">Height of the triangle</param>
Triangle::Triangle(string newName, int newHeight) : Shape(newName)
{
	cout << "Triangle Constructor" << endl;

	height = newHeight;
}

/// <summary>
/// Draws a triangle
/// </summary>
void Triangle::draw()
{
	// calls shape draw
	Shape::draw();

	cout << "Triangle Draw" << endl;

	// draws a triangle
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col <= row; col++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

