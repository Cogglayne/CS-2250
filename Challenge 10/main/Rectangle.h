#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

/// <summary>
/// A rectangle
/// </summary>
class Rectangle : public Shape
{
public:
	// constructor
	Rectangle(string newName, int newHeight, int newWidth);

	// method
	void draw();
private:
	// variables
	int height;
	int width;
};

#endif