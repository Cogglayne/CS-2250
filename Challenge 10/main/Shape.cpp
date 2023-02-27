#include "Shape.h"
#include <iostream>
using namespace std;

/// <summary>
/// Constructor
/// </summary>
/// <param name="newName">The name for the shape</param>
Shape::Shape(string newName)
{
	cout << "Shape Constructor" << endl;
	name = newName;
}

/// <summary>
/// Draws the shape
/// </summary>
void Shape::draw()
{
	cout << "Shape Draw" << endl;
	cout << "Name: " << name << endl;
}
