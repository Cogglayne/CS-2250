#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

/// <summary>
/// A shape
/// </summary>
class Shape
{
public:
	// constructor
	Shape(string newName);

	// method
	virtual void draw();
private:
	// variable
	string name;
};

#endif 

