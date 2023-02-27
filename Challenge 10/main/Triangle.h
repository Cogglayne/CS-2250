#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

/// <summary>
/// A triangle
/// </summary>
class Triangle : public Shape
{
public:
	// constructor
	Triangle(string newName, int newHeight);

	// method
	void draw();
private:
	// variable
	int height;
};

#endif 