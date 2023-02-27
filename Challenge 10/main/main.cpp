#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

/// <summary>
/// Creates shapes and then draws them
/// </summary>
/// <returns>0 if the program ran successfully</returns>
int main()
{
	// create an array of shapes and instantiate a shape for each index
	Shape** shapes = new Shape*[5];
	shapes[0] = new Shape("Shape 0");
	shapes[1] = new Rectangle("Rectangle 1", 3, 5);
	shapes[2] = new Triangle("Triangle 2", 5);
	shapes[3] = new Triangle("Triangle 3", 11);
	shapes[4] = new Rectangle("Rectangle 4", 13, 8);

	// draws each shape
	for (int index = 0; index < 5; index++) {
		shapes[index]->draw();
	}

	// deletes the memory for each pointer
	for (int index = 0; index < 5; index++) {
		delete shapes[index];
	}

	// dletes the memory of the array
	delete [] shapes;
}
