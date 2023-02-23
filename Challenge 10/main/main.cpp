#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

int main()
{
	Shape** shapes = new Shape*[5];
	shapes[0] = new Shape("Shape 0");
	shapes[1] = new Rectangle("Rectangle 1", 3, 5);
	shapes[2] = new Triangle("Triangle 2", 5);
	shapes[3] = new Triangle("Triangle 3", 11);
	shapes[4] = new Rectangle("Rectangle 4", 13, 8);

	for (int index = 0; index < 5; index++) {
		shapes[index]->draw();
	}

	for (int index = 0; index < 5; index++) {
		delete shapes[index];
	}

	delete [] shapes;
}
